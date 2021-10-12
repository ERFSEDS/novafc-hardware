use state_machine::StateMachine;
use data_acquisition as da;

fn main() {
    let state_machine = StateMachine::new();

    println!("Hello, world!");
    da::get_acceleration();
    da::get_high_g_acceleration();
    println!("Pressure: {:?}", da::get_pressure());
    println!("Temp: {:?}", da::get_temperature());

}
