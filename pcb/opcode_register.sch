EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 27 35
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
L power:GND #PWR023
U 1 1 5B0D6BA4
P 1750 2400
F 0 "#PWR023" H 1750 2150 50  0001 C CNN
F 1 "GND" H 1755 2227 50  0000 C CNN
F 2 "" H 1750 2400 50  0001 C CNN
F 3 "" H 1750 2400 50  0001 C CNN
	1    1750 2400
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR020
U 1 1 5B0D6BAA
P 1750 800
F 0 "#PWR020" H 1750 650 50  0001 C CNN
F 1 "VCC" H 1767 973 50  0000 C CNN
F 2 "" H 1750 800 50  0001 C CNN
F 3 "" H 1750 800 50  0001 C CNN
	1    1750 800 
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C103
U 1 1 5B0D6BB0
P 2050 800
F 0 "C103" V 1821 800 50  0000 C CNN
F 1 "0.1uF" V 1912 800 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2050 800 50  0001 C CNN
F 3 "~" H 2050 800 50  0001 C CNN
	1    2050 800 
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR026
U 1 1 5B0D6BB7
P 2150 800
F 0 "#PWR026" H 2150 550 50  0001 C CNN
F 1 "GND" V 2155 672 50  0000 R CNN
F 2 "" H 2150 800 50  0001 C CNN
F 3 "" H 2150 800 50  0001 C CNN
	1    2150 800 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1950 800  1750 800 
$Comp
L 74xx:74LS161 U?
U 1 1 5B0D6BBF
P 3600 1600
AR Path="/5B096BDD/5B0D6BBF" Ref="U?"  Part="1" 
AR Path="/5B0C6DCD/5B0D66CF/5B0D6BBF" Ref="U106"  Part="1" 
F 0 "U106" H 3600 1550 50  0000 C CNN
F 1 "74LS161" H 3650 1300 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 3600 1600 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 3600 1600 50  0001 C CNN
	1    3600 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR029
U 1 1 5B0D6BC6
P 3600 2400
F 0 "#PWR029" H 3600 2150 50  0001 C CNN
F 1 "GND" H 3605 2227 50  0000 C CNN
F 2 "" H 3600 2400 50  0001 C CNN
F 3 "" H 3600 2400 50  0001 C CNN
	1    3600 2400
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR028
U 1 1 5B0D6BCC
P 3600 800
F 0 "#PWR028" H 3600 650 50  0001 C CNN
F 1 "VCC" H 3617 973 50  0000 C CNN
F 2 "" H 3600 800 50  0001 C CNN
F 3 "" H 3600 800 50  0001 C CNN
	1    3600 800 
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C117
U 1 1 5B0D6BD2
P 3900 800
F 0 "C117" V 3671 800 50  0000 C CNN
F 1 "0.1uF" V 3762 800 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 3900 800 50  0001 C CNN
F 3 "~" H 3900 800 50  0001 C CNN
	1    3900 800 
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR030
U 1 1 5B0D6BD9
P 4000 800
F 0 "#PWR030" H 4000 550 50  0001 C CNN
F 1 "GND" V 4005 672 50  0000 R CNN
F 2 "" H 4000 800 50  0001 C CNN
F 3 "" H 4000 800 50  0001 C CNN
	1    4000 800 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3800 800  3600 800 
Connection ~ 3600 800 
Text HLabel 1250 1100 0    50   Input ~ 0
BUS0
Text HLabel 1250 1200 0    50   Input ~ 0
BUS1
Text HLabel 1250 1300 0    50   Input ~ 0
BUS2
Text HLabel 1250 1400 0    50   Input ~ 0
BUS3
Text HLabel 3100 1100 0    50   Input ~ 0
BUS4
Text HLabel 3100 1200 0    50   Input ~ 0
BUS5
Text HLabel 3100 1300 0    50   Input ~ 0
BUS6
Text HLabel 3100 1400 0    50   Input ~ 0
BUS7
Text HLabel 1250 1600 0    50   Input ~ 0
~OPCODE0_IN
Text HLabel 1250 2100 0    50   Input ~ 0
~RESET
Text HLabel 3100 2100 0    50   Input ~ 0
~RESET
Text HLabel 1250 1900 0    50   Input ~ 0
CLK
Text HLabel 3100 1900 0    50   Input ~ 0
CLK
$Comp
L 74xx:74LS161 U?
U 1 1 5B0D6CEE
P 1750 3650
AR Path="/5B096BDD/5B0D6CEE" Ref="U?"  Part="1" 
AR Path="/5B0C6DCD/5B0D66CF/5B0D6CEE" Ref="U105"  Part="1" 
F 0 "U105" H 1750 3600 50  0000 C CNN
F 1 "74LS161" H 1800 3350 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 1750 3650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 1750 3650 50  0001 C CNN
	1    1750 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 5B0D6CF5
P 1750 4450
F 0 "#PWR025" H 1750 4200 50  0001 C CNN
F 1 "GND" H 1755 4277 50  0000 C CNN
F 2 "" H 1750 4450 50  0001 C CNN
F 3 "" H 1750 4450 50  0001 C CNN
	1    1750 4450
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR024
U 1 1 5B0D6CFB
P 1750 2850
F 0 "#PWR024" H 1750 2700 50  0001 C CNN
F 1 "VCC" H 1767 3023 50  0000 C CNN
F 2 "" H 1750 2850 50  0001 C CNN
F 3 "" H 1750 2850 50  0001 C CNN
	1    1750 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C116
U 1 1 5B0D6D01
P 2050 2850
F 0 "C116" V 1821 2850 50  0000 C CNN
F 1 "0.1uF" V 1912 2850 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2050 2850 50  0001 C CNN
F 3 "~" H 2050 2850 50  0001 C CNN
	1    2050 2850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR027
U 1 1 5B0D6D08
P 2150 2850
F 0 "#PWR027" H 2150 2600 50  0001 C CNN
F 1 "GND" V 2155 2722 50  0000 R CNN
F 2 "" H 2150 2850 50  0001 C CNN
F 3 "" H 2150 2850 50  0001 C CNN
	1    2150 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1950 2850 1750 2850
Connection ~ 1750 2850
Text HLabel 1250 3150 0    50   Input ~ 0
BUS0
Text HLabel 1250 3250 0    50   Input ~ 0
BUS1
Text HLabel 1250 3350 0    50   Input ~ 0
BUS2
Text HLabel 1250 3450 0    50   Input ~ 0
BUS3
Text HLabel 1250 3650 0    50   Input ~ 0
~OPCODE1_IN
Text HLabel 1250 4150 0    50   Input ~ 0
~RESET
Text HLabel 1250 3950 0    50   Input ~ 0
CLK
Text HLabel 3100 1600 0    50   Input ~ 0
~OPCODE0_IN
Text HLabel 2250 1100 2    50   Input ~ 0
O0
Text HLabel 2250 1200 2    50   Input ~ 0
O1
Text HLabel 2250 1300 2    50   Input ~ 0
O2
Text HLabel 2250 1400 2    50   Input ~ 0
O3
Text HLabel 4100 1100 2    50   Input ~ 0
O4
Text HLabel 4100 1200 2    50   Input ~ 0
O5
Text HLabel 4100 1300 2    50   Input ~ 0
O6
Text HLabel 4100 1400 2    50   Input ~ 0
O7
NoConn ~ 4100 1600
NoConn ~ 2250 3650
Text HLabel 2250 3150 2    50   Input ~ 0
O8
Text HLabel 2250 3250 2    50   Input ~ 0
O9
Text HLabel 2250 3350 2    50   Input ~ 0
O10
Text HLabel 2250 3450 2    50   Input ~ 0
O11
Text Notes 550  250  0    50   ~ 0
Use counters here\nsince they are presettable.
Connection ~ 1750 800 
$Comp
L 74xx:74LS161 U?
U 1 1 5B0D6B9D
P 1750 1600
AR Path="/5B096BDD/5B0D6B9D" Ref="U?"  Part="1" 
AR Path="/5B0C6DCD/5B0D66CF/5B0D6B9D" Ref="U91"  Part="1" 
F 0 "U91" H 1750 1550 50  0000 C CNN
F 1 "74LS161" H 1800 1300 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 1750 1600 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 1750 1600 50  0001 C CNN
	1    1750 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0214
U 1 1 5B5F39D0
P 1250 3750
F 0 "#PWR0214" H 1250 3500 50  0001 C CNN
F 1 "GND" H 1255 3577 50  0000 C CNN
F 2 "" H 1250 3750 50  0001 C CNN
F 3 "" H 1250 3750 50  0001 C CNN
	1    1250 3750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0215
U 1 1 5B5F39ED
P 1250 3850
F 0 "#PWR0215" H 1250 3600 50  0001 C CNN
F 1 "GND" H 1255 3677 50  0000 C CNN
F 2 "" H 1250 3850 50  0001 C CNN
F 3 "" H 1250 3850 50  0001 C CNN
	1    1250 3850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0216
U 1 1 5B5F3A04
P 1250 1700
F 0 "#PWR0216" H 1250 1450 50  0001 C CNN
F 1 "GND" H 1255 1527 50  0000 C CNN
F 2 "" H 1250 1700 50  0001 C CNN
F 3 "" H 1250 1700 50  0001 C CNN
	1    1250 1700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0220
U 1 1 5B5F3A1B
P 1250 1800
F 0 "#PWR0220" H 1250 1550 50  0001 C CNN
F 1 "GND" H 1255 1627 50  0000 C CNN
F 2 "" H 1250 1800 50  0001 C CNN
F 3 "" H 1250 1800 50  0001 C CNN
	1    1250 1800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0221
U 1 1 5B5F3A32
P 3100 1700
F 0 "#PWR0221" H 3100 1450 50  0001 C CNN
F 1 "GND" H 3105 1527 50  0000 C CNN
F 2 "" H 3100 1700 50  0001 C CNN
F 3 "" H 3100 1700 50  0001 C CNN
	1    3100 1700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0222
U 1 1 5B5F3A49
P 3100 1800
F 0 "#PWR0222" H 3100 1550 50  0001 C CNN
F 1 "GND" H 3105 1627 50  0000 C CNN
F 2 "" H 3100 1800 50  0001 C CNN
F 3 "" H 3100 1800 50  0001 C CNN
	1    3100 1800
	0    1    1    0   
$EndComp
NoConn ~ 2250 1600
$EndSCHEMATC
