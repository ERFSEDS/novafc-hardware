#![no_std]

use heapless::{String, Vec};

/// The main struct that manages the state machine
pub struct StateMachine<'a> {
    states: Vec<State<'a>, 16>,
    /// The current state the state machine is in.
    ///
    /// Not sure if this should be an option, but I did it just to make sure it is able to be
    /// created in an empty new() function
    current_state: Option<&'a State<'a>>,
}

impl StateMachine<'_> {
    /// Creates a new state machine with the provided state machine configuration
    pub fn new() -> Self {
        Self {
            states: Vec::new(),
            current_state: None,
        }
    }

    /// Executes the state machine
    pub fn execute() {
        todo!();
    }
}

/// A state that the rocket/flight computer can be in
///
/// This should be things like Armed, Stage1, Stage2, Safe, etc.
///
pub struct State<'a> {
    name: String<32>,
    checks: Vec<Check<'a>, 4>,
}

/// A check within a state that is run every time the state is run
pub struct Check<'a> {
    name: String<32>,
    value: String<32>,
    check_type: CheckType,
    satisfied: Option<CheckSatisfied<'a>>,
}

/// Represents a type of state check
pub enum CheckType {
    Flag,
    Equals { value: f32 },
    GreaterThan { value: f32 },
    LessThan { value: f32 },
    Between { upper_bound: f32, lower_bound: f32 },
}

/// Represents how a state check will act when it is satisfied
pub enum CheckSatisfied<'a> {
    /// Represents a safe transition to another state
    Transition(&'a State<'a>),
    /// Represents an abort to a safer state if an abort condition was met
    Abort(&'a State<'a>),
}
