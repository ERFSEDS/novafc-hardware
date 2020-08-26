EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 19
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 1250 -1150 0    157  ~ 31
When creating your part in your feature branch create a heirarchical\nsheet and name it appropriately and do your work in there. NOT IN\nTHIS SHEET. THis sheet is the top level connect all the parts together\nsheet. I will find you if you put something other than  Heirarchical\nsheet in here
Wire Wire Line
	4350 1500 3550 1500
Wire Wire Line
	4350 1750 3550 1750
Wire Wire Line
	4350 1850 3550 1850
Wire Wire Line
	4350 2000 3550 2000
Wire Wire Line
	4350 2100 3550 2100
Text Label 3850 1500 0    50   ~ 0
RESET
Text Label 3800 1750 0    50   ~ 0
CLOCKIN
Text Label 3800 1850 0    50   ~ 0
CLOCKOUT
Text Label 3750 2000 0    50   ~ 0
32CLOCKIN
Text Label 3750 2100 0    50   ~ 0
32CLOCKOUT
Wire Wire Line
	4350 1200 3550 1200
Wire Wire Line
	4350 1300 3550 1300
Text Label 3850 1200 0    50   ~ 0
SWDIO
Text Label 3850 1300 0    50   ~ 0
SWCLK
Wire Wire Line
	4350 2350 3550 2350
Wire Wire Line
	4350 2450 3550 2450
Wire Wire Line
	4350 2550 3550 2550
Text Label 3900 2350 0    50   ~ 0
VCAP
Text Label 3900 2450 0    50   ~ 0
VSSA
Text Label 3900 2550 0    50   ~ 0
VREF+
Wire Wire Line
	4350 2750 3550 2750
Wire Wire Line
	4350 2850 3550 2850
Text Label 3850 2750 0    50   ~ 0
RXD
Text Label 3850 2850 0    50   ~ 0
TXD
Wire Wire Line
	4350 3150 3550 3150
Wire Wire Line
	4350 3250 3550 3250
Wire Wire Line
	4350 3350 3550 3350
Wire Wire Line
	4350 3450 3550 3450
Text Label 3850 3150 0    50   ~ 0
NSS
Text Label 3850 3250 0    50   ~ 0
SCLK
Text Label 3850 3350 0    50   ~ 0
MISO
Text Label 3850 3450 0    50   ~ 0
MOSI
$Sheet
S 800  4300 1250 500 
U 5F3616EF
F0 "LED Indication" 50
F1 "LED Indication.sch" 20
F2 "LED_RED" I R 2050 4400 50 
F3 "LED_BLUE" I R 2050 4550 50 
F4 "LED_GREEN" I R 2050 4700 50 
$EndSheet
Text Label 2400 3600 0    50   ~ 0
RXD
Text Label 2400 3500 0    50   ~ 0
TXD
Wire Wire Line
	2050 3600 2850 3600
Wire Wire Line
	2050 3500 2850 3500
Text Label 2350 3150 0    50   ~ 0
VREF+
Text Label 2350 2950 0    50   ~ 0
VSSA
Text Label 2350 2850 0    50   ~ 0
VCAP
Wire Wire Line
	2200 3150 2850 3150
Connection ~ 2200 3150
Wire Wire Line
	2200 3050 2200 3150
Wire Wire Line
	2050 3050 2200 3050
Wire Wire Line
	2050 3150 2200 3150
Wire Wire Line
	2050 2950 2850 2950
Wire Wire Line
	2050 2850 2850 2850
Text Label 2350 800  0    50   ~ 0
SWDIO
Text Label 2350 900  0    50   ~ 0
SWCLK
Text Label 2350 1000 0    50   ~ 0
RESET
Wire Wire Line
	2050 800  2850 800 
Wire Wire Line
	2050 900  2850 900 
Wire Wire Line
	2050 1000 2850 1000
Text Label 2250 2450 0    50   ~ 0
32CLOCKOUT
Text Label 2250 2350 0    50   ~ 0
32CLOCKIN
Text Label 2250 2200 0    50   ~ 0
CLOCKOUT
Text Label 2300 2100 0    50   ~ 0
CLOCKIN
Text Label 2350 1650 0    50   ~ 0
RESET
Wire Wire Line
	2050 2450 2850 2450
Wire Wire Line
	2050 2350 2850 2350
Wire Wire Line
	2050 2200 2850 2200
Wire Wire Line
	2050 2100 2850 2100
Wire Wire Line
	2050 1650 2850 1650
Wire Notes Line
	700  550  3100 550 
Text Notes 1300 4150 0    79   ~ 0
MCU PERIPHERALS\n\n
$Sheet
S 800  3400 1250 350 
U 5F319D4B
F0 "USB-C" 50
F1 "USB-C.sch" 20
F2 "TXD" I R 2050 3500 50 
F3 "RXD" I R 2050 3600 50 
$EndSheet
$Sheet
S 800  2000 1250 550 
U 5F319C9C
F0 "CLOCKS" 50
F1 "Clocks.sch" 20
F2 "CLOCKIN" I R 2050 2100 50 
F3 "CLOCKOUT" I R 2050 2200 50 
F4 "RTCCRYSTALIN" I R 2050 2350 50 
F5 "RTCCRYSTALOUT" I R 2050 2450 50 
$EndSheet
$Sheet
S 800  2750 1250 500 
U 5F3189B2
F0 "MCU FILTERING" 50
F1 "MCU FILTERING.sch" 20
F2 "VCAP" I R 2050 2850 50 
F3 "VSSA" I R 2050 2950 50 
F4 "VDDA" I R 2050 3050 50 
F5 "VREF+" I R 2050 3150 50 
$EndSheet
$Sheet
S 800  1450 1250 350 
U 5F317E00
F0 "MCU RESET" 50
F1 "MCU RESET.sch" 20
F2 "RESET" I R 2050 1650 50 
$EndSheet
$Sheet
S 800  700  1250 450 
U 5F31B2A5
F0 "SWD" 50
F1 "SWD.sch" 20
F2 "JTMS-SWDIO" I R 2050 800 50 
F3 "JTCK-SWCLK" I R 2050 900 50 
F4 "RESET" I R 2050 1000 50 
$EndSheet
$Sheet
S 9350 800  1000 500 
U 5F3A063C
F0 "Barometer" 50
F1 "Barometer.sch" 20
F2 "SCLK" I L 9350 900 50 
F3 "SDI" I L 9350 1000 50 
F4 "SDO" I L 9350 1100 50 
F5 "CSB" I L 9350 1200 50 
$EndSheet
Wire Wire Line
	9350 900  8550 900 
Wire Wire Line
	9350 1000 8550 1000
Wire Wire Line
	9350 1100 8550 1100
Wire Wire Line
	8550 1200 9350 1200
Text Label 8850 900  0    50   ~ 0
SCLK
Text Label 8850 1000 0    50   ~ 0
MOSI
Text Label 8850 1100 0    50   ~ 0
MISO
$Sheet
S 9350 5850 1000 500 
U 5F3B0B4B
F0 "PowerSupply" 50
F1 "PowerSupply.sch" 20
$EndSheet
$Sheet
S 9350 4000 1000 500 
U 5F3B5BD1
F0 "MicroSD" 50
F1 "MicroSD.sch" 20
F2 "MISO" I L 9350 4100 50 
F3 "MOSI" I L 9350 4200 50 
F4 "SCLK" I L 9350 4300 50 
F5 "CS_SD" I L 9350 4400 50 
$EndSheet
$Sheet
S 9350 4700 1000 600 
U 5F3B5C2E
F0 "FlashChip" 50
F1 "FlashChip.sch" 20
F2 "SCLK" I L 9350 4750 50 
F3 "MOSI" I L 9350 4850 50 
F4 "MISO" I L 9350 4950 50 
F5 "CS_FLASH" I L 9350 5050 50 
F6 "HOLD" I L 9350 5150 50 
F7 "WP" I L 9350 5250 50 
$EndSheet
Wire Wire Line
	9350 4100 8550 4100
Wire Wire Line
	8550 4200 9350 4200
Wire Wire Line
	9350 4300 8550 4300
Wire Wire Line
	9350 4400 8550 4400
Wire Wire Line
	8550 4750 9350 4750
Wire Wire Line
	9350 4850 8550 4850
Wire Wire Line
	9350 4950 8550 4950
Wire Wire Line
	8550 5050 9350 5050
Wire Wire Line
	9350 5150 8550 5150
Wire Wire Line
	9350 5250 8550 5250
Text Label 8850 4100 0    50   ~ 0
MISO
Text Label 8850 4200 0    50   ~ 0
MOSI
Text Label 8850 4300 0    50   ~ 0
SCLK
Text Label 8850 4750 0    50   ~ 0
SCLK
Text Label 8850 4850 0    50   ~ 0
MOSI
Text Label 8850 4950 0    50   ~ 0
MISO
Text Label 8850 5150 0    50   ~ 0
HOLD
Text Label 9000 5250 2    50   ~ 0
WP
Text Label 8700 1200 0    50   ~ 0
BAROMETER_CS
Text Label 8800 4400 0    50   ~ 0
SD_CS
Text Label 8750 5050 0    50   ~ 0
FLASH_CS
Wire Wire Line
	6800 1200 7600 1200
Wire Wire Line
	6800 1300 7600 1300
Wire Wire Line
	6800 1400 7600 1400
Text Label 6900 1200 0    50   ~ 0
BAROMETER_CS
Text Label 6850 1300 0    50   ~ 0
ACCELEROMETER_CS
Text Label 7000 1400 0    50   ~ 0
GYRO_CS
$Sheet
S 800  5000 1250 300 
U 5F36176A
F0 "Buzzer" 50
F1 "Buzzer.sch" 20
F2 "BUZZER" I R 2050 5150 50 
$EndSheet
Wire Wire Line
	2050 5150 2850 5150
Text Label 2350 5150 0    50   ~ 0
BUZZER
Wire Notes Line
	8450 3750 10450 3750
Wire Notes Line
	10450 3750 10450 5450
Wire Notes Line
	10450 5450 8450 5450
Wire Notes Line
	8450 5450 8450 3750
Text Notes 9100 5600 0    79   ~ 0
DATA LOGGING\n
Wire Notes Line
	8450 5750 10450 5750
Wire Notes Line
	10450 5750 10450 6500
Wire Notes Line
	10450 6500 8450 6500
Wire Notes Line
	8450 6500 8450 5750
Text Notes 9000 6650 0    79   ~ 0
POWER SUPPLY\n
Wire Notes Line
	3300 550  7750 550 
Wire Notes Line
	7750 550  7750 4550
Wire Notes Line
	7750 4550 3300 4550
Wire Notes Line
	3300 4550 3300 550 
Text Notes 5350 4700 0    79   ~ 0
MCU
$Sheet
S 9350 1500 1000 600 
U 5F440A67
F0 "GyroScope" 50
F1 "../Common_Modules/Gyroscope/breakout/Gyroscope.sch" 20
F2 "SCK" B L 9350 1600 50 
F3 "SDI" B L 9350 1700 50 
F4 "SDO" B L 9350 1800 50 
F5 "INT1_ACCEL" O R 10350 1850 50 
F6 "INT2_ACCEL" O R 10350 1750 50 
F7 "INT3_GYRO" O R 10350 1650 50 
F8 "INT4_GYRO" O R 10350 1550 50 
F9 "CSB_ACCEL" O L 9350 1900 50 
F10 "CSB_GYRO" O L 9350 2000 50 
$EndSheet
Wire Wire Line
	9350 1600 8550 1600
Wire Wire Line
	9350 1700 8550 1700
Wire Wire Line
	9350 1800 8550 1800
Wire Wire Line
	9350 1900 8550 1900
Wire Wire Line
	9350 2000 8550 2000
Text Label 8850 1600 0    50   ~ 0
SCLK
Text Label 8850 1700 0    50   ~ 0
MOSI
Text Label 8850 1800 0    50   ~ 0
MISO
Text Label 8650 1900 0    50   ~ 0
GYRO_ACCEL_CS
Text Label 8800 2000 0    50   ~ 0
GYRO_CS
$Sheet
S 800  6100 1250 600 
U 5F448D4B
F0 "Pyro Channels" 50
F1 "PyroChannels.sch" 20
F2 "arm" I R 2050 6200 50 
F3 "Fire1" I R 2050 6300 50 
F4 "1Correct" O R 2050 6500 50 
F5 "Fire2" I R 2050 6400 50 
F6 "2Correct" O R 2050 6600 50 
$EndSheet
Wire Wire Line
	2050 6200 2850 6200
Wire Wire Line
	2050 6300 2850 6300
Wire Wire Line
	2050 6400 2850 6400
Wire Wire Line
	2050 6500 2850 6500
Wire Wire Line
	2050 6600 2850 6600
Text Label 2400 6200 0    50   ~ 0
ARM
Text Label 2350 6300 0    50   ~ 0
FIRE1
Text Label 2350 6400 0    50   ~ 0
FIRE2
Text Label 2200 6500 0    50   ~ 0
CONTINUITY1
Text Label 2200 6600 0    50   ~ 0
CONTINUITY2
Wire Notes Line
	3100 550  3100 3900
Wire Notes Line
	3100 3900 700  3900
Wire Notes Line
	700  3900 700  550 
Wire Notes Line
	700  4150 3100 4150
Wire Notes Line
	3100 4150 3100 5500
Wire Notes Line
	3100 5500 700  5500
Wire Notes Line
	700  5500 700  4150
Text Notes 1000 5650 0    79   ~ 0
AUDIBLE/VISIBLE INDICATION\n
Wire Notes Line
	700  5850 3100 5850
Wire Notes Line
	3100 5850 3100 6850
Wire Notes Line
	700  6850 700  5850
Wire Notes Line
	700  6850 3100 6850
Text Notes 1450 7000 0    79   ~ 0
PYRO CHANNELS
Wire Notes Line
	8450 3400 10450 3400
Wire Notes Line
	10450 3400 10450 650 
Wire Notes Line
	10450 650  8450 650 
Wire Notes Line
	8450 650  8450 3400
Text Notes 9150 3650 0    79   ~ 0
SENSORS\n\n
Wire Wire Line
	2050 4400 2900 4400
Wire Wire Line
	2050 4550 2900 4550
Wire Wire Line
	2050 4700 2900 4700
Text Label 2350 4400 0    50   ~ 0
LED_RED
Text Label 2350 4550 0    50   ~ 0
LED_BLUE
Text Label 2350 4700 0    50   ~ 0
LED_GREEN
Wire Wire Line
	6800 1500 7600 1500
Text Label 6900 1500 0    50   ~ 0
GYRO_ACCEL_CS
Wire Wire Line
	6800 1750 7600 1750
Text Label 7050 1750 0    50   ~ 0
BUZZER
Wire Wire Line
	6800 2000 7600 2000
Wire Wire Line
	6800 2100 7600 2100
Wire Wire Line
	6800 2200 7600 2200
Text Label 7050 2000 0    50   ~ 0
LED_RED
Text Label 7050 2100 0    50   ~ 0
LED_BLUE
Text Label 7050 2200 0    50   ~ 0
LED_GREEN
$Sheet
S 4350 1100 2450 3150
U 5F317AC9
F0 "MCU" 50
F1 "MCU.sch" 20
F2 "RESET" I L 4350 1500 50 
F3 "CRYSTALIN" I L 4350 1750 50 
F4 "CRYSTALOUT" I L 4350 1850 50 
F5 "RTCCRYSTALIN" I L 4350 2000 50 
F6 "RTCCRYSTALOUT" I L 4350 2100 50 
F7 "TXD" I L 4350 2750 50 
F8 "RXD" I L 4350 2850 50 
F9 "VCAP" I L 4350 2350 50 
F10 "VSSA" I L 4350 2450 50 
F11 "VREF+" I L 4350 2550 50 
F12 "PA14" I L 4350 1300 50 
F13 "PA13" I L 4350 1200 50 
F14 "PA4" I L 4350 3150 50 
F15 "PA5" I L 4350 3250 50 
F16 "PA6" I L 4350 3350 50 
F17 "PA7" I L 4350 3450 50 
F18 "PB0" I R 6800 1200 50 
F19 "PB1" I R 6800 1300 50 
F20 "PB2" I R 6800 1400 50 
F21 "PC6" I R 6800 2200 50 
F22 "PC8" I R 6800 2400 50 
F23 "PC9" I R 6800 2500 50 
F24 "PA8" I R 6800 2600 50 
F25 "PA9" I R 6800 2700 50 
F26 "PA10" I R 6800 2800 50 
F27 "PB10" I R 6800 1500 50 
F28 "PB13" I R 6800 1750 50 
F29 "PB14" I R 6800 2000 50 
F30 "PB15" I R 6800 2100 50 
$EndSheet
Wire Wire Line
	6800 2400 7600 2400
Wire Wire Line
	6800 2500 7600 2500
Wire Wire Line
	6800 2600 7600 2600
Wire Wire Line
	6800 2700 7600 2700
Wire Wire Line
	6800 2800 7600 2800
Text Label 7150 2400 0    50   ~ 0
ARM
Text Label 7150 2500 0    50   ~ 0
FIRE1
Text Label 7150 2600 0    50   ~ 0
FIRE2
Text Label 6950 2700 0    50   ~ 0
CONTINUITY1
Text Label 6950 2800 0    50   ~ 0
CONTINUITY2
$Sheet
S 9400 2425 950  850 
U 5F46051D
F0 "Accelerometer" 50
F1 "Accelerometer.sch" 50
$EndSheet
$EndSCHEMATC
