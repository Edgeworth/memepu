EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 23 37
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
L 74xx:74LS154 U93
U 1 1 5B0C7F2C
P 1550 1950
AR Path="/5B0C6DCD/5B0C7EFE/5B0C7F2C" Ref="U93"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C7F2C" Ref="U95"  Part="1" 
F 0 "U93" H 1500 1800 50  0000 C CNN
F 1 "74LS154" H 1500 1600 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W7.62mm_Socket" H 1550 1950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS154" H 1550 1950 50  0001 C CNN
	1    1550 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0377
U 1 1 5B0C7FBD
P 1550 3050
AR Path="/5B0C6DCD/5B0C7EFE/5B0C7FBD" Ref="#PWR0377"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C7FBD" Ref="#PWR0385"  Part="1" 
F 0 "#PWR0377" H 1550 2800 50  0001 C CNN
F 1 "GND" H 1555 2877 50  0000 C CNN
F 2 "" H 1550 3050 50  0001 C CNN
F 3 "" H 1550 3050 50  0001 C CNN
	1    1550 3050
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0378
U 1 1 5B0C7FE8
P 1550 950
AR Path="/5B0C6DCD/5B0C7EFE/5B0C7FE8" Ref="#PWR0378"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C7FE8" Ref="#PWR0386"  Part="1" 
F 0 "#PWR0378" H 1550 800 50  0001 C CNN
F 1 "VCC" H 1567 1123 50  0000 C CNN
F 2 "" H 1550 950 50  0001 C CNN
F 3 "" H 1550 950 50  0001 C CNN
	1    1550 950 
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C104
U 1 1 5B0C8087
P 1900 950
AR Path="/5B0C6DCD/5B0C7EFE/5B0C8087" Ref="C104"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C8087" Ref="C106"  Part="1" 
F 0 "C104" V 1671 950 50  0000 C CNN
F 1 "0.1uF" V 1762 950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 1900 950 50  0001 C CNN
F 3 "~" H 1900 950 50  0001 C CNN
	1    1900 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 950  1550 950 
Connection ~ 1550 950 
$Comp
L power:GND #PWR0379
U 1 1 5B0C80C2
P 2000 950
AR Path="/5B0C6DCD/5B0C7EFE/5B0C80C2" Ref="#PWR0379"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C80C2" Ref="#PWR0387"  Part="1" 
F 0 "#PWR0379" H 2000 700 50  0001 C CNN
F 1 "GND" V 2005 822 50  0000 R CNN
F 2 "" H 2000 950 50  0001 C CNN
F 3 "" H 2000 950 50  0001 C CNN
	1    2000 950 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0380
U 1 1 5B0C89F0
P 1050 1850
AR Path="/5B0C6DCD/5B0C7EFE/5B0C89F0" Ref="#PWR0380"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C89F0" Ref="#PWR0388"  Part="1" 
F 0 "#PWR0380" H 1050 1600 50  0001 C CNN
F 1 "GND" V 1055 1722 50  0000 R CNN
F 2 "" H 1050 1850 50  0001 C CNN
F 3 "" H 1050 1850 50  0001 C CNN
	1    1050 1850
	0    1    1    0   
$EndComp
Text HLabel 1050 1250 0    50   Input ~ 0
S0
Text HLabel 1050 1350 0    50   Input ~ 0
S1
Text HLabel 1050 1450 0    50   Input ~ 0
S2
Text HLabel 1050 1550 0    50   Input ~ 0
S3
Text HLabel 2050 1250 2    50   Input ~ 0
O0
Text HLabel 2050 1350 2    50   Input ~ 0
O1
Text HLabel 2050 1450 2    50   Input ~ 0
O2
Text HLabel 2050 1550 2    50   Input ~ 0
O3
Text HLabel 2050 1650 2    50   Input ~ 0
O4
Text HLabel 2050 1750 2    50   Input ~ 0
O5
Text HLabel 2050 1850 2    50   Input ~ 0
O6
Text HLabel 2050 1950 2    50   Input ~ 0
O7
Text HLabel 2050 2050 2    50   Input ~ 0
O8
Text HLabel 2050 2150 2    50   Input ~ 0
O9
Text HLabel 2050 2250 2    50   Input ~ 0
O10
Text HLabel 2050 2350 2    50   Input ~ 0
O11
Text HLabel 2050 2450 2    50   Input ~ 0
O12
Text HLabel 2050 2550 2    50   Input ~ 0
O13
Text HLabel 2050 2650 2    50   Input ~ 0
O14
Text HLabel 2050 2750 2    50   Input ~ 0
O15
$Comp
L 74xx:74LS154 U94
U 1 1 5B0C8B66
P 3250 1950
AR Path="/5B0C6DCD/5B0C7EFE/5B0C8B66" Ref="U94"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C8B66" Ref="U96"  Part="1" 
F 0 "U94" H 3200 1800 50  0000 C CNN
F 1 "74LS154" H 3200 1600 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W7.62mm_Socket" H 3250 1950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS154" H 3250 1950 50  0001 C CNN
	1    3250 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0381
U 1 1 5B0C8B6D
P 3250 3050
AR Path="/5B0C6DCD/5B0C7EFE/5B0C8B6D" Ref="#PWR0381"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C8B6D" Ref="#PWR0389"  Part="1" 
F 0 "#PWR0381" H 3250 2800 50  0001 C CNN
F 1 "GND" H 3255 2877 50  0000 C CNN
F 2 "" H 3250 3050 50  0001 C CNN
F 3 "" H 3250 3050 50  0001 C CNN
	1    3250 3050
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0382
U 1 1 5B0C8B73
P 3250 950
AR Path="/5B0C6DCD/5B0C7EFE/5B0C8B73" Ref="#PWR0382"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C8B73" Ref="#PWR0390"  Part="1" 
F 0 "#PWR0382" H 3250 800 50  0001 C CNN
F 1 "VCC" H 3267 1123 50  0000 C CNN
F 2 "" H 3250 950 50  0001 C CNN
F 3 "" H 3250 950 50  0001 C CNN
	1    3250 950 
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C105
U 1 1 5B0C8B79
P 3600 950
AR Path="/5B0C6DCD/5B0C7EFE/5B0C8B79" Ref="C105"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C8B79" Ref="C107"  Part="1" 
F 0 "C105" V 3371 950 50  0000 C CNN
F 1 "0.1uF" V 3462 950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 3600 950 50  0001 C CNN
F 3 "~" H 3600 950 50  0001 C CNN
	1    3600 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	3500 950  3250 950 
Connection ~ 3250 950 
$Comp
L power:GND #PWR0383
U 1 1 5B0C8B82
P 3700 950
AR Path="/5B0C6DCD/5B0C7EFE/5B0C8B82" Ref="#PWR0383"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C8B82" Ref="#PWR0391"  Part="1" 
F 0 "#PWR0383" H 3700 700 50  0001 C CNN
F 1 "GND" V 3705 822 50  0000 R CNN
F 2 "" H 3700 950 50  0001 C CNN
F 3 "" H 3700 950 50  0001 C CNN
	1    3700 950 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0384
U 1 1 5B0C8B8E
P 2750 1850
AR Path="/5B0C6DCD/5B0C7EFE/5B0C8B8E" Ref="#PWR0384"  Part="1" 
AR Path="/5B0C6DCD/5B0CC7A2/5B0C8B8E" Ref="#PWR0392"  Part="1" 
F 0 "#PWR0384" H 2750 1600 50  0001 C CNN
F 1 "GND" V 2755 1722 50  0000 R CNN
F 2 "" H 2750 1850 50  0001 C CNN
F 3 "" H 2750 1850 50  0001 C CNN
	1    2750 1850
	0    1    1    0   
$EndComp
Text HLabel 2750 1250 0    50   Input ~ 0
S0
Text HLabel 2750 1350 0    50   Input ~ 0
S1
Text HLabel 2750 1450 0    50   Input ~ 0
S2
Text HLabel 2750 1550 0    50   Input ~ 0
S3
Text HLabel 3750 1250 2    50   Input ~ 0
O16
Text HLabel 3750 1350 2    50   Input ~ 0
O17
Text HLabel 3750 1450 2    50   Input ~ 0
O18
Text HLabel 3750 1550 2    50   Input ~ 0
O19
Text HLabel 3750 1650 2    50   Input ~ 0
O20
Text HLabel 3750 1750 2    50   Input ~ 0
O21
Text HLabel 3750 1850 2    50   Input ~ 0
O22
Text HLabel 3750 1950 2    50   Input ~ 0
O23
Text HLabel 3750 2050 2    50   Input ~ 0
O24
Text HLabel 3750 2150 2    50   Input ~ 0
O25
Text HLabel 3750 2250 2    50   Input ~ 0
O26
Text HLabel 3750 2350 2    50   Input ~ 0
O27
Text HLabel 3750 2450 2    50   Input ~ 0
O28
Text HLabel 3750 2550 2    50   Input ~ 0
O29
Text HLabel 3750 2650 2    50   Input ~ 0
O30
Text HLabel 3750 2750 2    50   Input ~ 0
O31
Text HLabel 1050 1750 0    50   Input ~ 0
S4
Text HLabel 2750 1750 0    50   Input ~ 0
~S4
$EndSCHEMATC
