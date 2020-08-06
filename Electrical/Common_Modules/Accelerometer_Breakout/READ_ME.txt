The H3LIS331DL is a low-power high performance 3-axis linear accelerometer capable of withstanding high G-loads of up to ± 400Gs making it ideal for rockets.

The accelerometer supports both SPI and I2C, and the breakout board has pin-headers for them, respectively.

SPI Read:

Bit 0: READ bit. Value = 1
Bit 1: MS bit. 	Value = 0 means no increment in address
		Value = 1 means increments in the address (For multiple reads)
Bit 2-7: Address AD(5:0). Address field of the Register
Bit 8-15: Data DO(7:0)(Read Mode). Reads data (MSB First)
Bit 16-...: Data DO(...-8). Further data in multiple byte reads

SPI Write:

Bit 0: WRITE bit. Value = 0
Bit 1: MS bit. 	Value = 0 means no increment in address
		Value = 1 means increments in the address (For multiple reads)
Bit 2-7: Address AD(5:0). Address field of the Register
Bit 8-15: Data DO(7:0)(Write Mode). Writes data (MSB First)
Bit 16-...: Data DO(...-8). Further data in multiple byte writes

SPI Read 3-wire mode
Bit 0: READ bit. Value = 1
Bit 1: MS bit. 	Value = 0 means no increment in address
		Value = 1 means increments in the address (For multiple reads)
Bit 2-7: Address AD(5:0). Address field of the Register
Bit 8-15: Data DO(7:0)(Read Mode). Reads data (MSB First)


Important Registers

			HEX		

WHO_AM_I: 		0F 
	Device Identification Register

CTRL_REG1:		20
	Controls Power Modes, Output Rates (Hz) and axis enabling

CTRL_REG2:		21
	Memory Reboot and Filter Control

CTRL_REG4:		23
	Data type and interface selection

CTRL_REG5:		24
	Sleep-to-wake function

HP_FILTER_RESET:	25
	High-Pass Filter Reset

STATUS_REG:		27
	Gives status on the data

OUT_X_L:		28
OUT_X_H:		29 
	Gives X axis data

OUT_Y_L:		2A
OUT_Y_H:		2B
	Gives Z axis data

OUT_Z_L:		2C
OUT_Z_H:		2D 
	Gives Z axis data