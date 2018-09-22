EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 10 20
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
P 1350 2250
F 0 "#PWR051" H 1350 2000 50  0001 C CNN
F 1 "GND" H 1355 2077 50  0000 C CNN
F 2 "" H 1350 2250 50  0001 C CNN
F 3 "" H 1350 2250 50  0001 C CNN
	1    1350 2250
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR050
U 1 1 5B0D9F9C
P 1350 950
F 0 "#PWR050" H 1350 800 50  0001 C CNN
F 1 "VCC" H 1367 1123 50  0000 C CNN
F 2 "" H 1350 950 50  0001 C CNN
F 3 "" H 1350 950 50  0001 C CNN
	1    1350 950 
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C118
U 1 1 5B0D9FA2
P 1650 950
F 0 "C118" V 1421 950 50  0000 C CNN
F 1 "0.1uF" V 1512 950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 1650 950 50  0001 C CNN
F 3 "~" H 1650 950 50  0001 C CNN
	1    1650 950 
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR052
U 1 1 5B0D9FA9
P 1750 950
F 0 "#PWR052" H 1750 700 50  0001 C CNN
F 1 "GND" V 1755 822 50  0000 R CNN
F 2 "" H 1750 950 50  0001 C CNN
F 3 "" H 1750 950 50  0001 C CNN
	1    1750 950 
	0    -1   -1   0   
$EndComp
Text HLabel 950  1650 0    50   Input ~ 0
~RESET
Text HLabel 950  1350 0    50   Input ~ 0
CLK
Text HLabel 1750 1150 2    50   Input ~ 0
O0
Text HLabel 1750 1250 2    50   Input ~ 0
O1
Text HLabel 1750 1350 2    50   Input ~ 0
O2
Text HLabel 1750 1450 2    50   Input ~ 0
O3
$Comp
L 74xx:74HC590 U39
U 1 1 5B6FC11A
P 1350 1650
F 0 "U39" H 1350 1650 50  0000 C CNN
F 1 "74HC590" H 1350 1450 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 1350 1700 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC590.pdf" H 1350 1700 50  0001 C CNN
	1    1350 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 950  1350 950 
Connection ~ 1350 950 
$Comp
L power:GND #PWR011
U 1 1 5B6FC33E
P 950 1850
F 0 "#PWR011" H 950 1600 50  0001 C CNN
F 1 "GND" H 955 1677 50  0000 C CNN
F 2 "" H 950 1850 50  0001 C CNN
F 3 "" H 950 1850 50  0001 C CNN
	1    950  1850
	0    1    1    0   
$EndComp
NoConn ~ 1750 2050
Text HLabel 1750 1550 2    50   Input ~ 0
O4
Wire Wire Line
	950  1350 950  1450
$Comp
L power:GND #PWR06
U 1 1 5B6FD8D8
P 950 1150
F 0 "#PWR06" H 950 900 50  0001 C CNN
F 1 "GND" H 955 977 50  0000 C CNN
F 2 "" H 950 1150 50  0001 C CNN
F 3 "" H 950 1150 50  0001 C CNN
	1    950  1150
	0    1    1    0   
$EndComp
NoConn ~ 1750 1650
NoConn ~ 1750 1750
NoConn ~ 1750 1850
$EndSCHEMATC
