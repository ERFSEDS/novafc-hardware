use heapless::{String, Vec};
use state_machine::{State, StateMachine};

#[test]
fn success_create_state_machine() {
    let power_on = State::new(String::from("PowerOn"), Vec::new());
    let mut states = Vec::new();
    states.push(power_on).expect("Failed to push to states Vec");

    let _state_machine = StateMachine::from_vec(states)
        .expect("Failed to create state machine. Could not find PowerOn state.");
}

#[test]
fn fail_create_state_machine() {
    let armed = State::new(String::from("Armed"), Vec::new());
    let mut states = Vec::new();
    states.push(armed).expect("Failed to push to states Vec");

    if let Ok(_) = StateMachine::from_vec(states) {
        panic!("Create state machine, but without a PowerOn state");
    }
}
