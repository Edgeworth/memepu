EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 13 29
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
L power:VCC #PWR0170
U 1 1 5B042567
P 1950 1300
F 0 "#PWR0170" H 1950 1150 50  0001 C CNN
F 1 "VCC" V 1967 1428 50  0000 L CNN
F 2 "" H 1950 1300 50  0001 C CNN
F 3 "" H 1950 1300 50  0001 C CNN
	1    1950 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0171
U 1 1 5B0425AF
P 1950 3800
F 0 "#PWR0171" H 1950 3550 50  0001 C CNN
F 1 "GND" V 1955 3672 50  0000 R CNN
F 2 "" H 1950 3800 50  0001 C CNN
F 3 "" H 1950 3800 50  0001 C CNN
	1    1950 3800
	1    0    0    -1  
$EndComp
Text HLabel 1350 1400 0    50   Input ~ 0
A0
Text HLabel 1350 1500 0    50   Input ~ 0
A1
Text HLabel 1350 1600 0    50   Input ~ 0
A2
Text HLabel 1350 1700 0    50   Input ~ 0
A3
Text HLabel 1350 1800 0    50   Input ~ 0
A4
Text HLabel 1350 1900 0    50   Input ~ 0
A5
Text HLabel 1350 2000 0    50   Input ~ 0
A6
Text HLabel 1350 2100 0    50   Input ~ 0
A7
Text HLabel 1350 2200 0    50   Input ~ 0
B0
Text HLabel 1350 2300 0    50   Input ~ 0
B1
Text HLabel 1350 2400 0    50   Input ~ 0
B2
Text HLabel 1350 2500 0    50   Input ~ 0
B3
Text HLabel 1350 2600 0    50   Input ~ 0
B4
Text HLabel 1350 2700 0    50   Input ~ 0
B5
Text HLabel 1350 2800 0    50   Input ~ 0
B6
Text HLabel 1350 2900 0    50   Input ~ 0
B7
Text HLabel 1350 3700 0    50   Input ~ 0
~OUT
$Comp
L power:GND #PWR0172
U 1 1 5B042674
P 1350 3600
F 0 "#PWR0172" H 1350 3350 50  0001 C CNN
F 1 "GND" V 1355 3472 50  0000 R CNN
F 2 "" H 1350 3600 50  0001 C CNN
F 3 "" H 1350 3600 50  0001 C CNN
	1    1350 3600
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0173
U 1 1 5B042983
P 1350 3400
F 0 "#PWR0173" H 1350 3250 50  0001 C CNN
F 1 "VCC" V 1368 3527 50  0000 L CNN
F 2 "" H 1350 3400 50  0001 C CNN
F 3 "" H 1350 3400 50  0001 C CNN
	1    1350 3400
	0    -1   -1   0   
$EndComp
Text HLabel 2550 1400 2    50   Input ~ 0
O0
Text HLabel 2550 1500 2    50   Input ~ 0
O1
Text HLabel 2550 1600 2    50   Input ~ 0
O2
Text HLabel 2550 1700 2    50   Input ~ 0
O3
Text HLabel 2550 1800 2    50   Input ~ 0
O4
Text HLabel 2550 1900 2    50   Input ~ 0
O5
Text HLabel 2550 2000 2    50   Input ~ 0
O6
Text HLabel 2550 2100 2    50   Input ~ 0
O7
Text HLabel 1350 3000 0    50   Input ~ 0
MLU0
Text HLabel 1350 3100 0    50   Input ~ 0
MLU1
Text HLabel 1350 3200 0    50   Input ~ 0
MLU2
$Comp
L Device:C_Small C38
U 1 1 5B0441A8
P 2300 950
F 0 "C38" H 2392 996 50  0000 L CNN
F 1 "0.1uF" H 2392 905 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2300 950 50  0001 C CNN
F 3 "~" H 2300 950 50  0001 C CNN
	1    2300 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0174
U 1 1 5B044211
P 2300 850
F 0 "#PWR0174" H 2300 600 50  0001 C CNN
F 1 "GND" H 2305 677 50  0000 C CNN
F 2 "" H 2300 850 50  0001 C CNN
F 3 "" H 2300 850 50  0001 C CNN
	1    2300 850 
	-1   0    0    1   
$EndComp
$Comp
L Memory_Flash:SST39SF040 U?
U 1 1 5B55481F
P 1950 2600
AR Path="/5B0C6DCD/5B55481F" Ref="U?"  Part="1" 
AR Path="/5B04243E/5B55481F" Ref="U31"  Part="1" 
F 0 "U31" H 1950 2700 50  0000 C CNN
F 1 "SST39SF040" H 2000 2550 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 1950 2900 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 1950 2900 50  0001 C CNN
	1    1950 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1050 2300 1300
Wire Wire Line
	2300 1300 1950 1300
Connection ~ 1950 1300
$EndSCHEMATC
