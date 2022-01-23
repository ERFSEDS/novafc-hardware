EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 19
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
L Device:Buzzer BZ1
U 1 1 60310C97
P 5750 2750
F 0 "BZ1" V 5801 2563 50  0000 R CNN
F 1 "Buzzer" V 5710 2563 50  0000 R CNN
F 2 "Transducer:XDCR_CMT-7525-80-SMT-TR" V 5725 2850 50  0001 C CNN
F 3 "https://www.cuidevices.com/product/resource/cmt-7525-80-smt-tr.pdf" V 5725 2850 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/cui-devices/CMT-7525-80-SMT-TR/10326249" V 5750 2750 50  0001 C CNN "Order Link"
	1    5750 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0127
U 1 1 60506B3B
P 5650 3950
F 0 "#PWR0127" H 5650 3700 50  0001 C CNN
F 1 "GND" V 5655 3822 50  0000 R CNN
F 2 "" H 5650 3950 50  0001 C CNN
F 3 "" H 5650 3950 50  0001 C CNN
	1    5650 3950
	1    0    0    -1  
$EndComp
Text HLabel 4700 3600 0    50   Input ~ 0
BUZZER
$Comp
L pspice:DIODE D2
U 1 1 6041DF62
P 5200 2750
F 0 "D2" V 5246 2622 50  0000 R CNN
F 1 "DIODE" V 5155 2622 50  0000 R CNN
F 2 "Diode_SMD:D_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5200 2750 50  0001 C CNN
F 3 "~" H 5200 2750 50  0001 C CNN
	1    5200 2750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5200 2550 5200 2350
Wire Wire Line
	5200 2350 5650 2350
Wire Wire Line
	5650 2350 5650 2650
Wire Wire Line
	5200 2950 5200 3150
Wire Wire Line
	5200 3150 5650 3150
Wire Wire Line
	5650 3150 5650 2850
$Comp
L power:+3.3V #PWR0142
U 1 1 6041F886
P 5650 2150
F 0 "#PWR0142" H 5650 2000 50  0001 C CNN
F 1 "+3.3V" H 5665 2323 50  0000 C CNN
F 2 "" H 5650 2150 50  0001 C CNN
F 3 "" H 5650 2150 50  0001 C CNN
	1    5650 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2150 5650 2350
Connection ~ 5650 2350
Wire Wire Line
	5650 3150 5650 3400
Connection ~ 5650 3150
$Comp
L Device:R_US R27
U 1 1 60424467
P 5000 3600
F 0 "R27" V 4795 3600 50  0000 C CNN
F 1 "180" V 4886 3600 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5040 3590 50  0001 C CNN
F 3 "~" H 5000 3600 50  0001 C CNN
	1    5000 3600
	0    1    1    0   
$EndComp
Wire Wire Line
	4700 3600 4850 3600
Wire Wire Line
	5650 3800 5650 3950
Wire Wire Line
	5150 3600 5350 3600
$Comp
L Nova-rescue:Q_NMOS_DGS-MOSFET Q?
U 1 1 617C8203
P 5550 3600
AR Path="/5F448D4B/6179571F/617C8203" Ref="Q?"  Part="1" 
AR Path="/5F448D4B/617C20EF/617C8203" Ref="Q?"  Part="1" 
AR Path="/5F448D4B/617C2A68/617C8203" Ref="Q?"  Part="1" 
AR Path="/5F448D4B/617C3265/617C8203" Ref="Q?"  Part="1" 
AR Path="/5F36176A/617C8203" Ref="Q9"  Part="1" 
AR Path="/617C8203" Ref="Q9"  Part="1" 
F 0 "Q9" H 5754 3646 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 5754 3555 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 5750 3700 50  0001 C CNN
F 3 "~" H 5550 3600 50  0001 C CNN
	1    5550 3600
	1    0    0    -1  
$EndComp
$EndSCHEMATC
