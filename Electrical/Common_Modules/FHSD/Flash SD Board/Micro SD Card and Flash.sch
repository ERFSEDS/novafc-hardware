EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 3 4
Title ""
Date "2020-06-30"
Rev "1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3450 3550 3450 4000
Text HLabel 5250 2850 1    50   Input ~ 0
DO
Text HLabel 5150 2850 1    50   Input ~ 0
CLK
Text HLabel 5050 2850 1    50   Input ~ 0
DI
Wire Wire Line
	5150 3650 5850 3650
Connection ~ 5150 3650
Wire Wire Line
	5150 2850 5150 3650
Connection ~ 5050 3450
Wire Wire Line
	5050 3750 5050 3450
Wire Wire Line
	4650 3750 5050 3750
Wire Wire Line
	5050 3450 5050 2850
Wire Wire Line
	3950 3550 3450 3550
Wire Wire Line
	5850 3450 5050 3450
Wire Wire Line
	4650 3650 5150 3650
Connection ~ 4900 3450
Wire Wire Line
	4900 3450 4900 3300
Wire Wire Line
	4900 3550 5850 3550
$Comp
L Flash~Chip:W25N512GVPIT U?
U 1 1 5F04351D
P 4300 3600
AR Path="/5F04351D" Ref="U?"  Part="1" 
AR Path="/5F0430E6/5F0432C4/5F04351D" Ref="U?"  Part="1" 
F 0 "U?" H 4300 4015 50  0000 C CNN
F 1 "W25N512GVPIT" H 4300 3924 50  0000 C CNN
F 2 "" H 4300 3900 50  0001 C CNN
F 3 "" H 4300 3900 50  0001 C CNN
	1    4300 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 3450 4900 3550
Wire Wire Line
	4650 3450 4900 3450
$Comp
L power:+3.3V #PWR?
U 1 1 5F04351E
P 4900 3300
AR Path="/5F04351E" Ref="#PWR?"  Part="1" 
AR Path="/5F0430E6/5F0432C4/5F04351E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4900 3150 50  0001 C CNN
F 1 "+3.3V" H 4915 3473 50  0000 C CNN
F 2 "" H 4900 3300 50  0001 C CNN
F 3 "" H 4900 3300 50  0001 C CNN
	1    4900 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3750 5650 3750
$Comp
L power:GND #PWR?
U 1 1 5F04351F
P 5650 3750
AR Path="/5F04351F" Ref="#PWR?"  Part="1" 
AR Path="/5F0430E6/5F0432C4/5F04351F" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5650 3500 50  0001 C CNN
F 1 "GND" H 5655 3577 50  0000 C CNN
F 2 "" H 5650 3750 50  0001 C CNN
F 3 "" H 5650 3750 50  0001 C CNN
	1    5650 3750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F043520
P 3800 3750
AR Path="/5F043520" Ref="#PWR?"  Part="1" 
AR Path="/5F0430E6/5F0432C4/5F043520" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3800 3500 50  0001 C CNN
F 1 "GND" V 3805 3622 50  0000 R CNN
F 2 "" H 3800 3750 50  0001 C CNN
F 3 "" H 3800 3750 50  0001 C CNN
	1    3800 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	3950 3750 3800 3750
$Comp
L Connector:Micro_SD_Card_Det J?
U 1 1 5F043521
P 6750 3650
AR Path="/5F043521" Ref="J?"  Part="1" 
AR Path="/5F0430E6/5F0432C4/5F043521" Ref="J?"  Part="1" 
F 0 "J?" H 6700 4467 50  0000 C CNN
F 1 "Micro_SD_Card_Det" H 6700 4376 50  0000 C CNN
F 2 "" H 8800 4350 50  0001 C CNN
F 3 "https://www.hirose.com/product/en/download_file/key_name/DM3/category/Catalog/doc_file_id/49662/?file_category_id=4&item_id=195&is_series=1" H 6750 3750 50  0001 C CNN
	1    6750 3650
	1    0    0    -1  
$EndComp
Text HLabel 5250 2850 1    50   Input ~ 0
DO
Text HLabel 5150 2850 1    50   Input ~ 0
CLK
Text HLabel 5050 2850 1    50   Input ~ 0
DI
$Comp
L Flash~Chip:W25N512GVPIT U?
U 1 1 5F042CCA
P 4300 3600
F 0 "U?" H 4300 4015 50  0000 C CNN
F 1 "W25N512GVPIT" H 4300 3924 50  0000 C CNN
F 2 "" H 4300 3900 50  0001 C CNN
F 3 "" H 4300 3900 50  0001 C CNN
	1    4300 3600
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5F042CD2
P 4900 3300
F 0 "#PWR?" H 4900 3150 50  0001 C CNN
F 1 "+3.3V" H 4915 3473 50  0000 C CNN
F 2 "" H 4900 3300 50  0001 C CNN
F 3 "" H 4900 3300 50  0001 C CNN
	1    4900 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F042CD9
P 5650 3750
F 0 "#PWR?" H 5650 3500 50  0001 C CNN
F 1 "GND" H 5655 3577 50  0000 C CNN
F 2 "" H 5650 3750 50  0001 C CNN
F 3 "" H 5650 3750 50  0001 C CNN
	1    5650 3750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F042CDF
P 3800 3750
F 0 "#PWR?" H 3800 3500 50  0001 C CNN
F 1 "GND" V 3805 3622 50  0000 R CNN
F 2 "" H 3800 3750 50  0001 C CNN
F 3 "" H 3800 3750 50  0001 C CNN
	1    3800 3750
	0    1    1    0   
$EndComp
$Comp
L Connector:Micro_SD_Card_Det J?
U 1 1 5F042CE6
P 6750 3650
F 0 "J?" H 6700 4467 50  0000 C CNN
F 1 "Micro_SD_Card_Det" H 6700 4376 50  0000 C CNN
F 2 "" H 8800 4350 50  0001 C CNN
F 3 "https://www.hirose.com/product/en/download_file/key_name/DM3/category/Catalog/doc_file_id/49662/?file_category_id=4&item_id=195&is_series=1" H 6750 3750 50  0001 C CNN
	1    6750 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2850 5250 3850
Wire Wire Line
	5250 3850 5850 3850
Wire Wire Line
	5250 3850 5250 4000
Wire Wire Line
	5250 4000 3450 4000
Connection ~ 5250 3850
Text HLabel 5850 3350 0    50   Input ~ 0
CSSD
Text HLabel 3950 3450 0    50   Input ~ 0
CSFH
Text HLabel 4750 3050 1    50   Input ~ 0
HOLD
Wire Wire Line
	4750 3050 4750 3550
Wire Wire Line
	4750 3550 4650 3550
$EndSCHEMATC
