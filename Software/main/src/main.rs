use control::Controls;
use data_acquisition::DataWorkspace;
use heapless::{pool::Pool, Vec};
use nova_software_common::{CheckObject, CommandObject, ObjectState};
use state_machine::{Check, Command, State, StateMachine, StateTransition, Timeout};

const MAX_NUM_STATES: usize = 16;
const MAX_CHECKS_PER_STATE: usize = 3;
const MAX_COMMANDS_PER_STATE: usize = 3;

const STATE_POOL_SIZE: usize = core::mem::size_of::<State>() * MAX_NUM_STATES;
const CHECK_POOL_SIZE: usize =
    core::mem::size_of::<Check>() * MAX_CHECKS_PER_STATE * MAX_NUM_STATES;
const COMMAND_POOL_SIZE: usize =
    core::mem::size_of::<Command>() * MAX_COMMANDS_PER_STATE * MAX_NUM_STATES;

static mut STATE_POOL_BYTES: [u8; STATE_POOL_SIZE] = [0u8; STATE_POOL_SIZE];
static mut CHECK_POOL_BYTES: [u8; CHECK_POOL_SIZE] = [0u8; CHECK_POOL_SIZE];
static mut COMMAND_POOL_BYTES: [u8; COMMAND_POOL_SIZE] = [0u8; COMMAND_POOL_SIZE];

fn main() {
    // Create the memory pools
    let state_pool: Pool<State> = Pool::new();
    let check_pool: Pool<Check> = Pool::new();
    let command_pool: Pool<Command> = Pool::new();

    // SAFETY: We are the only ones who access any of the *_POOL_BYTES, and Pool takes care of concurrent
    // access
    unsafe {
        state_pool.grow(&mut STATE_POOL_BYTES);
        check_pool.grow(&mut CHECK_POOL_BYTES);
        command_pool.grow(&mut COMMAND_POOL_BYTES);
    }

    let increase_data_rate = Command::new(CommandObject::DataRate, ObjectState::Flag(true), 4.0);
    let increase_data_rate = command_pool.alloc().unwrap().init(increase_data_rate);
    let mut launch_commands: Vec<&Command, MAX_COMMANDS_PER_STATE> = Vec::new();
    if let Err(_) = launch_commands.push(&increase_data_rate) {
        panic!()
    }

    let launch = State::new(String::from("Launch"), Vec::new(), launch_commands, None);
    let launch = &state_pool.alloc().unwrap().init(launch);

    let safe = State::new(String::from("Safe"), Vec::new(), Vec::new(), None);
    let safe = &state_pool.alloc().unwrap().init(safe);

    let mut poweron_checks: Vec<&Check, MAX_CHECKS_PER_STATE> = Vec::new();
    let continuity_check = Check::new(
        CheckObject::Pyro1Continuity,
        nova_software_common::CheckCondition::FlagSet,
        StateTransition::Transition(launch),
    );
    let continuity_check = check_pool.alloc().unwrap().init(continuity_check);
    if let Err(_) = poweron_checks.push(&continuity_check) {
        panic!();
    }

    let poweron = State::new(
        String::from("PowerOn"),
        poweron_checks,
        Vec::new(),
        Some(Timeout::new(3.0, StateTransition::Abort(safe))),
    );
    let poweron = &state_pool.alloc().unwrap().init(poweron);

    let data_workspace = DataWorkspace::new();

    let mut controls = Controls::new();

    let mut state_machine = StateMachine::new(&poweron, &data_workspace, &mut controls);

    loop {
        state_machine.execute();
    }
}
