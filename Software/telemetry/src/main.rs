#![no_main]
#![no_std]
use cortex_m_rt::entry;
use panic_halt as _;

use stm32f4xx_hal as hal;

#[entry]
fn main() -> ! {
    loop {}
}

//pub fn testing_sd() {
//    let file_name = "test1.txt";
//
//    let mut file = std_Implementation::telemetry::FileIO::open(
//        file_name,
//        telemetry::FileMode::ReadWriteAppend,
//    )
//    .unwrap();
//
//    let mut buffer: [u8; 256] = [0u8; 256];
//
//    for (i, c) in "Hello World".as_bytes().iter().enumerate() {
//        buffer[i] = *c;
//    }
//
//    file.write(&mut buffer).unwrap();
//    println!("Writing to file");
//
//    let mut other_file =
//        telemetry::FileIO::open("test1.txt", telemetry::FileMode::ReadOnly).unwrap();
//
//    let mut scnd_buffer: [u8; 256] = [0u8; 256];
//
//    other_file.read(&mut scnd_buffer).unwrap();
//
//    println!("{:?}", from_utf8(&buffer));
//}
