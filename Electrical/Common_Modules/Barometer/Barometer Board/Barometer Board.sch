EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 3
Title "Barometer-Breakout-Board"
Date "2020-07-04"
Rev "1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3500 3000 1500 1000
U 5F013144
F0 "Barometer" 50
F1 "Barometer.sch" 50
F2 "SCLK" I R 5000 3250 50 
F3 "SDI" I R 5000 3450 50 
F4 "SDO" I R 5000 3650 50 
F5 "CSB" I R 5000 3850 50 
$EndSheet
$Sheet
S 5500 3000 1500 1000
U 5F01E12A
F0 "Header-Pins" 50
F1 "Header-Pins.sch" 50
F2 "SCLK" I L 5500 3250 50 
F3 "SDI" I L 5500 3450 50 
F4 "SDO" I L 5500 3650 50 
F5 "CSB" I L 5500 3850 50 
$EndSheet
Wire Wire Line
	5000 3250 5500 3250
Wire Wire Line
	5500 3450 5000 3450
Wire Wire Line
	5000 3650 5500 3650
Wire Wire Line
	5500 3850 5000 3850
$EndSCHEMATC
