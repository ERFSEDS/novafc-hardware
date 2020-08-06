EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 4
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
L Connector:Conn_01x16_Male J?
U 1 1 5F0D6E62
P 6200 3950
AR Path="/5F0D6E62" Ref="J?"  Part="1" 
AR Path="/5F0CC5A4/5F0D6E62" Ref="J301"  Part="1" 
F 0 "J301" H 6172 3832 50  0000 R CNN
F 1 "16PinConnector" H 6172 3923 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Vertical" H 6200 3950 50  0001 C CNN
F 3 "~" H 6200 3950 50  0001 C CNN
	1    6200 3950
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5F0D6E68
P 5850 3050
AR Path="/5F0D6E68" Ref="#PWR?"  Part="1" 
AR Path="/5F0CC5A4/5F0D6E68" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 5850 2900 50  0001 C CNN
F 1 "+3V3" H 5865 3223 50  0000 C CNN
F 2 "" H 5850 3050 50  0001 C CNN
F 3 "" H 5850 3050 50  0001 C CNN
	1    5850 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3850 5850 3850
Wire Wire Line
	5850 3850 5850 3750
Wire Wire Line
	6000 3150 5850 3150
Connection ~ 5850 3150
Wire Wire Line
	5850 3150 5850 3050
Wire Wire Line
	6000 3250 5850 3250
Connection ~ 5850 3250
Wire Wire Line
	5850 3250 5850 3150
Wire Wire Line
	6000 3350 5850 3350
Connection ~ 5850 3350
Wire Wire Line
	5850 3350 5850 3250
Wire Wire Line
	6000 3450 5850 3450
Connection ~ 5850 3450
Wire Wire Line
	5850 3450 5850 3350
Wire Wire Line
	5850 3550 6000 3550
Connection ~ 5850 3550
Wire Wire Line
	5850 3550 5850 3450
Wire Wire Line
	6000 3650 5850 3650
Connection ~ 5850 3650
Wire Wire Line
	5850 3650 5850 3550
Wire Wire Line
	6000 3750 5850 3750
Connection ~ 5850 3750
Wire Wire Line
	5850 3750 5850 3650
$Comp
L power:GND #PWR?
U 1 1 5F0D6E85
P 5650 3050
AR Path="/5F0D6E85" Ref="#PWR?"  Part="1" 
AR Path="/5F0CC5A4/5F0D6E85" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 5650 2800 50  0001 C CNN
F 1 "GND" H 5655 2877 50  0000 C CNN
F 2 "" H 5650 3050 50  0001 C CNN
F 3 "" H 5650 3050 50  0001 C CNN
	1    5650 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	5650 3050 5650 3950
Wire Wire Line
	5650 3950 6000 3950
Wire Wire Line
	6000 4050 5650 4050
Wire Wire Line
	5650 4050 5650 3950
Connection ~ 5650 3950
Wire Wire Line
	5650 4050 5650 4150
Wire Wire Line
	5650 4150 6000 4150
Connection ~ 5650 4050
Wire Wire Line
	5650 4150 5650 4250
Wire Wire Line
	5650 4250 6000 4250
Connection ~ 5650 4150
Connection ~ 5650 4250
Wire Wire Line
	5650 4450 6000 4450
Wire Wire Line
	5650 4450 5650 4550
Wire Wire Line
	5650 4550 6000 4550
Connection ~ 5650 4450
Wire Wire Line
	5650 4550 5650 4650
Wire Wire Line
	5650 4650 6000 4650
Connection ~ 5650 4550
Wire Wire Line
	5650 4250 5650 4350
Wire Wire Line
	6000 4350 5650 4350
Connection ~ 5650 4350
Wire Wire Line
	5650 4350 5650 4450
$EndSCHEMATC
