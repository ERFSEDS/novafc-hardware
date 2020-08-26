EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 14 19
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
$Sheet
S 4800 2800 1000 400 
U 5F44909A
F0 "Channel 1" 50
F1 "../Common_Modules/PyroChannel/Breakout/PyroChannel.sch" 50
F2 "FIRE" I L 4800 2900 50 
F3 "pyroCorrect" O L 4800 3050 50 
F4 "fireOut" O R 5800 2900 50 
$EndSheet
$Sheet
S 4750 4600 1000 400 
U 5F449170
F0 "Channel 2" 50
F1 "../Common_Modules/PyroChannel/Breakout/PyroChannel.sch" 50
F2 "FIRE" I L 4750 4700 50 
F3 "pyroCorrect" O L 4750 4850 50 
F4 "fireOut" O R 5750 4700 50 
$EndSheet
Wire Wire Line
	6700 3600 6250 3600
Wire Wire Line
	6250 3600 6250 4700
Wire Wire Line
	6250 4700 5750 4700
Wire Wire Line
	5800 2900 6250 2900
Wire Wire Line
	6250 2900 6250 3600
Connection ~ 6250 3600
Wire Wire Line
	6700 3950 6350 3950
Wire Wire Line
	4800 3050 4400 3050
Wire Wire Line
	4400 2900 4800 2900
Wire Wire Line
	4750 4700 4450 4700
Wire Wire Line
	4750 4850 4450 4850
$Comp
L Device:C C1401
U 1 1 5F4497A2
P 2900 3650
F 0 "C1401" H 3015 3696 50  0000 L CNN
F 1 "1mF" H 3015 3605 50  0000 L CNN
F 2 "PyroChannel:CP_Radial_D10.0mm_P5.00mm" H 2938 3500 50  0001 C CNN
F 3 "~" H 2900 3650 50  0001 C CNN
F 4 "1189-3703-1-ND" H 2900 3650 50  0001 C CNN "digikey"
	1    2900 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR01401
U 1 1 5F449DDB
P 2900 3350
F 0 "#PWR01401" H 2900 3200 50  0001 C CNN
F 1 "+BATT" H 2915 3523 50  0000 C CNN
F 2 "" H 2900 3350 50  0001 C CNN
F 3 "" H 2900 3350 50  0001 C CNN
	1    2900 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3350 2900 3500
$Comp
L power:GND #PWR01402
U 1 1 5F44A4A7
P 2900 3950
F 0 "#PWR01402" H 2900 3700 50  0001 C CNN
F 1 "GND" H 2905 3777 50  0000 C CNN
F 2 "" H 2900 3950 50  0001 C CNN
F 3 "" H 2900 3950 50  0001 C CNN
	1    2900 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3800 2900 3950
Text HLabel 6350 3950 0    50   Input ~ 0
arm
Text HLabel 4400 2900 0    50   Input ~ 0
Fire1
Text HLabel 4400 3050 0    50   Output ~ 0
1Correct
Text HLabel 4450 4700 0    50   Input ~ 0
Fire2
Text HLabel 4450 4850 0    50   Output ~ 0
2Correct
$EndSCHEMATC
