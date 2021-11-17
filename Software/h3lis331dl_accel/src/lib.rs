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



enum comm_mode {USE_I2C, USE_SPI}
enum power_mode {POWER_DOWN, NORMAL, LOW_POWER_0_5HZ, LOW_POWER_1HZ, LOW_POWER_2HZ, LOW_POWER_5HZ, LOW_POWER_10HZ}
enum data_rate {DR_50HZ, DR_100HZ, DR_400HZ, DR_1000HZ}
enum high_pass_cutoff_freq_cfg {HPC_8, HPC_16, HPC_32, HPC_64}
enum pp_od {PUSH_PULL, OPEN_DRAIN} 
enum int_sig_src {INT_SRC, INT1_2_SRC, DRDY, BOOT}
enum fs_range {LOW_RANGE, MED_RANGE, NO_RANGE, HIGH_RANGE}
enum int_axis {X_AXIS, Y_AXIS, Z_AXIS}
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

        h3lis331dl.setPowerMode(NORMAL);
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
        data |= power_mode<<5; // set the top three bits to our pmode value
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
        let mut data: [u8; 1];
        let mut data1: [u8; 1];
        let mut data2: [u8; 1];
        let mut data3: [u8; 1];
        let mut data4: [u8; 1];
        let mut data5: [u8; 1];

        // LIS331_read(OUT_X_L, &data[0], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data, 1);
        // LIS331_read(OUT_X_H, &data[1], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data1, 1);
        // LIS331_read(OUT_Y_L, &data[2], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data2, 1);
        // LIS331_read(OUT_Y_H, &data[3], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data3, 1);
        // LIS331_read(OUT_Z_L, &data[4], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data4, 1);
        // LIS331_read(OUT_Z_H, &data[5], 1);
        self.H3LIS331DL_read(OUT_X_L, &mut data5, 1);
        // The data that comes out is 12-bit data, left justified, so the lower
        //  four bits of the data are always zero. We need to right shift by four,
        //  then typecase the upper data to an integer type so it does a signed
        //  right shift.
        x = data[0] | data1[0] << 8;
        y = data2[0] | data3[0] << 8;
        z = data4[0] | data5[0] << 8;
        x = x >> 4;
        y = y >> 4;
        z = z >> 4;
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