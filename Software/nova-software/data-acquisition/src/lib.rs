#![no_std]
extern crate ms5611_spi as ms5611;

use ms5611::{Ms5611, Oversampling};
use embedded_hal as hal;

//gets the most recent acceleration value from the imu
pub fn get_acceleration() {
}

//gets the most recent high g acceleration value from the high g accelerometer
pub fn get_high_g_acceleration() {
}

//gets the most recent pressure value from the barometer
pub fn get_pressure() -> i32 {
    let sample = get_sample();
    sample.pressure
}

//gets the most recent temperature value from the barometer
pub fn get_temperature() -> i32 {
    let sample = get_sample();
    sample.temperature
}

//connects and reads from sensor
fn get_sample() -> Sample {
    //ms5611: Ms5611
    
    // let sample = ms5611
    //     .get_second_order_sample(Oversampling::OS_2048, &mut delay_source)
    //     .unwrap();
    // sample
    let sample = Sample{
        pressure: 13,
        temperature: 23,
    };
    sample
}

pub struct Sample {
    pub pressure: i32,
    pub temperature: i32,
}