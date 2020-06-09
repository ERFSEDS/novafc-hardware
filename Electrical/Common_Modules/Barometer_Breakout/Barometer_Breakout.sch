EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
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
L Device:C C1
U 1 1 5EC72DC6
P 5250 3700
F 0 "C1" H 5365 3746 50  0000 L CNN
F 1 "100nF" H 5365 3655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5288 3550 50  0001 C CNN
F 3 "~" H 5250 3700 50  0001 C CNN
	1    5250 3700
	-1   0    0    1   
$EndComp
$Comp
L MS560702BA03-50:MS560702BA03-50 U1
U 1 1 5EC6E49F
P 6100 4150
F 0 "U1" H 6100 4617 50  0000 C CNN
F 1 "MS560702BA03-50" H 6100 4526 50  0000 C CNN
F 2 "MS560702BA03-50:SON125P300X500X100-8N" H 6100 4150 50  0001 L BNN
F 3 "MS560702BA03-50" H 6100 4150 50  0001 L BNN
F 4 "https://www.te.com/usa-en/product-MS560702BA03-50.html?te_bu=Cor&te_type=disp&te_campaign=seda_glo_cor-seda-global-disp-prtnr-fy19-seda-model-bom-cta_sma-317_1&elqCampaignId=32493" H 6100 4150 50  0001 L BNN "Field4"
F 5 "Compliant" H 6100 4150 50  0001 L BNN "Field5"
	1    6100 4150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Male J1
U 1 1 5EC8391A
P 4550 4050
F 0 "J1" H 4658 4339 50  0000 C CNN
F 1 "Conn_01x06_Male" H 4658 4340 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 4550 4050 50  0001 C CNN
F 3 "~" H 4550 4050 50  0001 C CNN
	1    4550 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4350 4750 4350
Wire Wire Line
	5500 4150 4750 4150
Wire Wire Line
	6700 4150 6750 4150
Wire Wire Line
	5150 4600 5150 4250
Wire Wire Line
	5150 4250 4750 4250
Wire Wire Line
	5250 4050 5500 4050
Connection ~ 5250 4050
Wire Wire Line
	4750 4050 5250 4050
Wire Wire Line
	5250 4050 5250 4550
Wire Wire Line
	5500 3950 4750 3950
Wire Wire Line
	5250 3850 5250 4050
Wire Wire Line
	6700 3950 6700 3500
Wire Wire Line
	6700 3500 5250 3500
Wire Wire Line
	5250 3500 5250 3550
Wire Wire Line
	5250 3500 4750 3500
Wire Wire Line
	4750 3500 4750 3850
Connection ~ 5250 3500
Wire Wire Line
	6700 4350 6700 4550
Wire Wire Line
	6700 4550 5250 4550
Wire Wire Line
	6750 4600 6750 4150
Wire Wire Line
	6750 4600 5150 4600
Text Label 4400 3850 0    50   ~ 0
VDD
Text Label 4400 3950 0    50   ~ 0
CSB
Text Label 4400 4050 0    50   ~ 0
GND
Text Label 4400 4150 0    50   ~ 0
SCLK
Text Label 4400 4250 0    50   ~ 0
SDO
Text Label 4400 4350 0    50   ~ 0
SDI
$EndSCHEMATC
