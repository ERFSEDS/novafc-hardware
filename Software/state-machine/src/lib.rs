#![no_std]

use heapless::{String, Vec};

/// The main struct that manages the state machine
pub struct StateMachine {
    states: Vec<State, 16>,
    /// The current state the state machine is in.
    ///
    /// Not sure if this should be an option, but I did it just to make sure it is able to be
    /// created in an empty new() function
    current_state: usize,
}

impl StateMachine {
    /*
    /// Creates a new state machine with the provided state machine configuration
    pub fn new() -> Self {
        Self {
            states: Vec::new(),
            current_state: None,
        }
    }
    */

    /// THIS IS FOR TESTING PURPOSES ONLY, SHOULD BE REMOVED AS SOON AS CONFIGURATION READING IS
    /// IMPLEMENTED
    pub fn from_vec(states: Vec<State, 16>) -> Result<Self, ()> {
        let current_state = states.iter().position(|s| s.name() == "PowerOn");

        if let Some(first_state) = current_state {
            Ok(Self {
                states,
                current_state: first_state,
            })
        } else {
            Err(())
        }
    }

    /// Executes the state machine
    pub fn execute(&mut self) {
        for check in self.states.get(self.current_state).unwrap().checks() {
            let satisfied = check.execute();
        }
    }
}

/// A state that the rocket/flight computer can be in
///
/// This should be things like Armed, Stage1, Stage2, Safe, etc.
///
#[derive(Debug)]
pub struct State {
    name: String<32>,
    checks: Vec<Check, 4>,
}

impl State {
    pub fn new(name: String<32>, checks: Vec<Check, 4>) -> Self {
        Self { name, checks }
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn checks(&self) -> &Vec<Check, 4> {
        &self.checks
    }
}

/// A check within a state that is run every time the state is run
#[derive(Debug)]
pub struct Check {
    name: String<32>,
    value: String<32>,
    check_type: CheckType,
    satisfied: Option<CheckSatisfied>,
}

impl Check {
    pub fn new(
        name: String<32>,
        value: String<32>,
        check_type: CheckType,
        satisfied: Option<CheckSatisfied>,
    ) -> Self {
        Self {
            name,
            value,
            check_type,
            satisfied,
        }
    }

    /// Runs the check.
    ///
    /// Returns an Option which is Some if the check has returned true.
    /// None if the check has returned false.
    pub fn execute(&self) -> Option<CheckSatisfied> {
        todo!();
    }
}

/// Represents a type of state check
#[derive(Debug)]
pub enum CheckType {
    Flag,
    Equals { value: f32 },
    GreaterThan { value: f32 },
    LessThan { value: f32 },
    Between { upper_bound: f32, lower_bound: f32 },
}

/// A state transition due to a check being satisfied
/// This is how states transition from one to another.
///
/// The enum values are the indexes of states within the vector passed to StateMachine::from_vec()
#[derive(Debug)]
pub enum CheckSatisfied {
    /// Represents a safe transition to another state
    Transition(usize),
    /// Represents an abort to a safer state if an abort condition was met
    Abort(usize),
}
