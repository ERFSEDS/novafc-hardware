EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 5955 4170 2    50   Input ~ 0
MISO
Text HLabel 5085 4170 0    50   Input ~ 0
SCLK
Text HLabel 5955 4070 2    50   Input ~ 0
MOSI
$Comp
L Connector_Generic:Conn_02x10_Odd_Even J1
U 1 1 5FF82731
P 5470 3770
F 0 "J1" H 5520 4387 50  0000 C CNN
F 1 "Conn_02x10_Odd_Even" H 5520 4296 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x10_P2.54mm_Vertical" H 5470 3770 50  0001 C CNN
F 3 "~" H 5470 3770 50  0001 C CNN
	1    5470 3770
	1    0    0    -1  
$EndComp
Wire Wire Line
	5270 3370 5085 3370
Wire Wire Line
	5270 3470 5085 3470
Wire Wire Line
	5955 3770 5770 3770
Wire Wire Line
	5270 3870 5085 3870
Wire Wire Line
	5955 3870 5770 3870
Wire Wire Line
	5270 3970 5085 3970
Wire Wire Line
	5270 4070 5085 4070
Text HLabel 5085 3470 0    50   Input ~ 0
+3V3
Text HLabel 5085 3370 0    50   Input ~ 0
GND
Wire Wire Line
	5955 3970 5770 3970
Wire Wire Line
	5270 3770 5085 3770
Text HLabel 5085 4070 0    50   Input ~ 0
H_PIN_0
Text HLabel 5085 3870 0    50   Input ~ 0
H_PIN_1
Text HLabel 5955 3770 2    50   Input ~ 0
H_PIN_2
Text HLabel 5955 3870 2    50   Input ~ 0
H_PIN_3
Text HLabel 5085 3970 0    50   Input ~ 0
H_PIN_4
Text HLabel 5955 3970 2    50   Input ~ 0
H_PIN_5
Text HLabel 5085 3770 0    50   Input ~ 0
H_PIN_6
Wire Wire Line
	5270 4170 5085 4170
Wire Wire Line
	5955 4070 5770 4070
Wire Wire Line
	5955 4170 5770 4170
Wire Wire Line
	5270 3670 5085 3670
Wire Wire Line
	5270 3570 5085 3570
Wire Wire Line
	5955 3670 5770 3670
Wire Wire Line
	5955 3570 5770 3570
Wire Wire Line
	5955 3470 5770 3470
Wire Wire Line
	5955 3370 5770 3370
Wire Wire Line
	5270 4270 5085 4270
Wire Wire Line
	5955 4270 5770 4270
Text HLabel 5085 3570 0    50   Input ~ 0
H_PIN_10
Text HLabel 5085 3670 0    50   Input ~ 0
H_PIN_8
Text HLabel 5955 3370 2    50   Input ~ 0
+BATT
Text HLabel 5955 3470 2    50   Input ~ 0
H_PIN_11
Text HLabel 5955 3570 2    50   Input ~ 0
H_PIN_9
Text HLabel 5955 3670 2    50   Input ~ 0
H_PIN_7
Text HLabel 5085 4270 0    50   Input ~ 0
H_TX
Text HLabel 5955 4270 2    50   Input ~ 0
H_RX
$EndSCHEMATC
