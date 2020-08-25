EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 13 18
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
L Nova-rescue:PS1440P02BT-PS1440P02BT-Nova-rescue-Nova-rescue-Nova-rescue LS101
U 1 1 5F404605
P 5450 3800
F 0 "LS101" H 5580 3846 50  0000 L CNN
F 1 "PS1440P02BT" H 5580 3755 50  0000 L CNN
F 2 "Footprint Library:BUZZER_PS1440P02BT" H 5450 3800 50  0001 L BNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/piezoelectronic_buzzer_ps_en.pdf" H 5450 3800 50  0001 L BNN
F 4 "IPC-7251" H 5450 3800 50  0001 L BNN "Field4"
	1    5450 3800
	0    1    1    0   
$EndComp
$Comp
L Nova-rescue:74HC2GU04GW,125-74HC2GU04GW_125-Nova-rescue-Nova-rescue-Nova-rescue IC101
U 1 1 5F40586B
P 4950 3100
AR Path="/5F40586B" Ref="IC101"  Part="1" 
AR Path="/5F36176A/5F40586B" Ref="IC101"  Part="1" 
F 0 "IC101" H 5450 3365 50  0000 C CNN
F 1 "74HC2GU04GW,125" H 5450 3274 50  0000 C CNN
F 2 "Footprint Library:SOP65P210X110-6N" H 5800 3200 50  0001 L CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC2GU04.pdf" H 5800 3100 50  0001 L CNN
F 4 "74HC2GU04 - Dual unbuffered inverter@en-us" H 5800 3000 50  0001 L CNN "Description"
F 5 "1.1" H 5800 2900 50  0001 L CNN "Height"
F 6 "Nexperia" H 5800 2800 50  0001 L CNN "Manufacturer_Name"
F 7 "74HC2GU04GW,125" H 5800 2700 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "74HC2GU04GW,125" H 5800 2600 50  0001 L CNN "Arrow Part Number"
F 9 "https://www.arrow.com/en/products/74hc2gu04gw125/nexperia" H 5800 2500 50  0001 L CNN "Arrow Price/Stock"
F 10 "" H 5800 2400 50  0001 L CNN "Mouser Part Number"
F 11 "" H 5800 2300 50  0001 L CNN "Mouser Price/Stock"
	1    4950 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5F407098
P 4750 3200
F 0 "#PWR0101" H 4750 2950 50  0001 C CNN
F 1 "GND" V 4755 3072 50  0000 R CNN
F 2 "" H 4750 3200 50  0001 C CNN
F 3 "" H 4750 3200 50  0001 C CNN
	1    4750 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	4950 3200 4750 3200
$Comp
L power:+3V3 #PWR0102
U 1 1 5F4096B6
P 6150 3200
F 0 "#PWR0102" H 6150 3050 50  0001 C CNN
F 1 "+3V3" V 6165 3328 50  0000 L CNN
F 2 "" H 6150 3200 50  0001 C CNN
F 3 "" H 6150 3200 50  0001 C CNN
	1    6150 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	5950 3200 6100 3200
Wire Wire Line
	5950 3100 6500 3100
Wire Wire Line
	6500 3700 5650 3700
Wire Wire Line
	4700 3100 4950 3100
Wire Wire Line
	6500 3100 6500 3600
Wire Wire Line
	5250 3700 5100 3700
Wire Wire Line
	5100 3700 5100 3500
Wire Wire Line
	5100 3500 6100 3500
Wire Wire Line
	6100 3500 6100 3300
Wire Wire Line
	6100 3300 5950 3300
Wire Wire Line
	4950 3300 4800 3300
Wire Wire Line
	4800 3300 4800 3600
Wire Wire Line
	4800 3600 6500 3600
Connection ~ 6500 3600
Wire Wire Line
	6500 3600 6500 3700
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5F410118
P 6100 3200
F 0 "#FLG0101" H 6100 3275 50  0001 C CNN
F 1 "PWR_FLAG" H 6100 3373 50  0000 C CNN
F 2 "" H 6100 3200 50  0001 C CNN
F 3 "~" H 6100 3200 50  0001 C CNN
	1    6100 3200
	1    0    0    -1  
$EndComp
Connection ~ 6100 3200
Wire Wire Line
	6100 3200 6150 3200
Text HLabel 4700 3100 0    50   Input ~ 0
BUZZER
$EndSCHEMATC
