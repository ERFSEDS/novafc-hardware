// use state_machine::StateMachine;
// use data_acquisition as da;


#![no_std]
#![no_main]
extern crate ms5611_spi as ms5611;
use ms5611::{Ms5611, Oversampling};
use bmi088;

extern crate shared_bus as sb;

// use core::cell::{Cell, RefCell};
// use core::ops::DerefMut;
// use cortex_m::interrupt::{free, Mutex};
use cortex_m_rt::entry;
// use hal::{
    
// };

use panic_halt as _;
use stm32f4xx_hal as hal;

// use crate::hal::{pac, prelude::*, delay::Delay};
use crate::hal::{pac, prelude::*, spi::Spi};
use hal::spi::{Mode, Phase, Polarity};


#[entry]
fn start() -> ! {
    // let device_periphs = stm32::Peripherals::take().unwrap();
    let dp = pac::Peripherals::take().unwrap();
    let cp = cortex_m::peripheral::Peripherals::take().unwrap();
    
    let rcc = dp.RCC.constrain();

    let clocks = rcc.cfgr.use_hse(8.mhz()).freeze();

    let mut delay = hal::delay::Delay::new(cp.SYST, &clocks);


    let gpioa = dp.GPIOA.split();
    let gpiob = dp.GPIOB.split();
    let gpioc = dp.GPIOC.split();
    let bar_pin = gpioc.pc5.into_push_pull_output();
    let gyro_accel_pin = gpiob.pb0.into_push_pull_output();
    let gyro_pin = gpiob.pb1.into_push_pull_output();
    let mut red_led = gpioc.pc6.into_push_pull_output();
    let mut green_led = gpiob.pb15.into_push_pull_output();
    let mut blue_led = gpiob.pb14.into_push_pull_output();
    let mut bright_led = gpiob.pb3.into_push_pull_output();
    // success_led.set_high();
    red_led.set_high(); //high is off low is on
    green_led.set_high(); //high is off low is on
    blue_led.set_high(); //high is off low is on
    bright_led.set_low(); //low is off high is on for this one
    
// sck pa5 miso pa6 mosi pa7 
    let sck = gpioa.pa5.into_alternate();
    let miso = gpioa.pa6.into_alternate();
    let mosi = gpioa.pa7.into_alternate();

    // let spi = Spi::new(
    //     dp.SPI1,
    //     (sck, miso, mosi),  
    //     Mode {
    //         polarity: Polarity::IdleLow,
    //         phase: Phase::CaptureOnFirstTransition,
    //     }, 
    //     800.khz(), 
    //     clocks
    // );
    let spi = Spi::new(
        dp.SPI1,
        (sck, miso, mosi),  
        Mode {
            polarity: Polarity::IdleLow,
            phase: Phase::CaptureOnFirstTransition,
        }, 
        800.khz(), 
        clocks
    );

    let bus = sb::BusManagerSimple::new(spi);


    // let mut ms5611 = Ms5611::new(spi, bar_pin, &mut delay).unwrap();
    let mut ms5611 = Ms5611::new(bus.acquire_spi(), bar_pin, &mut delay).unwrap();

    // let mut bmi088_accel = bmi088::Builder::new_accel_spi(spi, gyro_accel_pin);
    let mut bmi088_accel = bmi088::Builder::new_accel_spi(bus.acquire_spi(), gyro_accel_pin);
    bmi088_accel.setup(&mut delay).unwrap();

    // let mut bmi088_gyro = bmi088::Builder::new_gyro_spi(spi, gyro_pin);
    let mut bmi088_gyro = bmi088::Builder::new_gyro_spi(bus.acquire_spi(), gyro_pin);
    bmi088_gyro.setup(&mut delay).unwrap();

    loop {
        let sample = ms5611.get_second_order_sample(Oversampling::OS_2048, &mut delay).unwrap();
        let temperature = sample.temperature;
        if temperature/100 < 20 {
            bright_led.set_high();
        } else if temperature/100 == 20 {
            green_led.set_low();
        } else if temperature/100 > 20 {
            blue_led.set_low();
        } else {
            red_led.set_low();
        }

        delay.delay_ms(1_000u16);
        red_led.set_high();
        green_led.set_high();
        blue_led.set_high();
        bright_led.set_low();
        delay.delay_ms(1_000u16);

        // if let Ok(gyro_sample) = bmi088_gyro.get_gyro() {
        //     green_led.set_low();
        // } else {
        //     red_led.set_low();
        // }

        // delay.delay_ms(1_000u16);
        // red_led.set_high();
        // green_led.set_high();
        // blue_led.set_high();
        // bright_led.set_high();
        // delay.delay_ms(1_000u16);

        // if let Ok(accel_sample) = bmi088_accel.get_accel() {
        //     blue_led.set_low();
        // } else {
        //     red_led.set_high();
        // }
    }
}
