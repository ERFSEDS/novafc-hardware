#![no_std]
#![no_main]

use panic_halt as _;

use cortex_m_rt::entry;
use data_acquisition::DataWorkspace;
use heapless::{String, Vec};
use state_machine::{Check, CheckSatisfied, CheckType, State, StateMachine};
use stm32f4xx_hal::gpio::GpioExt;

#[entry]
fn main() -> ! {
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

    let dp = stm32f4xx_hal::pac::Peripherals::take().unwrap();

    let gpioe = dp.GPIOE.split();

    let data_workspace = DataWorkspace::new(gpioe.pe1.into_pull_down_input());

    let mut state_machine = StateMachine::from_vec(states, &data_workspace)
        .expect("Failed to create state machine. Could not find PowerOn state.");

    state_machine.execute();

    loop {}
}
