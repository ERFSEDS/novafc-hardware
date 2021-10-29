// use state_machine::StateMachine;
// use data_acquisition as da;
// // use embedded_hal as hal;

#![no_std]
#![no_main]
extern crate ms5611_spi as ms5611;
use ms5611::{Ms5611, Oversampling};

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
    let mut success_led = gpiob.pb15.into_push_pull_output();
    let mut hi_temp_light = gpiob.pb14.into_push_pull_output();
    // success_led.set_high();
    success_led.set_low();
    hi_temp_light.set_low();
    
// sck pa5 miso pa6 mosi pa7 
    let sck = gpioa.pa5.into_alternate();
    let miso = gpioa.pa6.into_alternate();
    let mosi = gpioa.pa7.into_alternate();

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
    // let mut spi = Spi::(
    //     dp.SPI1,
    //     bar_pin,
    //     Config::default().baudrate(9600.bps()),
    //     clocks,
    // )
    // .unwrap();


    let mut ms5611 = Ms5611::new(spi, bar_pin, &mut delay).unwrap();

    loop {
        let sample = ms5611.get_second_order_sample(Oversampling::OS_2048, &mut delay).unwrap();
        let temperature = sample.temperature;
        if temperature <= 20 {
            success_led.set_high();
        } else if temperature > 20 {
            hi_temp_light.set_high();
        }
        
        // panic!("{:?}", sample.pressure);
        // panic!("ahhhhh");
    }
}
