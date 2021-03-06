EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 35 35
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
L power:VCC #PWR0161
U 1 1 5B0A5BCB
P 2250 950
AR Path="/5B0B7FE8/5B0A5BCB" Ref="#PWR0161"  Part="1" 
AR Path="/5B0B7FFA/5B0A5BCB" Ref="#PWR0246"  Part="1" 
F 0 "#PWR0246" H 2250 800 50  0001 C CNN
F 1 "VCC" H 2267 1123 50  0000 C CNN
F 2 "" H 2250 950 50  0001 C CNN
F 3 "" H 2250 950 50  0001 C CNN
	1    2250 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0214
U 1 1 5B0A5C12
P 2250 2450
AR Path="/5B0B7FE8/5B0A5C12" Ref="#PWR0214"  Part="1" 
AR Path="/5B0B7FFA/5B0A5C12" Ref="#PWR0247"  Part="1" 
F 0 "#PWR0247" H 2250 2200 50  0001 C CNN
F 1 "GND" H 2255 2277 50  0000 C CNN
F 2 "" H 2250 2450 50  0001 C CNN
F 3 "" H 2250 2450 50  0001 C CNN
	1    2250 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C56
U 1 1 5B0A5C60
P 2500 950
AR Path="/5B0B7FE8/5B0A5C60" Ref="C56"  Part="1" 
AR Path="/5B0B7FFA/5B0A5C60" Ref="C66"  Part="1" 
F 0 "C66" V 2271 950 50  0000 C CNN
F 1 "0.1uF" V 2362 950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2500 950 50  0001 C CNN
F 3 "~" H 2500 950 50  0001 C CNN
	1    2500 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 950  2250 950 
Connection ~ 2250 950 
$Comp
L power:GND #PWR0215
U 1 1 5B0A5CAC
P 2600 950
AR Path="/5B0B7FE8/5B0A5CAC" Ref="#PWR0215"  Part="1" 
AR Path="/5B0B7FFA/5B0A5CAC" Ref="#PWR0248"  Part="1" 
F 0 "#PWR0248" H 2600 700 50  0001 C CNN
F 1 "GND" V 2605 822 50  0000 R CNN
F 2 "" H 2600 950 50  0001 C CNN
F 3 "" H 2600 950 50  0001 C CNN
	1    2600 950 
	0    -1   -1   0   
$EndComp
Text HLabel 1750 1750 0    50   Input ~ 0
~R0_IN
$Comp
L power:VCC #PWR0216
U 1 1 5B0AABF2
P 3950 950
AR Path="/5B0B7FE8/5B0AABF2" Ref="#PWR0216"  Part="1" 
AR Path="/5B0B7FFA/5B0AABF2" Ref="#PWR0249"  Part="1" 
F 0 "#PWR0249" H 3950 800 50  0001 C CNN
F 1 "VCC" H 3967 1123 50  0000 C CNN
F 2 "" H 3950 950 50  0001 C CNN
F 3 "" H 3950 950 50  0001 C CNN
	1    3950 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0217
U 1 1 5B0AABF8
P 3950 2450
AR Path="/5B0B7FE8/5B0AABF8" Ref="#PWR0217"  Part="1" 
AR Path="/5B0B7FFA/5B0AABF8" Ref="#PWR0250"  Part="1" 
F 0 "#PWR0250" H 3950 2200 50  0001 C CNN
F 1 "GND" H 3955 2277 50  0000 C CNN
F 2 "" H 3950 2450 50  0001 C CNN
F 3 "" H 3950 2450 50  0001 C CNN
	1    3950 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C59
U 1 1 5B0AABFE
P 4200 950
AR Path="/5B0B7FE8/5B0AABFE" Ref="C59"  Part="1" 
AR Path="/5B0B7FFA/5B0AABFE" Ref="C69"  Part="1" 
F 0 "C69" V 3971 950 50  0000 C CNN
F 1 "0.1uF" V 4062 950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4200 950 50  0001 C CNN
F 3 "~" H 4200 950 50  0001 C CNN
	1    4200 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	4100 950  3950 950 
$Comp
L power:GND #PWR0218
U 1 1 5B0AAC07
P 4300 950
AR Path="/5B0B7FE8/5B0AAC07" Ref="#PWR0218"  Part="1" 
AR Path="/5B0B7FFA/5B0AAC07" Ref="#PWR0251"  Part="1" 
F 0 "#PWR0251" H 4300 700 50  0001 C CNN
F 1 "GND" V 4305 822 50  0000 R CNN
F 2 "" H 4300 950 50  0001 C CNN
F 3 "" H 4300 950 50  0001 C CNN
	1    4300 950 
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0219
U 1 1 5B0AACD1
P 2250 3150
AR Path="/5B0B7FE8/5B0AACD1" Ref="#PWR0219"  Part="1" 
AR Path="/5B0B7FFA/5B0AACD1" Ref="#PWR0252"  Part="1" 
F 0 "#PWR0252" H 2250 3000 50  0001 C CNN
F 1 "VCC" H 2267 3323 50  0000 C CNN
F 2 "" H 2250 3150 50  0001 C CNN
F 3 "" H 2250 3150 50  0001 C CNN
	1    2250 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0220
U 1 1 5B0AACD7
P 2250 4650
AR Path="/5B0B7FE8/5B0AACD7" Ref="#PWR0220"  Part="1" 
AR Path="/5B0B7FFA/5B0AACD7" Ref="#PWR0253"  Part="1" 
F 0 "#PWR0253" H 2250 4400 50  0001 C CNN
F 1 "GND" H 2255 4477 50  0000 C CNN
F 2 "" H 2250 4650 50  0001 C CNN
F 3 "" H 2250 4650 50  0001 C CNN
	1    2250 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C57
U 1 1 5B0AACDD
P 2500 3150
AR Path="/5B0B7FE8/5B0AACDD" Ref="C57"  Part="1" 
AR Path="/5B0B7FFA/5B0AACDD" Ref="C67"  Part="1" 
F 0 "C67" V 2271 3150 50  0000 C CNN
F 1 "0.1uF" V 2362 3150 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2500 3150 50  0001 C CNN
F 3 "~" H 2500 3150 50  0001 C CNN
	1    2500 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 3150 2250 3150
$Comp
L power:GND #PWR0221
U 1 1 5B0AACE6
P 2600 3150
AR Path="/5B0B7FE8/5B0AACE6" Ref="#PWR0221"  Part="1" 
AR Path="/5B0B7FFA/5B0AACE6" Ref="#PWR0254"  Part="1" 
F 0 "#PWR0254" H 2600 2900 50  0001 C CNN
F 1 "GND" V 2605 3022 50  0000 R CNN
F 2 "" H 2600 3150 50  0001 C CNN
F 3 "" H 2600 3150 50  0001 C CNN
	1    2600 3150
	0    -1   -1   0   
$EndComp
Text HLabel 3450 6150 0    50   Input ~ 0
~R2_IN
$Comp
L power:VCC #PWR0222
U 1 1 5B0AACF7
P 6100 5100
AR Path="/5B0B7FE8/5B0AACF7" Ref="#PWR0222"  Part="1" 
AR Path="/5B0B7FFA/5B0AACF7" Ref="#PWR0255"  Part="1" 
F 0 "#PWR0255" H 6100 4950 50  0001 C CNN
F 1 "VCC" H 6117 5273 50  0000 C CNN
F 2 "" H 6100 5100 50  0001 C CNN
F 3 "" H 6100 5100 50  0001 C CNN
	1    6100 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0223
U 1 1 5B0AACFD
P 3950 4650
AR Path="/5B0B7FE8/5B0AACFD" Ref="#PWR0223"  Part="1" 
AR Path="/5B0B7FFA/5B0AACFD" Ref="#PWR0256"  Part="1" 
F 0 "#PWR0256" H 3950 4400 50  0001 C CNN
F 1 "GND" H 3955 4477 50  0000 C CNN
F 2 "" H 3950 4650 50  0001 C CNN
F 3 "" H 3950 4650 50  0001 C CNN
	1    3950 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C61
U 1 1 5B0AAD03
P 6350 5100
AR Path="/5B0B7FE8/5B0AAD03" Ref="C61"  Part="1" 
AR Path="/5B0B7FFA/5B0AAD03" Ref="C71"  Part="1" 
F 0 "C71" V 6121 5100 50  0000 C CNN
F 1 "0.1uF" V 6212 5100 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 6350 5100 50  0001 C CNN
F 3 "~" H 6350 5100 50  0001 C CNN
	1    6350 5100
	0    1    1    0   
$EndComp
Wire Wire Line
	4100 3150 3950 3150
$Comp
L power:GND #PWR0224
U 1 1 5B0AAD0C
P 6450 5100
AR Path="/5B0B7FE8/5B0AAD0C" Ref="#PWR0224"  Part="1" 
AR Path="/5B0B7FFA/5B0AAD0C" Ref="#PWR0257"  Part="1" 
F 0 "#PWR0257" H 6450 4850 50  0001 C CNN
F 1 "GND" V 6455 4972 50  0000 R CNN
F 2 "" H 6450 5100 50  0001 C CNN
F 3 "" H 6450 5100 50  0001 C CNN
	1    6450 5100
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0225
U 1 1 5B0AAE22
P 2250 5350
AR Path="/5B0B7FE8/5B0AAE22" Ref="#PWR0225"  Part="1" 
AR Path="/5B0B7FFA/5B0AAE22" Ref="#PWR0258"  Part="1" 
F 0 "#PWR0258" H 2250 5200 50  0001 C CNN
F 1 "VCC" H 2267 5523 50  0000 C CNN
F 2 "" H 2250 5350 50  0001 C CNN
F 3 "" H 2250 5350 50  0001 C CNN
	1    2250 5350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0226
U 1 1 5B0AAE28
P 2250 6850
AR Path="/5B0B7FE8/5B0AAE28" Ref="#PWR0226"  Part="1" 
AR Path="/5B0B7FFA/5B0AAE28" Ref="#PWR0259"  Part="1" 
F 0 "#PWR0259" H 2250 6600 50  0001 C CNN
F 1 "GND" H 2255 6677 50  0000 C CNN
F 2 "" H 2250 6850 50  0001 C CNN
F 3 "" H 2250 6850 50  0001 C CNN
	1    2250 6850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C58
U 1 1 5B0AAE2E
P 2500 5350
AR Path="/5B0B7FE8/5B0AAE2E" Ref="C58"  Part="1" 
AR Path="/5B0B7FFA/5B0AAE2E" Ref="C68"  Part="1" 
F 0 "C68" V 2271 5350 50  0000 C CNN
F 1 "0.1uF" V 2362 5350 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2500 5350 50  0001 C CNN
F 3 "~" H 2500 5350 50  0001 C CNN
	1    2500 5350
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 5350 2250 5350
$Comp
L power:GND #PWR0227
U 1 1 5B0AAE37
P 2600 5350
AR Path="/5B0B7FE8/5B0AAE37" Ref="#PWR0227"  Part="1" 
AR Path="/5B0B7FFA/5B0AAE37" Ref="#PWR0260"  Part="1" 
F 0 "#PWR0260" H 2600 5100 50  0001 C CNN
F 1 "GND" V 2605 5222 50  0000 R CNN
F 2 "" H 2600 5350 50  0001 C CNN
F 3 "" H 2600 5350 50  0001 C CNN
	1    2600 5350
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0228
U 1 1 5B0AAE48
P 3950 5350
AR Path="/5B0B7FE8/5B0AAE48" Ref="#PWR0228"  Part="1" 
AR Path="/5B0B7FFA/5B0AAE48" Ref="#PWR0261"  Part="1" 
F 0 "#PWR0261" H 3950 5200 50  0001 C CNN
F 1 "VCC" H 3967 5523 50  0000 C CNN
F 2 "" H 3950 5350 50  0001 C CNN
F 3 "" H 3950 5350 50  0001 C CNN
	1    3950 5350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0229
U 1 1 5B0AAE4E
P 3950 6850
AR Path="/5B0B7FE8/5B0AAE4E" Ref="#PWR0229"  Part="1" 
AR Path="/5B0B7FFA/5B0AAE4E" Ref="#PWR0262"  Part="1" 
F 0 "#PWR0262" H 3950 6600 50  0001 C CNN
F 1 "GND" H 3955 6677 50  0000 C CNN
F 2 "" H 3950 6850 50  0001 C CNN
F 3 "" H 3950 6850 50  0001 C CNN
	1    3950 6850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C60
U 1 1 5B0AAE54
P 4200 5350
AR Path="/5B0B7FE8/5B0AAE54" Ref="C60"  Part="1" 
AR Path="/5B0B7FFA/5B0AAE54" Ref="C70"  Part="1" 
F 0 "C70" V 3971 5350 50  0000 C CNN
F 1 "0.1uF" V 4062 5350 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4200 5350 50  0001 C CNN
F 3 "~" H 4200 5350 50  0001 C CNN
	1    4200 5350
	0    1    1    0   
$EndComp
Wire Wire Line
	4100 5350 3950 5350
$Comp
L power:GND #PWR0230
U 1 1 5B0AAE5D
P 4300 5350
AR Path="/5B0B7FE8/5B0AAE5D" Ref="#PWR0230"  Part="1" 
AR Path="/5B0B7FFA/5B0AAE5D" Ref="#PWR0263"  Part="1" 
F 0 "#PWR0263" H 4300 5100 50  0001 C CNN
F 1 "GND" V 4305 5222 50  0000 R CNN
F 2 "" H 4300 5350 50  0001 C CNN
F 3 "" H 4300 5350 50  0001 C CNN
	1    4300 5350
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74LS191 U?
U 1 1 5B0AB442
P 2250 1650
AR Path="/5B0A5A56/5B0A5A5D/5B0AB442" Ref="U?"  Part="1" 
AR Path="/5B0B7FE8/5B0AB442" Ref="U48"  Part="1" 
AR Path="/5B0B7FFA/5B0AB442" Ref="U59"  Part="1" 
F 0 "U59" H 2250 1600 50  0000 C CNN
F 1 "74LS191" H 2250 1350 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 2250 1650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS191" H 2250 1650 50  0001 C CNN
	1    2250 1650
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS191 U?
U 1 1 5B0ABA15
P 3950 1650
AR Path="/5B0A5A56/5B0A5A5D/5B0ABA15" Ref="U?"  Part="1" 
AR Path="/5B0B7FE8/5B0ABA15" Ref="U51"  Part="1" 
AR Path="/5B0B7FFA/5B0ABA15" Ref="U62"  Part="1" 
F 0 "U62" H 3950 1600 50  0000 C CNN
F 1 "74LS191" H 3950 1350 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 3950 1650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS191" H 3950 1650 50  0001 C CNN
	1    3950 1650
	1    0    0    -1  
$EndComp
Connection ~ 3950 950 
$Comp
L 74xx:74LS191 U?
U 1 1 5B0ABA61
P 3950 3850
AR Path="/5B0A5A56/5B0A5A5D/5B0ABA61" Ref="U?"  Part="1" 
AR Path="/5B0B7FE8/5B0ABA61" Ref="U52"  Part="1" 
AR Path="/5B0B7FFA/5B0ABA61" Ref="U63"  Part="1" 
F 0 "U63" H 3950 3800 50  0000 C CNN
F 1 "74LS191" H 3950 3550 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 3950 3850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS191" H 3950 3850 50  0001 C CNN
	1    3950 3850
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS191 U?
U 1 1 5B0ABAA3
P 2250 3850
AR Path="/5B0A5A56/5B0A5A5D/5B0ABAA3" Ref="U?"  Part="1" 
AR Path="/5B0B7FE8/5B0ABAA3" Ref="U49"  Part="1" 
AR Path="/5B0B7FFA/5B0ABAA3" Ref="U60"  Part="1" 
F 0 "U60" H 2250 3800 50  0000 C CNN
F 1 "74LS191" H 2250 3550 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 2250 3850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS191" H 2250 3850 50  0001 C CNN
	1    2250 3850
	1    0    0    -1  
$EndComp
Connection ~ 2250 3150
$Comp
L 74xx:74LS191 U?
U 1 1 5B0ABBA3
P 2250 6050
AR Path="/5B0A5A56/5B0A5A5D/5B0ABBA3" Ref="U?"  Part="1" 
AR Path="/5B0B7FE8/5B0ABBA3" Ref="U50"  Part="1" 
AR Path="/5B0B7FFA/5B0ABBA3" Ref="U61"  Part="1" 
F 0 "U61" H 2250 6000 50  0000 C CNN
F 1 "74LS191" H 2250 5750 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 2250 6050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS191" H 2250 6050 50  0001 C CNN
	1    2250 6050
	1    0    0    -1  
$EndComp
Connection ~ 2250 5350
$Comp
L 74xx:74LS191 U?
U 1 1 5B0ABBFD
P 3950 6050
AR Path="/5B0A5A56/5B0A5A5D/5B0ABBFD" Ref="U?"  Part="1" 
AR Path="/5B0B7FE8/5B0ABBFD" Ref="U53"  Part="1" 
AR Path="/5B0B7FFA/5B0ABBFD" Ref="U64"  Part="1" 
F 0 "U64" H 3950 6000 50  0000 C CNN
F 1 "74LS191" H 3950 5750 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 3950 6050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS191" H 3950 6050 50  0001 C CNN
	1    3950 6050
	1    0    0    -1  
$EndComp
Connection ~ 3950 5350
Text HLabel 1750 1250 0    50   Input ~ 0
BUS0
Text HLabel 1750 1350 0    50   Input ~ 0
BUS1
Text HLabel 1750 1450 0    50   Input ~ 0
BUS2
Text HLabel 1750 1550 0    50   Input ~ 0
BUS3
Text HLabel 3450 1250 0    50   Input ~ 0
BUS4
Text HLabel 3450 1350 0    50   Input ~ 0
BUS5
Text HLabel 3450 1450 0    50   Input ~ 0
BUS6
Text HLabel 3450 1550 0    50   Input ~ 0
BUS7
Text HLabel 1750 3450 0    50   Input ~ 0
BUS0
Text HLabel 1750 3550 0    50   Input ~ 0
BUS1
Text HLabel 1750 3650 0    50   Input ~ 0
BUS2
Text HLabel 1750 3750 0    50   Input ~ 0
BUS3
Text HLabel 1750 5650 0    50   Input ~ 0
BUS0
Text HLabel 1750 5750 0    50   Input ~ 0
BUS1
Text HLabel 1750 5850 0    50   Input ~ 0
BUS2
Text HLabel 1750 5950 0    50   Input ~ 0
BUS3
Text HLabel 3450 3450 0    50   Input ~ 0
BUS4
Text HLabel 3450 3550 0    50   Input ~ 0
BUS5
Text HLabel 3450 3650 0    50   Input ~ 0
BUS6
Text HLabel 3450 3750 0    50   Input ~ 0
BUS7
Text HLabel 3450 5650 0    50   Input ~ 0
BUS4
Text HLabel 3450 5750 0    50   Input ~ 0
BUS5
Text HLabel 3450 5850 0    50   Input ~ 0
BUS6
Text HLabel 3450 5950 0    50   Input ~ 0
BUS7
Text HLabel 1750 1850 0    50   Input ~ 0
~UP
Text HLabel 3450 1850 0    50   Input ~ 0
~UP
Text HLabel 1750 4050 0    50   Input ~ 0
~UP
Text HLabel 3450 4050 0    50   Input ~ 0
~UP
Text HLabel 1750 6250 0    50   Input ~ 0
~UP
Text HLabel 3450 6250 0    50   Input ~ 0
~UP
Text HLabel 1750 2150 0    50   Input ~ 0
CLK
Text HLabel 3450 2150 0    50   Input ~ 0
CLK
Text HLabel 3450 4350 0    50   Input ~ 0
CLK
Text HLabel 1750 4350 0    50   Input ~ 0
CLK
Text HLabel 1750 6550 0    50   Input ~ 0
CLK
Text HLabel 3450 6550 0    50   Input ~ 0
CLK
Text Label 2750 1950 0    50   ~ 0
CARRY0
NoConn ~ 2750 1750
NoConn ~ 4450 1750
NoConn ~ 4450 3950
NoConn ~ 2750 3950
NoConn ~ 4450 6150
NoConn ~ 2750 6150
$Comp
L Device:C_Small C63
U 1 1 5B0ADD55
P 7950 1500
AR Path="/5B0B7FE8/5B0ADD55" Ref="C63"  Part="1" 
AR Path="/5B0B7FFA/5B0ADD55" Ref="C73"  Part="1" 
F 0 "C73" H 7858 1454 50  0000 R CNN
F 1 "0.1uF" H 7858 1545 50  0000 R CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 7950 1500 50  0001 C CNN
F 3 "~" H 7950 1500 50  0001 C CNN
	1    7950 1500
	-1   0    0    1   
$EndComp
Wire Wire Line
	7300 1000 7950 1000
Wire Wire Line
	7950 1000 7950 1400
Wire Wire Line
	7950 1600 7950 2000
Wire Wire Line
	7950 2000 7300 2000
$Comp
L power:VCC #PWR0232
U 1 1 5B0ADEA2
P 7300 1000
AR Path="/5B0B7FE8/5B0ADEA2" Ref="#PWR0232"  Part="1" 
AR Path="/5B0B7FFA/5B0ADEA2" Ref="#PWR0265"  Part="1" 
F 0 "#PWR0265" H 7300 850 50  0001 C CNN
F 1 "VCC" H 7317 1173 50  0000 C CNN
F 2 "" H 7300 1000 50  0001 C CNN
F 3 "" H 7300 1000 50  0001 C CNN
	1    7300 1000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0233
U 1 1 5B0ADED1
P 7300 2000
AR Path="/5B0B7FE8/5B0ADED1" Ref="#PWR0233"  Part="1" 
AR Path="/5B0B7FFA/5B0ADED1" Ref="#PWR0266"  Part="1" 
F 0 "#PWR0266" H 7300 1750 50  0001 C CNN
F 1 "GND" H 7305 1827 50  0000 C CNN
F 2 "" H 7300 2000 50  0001 C CNN
F 3 "" H 7300 2000 50  0001 C CNN
	1    7300 2000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS08 U?
U 1 1 5B0AEA35
P 5500 1950
AR Path="/5B0A5A56/5B0A5A5D/5B0AEA35" Ref="U?"  Part="1" 
AR Path="/5B0B7FE8/5B0AEA35" Ref="U54"  Part="1" 
AR Path="/5B0B7FFA/5B0AEA35" Ref="U65"  Part="1" 
F 0 "U65" H 5500 2275 50  0000 C CNN
F 1 "74LS08" H 5500 2184 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5500 1950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 5500 1950 50  0001 C CNN
	1    5500 1950
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS08 U?
U 2 1 5B0AEB66
P 5450 2700
AR Path="/5B0A5A56/5B0A5A5D/5B0AEB66" Ref="U?"  Part="2" 
AR Path="/5B0B7FE8/5B0AEB66" Ref="U54"  Part="2" 
AR Path="/5B0B7FFA/5B0AEB66" Ref="U65"  Part="2" 
F 0 "U65" H 5450 3025 50  0000 C CNN
F 1 "74LS08" H 5450 2934 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5450 2700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 5450 2700 50  0001 C CNN
	2    5450 2700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS08 U?
U 3 1 5B0AEBB7
P 5450 3400
AR Path="/5B0A5A56/5B0A5A5D/5B0AEBB7" Ref="U?"  Part="3" 
AR Path="/5B0B7FE8/5B0AEBB7" Ref="U54"  Part="3" 
AR Path="/5B0B7FFA/5B0AEBB7" Ref="U65"  Part="3" 
F 0 "U65" H 5450 3725 50  0000 C CNN
F 1 "74LS08" H 5450 3634 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5450 3400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 5450 3400 50  0001 C CNN
	3    5450 3400
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS08 U?
U 4 1 5B0AEC1C
P 5450 4150
AR Path="/5B0A5A56/5B0A5A5D/5B0AEC1C" Ref="U?"  Part="4" 
AR Path="/5B0B7FE8/5B0AEC1C" Ref="U54"  Part="4" 
AR Path="/5B0B7FFA/5B0AEC1C" Ref="U65"  Part="4" 
F 0 "U65" H 5450 4475 50  0000 C CNN
F 1 "74LS08" H 5450 4384 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5450 4150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 5450 4150 50  0001 C CNN
	4    5450 4150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS08 U?
U 5 1 5B0AEC7D
P 7300 1500
AR Path="/5B0A5A56/5B0A5A5D/5B0AEC7D" Ref="U?"  Part="5" 
AR Path="/5B0B7FE8/5B0AEC7D" Ref="U54"  Part="5" 
AR Path="/5B0B7FFA/5B0AEC7D" Ref="U65"  Part="5" 
F 0 "U65" H 7530 1546 50  0000 L CNN
F 1 "74LS08" H 7530 1455 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7300 1500 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 7300 1500 50  0001 C CNN
	5    7300 1500
	1    0    0    -1  
$EndComp
Connection ~ 7300 1000
Connection ~ 7300 2000
$Comp
L Device:C_Small C65
U 1 1 5B0AF3D4
P 9350 1500
AR Path="/5B0B7FE8/5B0AF3D4" Ref="C65"  Part="1" 
AR Path="/5B0B7FFA/5B0AF3D4" Ref="C75"  Part="1" 
F 0 "C75" H 9258 1454 50  0000 R CNN
F 1 "0.1uF" H 9258 1545 50  0000 R CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 9350 1500 50  0001 C CNN
F 3 "~" H 9350 1500 50  0001 C CNN
	1    9350 1500
	-1   0    0    1   
$EndComp
Wire Wire Line
	8700 1000 9350 1000
Wire Wire Line
	9350 1000 9350 1400
Wire Wire Line
	9350 1600 9350 2000
Wire Wire Line
	9350 2000 8700 2000
$Comp
L power:VCC #PWR0234
U 1 1 5B0AF3DF
P 8700 1000
AR Path="/5B0B7FE8/5B0AF3DF" Ref="#PWR0234"  Part="1" 
AR Path="/5B0B7FFA/5B0AF3DF" Ref="#PWR0267"  Part="1" 
F 0 "#PWR0267" H 8700 850 50  0001 C CNN
F 1 "VCC" H 8717 1173 50  0000 C CNN
F 2 "" H 8700 1000 50  0001 C CNN
F 3 "" H 8700 1000 50  0001 C CNN
	1    8700 1000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0235
U 1 1 5B0AF3E5
P 8700 2000
AR Path="/5B0B7FE8/5B0AF3E5" Ref="#PWR0235"  Part="1" 
AR Path="/5B0B7FFA/5B0AF3E5" Ref="#PWR0268"  Part="1" 
F 0 "#PWR0268" H 8700 1750 50  0001 C CNN
F 1 "GND" H 8705 1827 50  0000 C CNN
F 2 "" H 8700 2000 50  0001 C CNN
F 3 "" H 8700 2000 50  0001 C CNN
	1    8700 2000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 1 1 5B0AF548
P 5500 1250
AR Path="/5B0A5A56/5B0A5A5D/5B0AF548" Ref="U?"  Part="1" 
AR Path="/5B0B7FE8/5B0AF548" Ref="U55"  Part="1" 
AR Path="/5B0B7FFA/5B0AF548" Ref="U66"  Part="1" 
F 0 "U66" H 5500 1567 50  0000 C CNN
F 1 "74HC04" H 5500 1476 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5500 1250 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 5500 1250 50  0001 C CNN
	1    5500 1250
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 2 1 5B0AF619
P 6100 1950
AR Path="/5B0A5A56/5B0A5A5D/5B0AF619" Ref="U?"  Part="2" 
AR Path="/5B0B7FE8/5B0AF619" Ref="U55"  Part="2" 
AR Path="/5B0B7FFA/5B0AF619" Ref="U66"  Part="2" 
F 0 "U66" H 6100 2267 50  0000 C CNN
F 1 "74HC04" H 6100 2176 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 6100 1950 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 6100 1950 50  0001 C CNN
	2    6100 1950
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 3 1 5B0AF68E
P 6050 2700
AR Path="/5B0A5A56/5B0A5A5D/5B0AF68E" Ref="U?"  Part="3" 
AR Path="/5B0B7FE8/5B0AF68E" Ref="U55"  Part="3" 
AR Path="/5B0B7FFA/5B0AF68E" Ref="U66"  Part="3" 
F 0 "U66" H 6050 3017 50  0000 C CNN
F 1 "74HC04" H 6050 2926 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 6050 2700 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 6050 2700 50  0001 C CNN
	3    6050 2700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 4 1 5B0AF6FF
P 6050 3400
AR Path="/5B0A5A56/5B0A5A5D/5B0AF6FF" Ref="U?"  Part="4" 
AR Path="/5B0B7FE8/5B0AF6FF" Ref="U55"  Part="4" 
AR Path="/5B0B7FFA/5B0AF6FF" Ref="U66"  Part="4" 
F 0 "U66" H 6050 3717 50  0000 C CNN
F 1 "74HC04" H 6050 3626 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 6050 3400 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 6050 3400 50  0001 C CNN
	4    6050 3400
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 5 1 5B0AF76C
P 6050 4150
AR Path="/5B0A5A56/5B0A5A5D/5B0AF76C" Ref="U?"  Part="5" 
AR Path="/5B0B7FE8/5B0AF76C" Ref="U55"  Part="5" 
AR Path="/5B0B7FFA/5B0AF76C" Ref="U66"  Part="5" 
F 0 "U66" H 6050 4467 50  0000 C CNN
F 1 "74HC04" H 6050 4376 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 6050 4150 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 6050 4150 50  0001 C CNN
	5    6050 4150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 6 1 5B0AF7CD
P 7500 3050
AR Path="/5B0A5A56/5B0A5A5D/5B0AF7CD" Ref="U?"  Part="6" 
AR Path="/5B0B7FE8/5B0AF7CD" Ref="U55"  Part="6" 
AR Path="/5B0B7FFA/5B0AF7CD" Ref="U66"  Part="6" 
F 0 "U66" H 7500 3367 50  0000 C CNN
F 1 "74HC04" H 7500 3276 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7500 3050 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 7500 3050 50  0001 C CNN
	6    7500 3050
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 7 1 5B0AF830
P 8700 1500
AR Path="/5B0A5A56/5B0A5A5D/5B0AF830" Ref="U?"  Part="7" 
AR Path="/5B0B7FE8/5B0AF830" Ref="U55"  Part="7" 
AR Path="/5B0B7FFA/5B0AF830" Ref="U66"  Part="7" 
F 0 "U66" H 8930 1546 50  0000 L CNN
F 1 "74HC04" H 8930 1455 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 8700 1500 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 8700 1500 50  0001 C CNN
	7    8700 1500
	1    0    0    -1  
$EndComp
Connection ~ 8700 1000
Connection ~ 8700 2000
Text Label 4450 1950 0    50   ~ 0
CARRY1
Text Label 2750 4150 0    50   ~ 0
CARRY2
Text Label 4450 4150 0    50   ~ 0
CARRY3
Text Label 2750 6350 0    50   ~ 0
CARRY4
NoConn ~ 4450 6350
Text Label 5200 1250 2    50   ~ 0
CARRY0
Text Label 3450 2050 2    50   ~ 0
~ENABLE1
Text Label 1750 4250 2    50   ~ 0
~ENABLE2
Text Label 3450 4250 2    50   ~ 0
~ENABLE3
Text Label 1750 6450 2    50   ~ 0
~ENABLE4
Text Label 3450 6450 2    50   ~ 0
~ENABLE5
Text Label 5800 1250 0    50   ~ 0
~ENABLE1
Text Label 5200 1850 2    50   ~ 0
CARRY0
Text Label 5200 2050 2    50   ~ 0
CARRY1
Text Label 6400 1950 0    50   ~ 0
~ENABLE2
Wire Wire Line
	5800 1950 5800 2250
Wire Wire Line
	5800 2250 5150 2250
Wire Wire Line
	5150 2250 5150 2600
Connection ~ 5800 1950
Wire Wire Line
	5750 2700 5750 3000
Wire Wire Line
	5750 3000 5150 3000
Wire Wire Line
	5150 3000 5150 3300
Connection ~ 5750 2700
Wire Wire Line
	5750 3400 5750 3700
Wire Wire Line
	5750 3700 5150 3700
Wire Wire Line
	5150 3700 5150 4050
Connection ~ 5750 3400
Wire Notes Line
	7000 2400 7000 3400
Wire Notes Line
	7000 3400 7950 3400
Wire Notes Line
	7950 3400 7950 2400
Wire Notes Line
	7950 2400 7000 2400
Text Notes 7300 2600 0    50   ~ 0
Spare
Text Label 6350 2700 0    50   ~ 0
~ENABLE3
Text Label 6350 3400 0    50   ~ 0
~ENABLE4
Text Label 6350 4150 0    50   ~ 0
~ENABLE5
Text Label 5150 2800 2    50   ~ 0
CARRY2
Text Label 5150 3500 2    50   ~ 0
CARRY3
Text Label 5150 4250 2    50   ~ 0
CARRY4
$Comp
L 74xx:74HC245 U?
U 1 1 5B0B3075
P 6100 5900
AR Path="/5B0A5A56/5B0A5A5D/5B0B3075" Ref="U?"  Part="1" 
AR Path="/5B0B7FE8/5B0B3075" Ref="U56"  Part="1" 
AR Path="/5B0B7FFA/5B0B3075" Ref="U67"  Part="1" 
F 0 "U67" H 6100 5750 50  0000 C CNN
F 1 "74HC245" H 6150 5600 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 6100 5900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 6100 5900 50  0001 C CNN
	1    6100 5900
	1    0    0    -1  
$EndComp
Text Label 2750 1250 0    50   ~ 0
O0
Text Label 2750 1350 0    50   ~ 0
O1
Text Label 2750 1450 0    50   ~ 0
O2
Text Label 2750 1550 0    50   ~ 0
O3
Text Label 4450 1250 0    50   ~ 0
O4
Text Label 4450 1350 0    50   ~ 0
O5
Text Label 4450 1450 0    50   ~ 0
O6
Text Label 4450 1550 0    50   ~ 0
O7
Text Label 2750 3450 0    50   ~ 0
O8
Text Label 2750 3550 0    50   ~ 0
O9
Text Label 2750 3650 0    50   ~ 0
O10
Text Label 2750 3750 0    50   ~ 0
O11
Text Label 4450 3450 0    50   ~ 0
O12
Text Label 4450 3550 0    50   ~ 0
O13
Text Label 4450 3650 0    50   ~ 0
O14
Text Label 4450 3750 0    50   ~ 0
O15
Text Label 2750 5650 0    50   ~ 0
O16
Text Label 2750 5750 0    50   ~ 0
O17
Text Label 2750 5850 0    50   ~ 0
O18
Text Label 2750 5950 0    50   ~ 0
O19
Text Label 4450 5650 0    50   ~ 0
O20
Text Label 4450 5750 0    50   ~ 0
O21
Text Label 4450 5850 0    50   ~ 0
O22
Text Label 4450 5950 0    50   ~ 0
O23
Wire Wire Line
	6250 5100 6100 5100
Connection ~ 6100 5100
$Comp
L power:GND #PWR0236
U 1 1 5B0B40D4
P 6100 6700
AR Path="/5B0B7FE8/5B0B40D4" Ref="#PWR0236"  Part="1" 
AR Path="/5B0B7FFA/5B0B40D4" Ref="#PWR0269"  Part="1" 
F 0 "#PWR0269" H 6100 6450 50  0001 C CNN
F 1 "GND" H 6105 6527 50  0000 C CNN
F 2 "" H 6100 6700 50  0001 C CNN
F 3 "" H 6100 6700 50  0001 C CNN
	1    6100 6700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0237
U 1 1 5B0B418C
P 5600 6300
AR Path="/5B0B7FE8/5B0B418C" Ref="#PWR0237"  Part="1" 
AR Path="/5B0B7FFA/5B0B418C" Ref="#PWR0270"  Part="1" 
F 0 "#PWR0270" H 5600 6150 50  0001 C CNN
F 1 "VCC" V 5618 6427 50  0000 L CNN
F 2 "" H 5600 6300 50  0001 C CNN
F 3 "" H 5600 6300 50  0001 C CNN
	1    5600 6300
	0    -1   -1   0   
$EndComp
Text HLabel 5600 6400 0    50   Input ~ 0
~R0_OUT
$Comp
L power:VCC #PWR0238
U 1 1 5B0B4992
P 7550 5100
AR Path="/5B0B7FE8/5B0B4992" Ref="#PWR0238"  Part="1" 
AR Path="/5B0B7FFA/5B0B4992" Ref="#PWR0271"  Part="1" 
F 0 "#PWR0271" H 7550 4950 50  0001 C CNN
F 1 "VCC" H 7567 5273 50  0000 C CNN
F 2 "" H 7550 5100 50  0001 C CNN
F 3 "" H 7550 5100 50  0001 C CNN
	1    7550 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C62
U 1 1 5B0B4998
P 7800 5100
AR Path="/5B0B7FE8/5B0B4998" Ref="C62"  Part="1" 
AR Path="/5B0B7FFA/5B0B4998" Ref="C72"  Part="1" 
F 0 "C72" V 7571 5100 50  0000 C CNN
F 1 "0.1uF" V 7662 5100 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 7800 5100 50  0001 C CNN
F 3 "~" H 7800 5100 50  0001 C CNN
	1    7800 5100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0239
U 1 1 5B0B499F
P 7900 5100
AR Path="/5B0B7FE8/5B0B499F" Ref="#PWR0239"  Part="1" 
AR Path="/5B0B7FFA/5B0B499F" Ref="#PWR0272"  Part="1" 
F 0 "#PWR0272" H 7900 4850 50  0001 C CNN
F 1 "GND" V 7905 4972 50  0000 R CNN
F 2 "" H 7900 5100 50  0001 C CNN
F 3 "" H 7900 5100 50  0001 C CNN
	1    7900 5100
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74HC245 U?
U 1 1 5B0B49A5
P 7550 5900
AR Path="/5B0A5A56/5B0A5A5D/5B0B49A5" Ref="U?"  Part="1" 
AR Path="/5B0B7FE8/5B0B49A5" Ref="U57"  Part="1" 
AR Path="/5B0B7FFA/5B0B49A5" Ref="U68"  Part="1" 
F 0 "U68" H 7550 5750 50  0000 C CNN
F 1 "74HC245" H 7600 5600 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 7550 5900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 7550 5900 50  0001 C CNN
	1    7550 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 5100 7550 5100
Connection ~ 7550 5100
$Comp
L power:GND #PWR0240
U 1 1 5B0B49AE
P 7550 6700
AR Path="/5B0B7FE8/5B0B49AE" Ref="#PWR0240"  Part="1" 
AR Path="/5B0B7FFA/5B0B49AE" Ref="#PWR0273"  Part="1" 
F 0 "#PWR0273" H 7550 6450 50  0001 C CNN
F 1 "GND" H 7555 6527 50  0000 C CNN
F 2 "" H 7550 6700 50  0001 C CNN
F 3 "" H 7550 6700 50  0001 C CNN
	1    7550 6700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0241
U 1 1 5B0B49B4
P 7050 6300
AR Path="/5B0B7FE8/5B0B49B4" Ref="#PWR0241"  Part="1" 
AR Path="/5B0B7FFA/5B0B49B4" Ref="#PWR0274"  Part="1" 
F 0 "#PWR0274" H 7050 6150 50  0001 C CNN
F 1 "VCC" V 7068 6427 50  0000 L CNN
F 2 "" H 7050 6300 50  0001 C CNN
F 3 "" H 7050 6300 50  0001 C CNN
	1    7050 6300
	0    -1   -1   0   
$EndComp
Text HLabel 7050 6400 0    50   Input ~ 0
~R1_OUT
$Comp
L power:VCC #PWR0242
U 1 1 5B0B4D51
P 9050 5100
AR Path="/5B0B7FE8/5B0B4D51" Ref="#PWR0242"  Part="1" 
AR Path="/5B0B7FFA/5B0B4D51" Ref="#PWR0275"  Part="1" 
F 0 "#PWR0275" H 9050 4950 50  0001 C CNN
F 1 "VCC" H 9067 5273 50  0000 C CNN
F 2 "" H 9050 5100 50  0001 C CNN
F 3 "" H 9050 5100 50  0001 C CNN
	1    9050 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C64
U 1 1 5B0B4D57
P 9300 5100
AR Path="/5B0B7FE8/5B0B4D57" Ref="C64"  Part="1" 
AR Path="/5B0B7FFA/5B0B4D57" Ref="C74"  Part="1" 
F 0 "C74" V 9071 5100 50  0000 C CNN
F 1 "0.1uF" V 9162 5100 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 9300 5100 50  0001 C CNN
F 3 "~" H 9300 5100 50  0001 C CNN
	1    9300 5100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0243
U 1 1 5B0B4D5E
P 9400 5100
AR Path="/5B0B7FE8/5B0B4D5E" Ref="#PWR0243"  Part="1" 
AR Path="/5B0B7FFA/5B0B4D5E" Ref="#PWR0276"  Part="1" 
F 0 "#PWR0276" H 9400 4850 50  0001 C CNN
F 1 "GND" V 9405 4972 50  0000 R CNN
F 2 "" H 9400 5100 50  0001 C CNN
F 3 "" H 9400 5100 50  0001 C CNN
	1    9400 5100
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74HC245 U?
U 1 1 5B0B4D64
P 9050 5900
AR Path="/5B0A5A56/5B0A5A5D/5B0B4D64" Ref="U?"  Part="1" 
AR Path="/5B0B7FE8/5B0B4D64" Ref="U58"  Part="1" 
AR Path="/5B0B7FFA/5B0B4D64" Ref="U69"  Part="1" 
F 0 "U69" H 9050 5750 50  0000 C CNN
F 1 "74HC245" H 9100 5600 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 9050 5900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 9050 5900 50  0001 C CNN
	1    9050 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 5100 9050 5100
Connection ~ 9050 5100
$Comp
L power:GND #PWR0244
U 1 1 5B0B4D6D
P 9050 6700
AR Path="/5B0B7FE8/5B0B4D6D" Ref="#PWR0244"  Part="1" 
AR Path="/5B0B7FFA/5B0B4D6D" Ref="#PWR0277"  Part="1" 
F 0 "#PWR0277" H 9050 6450 50  0001 C CNN
F 1 "GND" H 9055 6527 50  0000 C CNN
F 2 "" H 9050 6700 50  0001 C CNN
F 3 "" H 9050 6700 50  0001 C CNN
	1    9050 6700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0245
U 1 1 5B0B4D73
P 8550 6300
AR Path="/5B0B7FE8/5B0B4D73" Ref="#PWR0245"  Part="1" 
AR Path="/5B0B7FFA/5B0B4D73" Ref="#PWR0278"  Part="1" 
F 0 "#PWR0278" H 8550 6150 50  0001 C CNN
F 1 "VCC" V 8568 6427 50  0000 L CNN
F 2 "" H 8550 6300 50  0001 C CNN
F 3 "" H 8550 6300 50  0001 C CNN
	1    8550 6300
	0    -1   -1   0   
$EndComp
Text HLabel 8550 6400 0    50   Input ~ 0
~R2_OUT
Text Label 5600 5400 2    50   ~ 0
O0
Text Label 5600 5500 2    50   ~ 0
O1
Text Label 5600 5600 2    50   ~ 0
O2
Text Label 5600 5700 2    50   ~ 0
O3
Text Label 5600 5800 2    50   ~ 0
O4
Text Label 5600 5900 2    50   ~ 0
O5
Text Label 5600 6000 2    50   ~ 0
O6
Text Label 5600 6100 2    50   ~ 0
O7
Text Label 7050 5400 2    50   ~ 0
O8
Text Label 7050 5500 2    50   ~ 0
O9
Text Label 7050 5600 2    50   ~ 0
O10
Text Label 7050 5700 2    50   ~ 0
O11
Text Label 7050 5800 2    50   ~ 0
O12
Text Label 7050 5900 2    50   ~ 0
O13
Text Label 7050 6000 2    50   ~ 0
O14
Text Label 7050 6100 2    50   ~ 0
O15
Text Label 8550 5400 2    50   ~ 0
O16
Text Label 8550 5500 2    50   ~ 0
O17
Text Label 8550 5600 2    50   ~ 0
O18
Text Label 8550 5700 2    50   ~ 0
O19
Text Label 8550 5800 2    50   ~ 0
O20
Text Label 8550 5900 2    50   ~ 0
O21
Text Label 8550 6000 2    50   ~ 0
O22
Text Label 8550 6100 2    50   ~ 0
O23
Text HLabel 6600 5400 2    50   Input ~ 0
BUS0
Text HLabel 6600 5500 2    50   Input ~ 0
BUS1
Text HLabel 6600 5600 2    50   Input ~ 0
BUS2
Text HLabel 6600 5700 2    50   Input ~ 0
BUS3
Text HLabel 6600 5800 2    50   Input ~ 0
BUS4
Text HLabel 6600 5900 2    50   Input ~ 0
BUS5
Text HLabel 6600 6000 2    50   Input ~ 0
BUS6
Text HLabel 6600 6100 2    50   Input ~ 0
BUS7
Text HLabel 8050 5400 2    50   Input ~ 0
BUS0
Text HLabel 8050 5500 2    50   Input ~ 0
BUS1
Text HLabel 8050 5600 2    50   Input ~ 0
BUS2
Text HLabel 8050 5700 2    50   Input ~ 0
BUS3
Text HLabel 8050 5800 2    50   Input ~ 0
BUS4
Text HLabel 8050 5900 2    50   Input ~ 0
BUS5
Text HLabel 8050 6000 2    50   Input ~ 0
BUS6
Text HLabel 8050 6100 2    50   Input ~ 0
BUS7
Text HLabel 9550 5400 2    50   Input ~ 0
BUS0
Text HLabel 9550 5500 2    50   Input ~ 0
BUS1
Text HLabel 9550 5600 2    50   Input ~ 0
BUS2
Text HLabel 9550 5700 2    50   Input ~ 0
BUS3
Text HLabel 9550 5800 2    50   Input ~ 0
BUS4
Text HLabel 9550 5900 2    50   Input ~ 0
BUS5
Text HLabel 9550 6000 2    50   Input ~ 0
BUS6
Text HLabel 9550 6100 2    50   Input ~ 0
BUS7
Text HLabel 1750 3950 0    50   Input ~ 0
~R1_IN
Text HLabel 3450 1750 0    50   Input ~ 0
~R0_IN
Text HLabel 1750 6150 0    50   Input ~ 0
~R2_IN
Text HLabel 3450 3950 0    50   Input ~ 0
~R1_IN
$Comp
L power:VCC #PWR0279
U 1 1 5B0B9051
P 3950 3150
AR Path="/5B0B7FE8/5B0B9051" Ref="#PWR0279"  Part="1" 
AR Path="/5B0B7FFA/5B0B9051" Ref="#PWR0281"  Part="1" 
F 0 "#PWR0281" H 3950 3000 50  0001 C CNN
F 1 "VCC" H 3967 3323 50  0000 C CNN
F 2 "" H 3950 3150 50  0001 C CNN
F 3 "" H 3950 3150 50  0001 C CNN
	1    3950 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0280
U 1 1 5B0B905E
P 4300 3150
AR Path="/5B0B7FE8/5B0B905E" Ref="#PWR0280"  Part="1" 
AR Path="/5B0B7FFA/5B0B905E" Ref="#PWR0282"  Part="1" 
F 0 "#PWR0282" H 4300 2900 50  0001 C CNN
F 1 "GND" V 4305 3022 50  0000 R CNN
F 2 "" H 4300 3150 50  0001 C CNN
F 3 "" H 4300 3150 50  0001 C CNN
	1    4300 3150
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C76
U 1 1 5B0B9C67
P 4200 3150
AR Path="/5B0B7FE8/5B0B9C67" Ref="C76"  Part="1" 
AR Path="/5B0B7FFA/5B0B9C67" Ref="C77"  Part="1" 
F 0 "C77" V 3971 3150 50  0000 C CNN
F 1 "0.1uF" V 4062 3150 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4200 3150 50  0001 C CNN
F 3 "~" H 4200 3150 50  0001 C CNN
	1    4200 3150
	0    1    1    0   
$EndComp
Text HLabel 1750 2050 0    50   Input ~ 0
~COUNT_ENABLE
$Comp
L power:GND #PWR0127
U 1 1 5B3604FF
P 7200 3050
AR Path="/5B0B7FFA/5B3604FF" Ref="#PWR0127"  Part="1" 
AR Path="/5B0B7FE8/5B3604FF" Ref="#PWR0125"  Part="1" 
F 0 "#PWR0127" H 7200 2800 50  0001 C CNN
F 1 "GND" H 7205 2877 50  0000 C CNN
F 2 "" H 7200 3050 50  0001 C CNN
F 3 "" H 7200 3050 50  0001 C CNN
	1    7200 3050
	0    1    1    0   
$EndComp
NoConn ~ 7800 3050
$EndSCHEMATC
