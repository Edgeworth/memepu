EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 31 35
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
L 74xx:74LS32 U119
U 1 1 5B101C4D
P 1200 1350
F 0 "U119" H 1200 1675 50  0000 C CNN
F 1 "74LS32" H 1200 1584 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1200 1350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 1200 1350 50  0001 C CNN
	1    1200 1350
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS32 U119
U 2 1 5B101C7F
P 1200 1900
F 0 "U119" H 1200 2225 50  0000 C CNN
F 1 "74LS32" H 1200 2134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1200 1900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 1200 1900 50  0001 C CNN
	2    1200 1900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS32 U119
U 3 1 5B101CB8
P 1200 2450
F 0 "U119" H 1200 2775 50  0000 C CNN
F 1 "74LS32" H 1200 2684 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1200 2450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 1200 2450 50  0001 C CNN
	3    1200 2450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS32 U119
U 4 1 5B101CF4
P 1200 3000
F 0 "U119" H 1200 3325 50  0000 C CNN
F 1 "74LS32" H 1200 3234 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1200 3000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 1200 3000 50  0001 C CNN
	4    1200 3000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS32 U119
U 5 1 5B101D33
P 1600 700
F 0 "U119" V 1233 700 50  0000 C CNN
F 1 "74LS32" V 1324 700 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1600 700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 1600 700 50  0001 C CNN
	5    1600 700 
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C130
U 1 1 5B101EE4
P 2100 600
F 0 "C130" H 2192 646 50  0000 L CNN
F 1 "0.1uF" H 2192 555 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2100 600 50  0001 C CNN
F 3 "~" H 2100 600 50  0001 C CNN
	1    2100 600 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0463
U 1 1 5B101F67
P 2100 700
F 0 "#PWR0463" H 2100 550 50  0001 C CNN
F 1 "VCC" V 2117 828 50  0000 L CNN
F 2 "" H 2100 700 50  0001 C CNN
F 3 "" H 2100 700 50  0001 C CNN
	1    2100 700 
	0    1    1    0   
$EndComp
Connection ~ 2100 700 
$Comp
L power:GND #PWR0464
U 1 1 5B101FEE
P 2100 500
F 0 "#PWR0464" H 2100 250 50  0001 C CNN
F 1 "GND" H 2105 327 50  0000 C CNN
F 2 "" H 2100 500 50  0001 C CNN
F 3 "" H 2100 500 50  0001 C CNN
	1    2100 500 
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0465
U 1 1 5B102018
P 1100 700
F 0 "#PWR0465" H 1100 450 50  0001 C CNN
F 1 "GND" V 1105 572 50  0000 R CNN
F 2 "" H 1100 700 50  0001 C CNN
F 3 "" H 1100 700 50  0001 C CNN
	1    1100 700 
	0    1    1    0   
$EndComp
$Comp
L 74xx:74LS32 U120
U 1 1 5B102297
P 2150 1600
F 0 "U120" H 2150 1925 50  0000 C CNN
F 1 "74LS32" H 2150 1834 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 2150 1600 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 2150 1600 50  0001 C CNN
	1    2150 1600
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS32 U120
U 2 1 5B10229E
P 2200 2700
F 0 "U120" H 2200 3025 50  0000 C CNN
F 1 "74LS32" H 2200 2934 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 2200 2700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 2200 2700 50  0001 C CNN
	2    2200 2700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS32 U120
U 3 1 5B1022A5
P 2950 2100
F 0 "U120" H 2950 2425 50  0000 C CNN
F 1 "74LS32" H 2950 2334 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 2950 2100 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 2950 2100 50  0001 C CNN
	3    2950 2100
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS32 U120
U 4 1 5B1022AC
P 1800 3600
F 0 "U120" H 1800 3925 50  0000 C CNN
F 1 "74LS32" H 1800 3834 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1800 3600 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 1800 3600 50  0001 C CNN
	4    1800 3600
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS32 U120
U 5 1 5B1022B3
P 3350 850
F 0 "U120" V 2983 850 50  0000 C CNN
F 1 "74LS32" V 3074 850 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 3350 850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 3350 850 50  0001 C CNN
	5    3350 850 
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C131
U 1 1 5B1022BA
P 3850 750
F 0 "C131" H 3942 796 50  0000 L CNN
F 1 "0.1uF" H 3942 705 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 3850 750 50  0001 C CNN
F 3 "~" H 3850 750 50  0001 C CNN
	1    3850 750 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0466
U 1 1 5B1022C1
P 3850 850
F 0 "#PWR0466" H 3850 700 50  0001 C CNN
F 1 "VCC" V 3867 978 50  0000 L CNN
F 2 "" H 3850 850 50  0001 C CNN
F 3 "" H 3850 850 50  0001 C CNN
	1    3850 850 
	0    1    1    0   
$EndComp
Connection ~ 3850 850 
$Comp
L power:GND #PWR0467
U 1 1 5B1022C8
P 3850 650
F 0 "#PWR0467" H 3850 400 50  0001 C CNN
F 1 "GND" H 3855 477 50  0000 C CNN
F 2 "" H 3850 650 50  0001 C CNN
F 3 "" H 3850 650 50  0001 C CNN
	1    3850 650 
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0468
U 1 1 5B1022CE
P 2850 850
F 0 "#PWR0468" H 2850 600 50  0001 C CNN
F 1 "GND" V 2855 722 50  0000 R CNN
F 2 "" H 2850 850 50  0001 C CNN
F 3 "" H 2850 850 50  0001 C CNN
	1    2850 850 
	0    1    1    0   
$EndComp
Wire Wire Line
	1500 1350 1850 1350
Wire Wire Line
	1850 1350 1850 1500
Wire Wire Line
	1500 1900 1850 1900
Wire Wire Line
	1850 1900 1850 1700
Wire Wire Line
	1500 2450 1900 2450
Wire Wire Line
	1900 2450 1900 2600
Wire Wire Line
	1500 3000 1900 3000
Wire Wire Line
	1900 3000 1900 2800
Wire Wire Line
	2500 2700 2500 2200
Wire Wire Line
	2500 2200 2650 2200
Wire Wire Line
	2450 1600 2450 2000
Wire Wire Line
	2450 2000 2650 2000
Text HLabel 3250 2100 2    50   Input ~ 0
INT_FLAG
Text HLabel 900  1250 0    50   Input ~ 0
INT0
Text HLabel 900  1450 0    50   Input ~ 0
INT1
Text HLabel 900  1800 0    50   Input ~ 0
INT2
Text HLabel 900  2000 0    50   Input ~ 0
INT3
Text HLabel 900  2350 0    50   Input ~ 0
INT4
Text HLabel 900  2550 0    50   Input ~ 0
INT5
Text HLabel 900  2900 0    50   Input ~ 0
INT6
Text HLabel 900  3100 0    50   Input ~ 0
INT7
Text HLabel 1500 3500 0    50   Input ~ 0
MMU_READ_FAULT
Text HLabel 1500 3700 0    50   Input ~ 0
MMU_WRITE_FAULT
Text HLabel 2100 3600 2    50   Input ~ 0
MMU_FAULT_FLAG
$EndSCHEMATC
