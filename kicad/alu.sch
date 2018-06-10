EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 11 35
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
L 74xx:74HC86 U13
U 1 1 5AFDA904
P 1450 1550
F 0 "U13" H 1450 1550 50  0000 C CNN
F 1 "74HC86" H 1700 1450 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1450 1550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 1450 1550 50  0001 C CNN
	1    1450 1550
	1    0    0    -1  
$EndComp
Text HLabel 2400 1050 0    50   Input ~ 0
SUB
Text HLabel 2400 1250 0    50   Input ~ 0
A0
Text HLabel 2400 1350 0    50   Input ~ 0
A1
Text HLabel 2400 1450 0    50   Input ~ 0
A2
Text HLabel 2400 1550 0    50   Input ~ 0
A3
Text HLabel 5450 2150 2    50   Input ~ 0
O0
Text HLabel 5450 2250 2    50   Input ~ 0
O1
Text HLabel 5450 2350 2    50   Input ~ 0
O2
Text HLabel 5450 2450 2    50   Input ~ 0
O3
$Comp
L 74xx:74LS283 U17
U 1 1 5AFDA782
P 2900 1550
F 0 "U17" H 3000 2250 50  0000 C CNN
F 1 "74LS283" H 2950 1300 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 2900 1550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS283" H 2900 1550 50  0001 C CNN
	1    2900 1550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U13
U 2 1 5AFDD175
P 1450 1900
F 0 "U13" H 1450 1900 50  0000 C CNN
F 1 "74HC86" H 1700 1800 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1450 1900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 1450 1900 50  0001 C CNN
	2    1450 1900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U13
U 3 1 5AFDD425
P 1450 2250
F 0 "U13" H 1450 2250 50  0000 C CNN
F 1 "74HC86" H 1700 2150 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1450 2250 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 1450 2250 50  0001 C CNN
	3    1450 2250
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U13
U 4 1 5AFDD974
P 1450 2600
F 0 "U13" H 1450 2600 50  0000 C CNN
F 1 "74HC86" H 1700 2500 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1450 2600 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 1450 2600 50  0001 C CNN
	4    1450 2600
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U13
U 5 1 5AFDDBF6
P 1450 3000
F 0 "U13" V 1400 3000 50  0000 C CNN
F 1 "74HC86" V 1550 3000 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1450 3000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 1450 3000 50  0001 C CNN
	5    1450 3000
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C24
U 1 1 5AFE0200
P 1450 3350
F 0 "C24" V 1550 3350 50  0000 C CNN
F 1 "0.1uF" V 1300 3350 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 1450 3350 50  0001 C CNN
F 3 "~" H 1450 3350 50  0001 C CNN
	1    1450 3350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	950  3000 950  3350
Wire Wire Line
	950  3350 1350 3350
Wire Wire Line
	1950 3000 1950 3350
Wire Wire Line
	1950 3350 1550 3350
Text HLabel 1150 1450 0    50   Input ~ 0
B0
Text HLabel 1150 1800 0    50   Input ~ 0
B1
Text HLabel 1150 2150 0    50   Input ~ 0
B2
Text HLabel 1150 2500 0    50   Input ~ 0
B3
Text HLabel 1150 1650 0    50   Input ~ 0
SUB
Text HLabel 1150 2000 0    50   Input ~ 0
SUB
Text HLabel 1150 2350 0    50   Input ~ 0
SUB
Text HLabel 1150 2700 0    50   Input ~ 0
SUB
Wire Wire Line
	1750 1550 1950 1550
Wire Wire Line
	1950 1550 1950 1750
Wire Wire Line
	1950 1750 2400 1750
Wire Wire Line
	1750 1900 2400 1900
Wire Wire Line
	2400 1900 2400 1850
Wire Wire Line
	1750 2250 1950 2250
Wire Wire Line
	1950 2250 1950 1950
Wire Wire Line
	1950 1950 2400 1950
Wire Wire Line
	1750 2600 2100 2600
Wire Wire Line
	2100 2600 2100 2050
Wire Wire Line
	2100 2050 2400 2050
$Comp
L power:GND #PWR041
U 1 1 5AFE6C21
P 2900 2350
F 0 "#PWR041" H 2900 2100 50  0001 C CNN
F 1 "GND" H 2905 2177 50  0000 C CNN
F 2 "" H 2900 2350 50  0001 C CNN
F 3 "" H 2900 2350 50  0001 C CNN
	1    2900 2350
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR040
U 1 1 5AFE7002
P 2900 750
F 0 "#PWR040" H 2900 600 50  0001 C CNN
F 1 "VCC" H 2917 923 50  0000 C CNN
F 2 "" H 2900 750 50  0001 C CNN
F 3 "" H 2900 750 50  0001 C CNN
	1    2900 750 
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U15
U 1 1 5AFE829E
P 1450 3800
F 0 "U15" H 1450 3800 50  0000 C CNN
F 1 "74HC86" H 1700 3700 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1450 3800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 1450 3800 50  0001 C CNN
	1    1450 3800
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS283 U19
U 1 1 5AFE82AE
P 2900 3800
F 0 "U19" H 3000 4500 50  0000 C CNN
F 1 "74LS283" H 2950 3550 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 2900 3800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS283" H 2900 3800 50  0001 C CNN
	1    2900 3800
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U15
U 2 1 5AFE82B5
P 1450 4150
F 0 "U15" H 1450 4150 50  0000 C CNN
F 1 "74HC86" H 1700 4050 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1450 4150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 1450 4150 50  0001 C CNN
	2    1450 4150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U15
U 3 1 5AFE82BC
P 1450 4500
F 0 "U15" H 1450 4500 50  0000 C CNN
F 1 "74HC86" H 1700 4400 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1450 4500 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 1450 4500 50  0001 C CNN
	3    1450 4500
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U15
U 4 1 5AFE82C3
P 1450 4850
F 0 "U15" H 1450 4850 50  0000 C CNN
F 1 "74HC86" H 1700 4750 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1450 4850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 1450 4850 50  0001 C CNN
	4    1450 4850
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U15
U 5 1 5AFE82CA
P 1450 5250
F 0 "U15" V 1400 5250 50  0000 C CNN
F 1 "74HC86" V 1550 5250 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1450 5250 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 1450 5250 50  0001 C CNN
	5    1450 5250
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C25
U 1 1 5AFE82D1
P 1450 5600
F 0 "C25" V 1550 5600 50  0000 C CNN
F 1 "0.1uF" V 1300 5600 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 1450 5600 50  0001 C CNN
F 3 "~" H 1450 5600 50  0001 C CNN
	1    1450 5600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	950  5250 950  5600
Wire Wire Line
	950  5600 1350 5600
Wire Wire Line
	1950 5250 1950 5600
Wire Wire Line
	1950 5600 1550 5600
Text HLabel 1150 3900 0    50   Input ~ 0
SUB
Text HLabel 1150 4250 0    50   Input ~ 0
SUB
Text HLabel 1150 4600 0    50   Input ~ 0
SUB
Text HLabel 1150 4950 0    50   Input ~ 0
SUB
Wire Wire Line
	1750 3800 1950 3800
Wire Wire Line
	1950 3800 1950 4000
Wire Wire Line
	1950 4000 2400 4000
Wire Wire Line
	1750 4150 2400 4150
Wire Wire Line
	2400 4150 2400 4100
Wire Wire Line
	1750 4500 1950 4500
Wire Wire Line
	1950 4500 1950 4200
Wire Wire Line
	1950 4200 2400 4200
Wire Wire Line
	1750 4850 2100 4850
Wire Wire Line
	2100 4850 2100 4300
Wire Wire Line
	2100 4300 2400 4300
$Comp
L power:GND #PWR043
U 1 1 5AFE82EF
P 2900 4600
F 0 "#PWR043" H 2900 4350 50  0001 C CNN
F 1 "GND" H 2905 4427 50  0000 C CNN
F 2 "" H 2900 4600 50  0001 C CNN
F 3 "" H 2900 4600 50  0001 C CNN
	1    2900 4600
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR042
U 1 1 5AFE82F5
P 2900 3000
F 0 "#PWR042" H 2900 2850 50  0001 C CNN
F 1 "VCC" H 2917 3173 50  0000 C CNN
F 2 "" H 2900 3000 50  0001 C CNN
F 3 "" H 2900 3000 50  0001 C CNN
	1    2900 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 1550 3400 2700
Wire Wire Line
	3400 2700 2400 2700
Wire Wire Line
	2400 2700 2400 3300
Text HLabel 2400 3500 0    50   Input ~ 0
A4
Text HLabel 2400 3600 0    50   Input ~ 0
A5
Text HLabel 2400 3700 0    50   Input ~ 0
A6
Text HLabel 2400 3800 0    50   Input ~ 0
A7
Text HLabel 5450 2550 2    50   Input ~ 0
O4
Text HLabel 5450 2650 2    50   Input ~ 0
O5
Text HLabel 5450 2750 2    50   Input ~ 0
O6
Text HLabel 5450 2850 2    50   Input ~ 0
O7
Text HLabel 3400 3800 2    50   Input ~ 0
CARRY
$Comp
L 74xx:74HC245 U20
U 1 1 5AFED6C1
P 4950 2650
F 0 "U20" H 5050 3300 50  0000 C CNN
F 1 "74HC245" H 4950 2350 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 4950 2650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 4950 2650 50  0001 C CNN
	1    4950 2650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR045
U 1 1 5AFEE097
P 4950 1850
F 0 "#PWR045" H 4950 1700 50  0001 C CNN
F 1 "VCC" H 4967 2023 50  0000 C CNN
F 2 "" H 4950 1850 50  0001 C CNN
F 3 "" H 4950 1850 50  0001 C CNN
	1    4950 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR046
U 1 1 5AFEE39F
P 4950 3450
F 0 "#PWR046" H 4950 3200 50  0001 C CNN
F 1 "GND" H 4955 3277 50  0000 C CNN
F 2 "" H 4950 3450 50  0001 C CNN
F 3 "" H 4950 3450 50  0001 C CNN
	1    4950 3450
	1    0    0    -1  
$EndComp
Text HLabel 4450 3150 0    50   Input ~ 0
~SUM_OUT
$Comp
L power:VCC #PWR044
U 1 1 5AFEF7A6
P 4450 3050
F 0 "#PWR044" H 4450 2900 50  0001 C CNN
F 1 "VCC" V 4468 3177 50  0000 L CNN
F 2 "" H 4450 3050 50  0001 C CNN
F 3 "" H 4450 3050 50  0001 C CNN
	1    4450 3050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3400 1050 4450 1050
Wire Wire Line
	4450 1050 4450 2150
Wire Wire Line
	3400 1150 4350 1150
Wire Wire Line
	4350 1150 4350 2250
Wire Wire Line
	4350 2250 4450 2250
Wire Wire Line
	3400 1250 4250 1250
Wire Wire Line
	4250 1250 4250 2350
Wire Wire Line
	4250 2350 4450 2350
Wire Wire Line
	3400 1350 4150 1350
Wire Wire Line
	4150 1350 4150 2450
Wire Wire Line
	4150 2450 4450 2450
Wire Wire Line
	3600 2550 4450 2550
Wire Wire Line
	3600 3300 3400 3300
Wire Wire Line
	3600 2550 3600 3300
Wire Wire Line
	3400 3400 3700 3400
Wire Wire Line
	3700 3400 3700 2650
Wire Wire Line
	3700 2650 4450 2650
Wire Wire Line
	3400 3500 3800 3500
Wire Wire Line
	3800 3500 3800 2750
Wire Wire Line
	3800 2750 4450 2750
Wire Wire Line
	3400 3600 3900 3600
Wire Wire Line
	3900 3600 3900 2850
Wire Wire Line
	3900 2850 4450 2850
Text HLabel 1150 3700 0    50   Input ~ 0
B4
Text HLabel 1150 4050 0    50   Input ~ 0
B5
Text HLabel 1150 4400 0    50   Input ~ 0
B6
Text HLabel 1150 4750 0    50   Input ~ 0
B7
$Comp
L power:GND #PWR0130
U 1 1 5AFD8FA6
P 950 5250
F 0 "#PWR0130" H 950 5000 50  0001 C CNN
F 1 "GND" H 955 5077 50  0000 C CNN
F 2 "" H 950 5250 50  0001 C CNN
F 3 "" H 950 5250 50  0001 C CNN
	1    950  5250
	0    1    1    0   
$EndComp
Connection ~ 950  5250
$Comp
L power:GND #PWR0131
U 1 1 5AFD9407
P 950 3000
F 0 "#PWR0131" H 950 2750 50  0001 C CNN
F 1 "GND" H 955 2827 50  0000 C CNN
F 2 "" H 950 3000 50  0001 C CNN
F 3 "" H 950 3000 50  0001 C CNN
	1    950  3000
	0    1    1    0   
$EndComp
Connection ~ 950  3000
$Comp
L power:VCC #PWR0132
U 1 1 5AFD97D2
P 1950 3000
F 0 "#PWR0132" H 1950 2850 50  0001 C CNN
F 1 "VCC" H 1967 3173 50  0000 C CNN
F 2 "" H 1950 3000 50  0001 C CNN
F 3 "" H 1950 3000 50  0001 C CNN
	1    1950 3000
	0    1    1    0   
$EndComp
Connection ~ 1950 3000
$Comp
L power:VCC #PWR0133
U 1 1 5AFD999F
P 1950 5250
F 0 "#PWR0133" H 1950 5100 50  0001 C CNN
F 1 "VCC" H 1967 5423 50  0000 C CNN
F 2 "" H 1950 5250 50  0001 C CNN
F 3 "" H 1950 5250 50  0001 C CNN
	1    1950 5250
	0    1    1    0   
$EndComp
Connection ~ 1950 5250
$Comp
L Device:C_Small C27
U 1 1 5AFE6E12
P 3400 700
F 0 "C27" V 3500 700 50  0000 C CNN
F 1 "0.1uF" V 3250 700 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 3400 700 50  0001 C CNN
F 3 "~" H 3400 700 50  0001 C CNN
	1    3400 700 
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C26
U 1 1 5AFE8488
P 3250 3000
F 0 "C26" V 3350 3000 50  0000 C CNN
F 1 "0.1uF" V 3100 3000 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 3250 3000 50  0001 C CNN
F 3 "~" H 3250 3000 50  0001 C CNN
	1    3250 3000
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C28
U 1 1 5AFE858C
P 5300 1700
F 0 "C28" V 5400 1700 50  0000 C CNN
F 1 "0.1uF" V 5150 1700 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 5300 1700 50  0001 C CNN
F 3 "~" H 5300 1700 50  0001 C CNN
	1    5300 1700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4950 1850 5100 1850
Wire Wire Line
	5100 1850 5100 1700
Wire Wire Line
	5100 1700 5200 1700
Connection ~ 4950 1850
Wire Wire Line
	2900 750  3300 750 
Wire Wire Line
	3300 750  3300 700 
Connection ~ 2900 750 
Wire Wire Line
	2900 3000 3150 3000
Connection ~ 2900 3000
$Comp
L power:GND #PWR0134
U 1 1 5AFEC01F
P 3350 3000
F 0 "#PWR0134" H 3350 2750 50  0001 C CNN
F 1 "GND" H 3355 2827 50  0000 C CNN
F 2 "" H 3350 3000 50  0001 C CNN
F 3 "" H 3350 3000 50  0001 C CNN
	1    3350 3000
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0135
U 1 1 5AFEC38A
P 3500 700
F 0 "#PWR0135" H 3500 450 50  0001 C CNN
F 1 "GND" H 3505 527 50  0000 C CNN
F 2 "" H 3500 700 50  0001 C CNN
F 3 "" H 3500 700 50  0001 C CNN
	1    3500 700 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0136
U 1 1 5AFECB6E
P 5400 1700
F 0 "#PWR0136" H 5400 1450 50  0001 C CNN
F 1 "GND" H 5405 1527 50  0000 C CNN
F 2 "" H 5400 1700 50  0001 C CNN
F 3 "" H 5400 1700 50  0001 C CNN
	1    5400 1700
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74HC00 U36
U 1 1 5B047088
P 7550 1450
F 0 "U36" H 7550 1450 50  0000 C CNN
F 1 "74HC00" H 7550 1684 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7550 1450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7550 1450 50  0001 C CNN
	1    7550 1450
	1    0    0    -1  
$EndComp
Wire Notes Line
	550  500  550  6000
Wire Notes Line
	550  6000 6100 6000
Wire Notes Line
	6100 6000 6100 500 
Wire Notes Line
	6100 500  550  500 
Text Notes 4700 700  0    100  ~ 0
Adder
$Comp
L 74xx:74HC00 U36
U 2 1 5B048AC7
P 7550 1900
F 0 "U36" H 7550 1900 50  0000 C CNN
F 1 "74HC00" H 7550 2134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7550 1900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7550 1900 50  0001 C CNN
	2    7550 1900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U36
U 3 1 5B048B7E
P 7550 2350
F 0 "U36" H 7550 2350 50  0000 C CNN
F 1 "74HC00" H 7550 2584 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7550 2350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7550 2350 50  0001 C CNN
	3    7550 2350
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U36
U 4 1 5B048C41
P 7550 2800
F 0 "U36" H 7550 2800 50  0000 C CNN
F 1 "74HC00" H 7550 3034 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7550 2800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7550 2800 50  0001 C CNN
	4    7550 2800
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U36
U 5 1 5B048CF0
P 7500 4150
F 0 "U36" V 7133 4150 50  0000 C CNN
F 1 "74HC00" V 7224 4150 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7500 4150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7500 4150 50  0001 C CNN
	5    7500 4150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0168
U 1 1 5B048F20
P 7000 4150
F 0 "#PWR0168" H 7000 3900 50  0001 C CNN
F 1 "GND" H 7005 3977 50  0000 C CNN
F 2 "" H 7000 4150 50  0001 C CNN
F 3 "" H 7000 4150 50  0001 C CNN
	1    7000 4150
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0169
U 1 1 5B048F70
P 8000 4150
F 0 "#PWR0169" H 8000 4000 50  0001 C CNN
F 1 "VCC" H 8017 4323 50  0000 C CNN
F 2 "" H 8000 4150 50  0001 C CNN
F 3 "" H 8000 4150 50  0001 C CNN
	1    8000 4150
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C44
U 1 1 5B048FC0
P 8000 4450
F 0 "C44" V 8100 4450 50  0000 C CNN
F 1 "0.1uF" V 7850 4450 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 8000 4450 50  0001 C CNN
F 3 "~" H 8000 4450 50  0001 C CNN
	1    8000 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 4350 8000 4150
Connection ~ 8000 4150
$Comp
L power:GND #PWR0175
U 1 1 5B04AC9F
P 8000 4550
F 0 "#PWR0175" H 8000 4300 50  0001 C CNN
F 1 "GND" H 8005 4377 50  0000 C CNN
F 2 "" H 8000 4550 50  0001 C CNN
F 3 "" H 8000 4550 50  0001 C CNN
	1    8000 4550
	1    0    0    -1  
$EndComp
Text HLabel 7250 1350 0    50   Input ~ 0
A0
Text HLabel 7250 1550 0    50   Input ~ 0
A1
Text HLabel 7250 1800 0    50   Input ~ 0
A2
Text HLabel 7250 2000 0    50   Input ~ 0
A3
Text HLabel 7250 2250 0    50   Input ~ 0
A4
Text HLabel 7250 2450 0    50   Input ~ 0
A5
Text HLabel 7250 2700 0    50   Input ~ 0
A6
Text HLabel 7250 2900 0    50   Input ~ 0
A7
$Comp
L 74xx:74LS08 U?
U 2 1 5B078AB5
P 8400 1950
AR Path="/5ADF0E03/5B078AB5" Ref="U?"  Part="2" 
AR Path="/5B078AB5" Ref="U?"  Part="2" 
AR Path="/5AFDA122/5B078AB5" Ref="U33"  Part="2" 
F 0 "U33" H 8400 1950 50  0000 C CNN
F 1 "74LS08" H 8400 2184 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 8400 1950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 8400 1950 50  0001 C CNN
	2    8400 1950
	1    0    0    -1  
$EndComp
Text Notes 8150 1450 0    50   ~ 0
Note: AND gates from CLK spare parts
Wire Wire Line
	7850 1450 8100 1450
Wire Wire Line
	8100 1450 8100 1850
Wire Wire Line
	7850 1900 7850 2050
Wire Wire Line
	7850 2050 8100 2050
Wire Wire Line
	7850 2350 8100 2350
Wire Wire Line
	8100 2350 8100 2300
Wire Wire Line
	7850 2800 8100 2800
Wire Wire Line
	8100 2800 8100 2500
$Comp
L 74xx:74LS08 U?
U 4 1 5B08DA36
P 9150 2150
AR Path="/5ADF0E03/5B08DA36" Ref="U?"  Part="4" 
AR Path="/5B08DA36" Ref="U?"  Part="4" 
AR Path="/5AFDA122/5B08DA36" Ref="U33"  Part="4" 
F 0 "U33" H 9150 2150 50  0000 C CNN
F 1 "74LS08" H 9150 2384 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 9150 2150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 9150 2150 50  0001 C CNN
	4    9150 2150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS08 U?
U 3 1 5B078AD6
P 8400 2400
AR Path="/5ADF0E03/5B078AD6" Ref="U?"  Part="3" 
AR Path="/5B078AD6" Ref="U?"  Part="3" 
AR Path="/5AFDA122/5B078AD6" Ref="U33"  Part="3" 
F 0 "U33" H 8400 2400 50  0000 C CNN
F 1 "74LS08" H 8400 2634 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 8400 2400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 8400 2400 50  0001 C CNN
	3    8400 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 1950 8850 1950
Wire Wire Line
	8850 1950 8850 2050
Wire Wire Line
	8700 2400 8700 2250
Wire Wire Line
	8700 2250 8850 2250
Text HLabel 9450 2150 2    50   Input ~ 0
ZERO
$EndSCHEMATC
