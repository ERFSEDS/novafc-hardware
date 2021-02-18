EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 10 21
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:C C24
U 1 1 5F4497A2
P 2700 3150
F 0 "C24" H 2815 3196 50  0000 L CNN
F 1 "1mF" H 2815 3105 50  0000 L CNN
F 2 "" H 2738 3000 50  0001 C CNN
F 3 "~" H 2700 3150 50  0001 C CNN
F 4 "1189-3703-1-ND" H 2700 3150 50  0001 C CNN "digikey"
	1    2700 3150
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR035
U 1 1 5F449DDB
P 2700 2350
F 0 "#PWR035" H 2700 2200 50  0001 C CNN
F 1 "+BATT" H 2715 2523 50  0000 C CNN
F 2 "" H 2700 2350 50  0001 C CNN
F 3 "" H 2700 2350 50  0001 C CNN
	1    2700 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR036
U 1 1 5F44A4A7
P 2700 3450
F 0 "#PWR036" H 2700 3200 50  0001 C CNN
F 1 "GND" H 2705 3277 50  0000 C CNN
F 2 "" H 2700 3450 50  0001 C CNN
F 3 "" H 2700 3450 50  0001 C CNN
	1    2700 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 3300 2700 3400
Wire Wire Line
	2300 3300 2300 3400
Wire Wire Line
	2300 3400 2700 3400
Connection ~ 2700 3400
Wire Wire Line
	2700 3400 2700 3450
Wire Wire Line
	2300 3000 2300 2900
Wire Wire Line
	2300 2900 2700 2900
Connection ~ 2700 2900
Wire Wire Line
	2700 2900 2700 3000
$Comp
L Device:R_US R5
U 1 1 5F6ECA83
P 2300 3150
F 0 "R5" H 2368 3196 50  0000 L CNN
F 1 "10k" H 2368 3105 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2340 3140 50  0001 C CNN
F 3 "~" H 2300 3150 50  0001 C CNN
	1    2300 3150
	1    0    0    -1  
$EndComp
Text HLabel 5350 4750 2    50   Input ~ 0
Fire3
Text HLabel 5350 4600 2    50   Output ~ 0
3Correct
$Sheet
S 4200 4500 850  350 
U 5F71312E
F0 "Channel 3" 50
F1 "../Common_Modules/PyroChannel/Breakout/PyroChannel.sch" 50
F2 "FIRE" I R 5050 4600 50 
F3 "pyroCorrect" O R 5050 4750 50 
F4 "fireOut" O L 4200 4600 50 
F5 "Pyro" O L 4200 4750 50 
$EndSheet
Wire Wire Line
	5350 4750 5050 4750
Wire Wire Line
	5050 4600 5350 4600
Wire Wire Line
	4200 3900 3150 3900
Wire Wire Line
	4200 3150 3150 3150
Wire Wire Line
	3150 3150 3150 3900
Connection ~ 3150 3900
Wire Wire Line
	3150 3900 2100 3900
Wire Wire Line
	3150 3900 3150 4600
Wire Wire Line
	3150 4600 4200 4600
Text HLabel 2300 4050 2    50   Input ~ 0
arm
Wire Wire Line
	2100 4050 2300 4050
Text HLabel 5350 3900 2    50   Output ~ 0
2Correct
Text HLabel 5350 4050 2    50   Input ~ 0
Fire2
Wire Wire Line
	5350 4050 5050 4050
Wire Wire Line
	5350 3900 5050 3900
$Sheet
S 4200 3800 850  350 
U 5F449170
F0 "Channel 2" 50
F1 "../Common_Modules/PyroChannel/Breakout/PyroChannel.sch" 50
F2 "FIRE" I R 5050 3900 50 
F3 "pyroCorrect" O R 5050 4050 50 
F4 "fireOut" O L 4200 3900 50 
F5 "Pyro" O L 4200 4050 50 
$EndSheet
Text HLabel 5350 3300 2    50   Input ~ 0
Fire1
Wire Wire Line
	5350 3300 5050 3300
Wire Wire Line
	5350 3150 5050 3150
Text HLabel 5350 3150 2    50   Output ~ 0
1Correct
$Sheet
S 4200 3050 850  350 
U 5F44909A
F0 "Channel 1" 50
F1 "../Common_Modules/PyroChannel/Breakout/PyroChannel.sch" 50
F2 "FIRE" I R 5050 3150 50 
F3 "pyroCorrect" O R 5050 3300 50 
F4 "fireOut" O L 4200 3150 50 
F5 "Pyro" O L 4200 3300 50 
$EndSheet
Wire Wire Line
	4200 3300 3900 3300
Wire Wire Line
	4200 4050 3900 4050
Wire Wire Line
	4200 4750 3900 4750
$Sheet
S 1550 3800 550  350 
U 5F448D89
F0 "Arm Schematic" 50
F1 "../Common_Modules/PyroChannel/Breakout/ArmSchematic.sch" 50
F2 "FireOut" I R 2100 3900 50 
F3 "arm" I R 2100 4050 50 
$EndSheet
Text HLabel 5350 5400 2    50   Input ~ 0
Fire4
Wire Wire Line
	5350 5400 5050 5400
Wire Wire Line
	5350 5250 5050 5250
Text HLabel 5350 5250 2    50   Output ~ 0
4Correct
$Sheet
S 4200 5150 850  350 
U 6040FF20
F0 "Channel 4" 50
F1 "../Common_Modules/PyroChannel/Breakout/PyroChannel.sch" 50
F2 "FIRE" I R 5050 5250 50 
F3 "pyroCorrect" O R 5050 5400 50 
F4 "fireOut" O L 4200 5250 50 
F5 "Pyro" O L 4200 5400 50 
$EndSheet
Wire Wire Line
	4200 5400 3900 5400
Wire Wire Line
	3150 5250 4200 5250
Wire Wire Line
	3150 4600 3150 5250
Connection ~ 3150 4600
Text Label 4150 3300 2    50   ~ 0
PYRO1
Text Label 4150 4050 2    50   ~ 0
PYRO2
Text Label 4150 4750 2    50   ~ 0
PYRO3
Text Label 4150 5400 2    50   ~ 0
PYRO4
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 6033E472
P 8000 3900
F 0 "J?" H 8028 3876 50  0000 L CNN
F 1 "Conn_01x04_Female" H 8028 3785 50  0000 L CNN
F 2 "" H 8000 3900 50  0001 C CNN
F 3 "~" H 8000 3900 50  0001 C CNN
	1    8000 3900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 6033EDCD
P 8000 4600
F 0 "J?" H 8028 4576 50  0000 L CNN
F 1 "Conn_01x04_Female" H 8028 4485 50  0000 L CNN
F 2 "" H 8000 4600 50  0001 C CNN
F 3 "~" H 8000 4600 50  0001 C CNN
	1    8000 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 3800 7500 3800
Text Label 7750 3800 2    50   ~ 0
PYRO1
Wire Wire Line
	7800 4000 7500 4000
Text Label 7750 4000 2    50   ~ 0
PYRO2
Wire Wire Line
	7800 4500 7500 4500
Text Label 7750 4500 2    50   ~ 0
PYRO3
Wire Wire Line
	7800 4700 7500 4700
Text Label 7750 4700 2    50   ~ 0
PYRO4
$Comp
L power:GND #PWR?
U 1 1 60342F05
P 7500 3900
F 0 "#PWR?" H 7500 3650 50  0001 C CNN
F 1 "GND" V 7505 3772 50  0000 R CNN
F 2 "" H 7500 3900 50  0001 C CNN
F 3 "" H 7500 3900 50  0001 C CNN
	1    7500 3900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 603438C3
P 7500 4100
F 0 "#PWR?" H 7500 3850 50  0001 C CNN
F 1 "GND" V 7505 3972 50  0000 R CNN
F 2 "" H 7500 4100 50  0001 C CNN
F 3 "" H 7500 4100 50  0001 C CNN
	1    7500 4100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60343E90
P 7500 4600
F 0 "#PWR?" H 7500 4350 50  0001 C CNN
F 1 "GND" V 7505 4472 50  0000 R CNN
F 2 "" H 7500 4600 50  0001 C CNN
F 3 "" H 7500 4600 50  0001 C CNN
	1    7500 4600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 603444B0
P 7500 4800
F 0 "#PWR?" H 7500 4550 50  0001 C CNN
F 1 "GND" V 7505 4672 50  0000 R CNN
F 2 "" H 7500 4800 50  0001 C CNN
F 3 "" H 7500 4800 50  0001 C CNN
	1    7500 4800
	0    1    1    0   
$EndComp
Wire Wire Line
	7800 4800 7500 4800
Wire Wire Line
	7500 4600 7800 4600
Wire Wire Line
	7800 4100 7500 4100
Wire Wire Line
	7500 3900 7800 3900
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 60348F4E
P 2950 2550
F 0 "J?" H 2978 2526 50  0000 L CNN
F 1 "Conn_01x02_Female" H 2978 2435 50  0000 L CNN
F 2 "" H 2950 2550 50  0001 C CNN
F 3 "~" H 2950 2550 50  0001 C CNN
	1    2950 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 2350 2700 2550
Wire Wire Line
	2700 2550 2750 2550
Wire Wire Line
	2750 2650 2700 2650
Wire Wire Line
	2700 2650 2700 2900
$EndSCHEMATC
