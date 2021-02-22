EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 21
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
P 5650 3450
F 0 "BZ1" V 5701 3263 50  0000 R CNN
F 1 "Buzzer" V 5610 3263 50  0000 R CNN
F 2 "Transducer:XDCR_CMT-7525-80-SMT-TR" V 5625 3550 50  0001 C CNN
F 3 "https://www.cuidevices.com/product/resource/cmt-7525-80-smt-tr.pdf" V 5625 3550 50  0001 C CNN
	1    5650 3450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 3550 5750 3600
Wire Wire Line
	5750 3600 6400 3600
Wire Wire Line
	5550 3550 5550 3600
Wire Wire Line
	5550 3600 4950 3600
$Comp
L power:GND #PWR0127
U 1 1 60506B3B
P 6400 3600
F 0 "#PWR0127" H 6400 3350 50  0001 C CNN
F 1 "GND" V 6405 3472 50  0000 R CNN
F 2 "" H 6400 3600 50  0001 C CNN
F 3 "" H 6400 3600 50  0001 C CNN
	1    6400 3600
	0    -1   -1   0   
$EndComp
Text HLabel 4950 3600 0    50   Input ~ 0
BUZZER
$EndSCHEMATC
