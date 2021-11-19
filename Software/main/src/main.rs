#![no_std]
#![no_main]

use panic_halt as _;

use cortex_m_rt::entry;
use stm32f4::stm32f412;

#[entry]
fn main() -> ! {
    // Set up GPIO pin B3 as push-pull output.
    let p = stm32f412::Peripherals::take().unwrap();
    let b = p.GPIOB;
    let mut state = 0usize;
    b.moder.modify(|_, w| w.moder7().output());
    b.moder.modify(|_, w| w.moder8().output());
    b.moder.modify(|_, w| w.moder9().output());

    b.otyper.modify(|_, w| w.ot7().push_pull());
    b.otyper.modify(|_, w| w.ot8().push_pull());
    b.otyper.modify(|_, w| w.ot9().push_pull());

    loop {
        let b0 = state & 0b001 == 1;
        let b1 = state & 0b010 == 1;
        let b2 = state & 0b100 == 1;

        b.odr.modify(|_, w| w.odr7().bit(b0));
        b.odr.modify(|_, w| w.odr8().bit(b1));
        b.odr.modify(|_, w| w.odr9().bit(b2));

        state = state.wrapping_add(1);
        cortex_m::asm::delay(10000);
    }
}
