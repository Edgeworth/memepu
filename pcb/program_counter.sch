EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 21 38
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
L 74xx:74LS161 U40
U 1 1 5B096C53
P 2050 1900
F 0 "U40" H 2050 1850 50  0000 C CNN
F 1 "74LS161" H 2100 1600 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 2050 1900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 2050 1900 50  0001 C CNN
	1    2050 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0186
U 1 1 5B096D28
P 2050 2700
F 0 "#PWR0186" H 2050 2450 50  0001 C CNN
F 1 "GND" H 2055 2527 50  0000 C CNN
F 2 "" H 2050 2700 50  0001 C CNN
F 3 "" H 2050 2700 50  0001 C CNN
	1    2050 2700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0187
U 1 1 5B096D60
P 2050 1100
F 0 "#PWR0187" H 2050 950 50  0001 C CNN
F 1 "VCC" H 2067 1273 50  0000 C CNN
F 2 "" H 2050 1100 50  0001 C CNN
F 3 "" H 2050 1100 50  0001 C CNN
	1    2050 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C48
U 1 1 5B096DB4
P 2350 1100
F 0 "C48" V 2121 1100 50  0000 C CNN
F 1 "0.1uF" V 2212 1100 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2350 1100 50  0001 C CNN
F 3 "~" H 2350 1100 50  0001 C CNN
	1    2350 1100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0188
U 1 1 5B096E07
P 2450 1100
F 0 "#PWR0188" H 2450 850 50  0001 C CNN
F 1 "GND" V 2455 972 50  0000 R CNN
F 2 "" H 2450 1100 50  0001 C CNN
F 3 "" H 2450 1100 50  0001 C CNN
	1    2450 1100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2250 1100 2050 1100
Connection ~ 2050 1100
$Comp
L 74xx:74LS161 U42
U 1 1 5B096E8F
P 3900 1900
F 0 "U42" H 3900 1850 50  0000 C CNN
F 1 "74LS161" H 3950 1600 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 3900 1900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 3900 1900 50  0001 C CNN
	1    3900 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0189
U 1 1 5B096E96
P 3900 2700
F 0 "#PWR0189" H 3900 2450 50  0001 C CNN
F 1 "GND" H 3905 2527 50  0000 C CNN
F 2 "" H 3900 2700 50  0001 C CNN
F 3 "" H 3900 2700 50  0001 C CNN
	1    3900 2700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0190
U 1 1 5B096E9C
P 3900 1100
F 0 "#PWR0190" H 3900 950 50  0001 C CNN
F 1 "VCC" H 3917 1273 50  0000 C CNN
F 2 "" H 3900 1100 50  0001 C CNN
F 3 "" H 3900 1100 50  0001 C CNN
	1    3900 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C50
U 1 1 5B096EA2
P 4200 1100
F 0 "C50" V 3971 1100 50  0000 C CNN
F 1 "0.1uF" V 4062 1100 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4200 1100 50  0001 C CNN
F 3 "~" H 4200 1100 50  0001 C CNN
	1    4200 1100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0191
U 1 1 5B096EA9
P 4300 1100
F 0 "#PWR0191" H 4300 850 50  0001 C CNN
F 1 "GND" V 4305 972 50  0000 R CNN
F 2 "" H 4300 1100 50  0001 C CNN
F 3 "" H 4300 1100 50  0001 C CNN
	1    4300 1100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4100 1100 3900 1100
Connection ~ 3900 1100
$Comp
L 74xx:74LS161 U41
U 1 1 5B096F04
P 2050 4400
F 0 "U41" H 2050 4350 50  0000 C CNN
F 1 "74LS161" H 2100 4100 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 2050 4400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 2050 4400 50  0001 C CNN
	1    2050 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0192
U 1 1 5B096F0B
P 2050 5200
F 0 "#PWR0192" H 2050 4950 50  0001 C CNN
F 1 "GND" H 2055 5027 50  0000 C CNN
F 2 "" H 2050 5200 50  0001 C CNN
F 3 "" H 2050 5200 50  0001 C CNN
	1    2050 5200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0193
U 1 1 5B096F11
P 2050 3600
F 0 "#PWR0193" H 2050 3450 50  0001 C CNN
F 1 "VCC" H 2067 3773 50  0000 C CNN
F 2 "" H 2050 3600 50  0001 C CNN
F 3 "" H 2050 3600 50  0001 C CNN
	1    2050 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C49
U 1 1 5B096F17
P 2350 3600
F 0 "C49" V 2121 3600 50  0000 C CNN
F 1 "0.1uF" V 2212 3600 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2350 3600 50  0001 C CNN
F 3 "~" H 2350 3600 50  0001 C CNN
	1    2350 3600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0194
U 1 1 5B096F1E
P 2450 3600
F 0 "#PWR0194" H 2450 3350 50  0001 C CNN
F 1 "GND" V 2455 3472 50  0000 R CNN
F 2 "" H 2450 3600 50  0001 C CNN
F 3 "" H 2450 3600 50  0001 C CNN
	1    2450 3600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2250 3600 2050 3600
Connection ~ 2050 3600
$Comp
L 74xx:74LS161 U43
U 1 1 5B096F8D
P 3900 4400
F 0 "U43" H 3900 4350 50  0000 C CNN
F 1 "74LS161" H 3950 4100 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 3900 4400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 3900 4400 50  0001 C CNN
	1    3900 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0195
U 1 1 5B096F94
P 3900 5200
F 0 "#PWR0195" H 3900 4950 50  0001 C CNN
F 1 "GND" H 3905 5027 50  0000 C CNN
F 2 "" H 3900 5200 50  0001 C CNN
F 3 "" H 3900 5200 50  0001 C CNN
	1    3900 5200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0196
U 1 1 5B096F9A
P 3900 3600
F 0 "#PWR0196" H 3900 3450 50  0001 C CNN
F 1 "VCC" H 3917 3773 50  0000 C CNN
F 2 "" H 3900 3600 50  0001 C CNN
F 3 "" H 3900 3600 50  0001 C CNN
	1    3900 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C51
U 1 1 5B096FA0
P 4200 3600
F 0 "C51" V 3971 3600 50  0000 C CNN
F 1 "0.1uF" V 4062 3600 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4200 3600 50  0001 C CNN
F 3 "~" H 4200 3600 50  0001 C CNN
	1    4200 3600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0197
U 1 1 5B096FA7
P 4300 3600
F 0 "#PWR0197" H 4300 3350 50  0001 C CNN
F 1 "GND" V 4305 3472 50  0000 R CNN
F 2 "" H 4300 3600 50  0001 C CNN
F 3 "" H 4300 3600 50  0001 C CNN
	1    4300 3600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4100 3600 3900 3600
Connection ~ 3900 3600
Text HLabel 5650 2350 0    50   Input ~ 0
~PC0_OUT
$Comp
L 74xx:74HC245 U?
U 1 1 5B09711A
P 6150 1850
AR Path="/5AFD5CE2/5AFCCD08/5B09711A" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5B09711A" Ref="U?"  Part="1" 
AR Path="/5B096BDD/5B09711A" Ref="U45"  Part="1" 
F 0 "U45" H 6250 2550 50  0000 C CNN
F 1 "74HC245" H 6200 1550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 6150 1850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 6150 1850 50  0001 C CNN
	1    6150 1850
	1    0    0    -1  
$EndComp
Text HLabel 6650 1350 2    50   Input ~ 0
BUS0
Text HLabel 6650 1450 2    50   Input ~ 0
BUS1
Text HLabel 6650 1550 2    50   Input ~ 0
BUS2
Text HLabel 6650 1650 2    50   Input ~ 0
BUS3
Text HLabel 6650 1750 2    50   Input ~ 0
BUS4
Text HLabel 6650 1850 2    50   Input ~ 0
BUS5
Text HLabel 6650 1950 2    50   Input ~ 0
BUS6
Text HLabel 6650 2050 2    50   Input ~ 0
BUS7
$Comp
L power:GND #PWR0198
U 1 1 5B097131
P 6150 2650
F 0 "#PWR0198" H 6150 2400 50  0001 C CNN
F 1 "GND" H 6155 2477 50  0000 C CNN
F 2 "" H 6150 2650 50  0001 C CNN
F 3 "" H 6150 2650 50  0001 C CNN
	1    6150 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C53
U 1 1 5B097137
P 5100 1750
F 0 "C53" H 5192 1796 50  0000 L CNN
F 1 "0.1uF" H 5192 1705 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 5100 1750 50  0001 C CNN
F 3 "~" H 5100 1750 50  0001 C CNN
	1    5100 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 1650 5100 1050
Wire Wire Line
	5100 1050 6150 1050
Wire Wire Line
	6150 2650 5100 2650
Wire Wire Line
	5100 2650 5100 1850
Connection ~ 6150 2650
$Comp
L power:VCC #PWR0199
U 1 1 5B097143
P 6150 1050
F 0 "#PWR0199" H 6150 900 50  0001 C CNN
F 1 "VCC" H 6167 1223 50  0000 C CNN
F 2 "" H 6150 1050 50  0001 C CNN
F 3 "" H 6150 1050 50  0001 C CNN
	1    6150 1050
	1    0    0    -1  
$EndComp
Connection ~ 6150 1050
$Comp
L power:VCC #PWR0200
U 1 1 5B09714A
P 5650 2250
F 0 "#PWR0200" H 5650 2100 50  0001 C CNN
F 1 "VCC" H 5667 2423 50  0000 C CNN
F 2 "" H 5650 2250 50  0001 C CNN
F 3 "" H 5650 2250 50  0001 C CNN
	1    5650 2250
	0    -1   -1   0   
$EndComp
Text HLabel 7800 2350 0    50   Input ~ 0
~PC1_OUT
$Comp
L 74xx:74HC245 U?
U 1 1 5B097257
P 8300 1850
AR Path="/5AFD5CE2/5AFCCD08/5B097257" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5B097257" Ref="U?"  Part="1" 
AR Path="/5B096BDD/5B097257" Ref="U46"  Part="1" 
F 0 "U46" H 8400 2550 50  0000 C CNN
F 1 "74HC245" H 8350 1550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 8300 1850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 8300 1850 50  0001 C CNN
	1    8300 1850
	1    0    0    -1  
$EndComp
Text HLabel 8800 1350 2    50   Input ~ 0
BUS0
Text HLabel 8800 1450 2    50   Input ~ 0
BUS1
Text HLabel 8800 1550 2    50   Input ~ 0
BUS2
Text HLabel 8800 1650 2    50   Input ~ 0
BUS3
Text HLabel 8800 1750 2    50   Input ~ 0
BUS4
Text HLabel 8800 1850 2    50   Input ~ 0
BUS5
Text HLabel 8800 1950 2    50   Input ~ 0
BUS6
Text HLabel 8800 2050 2    50   Input ~ 0
BUS7
$Comp
L power:GND #PWR0201
U 1 1 5B097266
P 8300 2650
F 0 "#PWR0201" H 8300 2400 50  0001 C CNN
F 1 "GND" H 8305 2477 50  0000 C CNN
F 2 "" H 8300 2650 50  0001 C CNN
F 3 "" H 8300 2650 50  0001 C CNN
	1    8300 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C54
U 1 1 5B09726C
P 7250 1750
F 0 "C54" H 7342 1796 50  0000 L CNN
F 1 "0.1uF" H 7342 1705 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 7250 1750 50  0001 C CNN
F 3 "~" H 7250 1750 50  0001 C CNN
	1    7250 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 1650 7250 1050
Wire Wire Line
	7250 1050 8300 1050
Wire Wire Line
	8300 2650 7250 2650
Wire Wire Line
	7250 2650 7250 1850
Connection ~ 8300 2650
$Comp
L power:VCC #PWR0202
U 1 1 5B097278
P 8300 1050
F 0 "#PWR0202" H 8300 900 50  0001 C CNN
F 1 "VCC" H 8317 1223 50  0000 C CNN
F 2 "" H 8300 1050 50  0001 C CNN
F 3 "" H 8300 1050 50  0001 C CNN
	1    8300 1050
	1    0    0    -1  
$EndComp
Connection ~ 8300 1050
$Comp
L power:VCC #PWR0203
U 1 1 5B09727F
P 7800 2250
F 0 "#PWR0203" H 7800 2100 50  0001 C CNN
F 1 "VCC" H 7817 2423 50  0000 C CNN
F 2 "" H 7800 2250 50  0001 C CNN
F 3 "" H 7800 2250 50  0001 C CNN
	1    7800 2250
	0    -1   -1   0   
$EndComp
Text HLabel 9850 2350 0    50   Input ~ 0
~PC2_OUT
$Comp
L 74xx:74HC245 U?
U 1 1 5B09735A
P 10350 1850
AR Path="/5AFD5CE2/5AFCCD08/5B09735A" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5B09735A" Ref="U?"  Part="1" 
AR Path="/5B096BDD/5B09735A" Ref="U47"  Part="1" 
F 0 "U47" H 10450 2550 50  0000 C CNN
F 1 "74HC245" H 10400 1550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 10350 1850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 10350 1850 50  0001 C CNN
	1    10350 1850
	1    0    0    -1  
$EndComp
Text HLabel 10850 1350 2    50   Input ~ 0
BUS0
Text HLabel 10850 1450 2    50   Input ~ 0
BUS1
Text HLabel 10850 1550 2    50   Input ~ 0
BUS2
Text HLabel 10850 1650 2    50   Input ~ 0
BUS3
Text HLabel 10850 1750 2    50   Input ~ 0
BUS4
Text HLabel 10850 1850 2    50   Input ~ 0
BUS5
Text HLabel 10850 1950 2    50   Input ~ 0
BUS6
Text HLabel 10850 2050 2    50   Input ~ 0
BUS7
$Comp
L power:GND #PWR0204
U 1 1 5B097369
P 10350 2650
F 0 "#PWR0204" H 10350 2400 50  0001 C CNN
F 1 "GND" H 10355 2477 50  0000 C CNN
F 2 "" H 10350 2650 50  0001 C CNN
F 3 "" H 10350 2650 50  0001 C CNN
	1    10350 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C55
U 1 1 5B09736F
P 9300 1750
F 0 "C55" H 9392 1796 50  0000 L CNN
F 1 "0.1uF" H 9392 1705 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 9300 1750 50  0001 C CNN
F 3 "~" H 9300 1750 50  0001 C CNN
	1    9300 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 1650 9300 1050
Wire Wire Line
	9300 1050 10350 1050
Wire Wire Line
	10350 2650 9300 2650
Wire Wire Line
	9300 2650 9300 1850
Connection ~ 10350 2650
$Comp
L power:VCC #PWR0205
U 1 1 5B09737B
P 10350 1050
F 0 "#PWR0205" H 10350 900 50  0001 C CNN
F 1 "VCC" H 10367 1223 50  0000 C CNN
F 2 "" H 10350 1050 50  0001 C CNN
F 3 "" H 10350 1050 50  0001 C CNN
	1    10350 1050
	1    0    0    -1  
$EndComp
Connection ~ 10350 1050
$Comp
L power:VCC #PWR0206
U 1 1 5B097382
P 9850 2250
F 0 "#PWR0206" H 9850 2100 50  0001 C CNN
F 1 "VCC" H 9867 2423 50  0000 C CNN
F 2 "" H 9850 2250 50  0001 C CNN
F 3 "" H 9850 2250 50  0001 C CNN
	1    9850 2250
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74LS161 U39
U 1 1 5B0975BE
P 2000 6700
F 0 "U39" H 2000 6650 50  0000 C CNN
F 1 "74LS161" H 2050 6400 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 2000 6700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 2000 6700 50  0001 C CNN
	1    2000 6700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0207
U 1 1 5B0975C5
P 2000 7500
F 0 "#PWR0207" H 2000 7250 50  0001 C CNN
F 1 "GND" H 2005 7327 50  0000 C CNN
F 2 "" H 2000 7500 50  0001 C CNN
F 3 "" H 2000 7500 50  0001 C CNN
	1    2000 7500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0208
U 1 1 5B0975CB
P 2000 5900
F 0 "#PWR0208" H 2000 5750 50  0001 C CNN
F 1 "VCC" H 2017 6073 50  0000 C CNN
F 2 "" H 2000 5900 50  0001 C CNN
F 3 "" H 2000 5900 50  0001 C CNN
	1    2000 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C47
U 1 1 5B0975D1
P 2300 5900
F 0 "C47" V 2071 5900 50  0000 C CNN
F 1 "0.1uF" V 2162 5900 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2300 5900 50  0001 C CNN
F 3 "~" H 2300 5900 50  0001 C CNN
	1    2300 5900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0209
U 1 1 5B0975D8
P 2400 5900
F 0 "#PWR0209" H 2400 5650 50  0001 C CNN
F 1 "GND" V 2405 5772 50  0000 R CNN
F 2 "" H 2400 5900 50  0001 C CNN
F 3 "" H 2400 5900 50  0001 C CNN
	1    2400 5900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2200 5900 2000 5900
Connection ~ 2000 5900
$Comp
L 74xx:74LS161 U44
U 1 1 5B0975E0
P 3950 6700
F 0 "U44" H 3950 6650 50  0000 C CNN
F 1 "74LS161" H 4000 6400 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 3950 6700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 3950 6700 50  0001 C CNN
	1    3950 6700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0210
U 1 1 5B0975E7
P 3950 7500
F 0 "#PWR0210" H 3950 7250 50  0001 C CNN
F 1 "GND" H 3955 7327 50  0000 C CNN
F 2 "" H 3950 7500 50  0001 C CNN
F 3 "" H 3950 7500 50  0001 C CNN
	1    3950 7500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0211
U 1 1 5B0975ED
P 3950 5900
F 0 "#PWR0211" H 3950 5750 50  0001 C CNN
F 1 "VCC" H 3967 6073 50  0000 C CNN
F 2 "" H 3950 5900 50  0001 C CNN
F 3 "" H 3950 5900 50  0001 C CNN
	1    3950 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C52
U 1 1 5B0975F3
P 4250 5900
F 0 "C52" V 4021 5900 50  0000 C CNN
F 1 "0.1uF" V 4112 5900 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4250 5900 50  0001 C CNN
F 3 "~" H 4250 5900 50  0001 C CNN
	1    4250 5900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0212
U 1 1 5B0975FA
P 4350 5900
F 0 "#PWR0212" H 4350 5650 50  0001 C CNN
F 1 "GND" V 4355 5772 50  0000 R CNN
F 2 "" H 4350 5900 50  0001 C CNN
F 3 "" H 4350 5900 50  0001 C CNN
	1    4350 5900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4150 5900 3950 5900
Connection ~ 3950 5900
Text HLabel 1550 1400 0    50   Input ~ 0
BUS0
Text HLabel 1550 1500 0    50   Input ~ 0
BUS1
Text HLabel 1550 1600 0    50   Input ~ 0
BUS2
Text HLabel 1550 1700 0    50   Input ~ 0
BUS3
Text HLabel 3400 1400 0    50   Input ~ 0
BUS4
Text HLabel 3400 1500 0    50   Input ~ 0
BUS5
Text HLabel 3400 1600 0    50   Input ~ 0
BUS6
Text HLabel 3400 1700 0    50   Input ~ 0
BUS7
Text HLabel 1550 3900 0    50   Input ~ 0
BUS0
Text HLabel 1550 4000 0    50   Input ~ 0
BUS1
Text HLabel 1550 4100 0    50   Input ~ 0
BUS2
Text HLabel 1550 4200 0    50   Input ~ 0
BUS3
Text HLabel 1500 6200 0    50   Input ~ 0
BUS0
Text HLabel 1500 6300 0    50   Input ~ 0
BUS1
Text HLabel 1500 6400 0    50   Input ~ 0
BUS2
Text HLabel 1500 6500 0    50   Input ~ 0
BUS3
Text HLabel 3400 3900 0    50   Input ~ 0
BUS4
Text HLabel 3400 4000 0    50   Input ~ 0
BUS5
Text HLabel 3400 4100 0    50   Input ~ 0
BUS6
Text HLabel 3400 4200 0    50   Input ~ 0
BUS7
Text HLabel 3450 6200 0    50   Input ~ 0
BUS4
Text HLabel 3450 6300 0    50   Input ~ 0
BUS5
Text HLabel 3450 6400 0    50   Input ~ 0
BUS6
Text HLabel 3450 6500 0    50   Input ~ 0
BUS7
Text Label 5650 1350 2    50   ~ 0
PC0
Text Label 5650 1450 2    50   ~ 0
PC1
Text Label 5650 1550 2    50   ~ 0
PC2
Text Label 5650 1650 2    50   ~ 0
PC3
Text Label 5650 1750 2    50   ~ 0
PC4
Text Label 5650 1850 2    50   ~ 0
PC5
Text Label 5650 1950 2    50   ~ 0
PC6
Text Label 5650 2050 2    50   ~ 0
PC7
Text Label 7800 1350 2    50   ~ 0
PC8
Text Label 7800 1450 2    50   ~ 0
PC9
Text Label 7800 1550 2    50   ~ 0
PC10
Text Label 7800 1650 2    50   ~ 0
PC11
Text Label 7800 1750 2    50   ~ 0
PC12
Text Label 7800 1850 2    50   ~ 0
PC13
Text Label 7800 1950 2    50   ~ 0
PC14
Text Label 7800 2050 2    50   ~ 0
PC15
Text Label 9850 1350 2    50   ~ 0
PC16
Text Label 9850 1450 2    50   ~ 0
PC17
Text Label 9850 1550 2    50   ~ 0
PC18
Text Label 9850 1650 2    50   ~ 0
PC19
Text Label 9850 1750 2    50   ~ 0
PC20
Text Label 9850 1850 2    50   ~ 0
PC21
Text Label 9850 1950 2    50   ~ 0
PC22
Text Label 9850 2050 2    50   ~ 0
PC23
Text HLabel 1550 1900 0    50   Input ~ 0
~PC0_IN_NCLK
Text HLabel 3400 1900 0    50   Input ~ 0
~PC0_IN_NCLK
Text HLabel 1550 4400 0    50   Input ~ 0
~PC1_IN_NCLK
Text HLabel 3400 4400 0    50   Input ~ 0
~PC1_IN_NCLK
Text HLabel 1500 6700 0    50   Input ~ 0
~PC2_IN_NCLK
Text HLabel 3450 6700 0    50   Input ~ 0
~PC2_IN_NCLK
Text Label 2550 1400 0    50   ~ 0
PC0
Text Label 2550 1500 0    50   ~ 0
PC1
Text Label 2550 1600 0    50   ~ 0
PC2
Text Label 2550 1700 0    50   ~ 0
PC3
Text Label 4400 1400 0    50   ~ 0
PC4
Text Label 4400 1500 0    50   ~ 0
PC5
Text Label 4400 1600 0    50   ~ 0
PC6
Text Label 4400 1700 0    50   ~ 0
PC7
Text Label 2550 3900 0    50   ~ 0
PC8
Text Label 2550 4000 0    50   ~ 0
PC9
Text Label 2550 4100 0    50   ~ 0
PC10
Text Label 2550 4200 0    50   ~ 0
PC11
Text Label 4400 3900 0    50   ~ 0
PC12
Text Label 4400 4000 0    50   ~ 0
PC13
Text Label 4400 4100 0    50   ~ 0
PC14
Text Label 4400 4200 0    50   ~ 0
PC15
Text Label 2500 6200 0    50   ~ 0
PC16
Text Label 2500 6300 0    50   ~ 0
PC17
Text Label 2500 6400 0    50   ~ 0
PC18
Text Label 2500 6500 0    50   ~ 0
PC19
Text Label 4450 6200 0    50   ~ 0
PC20
Text Label 4450 6300 0    50   ~ 0
PC21
Text Label 4450 6400 0    50   ~ 0
PC22
Text Label 4450 6500 0    50   ~ 0
PC23
NoConn ~ 4450 6700
Text HLabel 1550 2400 0    50   Input ~ 0
~RESET
Text HLabel 3400 2400 0    50   Input ~ 0
~RESET
Text HLabel 3400 4900 0    50   Input ~ 0
~RESET
Text HLabel 1550 4900 0    50   Input ~ 0
~RESET
Text HLabel 1500 7200 0    50   Input ~ 0
~RESET
Text HLabel 3450 7200 0    50   Input ~ 0
~RESET
Text Label 2550 1900 0    50   ~ 0
CARRY0
Text Label 4400 1900 0    50   ~ 0
CARRY1
Text Label 2550 4400 0    50   ~ 0
CARRY2
Text Label 4400 4400 0    50   ~ 0
CARRY3
Text Label 2500 6700 0    50   ~ 0
CARRY4
Text Label 3400 2100 2    50   ~ 0
CARRY0
Text HLabel 1550 2200 0    50   Input ~ 0
CLK
Text HLabel 3400 2200 0    50   Input ~ 0
CLK
Text HLabel 1550 4700 0    50   Input ~ 0
CLK
Text HLabel 3400 4700 0    50   Input ~ 0
CLK
Text HLabel 1500 7000 0    50   Input ~ 0
CLK
Text HLabel 3450 7000 0    50   Input ~ 0
CLK
Text HLabel 1550 2000 0    50   Input ~ 0
PC_INC
Text HLabel 3400 2000 0    50   Input ~ 0
PC_INC
Text HLabel 3400 4500 0    50   Input ~ 0
PC_INC
Text HLabel 1550 4500 0    50   Input ~ 0
PC_INC
Text HLabel 1500 6800 0    50   Input ~ 0
PC_INC
Text HLabel 3450 6800 0    50   Input ~ 0
PC_INC
$Comp
L power:VCC #PWR0213
U 1 1 5B0A0C40
P 1550 2100
F 0 "#PWR0213" H 1550 1950 50  0001 C CNN
F 1 "VCC" V 1568 2227 50  0000 L CNN
F 2 "" H 1550 2100 50  0001 C CNN
F 3 "" H 1550 2100 50  0001 C CNN
	1    1550 2100
	0    -1   -1   0   
$EndComp
Text Label 1550 4600 2    50   ~ 0
CARRY1
Text Label 3400 4600 2    50   ~ 0
CARRY2
Text Label 1500 6900 2    50   ~ 0
CARRY3
Text Label 3450 6900 2    50   ~ 0
CARRY4
$EndSCHEMATC
