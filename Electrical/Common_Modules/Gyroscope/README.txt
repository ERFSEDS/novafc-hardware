The Gyroscope is more accurately described as an IMU, it allows for reading both
rotational information as a Gyroscope however it also allows for reading 
accelleration values less that 24g which makes it not ideal for the requirements 
so a dedicated accelerometer is also used. 

The IMU also has a temperature sensor that can be used to monitor the temperature
inside the rocket.

THe Gyroscope supports both I2C and SPI, however due to the prefference of SPI,
that is the only protocol that will be covered here, for information in I2C refer
to the datasheet

It also appears that there are interupts that can be used to trigger events, say 
engine ignition for a rocket.

TO read data from this sensor format data as follows
uint16_t SPI_DATA = (0x7F & reg_addr) << 8
spi_send(addr, SPI_DATA)
	NOTE: some registers return 1 byte and some return 2!
	Data is read during the 2nd byte
To write Data to this sensor use the following
uint16_t SPI_DATA = ((0x80 | reg_addr) << 8 ) | DATA_BYTE
spi_send(addr, SPI_DATA)


Important registers

Register Name: Register Value
Register Purpose

ACC_STATUS: 0x03
Gives the status of the data in the accelerometer

ACC_Data: 0x12-0x17
Data for the accelerometers in 2's compliment each axis split into two registers

ACC_INT_STATUS: 0x1D
Acceleration data ready input cleared on read of this register

ACC_CONFIG: 0x40
Configuration for Accelerometer

ACC_RANGE: 0x41
Acceleration range for the Acceleromter (0x03 is 24G)

ACC_SELF_TEST: 0x6D
Enables the self test signal

ACC_PWR: 0x7C-7E
Power mode for the acceleroemter(on, off, suspend, reset)

Rate_Data: 0x02-0x07
Contains the angular velocity sensor output, stored in a similar matter to 
ACC_Data

GYRO_INT_STAT: 0x0A
Interupt status for the gyro

GYRO_RANGE: 0x0F
Range for the Gyroscope

GYRO_BANDWIDTH: 0x10
Bandwidth that the gyroscope data can be read at

GYRO_PWR: 0x11, 0x14
Power modes for gyroscope

GYRO_INT_CTL: 0x15
Enable interupt for gyro

GYRO_SELF_TEST: 0x3C
Enables the self test for the gyro

