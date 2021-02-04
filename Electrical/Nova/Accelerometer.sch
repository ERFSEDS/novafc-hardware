EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 19 19
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
L Accelerometer_Breakout:H3LIS331DL U1
U 1 1 5F0CD93E
P 5750 3700
F 0 "U1" H 5750 4950 50  0000 C CNN
F 1 "H3LIS331DL" H 5750 4800 50  0000 C CNN
F 2 "digikey-footprints:TFLGA-16_3x3mm" H 5750 3750 50  0001 C CNN
F 3 "" H 5750 3750 50  0001 C CNN
	1    5750 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5F0CE4E4
P 7400 4400
F 0 "#PWR0103" H 7400 4150 50  0001 C CNN
F 1 "GND" H 7405 4227 50  0000 C CNN
F 2 "" H 7400 4400 50  0001 C CNN
F 3 "" H 7400 4400 50  0001 C CNN
	1    7400 4400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0104
U 1 1 5F0CE97E
P 7400 3300
F 0 "#PWR0104" H 7400 3150 50  0001 C CNN
F 1 "+3.3V" H 7415 3473 50  0000 C CNN
F 2 "" H 7400 3300 50  0001 C CNN
F 3 "" H 7400 3300 50  0001 C CNN
	1    7400 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5F0CF12A
P 4300 4250
F 0 "C2" V 4048 4250 50  0000 C CNN
F 1 "0.1uf" V 4139 4250 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4338 4100 50  0001 C CNN
F 3 "~" H 4300 4250 50  0001 C CNN
	1    4300 4250
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 5F0CF6C1
P 4300 3750
F 0 "C1" V 4048 3750 50  0000 C CNN
F 1 "10uf" V 4139 3750 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4338 3600 50  0001 C CNN
F 3 "~" H 4300 3750 50  0001 C CNN
	1    4300 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	4450 4250 4450 3750
Wire Wire Line
	4150 4250 4150 3750
Wire Wire Line
	4450 3750 4450 3500
Connection ~ 4450 3750
Wire Wire Line
	4150 3750 4150 3500
Connection ~ 4150 3750
Text Label 6450 3350 0    50   ~ 0
GND
Text Label 6450 3500 0    50   ~ 0
GND
Text Label 6450 3800 0    50   ~ 0
GND
Text Label 5600 2950 1    50   ~ 0
GND
Text Label 5050 3950 2    50   ~ 0
GND
Text Label 5050 3350 2    50   ~ 0
3.3V
Text Label 5900 2950 1    50   ~ 0
3.3V
Text Label 5750 2950 1    50   ~ 0
3.3V
Text Label 7400 3300 3    50   ~ 0
3.3V
Text HLabel 6450 3650 2    50   Input ~ 0
INT_1_ACC
Text HLabel 6450 3950 2    50   Input ~ 0
INT_2_ACC
Text HLabel 5900 4350 3    50   Input ~ 0
CS_ACC
Text HLabel 5750 4350 3    50   Input ~ 0
SDO_ACC
Text HLabel 5600 4350 3    50   Input ~ 0
SDA_ACC
Text HLabel 5050 3800 0    50   Input ~ 0
SCL_ACC
Text Label 4450 3500 1    50   ~ 0
GND
Text Label 4150 3500 1    50   ~ 0
3.3V
Text Label 7400 4400 1    50   ~ 0
GND
$EndSCHEMATC
