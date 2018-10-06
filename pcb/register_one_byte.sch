EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 20 20
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
AR Path="/5BA101FE/5AFCD0D6" Ref="U85"  Part="1" 
F 0 "U85" H 1850 2650 50  0000 C CNN
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
AR Path="/5BA101FE/5AFCD0DD" Ref="#PWR083"  Part="1" 
F 0 "#PWR083" H 1750 2500 50  0001 C CNN
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
AR Path="/5BA101FE/5AFCD0E3" Ref="#PWR082"  Part="1" 
F 0 "#PWR082" H 1750 1000 50  0001 C CNN
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
AR Path="/5BA101FE/5AFCD0FB" Ref="C94"  Part="1" 
F 0 "C94" H 792 1896 50  0000 L CNN
F 1 "0.1uF" H 792 1805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 700 1850 50  0001 C CNN
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
Text HLabel 2250 1450 2    50   Input ~ 0
BUS0
Text HLabel 2250 1550 2    50   Input ~ 0
BUS1
Text HLabel 2250 1650 2    50   Input ~ 0
BUS2
Text HLabel 2250 1750 2    50   Input ~ 0
BUS3
Text HLabel 2250 1850 2    50   Input ~ 0
BUS4
Text HLabel 2250 1950 2    50   Input ~ 0
BUS5
Text HLabel 2250 2050 2    50   Input ~ 0
BUS6
Text HLabel 2250 2150 2    50   Input ~ 0
BUS7
Connection ~ 1750 2750
Connection ~ 1750 1150
Text HLabel 1250 1450 0    50   Input ~ 0
I0
Text HLabel 1250 1550 0    50   Input ~ 0
I1
Text HLabel 1250 2450 0    50   Input ~ 0
~REG_OUT
$EndSCHEMATC
