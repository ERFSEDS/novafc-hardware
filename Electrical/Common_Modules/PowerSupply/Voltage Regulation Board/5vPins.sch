EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 4
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
L Connector:Conn_01x08_Male J?
U 1 1 5F0D332B
P 6050 3900
AR Path="/5F0D332B" Ref="J?"  Part="1" 
AR Path="/5F0CD26D/5F0D332B" Ref="J401"  Part="1" 
F 0 "J401" H 6022 3782 50  0000 R CNN
F 1 "8PinConnector" H 6022 3873 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 6050 3900 50  0001 C CNN
F 3 "~" H 6050 3900 50  0001 C CNN
	1    6050 3900
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0D3331
P 5450 3450
AR Path="/5F0D3331" Ref="#PWR?"  Part="1" 
AR Path="/5F0CD26D/5F0D3331" Ref="#PWR0110"  Part="1" 
F 0 "#PWR0110" H 5450 3200 50  0001 C CNN
F 1 "GND" H 5455 3277 50  0000 C CNN
F 2 "" H 5450 3450 50  0001 C CNN
F 3 "" H 5450 3450 50  0001 C CNN
	1    5450 3450
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F0D3337
P 5650 3450
AR Path="/5F0D3337" Ref="#PWR?"  Part="1" 
AR Path="/5F0CD26D/5F0D3337" Ref="#PWR0111"  Part="1" 
F 0 "#PWR0111" H 5650 3300 50  0001 C CNN
F 1 "+5V" H 5665 3623 50  0000 C CNN
F 2 "" H 5650 3450 50  0001 C CNN
F 3 "" H 5650 3450 50  0001 C CNN
	1    5650 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3450 5650 3500
Wire Wire Line
	5650 3500 5850 3500
Wire Wire Line
	5850 3600 5650 3600
Wire Wire Line
	5650 3600 5650 3500
Connection ~ 5650 3500
Wire Wire Line
	5850 3700 5650 3700
Wire Wire Line
	5650 3700 5650 3600
Connection ~ 5650 3600
Wire Wire Line
	5850 3800 5650 3800
Wire Wire Line
	5650 3800 5650 3700
Connection ~ 5650 3700
Wire Wire Line
	5850 3900 5450 3900
Wire Wire Line
	5450 3900 5450 3450
Wire Wire Line
	5850 4000 5450 4000
Wire Wire Line
	5450 4000 5450 3900
Connection ~ 5450 3900
Wire Wire Line
	5850 4100 5450 4100
Wire Wire Line
	5450 4100 5450 4000
Connection ~ 5450 4000
Wire Wire Line
	5850 4200 5450 4200
Wire Wire Line
	5450 4200 5450 4100
Connection ~ 5450 4100
$EndSCHEMATC
