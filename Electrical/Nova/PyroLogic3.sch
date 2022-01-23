EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 12 19
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
L Nova-rescue:Q_NMOS_DGS-MOSFET Q?
U 1 1 617DF88C
P 5150 2600
AR Path="/5F448D4B/6179571F/617DF88C" Ref="Q?"  Part="1" 
AR Path="/5F448D4B/617C20EF/617DF88C" Ref="Q?"  Part="1" 
AR Path="/5F448D4B/617C2A68/617DF88C" Ref="Q5"  Part="1" 
AR Path="/5F448D4B/617C3265/617DF88C" Ref="Q?"  Part="1" 
AR Path="/617DF88C" Ref="Q5"  Part="1" 
F 0 "Q5" H 5354 2646 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 5354 2555 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 5350 2700 50  0001 C CNN
F 3 "~" H 5150 2600 50  0001 C CNN
	1    5150 2600
	1    0    0    -1  
$EndComp
$Comp
L Nova-rescue:Q_NMOS_DGS-MOSFET Q?
U 1 1 617DF88D
P 5150 3600
AR Path="/5F448D4B/6179571F/617DF88D" Ref="Q?"  Part="1" 
AR Path="/5F448D4B/617C20EF/617DF88D" Ref="Q?"  Part="1" 
AR Path="/5F448D4B/617C2A68/617DF88D" Ref="Q6"  Part="1" 
AR Path="/5F448D4B/617C3265/617DF88D" Ref="Q?"  Part="1" 
AR Path="/617DF88D" Ref="Q6"  Part="1" 
F 0 "Q6" H 5354 3646 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 5354 3555 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 5350 3700 50  0001 C CNN
F 3 "~" H 5150 3600 50  0001 C CNN
	1    5150 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 617E0646
P 5250 3100
AR Path="/5F448D4B/6179571F/617E0646" Ref="R?"  Part="1" 
AR Path="/5F448D4B/617C20EF/617E0646" Ref="R?"  Part="1" 
AR Path="/5F448D4B/617C2A68/617E0646" Ref="R16"  Part="1" 
AR Path="/5F448D4B/617C3265/617E0646" Ref="R?"  Part="1" 
F 0 "R16" H 5318 3146 50  0000 L CNN
F 1 "3.3" H 5318 3055 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5290 3090 50  0001 C CNN
F 3 "~" H 5250 3100 50  0001 C CNN
	1    5250 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2800 5250 2950
Wire Wire Line
	5250 3250 5250 3400
$Comp
L Device:R_US R?
U 1 1 617E0647
P 4750 2950
AR Path="/5F448D4B/6179571F/617E0647" Ref="R?"  Part="1" 
AR Path="/5F448D4B/617C20EF/617E0647" Ref="R?"  Part="1" 
AR Path="/5F448D4B/617C2A68/617E0647" Ref="R14"  Part="1" 
AR Path="/5F448D4B/617C3265/617E0647" Ref="R?"  Part="1" 
F 0 "R14" H 4818 2996 50  0000 L CNN
F 1 "10k" H 4818 2905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4790 2940 50  0001 C CNN
F 3 "~" H 4750 2950 50  0001 C CNN
	1    4750 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2600 4750 2600
Wire Wire Line
	4750 2600 4750 2800
$Comp
L power:GND #PWR?
U 1 1 617DF890
P 4750 3250
AR Path="/5F448D4B/6179571F/617DF890" Ref="#PWR?"  Part="1" 
AR Path="/5F448D4B/617C20EF/617DF890" Ref="#PWR?"  Part="1" 
AR Path="/5F448D4B/617C2A68/617DF890" Ref="#PWR0155"  Part="1" 
AR Path="/5F448D4B/617C3265/617DF890" Ref="#PWR?"  Part="1" 
F 0 "#PWR0155" H 4750 3000 50  0001 C CNN
F 1 "GND" H 4755 3077 50  0000 C CNN
F 2 "" H 4750 3250 50  0001 C CNN
F 3 "" H 4750 3250 50  0001 C CNN
	1    4750 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3100 4750 3250
$Comp
L Device:R_US R?
U 1 1 617DF891
P 4750 3950
AR Path="/5F448D4B/6179571F/617DF891" Ref="R?"  Part="1" 
AR Path="/5F448D4B/617C20EF/617DF891" Ref="R?"  Part="1" 
AR Path="/5F448D4B/617C2A68/617DF891" Ref="R15"  Part="1" 
AR Path="/5F448D4B/617C3265/617DF891" Ref="R?"  Part="1" 
F 0 "R15" H 4818 3996 50  0000 L CNN
F 1 "10k" H 4818 3905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4790 3940 50  0001 C CNN
F 3 "~" H 4750 3950 50  0001 C CNN
	1    4750 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3600 4750 3600
Wire Wire Line
	4750 3600 4750 3800
$Comp
L power:GND #PWR?
U 1 1 6188A114
P 4750 4250
AR Path="/5F448D4B/6179571F/6188A114" Ref="#PWR?"  Part="1" 
AR Path="/5F448D4B/617C20EF/6188A114" Ref="#PWR?"  Part="1" 
AR Path="/5F448D4B/617C2A68/6188A114" Ref="#PWR0156"  Part="1" 
AR Path="/5F448D4B/617C3265/6188A114" Ref="#PWR?"  Part="1" 
F 0 "#PWR0156" H 4750 4000 50  0001 C CNN
F 1 "GND" H 4755 4077 50  0000 C CNN
F 2 "" H 4750 4250 50  0001 C CNN
F 3 "" H 4750 4250 50  0001 C CNN
	1    4750 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4100 4750 4250
$Comp
L power:GND #PWR?
U 1 1 6188A115
P 5250 3950
AR Path="/5F448D4B/6179571F/6188A115" Ref="#PWR?"  Part="1" 
AR Path="/5F448D4B/617C20EF/6188A115" Ref="#PWR?"  Part="1" 
AR Path="/5F448D4B/617C2A68/6188A115" Ref="#PWR0157"  Part="1" 
AR Path="/5F448D4B/617C3265/6188A115" Ref="#PWR?"  Part="1" 
F 0 "#PWR0157" H 5250 3700 50  0001 C CNN
F 1 "GND" H 5255 3777 50  0000 C CNN
F 2 "" H 5250 3950 50  0001 C CNN
F 3 "" H 5250 3950 50  0001 C CNN
	1    5250 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 3800 5250 3950
Text HLabel 4750 2600 0    50   Input ~ 0
Fire
Text HLabel 4750 3600 0    50   Input ~ 0
Arm
Text HLabel 5250 1950 1    50   Input ~ 0
Pyro
Wire Wire Line
	5250 1950 5250 2400
$EndSCHEMATC
