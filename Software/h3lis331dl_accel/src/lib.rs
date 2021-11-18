#![cfg_attr(not(test), no_std)]
extern crate embedded_hal as hal;

use hal::blocking::delay::DelayMs;
use hal::blocking::spi::{Transfer, Write};
use hal::digital::v2::OutputPin;


const CTRL_REG1: u8 = 0x20;
const CTRL_REG2: u8 = 0x21;
const CTRL_REG3: u8 = 0x22;
const CTRL_REG4: u8 = 0x23;
const CTRL_REG5: u8 = 0x24;
const HP_FILTER_RESET: u8 = 0x25;
const REFERENCE: u8 = 0x26;
const STATUS_REG: u8 = 0x27;
const OUT_X_L: u8 = 0x28;
const OUT_X_H: u8 = 0x29;
const OUT_Y_L: u8 = 0x2A;
const OUT_Y_H: u8 = 0x2B;
const OUT_Z_L: u8 = 0x2C;
const OUT_Z_H: u8 = 0x2D;
const INT1_CFG: u8 = 0x30;
const INT1_SOURCE: u8 = 0x31;
const INT1_THS: u8 = 0x32;
const INT1_DURATION: u8 = 0x33;
const INT2_CFG: u8 = 0x34;
const INT2_SOURCE: u8 = 0x35;
const INT2_THS: u8 = 0x36;
const INT2_DURATION: u8 = 0x37;

#[repr(C)]
enum comm_mode {USE_I2C, USE_SPI}
#[repr(C)]
enum power_mode {POWER_DOWN, NORMAL, LOW_POWER_0_5HZ, LOW_POWER_1HZ, LOW_POWER_2HZ, LOW_POWER_5HZ, LOW_POWER_10HZ}
#[repr(C)]
enum data_rate {DR_50HZ, DR_100HZ, DR_400HZ, DR_1000HZ}
#[repr(C)]
enum high_pass_cutoff_freq_cfg {HPC_8, HPC_16, HPC_32, HPC_64}
#[repr(C)]
enum pp_od {PUSH_PULL, OPEN_DRAIN}
#[repr(C)]
enum int_sig_src {INT_SRC, INT1_2_SRC, DRDY, BOOT}
#[repr(C)]
enum fs_range {LOW_RANGE, MED_RANGE, NO_RANGE, HIGH_RANGE}
#[repr(C)]
enum int_axis {X_AXIS, Y_AXIS, Z_AXIS}
#[repr(C)]
enum trig_on_level {TRIG_ON_HIGH, TRIG_ON_LOW}



// H3LIS331DL
pub struct H3LIS331DL<SPI, NCS>{
    spi: SPI,
    ncs: NCS,
}



impl<SPI, NCS, E> H3LIS331DL<SPI, NCS>
where
    SPI: Transfer<u8, Error = E> + Write<u8, Error = E>,
    NCS: OutputPin,
{
    ///Creates a new H3LIS331DL driver from a SPI peripheral and a NCS pin
    pub fn new(spi: SPI, ncs: NCS, delay: &mut impl DelayMs<u8>) -> Result<H3LIS331DL<SPI, NCS>, E> {
        let mut h3lis331dl = H3LIS331DL {
            spi,
            ncs,
        };

        h3lis331dl.setPowerMode(power_mode::NORMAL);
        h3lis331dl.axisEnable(true);
        let mut data: [u8; 1] = [0];

        for register in 0x21..0x25 {
            h3lis331dl.H3LIS331DL_write(register, &mut data, 1);
        }
        for register in 0x30..0x37 {
            h3lis331dl.H3LIS331DL_write(register, &mut data, 1);
        }
        Ok(h3lis331dl)
    }

    fn setPowerMode(&self, mode: power_mode) {
        // let mut data: u8;
        let mut data: [u8; 4];
        self.H3LIS331DL_read(CTRL_REG1, &mut data, 1);

        // The power mode is the high three bits of CTRL_REG1. The mode 
        //  constants are the appropriate bit values left shifted by five, so we 
        //  need to right shift them to make them work. We also want to mask off the
        //  top three bits to zero, and leave the others untouched, so we *only*
        //  affect the power mode bits.
        data[0] &= !0xe0; // Clear the top three bits
        data |= mode<<5; // set the top three bits to our pmode value
        self.H3LIS331DL_write(CTRL_REG1, &mut data, 1); // write the new value to CTRL_REG1
    }

    fn axisEnable(&self, enable: bool){
        let data: [u8; 1];
        self.H3LIS331DL_read(CTRL_REG1, &mut data, 1);
        if enable
        {
          data[0] |= 0x07;
        }
        else
        {
          data[0] &= !0x07;
        }
        self.H3LIS331DL_write(CTRL_REG1, &mut data, 1);
    }


    fn setODR(&self, drate: data_rate){
        let mut data: [u8; 1];
        self.H3LIS331DL_read(CTRL_REG1, &mut data, 1);

        // The data rate is bits 4:3 of CTRL_REG1. The data rate constants are the
        //  appropriate bit values; we need to right shift them by 3 to align them
        //  with the appropriate bits in the register. We also want to mask off the
        //  top three and bottom three bits, as those are unrelated to data rate and
        //  we want to only change the data rate.
        data[0] &=!0x18;     // Clear the two data rate bits
        data |= drate<<3; // Set the two data rate bits appropriately.
        self.H3LIS331DL_write(CTRL_REG1, &mut data, 1);  // write the new value to CTRL_REG1
    }

    fn readAxes(&self, x: &i16, y: &i16, z: &i16){
        let mut data: [u8; 6];

        // LIS331_read(OUT_X_L, &data[0], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data[0..1], 1);
        // LIS331_read(OUT_X_H, &data[1], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data[1..2], 1);
        // LIS331_read(OUT_Y_L, &data[2], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data[2..3], 1);
        // LIS331_read(OUT_Y_H, &data[3], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data[3..4], 1);
        // LIS331_read(OUT_Z_L, &data[4], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data[4..5], 1);
        // LIS331_read(OUT_Z_H, &data[5], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data[5..6], 1);
        // The data that comes out is 12-bit data, left justified, so the lower
        //  four bits of the data are always zero. We need to right shift by four,
        //  then typecase the upper data to an integer type so it does a signed
        //  right shift.
        x = &((data[0] | data[1] << 8) as i16);
        y = &((data[2] | data[3] << 8) as i16);
        z = &((data[4] | data[5] << 8) as i16);
        x = &(x >> 4);
        y = &(y >> 4);
        z = &(z >> 4);
    }

    fn readReg(&mut self, reg_address: u8) -> u8{
    let mut data: [u8; 1];
    self.H3LIS331DL_read(reg_address, &mut data, 1);
    data[0]
    }

    fn convertToG(&mut self, maxScale: i32, reading: i32) -> f32{
        let result = ((maxScale as f32) * (reading as f32))/(2047 as f32);
        result
    }

    
    fn setHighPassCoeff(&mut self, hpcoeff: high_pass_cutoff_freq_cfg){
        // The HPF coeff depends on the output data rate. The cutoff frequency is
        //  is approximately fs/(6*HPc) where HPc is 8, 16, 32 or 64, corresponding
        //  to the various constants available for this parameter.
        let mut data: [u8; 1];
        self.H3LIS331DL_read(CTRL_REG2, &mut data, 1);
        data[0] &= !0xfc;  // Clear the two low bits of the CTRL_REG2
        data[0] |= hpcoeff;
        self.H3LIS331DL_write(CTRL_REG2, &mut data, 1)
    }

    fn enableHPF(&mut self, enable: bool){
        // Enable the high pass filter
        let mut data: [u8; 1];
        self.H3LIS331DL_read(CTRL_REG2, &mut data, 1);
        if enable
        {
            data[0] |= 1<<5;
        }
        else
        {
            data[0] &= !(1<<5);
        }
        self.H3LIS331DL_write(CTRL_REG2, &mut data, 1);
    }

    fn HPFOnIntPin(&mut self, enable: bool, pin: u8){
    // Enable the hpf on signal to int pins 
        let mut data: [u8; 1];
        self.H3LIS331DL_read(CTRL_REG2, &mut data, 1);
        if enable
        {
            if pin == 1
            {
                data[0] |= 1<<3;
            }
            if pin == 2
            {
                data[0] |= 1<<4;
            }
        }
        else
        {
            if pin == 1
            {
                data[0] &= !1<<3;
            }
            if pin == 2
            {
                data[0] &= !1<<4;
            }
        }
        self.H3LIS331DL_write(CTRL_REG2, &mut data, 1)
    }

    fn intActiveHigh(&mut self, enable: bool)
    {
        // Are the int pins active high or active low?
        let mut data: [u8; 1];
        self.H3LIS331DL_read(CTRL_REG3, &mut data, 1);
        // Setting bit 7 makes int pins active low
        if !enable
        {
            data[0] |= 1<<7;
        }
        else
        {
            data[0] &= !(1<<7);
        }
        self.H3LIS331DL_write(CTRL_REG3, &mut data, 1);
    }

    fn intPinMode(&mut self, _pinMode: pp_od){
        let mut data: [u8; 1];
        self.H3LIS331DL_read(CTRL_REG3, &mut data, 1);
        // Setting bit 6 makes int pins open drain.
        if _pinMode == pp_od::OPEN_DRAIN
        {
            data[0] |= 1<<6;
        }
        else
        {
            data[0] &= !(1<<6);
        }
        self.H3LIS331DL_write(CTRL_REG3, &mut data, 1);
    }

    fn latchInterrupt(&mut self, enable: bool, intSource: u8){
        // Latch mode for interrupt. When enabled, you must read the INTx_SRC reg
        //  to clear the interrupt and make way for another.
        let mut data: [u8; 1];
        self.H3LIS331DL_read(CTRL_REG3, &mut data, 1);
        // Enable latching by setting the appropriate bit.
        if enable
        {
            if intSource == 1
            {
            data[0] |= 1<<2;
            }
            if intSource == 2
            {
            data[0] |= 1<<5;
            }
        }
        else
        {
            if intSource == 1
            {
            data[0] &= !1<<2;
            }
            if intSource == 2
            {
            data[0] &= !1<<5;
            }
        }
        self.H3LIS331DL_write(CTRL_REG3, &mut data, 1);
    }

    fn intSrcConfig(&mut self, src: int_sig_src, pin: u8){
        let mut data: [u8; 1];
        self.H3LIS331DL_read(CTRL_REG3, &mut data, 1);
        // Enable latching by setting the appropriate bit.
        if pin == 1
        {
            data[0] &= !0xfc; // clear the low two bits of the register
            data[0] |= src;
        }
        if pin == 2
        {
            data[0] &= !0xe7; // clear bits 4:3 of the register
            data[0] |= src<<4;
        }
        self.H3LIS331DL_write(CTRL_REG3, &mut data, 1);
    }

    fn setFullScale(&mut self, range: fs_range){
        let mut data: [u8; 1];
        self.H3LIS331DL_read(CTRL_REG4, &mut data, 1);
        data[0] &= !0xcf;
        data[0] |= range<<4;
        self.H3LIS331DL_write(CTRL_REG4, &mut data, 1);
    }

    fn newXData(&mut self) -> bool{
        let mut data: [u8; 1];
        self.H3LIS331DL_read(STATUS_REG, &mut data, 1);
        if data[0] & 1<<0
        {
            true
        }
        else
        {
            false
        }
    }

    fn newYData(&mut self) -> bool{
        let mut data: [u8; 1];
        self.H3LIS331DL_read(STATUS_REG, &mut data, 1);
        if data[0] & 1<<1
        {
            true
        }
        else
        {
            false
        }
    }

    fn newZData(&mut self){
        let mut data: [u8; 1];
        self.H3LIS331DL_read(STATUS_REG, &mut data, 1);
        if data[0] & 1<<2
        {
            true;
        }
        else
        {
            false;
        }
    }

    fn enableInterrupt(&mut self, axis: int_axis, trigLevel: trig_on_level, interrupt: u8, enable: bool){
        let mut data: [u8; 1];
        let (mut reg, mut mask): (u8, u8);
        mask = 0;
        if interrupt == 1
        {
            reg = INT1_CFG;
        }
        else
        {
            reg = INT2_CFG;
        }
        self.H3LIS331DL_read(reg, &mut data, 1);
        if trigLevel == trig_on_level::TRIG_ON_HIGH
        {
            mask = 1<<1;
        }
        else
        {
            mask = 1;
        }
        if axis == int_axis::Z_AXIS 
        { 
            mask = mask<<4; 
        }
        if axis == int_axis::Y_AXIS
        { 
            mask = mask<<2;
        }
        if enable
        {
            data[0] |= mask;
        }
        else
        {
            data[0] &= !mask;
        }
        self.H3LIS331DL_write(reg, &mut data, 1);
    }

    fn setIntDuration(&mut self, duration: u8, intSource: u8){
        let mut data: [u8; 1];
        data[0] = duration;
        if intSource == 1
        {
            self.H3LIS331DL_write(INT1_DURATION, &mut data, 1);
        }
        else
        {
            self.H3LIS331DL_write(INT2_DURATION, &mut data, 1);
        }
    }

    fn setIntThreshold(&mut self, threshold: u8, intSource: u8){
    let mut data: [u8; 1];
    data[0] = threshold;
        if intSource == 1
        {
            self.H3LIS331DL_write(INT1_THS, &mut data, 1);
        }
        else
        {
            self.H3LIS331DL_write(INT2_THS, &mut data, 1);
        }
    }


    fn H3LIS331DL_read(&mut self, reg_address: u8, data: &mut [u8], len: u8){

        // SPI read handling code
        data[0] = reg_address | 0xC0;
        let _ = self.ncs.set_low();
        self.spi.transfer(&mut data);
        let _ = self.ncs.set_high();
    }
    
    fn H3LIS331DL_write(&mut self, reg_address: u8, data: &mut [u8], len: u8){
        // SPI write handling code
        let _ = self.ncs.set_low();
        self.spi.write(&[reg_address | 0x40]);
        let _ = self.ncs.set_high();
    }
}