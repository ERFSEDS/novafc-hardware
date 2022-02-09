#![no_std]
#![no_main]

use panic_halt as _;

use cortex_m_rt::entry;
use embedded_hal::digital::v2::OutputPin;
use hal::{delay::Delay, pac, prelude::*};
use stm32f4xx_hal as hal;

#[entry]
fn main() -> ! {
    /* Get access to device and core peripherals */
    let dp = pac::Peripherals::take().unwrap();
    let cp = cortex_m::Peripherals::take().unwrap();

    let rcc = dp.RCC.constrain();
    let clocks = rcc
        .cfgr
        .use_hse(26.mhz())
        .sysclk(84.mhz())
        .hclk(42.mhz())
        .freeze();

    let mut delay = hal::delay::Delay::new(cp.SYST, clocks);

    /* Get access to RCC, AFIO and GPIOA */
    let mut gpiob = dp.GPIOB.split();

    /* Set up LED pin */
    let mut blue_led = gpiob.pb14.into_push_pull_output();
    let mut green_led = gpiob.pb15.into_push_pull_output();

    /* Set up sysclk and freeze it */
    //let clocks = rcc.cfgr.sysclk(8.mhz()).freeze();

    /* Set up systick delay */
    //let mut delay = Delay::new(cp.SYST, clocks);

    loop {
        /* Light show */
        blue_led.set_high().ok();
        green_led.set_low().ok();
        delay.delay_ms(500u16);

        blue_led.set_low().ok();
        green_led.set_high().ok();
        delay.delay_ms(500u16);

        blue_led.set_low().ok();
        green_led.set_low().ok();
        delay.delay_ms(500u16);
    }
}
