EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 21 35
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
L 74xx:74HCT574 U?
U 1 1 5AFCD0D6
P 1750 1950
AR Path="/5AFD5CE2/5AFCD0D6" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFCD0D6" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFCD0D6" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFCB536/5AFCD0D6" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFCB55D/5AFCD0D6" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFCB584/5AFCD0D6" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFD86BE/5AFCD0D6" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFCCD08/5AFCD0D6" Ref="U8"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5AFCD0D6" Ref="U18"  Part="1" 
AR Path="/5AFD5CE2/5B0AB8A7/5AFCD0D6" Ref="U10"  Part="1" 
AR Path="/5B0FE4FF/5AFCD0D6" Ref="U18"  Part="1" 
AR Path="/5B0FE82A/5AFCD0D6" Ref="U18"  Part="1" 
AR Path="/5B0FEA60/5AFCD0D6" Ref="U121"  Part="1" 
F 0 "U121" H 1850 2650 50  0000 C CNN
F 1 "74HCT574" H 1750 1650 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 1750 1950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HCT574" H 1750 1950 50  0001 C CNN
	1    1750 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0285
U 1 1 5AFCD0DD
P 1750 2750
AR Path="/5AFD5CE2/5AFCCD08/5AFCD0DD" Ref="#PWR0285"  Part="1" 
AR Path="/5AFD5CE2/5B0AB8A7/5AFCD0DD" Ref="#PWR0321"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5AFCD0DD" Ref="#PWR0327"  Part="1" 
AR Path="/5B0FE4FF/5AFCD0DD" Ref="#PWR0327"  Part="1" 
AR Path="/5B0FE82A/5AFCD0DD" Ref="#PWR0327"  Part="1" 
AR Path="/5B0FEA60/5AFCD0DD" Ref="#PWR0475"  Part="1" 
F 0 "#PWR0475" H 1750 2500 50  0001 C CNN
F 1 "GND" H 1755 2577 50  0000 C CNN
F 2 "" H 1750 2750 50  0001 C CNN
F 3 "" H 1750 2750 50  0001 C CNN
	1    1750 2750
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0286
U 1 1 5AFCD0E3
P 1750 1150
AR Path="/5AFD5CE2/5AFCCD08/5AFCD0E3" Ref="#PWR0286"  Part="1" 
AR Path="/5AFD5CE2/5B0AB8A7/5AFCD0E3" Ref="#PWR0322"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5AFCD0E3" Ref="#PWR0328"  Part="1" 
AR Path="/5B0FE4FF/5AFCD0E3" Ref="#PWR0328"  Part="1" 
AR Path="/5B0FE82A/5AFCD0E3" Ref="#PWR0328"  Part="1" 
AR Path="/5B0FEA60/5AFCD0E3" Ref="#PWR0476"  Part="1" 
F 0 "#PWR0476" H 1750 1000 50  0001 C CNN
F 1 "VCC" H 1767 1323 50  0000 C CNN
F 2 "" H 1750 1150 50  0001 C CNN
F 3 "" H 1750 1150 50  0001 C CNN
	1    1750 1150
	1    0    0    -1  
$EndComp
Text HLabel 1250 2350 0    50   Input ~ 0
REG_IN
Text HLabel 1250 1650 0    50   Input ~ 0
I2
Text HLabel 1250 1750 0    50   Input ~ 0
I3
Text HLabel 1250 1850 0    50   Input ~ 0
I4
Text HLabel 1250 1950 0    50   Input ~ 0
I5
Text HLabel 1250 2050 0    50   Input ~ 0
I6
Text HLabel 1250 2150 0    50   Input ~ 0
I7
Text HLabel 3350 2500 0    50   Input ~ 0
~REG_OUT
Text HLabel 2250 1450 2    50   Input ~ 0
O0
Text HLabel 2250 1550 2    50   Input ~ 0
O1
Text HLabel 2250 1650 2    50   Input ~ 0
O2
Text HLabel 2250 1750 2    50   Input ~ 0
O3
Text HLabel 2250 1850 2    50   Input ~ 0
O4
Text HLabel 2250 1950 2    50   Input ~ 0
O5
Text HLabel 2250 2050 2    50   Input ~ 0
O6
Text HLabel 2250 2150 2    50   Input ~ 0
O7
$Comp
L Device:C_Small C19
U 1 1 5AFCD0FB
P 700 1850
AR Path="/5AFD5CE2/5AFCCD08/5AFCD0FB" Ref="C19"  Part="1" 
AR Path="/5AFD5CE2/5B0AB8A7/5AFCD0FB" Ref="C21"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5AFCD0FB" Ref="C23"  Part="1" 
AR Path="/5B0FE4FF/5AFCD0FB" Ref="C23"  Part="1" 
AR Path="/5B0FE82A/5AFCD0FB" Ref="C23"  Part="1" 
AR Path="/5B0FEA60/5AFCD0FB" Ref="C132"  Part="1" 
F 0 "C132" H 792 1896 50  0000 L CNN
F 1 "0.1uF" H 792 1805 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 700 1850 50  0001 C CNN
F 3 "~" H 700 1850 50  0001 C CNN
	1    700  1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  1750 700  1150
Wire Wire Line
	700  1150 1750 1150
Wire Wire Line
	1750 2750 700  2750
Wire Wire Line
	700  2750 700  1950
$Comp
L 74xx:74HC245 U9
U 1 1 5AFCDA3B
P 3850 2000
AR Path="/5AFD5CE2/5AFCCD08/5AFCDA3B" Ref="U9"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5AFCDA3B" Ref="U83"  Part="1" 
AR Path="/5AFD5CE2/5B0AB8A7/5AFCDA3B" Ref="U11"  Part="1" 
AR Path="/5B0FE4FF/5AFCDA3B" Ref="U83"  Part="1" 
AR Path="/5B0FE82A/5AFCDA3B" Ref="U83"  Part="1" 
AR Path="/5B0FEA60/5AFCDA3B" Ref="U122"  Part="1" 
F 0 "U122" H 3950 2700 50  0000 C CNN
F 1 "74HC245" H 3900 1700 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 3850 2000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 3850 2000 50  0001 C CNN
	1    3850 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0317
U 1 1 5AFCDF58
P 1250 2450
AR Path="/5AFD5CE2/5AFCCD08/5AFCDF58" Ref="#PWR0317"  Part="1" 
AR Path="/5AFD5CE2/5B0AB8A7/5AFCDF58" Ref="#PWR0323"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5AFCDF58" Ref="#PWR0329"  Part="1" 
AR Path="/5B0FE4FF/5AFCDF58" Ref="#PWR0329"  Part="1" 
AR Path="/5B0FE82A/5AFCDF58" Ref="#PWR0329"  Part="1" 
AR Path="/5B0FEA60/5AFCDF58" Ref="#PWR0477"  Part="1" 
F 0 "#PWR0477" H 1250 2200 50  0001 C CNN
F 1 "GND" H 1255 2277 50  0000 C CNN
F 2 "" H 1250 2450 50  0001 C CNN
F 3 "" H 1250 2450 50  0001 C CNN
	1    1250 2450
	1    0    0    -1  
$EndComp
Text HLabel 3350 1500 0    50   Input ~ 0
O0
Text HLabel 3350 1600 0    50   Input ~ 0
O1
Text HLabel 3350 1700 0    50   Input ~ 0
O2
Text HLabel 3350 1800 0    50   Input ~ 0
O3
Text HLabel 3350 1900 0    50   Input ~ 0
O4
Text HLabel 3350 2000 0    50   Input ~ 0
O5
Text HLabel 3350 2100 0    50   Input ~ 0
O6
Text HLabel 3350 2200 0    50   Input ~ 0
O7
Text HLabel 4350 1500 2    50   Input ~ 0
BUS0
Text HLabel 4350 1600 2    50   Input ~ 0
BUS1
Text HLabel 4350 1700 2    50   Input ~ 0
BUS2
Text HLabel 4350 1800 2    50   Input ~ 0
BUS3
Text HLabel 4350 1900 2    50   Input ~ 0
BUS4
Text HLabel 4350 2000 2    50   Input ~ 0
BUS5
Text HLabel 4350 2100 2    50   Input ~ 0
BUS6
Text HLabel 4350 2200 2    50   Input ~ 0
BUS7
$Comp
L power:GND #PWR0318
U 1 1 5AFCF275
P 3850 2800
AR Path="/5AFD5CE2/5AFCCD08/5AFCF275" Ref="#PWR0318"  Part="1" 
AR Path="/5AFD5CE2/5B0AB8A7/5AFCF275" Ref="#PWR0324"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5AFCF275" Ref="#PWR0330"  Part="1" 
AR Path="/5B0FE4FF/5AFCF275" Ref="#PWR0330"  Part="1" 
AR Path="/5B0FE82A/5AFCF275" Ref="#PWR0330"  Part="1" 
AR Path="/5B0FEA60/5AFCF275" Ref="#PWR0478"  Part="1" 
F 0 "#PWR0478" H 3850 2550 50  0001 C CNN
F 1 "GND" H 3855 2627 50  0000 C CNN
F 2 "" H 3850 2800 50  0001 C CNN
F 3 "" H 3850 2800 50  0001 C CNN
	1    3850 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C20
U 1 1 5AFCF63F
P 2800 1900
AR Path="/5AFD5CE2/5AFCCD08/5AFCF63F" Ref="C20"  Part="1" 
AR Path="/5AFD5CE2/5B0AB8A7/5AFCF63F" Ref="C22"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5AFCF63F" Ref="C90"  Part="1" 
AR Path="/5B0FE4FF/5AFCF63F" Ref="C90"  Part="1" 
AR Path="/5B0FE82A/5AFCF63F" Ref="C90"  Part="1" 
AR Path="/5B0FEA60/5AFCF63F" Ref="C133"  Part="1" 
F 0 "C133" H 2892 1946 50  0000 L CNN
F 1 "0.1uF" H 2892 1855 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2800 1900 50  0001 C CNN
F 3 "~" H 2800 1900 50  0001 C CNN
	1    2800 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 1800 2800 1200
Wire Wire Line
	2800 1200 3850 1200
Wire Wire Line
	3850 2800 2800 2800
Wire Wire Line
	2800 2800 2800 2000
Connection ~ 3850 2800
$Comp
L power:VCC #PWR0319
U 1 1 5AFCFAAC
P 3850 1200
AR Path="/5AFD5CE2/5AFCCD08/5AFCFAAC" Ref="#PWR0319"  Part="1" 
AR Path="/5AFD5CE2/5B0AB8A7/5AFCFAAC" Ref="#PWR0325"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5AFCFAAC" Ref="#PWR0331"  Part="1" 
AR Path="/5B0FE4FF/5AFCFAAC" Ref="#PWR0331"  Part="1" 
AR Path="/5B0FE82A/5AFCFAAC" Ref="#PWR0331"  Part="1" 
AR Path="/5B0FEA60/5AFCFAAC" Ref="#PWR0479"  Part="1" 
F 0 "#PWR0479" H 3850 1050 50  0001 C CNN
F 1 "VCC" H 3867 1373 50  0000 C CNN
F 2 "" H 3850 1200 50  0001 C CNN
F 3 "" H 3850 1200 50  0001 C CNN
	1    3850 1200
	1    0    0    -1  
$EndComp
Connection ~ 3850 1200
$Comp
L power:VCC #PWR0320
U 1 1 5AFCFCC3
P 3350 2400
AR Path="/5AFD5CE2/5AFCCD08/5AFCFCC3" Ref="#PWR0320"  Part="1" 
AR Path="/5AFD5CE2/5B0AB8A7/5AFCFCC3" Ref="#PWR0326"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5AFCFCC3" Ref="#PWR0332"  Part="1" 
AR Path="/5B0FE4FF/5AFCFCC3" Ref="#PWR0332"  Part="1" 
AR Path="/5B0FE82A/5AFCFCC3" Ref="#PWR0332"  Part="1" 
AR Path="/5B0FEA60/5AFCFCC3" Ref="#PWR0480"  Part="1" 
F 0 "#PWR0480" H 3350 2250 50  0001 C CNN
F 1 "VCC" H 3367 2573 50  0000 C CNN
F 2 "" H 3350 2400 50  0001 C CNN
F 3 "" H 3350 2400 50  0001 C CNN
	1    3350 2400
	0    -1   -1   0   
$EndComp
Connection ~ 1750 2750
Connection ~ 1750 1150
Text HLabel 1250 1450 0    50   Input ~ 0
I0
Text HLabel 1250 1550 0    50   Input ~ 0
I1
$EndSCHEMATC
