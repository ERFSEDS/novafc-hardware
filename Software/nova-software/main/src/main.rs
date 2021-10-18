use heapless::{String, Vec};
use state_machine::{Check, CheckSatisfied, CheckType, State, StateMachine};

fn main() {
    let armed = State::new(String::from("Armed"), Vec::new());

    let mut states = Vec::new();
    states.push(armed).unwrap();

    let mut power_on_checks = Vec::new();
    power_on_checks
        .push(Check::new(
            String::from("Arming"),
            String::from("ArmPin"),
            CheckType::Flag,
            Some(CheckSatisfied::Transition(1)),
        ))
        .unwrap();
    let power_on = State::new(String::from("PowerOn"), power_on_checks);

    states.push(power_on).unwrap();

    let mut state_machine = StateMachine::from_vec(states)
        .expect("Failed to create state machine. Could not find PowerOn state.");

    state_machine.execute();
}
