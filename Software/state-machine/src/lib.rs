#![no_std]

use data_acquisition::DataWorkspace;
use heapless::{String, Vec};
use stm32f4xx_hal::gpio::{Input, PullDown};

use nova_software_common::State;

type PyroPin = stm32f4xx_hal::gpio::gpioe::PE1<Input<PullDown>>;

/// The main struct that manages the state machine
pub struct StateMachine<'a> {
    states: Vec<State, 16>,
    /// The current state the state machine is in.
    ///
    /// Not sure if this should be an option, but I did it just to make sure it is able to be
    /// created in an empty new() function
    current_state: usize,
    /// In order to read inputs for check values we need a reference to the data acquisition
    /// workspace
    data_workspace: &'a DataWorkspace<PyroPin>,
}

impl<'a> StateMachine<'a> {
    /// THIS IS FOR TESTING PURPOSES ONLY, SHOULD BE REMOVED AS SOON AS CONFIGURATION READING IS
    /// IMPLEMENTED
    pub fn from_vec(
        states: Vec<State, 16>,
        data_workspace: &'a DataWorkspace<PyroPin>,
    ) -> Result<Self, ()> {
        let current_state = states.iter().position(|s| s.name() == "PowerOn");

        if let Some(first_state) = current_state {
            Ok(Self {
                states,
                current_state: first_state,
                data_workspace,
            })
        } else {
            Err(())
        }
    }

    /// Executes the state machine
    pub fn execute(&mut self) {
        for check in self.states.get(self.current_state).unwrap().checks() {
            let _satisfied = check.execute();
        }
    }
}
