#![no_std]
extern crate ms5611_spi as ms5611;
extern crate embedded_hal as hal;

use ms5611::{Ms5611, Oversampling};

//gets the most recent acceleration value from the imu
pub fn get_acceleration() {
}

//gets the most recent high g acceleration value from the high g accelerometer
pub fn get_high_g_acceleration() {
}

//gets the most recent pressure value from the barometer
pub fn get_pressure() -> i32 {
    13
}

//gets the most recent temperature value from the barometer
pub fn get_temperature() -> i32 {
    13
}

//connects and reads from sensor
fn get_sample() -> Sample {
    let sample = Sample {
        pressure: 13,
        temperature: 13,
    };
    sample
}

pub struct Sample {
    pub pressure: i32,
    pub temperature: i32,
}