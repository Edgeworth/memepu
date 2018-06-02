EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 37
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
L Switch:SW_DIP_x08 SW4
U 1 1 5B2C1F8A
P 1250 1050
F 0 "SW4" V 1296 620 50  0000 R CNN
F 1 "SW_DIP_x08" V 1205 620 50  0000 R CNN
F 2 "Button_Switch_THT:SW_DIP_SPSTx08_Slide_9.78x22.5mm_W7.62mm_P2.54mm" H 1250 1050 50  0001 C CNN
F 3 "" H 1250 1050 50  0001 C CNN
	1    1250 1050
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0125
U 1 1 5B2C21F5
P 850 750
F 0 "#PWR0125" H 850 600 50  0001 C CNN
F 1 "VCC" H 867 923 50  0000 C CNN
F 2 "" H 850 750 50  0001 C CNN
F 3 "" H 850 750 50  0001 C CNN
	1    850  750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  750  950  750 
Connection ~ 850  750 
Wire Wire Line
	950  750  1050 750 
Connection ~ 950  750 
Wire Wire Line
	1050 750  1150 750 
Connection ~ 1050 750 
Wire Wire Line
	1150 750  1250 750 
Connection ~ 1150 750 
Wire Wire Line
	1250 750  1350 750 
Connection ~ 1250 750 
Wire Wire Line
	1350 750  1450 750 
Connection ~ 1350 750 
Wire Wire Line
	1450 750  1550 750 
Connection ~ 1450 750 
$Comp
L Device:R R15
U 1 1 5B2C25DC
P 850 2700
F 0 "R15" H 750 2850 50  0000 L CNN
F 1 "100K" V 850 2600 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 780 2700 50  0001 C CNN
F 3 "~" H 850 2700 50  0001 C CNN
	1    850  2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 5B2C2BC6
P 950 2700
F 0 "R16" H 850 2850 50  0000 L CNN
F 1 "100K" V 950 2600 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 880 2700 50  0001 C CNN
F 3 "~" H 950 2700 50  0001 C CNN
	1    950  2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R17
U 1 1 5B2C2C99
P 1050 2700
F 0 "R17" H 950 2850 50  0000 L CNN
F 1 "100K" V 1050 2600 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 980 2700 50  0001 C CNN
F 3 "~" H 1050 2700 50  0001 C CNN
	1    1050 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R18
U 1 1 5B2C2DA5
P 1150 2700
F 0 "R18" H 1050 2850 50  0000 L CNN
F 1 "100K" V 1150 2600 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1080 2700 50  0001 C CNN
F 3 "~" H 1150 2700 50  0001 C CNN
	1    1150 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R19
U 1 1 5B2C2E95
P 1250 2700
F 0 "R19" H 1150 2850 50  0000 L CNN
F 1 "100K" V 1250 2600 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1180 2700 50  0001 C CNN
F 3 "~" H 1250 2700 50  0001 C CNN
	1    1250 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R20
U 1 1 5B2C2FA7
P 1350 2700
F 0 "R20" H 1250 2850 50  0000 L CNN
F 1 "100K" V 1350 2600 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1280 2700 50  0001 C CNN
F 3 "~" H 1350 2700 50  0001 C CNN
	1    1350 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R21
U 1 1 5B2C305F
P 1450 2700
F 0 "R21" H 1350 2850 50  0000 L CNN
F 1 "100K" V 1450 2600 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 2700 50  0001 C CNN
F 3 "~" H 1450 2700 50  0001 C CNN
	1    1450 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R22
U 1 1 5B2C312F
P 1550 2700
F 0 "R22" H 1450 2850 50  0000 L CNN
F 1 "100K" V 1550 2600 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1480 2700 50  0001 C CNN
F 3 "~" H 1550 2700 50  0001 C CNN
	1    1550 2700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC245 U7
U 1 1 5B2C3561
P 2200 1850
F 0 "U7" H 2300 2500 50  0000 C CNN
F 1 "74HC245" H 2200 1550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 2200 1850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 2200 1850 50  0001 C CNN
	1    2200 1850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0126
U 1 1 5B2C3FAF
P 2200 1050
F 0 "#PWR0126" H 2200 900 50  0001 C CNN
F 1 "VCC" H 2217 1223 50  0000 C CNN
F 2 "" H 2200 1050 50  0001 C CNN
F 3 "" H 2200 1050 50  0001 C CNN
	1    2200 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0127
U 1 1 5B2C4405
P 2200 2650
F 0 "#PWR0127" H 2200 2400 50  0001 C CNN
F 1 "GND" H 2205 2477 50  0000 C CNN
F 2 "" H 2200 2650 50  0001 C CNN
F 3 "" H 2200 2650 50  0001 C CNN
	1    2200 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0128
U 1 1 5B2CAE54
P 850 2850
F 0 "#PWR0128" H 850 2600 50  0001 C CNN
F 1 "GND" H 855 2677 50  0000 C CNN
F 2 "" H 850 2850 50  0001 C CNN
F 3 "" H 850 2850 50  0001 C CNN
	1    850  2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 1350 1700 1350
Wire Wire Line
	1450 1350 1450 1450
Wire Wire Line
	1450 1450 1700 1450
Wire Wire Line
	1700 1550 1350 1550
Wire Wire Line
	1350 1550 1350 1350
Wire Wire Line
	1250 1350 1250 1650
Wire Wire Line
	1250 1650 1700 1650
Wire Wire Line
	1700 1750 1150 1750
Wire Wire Line
	1150 1750 1150 1350
Wire Wire Line
	1050 1350 1050 1850
Wire Wire Line
	1050 1850 1700 1850
Wire Wire Line
	1700 1950 950  1950
Wire Wire Line
	950  1950 950  1350
Wire Wire Line
	850  1350 850  2050
Wire Wire Line
	850  2050 1700 2050
Wire Wire Line
	850  2050 850  2550
Wire Wire Line
	950  2550 950  1950
Wire Wire Line
	1050 1850 1050 2550
Wire Wire Line
	1150 2550 1150 1750
Wire Wire Line
	1250 2550 1250 1650
Wire Wire Line
	1350 1550 1350 2550
Wire Wire Line
	1450 2550 1450 1450
Wire Wire Line
	1550 1350 1550 2550
Wire Wire Line
	850  2850 950  2850
Connection ~ 850  2850
Wire Wire Line
	950  2850 1050 2850
Connection ~ 950  2850
Wire Wire Line
	1050 2850 1150 2850
Connection ~ 1050 2850
Wire Wire Line
	1150 2850 1250 2850
Connection ~ 1150 2850
Wire Wire Line
	1250 2850 1350 2850
Connection ~ 1250 2850
Wire Wire Line
	1350 2850 1450 2850
Connection ~ 1350 2850
Wire Wire Line
	1450 2850 1550 2850
Connection ~ 1450 2850
Connection ~ 1550 1350
Connection ~ 1450 1450
Connection ~ 1350 1550
Connection ~ 1250 1650
Connection ~ 1150 1750
Connection ~ 1050 1850
Connection ~ 950  1950
Connection ~ 850  2050
$Comp
L power:VCC #PWR0129
U 1 1 5B2DCAC9
P 1700 2250
F 0 "#PWR0129" H 1700 2100 50  0001 C CNN
F 1 "VCC" H 1717 2423 50  0000 C CNN
F 2 "" H 1700 2250 50  0001 C CNN
F 3 "" H 1700 2250 50  0001 C CNN
	1    1700 2250
	1    0    0    -1  
$EndComp
Text HLabel 1700 2350 0    50   Input ~ 0
~OUT
Text HLabel 2700 1350 2    50   Input ~ 0
O0
Text HLabel 2700 1450 2    50   Input ~ 0
O1
Text HLabel 2700 1550 2    50   Input ~ 0
O2
Text HLabel 2700 1650 2    50   Input ~ 0
O3
Text HLabel 2700 1750 2    50   Input ~ 0
O4
Text HLabel 2700 1850 2    50   Input ~ 0
O5
Text HLabel 2700 1950 2    50   Input ~ 0
O6
Text HLabel 2700 2050 2    50   Input ~ 0
O7
$EndSCHEMATC
