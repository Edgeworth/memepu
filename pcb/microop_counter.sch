EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 29 35
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
L power:GND #PWR051
U 1 1 5B0D9F96
P 1750 2600
F 0 "#PWR051" H 1750 2350 50  0001 C CNN
F 1 "GND" H 1755 2427 50  0000 C CNN
F 2 "" H 1750 2600 50  0001 C CNN
F 3 "" H 1750 2600 50  0001 C CNN
	1    1750 2600
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR050
U 1 1 5B0D9F9C
P 1750 1000
F 0 "#PWR050" H 1750 850 50  0001 C CNN
F 1 "VCC" H 1767 1173 50  0000 C CNN
F 2 "" H 1750 1000 50  0001 C CNN
F 3 "" H 1750 1000 50  0001 C CNN
	1    1750 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C118
U 1 1 5B0D9FA2
P 2050 1000
F 0 "C118" V 1821 1000 50  0000 C CNN
F 1 "0.1uF" V 1912 1000 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2050 1000 50  0001 C CNN
F 3 "~" H 2050 1000 50  0001 C CNN
	1    2050 1000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR052
U 1 1 5B0D9FA9
P 2150 1000
F 0 "#PWR052" H 2150 750 50  0001 C CNN
F 1 "GND" V 2155 872 50  0000 R CNN
F 2 "" H 2150 1000 50  0001 C CNN
F 3 "" H 2150 1000 50  0001 C CNN
	1    2150 1000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1950 1000 1750 1000
Text HLabel 1250 2300 0    50   Input ~ 0
~RESET
Text HLabel 1250 2100 0    50   Input ~ 0
CLK
$Comp
L power:VCC #PWR037
U 1 1 5B0D9FB9
P 1250 2000
F 0 "#PWR037" H 1250 1850 50  0001 C CNN
F 1 "VCC" V 1268 2127 50  0000 L CNN
F 2 "" H 1250 2000 50  0001 C CNN
F 3 "" H 1250 2000 50  0001 C CNN
	1    1250 2000
	0    -1   -1   0   
$EndComp
Text HLabel 2250 1300 2    50   Input ~ 0
O0
Text HLabel 2250 1400 2    50   Input ~ 0
O1
Text HLabel 2250 1500 2    50   Input ~ 0
O2
Text HLabel 2250 1600 2    50   Input ~ 0
O3
Connection ~ 1750 1000
$Comp
L 74xx:74LS161 U?
U 1 1 5B0D9F8F
P 1750 1800
AR Path="/5B096BDD/5B0D9F8F" Ref="U?"  Part="1" 
AR Path="/5B0C6DCD/5B0D66CF/5B0D9F8F" Ref="U?"  Part="1" 
AR Path="/5B0C6DCD/5B0D9D66/5B0D9F8F" Ref="U107"  Part="1" 
F 0 "U107" H 1750 1750 50  0000 C CNN
F 1 "74LS161" H 1800 1500 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 1750 1800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 1750 1800 50  0001 C CNN
	1    1750 1800
	1    0    0    -1  
$EndComp
NoConn ~ 2250 1800
Text Notes 500  2650 0    50   ~ 0
Count on falling edge
$Comp
L power:VCC #PWR036
U 1 1 5B0DA463
P 1250 1900
F 0 "#PWR036" H 1250 1750 50  0001 C CNN
F 1 "VCC" V 1268 2027 50  0000 L CNN
F 2 "" H 1250 1900 50  0001 C CNN
F 3 "" H 1250 1900 50  0001 C CNN
	1    1250 1900
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR035
U 1 1 5B0DA474
P 1250 1800
F 0 "#PWR035" H 1250 1650 50  0001 C CNN
F 1 "VCC" V 1268 1927 50  0000 L CNN
F 2 "" H 1250 1800 50  0001 C CNN
F 3 "" H 1250 1800 50  0001 C CNN
	1    1250 1800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR034
U 1 1 5B0DA49F
P 1250 1600
F 0 "#PWR034" H 1250 1350 50  0001 C CNN
F 1 "GND" H 1255 1427 50  0000 C CNN
F 2 "" H 1250 1600 50  0001 C CNN
F 3 "" H 1250 1600 50  0001 C CNN
	1    1250 1600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR033
U 1 1 5B0DA4C0
P 1250 1500
F 0 "#PWR033" H 1250 1250 50  0001 C CNN
F 1 "GND" H 1255 1327 50  0000 C CNN
F 2 "" H 1250 1500 50  0001 C CNN
F 3 "" H 1250 1500 50  0001 C CNN
	1    1250 1500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR032
U 1 1 5B0DA4CF
P 1250 1400
F 0 "#PWR032" H 1250 1150 50  0001 C CNN
F 1 "GND" H 1255 1227 50  0000 C CNN
F 2 "" H 1250 1400 50  0001 C CNN
F 3 "" H 1250 1400 50  0001 C CNN
	1    1250 1400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR031
U 1 1 5B0DA4DE
P 1250 1300
F 0 "#PWR031" H 1250 1050 50  0001 C CNN
F 1 "GND" H 1255 1127 50  0000 C CNN
F 2 "" H 1250 1300 50  0001 C CNN
F 3 "" H 1250 1300 50  0001 C CNN
	1    1250 1300
	0    1    1    0   
$EndComp
$EndSCHEMATC
