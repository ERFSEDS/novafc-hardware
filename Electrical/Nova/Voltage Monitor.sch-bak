EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 9 20
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
L Amplifier_Operational:OP179GRT U5
U 1 1 5F935857
P 5700 3900
F 0 "U5" H 5750 3750 50  0000 L CNN
F 1 "OP179GRT" H 5700 4050 50  0000 L CNN
F 2 "" H 5700 3900 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/OP179_279.pdf" H 5700 4100 50  0001 C CNN
	1    5700 3900
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0111
U 1 1 5F93B73B
P 4850 3300
F 0 "#PWR0111" H 4850 3150 50  0001 C CNN
F 1 "+BATT" H 4865 3473 50  0000 C CNN
F 2 "" H 4850 3300 50  0001 C CNN
F 3 "" H 4850 3300 50  0001 C CNN
	1    4850 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5F93C2F4
P 5600 4200
F 0 "#PWR0112" H 5600 3950 50  0001 C CNN
F 1 "GND" H 5605 4027 50  0000 C CNN
F 2 "" H 5600 4200 50  0001 C CNN
F 3 "" H 5600 4200 50  0001 C CNN
	1    5600 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3300 4850 3400
Wire Wire Line
	4850 3700 4850 3800
Wire Wire Line
	4850 4200 4850 4300
Connection ~ 4850 3800
Wire Wire Line
	4850 3800 4850 3900
Wire Wire Line
	4850 3800 5400 3800
Wire Wire Line
	5150 4000 5400 4000
Wire Wire Line
	6200 3900 6650 3900
Wire Wire Line
	6000 3900 6200 3900
Connection ~ 6200 3900
Wire Wire Line
	6200 4500 5150 4500
$Comp
L power:+3.3V #PWR0113
U 1 1 5F94E8D1
P 5600 3550
F 0 "#PWR0113" H 5600 3400 50  0001 C CNN
F 1 "+3.3V" H 5615 3723 50  0000 C CNN
F 2 "" H 5600 3550 50  0001 C CNN
F 3 "" H 5600 3550 50  0001 C CNN
	1    5600 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5F94FFAB
P 4850 4300
F 0 "#PWR0114" H 4850 4050 50  0001 C CNN
F 1 "GND" H 4855 4127 50  0000 C CNN
F 2 "" H 4850 4300 50  0001 C CNN
F 3 "" H 4850 4300 50  0001 C CNN
	1    4850 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3900 6200 4500
Wire Wire Line
	5150 4000 5150 4500
Text Notes 5800 3500 0    50   ~ 0
Battrty voltage is from 10V to 7.3V\n+BATT == Vout\n10V == 3.298V\n7.3V == 2.407V\n0V == 0V
Text HLabel 6650 3900 2    50   Output ~ 0
MonitorPin
$Comp
L Device:R_US R19
U 1 1 6024316E
P 4850 3550
F 0 "R19" H 4918 3596 50  0000 L CNN
F 1 "95.5k" H 4918 3505 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4890 3540 50  0001 C CNN
F 3 "~" H 4850 3550 50  0001 C CNN
	1    4850 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R20
U 1 1 60243E65
P 4850 4050
F 0 "R20" H 4918 4096 50  0000 L CNN
F 1 "47k" H 4918 4005 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4890 4040 50  0001 C CNN
F 3 "~" H 4850 4050 50  0001 C CNN
	1    4850 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 3600 5600 3550
$EndSCHEMATC
