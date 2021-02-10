EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 12 21
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
S 6700 3400 1850 850 
U 5F448D89
F0 "Arm Schematic" 50
F1 "../Common_Modules/PyroChannel/Breakout/ArmSchematic.sch" 50
F2 "FireOut" I L 6700 3600 50 
F3 "arm" I L 6700 3950 50 
$EndSheet
Wire Wire Line
	6700 3600 6250 3600
Wire Wire Line
	4150 2900 3750 2900
Wire Wire Line
	3750 2750 4150 2750
Wire Wire Line
	4150 3450 3850 3450
Wire Wire Line
	4150 3600 3850 3600
$Comp
L Device:C C24
U 1 1 5F4497A2
P 2900 3650
F 0 "C24" H 3015 3696 50  0000 L CNN
F 1 "1mF" H 3015 3605 50  0000 L CNN
F 2 "PyroChannel:CP_Radial_D10.0mm_P5.00mm" H 2938 3500 50  0001 C CNN
F 3 "~" H 2900 3650 50  0001 C CNN
F 4 "1189-3703-1-ND" H 2900 3650 50  0001 C CNN "digikey"
	1    2900 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR035
U 1 1 5F449DDB
P 2900 3350
F 0 "#PWR035" H 2900 3200 50  0001 C CNN
F 1 "+BATT" H 2915 3523 50  0000 C CNN
F 2 "" H 2900 3350 50  0001 C CNN
F 3 "" H 2900 3350 50  0001 C CNN
	1    2900 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3350 2900 3400
$Comp
L power:GND #PWR036
U 1 1 5F44A4A7
P 2900 3950
F 0 "#PWR036" H 2900 3700 50  0001 C CNN
F 1 "GND" H 2905 3777 50  0000 C CNN
F 2 "" H 2900 3950 50  0001 C CNN
F 3 "" H 2900 3950 50  0001 C CNN
	1    2900 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3800 2900 3900
Text HLabel 3750 2750 0    50   Input ~ 0
Fire1
Text HLabel 3750 2900 0    50   Output ~ 0
1Correct
Text HLabel 3850 3450 0    50   Input ~ 0
Fire2
Text HLabel 3850 3600 0    50   Output ~ 0
2Correct
Wire Wire Line
	2500 3800 2500 3900
Wire Wire Line
	2500 3900 2900 3900
Connection ~ 2900 3900
Wire Wire Line
	2900 3900 2900 3950
Wire Wire Line
	2500 3500 2500 3400
Wire Wire Line
	2500 3400 2900 3400
Connection ~ 2900 3400
Wire Wire Line
	2900 3400 2900 3500
$Comp
L Device:R_US R5
U 1 1 5F6ECA83
P 2500 3650
F 0 "R5" H 2568 3696 50  0000 L CNN
F 1 "10k" H 2568 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2540 3640 50  0001 C CNN
F 3 "~" H 2500 3650 50  0001 C CNN
	1    2500 3650
	1    0    0    -1  
$EndComp
$Sheet
S 4150 3350 1000 400 
U 5F449170
F0 "Channel 2" 50
F1 "../Common_Modules/PyroChannel/Breakout/PyroChannel.sch" 50
F2 "FIRE" I L 4150 3450 50 
F3 "pyroCorrect" O L 4150 3600 50 
F4 "fireOut" O R 5150 3450 50 
$EndSheet
$Sheet
S 4150 2650 1000 400 
U 5F44909A
F0 "Channel 1" 50
F1 "../Common_Modules/PyroChannel/Breakout/PyroChannel.sch" 50
F2 "FIRE" I L 4150 2750 50 
F3 "pyroCorrect" O L 4150 2900 50 
F4 "fireOut" O R 5150 2750 50 
$EndSheet
Wire Wire Line
	5150 3450 6250 3450
Wire Wire Line
	6250 3450 6250 3600
Wire Wire Line
	6250 3450 6250 2750
Wire Wire Line
	6250 2750 5150 2750
Connection ~ 6250 3450
Wire Wire Line
	5150 4150 6250 4150
Wire Wire Line
	6250 4150 6250 3600
Connection ~ 6250 3600
Text HLabel 3850 4150 0    50   Input ~ 0
Fire3
Text HLabel 3850 4300 0    50   Input ~ 0
3Correct
Wire Wire Line
	3850 4150 4150 4150
Wire Wire Line
	4150 4300 3850 4300
$Sheet
S 4150 4050 1000 400 
U 5F71312E
F0 "Channel 3" 50
F1 "../Common_Modules/PyroChannel/Breakout/PyroChannel.sch" 50
F2 "FIRE" I L 4150 4150 50 
F3 "pyroCorrect" O L 4150 4300 50 
F4 "fireOut" O R 5150 4150 50 
$EndSheet
Text HLabel 6500 3950 0    50   Input ~ 0
arm
Wire Wire Line
	6500 3950 6700 3950
$EndSCHEMATC
