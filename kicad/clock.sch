EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L Timer:LM555 U1
U 1 1 5ADF0EF3
P 2650 1400
F 0 "U1" H 2800 1800 50  0000 C CNN
F 1 "LM555" H 2650 1400 50  0000 C CNN
F 2 "" H 2650 1400 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm555.pdf" H 2650 1400 50  0001 C CNN
	1    2650 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5ADF19B9
P 2600 2200
F 0 "C1" H 2692 2246 50  0000 L CNN
F 1 "0.1uF" H 2692 2155 50  0000 L CNN
F 2 "" H 2600 2200 50  0001 C CNN
F 3 "~" H 2600 2200 50  0001 C CNN
	1    2600 2200
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5ADF19F1
P 2600 2600
F 0 "C2" H 2508 2554 50  0000 R CNN
F 1 "1uF" H 2508 2645 50  0000 R CNN
F 2 "" H 2600 2600 50  0001 C CNN
F 3 "~" H 2600 2600 50  0001 C CNN
	1    2600 2600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2950 2200 2700 2200
Wire Wire Line
	2700 2200 2700 2600
Connection ~ 2700 2200
Wire Wire Line
	2500 2600 2500 2200
Wire Wire Line
	2500 2200 2050 2200
Connection ~ 2500 2200
$Comp
L power:+5V #PWR0101
U 1 1 5ADF1B6E
P 2950 2200
F 0 "#PWR0101" H 2950 2050 50  0001 C CNN
F 1 "+5V" H 2965 2373 50  0000 C CNN
F 2 "" H 2950 2200 50  0001 C CNN
F 3 "" H 2950 2200 50  0001 C CNN
	1    2950 2200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5ADF1BB9
P 2050 2200
F 0 "#PWR0102" H 2050 1950 50  0001 C CNN
F 1 "GND" H 2055 2027 50  0000 C CNN
F 2 "" H 2050 2200 50  0001 C CNN
F 3 "" H 2050 2200 50  0001 C CNN
	1    2050 2200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5ADF1D70
P 2650 1800
F 0 "#PWR0103" H 2650 1550 50  0001 C CNN
F 1 "GND" H 2655 1627 50  0000 C CNN
F 2 "" H 2650 1800 50  0001 C CNN
F 3 "" H 2650 1800 50  0001 C CNN
	1    2650 1800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5ADF1D9F
P 2650 1000
F 0 "#PWR0104" H 2650 850 50  0001 C CNN
F 1 "+5V" H 2665 1173 50  0000 C CNN
F 2 "" H 2650 1000 50  0001 C CNN
F 3 "" H 2650 1000 50  0001 C CNN
	1    2650 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5ADF1E11
P 1750 1700
F 0 "C4" H 1842 1746 50  0000 L CNN
F 1 "10nF" H 1842 1655 50  0000 L CNN
F 2 "" H 1750 1700 50  0001 C CNN
F 3 "~" H 1750 1700 50  0001 C CNN
	1    1750 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5ADF1E95
P 1750 1800
F 0 "#PWR0105" H 1750 1550 50  0001 C CNN
F 1 "GND" V 1755 1672 50  0000 R CNN
F 2 "" H 1750 1800 50  0001 C CNN
F 3 "" H 1750 1800 50  0001 C CNN
	1    1750 1800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 5ADF1F33
P 2150 1600
F 0 "#PWR0106" H 2150 1450 50  0001 C CNN
F 1 "+5V" V 2165 1728 50  0000 L CNN
F 2 "" H 2150 1600 50  0001 C CNN
F 3 "" H 2150 1600 50  0001 C CNN
	1    2150 1600
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0107
U 1 1 5ADF1FD5
P 3650 1100
F 0 "#PWR0107" H 3650 950 50  0001 C CNN
F 1 "+5V" H 3665 1273 50  0000 C CNN
F 2 "" H 3650 1100 50  0001 C CNN
F 3 "" H 3650 1100 50  0001 C CNN
	1    3650 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5ADF206F
P 3650 1250
F 0 "R1" H 3720 1296 50  0000 L CNN
F 1 "1K" H 3720 1205 50  0000 L CNN
F 2 "" V 3580 1250 50  0001 C CNN
F 3 "~" H 3650 1250 50  0001 C CNN
	1    3650 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 1400 3400 1400
Wire Wire Line
	3400 1400 3150 1400
$Comp
L Device:C_Small C3
U 1 1 5ADF22E9
P 1750 1200
F 0 "C3" V 1521 1200 50  0000 C CNN
F 1 "1uF" V 1612 1200 50  0000 C CNN
F 2 "" H 1750 1200 50  0001 C CNN
F 3 "~" H 1750 1200 50  0001 C CNN
	1    1750 1200
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 1400 1750 1400
Wire Wire Line
	1750 1400 1750 1600
$Comp
L power:GND #PWR0108
U 1 1 5ADF24BB
P 1650 1200
F 0 "#PWR0108" H 1650 950 50  0001 C CNN
F 1 "GND" H 1655 1027 50  0000 C CNN
F 2 "" H 1650 1200 50  0001 C CNN
F 3 "" H 1650 1200 50  0001 C CNN
	1    1650 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 1600 3150 1600
Connection ~ 3400 1400
Wire Wire Line
	2150 1200 1850 1200
Text Label 2150 1200 2    50   ~ 0
AC_TR
Wire Wire Line
	3400 1900 3400 2000
Text Label 3400 2000 0    50   ~ 0
AC_TR
$Comp
L Device:R_Variable R2
U 1 1 5ADF287B
P 3400 1750
F 0 "R2" H 3528 1796 50  0000 L CNN
F 1 "1M" H 3528 1705 50  0000 L CNN
F 2 "" V 3330 1750 50  0001 C CNN
F 3 "~" H 3400 1750 50  0001 C CNN
	1    3400 1750
	1    0    0    -1  
$EndComp
Connection ~ 3400 1600
Wire Wire Line
	3400 1400 3400 1600
$Comp
L Device:R R3
U 1 1 5ADF2B89
P 3750 1750
F 0 "R3" H 3820 1796 50  0000 L CNN
F 1 "10K" H 3820 1705 50  0000 L CNN
F 2 "" V 3680 1750 50  0001 C CNN
F 3 "~" H 3750 1750 50  0001 C CNN
	1    3750 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 1600 3750 1600
Wire Wire Line
	3750 1900 3400 1900
Connection ~ 3400 1900
Text Notes 3450 1550 0    20   ~ 0
Impose a minimum value on the \nvariable resistor to keep duty \ncycle close to 50%. Current\nvalues give min 0.7 Hz, max 70 Hz.
$Comp
L Timer:LM555 U?
U 1 1 5ADF4FEB
P 6350 1750
F 0 "U?" H 6500 2150 50  0000 C CNN
F 1 "LM555" H 6350 1750 50  0000 C CNN
F 2 "" H 6350 1750 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm555.pdf" H 6350 1750 50  0001 C CNN
	1    6350 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5ADF4FF2
P 6400 2600
F 0 "C?" H 6492 2646 50  0000 L CNN
F 1 "0.1uF" H 6492 2555 50  0000 L CNN
F 2 "" H 6400 2600 50  0001 C CNN
F 3 "~" H 6400 2600 50  0001 C CNN
	1    6400 2600
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5ADF4FF9
P 6400 3000
F 0 "C?" H 6308 2954 50  0000 R CNN
F 1 "1uF" H 6308 3045 50  0000 R CNN
F 2 "" H 6400 3000 50  0001 C CNN
F 3 "~" H 6400 3000 50  0001 C CNN
	1    6400 3000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6750 2600 6500 2600
Wire Wire Line
	6500 2600 6500 3000
Connection ~ 6500 2600
Wire Wire Line
	6300 3000 6300 2600
Wire Wire Line
	6300 2600 5850 2600
Connection ~ 6300 2600
$Comp
L power:+5V #PWR?
U 1 1 5ADF5006
P 6750 2600
F 0 "#PWR?" H 6750 2450 50  0001 C CNN
F 1 "+5V" H 6765 2773 50  0000 C CNN
F 2 "" H 6750 2600 50  0001 C CNN
F 3 "" H 6750 2600 50  0001 C CNN
	1    6750 2600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5ADF500C
P 5850 2600
F 0 "#PWR?" H 5850 2350 50  0001 C CNN
F 1 "GND" H 5855 2427 50  0000 C CNN
F 2 "" H 5850 2600 50  0001 C CNN
F 3 "" H 5850 2600 50  0001 C CNN
	1    5850 2600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5ADF5012
P 6350 2150
F 0 "#PWR?" H 6350 1900 50  0001 C CNN
F 1 "GND" H 6355 1977 50  0000 C CNN
F 2 "" H 6350 2150 50  0001 C CNN
F 3 "" H 6350 2150 50  0001 C CNN
	1    6350 2150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5ADF5018
P 6350 1350
F 0 "#PWR?" H 6350 1200 50  0001 C CNN
F 1 "+5V" H 6365 1523 50  0000 C CNN
F 2 "" H 6350 1350 50  0001 C CNN
F 3 "" H 6350 1350 50  0001 C CNN
	1    6350 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5ADF501E
P 5450 2050
F 0 "C?" V 5221 2050 50  0000 C CNN
F 1 "10nF" V 5312 2050 50  0000 C CNN
F 2 "" H 5450 2050 50  0001 C CNN
F 3 "~" H 5450 2050 50  0001 C CNN
	1    5450 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5ADF5025
P 5450 2150
F 0 "#PWR?" H 5450 1900 50  0001 C CNN
F 1 "GND" V 5455 2022 50  0000 R CNN
F 2 "" H 5450 2150 50  0001 C CNN
F 3 "" H 5450 2150 50  0001 C CNN
	1    5450 2150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5ADF502B
P 5850 1950
F 0 "#PWR?" H 5850 1800 50  0001 C CNN
F 1 "+5V" V 5865 2078 50  0000 L CNN
F 2 "" H 5850 1950 50  0001 C CNN
F 3 "" H 5850 1950 50  0001 C CNN
	1    5850 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5850 1750 5450 1750
Wire Wire Line
	5450 1750 5450 1950
Text Label 3150 1200 0    50   ~ 0
ADJ_CLK
Wire Notes Line
	4550 800  4550 3350
Wire Notes Line
	4550 3350 7900 3350
Wire Notes Line
	7900 3350 7900 800 
Wire Notes Line
	7900 800  4550 800 
Wire Notes Line
	1150 700  1150 3050
Wire Notes Line
	1150 3050 4200 3050
Wire Notes Line
	4200 3050 4200 700 
Wire Notes Line
	4200 700  1150 700 
Text Label 6850 1550 0    50   ~ 0
BTN_CLK
Wire Wire Line
	7100 1950 6850 1950
$Comp
L power:GND #PWR?
U 1 1 5ADF5049
P 5000 2200
F 0 "#PWR?" H 5000 1950 50  0001 C CNN
F 1 "GND" H 5005 2027 50  0000 C CNN
F 2 "" H 5000 2200 50  0001 C CNN
F 3 "" H 5000 2200 50  0001 C CNN
	1    5000 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2100 5000 2200
$Comp
L Switch:SW_Push SW?
U 1 1 5ADF3C8D
P 5000 1900
F 0 "SW?" H 5000 2185 50  0000 C CNN
F 1 "SW_Push" H 5000 2094 50  0000 C CNN
F 2 "" H 5000 2100 50  0001 C CNN
F 3 "" H 5000 2100 50  0001 C CNN
	1    5000 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5000 1100 5000 1150
$Comp
L power:+5V #PWR?
U 1 1 5ADFA32D
P 5000 1100
F 0 "#PWR?" H 5000 950 50  0001 C CNN
F 1 "+5V" H 5015 1273 50  0000 C CNN
F 2 "" H 5000 1100 50  0001 C CNN
F 3 "" H 5000 1100 50  0001 C CNN
	1    5000 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5ADF6F9C
P 5000 1300
F 0 "R?" H 4930 1254 50  0000 R CNN
F 1 "100K" H 4930 1345 50  0000 R CNN
F 2 "" V 4930 1300 50  0001 C CNN
F 3 "~" H 5000 1300 50  0001 C CNN
	1    5000 1300
	-1   0    0    1   
$EndComp
Wire Wire Line
	5000 1450 5000 1550
Wire Wire Line
	5000 1550 5000 1700
Connection ~ 5000 1550
Wire Wire Line
	5000 1550 5850 1550
$Comp
L Device:C_Small C?
U 1 1 5ADF5040
P 7100 2050
F 0 "C?" H 7008 2004 50  0000 R CNN
F 1 "0.1uF" H 7008 2095 50  0000 R CNN
F 2 "" H 7100 2050 50  0001 C CNN
F 3 "~" H 7100 2050 50  0001 C CNN
	1    7100 2050
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5ADFE1CA
P 7100 2150
F 0 "#PWR?" H 7100 1900 50  0001 C CNN
F 1 "GND" H 7105 1977 50  0000 C CNN
F 2 "" H 7100 2150 50  0001 C CNN
F 3 "" H 7100 2150 50  0001 C CNN
	1    7100 2150
	1    0    0    -1  
$EndComp
Connection ~ 7100 1950
Wire Wire Line
	7100 1750 7100 1950
Wire Wire Line
	7100 1750 6850 1750
Connection ~ 7100 1750
Wire Wire Line
	7300 1750 7100 1750
$Comp
L power:+5V #PWR?
U 1 1 5ADF5031
P 7300 1450
F 0 "#PWR?" H 7300 1300 50  0001 C CNN
F 1 "+5V" H 7315 1623 50  0000 C CNN
F 2 "" H 7300 1450 50  0001 C CNN
F 3 "" H 7300 1450 50  0001 C CNN
	1    7300 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5ADF5037
P 7300 1600
F 0 "R?" H 7370 1646 50  0000 L CNN
F 1 "1M" H 7370 1555 50  0000 L CNN
F 2 "" V 7230 1600 50  0001 C CNN
F 3 "~" H 7300 1600 50  0001 C CNN
	1    7300 1600
	1    0    0    -1  
$EndComp
Text Notes 5050 1500 0    20   ~ 0
On push, pullls TRIGGER down to GND,\nturning the output on. DISCHARGE is then\ndisconnected, allowing the cap to charge.
Text Notes 7150 1950 0    20   ~ 0
When button is pressed, C charges up\nuntil THRESHOLD is passed. The output\nis disabled, and it instantly discharges.\nCurrently set for 100ms ON time.\ndischarges turning 
Text Notes 6000 750  0    50   ~ 0
Button Clock\n
Text Notes 2350 650  0    50   ~ 0
Adjustable Clock\n
$Comp
L Timer:LM555 U?
U 1 1 5AE088E5
P 2450 4650
F 0 "U?" H 2600 5050 50  0000 C CNN
F 1 "LM555" H 2450 4650 50  0000 C CNN
F 2 "" H 2450 4650 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm555.pdf" H 2450 4650 50  0001 C CNN
	1    2450 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5AE088EC
P 2450 5350
F 0 "C?" H 2542 5396 50  0000 L CNN
F 1 "0.1uF" H 2542 5305 50  0000 L CNN
F 2 "" H 2450 5350 50  0001 C CNN
F 3 "~" H 2450 5350 50  0001 C CNN
	1    2450 5350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5AE088F3
P 2450 5750
F 0 "C?" H 2358 5704 50  0000 R CNN
F 1 "1uF" H 2358 5795 50  0000 R CNN
F 2 "" H 2450 5750 50  0001 C CNN
F 3 "~" H 2450 5750 50  0001 C CNN
	1    2450 5750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2800 5350 2550 5350
Wire Wire Line
	2550 5350 2550 5750
Connection ~ 2550 5350
Wire Wire Line
	2350 5750 2350 5350
Wire Wire Line
	2350 5350 1900 5350
Connection ~ 2350 5350
$Comp
L power:+5V #PWR?
U 1 1 5AE08900
P 2800 5350
F 0 "#PWR?" H 2800 5200 50  0001 C CNN
F 1 "+5V" H 2815 5523 50  0000 C CNN
F 2 "" H 2800 5350 50  0001 C CNN
F 3 "" H 2800 5350 50  0001 C CNN
	1    2800 5350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5AE08906
P 1900 5350
F 0 "#PWR?" H 1900 5100 50  0001 C CNN
F 1 "GND" H 1905 5177 50  0000 C CNN
F 2 "" H 1900 5350 50  0001 C CNN
F 3 "" H 1900 5350 50  0001 C CNN
	1    1900 5350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5AE0890C
P 2450 5050
F 0 "#PWR?" H 2450 4800 50  0001 C CNN
F 1 "GND" H 2455 4877 50  0000 C CNN
F 2 "" H 2450 5050 50  0001 C CNN
F 3 "" H 2450 5050 50  0001 C CNN
	1    2450 5050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5AE08912
P 2450 4250
F 0 "#PWR?" H 2450 4100 50  0001 C CNN
F 1 "+5V" H 2465 4423 50  0000 C CNN
F 2 "" H 2450 4250 50  0001 C CNN
F 3 "" H 2450 4250 50  0001 C CNN
	1    2450 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5AE08918
P 1600 4650
F 0 "C?" V 1371 4650 50  0000 C CNN
F 1 "10nF" V 1462 4650 50  0000 C CNN
F 2 "" H 1600 4650 50  0001 C CNN
F 3 "~" H 1600 4650 50  0001 C CNN
	1    1600 4650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5AE0891F
P 1500 4650
F 0 "#PWR?" H 1500 4400 50  0001 C CNN
F 1 "GND" V 1505 4522 50  0000 R CNN
F 2 "" H 1500 4650 50  0001 C CNN
F 3 "" H 1500 4650 50  0001 C CNN
	1    1500 4650
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_SPDT SW?
U 1 1 5AE0892D
P 3700 5400
F 0 "SW?" V 3746 5212 50  0000 R CNN
F 1 "ACS_SW" V 3655 5212 50  0000 R CNN
F 2 "" H 3700 5400 50  0001 C CNN
F 3 "" H 3700 5400 50  0001 C CNN
	1    3700 5400
	0    -1   -1   0   
$EndComp
NoConn ~ 2950 4650
Text Notes 2800 4200 0    20   ~ 0
Connecting the switch to RESET\nsets output to OFF. Connecting it\nto TRIGGER sets it to ON.  This\nuses the 555 as an SR latch.
$Comp
L power:GND #PWR?
U 1 1 5AE106C6
P 2950 4850
F 0 "#PWR?" H 2950 4600 50  0001 C CNN
F 1 "GND" V 2955 4722 50  0000 R CNN
F 2 "" H 2950 4850 50  0001 C CNN
F 3 "" H 2950 4850 50  0001 C CNN
	1    2950 4850
	0    -1   -1   0   
$EndComp
Text Label 2950 4450 0    50   ~ 0
ADJ_CLK_SEL
$Comp
L power:GND #PWR?
U 1 1 5AE15C63
P 3700 5600
F 0 "#PWR?" H 3700 5350 50  0001 C CNN
F 1 "GND" H 3705 5427 50  0000 C CNN
F 2 "" H 3700 5600 50  0001 C CNN
F 3 "" H 3700 5600 50  0001 C CNN
	1    3700 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5AE16346
P 3500 4750
F 0 "R?" H 3430 4704 50  0000 R CNN
F 1 "10K" H 3430 4795 50  0000 R CNN
F 2 "" V 3430 4750 50  0001 C CNN
F 3 "~" H 3500 4750 50  0001 C CNN
	1    3500 4750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5AE18727
P 3500 4600
F 0 "#PWR?" H 3500 4450 50  0001 C CNN
F 1 "+5V" H 3515 4773 50  0000 C CNN
F 2 "" H 3500 4600 50  0001 C CNN
F 3 "" H 3500 4600 50  0001 C CNN
	1    3500 4600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5AE1875E
P 3900 4750
F 0 "R?" H 3830 4704 50  0000 R CNN
F 1 "10K" H 3830 4795 50  0000 R CNN
F 2 "" V 3830 4750 50  0001 C CNN
F 3 "~" H 3900 4750 50  0001 C CNN
	1    3900 4750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5AE187B0
P 3900 4600
F 0 "#PWR?" H 3900 4450 50  0001 C CNN
F 1 "+5V" H 3915 4773 50  0000 C CNN
F 2 "" H 3900 4600 50  0001 C CNN
F 3 "" H 3900 4600 50  0001 C CNN
	1    3900 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 4650 1700 4650
Text Label 1950 4450 2    50   ~ 0
ACS_TR
Text Label 1950 4850 2    50   ~ 0
ACS_R
Text Label 3500 5050 2    50   ~ 0
ACS_R
Text Label 3900 5050 0    50   ~ 0
ACS_TR
Wire Wire Line
	3600 5200 3600 5050
Wire Wire Line
	3600 5050 3500 5050
Wire Wire Line
	3500 4900 3500 5050
Wire Wire Line
	3900 4900 3900 5050
Wire Wire Line
	3900 5050 3800 5050
Wire Wire Line
	3800 5050 3800 5200
Wire Notes Line
	1100 3800 1100 6150
Wire Notes Line
	1100 6150 4450 6150
Wire Notes Line
	4450 6150 4450 3800
Wire Notes Line
	4450 3800 1100 3800
Text Notes 1950 3700 0    50   ~ 0
Adjustable / Manual Clock Select Debouncer
$Comp
L Device:R R?
U 1 1 5AE2A155
P 5150 3850
F 0 "R?" H 5220 3896 50  0000 L CNN
F 1 "100K" H 5220 3805 50  0000 L CNN
F 2 "" V 5080 3850 50  0001 C CNN
F 3 "~" H 5150 3850 50  0001 C CNN
	1    5150 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5AE2A2D1
P 5500 3850
F 0 "R?" H 5570 3896 50  0000 L CNN
F 1 "100K" H 5570 3805 50  0000 L CNN
F 2 "" V 5430 3850 50  0001 C CNN
F 3 "~" H 5500 3850 50  0001 C CNN
	1    5500 3850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5AE2A333
P 5150 3700
F 0 "#PWR?" H 5150 3550 50  0001 C CNN
F 1 "+5V" V 5165 3828 50  0000 L CNN
F 2 "" H 5150 3700 50  0001 C CNN
F 3 "" H 5150 3700 50  0001 C CNN
	1    5150 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5AE2A3C7
P 5500 3700
F 0 "#PWR?" H 5500 3550 50  0001 C CNN
F 1 "+5V" V 5515 3828 50  0000 L CNN
F 2 "" H 5500 3700 50  0001 C CNN
F 3 "" H 5500 3700 50  0001 C CNN
	1    5500 3700
	1    0    0    -1  
$EndComp
$Comp
L 74xx_IEEE:74151 U?
U 1 1 5AE2A47F
P 8600 5300
F 0 "U?" H 8600 6166 50  0000 C CNN
F 1 "74151" H 8600 6075 50  0000 C CNN
F 2 "" H 8600 5300 50  0001 C CNN
F 3 "" H 8600 5300 50  0001 C CNN
	1    8600 5300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x03 SW?
U 1 1 5AE2A76E
P 5350 6050
F 0 "SW?" H 5350 6517 50  0000 C CNN
F 1 "SW_DIP_x03" H 5350 6426 50  0000 C CNN
F 2 "" H 5350 6050 50  0001 C CNN
F 3 "" H 5350 6050 50  0001 C CNN
	1    5350 6050
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5AE2B797
P 5850 3700
F 0 "#PWR?" H 5850 3550 50  0001 C CNN
F 1 "+5V" V 5865 3828 50  0000 L CNN
F 2 "" H 5850 3700 50  0001 C CNN
F 3 "" H 5850 3700 50  0001 C CNN
	1    5850 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5AE2F8E7
P 5850 3850
F 0 "R?" H 5920 3896 50  0000 L CNN
F 1 "100K" H 5920 3805 50  0000 L CNN
F 2 "" V 5780 3850 50  0001 C CNN
F 3 "~" H 5850 3850 50  0001 C CNN
	1    5850 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5AE2FAD9
P 5350 6350
F 0 "#PWR?" H 5350 6100 50  0001 C CNN
F 1 "GND" H 5355 6177 50  0000 C CNN
F 2 "" H 5350 6350 50  0001 C CNN
F 3 "" H 5350 6350 50  0001 C CNN
	1    5350 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 5050 8050 5050
$Comp
L power:GND #PWR?
U 1 1 5AE353DF
P 8050 4750
F 0 "#PWR?" H 8050 4500 50  0001 C CNN
F 1 "GND" H 8055 4577 50  0000 C CNN
F 2 "" H 8050 4750 50  0001 C CNN
F 3 "" H 8050 4750 50  0001 C CNN
	1    8050 4750
	-1   0    0    1   
$EndComp
Text Label 8050 5300 2    50   ~ 0
ADJ_CLK
Text Label 8050 5200 2    50   ~ 0
BTN_CLK
Text Label 9150 4950 0    50   ~ 0
CLK
Text Label 9150 5650 0    50   ~ 0
~CLK
$Comp
L Device:C_Small C?
U 1 1 5AE38673
P 6000 5650
F 0 "C?" V 5771 5650 50  0000 C CNN
F 1 "10nF" V 5862 5650 50  0000 C CNN
F 2 "" H 6000 5650 50  0001 C CNN
F 3 "~" H 6000 5650 50  0001 C CNN
	1    6000 5650
	-1   0    0    1   
$EndComp
$Comp
L Device:Crystal Y?
U 1 1 5AE6D74C
P 8950 1950
F 0 "Y?" H 8950 2218 50  0000 C CNN
F 1 "Crystal" H 8950 2127 50  0000 C CNN
F 2 "" H 8950 1950 50  0001 C CNN
F 3 "~" H 8950 1950 50  0001 C CNN
	1    8950 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5AE6D889
P 8500 2400
F 0 "C?" H 8592 2446 50  0000 L CNN
F 1 "C_Small" H 8592 2355 50  0000 L CNN
F 2 "" H 8500 2400 50  0001 C CNN
F 3 "~" H 8500 2400 50  0001 C CNN
	1    8500 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5AE6D8E9
P 9350 2400
F 0 "C?" H 9442 2446 50  0000 L CNN
F 1 "C_Small" H 9442 2355 50  0000 L CNN
F 2 "" H 9350 2400 50  0001 C CNN
F 3 "~" H 9350 2400 50  0001 C CNN
	1    9350 2400
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 1 1 5AE6E8B5
P 8900 1100
F 0 "U?" H 8900 1417 50  0000 C CNN
F 1 "74HC04" H 8900 1326 50  0000 C CNN
F 2 "" H 8900 1100 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 8900 1100 50  0001 C CNN
	1    8900 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5AE6E9D6
P 8950 1500
F 0 "R?" V 8743 1500 50  0000 C CNN
F 1 "R" V 8834 1500 50  0000 C CNN
F 2 "" V 8880 1500 50  0001 C CNN
F 3 "~" H 8950 1500 50  0001 C CNN
	1    8950 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 2300 8500 1950
Wire Wire Line
	8500 1100 8600 1100
Wire Wire Line
	9200 1100 9350 1100
Wire Wire Line
	9350 1100 9350 1500
$Comp
L power:GND #PWR?
U 1 1 5AE736E3
P 8500 2500
F 0 "#PWR?" H 8500 2250 50  0001 C CNN
F 1 "GND" H 8505 2327 50  0000 C CNN
F 2 "" H 8500 2500 50  0001 C CNN
F 3 "" H 8500 2500 50  0001 C CNN
	1    8500 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5AE73739
P 9350 2500
F 0 "#PWR?" H 9350 2250 50  0001 C CNN
F 1 "GND" H 9355 2327 50  0000 C CNN
F 2 "" H 9350 2500 50  0001 C CNN
F 3 "" H 9350 2500 50  0001 C CNN
	1    9350 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 1500 8800 1500
Connection ~ 8500 1500
Wire Wire Line
	8500 1500 8500 1100
Wire Wire Line
	9100 1500 9350 1500
Connection ~ 9350 1500
Wire Wire Line
	9350 1500 9350 1950
Wire Wire Line
	8500 1950 8800 1950
Connection ~ 8500 1950
Wire Wire Line
	8500 1950 8500 1500
Wire Wire Line
	9100 1950 9350 1950
Connection ~ 9350 1950
Wire Wire Line
	9350 1950 9350 2300
$Comp
L power:+5V #PWR?
U 1 1 5AE78D93
P 8500 1100
F 0 "#PWR?" H 8500 950 50  0001 C CNN
F 1 "+5V" H 8515 1273 50  0000 C CNN
F 2 "" H 8500 1100 50  0001 C CNN
F 3 "" H 8500 1100 50  0001 C CNN
	1    8500 1100
	1    0    0    -1  
$EndComp
Connection ~ 8500 1100
$Comp
L Amplifier_Operational:TL082 U?
U 1 1 5AE79F54
P 10250 1200
F 0 "U?" H 10300 1450 50  0000 L CNN
F 1 "TL082" H 10300 1350 50  0000 L CNN
F 2 "" H 10250 1200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 10250 1200 50  0001 C CNN
	1    10250 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 1100 9950 1100
Connection ~ 9350 1100
$Comp
L power:+5V #PWR?
U 1 1 5AE7B06B
P 10150 900
F 0 "#PWR?" H 10150 750 50  0001 C CNN
F 1 "+5V" H 10165 1073 50  0000 C CNN
F 2 "" H 10150 900 50  0001 C CNN
F 3 "" H 10150 900 50  0001 C CNN
	1    10150 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5AE7B0BC
P 10150 1500
F 0 "#PWR?" H 10150 1250 50  0001 C CNN
F 1 "GND" H 10155 1327 50  0000 C CNN
F 2 "" H 10150 1500 50  0001 C CNN
F 3 "" H 10150 1500 50  0001 C CNN
	1    10150 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5AE7B140
P 10550 1500
F 0 "R?" H 10620 1546 50  0000 L CNN
F 1 "R" H 10620 1455 50  0000 L CNN
F 2 "" V 10480 1500 50  0001 C CNN
F 3 "~" H 10550 1500 50  0001 C CNN
	1    10550 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5AE7B1C0
P 9950 1950
F 0 "R?" H 9880 1904 50  0000 R CNN
F 1 "R" H 9880 1995 50  0000 R CNN
F 2 "" V 9880 1950 50  0001 C CNN
F 3 "~" H 9950 1950 50  0001 C CNN
	1    9950 1950
	-1   0    0    1   
$EndComp
Wire Wire Line
	10550 1200 10550 1350
Wire Wire Line
	10550 1650 10550 1800
Wire Wire Line
	10550 1800 9950 1800
Wire Wire Line
	9950 1300 9950 1800
Connection ~ 9950 1800
Text Label 10550 1200 0    50   ~ 0
CHR_CLK
Text Label 8050 5400 2    50   ~ 0
CHR_CLK
Wire Wire Line
	5150 6350 5250 6350
Wire Wire Line
	5350 6350 5250 6350
Connection ~ 5350 6350
Connection ~ 5250 6350
$Comp
L 74xx_IEEE:7414 U?
U 1 1 5AEA1595
P 7000 4450
F 0 "U?" H 7000 4600 50  0000 C CNN
F 1 "7414" H 7000 4300 50  0000 C CNN
F 2 "" H 7000 4450 50  0001 C CNN
F 3 "" H 7000 4450 50  0001 C CNN
	1    7000 4450
	1    0    0    -1  
$EndComp
$Comp
L 74xx_IEEE:7414 U?
U 2 1 5AEA401B
P 7000 5000
F 0 "U?" H 7000 5150 50  0000 C CNN
F 1 "7414" H 7000 4850 50  0000 C CNN
F 2 "" H 7000 5000 50  0001 C CNN
F 3 "" H 7000 5000 50  0001 C CNN
	2    7000 5000
	1    0    0    -1  
$EndComp
$Comp
L 74xx_IEEE:7414 U?
U 3 1 5AEA4320
P 7000 5550
F 0 "U?" H 7000 5700 50  0000 C CNN
F 1 "7414" H 7000 5400 50  0000 C CNN
F 2 "" H 7000 5550 50  0001 C CNN
F 3 "" H 7000 5550 50  0001 C CNN
	3    7000 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4000 5250 4000
Wire Wire Line
	5850 4100 5350 4100
Wire Wire Line
	7550 4450 7550 4850
Wire Wire Line
	7550 5000 7550 4950
Wire Wire Line
	7550 5550 7650 5550
Wire Wire Line
	7650 5550 7650 5050
$Comp
L power:GND #PWR?
U 1 1 5AEC4517
P 6000 5750
F 0 "#PWR?" H 6000 5500 50  0001 C CNN
F 1 "GND" H 6005 5577 50  0000 C CNN
F 2 "" H 6000 5750 50  0001 C CNN
F 3 "" H 6000 5750 50  0001 C CNN
	1    6000 5750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5AEC45B5
P 5650 5550
F 0 "R?" V 5443 5550 50  0000 C CNN
F 1 "R" V 5534 5550 50  0000 C CNN
F 2 "" V 5580 5550 50  0001 C CNN
F 3 "~" H 5650 5550 50  0001 C CNN
	1    5650 5550
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 5550 6450 5550
Wire Wire Line
	6000 5550 5800 5550
Connection ~ 6000 5550
Wire Wire Line
	5500 5550 5350 5550
Connection ~ 5350 5550
Wire Wire Line
	5350 5550 5350 5750
Wire Wire Line
	5250 4000 5250 5000
Wire Wire Line
	5150 4000 5150 4450
$Comp
L Device:C_Small C?
U 1 1 5AED5F66
P 6000 5100
F 0 "C?" V 5771 5100 50  0000 C CNN
F 1 "10nF" V 5862 5100 50  0000 C CNN
F 2 "" H 6000 5100 50  0001 C CNN
F 3 "~" H 6000 5100 50  0001 C CNN
	1    6000 5100
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5AED5F6D
P 6000 5200
F 0 "#PWR?" H 6000 4950 50  0001 C CNN
F 1 "GND" H 6005 5027 50  0000 C CNN
F 2 "" H 6000 5200 50  0001 C CNN
F 3 "" H 6000 5200 50  0001 C CNN
	1    6000 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5AED5F73
P 5650 5000
F 0 "R?" V 5443 5000 50  0000 C CNN
F 1 "R" V 5534 5000 50  0000 C CNN
F 2 "" V 5580 5000 50  0001 C CNN
F 3 "~" H 5650 5000 50  0001 C CNN
	1    5650 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 5000 6450 5000
Wire Wire Line
	6000 5000 5800 5000
Connection ~ 6000 5000
$Comp
L Device:C_Small C?
U 1 1 5AED7965
P 6000 4550
F 0 "C?" V 5771 4550 50  0000 C CNN
F 1 "10nF" V 5862 4550 50  0000 C CNN
F 2 "" H 6000 4550 50  0001 C CNN
F 3 "~" H 6000 4550 50  0001 C CNN
	1    6000 4550
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5AED796C
P 6000 4650
F 0 "#PWR?" H 6000 4400 50  0001 C CNN
F 1 "GND" H 6005 4477 50  0000 C CNN
F 2 "" H 6000 4650 50  0001 C CNN
F 3 "" H 6000 4650 50  0001 C CNN
	1    6000 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5AED7972
P 5650 4450
F 0 "R?" V 5443 4450 50  0000 C CNN
F 1 "R" V 5534 4450 50  0000 C CNN
F 2 "" V 5580 4450 50  0001 C CNN
F 3 "~" H 5650 4450 50  0001 C CNN
	1    5650 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 4450 6450 4450
Wire Wire Line
	6000 4450 5800 4450
Connection ~ 6000 4450
Wire Wire Line
	5850 4100 5850 4000
Wire Wire Line
	5350 4100 5350 4450
Wire Wire Line
	5350 5000 5350 5550
Connection ~ 5250 5000
Wire Wire Line
	5250 5000 5250 5750
Wire Wire Line
	5350 4450 5350 5000
Connection ~ 5150 4450
Wire Wire Line
	5150 4450 5150 5750
Wire Wire Line
	5150 4450 5350 4450
Wire Wire Line
	5250 5000 5350 5000
Connection ~ 5350 4450
Wire Wire Line
	5350 4450 5500 4450
Connection ~ 5350 5000
Wire Wire Line
	5350 5000 5500 5000
Wire Wire Line
	7550 4850 8050 4850
Wire Wire Line
	7550 4950 8050 4950
$EndSCHEMATC
