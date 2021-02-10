EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 20
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 6350 700  800  400 
U 5F3616EF
F0 "LED Indication" 50
F1 "LED Indication.sch" 20
F2 "LED_RED" I R 7150 800 50 
F3 "LED_BLUE" I R 7150 1000 50 
F4 "LED_GREEN" I R 7150 900 50 
$EndSheet
Text Label 1550 2750 0    50   ~ 0
RXD
Text Label 1550 2650 0    50   ~ 0
TXD
Wire Wire Line
	1450 2750 2250 2750
Wire Wire Line
	1450 2650 2250 2650
Text Label 1600 2300 0    50   ~ 0
VREF+
Text Label 1550 2100 0    50   ~ 0
VSSA
Text Label 1550 2000 0    50   ~ 0
VCAP
Wire Wire Line
	1450 2100 2250 2100
Wire Wire Line
	1450 2000 2250 2000
Wire Wire Line
	1450 800  2250 800 
Wire Wire Line
	1450 900  2250 900 
Wire Wire Line
	1450 1000 2250 1000
Text Label 1550 1350 0    50   ~ 0
CLOCKIN
Text Label 1550 3100 0    50   ~ 0
RESET
Wire Wire Line
	1450 3100 2250 3100
Text Notes 900  3600 0    79   ~ 0
MCU PERIPHERALS\n\n
$Sheet
S 6350 1250 800  150 
U 5F36176A
F0 "Buzzer" 50
F1 "Buzzer.sch" 20
$EndSheet
Text Notes 6300 1700 0    79   ~ 0
AUDIBLE/VISIBLE INDICATION\n
Text Label 7250 800  0    50   ~ 0
LED_RED
Text Label 7250 1000 0    50   ~ 0
LED_BLUE
Text Label 7250 900  0    50   ~ 0
LED_GREEN
$Sheet
S 650  700  800  400 
U 5F31B2A5
F0 "SWD" 50
F1 "../Common_Modules/MCU/Breakout/SWD .sch" 20
F2 "JTMS-SWDIO" I R 1450 800 50 
F3 "JTCK-SWCLK" I R 1450 900 50 
F4 "RESET" I R 1450 1000 50 
$EndSheet
$Sheet
S 650  3000 800  200 
U 5F317E00
F0 "MCU RESET" 50
F1 "../Common_Modules/MCU/Breakout/RESET.sch" 20
F2 "RESET" I R 1450 3100 50 
$EndSheet
$Sheet
S 650  1900 800  500 
U 5F3189B2
F0 "MCU FILTERING" 50
F1 "../Common_Modules/MCU/Breakout/FILTERING.sch" 20
F2 "VCAP" I R 1450 2000 50 
F3 "VSSA" I R 1450 2100 50 
F4 "VDDA" I R 1450 2200 50 
F5 "VREF+" I R 1450 2300 50 
$EndSheet
$Sheet
S 650  2550 800  300 
U 5F319D4B
F0 "USB-C" 50
F1 "../Common_Modules/MCU/Breakout/USB-C.sch" 20
F2 "TXD" O R 1450 2650 50 
F3 "RXD" I R 1450 2750 50 
$EndSheet
$Sheet
S 650  1250 800  500 
U 5F319C9C
F0 "CLOCKS" 50
F1 "../Common_Modules/MCU/Breakout/Clocks.sch" 20
F2 "CLOCKIN" I R 1450 1350 50 
F3 "RTCCRYSTALIN" I R 1450 1550 50 
F4 "CLOCKOUT" O R 1450 1450 50 
F5 "RTCCRYSTALOUT" O R 1450 1650 50 
$EndSheet
Wire Wire Line
	1450 1350 2250 1350
Wire Wire Line
	1450 1450 2250 1450
Wire Wire Line
	1450 1550 2250 1550
Wire Wire Line
	1450 1650 2250 1650
Text Label 1550 1450 0    50   ~ 0
CLOCKOUT
Text Label 1550 1550 0    50   ~ 0
32CLOCKIN
Text Label 1550 1650 0    50   ~ 0
32CLOCKOUT
Wire Notes Line
	550  3300 550  550 
Wire Notes Line
	2350 550  2350 3300
Wire Notes Line
	6250 550  6250 1550
Wire Wire Line
	7150 800  7950 800 
Wire Wire Line
	7150 900  7950 900 
Wire Wire Line
	7150 1000 7950 1000
Text Notes 3050 3550 0    79   ~ 0
SENSORS\n\n
Text Notes 4850 2300 0    79   ~ 0
DATA LOGGING\n
Text Label 5300 900  0    50   ~ 0
SCLK
Text Label 5300 1000 0    50   ~ 0
MOSI
Text Label 5300 1100 0    50   ~ 0
MISO
Wire Notes Line
	4350 550  4350 2150
Wire Notes Line
	6150 550  6150 2150
Text Label 1550 1000 0    50   ~ 0
RESET
Text Label 1550 900  0    50   ~ 0
SWCLK
Text Label 1550 800  0    50   ~ 0
SWDIO
Wire Wire Line
	1450 2300 1500 2300
Wire Wire Line
	1450 2200 1500 2200
Wire Wire Line
	1500 2200 1500 2300
Connection ~ 1500 2300
Wire Wire Line
	1500 2300 2250 2300
Text Notes 8650 3000 0    79   ~ 0
POWER SUPPLY\n
$Sheet
S 8250 2150 800  200 
U 5F3B0B4B
F0 "PowerSupply" 50
F1 "../Common_Modules/PowerSupply/Voltage Regulation Board/VoltageRegulators.sch" 20
$EndSheet
$Sheet
S 8250 2500 800  200 
U 5F964042
F0 "Voltage Monitor" 50
F1 "Voltage Monitor.sch" 50
$EndSheet
$Comp
L Mechanical:MountingHole H1
U 1 1 5FA45FD6
P 6800 2700
F 0 "H1" H 6900 2746 50  0000 L CNN
F 1 "MountingHole" H 6900 2655 50  0000 L CNN
F 2 "" H 6800 2700 50  0001 C CNN
F 3 "~" H 6800 2700 50  0001 C CNN
	1    6800 2700
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5FA46591
P 6800 2950
F 0 "H2" H 6900 2996 50  0000 L CNN
F 1 "MountingHole" H 6900 2905 50  0000 L CNN
F 2 "" H 6800 2950 50  0001 C CNN
F 3 "~" H 6800 2950 50  0001 C CNN
	1    6800 2950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5FA4C592
P 6800 3200
F 0 "H3" H 6900 3246 50  0000 L CNN
F 1 "MountingHole" H 6900 3155 50  0000 L CNN
F 2 "" H 6800 3200 50  0001 C CNN
F 3 "~" H 6800 3200 50  0001 C CNN
	1    6800 3200
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5FA525D1
P 6800 3450
F 0 "H4" H 6900 3496 50  0000 L CNN
F 1 "MountingHole" H 6900 3405 50  0000 L CNN
F 2 "" H 6800 3450 50  0001 C CNN
F 3 "~" H 6800 3450 50  0001 C CNN
	1    6800 3450
	1    0    0    -1  
$EndComp
Entry Bus Bus
	6750 2650 6850 2750
$Sheet
S 4450 1350 800  700 
U 5F3B5C2E
F0 "FlashChip" 50
F1 "../Common_Modules/FHSD/Flash SD Board/Flash Chip.sch" 20
F2 "IO0" B R 5250 1650 50 
F3 "IO1" B R 5250 1750 50 
F4 "IO2" B R 5250 1850 50 
F5 "IO3" B R 5250 1950 50 
F6 "SCL" I R 5250 1550 50 
F7 "CS_FL" I R 5250 1450 50 
$EndSheet
Text Notes 8600 1750 0    79   ~ 0
PYRO CHANNELS
Text Label 9150 1100 0    50   ~ 0
FIRE3
$Sheet
S 8250 700  800  800 
U 5F448D4B
F0 "Pyro Channels" 50
F1 "PyroChannels.sch" 20
F2 "arm" I R 9050 800 50 
F3 "Fire1" I R 9050 900 50 
F4 "1Correct" O R 9050 1200 50 
F5 "Fire2" I R 9050 1000 50 
F6 "2Correct" O R 9050 1300 50 
F7 "Fire3" I R 9050 1100 50 
F8 "3Correct" O R 9050 1400 50 
$EndSheet
Text Label 9150 1000 0    50   ~ 0
FIRE2
Text Label 9150 900  0    50   ~ 0
FIRE1
Text Label 9150 800  0    50   ~ 0
ARM
Wire Notes Line
	8150 550  8150 1600
Wire Wire Line
	9050 800  9850 800 
Wire Wire Line
	9050 900  9850 900 
Wire Wire Line
	9050 1000 9850 1000
Wire Wire Line
	9050 1200 9850 1200
Wire Wire Line
	9050 1300 9850 1300
Text Label 9150 1200 0    50   ~ 0
CONTINUITY1
Text Label 9150 1300 0    50   ~ 0
CONTINUITY2
Wire Wire Line
	9050 1100 9850 1100
Wire Wire Line
	9050 1400 9850 1400
Text Label 9150 1400 0    50   ~ 0
CONTINUITY3
Wire Notes Line
	550  550  2350 550 
Wire Notes Line
	550  3300 2350 3300
Wire Notes Line
	6250 550  8050 550 
Wire Notes Line
	8050 550  8050 1550
Wire Notes Line
	8050 1550 6250 1550
Wire Notes Line
	8150 550  9950 550 
Wire Notes Line
	9950 550  9950 1600
Wire Notes Line
	9950 1600 8150 1600
Wire Notes Line
	8150 2000 9950 2000
Wire Notes Line
	9950 2000 9950 2850
Wire Notes Line
	9950 2850 8150 2850
Wire Notes Line
	8150 2000 8150 2850
Wire Wire Line
	4150 900  3350 900 
$Sheet
S 2550 700  800  475 
U 5F46051D
F0 "Accelerometer" 50
F1 "../Common_Modules/Accelerometer_Breakout/Breakout_Board/H3LIS331DL_Accelerometer.sch" 20
F2 "CS_ACC" I R 3350 800 50 
F3 "SCL" I R 3350 900 50 
F4 "MISO" O R 3350 1100 50 
F5 "MOSI" I R 3350 1000 50 
$EndSheet
Text Label 3450 900  0    50   ~ 0
SCLK
Text Label 3450 1000 0    50   ~ 0
MOSI
Text Label 3450 1100 0    50   ~ 0
MISO
Wire Wire Line
	4150 800  3350 800 
Wire Wire Line
	4150 1100 3350 1100
Wire Wire Line
	4150 1000 3350 1000
Text Label 3450 800  0    50   ~ 0
ACCELEROMETER_CS
$Sheet
S 2550 1350 800  500 
U 5F3A063C
F0 "Barometer" 50
F1 "../Common_Modules/Barometer/Barometer Board/Barometer.sch" 20
F2 "SCL" I R 3350 1550 50 
F3 "MOSI" I R 3350 1650 50 
F4 "MISO" O R 3350 1750 50 
F5 "CS_BARO" I R 3350 1450 50 
$EndSheet
Text Label 3450 1550 0    50   ~ 0
SCLK
Text Label 3450 1750 0    50   ~ 0
MISO
Text Label 3450 1650 0    50   ~ 0
MOSI
Text Label 3450 1450 0    50   ~ 0
BAROMETER_CS
Wire Wire Line
	3350 1450 4150 1450
Wire Wire Line
	4150 1750 3350 1750
Wire Wire Line
	4150 1650 3350 1650
Wire Wire Line
	4150 1550 3350 1550
Wire Wire Line
	6050 900  5250 900 
Wire Wire Line
	6050 1100 5250 1100
Wire Wire Line
	5250 1000 6050 1000
Wire Wire Line
	6050 800  5250 800 
Text Label 5300 800  0    50   ~ 0
SD_CS
$Sheet
S 4450 700  800  500 
U 5F3B5BD1
F0 "MicroSD" 50
F1 "../Common_Modules/FHSD/Flash SD Board/Micro SD.sch" 20
F2 "MISO" O R 5250 1100 50 
F3 "MOSI" I R 5250 1000 50 
F4 "SCLK" I R 5250 900 50 
F5 "CS_SD" I R 5250 800 50 
$EndSheet
Wire Wire Line
	6050 1550 5250 1550
Wire Wire Line
	6050 1750 5250 1750
Wire Wire Line
	5250 1650 6050 1650
Wire Wire Line
	6050 1450 5250 1450
Wire Wire Line
	6050 1950 5250 1950
Wire Wire Line
	6050 1850 5250 1850
Text Label 5350 1450 0    50   ~ 0
FL_CS
Text Label 5350 1550 0    50   ~ 0
SCLK
Text Label 5350 1650 0    50   ~ 0
IO0
Text Label 5350 1750 0    50   ~ 0
IO1
Text Label 5350 1850 0    50   ~ 0
IO2
Text Label 5350 1950 0    50   ~ 0
IO3
Wire Notes Line
	2450 3300 4250 3300
Wire Notes Line
	2450 550  4250 550 
Wire Notes Line
	4350 550  6150 550 
Wire Notes Line
	6150 2150 4350 2150
$Sheet
S 2550 2050 800  1100
U 6029A10C
F0 "IMU" 50
F1 "../Common_Modules/IMU/LSM9DS1.sch" 50
F2 "CS_AG" I R 3350 2150 50 
F3 "MOSI" I R 3350 2350 50 
F4 "SCL" I R 3350 2250 50 
F5 "MISO" O R 3350 2450 50 
F6 "INT1" I R 3350 2550 50 
F7 "INT2" I R 3350 2650 50 
F8 "DEN" I R 3350 2750 50 
F9 "CS_M" I R 3350 2850 50 
F10 "DRDYM" I R 3350 2950 50 
F11 "INTM" I R 3350 3050 50 
$EndSheet
Wire Notes Line
	4250 550  4250 3300
Wire Notes Line
	2450 550  2450 3300
Wire Wire Line
	4150 2150 3350 2150
Wire Wire Line
	4150 2250 3350 2250
Wire Wire Line
	4150 2350 3350 2350
Wire Wire Line
	4150 2450 3350 2450
Wire Wire Line
	4150 2550 3350 2550
Wire Wire Line
	4150 2650 3350 2650
Wire Wire Line
	4150 2750 3350 2750
Wire Wire Line
	4150 2850 3350 2850
Wire Wire Line
	4150 2950 3350 2950
Wire Wire Line
	4150 3050 3350 3050
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J?
U 1 1 602F4EF9
P 5150 2800
F 0 "J?" H 5200 3217 50  0000 C CNN
F 1 "Conn_02x05_Counter_Clockwise" H 5200 3126 50  0000 C CNN
F 2 "" H 5150 2800 50  0001 C CNN
F 3 "~" H 5150 2800 50  0001 C CNN
	1    5150 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 602F8265
P 4800 2600
F 0 "#PWR?" H 4800 2350 50  0001 C CNN
F 1 "GND" V 4805 2472 50  0000 R CNN
F 2 "" H 4800 2600 50  0001 C CNN
F 3 "" H 4800 2600 50  0001 C CNN
	1    4800 2600
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 602F8700
P 4800 2700
F 0 "#PWR?" H 4800 2550 50  0001 C CNN
F 1 "+3.3V" V 4815 2828 50  0000 L CNN
F 2 "" H 4800 2700 50  0001 C CNN
F 3 "" H 4800 2700 50  0001 C CNN
	1    4800 2700
	0    -1   -1   0   
$EndComp
$Comp
L power:+BATT #PWR?
U 1 1 602F8B35
P 5600 2600
F 0 "#PWR?" H 5600 2450 50  0001 C CNN
F 1 "+BATT" V 5615 2728 50  0000 L CNN
F 2 "" H 5600 2600 50  0001 C CNN
F 3 "" H 5600 2600 50  0001 C CNN
	1    5600 2600
	0    1    1    0   
$EndComp
Text HLabel 4800 2800 0    50   Input ~ 0
SCLK
Text HLabel 4800 2900 0    50   Input ~ 0
MISO
Text HLabel 4800 3000 0    50   Input ~ 0
MOSI
Text HLabel 5600 2700 2    50   Input ~ 0
GPIO0
Text HLabel 5600 2800 2    50   Input ~ 0
GPIO1
Text HLabel 5600 2900 2    50   Input ~ 0
GPIO2
Text HLabel 5600 3000 2    50   Input ~ 0
GPIO3
Wire Wire Line
	4800 2600 4950 2600
Wire Wire Line
	4950 2700 4800 2700
Wire Wire Line
	4800 2800 4950 2800
Wire Wire Line
	4950 2900 4800 2900
Wire Wire Line
	4800 3000 4950 3000
Wire Wire Line
	5450 2600 5600 2600
Wire Wire Line
	5600 2700 5450 2700
Wire Wire Line
	5450 2800 5600 2800
Wire Wire Line
	5600 2900 5450 2900
Wire Wire Line
	5450 3000 5600 3000
$EndSCHEMATC
