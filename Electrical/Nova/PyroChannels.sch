EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 9 15
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
P 7550 5100
F 0 "C24" H 7665 5146 50  0000 L CNN
F 1 "1mF" H 7665 5055 50  0000 L CNN
F 2 "PyroChannel:CP_Radial_D10.0mm_P5.00mm" H 7588 4950 50  0001 C CNN
F 3 "~" H 7550 5100 50  0001 C CNN
F 4 "1189-3703-1-ND" H 7550 5100 50  0001 C CNN "digikey"
	1    7550 5100
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR035
U 1 1 5F449DDB
P 7550 3300
F 0 "#PWR035" H 7550 3150 50  0001 C CNN
F 1 "+BATT" H 7565 3473 50  0000 C CNN
F 2 "" H 7550 3300 50  0001 C CNN
F 3 "" H 7550 3300 50  0001 C CNN
	1    7550 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR036
U 1 1 5F44A4A7
P 7550 5400
F 0 "#PWR036" H 7550 5150 50  0001 C CNN
F 1 "GND" H 7555 5227 50  0000 C CNN
F 2 "" H 7550 5400 50  0001 C CNN
F 3 "" H 7550 5400 50  0001 C CNN
	1    7550 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 5250 7550 5350
Wire Wire Line
	7150 5250 7150 5350
Wire Wire Line
	7150 5350 7550 5350
Connection ~ 7550 5350
Wire Wire Line
	7550 5350 7550 5400
Wire Wire Line
	7150 4950 7150 4850
Wire Wire Line
	7150 4850 7550 4850
Wire Wire Line
	7550 4850 7550 4950
$Comp
L Device:R_US R5
U 1 1 5F6ECA83
P 7150 5100
F 0 "R5" H 7218 5146 50  0000 L CNN
F 1 "10k" H 7218 5055 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7190 5090 50  0001 C CNN
F 3 "~" H 7150 5100 50  0001 C CNN
	1    7150 5100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J5
U 1 1 6033E472
P 8150 3850
F 0 "J5" H 8178 3826 50  0000 L CNN
F 1 "Conn_01x04_Female" H 8178 3735 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PTSM-0,5-4-2.5-H-THR_1x04_P2.50mm_Horizontal" H 8150 3850 50  0001 C CNN
F 3 "" H 8150 3850 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/phoenix-contact/1770908/2192462" H 8150 3850 50  0001 C CNN "Order Link"
	1    8150 3850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J6
U 1 1 6033EDCD
P 8150 4550
F 0 "J6" H 8178 4526 50  0000 L CNN
F 1 "Conn_01x04_Female" H 8178 4435 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PTSM-0,5-4-2.5-H-THR_1x04_P2.50mm_Horizontal" H 8150 4550 50  0001 C CNN
F 3 "~" H 8150 4550 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/phoenix-contact/1770908/2192462" H 8150 4550 50  0001 C CNN "Order Link"
	1    8150 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 3750 7650 3750
Text Label 7900 3950 2    50   ~ 0
PYRO1
Wire Wire Line
	7950 3950 7650 3950
Text Label 7900 3750 2    50   ~ 0
PYRO2
Wire Wire Line
	7950 4450 7650 4450
Text Label 7900 4650 2    50   ~ 0
PYRO3
Wire Wire Line
	7950 4650 7650 4650
Text Label 7900 4450 2    50   ~ 0
PYRO4
$Comp
L Connector:Conn_01x02_Female J4
U 1 1 60348F4E
P 7800 3500
F 0 "J4" H 7828 3476 50  0000 L CNN
F 1 "Conn_01x02_Female" H 7828 3385 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PTSM-0,5-2-2.5-H-THR_1x02_P2.50mm_Horizontal" H 7800 3500 50  0001 C CNN
F 3 "~" H 7800 3500 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/phoenix-contact/1770885/2192460" H 7800 3500 50  0001 C CNN "Order Link"
	1    7800 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3300 7550 3500
Wire Wire Line
	7550 3500 7600 3500
Wire Wire Line
	7600 3600 7550 3600
Wire Wire Line
	7550 3600 7550 3850
Wire Wire Line
	7550 4850 7550 4750
Wire Wire Line
	7550 4750 7950 4750
Connection ~ 7550 4850
Wire Wire Line
	7550 4750 7550 4550
Wire Wire Line
	7550 4550 7950 4550
Connection ~ 7550 4750
Wire Wire Line
	7550 4050 7950 4050
Wire Wire Line
	7550 4050 7550 4550
Connection ~ 7550 4550
Wire Wire Line
	7550 3850 7550 4050
Wire Wire Line
	7550 3850 7950 3850
Connection ~ 7550 4050
Connection ~ 7550 3850
Text HLabel 5350 5250 2    50   Output ~ 0
4Correct
Wire Wire Line
	5350 5250 5050 5250
Wire Wire Line
	5350 5400 5050 5400
Text HLabel 5350 5400 2    50   Input ~ 0
Fire4
Text HLabel 5350 3150 2    50   Output ~ 0
1Correct
Wire Wire Line
	5350 3150 5050 3150
Wire Wire Line
	5350 3300 5050 3300
Text HLabel 5350 3300 2    50   Input ~ 0
Fire1
Wire Wire Line
	5350 3900 5050 3900
Wire Wire Line
	5350 4050 5050 4050
Text HLabel 5350 4050 2    50   Input ~ 0
Fire2
Text HLabel 5350 3900 2    50   Output ~ 0
2Correct
Wire Wire Line
	2100 4050 2300 4050
Text HLabel 2300 4050 2    50   Input ~ 0
arm
Wire Wire Line
	5050 4600 5350 4600
Wire Wire Line
	5350 4750 5050 4750
Text HLabel 5350 4600 2    50   Output ~ 0
3Correct
Text HLabel 5350 4750 2    50   Input ~ 0
Fire3
$EndSCHEMATC
