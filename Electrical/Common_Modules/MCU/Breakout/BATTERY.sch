EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 8 11
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
L NOVA-MCU-(STM)-rescue:Connector_Generic_Conn_01x02-Red-cache J?
U 1 1 5EEB3AB5
P 4950 3300
AR Path="/5EEB3AB5" Ref="J?"  Part="1" 
AR Path="/5EE654BB/5EEB3769/5EEB3AB5" Ref="J801"  Part="1" 
F 0 "J801" H 5100 2950 50  0000 C CNN
F 1 "Connector_Generic_Conn_01x02" H 5100 3050 50  0000 C CNN
F 2 "TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x02_P3.50mm_Horizontal" H 4950 3300 50  0001 C CNN
F 3 "" H 4950 3300 50  0001 C CNN
	1    4950 3300
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0801
U 1 1 5EEB4049
P 5650 3300
F 0 "#PWR0801" H 5650 3050 50  0001 C CNN
F 1 "GND" V 5655 3172 50  0000 R CNN
F 2 "" H 5650 3300 50  0001 C CNN
F 3 "" H 5650 3300 50  0001 C CNN
	1    5650 3300
	0    -1   -1   0   
$EndComp
Text HLabel 5650 3200 2    50   Input ~ 0
BATTERY
Wire Wire Line
	5150 3200 5600 3200
Wire Wire Line
	5650 3300 5150 3300
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5EF3A696
P 5600 3200
F 0 "#FLG0103" H 5600 3275 50  0001 C CNN
F 1 "PWR_FLAG" H 5600 3373 50  0000 C CNN
F 2 "" H 5600 3200 50  0001 C CNN
F 3 "~" H 5600 3200 50  0001 C CNN
	1    5600 3200
	1    0    0    -1  
$EndComp
Connection ~ 5600 3200
Wire Wire Line
	5600 3200 5650 3200
$EndSCHEMATC
