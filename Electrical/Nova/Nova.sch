EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 1250 -1150 0    157  ~ 31
When creating your part in your feature branch create a heirarchical\nsheet and name it appropriately and do your work in there. NOT IN\nTHIS SHEET. THis sheet is the top level connect all the parts together\nsheet. I will find you if you put something other than  Heirarchical\nsheet in here
$Sheet
S 4350 1100 2450 3150
U 5F317AC9
F0 "MCU" 50
F1 "C:/Users/ckeer/OneDrive/Documents/Github/Modular-Flight-Computer/Electrical/Common_Modules/MCU/Breakout/MCU.sch" 20
F2 "RESET" I L 4350 1500 50 
F3 "CRYSTALIN" I L 4350 1750 50 
F4 "CRYSTALOUT" I L 4350 1850 50 
F5 "RTCCRYSTALIN" I L 4350 2000 50 
F6 "RTCCRYSTALOUT" I L 4350 2100 50 
F7 "TXD" I L 4350 2750 50 
F8 "RXD" I L 4350 2850 50 
F9 "VCAP" I L 4350 2350 50 
F10 "VSSA" I L 4350 2450 50 
F11 "VREF+" I L 4350 2550 50 
F12 "PA14" I L 4350 1300 50 
F13 "PA13" I L 4350 1200 50 
$EndSheet
$Sheet
S 800  1850 1250 350 
U 5F317E00
F0 "MCU RESET" 50
F1 "C:/Users/ckeer/OneDrive/Documents/Github/Modular-Flight-Computer/Electrical/Common_Modules/MCU/Breakout/RESET.sch" 20
F2 "RESET" I R 2050 2050 50 
$EndSheet
$Sheet
S 800  2400 1250 550 
U 5F319C9C
F0 "CLOCKS" 50
F1 "C:/Users/ckeer/OneDrive/Documents/Github/Modular-Flight-Computer/Electrical/Common_Modules/MCU/Breakout/Clocks.sch" 20
F2 "CLOCKIN" I R 2050 2500 50 
F3 "CLOCKOUT" I R 2050 2600 50 
F4 "RTCCRYSTALIN" I R 2050 2750 50 
F5 "RTCCRYSTALOUT" I R 2050 2850 50 
$EndSheet
Wire Wire Line
	2050 2050 2850 2050
Wire Wire Line
	2050 2500 2850 2500
Wire Wire Line
	2050 2600 2850 2600
Wire Wire Line
	2050 2750 2850 2750
Wire Wire Line
	2050 2850 2850 2850
Text Label 2350 2050 0    50   ~ 0
RESET
Text Label 2300 2500 0    50   ~ 0
CLOCKIN
Text Label 2250 2600 0    50   ~ 0
CLOCKOUT
Text Label 2250 2750 0    50   ~ 0
32CLOCKIN
Text Label 2250 2850 0    50   ~ 0
32CLOCKOUT
Wire Wire Line
	4350 1500 3550 1500
Wire Wire Line
	4350 1750 3550 1750
Wire Wire Line
	4350 1850 3550 1850
Wire Wire Line
	4350 2000 3550 2000
Wire Wire Line
	4350 2100 3550 2100
Text Label 3850 1500 0    50   ~ 0
RESET
Text Label 3800 1750 0    50   ~ 0
CLOCKIN
Text Label 3800 1850 0    50   ~ 0
CLOCKOUT
Text Label 3750 2000 0    50   ~ 0
32CLOCKIN
Text Label 3750 2100 0    50   ~ 0
32CLOCKOUT
$Sheet
S 800  1100 1250 450 
U 5F31B2A5
F0 "SWD" 50
F1 "C:/Users/ckeer/OneDrive/Documents/Github/Modular-Flight-Computer/Electrical/Common_Modules/MCU/Breakout/SWD .sch" 20
F2 "JTMS-SWDIO" I R 2050 1200 50 
F3 "JTCK-SWCLK" I R 2050 1300 50 
F4 "RESET" I R 2050 1400 50 
$EndSheet
Wire Wire Line
	2050 1400 2850 1400
Wire Wire Line
	2050 1300 2850 1300
Wire Wire Line
	2050 1200 2850 1200
Text Label 2350 1400 0    50   ~ 0
RESET
Text Label 2350 1300 0    50   ~ 0
SWCLK
Text Label 2350 1200 0    50   ~ 0
SWDIO
Wire Wire Line
	4350 1200 3550 1200
Wire Wire Line
	4350 1300 3550 1300
Text Label 3850 1200 0    50   ~ 0
SWDIO
Text Label 3850 1300 0    50   ~ 0
SWCLK
$Sheet
S 800  3150 1250 500 
U 5F3189B2
F0 "MCU FILTERING" 50
F1 "C:/Users/ckeer/OneDrive/Documents/Github/Modular-Flight-Computer/Electrical/Common_Modules/MCU/Breakout/FILTERING.sch" 20
F2 "VCAP" I R 2050 3250 50 
F3 "VSSA" I R 2050 3350 50 
F4 "VDDA" I R 2050 3450 50 
F5 "VREF+" I R 2050 3550 50 
$EndSheet
Wire Wire Line
	2050 3250 2850 3250
Wire Wire Line
	2050 3350 2850 3350
Wire Wire Line
	2050 3550 2200 3550
Wire Wire Line
	2050 3450 2200 3450
Wire Wire Line
	2200 3450 2200 3550
Connection ~ 2200 3550
Wire Wire Line
	2200 3550 2850 3550
Text Label 2350 3250 0    50   ~ 0
VCAP
Text Label 2350 3350 0    50   ~ 0
VSSA
Text Label 2350 3550 0    50   ~ 0
VREF+
Wire Wire Line
	4350 2350 3550 2350
Wire Wire Line
	4350 2450 3550 2450
Wire Wire Line
	4350 2550 3550 2550
Text Label 3900 2350 0    50   ~ 0
VCAP
Text Label 3900 2450 0    50   ~ 0
VSSA
Text Label 3900 2550 0    50   ~ 0
VREF+
$Sheet
S 800  3800 1250 350 
U 5F319D4B
F0 "USB-C" 50
F1 "C:/Users/ckeer/OneDrive/Documents/Github/Modular-Flight-Computer/Electrical/Common_Modules/MCU/Breakout/USB-C.sch" 20
F2 "TXD" I R 2050 3900 50 
F3 "RXD" I R 2050 4000 50 
$EndSheet
Wire Wire Line
	4350 2750 3550 2750
Wire Wire Line
	4350 2850 3550 2850
Text Label 3850 2750 0    50   ~ 0
RXD
Text Label 3850 2850 0    50   ~ 0
TXD
Wire Wire Line
	2050 3900 2850 3900
Wire Wire Line
	2050 4000 2850 4000
Text Label 2400 3900 0    50   ~ 0
TXD
Text Label 2400 4000 0    50   ~ 0
RXD
$EndSCHEMATC
