EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 6450 2600 0    50   ~ 0
fire1
Text Label 6450 2850 0    50   ~ 0
pyroCorrect1
Text Label 6450 4250 0    50   ~ 0
fire2
Text Label 6450 4500 0    50   ~ 0
pyroCorrect2
Wire Wire Line
	6450 4250 6950 4250
Wire Wire Line
	6450 4500 6950 4500
Wire Wire Line
	6450 2850 6950 2850
Wire Wire Line
	6450 2600 6950 2600
$Comp
L power:+BATT #PWR0101
U 1 1 5F1CBF48
P 4850 2700
F 0 "#PWR0101" H 4850 2550 50  0001 C CNN
F 1 "+BATT" H 4865 2873 50  0000 C CNN
F 2 "" H 4850 2700 50  0001 C CNN
F 3 "" H 4850 2700 50  0001 C CNN
	1    4850 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5F1CCE09
P 4850 3250
F 0 "#PWR0102" H 4850 3000 50  0001 C CNN
F 1 "GND" H 4855 3077 50  0000 C CNN
F 2 "" H 4850 3250 50  0001 C CNN
F 3 "" H 4850 3250 50  0001 C CNN
	1    4850 3250
	1    0    0    -1  
$EndComp
Text Label 5200 3900 0    50   ~ 0
fire1
Text Label 4900 4000 0    50   ~ 0
pyroCorrect1
Text Label 5200 4100 0    50   ~ 0
fire2
Text Label 4900 4200 0    50   ~ 0
pyroCorrect2
Wire Wire Line
	4850 4200 5350 4200
Wire Wire Line
	4850 4100 5350 4100
Wire Wire Line
	4850 4000 5350 4000
Wire Wire Line
	4850 3900 5350 3900
Wire Wire Line
	5250 5200 4850 5200
Text Label 5200 4300 0    50   ~ 0
arm
$Comp
L power:GND #PWR0104
U 1 1 5F1DA5F7
P 5250 5200
F 0 "#PWR0104" H 5250 4950 50  0001 C CNN
F 1 "GND" H 5255 5027 50  0000 C CNN
F 2 "" H 5250 5200 50  0001 C CNN
F 3 "" H 5250 5200 50  0001 C CNN
	1    5250 5200
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5F1E4B91
P 4850 2950
F 0 "#FLG0101" H 4850 3025 50  0001 C CNN
F 1 "PWR_FLAG" V 4850 3078 50  0000 L CNN
F 2 "" H 4850 2950 50  0001 C CNN
F 3 "~" H 4850 2950 50  0001 C CNN
	1    4850 2950
	0    1    1    0   
$EndComp
$Comp
L Pyro_Library:Conn_01x02 J103
U 1 1 5F1E8227
P 4650 5200
F 0 "J103" H 4568 4875 50  0000 C CNN
F 1 "Conn_01x02" H 4568 4966 50  0000 C CNN
F 2 "PyroChannel:PinSocket_1x02_P2.54mm_Vertical" H 4650 5200 50  0001 C CNN
F 3 "~" H 4650 5200 50  0001 C CNN
F 4 "732-5315-ND" H 4650 5200 50  0001 C CNN "digikey"
	1    4650 5200
	-1   0    0    1   
$EndComp
$Comp
L Pyro_Library:Conn_01x05 J102
U 1 1 5F1E9138
P 4650 4100
F 0 "J102" H 4568 3675 50  0000 C CNN
F 1 "Conn_01x05" H 4568 3766 50  0000 C CNN
F 2 "PyroChannel:PinSocket_1x05_P2.54mm_Vertical" H 4650 4100 50  0001 C CNN
F 3 "~" H 4650 4100 50  0001 C CNN
F 4 "732-5318-ND" H 4650 4100 50  0001 C CNN "digikey"
	1    4650 4100
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR0103
U 1 1 5F1EC181
P 5250 5100
F 0 "#PWR0103" H 5250 4950 50  0001 C CNN
F 1 "+3V3" H 5265 5273 50  0000 C CNN
F 2 "" H 5250 5100 50  0001 C CNN
F 3 "" H 5250 5100 50  0001 C CNN
	1    5250 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 5100 4850 5100
Wire Wire Line
	4850 4300 5350 4300
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5F1F08E8
P 5250 5100
F 0 "#FLG0103" H 5250 5175 50  0001 C CNN
F 1 "PWR_FLAG" V 5250 5228 50  0000 L CNN
F 2 "" H 5250 5100 50  0001 C CNN
F 3 "~" H 5250 5100 50  0001 C CNN
	1    5250 5100
	0    1    1    0   
$EndComp
Connection ~ 5250 5100
$Comp
L Pyro_Library:Conn_01x02 J101
U 1 1 5F1F7B3F
P 4450 3050
F 0 "J101" H 4368 2725 50  0000 C CNN
F 1 "Conn_01x02" H 4368 2816 50  0000 C CNN
F 2 "PyroChannel:AMASS_XT30PW-M_1x02_P2.50mm_Horizontal" H 4450 3050 50  0001 C CNN
F 3 "~" H 4450 3050 50  0001 C CNN
F 4 "B07YYTWQYD" H 4450 3050 50  0001 C CNN "amazon"
	1    4450 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	4650 2950 4850 2950
Wire Wire Line
	4850 3050 4650 3050
Connection ~ 4850 2950
Wire Wire Line
	4850 2700 4850 2950
Wire Wire Line
	4850 3050 4850 3250
$Sheet
S 9100 3300 1150 600 
U 5F18FD4A
F0 "ArmSchematic" 50
F1 "ArmSchematic.sch" 50
F2 "FireOut" I L 9100 3600 50 
F3 "arm" I L 9100 3750 50 
$EndSheet
$Sheet
S 6950 2250 1250 900 
U 5F19FDB4
F0 "pyro1" 50
F1 "PyroChannel.sch" 50
F2 "FIRE" I L 6950 2600 50 
F3 "pyroCorrect" O L 6950 2850 50 
F4 "fireOut" O R 8200 2850 50 
$EndSheet
$Sheet
S 6950 3950 1250 900 
U 5F1A022A
F0 "Pyro2" 50
F1 "PyroChannel.sch" 50
F2 "FIRE" I L 6950 4250 50 
F3 "pyroCorrect" O L 6950 4500 50 
F4 "fireOut" O R 8200 4500 50 
$EndSheet
$Comp
L Device:CP C101
U 1 1 5F1A93B5
P 5550 3000
F 0 "C101" H 5668 3046 50  0000 L CNN
F 1 "1mF" H 5668 2955 50  0000 L CNN
F 2 "PyroChannel:CP_Radial_D10.0mm_P5.00mm" H 5588 2850 50  0001 C CNN
F 3 "~" H 5550 3000 50  0001 C CNN
F 4 "1189-3703-1-ND" H 5550 3000 50  0001 C CNN "digikey"
	1    5550 3000
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0105
U 1 1 5F1AE2E0
P 5550 2700
F 0 "#PWR0105" H 5550 2550 50  0001 C CNN
F 1 "+BATT" H 5565 2873 50  0000 C CNN
F 2 "" H 5550 2700 50  0001 C CNN
F 3 "" H 5550 2700 50  0001 C CNN
	1    5550 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5F1AE51F
P 5550 3250
F 0 "#PWR0106" H 5550 3000 50  0001 C CNN
F 1 "GND" H 5555 3077 50  0000 C CNN
F 2 "" H 5550 3250 50  0001 C CNN
F 3 "" H 5550 3250 50  0001 C CNN
	1    5550 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 3250 5550 3150
Wire Wire Line
	5550 2850 5550 2700
Wire Wire Line
	9100 3600 8550 3600
Wire Wire Line
	8550 3600 8550 2850
Wire Wire Line
	8550 2850 8200 2850
Wire Wire Line
	8550 3600 8550 4500
Wire Wire Line
	8550 4500 8200 4500
Connection ~ 8550 3600
Wire Wire Line
	9100 3750 8800 3750
Text Label 8800 3750 0    50   ~ 0
arm
Text Notes 3450 2350 0    50   ~ 0
No flag on GND is intentional\nremoves a dumb error that \nan output is hooked up to an output
Text Notes 5150 2300 0    50   ~ 0
when copying this for your\nflight computer you need this!\nchange the value as needed\n
Text Notes 5700 2750 0    50   ~ 0
 |\n |\n |\n_|_\n\_/\n
$EndSCHEMATC
