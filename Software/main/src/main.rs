#![cfg_attr(not(feature = "std"), no_std)]
//#![no_std]

use control::Controls;
use data_acquisition::{DataWorkspace, StdTimeSource};
use heapless::Vec;
use nova_software_common::{
    CheckObject, CommandObject, ObjectState, MAX_CHECKS_PER_STATE, MAX_COMMANDS_PER_STATE,
    MAX_STATES,
};
use state_machine::{Check, Command, State, StateMachine, StateTransition, Timeout};

use static_alloc::Bump;

const STATE_SIZE: usize = core::mem::size_of::<State>() * MAX_STATES;
const CHECK_SIZE: usize = core::mem::size_of::<Check>() * MAX_CHECKS_PER_STATE * MAX_STATES;
const COMMAND_SIZE: usize = core::mem::size_of::<Command>() * MAX_COMMANDS_PER_STATE * MAX_STATES;
const BUMP_SIZE: usize = STATE_SIZE + CHECK_SIZE + COMMAND_SIZE;

// Our static allocator
static A: Bump<[u8; BUMP_SIZE]> = Bump::uninit();

fn main() {
    let increase_data_rate = Command::new(CommandObject::DataRate, ObjectState::Flag(true), 4.0);
    let increase_data_rate = &A.leak_box(increase_data_rate).unwrap();
    let mut launch_commands: Vec<&Command, MAX_COMMANDS_PER_STATE> = Vec::new();
    launch_commands
        .push(&increase_data_rate)
        .map_err(|_| ())
        .unwrap();

    let launch = State::new(2, Vec::new(), launch_commands, None);
    let launch = A.leak(launch).map_err(|_| ()).unwrap();

    let safe = State::new(1, Vec::new(), Vec::new(), None);
    let safe = A.leak(safe).map_err(|_| ()).unwrap();

    let mut poweron_checks: Vec<&Check, MAX_CHECKS_PER_STATE> = Vec::new();
    let continuity_check = Check::new(
        CheckObject::Pyro1Continuity,
        nova_software_common::CheckCondition::FlagSet,
        StateTransition::Transition(launch),
    );
    let continuity_check = A.leak(continuity_check).map_err(|_| ()).unwrap();

    poweron_checks
        .push(&continuity_check)
        .map_err(|_| ())
        .unwrap();

    let poweron = State::new(
        0,
        poweron_checks,
        Vec::new(),
        Some(Timeout::new(3.0, StateTransition::Abort(safe))),
    );
    let poweron = A.leak(poweron).map_err(|_| ()).unwrap();

    let data_workspace = DataWorkspace::new();

    let mut controls = Controls::new();

    let time_source = StdTimeSource::new();

    let mut state_machine =
        StateMachine::new(&poweron, &time_source, &data_workspace, &mut controls);

    loop {
        state_machine.execute();
    }
}
