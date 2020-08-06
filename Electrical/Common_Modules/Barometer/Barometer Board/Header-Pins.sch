EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 5900 3500 2    50   Input ~ 0
SCLK
Text HLabel 5900 3600 2    50   Input ~ 0
SDI
Text HLabel 5900 3700 2    50   Input ~ 0
SDO
Text HLabel 5900 3800 2    50   Input ~ 0
CSB
$Comp
L Connector:Conn_01x06_Male Header-Pins301
U 1 1 5F01E54D
P 4950 3700
F 0 "Header-Pins301" H 5058 4081 50  0000 C CNN
F 1 "Conn_01x06_Male" H 5058 3990 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 4950 3700 50  0001 C CNN
F 3 "~" H 4950 3700 50  0001 C CNN
	1    4950 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0301
U 1 1 5F01F229
P 5650 4000
F 0 "#PWR0301" H 5650 3850 50  0001 C CNN
F 1 "+3.3V" V 5665 4128 50  0000 L CNN
F 2 "" H 5650 4000 50  0001 C CNN
F 3 "" H 5650 4000 50  0001 C CNN
	1    5650 4000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0302
U 1 1 5F01FCCB
P 5650 3900
F 0 "#PWR0302" H 5650 3650 50  0001 C CNN
F 1 "GND" V 5655 3772 50  0000 R CNN
F 2 "" H 5650 3900 50  0001 C CNN
F 3 "" H 5650 3900 50  0001 C CNN
	1    5650 3900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5150 3500 5900 3500
Wire Wire Line
	5150 3600 5900 3600
Wire Wire Line
	5150 3700 5900 3700
Wire Wire Line
	5150 3800 5900 3800
Wire Wire Line
	5150 4000 5400 4000
Wire Wire Line
	5650 3900 5400 3900
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5F03E03C
P 5400 3900
F 0 "#FLG?" H 5400 3975 50  0001 C CNN
F 1 "PWR_FLAG" H 5400 4073 50  0000 C CNN
F 2 "" H 5400 3900 50  0001 C CNN
F 3 "~" H 5400 3900 50  0001 C CNN
	1    5400 3900
	1    0    0    -1  
$EndComp
Connection ~ 5400 3900
Wire Wire Line
	5400 3900 5150 3900
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5F03E983
P 5400 4000
F 0 "#FLG?" H 5400 4075 50  0001 C CNN
F 1 "PWR_FLAG" H 5400 4173 50  0000 C CNN
F 2 "" H 5400 4000 50  0001 C CNN
F 3 "~" H 5400 4000 50  0001 C CNN
	1    5400 4000
	-1   0    0    1   
$EndComp
Connection ~ 5400 4000
Wire Wire Line
	5400 4000 5650 4000
$EndSCHEMATC
