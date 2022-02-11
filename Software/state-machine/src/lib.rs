#![cfg_attr(not(feature = "std"), no_std)]

use core::sync::atomic::AtomicBool;
use std::time::SystemTime;

use control::Controls;
use data_acquisition::DataWorkspace;
use heapless::Vec;
use nova_software_common::{CheckCondition, CheckObject, CommandObject, ObjectState};

// TODO: Unify this into nova-software-common
const MAX_NUM_STATES: usize = 16;
const MAX_CHECKS_PER_STATE: usize = 3;
const MAX_COMMANDS_PER_STATE: usize = 3;

pub struct StateMachine<'a, 'b, 'c> {
    current_state: &'a State<'a>,
    start_time: SystemTime,
    state_time: SystemTime,
    data_workspace: &'b DataWorkspace,
    controls: &'c mut Controls,
}

impl<'a, 'b, 'c> StateMachine<'a, 'b, 'c> {
    pub fn new(
        begin: &'a State<'a>,
        data_workspace: &'b DataWorkspace,
        controls: &'c mut Controls,
    ) -> Self {
        let time = SystemTime::now();

        println!("State machine starting in state: {}", begin.name);

        Self {
            current_state: begin,
            start_time: time,
            state_time: time,
            data_workspace,
            controls,
        }
    }

    pub fn execute<'_self>(&'_self mut self) {
        if let Some(transition) = self.execute_state() {
            self.transition(transition);
        }
    }

    fn execute_state<'_self>(&'_self mut self) -> Option<StateTransition<'a>> {
        // Execute commands
        for command in self.current_state.commands.iter() {
            self.execute_command(command);
        }

        // Execute checks
        for check in self.current_state.checks.iter() {
            if let Some(transition) = self.execute_check(check) {
                return Some(transition);
            }
        }

        // Check for timeout
        if let Some(timeout) = &self.current_state.timeout {
            // Checks if the state has timed out
            if self.state_time.elapsed().unwrap().as_secs_f32() >= timeout.time {
                Some(timeout.transition)
            } else {
                None
            }
        } else {
            None
        }
    }

    fn execute_command<'_self>(&'_self mut self, command: &Command) {
        if !command
            .was_executed
            .load(std::sync::atomic::Ordering::SeqCst)
        {
            if self.state_time.elapsed().unwrap().as_secs_f32() >= command.delay {
                self.controls.set(command.object, command.setting);
                command
                    .was_executed
                    .store(true, std::sync::atomic::Ordering::SeqCst);
            }
        }
    }

    fn execute_check<'_self>(&'_self self, check: &Check<'a>) -> Option<StateTransition<'a>> {
        let value = self.data_workspace.get_object(check.object);

        let satisfied = match check.condition {
            CheckCondition::FlagSet | CheckCondition::FlagUnset => match value {
                ObjectState::Flag(b) => b == matches!(check.condition, CheckCondition::FlagSet),
                _ => panic!("Non-flag value provided to a check that requires a FlagSet/Unset"),
            },
            CheckCondition::LessThan { value: other } => match value {
                ObjectState::Float(f) => f < other,
                _ => panic!(
                    "Non-float value provided to a check that requires a float value (LessThan)"
                ),
            },
            CheckCondition::GreaterThan { value: other } => match value {
                ObjectState::Float(f) => f > other,
                _ => panic!(
                    "Non-float value provided to a check that requires a float value (GreaterThan)"
                ),
            },
            CheckCondition::Between {
                upper_bound,
                lower_bound,
            } => match value {
                ObjectState::Float(f) => f < upper_bound && f > lower_bound,
                _ => panic!(
                    "Non-float value provided to a check that requires a float value (Between)"
                ),
            },
        };

        satisfied.then(|| check.transition)
    }

    fn transition(&mut self, transition: StateTransition<'a>) {
        let new_state = match transition {
            StateTransition::Abort(state) => {
                println!(
                    "[{}s] Aborted to state: {}",
                    self.start_time.elapsed().unwrap().as_secs_f32(),
                    state.name
                );
                // Here we would have abort reporting of some kind like some "callback" to the data
                // acquisition module
                state
            }
            StateTransition::Transition(state) => {
                println!(
                    "[{}s] Transitioned to state: {}",
                    self.start_time.elapsed().unwrap().as_secs_f32(),
                    state.name
                );
                // We may also put some kind of transition reporting here or just use state ID's
                state
            }
        };

        // Set the new state and reset the state time
        self.current_state = new_state;
        self.state_time = SystemTime::now();
    }
}

pub struct Timeout<'a> {
    pub time: f32,
    pub transition: StateTransition<'a>,
}

impl<'a> Timeout<'a> {
    pub fn new(time: f32, transition: StateTransition<'a>) -> Self {
        Self { time, transition }
    }
}

pub struct State<'a> {
    // Debug purposes only
    pub name: String,
    pub checks: Vec<&'a Check<'a>, MAX_CHECKS_PER_STATE>,
    pub commands: Vec<&'a Command, MAX_COMMANDS_PER_STATE>,
    pub timeout: Option<Timeout<'a>>,
}

impl<'a> State<'a> {
    pub fn new(
        name: String,
        checks: Vec<&'a Check<'a>, MAX_CHECKS_PER_STATE>,
        commands: Vec<&'a Command, MAX_COMMANDS_PER_STATE>,
        timeout: Option<Timeout<'a>>,
    ) -> Self {
        Self {
            name,
            checks,
            commands,
            timeout,
        }
    }
}

pub struct Check<'a> {
    pub object: CheckObject,
    pub condition: CheckCondition,
    pub transition: StateTransition<'a>,
}

impl<'a> Check<'a> {
    pub fn new(
        object: CheckObject,
        condition: CheckCondition,
        transition: StateTransition<'a>,
    ) -> Self {
        Self {
            object,
            condition,
            transition,
        }
    }
}

#[derive(Copy, Clone)]
pub enum StateTransition<'a> {
    Transition(&'a State<'a>),
    Abort(&'a State<'a>),
}

pub struct Command {
    pub object: CommandObject,
    pub setting: ObjectState,
    pub delay: f32,
    pub was_executed: AtomicBool,
}

impl Command {
    pub fn new(object: CommandObject, setting: ObjectState, delay: f32) -> Self {
        Self {
            object,
            setting,
            delay,
            was_executed: AtomicBool::new(false),
        }
    }
}
