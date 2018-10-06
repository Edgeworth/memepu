EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A2 23386 16535
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
Text HLabel 2900 1050 0    50   Input ~ 0
CARRY_IN
$Comp
L power:GND #PWR0147
U 1 1 5AFE6C21
P 3400 2350
F 0 "#PWR0147" H 3400 2100 50  0001 C CNN
F 1 "GND" H 3405 2177 50  0000 C CNN
F 2 "" H 3400 2350 50  0001 C CNN
F 3 "" H 3400 2350 50  0001 C CNN
	1    3400 2350
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0148
U 1 1 5AFE7002
P 3400 750
F 0 "#PWR0148" H 3400 600 50  0001 C CNN
F 1 "VCC" H 3417 923 50  0000 C CNN
F 2 "" H 3400 750 50  0001 C CNN
F 3 "" H 3400 750 50  0001 C CNN
	1    3400 750 
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS283 U14
U 1 1 5AFE82AE
P 3400 3650
F 0 "U14" H 3500 4350 50  0000 C CNN
F 1 "74LS283" H 3450 3400 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 3400 3650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS283" H 3400 3650 50  0001 C CNN
	1    3400 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0151
U 1 1 5AFE82EF
P 3400 4450
F 0 "#PWR0151" H 3400 4200 50  0001 C CNN
F 1 "GND" H 3405 4277 50  0000 C CNN
F 2 "" H 3400 4450 50  0001 C CNN
F 3 "" H 3400 4450 50  0001 C CNN
	1    3400 4450
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0152
U 1 1 5AFE82F5
P 3400 2850
F 0 "#PWR0152" H 3400 2700 50  0001 C CNN
F 1 "VCC" H 3417 3023 50  0000 C CNN
F 2 "" H 3400 2850 50  0001 C CNN
F 3 "" H 3400 2850 50  0001 C CNN
	1    3400 2850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0153
U 1 1 5AFEE097
P 3400 5050
F 0 "#PWR0153" H 3400 4900 50  0001 C CNN
F 1 "VCC" H 3417 5223 50  0000 C CNN
F 2 "" H 3400 5050 50  0001 C CNN
F 3 "" H 3400 5050 50  0001 C CNN
	1    3400 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0154
U 1 1 5AFEE39F
P 3400 6650
F 0 "#PWR0154" H 3400 6400 50  0001 C CNN
F 1 "GND" H 3405 6477 50  0000 C CNN
F 2 "" H 3400 6650 50  0001 C CNN
F 3 "" H 3400 6650 50  0001 C CNN
	1    3400 6650
	1    0    0    -1  
$EndComp
Text HLabel 2900 6350 0    50   Input ~ 0
~SUM_OUT
$Comp
L power:VCC #PWR0155
U 1 1 5AFEF7A6
P 2900 6250
F 0 "#PWR0155" H 2900 6100 50  0001 C CNN
F 1 "VCC" V 2918 6377 50  0000 L CNN
F 2 "" H 2900 6250 50  0001 C CNN
F 3 "" H 2900 6250 50  0001 C CNN
	1    2900 6250
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C23
U 1 1 5AFE6E12
P 3900 700
F 0 "C23" V 4000 700 50  0000 C CNN
F 1 "0.1uF" V 3750 700 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3900 700 50  0001 C CNN
F 3 "~" H 3900 700 50  0001 C CNN
	1    3900 700 
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C20
U 1 1 5AFE8488
P 3750 2850
F 0 "C20" V 3850 2850 50  0000 C CNN
F 1 "0.1uF" V 3600 2850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3750 2850 50  0001 C CNN
F 3 "~" H 3750 2850 50  0001 C CNN
	1    3750 2850
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C21
U 1 1 5AFE858C
P 3750 4900
F 0 "C21" V 3850 4900 50  0000 C CNN
F 1 "0.1uF" V 3600 4900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3750 4900 50  0001 C CNN
F 3 "~" H 3750 4900 50  0001 C CNN
	1    3750 4900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3400 5050 3550 5050
Wire Wire Line
	3550 5050 3550 4900
Wire Wire Line
	3550 4900 3650 4900
Wire Wire Line
	3400 750  3800 750 
Wire Wire Line
	3800 750  3800 700 
Wire Wire Line
	3400 2850 3650 2850
Connection ~ 3400 2850
$Comp
L power:GND #PWR0156
U 1 1 5AFEC01F
P 3850 2850
F 0 "#PWR0156" H 3850 2600 50  0001 C CNN
F 1 "GND" H 3855 2677 50  0000 C CNN
F 2 "" H 3850 2850 50  0001 C CNN
F 3 "" H 3850 2850 50  0001 C CNN
	1    3850 2850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0157
U 1 1 5AFEC38A
P 4000 700
F 0 "#PWR0157" H 4000 450 50  0001 C CNN
F 1 "GND" H 4005 527 50  0000 C CNN
F 2 "" H 4000 700 50  0001 C CNN
F 3 "" H 4000 700 50  0001 C CNN
	1    4000 700 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0158
U 1 1 5AFECB6E
P 3850 4900
F 0 "#PWR0158" H 3850 4650 50  0001 C CNN
F 1 "GND" H 3855 4727 50  0000 C CNN
F 2 "" H 3850 4900 50  0001 C CNN
F 3 "" H 3850 4900 50  0001 C CNN
	1    3850 4900
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74LS283 U11
U 1 1 5AFDA782
P 3400 1550
F 0 "U11" H 3500 2250 50  0000 C CNN
F 1 "74LS283" H 3450 1300 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 3400 1550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS283" H 3400 1550 50  0001 C CNN
	1    3400 1550
	1    0    0    -1  
$EndComp
Text Label 3900 1550 0    50   ~ 0
CARRY0
Text Label 2900 3150 2    50   ~ 0
CARRY0
Connection ~ 3400 5050
$Comp
L 74xx:74HC245 U16
U 1 1 5AFED6C1
P 3400 5850
F 0 "U16" H 3500 6500 50  0000 C CNN
F 1 "74HC245" H 3400 5550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 3400 5850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 3400 5850 50  0001 C CNN
	1    3400 5850
	1    0    0    -1  
$EndComp
Text Label 3900 3650 0    50   ~ 0
CARRY1
$Comp
L power:GND #PWR0159
U 1 1 5BA11C23
P 5400 2350
F 0 "#PWR0159" H 5400 2100 50  0001 C CNN
F 1 "GND" H 5405 2177 50  0000 C CNN
F 2 "" H 5400 2350 50  0001 C CNN
F 3 "" H 5400 2350 50  0001 C CNN
	1    5400 2350
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0160
U 1 1 5BA11C29
P 5400 750
F 0 "#PWR0160" H 5400 600 50  0001 C CNN
F 1 "VCC" H 5417 923 50  0000 C CNN
F 2 "" H 5400 750 50  0001 C CNN
F 3 "" H 5400 750 50  0001 C CNN
	1    5400 750 
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS283 U23
U 1 1 5BA11C2F
P 5400 3650
F 0 "U23" H 5500 4350 50  0000 C CNN
F 1 "74LS283" H 5450 3400 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 5400 3650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS283" H 5400 3650 50  0001 C CNN
	1    5400 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0161
U 1 1 5BA11C36
P 5400 4450
F 0 "#PWR0161" H 5400 4200 50  0001 C CNN
F 1 "GND" H 5405 4277 50  0000 C CNN
F 2 "" H 5400 4450 50  0001 C CNN
F 3 "" H 5400 4450 50  0001 C CNN
	1    5400 4450
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0162
U 1 1 5BA11C3C
P 5400 2850
F 0 "#PWR0162" H 5400 2700 50  0001 C CNN
F 1 "VCC" H 5417 3023 50  0000 C CNN
F 2 "" H 5400 2850 50  0001 C CNN
F 3 "" H 5400 2850 50  0001 C CNN
	1    5400 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C33
U 1 1 5BA11C42
P 5900 700
F 0 "C33" V 6000 700 50  0000 C CNN
F 1 "0.1uF" V 5750 700 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5900 700 50  0001 C CNN
F 3 "~" H 5900 700 50  0001 C CNN
	1    5900 700 
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C29
U 1 1 5BA11C49
P 5750 2850
F 0 "C29" V 5850 2850 50  0000 C CNN
F 1 "0.1uF" V 5600 2850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5750 2850 50  0001 C CNN
F 3 "~" H 5750 2850 50  0001 C CNN
	1    5750 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5400 750  5800 750 
Wire Wire Line
	5800 750  5800 700 
Wire Wire Line
	5400 2850 5650 2850
Connection ~ 5400 2850
$Comp
L power:GND #PWR0163
U 1 1 5BA11C54
P 5850 2850
F 0 "#PWR0163" H 5850 2600 50  0001 C CNN
F 1 "GND" H 5855 2677 50  0000 C CNN
F 2 "" H 5850 2850 50  0001 C CNN
F 3 "" H 5850 2850 50  0001 C CNN
	1    5850 2850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0164
U 1 1 5BA11C5A
P 6000 700
F 0 "#PWR0164" H 6000 450 50  0001 C CNN
F 1 "GND" H 6005 527 50  0000 C CNN
F 2 "" H 6000 700 50  0001 C CNN
F 3 "" H 6000 700 50  0001 C CNN
	1    6000 700 
	0    -1   -1   0   
$EndComp
Connection ~ 5400 750 
$Comp
L 74xx:74LS283 U22
U 1 1 5BA11C61
P 5400 1550
F 0 "U22" H 5500 2250 50  0000 C CNN
F 1 "74LS283" H 5450 1300 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 5400 1550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS283" H 5400 1550 50  0001 C CNN
	1    5400 1550
	1    0    0    -1  
$EndComp
Text Label 5900 1550 0    50   ~ 0
CARRY2
Text Label 5900 3650 0    50   ~ 0
CARRY3
Text Label 4900 1050 2    50   ~ 0
CARRY1
Text Label 4900 3150 2    50   ~ 0
CARRY2
$Comp
L power:GND #PWR0165
U 1 1 5BA12B02
P 7400 2350
F 0 "#PWR0165" H 7400 2100 50  0001 C CNN
F 1 "GND" H 7405 2177 50  0000 C CNN
F 2 "" H 7400 2350 50  0001 C CNN
F 3 "" H 7400 2350 50  0001 C CNN
	1    7400 2350
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0167
U 1 1 5BA12B08
P 7400 750
F 0 "#PWR0167" H 7400 600 50  0001 C CNN
F 1 "VCC" H 7417 923 50  0000 C CNN
F 2 "" H 7400 750 50  0001 C CNN
F 3 "" H 7400 750 50  0001 C CNN
	1    7400 750 
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS283 U28
U 1 1 5BA12B0E
P 7400 3650
F 0 "U28" H 7500 4350 50  0000 C CNN
F 1 "74LS283" H 7450 3400 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 7400 3650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS283" H 7400 3650 50  0001 C CNN
	1    7400 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0168
U 1 1 5BA12B15
P 7400 4450
F 0 "#PWR0168" H 7400 4200 50  0001 C CNN
F 1 "GND" H 7405 4277 50  0000 C CNN
F 2 "" H 7400 4450 50  0001 C CNN
F 3 "" H 7400 4450 50  0001 C CNN
	1    7400 4450
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0169
U 1 1 5BA12B1B
P 7400 2850
F 0 "#PWR0169" H 7400 2700 50  0001 C CNN
F 1 "VCC" H 7417 3023 50  0000 C CNN
F 2 "" H 7400 2850 50  0001 C CNN
F 3 "" H 7400 2850 50  0001 C CNN
	1    7400 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C42
U 1 1 5BA12B21
P 7900 700
F 0 "C42" V 8000 700 50  0000 C CNN
F 1 "0.1uF" V 7750 700 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7900 700 50  0001 C CNN
F 3 "~" H 7900 700 50  0001 C CNN
	1    7900 700 
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C35
U 1 1 5BA12B28
P 7750 2850
F 0 "C35" V 7850 2850 50  0000 C CNN
F 1 "0.1uF" V 7600 2850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7750 2850 50  0001 C CNN
F 3 "~" H 7750 2850 50  0001 C CNN
	1    7750 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7400 750  7800 750 
Wire Wire Line
	7800 750  7800 700 
Wire Wire Line
	7400 2850 7650 2850
Connection ~ 7400 2850
$Comp
L power:GND #PWR0170
U 1 1 5BA12B33
P 7850 2850
F 0 "#PWR0170" H 7850 2600 50  0001 C CNN
F 1 "GND" H 7855 2677 50  0000 C CNN
F 2 "" H 7850 2850 50  0001 C CNN
F 3 "" H 7850 2850 50  0001 C CNN
	1    7850 2850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0171
U 1 1 5BA12B39
P 8000 700
F 0 "#PWR0171" H 8000 450 50  0001 C CNN
F 1 "GND" H 8005 527 50  0000 C CNN
F 2 "" H 8000 700 50  0001 C CNN
F 3 "" H 8000 700 50  0001 C CNN
	1    8000 700 
	0    -1   -1   0   
$EndComp
Connection ~ 7400 750 
$Comp
L 74xx:74LS283 U27
U 1 1 5BA12B40
P 7400 1550
F 0 "U27" H 7500 2250 50  0000 C CNN
F 1 "74LS283" H 7450 1300 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 7400 1550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS283" H 7400 1550 50  0001 C CNN
	1    7400 1550
	1    0    0    -1  
$EndComp
Text Label 7900 1550 0    50   ~ 0
CARRY4
Text Label 7900 3650 0    50   ~ 0
CARRY5
$Comp
L power:GND #PWR0172
U 1 1 5BA12B4A
P 9400 2350
F 0 "#PWR0172" H 9400 2100 50  0001 C CNN
F 1 "GND" H 9405 2177 50  0000 C CNN
F 2 "" H 9400 2350 50  0001 C CNN
F 3 "" H 9400 2350 50  0001 C CNN
	1    9400 2350
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0173
U 1 1 5BA12B50
P 9400 750
F 0 "#PWR0173" H 9400 600 50  0001 C CNN
F 1 "VCC" H 9417 923 50  0000 C CNN
F 2 "" H 9400 750 50  0001 C CNN
F 3 "" H 9400 750 50  0001 C CNN
	1    9400 750 
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS283 U40
U 1 1 5BA12B56
P 9400 3650
F 0 "U40" H 9500 4350 50  0000 C CNN
F 1 "74LS283" H 9450 3400 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 9400 3650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS283" H 9400 3650 50  0001 C CNN
	1    9400 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0174
U 1 1 5BA12B5D
P 9400 4450
F 0 "#PWR0174" H 9400 4200 50  0001 C CNN
F 1 "GND" H 9405 4277 50  0000 C CNN
F 2 "" H 9400 4450 50  0001 C CNN
F 3 "" H 9400 4450 50  0001 C CNN
	1    9400 4450
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0175
U 1 1 5BA12B63
P 9400 2850
F 0 "#PWR0175" H 9400 2700 50  0001 C CNN
F 1 "VCC" H 9417 3023 50  0000 C CNN
F 2 "" H 9400 2850 50  0001 C CNN
F 3 "" H 9400 2850 50  0001 C CNN
	1    9400 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C50
U 1 1 5BA12B69
P 9900 700
F 0 "C50" V 10000 700 50  0000 C CNN
F 1 "0.1uF" V 9750 700 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9900 700 50  0001 C CNN
F 3 "~" H 9900 700 50  0001 C CNN
	1    9900 700 
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C47
U 1 1 5BA12B70
P 9750 2850
F 0 "C47" V 9850 2850 50  0000 C CNN
F 1 "0.1uF" V 9600 2850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9750 2850 50  0001 C CNN
F 3 "~" H 9750 2850 50  0001 C CNN
	1    9750 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9400 750  9800 750 
Wire Wire Line
	9800 750  9800 700 
Wire Wire Line
	9400 2850 9650 2850
Connection ~ 9400 2850
$Comp
L power:GND #PWR0177
U 1 1 5BA12B7B
P 9850 2850
F 0 "#PWR0177" H 9850 2600 50  0001 C CNN
F 1 "GND" H 9855 2677 50  0000 C CNN
F 2 "" H 9850 2850 50  0001 C CNN
F 3 "" H 9850 2850 50  0001 C CNN
	1    9850 2850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0178
U 1 1 5BA12B81
P 10000 700
F 0 "#PWR0178" H 10000 450 50  0001 C CNN
F 1 "GND" H 10005 527 50  0000 C CNN
F 2 "" H 10000 700 50  0001 C CNN
F 3 "" H 10000 700 50  0001 C CNN
	1    10000 700 
	0    -1   -1   0   
$EndComp
Connection ~ 9400 750 
$Comp
L 74xx:74LS283 U34
U 1 1 5BA12B88
P 9400 1550
F 0 "U34" H 9500 2250 50  0000 C CNN
F 1 "74LS283" H 9450 1300 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 9400 1550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS283" H 9400 1550 50  0001 C CNN
	1    9400 1550
	1    0    0    -1  
$EndComp
Text Label 9900 1550 0    50   ~ 0
CARRY6
$Comp
L power:VCC #PWR0184
U 1 1 5BA1384C
P 5400 5050
F 0 "#PWR0184" H 5400 4900 50  0001 C CNN
F 1 "VCC" H 5417 5223 50  0000 C CNN
F 2 "" H 5400 5050 50  0001 C CNN
F 3 "" H 5400 5050 50  0001 C CNN
	1    5400 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0185
U 1 1 5BA13852
P 5400 6650
F 0 "#PWR0185" H 5400 6400 50  0001 C CNN
F 1 "GND" H 5405 6477 50  0000 C CNN
F 2 "" H 5400 6650 50  0001 C CNN
F 3 "" H 5400 6650 50  0001 C CNN
	1    5400 6650
	1    0    0    -1  
$EndComp
Text HLabel 4900 6350 0    50   Input ~ 0
~SUM_OUT
$Comp
L power:VCC #PWR0186
U 1 1 5BA13859
P 4900 6250
F 0 "#PWR0186" H 4900 6100 50  0001 C CNN
F 1 "VCC" V 4918 6377 50  0000 L CNN
F 2 "" H 4900 6250 50  0001 C CNN
F 3 "" H 4900 6250 50  0001 C CNN
	1    4900 6250
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C30
U 1 1 5BA1385F
P 5750 4900
F 0 "C30" V 5850 4900 50  0000 C CNN
F 1 "0.1uF" V 5600 4900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5750 4900 50  0001 C CNN
F 3 "~" H 5750 4900 50  0001 C CNN
	1    5750 4900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5400 5050 5550 5050
Wire Wire Line
	5550 5050 5550 4900
Wire Wire Line
	5550 4900 5650 4900
$Comp
L power:GND #PWR0187
U 1 1 5BA13869
P 5850 4900
F 0 "#PWR0187" H 5850 4650 50  0001 C CNN
F 1 "GND" H 5855 4727 50  0000 C CNN
F 2 "" H 5850 4900 50  0001 C CNN
F 3 "" H 5850 4900 50  0001 C CNN
	1    5850 4900
	0    -1   -1   0   
$EndComp
Connection ~ 5400 5050
$Comp
L 74xx:74HC245 U24
U 1 1 5BA13870
P 5400 5850
F 0 "U24" H 5500 6500 50  0000 C CNN
F 1 "74HC245" H 5400 5550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 5400 5850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 5400 5850 50  0001 C CNN
	1    5400 5850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0188
U 1 1 5BA13A5F
P 7400 5050
F 0 "#PWR0188" H 7400 4900 50  0001 C CNN
F 1 "VCC" H 7417 5223 50  0000 C CNN
F 2 "" H 7400 5050 50  0001 C CNN
F 3 "" H 7400 5050 50  0001 C CNN
	1    7400 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0189
U 1 1 5BA13A65
P 7400 6650
F 0 "#PWR0189" H 7400 6400 50  0001 C CNN
F 1 "GND" H 7405 6477 50  0000 C CNN
F 2 "" H 7400 6650 50  0001 C CNN
F 3 "" H 7400 6650 50  0001 C CNN
	1    7400 6650
	1    0    0    -1  
$EndComp
Text HLabel 6900 6350 0    50   Input ~ 0
~SUM_OUT
$Comp
L power:VCC #PWR0190
U 1 1 5BA13A6C
P 6900 6250
F 0 "#PWR0190" H 6900 6100 50  0001 C CNN
F 1 "VCC" V 6918 6377 50  0000 L CNN
F 2 "" H 6900 6250 50  0001 C CNN
F 3 "" H 6900 6250 50  0001 C CNN
	1    6900 6250
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C36
U 1 1 5BA13A72
P 7750 4900
F 0 "C36" V 7850 4900 50  0000 C CNN
F 1 "0.1uF" V 7600 4900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7750 4900 50  0001 C CNN
F 3 "~" H 7750 4900 50  0001 C CNN
	1    7750 4900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7400 5050 7550 5050
Wire Wire Line
	7550 5050 7550 4900
Wire Wire Line
	7550 4900 7650 4900
$Comp
L power:GND #PWR0191
U 1 1 5BA13A7C
P 7850 4900
F 0 "#PWR0191" H 7850 4650 50  0001 C CNN
F 1 "GND" H 7855 4727 50  0000 C CNN
F 2 "" H 7850 4900 50  0001 C CNN
F 3 "" H 7850 4900 50  0001 C CNN
	1    7850 4900
	0    -1   -1   0   
$EndComp
Connection ~ 7400 5050
$Comp
L 74xx:74HC245 U29
U 1 1 5BA13A83
P 7400 5850
F 0 "U29" H 7500 6500 50  0000 C CNN
F 1 "74HC245" H 7400 5550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 7400 5850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 7400 5850 50  0001 C CNN
	1    7400 5850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0192
U 1 1 5BA13A8A
P 9400 5050
F 0 "#PWR0192" H 9400 4900 50  0001 C CNN
F 1 "VCC" H 9417 5223 50  0000 C CNN
F 2 "" H 9400 5050 50  0001 C CNN
F 3 "" H 9400 5050 50  0001 C CNN
	1    9400 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0193
U 1 1 5BA13A90
P 9400 6650
F 0 "#PWR0193" H 9400 6400 50  0001 C CNN
F 1 "GND" H 9405 6477 50  0000 C CNN
F 2 "" H 9400 6650 50  0001 C CNN
F 3 "" H 9400 6650 50  0001 C CNN
	1    9400 6650
	1    0    0    -1  
$EndComp
Text HLabel 8900 6350 0    50   Input ~ 0
~SUM_OUT
$Comp
L power:VCC #PWR0194
U 1 1 5BA13A97
P 8900 6250
F 0 "#PWR0194" H 8900 6100 50  0001 C CNN
F 1 "VCC" V 8918 6377 50  0000 L CNN
F 2 "" H 8900 6250 50  0001 C CNN
F 3 "" H 8900 6250 50  0001 C CNN
	1    8900 6250
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C48
U 1 1 5BA13A9D
P 9750 4900
F 0 "C48" V 9850 4900 50  0000 C CNN
F 1 "0.1uF" V 9600 4900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9750 4900 50  0001 C CNN
F 3 "~" H 9750 4900 50  0001 C CNN
	1    9750 4900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9400 5050 9550 5050
Wire Wire Line
	9550 5050 9550 4900
Wire Wire Line
	9550 4900 9650 4900
$Comp
L power:GND #PWR0195
U 1 1 5BA13AA7
P 9850 4900
F 0 "#PWR0195" H 9850 4650 50  0001 C CNN
F 1 "GND" H 9855 4727 50  0000 C CNN
F 2 "" H 9850 4900 50  0001 C CNN
F 3 "" H 9850 4900 50  0001 C CNN
	1    9850 4900
	0    -1   -1   0   
$EndComp
Connection ~ 9400 5050
$Comp
L 74xx:74HC245 U41
U 1 1 5BA13AAE
P 9400 5850
F 0 "U41" H 9500 6500 50  0000 C CNN
F 1 "74HC245" H 9400 5550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 9400 5850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 9400 5850 50  0001 C CNN
	1    9400 5850
	1    0    0    -1  
$EndComp
Text Label 6900 1050 2    50   ~ 0
CARRY3
Text Label 6900 3150 2    50   ~ 0
CARRY4
Text Label 8900 1050 2    50   ~ 0
CARRY5
Text Label 8900 3150 2    50   ~ 0
CARRY6
$Sheet
S 950  700  550  3600
U 5BA156D7
F0 "ALU0" 50
F1 "register.sch" 50
F2 "REG_IN" I L 950 4150 50 
F3 "I0" I L 950 800 50 
F4 "I1" I L 950 900 50 
F5 "I2" I L 950 1000 50 
F6 "I3" I L 950 1100 50 
F7 "I4" I L 950 1200 50 
F8 "I5" I L 950 1300 50 
F9 "I6" I L 950 1400 50 
F10 "I7" I L 950 1500 50 
F11 "~REG_OUT" I R 1500 4050 50 
F12 "O0" I R 1500 800 50 
F13 "O1" I R 1500 900 50 
F14 "O2" I R 1500 1000 50 
F15 "O3" I R 1500 1100 50 
F16 "O4" I R 1500 1200 50 
F17 "O5" I R 1500 1300 50 
F18 "O6" I R 1500 1400 50 
F19 "O7" I R 1500 1500 50 
F20 "I8" I L 950 1600 50 
F21 "I9" I L 950 1700 50 
F22 "I10" I L 950 1800 50 
F23 "I11" I L 950 1900 50 
F24 "I12" I L 950 2000 50 
F25 "I13" I L 950 2100 50 
F26 "I14" I L 950 2200 50 
F27 "I15" I L 950 2300 50 
F28 "I16" I L 950 2400 50 
F29 "I17" I L 950 2500 50 
F30 "I18" I L 950 2600 50 
F31 "I19" I L 950 2700 50 
F32 "I20" I L 950 2800 50 
F33 "I21" I L 950 2900 50 
F34 "I22" I L 950 3000 50 
F35 "I23" I L 950 3100 50 
F36 "I24" I L 950 3200 50 
F37 "I25" I L 950 3300 50 
F38 "I26" I L 950 3400 50 
F39 "I27" I L 950 3500 50 
F40 "I28" I L 950 3600 50 
F41 "I29" I L 950 3700 50 
F42 "I30" I L 950 3800 50 
F43 "I31" I L 950 3900 50 
F44 "O8" I R 1500 1600 50 
F45 "O9" I R 1500 1700 50 
F46 "O10" I R 1500 1800 50 
F47 "O11" I R 1500 1900 50 
F48 "O12" I R 1500 2000 50 
F49 "O13" I R 1500 2100 50 
F50 "O14" I R 1500 2200 50 
F51 "O15" I R 1500 2300 50 
F52 "O16" I R 1500 2400 50 
F53 "O17" I R 1500 2500 50 
F54 "O18" I R 1500 2600 50 
F55 "O19" I R 1500 2700 50 
F56 "O20" I R 1500 2800 50 
F57 "O21" I R 1500 2900 50 
F58 "O22" I R 1500 3000 50 
F59 "O23" I R 1500 3100 50 
F60 "O24" I R 1500 3200 50 
F61 "O25" I R 1500 3300 50 
F62 "O26" I R 1500 3400 50 
F63 "O27" I R 1500 3500 50 
F64 "O28" I R 1500 3600 50 
F65 "O29" I R 1500 3700 50 
F66 "O30" I R 1500 3800 50 
F67 "O31" I R 1500 3900 50 
$EndSheet
Text HLabel 950  800  0    50   Input ~ 0
BUS0
Text HLabel 950  900  0    50   Input ~ 0
BUS1
Text HLabel 950  1000 0    50   Input ~ 0
BUS2
Text HLabel 950  1100 0    50   Input ~ 0
BUS3
Text HLabel 950  1200 0    50   Input ~ 0
BUS4
Text HLabel 950  1300 0    50   Input ~ 0
BUS5
Text HLabel 950  1400 0    50   Input ~ 0
BUS6
Text HLabel 950  1500 0    50   Input ~ 0
BUS7
Text HLabel 950  4150 0    50   Input ~ 0
REG_ALU0_IN
Text HLabel 950  1600 0    50   Input ~ 0
BUS8
Text HLabel 950  1700 0    50   Input ~ 0
BUS9
Text HLabel 950  1800 0    50   Input ~ 0
BUS10
Text HLabel 950  1900 0    50   Input ~ 0
BUS11
Text HLabel 950  2000 0    50   Input ~ 0
BUS12
Text HLabel 950  2100 0    50   Input ~ 0
BUS13
Text HLabel 950  2200 0    50   Input ~ 0
BUS14
Text HLabel 950  2300 0    50   Input ~ 0
BUS15
Text HLabel 950  2400 0    50   Input ~ 0
BUS16
Text HLabel 950  2500 0    50   Input ~ 0
BUS17
Text HLabel 950  2600 0    50   Input ~ 0
BUS18
Text HLabel 950  2700 0    50   Input ~ 0
BUS19
Text HLabel 950  2800 0    50   Input ~ 0
BUS20
Text HLabel 950  2900 0    50   Input ~ 0
BUS21
Text HLabel 950  3000 0    50   Input ~ 0
BUS22
Text HLabel 950  3100 0    50   Input ~ 0
BUS23
Text HLabel 950  3200 0    50   Input ~ 0
BUS24
Text HLabel 950  3300 0    50   Input ~ 0
BUS25
Text HLabel 950  3400 0    50   Input ~ 0
BUS26
Text HLabel 950  3500 0    50   Input ~ 0
BUS27
Text HLabel 950  3600 0    50   Input ~ 0
BUS28
Text HLabel 950  3700 0    50   Input ~ 0
BUS29
Text HLabel 950  3800 0    50   Input ~ 0
BUS30
Text HLabel 950  3900 0    50   Input ~ 0
BUS31
$Comp
L power:GND #PWR0196
U 1 1 5BA15E85
P 1500 4050
F 0 "#PWR0196" H 1500 3800 50  0001 C CNN
F 1 "GND" V 1505 3922 50  0000 R CNN
F 2 "" H 1500 4050 50  0001 C CNN
F 3 "" H 1500 4050 50  0001 C CNN
	1    1500 4050
	0    -1   -1   0   
$EndComp
$Sheet
S 950  4500 550  3600
U 5BA16609
F0 "ALU1" 50
F1 "register.sch" 50
F2 "REG_IN" I L 950 7950 50 
F3 "I0" I L 950 4600 50 
F4 "I1" I L 950 4700 50 
F5 "I2" I L 950 4800 50 
F6 "I3" I L 950 4900 50 
F7 "I4" I L 950 5000 50 
F8 "I5" I L 950 5100 50 
F9 "I6" I L 950 5200 50 
F10 "I7" I L 950 5300 50 
F11 "~REG_OUT" I R 1500 7850 50 
F12 "O0" I R 1500 4600 50 
F13 "O1" I R 1500 4700 50 
F14 "O2" I R 1500 4800 50 
F15 "O3" I R 1500 4900 50 
F16 "O4" I R 1500 5000 50 
F17 "O5" I R 1500 5100 50 
F18 "O6" I R 1500 5200 50 
F19 "O7" I R 1500 5300 50 
F20 "I8" I L 950 5400 50 
F21 "I9" I L 950 5500 50 
F22 "I10" I L 950 5600 50 
F23 "I11" I L 950 5700 50 
F24 "I12" I L 950 5800 50 
F25 "I13" I L 950 5900 50 
F26 "I14" I L 950 6000 50 
F27 "I15" I L 950 6100 50 
F28 "I16" I L 950 6200 50 
F29 "I17" I L 950 6300 50 
F30 "I18" I L 950 6400 50 
F31 "I19" I L 950 6500 50 
F32 "I20" I L 950 6600 50 
F33 "I21" I L 950 6700 50 
F34 "I22" I L 950 6800 50 
F35 "I23" I L 950 6900 50 
F36 "I24" I L 950 7000 50 
F37 "I25" I L 950 7100 50 
F38 "I26" I L 950 7200 50 
F39 "I27" I L 950 7300 50 
F40 "I28" I L 950 7400 50 
F41 "I29" I L 950 7500 50 
F42 "I30" I L 950 7600 50 
F43 "I31" I L 950 7700 50 
F44 "O8" I R 1500 5400 50 
F45 "O9" I R 1500 5500 50 
F46 "O10" I R 1500 5600 50 
F47 "O11" I R 1500 5700 50 
F48 "O12" I R 1500 5800 50 
F49 "O13" I R 1500 5900 50 
F50 "O14" I R 1500 6000 50 
F51 "O15" I R 1500 6100 50 
F52 "O16" I R 1500 6200 50 
F53 "O17" I R 1500 6300 50 
F54 "O18" I R 1500 6400 50 
F55 "O19" I R 1500 6500 50 
F56 "O20" I R 1500 6600 50 
F57 "O21" I R 1500 6700 50 
F58 "O22" I R 1500 6800 50 
F59 "O23" I R 1500 6900 50 
F60 "O24" I R 1500 7000 50 
F61 "O25" I R 1500 7100 50 
F62 "O26" I R 1500 7200 50 
F63 "O27" I R 1500 7300 50 
F64 "O28" I R 1500 7400 50 
F65 "O29" I R 1500 7500 50 
F66 "O30" I R 1500 7600 50 
F67 "O31" I R 1500 7700 50 
$EndSheet
Text HLabel 950  4600 0    50   Input ~ 0
BUS0
Text HLabel 950  4700 0    50   Input ~ 0
BUS1
Text HLabel 950  4800 0    50   Input ~ 0
BUS2
Text HLabel 950  4900 0    50   Input ~ 0
BUS3
Text HLabel 950  5000 0    50   Input ~ 0
BUS4
Text HLabel 950  5100 0    50   Input ~ 0
BUS5
Text HLabel 950  5200 0    50   Input ~ 0
BUS6
Text HLabel 950  5300 0    50   Input ~ 0
BUS7
Text HLabel 950  7950 0    50   Input ~ 0
REG_ALU1_IN
Text HLabel 950  5400 0    50   Input ~ 0
BUS8
Text HLabel 950  5500 0    50   Input ~ 0
BUS9
Text HLabel 950  5600 0    50   Input ~ 0
BUS10
Text HLabel 950  5700 0    50   Input ~ 0
BUS11
Text HLabel 950  5800 0    50   Input ~ 0
BUS12
Text HLabel 950  5900 0    50   Input ~ 0
BUS13
Text HLabel 950  6000 0    50   Input ~ 0
BUS14
Text HLabel 950  6100 0    50   Input ~ 0
BUS15
Text HLabel 950  6200 0    50   Input ~ 0
BUS16
Text HLabel 950  6300 0    50   Input ~ 0
BUS17
Text HLabel 950  6400 0    50   Input ~ 0
BUS18
Text HLabel 950  6500 0    50   Input ~ 0
BUS19
Text HLabel 950  6600 0    50   Input ~ 0
BUS20
Text HLabel 950  6700 0    50   Input ~ 0
BUS21
Text HLabel 950  6800 0    50   Input ~ 0
BUS22
Text HLabel 950  6900 0    50   Input ~ 0
BUS23
Text HLabel 950  7000 0    50   Input ~ 0
BUS24
Text HLabel 950  7100 0    50   Input ~ 0
BUS25
Text HLabel 950  7200 0    50   Input ~ 0
BUS26
Text HLabel 950  7300 0    50   Input ~ 0
BUS27
Text HLabel 950  7400 0    50   Input ~ 0
BUS28
Text HLabel 950  7500 0    50   Input ~ 0
BUS29
Text HLabel 950  7600 0    50   Input ~ 0
BUS30
Text HLabel 950  7700 0    50   Input ~ 0
BUS31
$Comp
L power:GND #PWR0197
U 1 1 5BA16630
P 1500 7850
F 0 "#PWR0197" H 1500 7600 50  0001 C CNN
F 1 "GND" V 1505 7722 50  0000 R CNN
F 2 "" H 1500 7850 50  0001 C CNN
F 3 "" H 1500 7850 50  0001 C CNN
	1    1500 7850
	0    -1   -1   0   
$EndComp
Text Label 1500 800  0    50   ~ 0
A0
Text Label 1500 900  0    50   ~ 0
A1
Text Label 1500 1000 0    50   ~ 0
A2
Text Label 1500 1100 0    50   ~ 0
A3
Text Label 1500 1200 0    50   ~ 0
A4
Text Label 1500 1300 0    50   ~ 0
A5
Text Label 1500 1400 0    50   ~ 0
A6
Text Label 1500 1500 0    50   ~ 0
A7
Text Label 1500 1600 0    50   ~ 0
A8
Text Label 1500 1700 0    50   ~ 0
A9
Text Label 1500 1800 0    50   ~ 0
A10
Text Label 1500 1900 0    50   ~ 0
A11
Text Label 1500 2000 0    50   ~ 0
A12
Text Label 1500 2100 0    50   ~ 0
A13
Text Label 1500 2200 0    50   ~ 0
A14
Text Label 1500 2300 0    50   ~ 0
A15
Text Label 1500 2400 0    50   ~ 0
A16
Text Label 1500 2500 0    50   ~ 0
A17
Text Label 1500 2600 0    50   ~ 0
A18
Text Label 1500 2700 0    50   ~ 0
A19
Text Label 1500 2800 0    50   ~ 0
A20
Text Label 1500 2900 0    50   ~ 0
A21
Text Label 1500 3000 0    50   ~ 0
A22
Text Label 1500 3100 0    50   ~ 0
A23
Text Label 1500 3200 0    50   ~ 0
A24
Text Label 1500 3300 0    50   ~ 0
A25
Text Label 1500 3400 0    50   ~ 0
A26
Text Label 1500 3500 0    50   ~ 0
A27
Text Label 1500 3600 0    50   ~ 0
A28
Text Label 1500 3700 0    50   ~ 0
A29
Text Label 1500 3800 0    50   ~ 0
A30
Text Label 1500 3900 0    50   ~ 0
A31
Text Label 1500 4600 0    50   ~ 0
B0
Text Label 1500 4700 0    50   ~ 0
B1
Text Label 1500 4800 0    50   ~ 0
B2
Text Label 1500 4900 0    50   ~ 0
B3
Text Label 1500 5000 0    50   ~ 0
B4
Text Label 1500 5100 0    50   ~ 0
B5
Text Label 1500 5200 0    50   ~ 0
B6
Text Label 1500 5300 0    50   ~ 0
B7
Text Label 1500 5400 0    50   ~ 0
B8
Text Label 1500 5500 0    50   ~ 0
B9
Text Label 1500 5600 0    50   ~ 0
B10
Text Label 1500 5700 0    50   ~ 0
B11
Text Label 1500 5800 0    50   ~ 0
B12
Text Label 1500 5900 0    50   ~ 0
B13
Text Label 1500 6000 0    50   ~ 0
B14
Text Label 1500 6100 0    50   ~ 0
B15
Text Label 1500 6200 0    50   ~ 0
B16
Text Label 1500 6300 0    50   ~ 0
B17
Text Label 1500 6400 0    50   ~ 0
B18
Text Label 1500 6500 0    50   ~ 0
B19
Text Label 1500 6600 0    50   ~ 0
B20
Text Label 1500 6700 0    50   ~ 0
B21
Text Label 1500 6800 0    50   ~ 0
B22
Text Label 1500 6900 0    50   ~ 0
B23
Text Label 1500 7000 0    50   ~ 0
B24
Text Label 1500 7100 0    50   ~ 0
B25
Text Label 1500 7200 0    50   ~ 0
B26
Text Label 1500 7300 0    50   ~ 0
B27
Text Label 1500 7400 0    50   ~ 0
B28
Text Label 1500 7500 0    50   ~ 0
B29
Text Label 1500 7600 0    50   ~ 0
B30
Text Label 1500 7700 0    50   ~ 0
B31
Text Label 2900 1750 2    50   ~ 0
B0
Text Label 2900 1850 2    50   ~ 0
B1
Text Label 2900 1950 2    50   ~ 0
B2
Text Label 2900 2050 2    50   ~ 0
B3
Connection ~ 3400 750 
Text Label 2900 3850 2    50   ~ 0
B4
Text Label 2900 3950 2    50   ~ 0
B5
Text Label 2900 4050 2    50   ~ 0
B6
Text Label 2900 4150 2    50   ~ 0
B7
Text Label 4900 1750 2    50   ~ 0
B8
Text Label 4900 1850 2    50   ~ 0
B9
Text Label 4900 1950 2    50   ~ 0
B10
Text Label 4900 2050 2    50   ~ 0
B11
Text Label 4900 3850 2    50   ~ 0
B12
Text Label 4900 3950 2    50   ~ 0
B13
Text Label 4900 4050 2    50   ~ 0
B14
Text Label 4900 4150 2    50   ~ 0
B15
Text Label 6900 1750 2    50   ~ 0
B16
Text Label 6900 1850 2    50   ~ 0
B17
Text Label 6900 1950 2    50   ~ 0
B18
Text Label 6900 2050 2    50   ~ 0
B19
Text Label 6900 3850 2    50   ~ 0
B20
Text Label 6900 3950 2    50   ~ 0
B21
Text Label 6900 4050 2    50   ~ 0
B22
Text Label 6900 4150 2    50   ~ 0
B23
Text Label 8900 1750 2    50   ~ 0
B24
Text Label 8900 1850 2    50   ~ 0
B25
Text Label 8900 1950 2    50   ~ 0
B26
Text Label 8900 2050 2    50   ~ 0
B27
Text Label 8900 3850 2    50   ~ 0
B28
Text Label 8900 3950 2    50   ~ 0
B29
Text Label 8900 4050 2    50   ~ 0
B30
Text Label 8900 4150 2    50   ~ 0
B31
Text Label 2900 1250 2    50   ~ 0
A0
Text Label 2900 1350 2    50   ~ 0
A1
Text Label 2900 1450 2    50   ~ 0
A2
Text Label 2900 1550 2    50   ~ 0
A3
Text Label 2900 3350 2    50   ~ 0
A4
Text Label 2900 3450 2    50   ~ 0
A5
Text Label 2900 3550 2    50   ~ 0
A6
Text Label 2900 3650 2    50   ~ 0
A7
Text Label 4900 1250 2    50   ~ 0
A8
Text Label 4900 1350 2    50   ~ 0
A9
Text Label 4900 1450 2    50   ~ 0
A10
Text Label 4900 1550 2    50   ~ 0
A11
Text Label 4900 3350 2    50   ~ 0
A12
Text Label 4900 3450 2    50   ~ 0
A13
Text Label 4900 3550 2    50   ~ 0
A14
Text Label 4900 3650 2    50   ~ 0
A15
Text Label 6900 1250 2    50   ~ 0
A16
Text Label 6900 1350 2    50   ~ 0
A17
Text Label 6900 1450 2    50   ~ 0
A18
Text Label 6900 1550 2    50   ~ 0
A19
Text Label 6900 3350 2    50   ~ 0
A20
Text Label 6900 3450 2    50   ~ 0
A21
Text Label 6900 3550 2    50   ~ 0
A22
Text Label 6900 3650 2    50   ~ 0
A23
Text Label 8900 1250 2    50   ~ 0
A24
Text Label 8900 1350 2    50   ~ 0
A25
Text Label 8900 1450 2    50   ~ 0
A26
Text Label 8900 1550 2    50   ~ 0
A27
Text Label 8900 3350 2    50   ~ 0
A28
Text Label 8900 3450 2    50   ~ 0
A29
Text Label 8900 3550 2    50   ~ 0
A30
Text Label 8900 3650 2    50   ~ 0
A31
Text Label 3900 1050 0    50   ~ 0
SUM0
Text Label 3900 1150 0    50   ~ 0
SUM1
Text Label 3900 1250 0    50   ~ 0
SUM2
Text Label 3900 1350 0    50   ~ 0
SUM3
Text Label 3900 3150 0    50   ~ 0
SUM4
Text Label 3900 3250 0    50   ~ 0
SUM5
Text Label 3900 3350 0    50   ~ 0
SUM6
Text Label 3900 3450 0    50   ~ 0
SUM7
Text Label 5900 1050 0    50   ~ 0
SUM8
Text Label 5900 1150 0    50   ~ 0
SUM9
Text Label 5900 1250 0    50   ~ 0
SUM10
Text Label 5900 1350 0    50   ~ 0
SUM11
Text Label 5900 3150 0    50   ~ 0
SUM12
Text Label 5900 3250 0    50   ~ 0
SUM13
Text Label 5900 3350 0    50   ~ 0
SUM14
Text Label 5900 3450 0    50   ~ 0
SUM15
Text Label 7900 1050 0    50   ~ 0
SUM16
Text Label 7900 1150 0    50   ~ 0
SUM17
Text Label 7900 1250 0    50   ~ 0
SUM18
Text Label 7900 1350 0    50   ~ 0
SUM19
Text Label 7900 3150 0    50   ~ 0
SUM20
Text Label 7900 3250 0    50   ~ 0
SUM21
Text Label 7900 3350 0    50   ~ 0
SUM22
Text Label 7900 3450 0    50   ~ 0
SUM23
Text Label 9900 1050 0    50   ~ 0
SUM24
Text Label 9900 1150 0    50   ~ 0
SUM25
Text Label 9900 1250 0    50   ~ 0
SUM26
Text Label 9900 1350 0    50   ~ 0
SUM27
Text Label 9900 3150 0    50   ~ 0
SUM28
Text Label 9900 3250 0    50   ~ 0
SUM29
Text Label 9900 3350 0    50   ~ 0
SUM30
Text Label 9900 3450 0    50   ~ 0
SUM31
Text Label 2900 5350 2    50   ~ 0
SUM0
Text Label 2900 5450 2    50   ~ 0
SUM1
Text Label 2900 5550 2    50   ~ 0
SUM2
Text Label 2900 5650 2    50   ~ 0
SUM3
Text Label 2900 5750 2    50   ~ 0
SUM4
Text Label 2900 5850 2    50   ~ 0
SUM5
Text Label 2900 5950 2    50   ~ 0
SUM6
Text Label 2900 6050 2    50   ~ 0
SUM7
Text Label 4900 5350 2    50   ~ 0
SUM8
Text Label 4900 5450 2    50   ~ 0
SUM9
Text Label 4900 5550 2    50   ~ 0
SUM10
Text Label 4900 5650 2    50   ~ 0
SUM11
Text Label 4900 5750 2    50   ~ 0
SUM12
Text Label 4900 5850 2    50   ~ 0
SUM13
Text Label 4900 5950 2    50   ~ 0
SUM14
Text Label 4900 6050 2    50   ~ 0
SUM15
Text Label 6900 5350 2    50   ~ 0
SUM16
Text Label 6900 5450 2    50   ~ 0
SUM17
Text Label 6900 5550 2    50   ~ 0
SUM18
Text Label 6900 5650 2    50   ~ 0
SUM19
Text Label 6900 5750 2    50   ~ 0
SUM20
Text Label 6900 5850 2    50   ~ 0
SUM21
Text Label 6900 5950 2    50   ~ 0
SUM22
Text Label 6900 6050 2    50   ~ 0
SUM23
Text Label 8900 5350 2    50   ~ 0
SUM24
Text Label 8900 5450 2    50   ~ 0
SUM25
Text Label 8900 5550 2    50   ~ 0
SUM26
Text Label 8900 5650 2    50   ~ 0
SUM27
Text Label 8900 5750 2    50   ~ 0
SUM28
Text Label 8900 5850 2    50   ~ 0
SUM29
Text Label 8900 5950 2    50   ~ 0
SUM30
Text Label 8900 6050 2    50   ~ 0
SUM31
Text HLabel 3900 5350 2    50   Input ~ 0
BUS0
Text HLabel 3900 5450 2    50   Input ~ 0
BUS1
Text HLabel 3900 5550 2    50   Input ~ 0
BUS2
Text HLabel 3900 5650 2    50   Input ~ 0
BUS3
Text HLabel 3900 5750 2    50   Input ~ 0
BUS4
Text HLabel 3900 5850 2    50   Input ~ 0
BUS5
Text HLabel 3900 5950 2    50   Input ~ 0
BUS6
Text HLabel 3900 6050 2    50   Input ~ 0
BUS7
Text HLabel 5900 5350 2    50   Input ~ 0
BUS8
Text HLabel 5900 5450 2    50   Input ~ 0
BUS9
Text HLabel 5900 5550 2    50   Input ~ 0
BUS10
Text HLabel 5900 5650 2    50   Input ~ 0
BUS11
Text HLabel 5900 5750 2    50   Input ~ 0
BUS12
Text HLabel 5900 5850 2    50   Input ~ 0
BUS13
Text HLabel 5900 5950 2    50   Input ~ 0
BUS14
Text HLabel 5900 6050 2    50   Input ~ 0
BUS15
Text HLabel 7900 5350 2    50   Input ~ 0
BUS16
Text HLabel 7900 5450 2    50   Input ~ 0
BUS17
Text HLabel 7900 5550 2    50   Input ~ 0
BUS18
Text HLabel 7900 5650 2    50   Input ~ 0
BUS19
Text HLabel 7900 5750 2    50   Input ~ 0
BUS20
Text HLabel 7900 5850 2    50   Input ~ 0
BUS21
Text HLabel 7900 5950 2    50   Input ~ 0
BUS22
Text HLabel 7900 6050 2    50   Input ~ 0
BUS23
Text HLabel 9900 5350 2    50   Input ~ 0
BUS24
Text HLabel 9900 5450 2    50   Input ~ 0
BUS25
Text HLabel 9900 5550 2    50   Input ~ 0
BUS26
Text HLabel 9900 5650 2    50   Input ~ 0
BUS27
Text HLabel 9900 5750 2    50   Input ~ 0
BUS28
Text HLabel 9900 5850 2    50   Input ~ 0
BUS29
Text HLabel 9900 5950 2    50   Input ~ 0
BUS30
Text HLabel 9900 6050 2    50   Input ~ 0
BUS31
$Comp
L 74xx:74HC00 U21
U 1 1 5BA2441F
P 3450 7900
F 0 "U21" H 3450 8225 50  0000 C CNN
F 1 "74HC00" H 3450 8134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 3450 7900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 3450 7900 50  0001 C CNN
	1    3450 7900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U21
U 2 1 5BA2465E
P 3450 8450
F 0 "U21" H 3450 8775 50  0000 C CNN
F 1 "74HC00" H 3450 8684 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 3450 8450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 3450 8450 50  0001 C CNN
	2    3450 8450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U21
U 3 1 5BA24721
P 3450 9000
F 0 "U21" H 3450 9325 50  0000 C CNN
F 1 "74HC00" H 3450 9234 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 3450 9000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 3450 9000 50  0001 C CNN
	3    3450 9000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U21
U 4 1 5BA247A5
P 3450 9550
F 0 "U21" H 3450 9875 50  0000 C CNN
F 1 "74HC00" H 3450 9784 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 3450 9550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 3450 9550 50  0001 C CNN
	4    3450 9550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U21
U 5 1 5BA2482C
P 3450 10350
F 0 "U21" V 3083 10350 50  0000 C CNN
F 1 "74HC00" V 3174 10350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 3450 10350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 3450 10350 50  0001 C CNN
	5    3450 10350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0198
U 1 1 5BA24CC9
P 2950 10350
F 0 "#PWR0198" H 2950 10100 50  0001 C CNN
F 1 "GND" V 2955 10222 50  0000 R CNN
F 2 "" H 2950 10350 50  0001 C CNN
F 3 "" H 2950 10350 50  0001 C CNN
	1    2950 10350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C26
U 1 1 5BA257C0
P 4050 10350
F 0 "C26" V 4150 10350 50  0000 C CNN
F 1 "0.1uF" V 3900 10350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4050 10350 50  0001 C CNN
F 3 "~" H 4050 10350 50  0001 C CNN
	1    4050 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0199
U 1 1 5BA257C7
P 4150 10350
F 0 "#PWR0199" H 4150 10100 50  0001 C CNN
F 1 "GND" H 4155 10177 50  0000 C CNN
F 2 "" H 4150 10350 50  0001 C CNN
F 3 "" H 4150 10350 50  0001 C CNN
	1    4150 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0200
U 1 1 5BA2615B
P 3950 10350
F 0 "#PWR0200" H 3950 10200 50  0001 C CNN
F 1 "VCC" H 3967 10523 50  0000 C CNN
F 2 "" H 3950 10350 50  0001 C CNN
F 3 "" H 3950 10350 50  0001 C CNN
	1    3950 10350
	1    0    0    -1  
$EndComp
Connection ~ 3950 10350
$Comp
L power:VCC #PWR0201
U 1 1 5BA2A869
P 3400 11050
F 0 "#PWR0201" H 3400 10900 50  0001 C CNN
F 1 "VCC" H 3417 11223 50  0000 C CNN
F 2 "" H 3400 11050 50  0001 C CNN
F 3 "" H 3400 11050 50  0001 C CNN
	1    3400 11050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0202
U 1 1 5BA2A86F
P 3400 12650
F 0 "#PWR0202" H 3400 12400 50  0001 C CNN
F 1 "GND" H 3405 12477 50  0000 C CNN
F 2 "" H 3400 12650 50  0001 C CNN
F 3 "" H 3400 12650 50  0001 C CNN
	1    3400 12650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0203
U 1 1 5BA2A876
P 2900 12250
F 0 "#PWR0203" H 2900 12100 50  0001 C CNN
F 1 "VCC" V 2918 12377 50  0000 L CNN
F 2 "" H 2900 12250 50  0001 C CNN
F 3 "" H 2900 12250 50  0001 C CNN
	1    2900 12250
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C22
U 1 1 5BA2A87C
P 3750 10900
F 0 "C22" V 3850 10900 50  0000 C CNN
F 1 "0.1uF" V 3600 10900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3750 10900 50  0001 C CNN
F 3 "~" H 3750 10900 50  0001 C CNN
	1    3750 10900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3400 11050 3550 11050
Wire Wire Line
	3550 11050 3550 10900
Wire Wire Line
	3550 10900 3650 10900
$Comp
L power:GND #PWR0204
U 1 1 5BA2A886
P 3850 10900
F 0 "#PWR0204" H 3850 10650 50  0001 C CNN
F 1 "GND" H 3855 10727 50  0000 C CNN
F 2 "" H 3850 10900 50  0001 C CNN
F 3 "" H 3850 10900 50  0001 C CNN
	1    3850 10900
	0    -1   -1   0   
$EndComp
Connection ~ 3400 11050
$Comp
L 74xx:74HC245 U18
U 1 1 5BA2A88D
P 3400 11850
F 0 "U18" H 3500 12500 50  0000 C CNN
F 1 "74HC245" H 3400 11550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 3400 11850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 3400 11850 50  0001 C CNN
	1    3400 11850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0205
U 1 1 5BA2A894
P 5400 11050
F 0 "#PWR0205" H 5400 10900 50  0001 C CNN
F 1 "VCC" H 5417 11223 50  0000 C CNN
F 2 "" H 5400 11050 50  0001 C CNN
F 3 "" H 5400 11050 50  0001 C CNN
	1    5400 11050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0206
U 1 1 5BA2A89A
P 5400 12650
F 0 "#PWR0206" H 5400 12400 50  0001 C CNN
F 1 "GND" H 5405 12477 50  0000 C CNN
F 2 "" H 5400 12650 50  0001 C CNN
F 3 "" H 5400 12650 50  0001 C CNN
	1    5400 12650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0207
U 1 1 5BA2A8A1
P 4900 12250
F 0 "#PWR0207" H 4900 12100 50  0001 C CNN
F 1 "VCC" V 4918 12377 50  0000 L CNN
F 2 "" H 4900 12250 50  0001 C CNN
F 3 "" H 4900 12250 50  0001 C CNN
	1    4900 12250
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C32
U 1 1 5BA2A8A7
P 5750 10900
F 0 "C32" V 5850 10900 50  0000 C CNN
F 1 "0.1uF" V 5600 10900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5750 10900 50  0001 C CNN
F 3 "~" H 5750 10900 50  0001 C CNN
	1    5750 10900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5400 11050 5550 11050
Wire Wire Line
	5550 11050 5550 10900
Wire Wire Line
	5550 10900 5650 10900
$Comp
L power:GND #PWR0208
U 1 1 5BA2A8B1
P 5850 10900
F 0 "#PWR0208" H 5850 10650 50  0001 C CNN
F 1 "GND" H 5855 10727 50  0000 C CNN
F 2 "" H 5850 10900 50  0001 C CNN
F 3 "" H 5850 10900 50  0001 C CNN
	1    5850 10900
	0    -1   -1   0   
$EndComp
Connection ~ 5400 11050
$Comp
L 74xx:74HC245 U25
U 1 1 5BA2A8B8
P 5400 11850
F 0 "U25" H 5500 12500 50  0000 C CNN
F 1 "74HC245" H 5400 11550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 5400 11850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 5400 11850 50  0001 C CNN
	1    5400 11850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0209
U 1 1 5BA2A8BF
P 7400 11050
F 0 "#PWR0209" H 7400 10900 50  0001 C CNN
F 1 "VCC" H 7417 11223 50  0000 C CNN
F 2 "" H 7400 11050 50  0001 C CNN
F 3 "" H 7400 11050 50  0001 C CNN
	1    7400 11050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0210
U 1 1 5BA2A8C5
P 7400 12650
F 0 "#PWR0210" H 7400 12400 50  0001 C CNN
F 1 "GND" H 7405 12477 50  0000 C CNN
F 2 "" H 7400 12650 50  0001 C CNN
F 3 "" H 7400 12650 50  0001 C CNN
	1    7400 12650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0211
U 1 1 5BA2A8CC
P 6900 12250
F 0 "#PWR0211" H 6900 12100 50  0001 C CNN
F 1 "VCC" V 6918 12377 50  0000 L CNN
F 2 "" H 6900 12250 50  0001 C CNN
F 3 "" H 6900 12250 50  0001 C CNN
	1    6900 12250
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C38
U 1 1 5BA2A8D2
P 7750 10900
F 0 "C38" V 7850 10900 50  0000 C CNN
F 1 "0.1uF" V 7600 10900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7750 10900 50  0001 C CNN
F 3 "~" H 7750 10900 50  0001 C CNN
	1    7750 10900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7400 11050 7550 11050
Wire Wire Line
	7550 11050 7550 10900
Wire Wire Line
	7550 10900 7650 10900
$Comp
L power:GND #PWR0212
U 1 1 5BA2A8DC
P 7850 10900
F 0 "#PWR0212" H 7850 10650 50  0001 C CNN
F 1 "GND" H 7855 10727 50  0000 C CNN
F 2 "" H 7850 10900 50  0001 C CNN
F 3 "" H 7850 10900 50  0001 C CNN
	1    7850 10900
	0    -1   -1   0   
$EndComp
Connection ~ 7400 11050
$Comp
L 74xx:74HC245 U31
U 1 1 5BA2A8E3
P 7400 11850
F 0 "U31" H 7500 12500 50  0000 C CNN
F 1 "74HC245" H 7400 11550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 7400 11850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 7400 11850 50  0001 C CNN
	1    7400 11850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0213
U 1 1 5BA2A8EA
P 9400 11050
F 0 "#PWR0213" H 9400 10900 50  0001 C CNN
F 1 "VCC" H 9417 11223 50  0000 C CNN
F 2 "" H 9400 11050 50  0001 C CNN
F 3 "" H 9400 11050 50  0001 C CNN
	1    9400 11050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0214
U 1 1 5BA2A8F0
P 9400 12650
F 0 "#PWR0214" H 9400 12400 50  0001 C CNN
F 1 "GND" H 9405 12477 50  0000 C CNN
F 2 "" H 9400 12650 50  0001 C CNN
F 3 "" H 9400 12650 50  0001 C CNN
	1    9400 12650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0215
U 1 1 5BA2A8F7
P 8900 12250
F 0 "#PWR0215" H 8900 12100 50  0001 C CNN
F 1 "VCC" V 8918 12377 50  0000 L CNN
F 2 "" H 8900 12250 50  0001 C CNN
F 3 "" H 8900 12250 50  0001 C CNN
	1    8900 12250
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C49
U 1 1 5BA2A8FD
P 9750 10900
F 0 "C49" V 9850 10900 50  0000 C CNN
F 1 "0.1uF" V 9600 10900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9750 10900 50  0001 C CNN
F 3 "~" H 9750 10900 50  0001 C CNN
	1    9750 10900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9400 11050 9550 11050
Wire Wire Line
	9550 11050 9550 10900
Wire Wire Line
	9550 10900 9650 10900
$Comp
L power:GND #PWR0216
U 1 1 5BA2A907
P 9850 10900
F 0 "#PWR0216" H 9850 10650 50  0001 C CNN
F 1 "GND" H 9855 10727 50  0000 C CNN
F 2 "" H 9850 10900 50  0001 C CNN
F 3 "" H 9850 10900 50  0001 C CNN
	1    9850 10900
	0    -1   -1   0   
$EndComp
Connection ~ 9400 11050
$Comp
L 74xx:74HC245 U42
U 1 1 5BA2A90E
P 9400 11850
F 0 "U42" H 9500 12500 50  0000 C CNN
F 1 "74HC245" H 9400 11550 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 9400 11850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 9400 11850 50  0001 C CNN
	1    9400 11850
	1    0    0    -1  
$EndComp
Text HLabel 3900 11350 2    50   Input ~ 0
BUS0
Text HLabel 3900 11450 2    50   Input ~ 0
BUS1
Text HLabel 3900 11550 2    50   Input ~ 0
BUS2
Text HLabel 3900 11650 2    50   Input ~ 0
BUS3
Text HLabel 3900 11750 2    50   Input ~ 0
BUS4
Text HLabel 3900 11850 2    50   Input ~ 0
BUS5
Text HLabel 3900 11950 2    50   Input ~ 0
BUS6
Text HLabel 3900 12050 2    50   Input ~ 0
BUS7
Text HLabel 5900 11350 2    50   Input ~ 0
BUS8
Text HLabel 5900 11450 2    50   Input ~ 0
BUS9
Text HLabel 5900 11550 2    50   Input ~ 0
BUS10
Text HLabel 5900 11650 2    50   Input ~ 0
BUS11
Text HLabel 5900 11750 2    50   Input ~ 0
BUS12
Text HLabel 5900 11850 2    50   Input ~ 0
BUS13
Text HLabel 5900 11950 2    50   Input ~ 0
BUS14
Text HLabel 5900 12050 2    50   Input ~ 0
BUS15
Text HLabel 7900 11350 2    50   Input ~ 0
BUS16
Text HLabel 7900 11450 2    50   Input ~ 0
BUS17
Text HLabel 7900 11550 2    50   Input ~ 0
BUS18
Text HLabel 7900 11650 2    50   Input ~ 0
BUS19
Text HLabel 7900 11750 2    50   Input ~ 0
BUS20
Text HLabel 7900 11850 2    50   Input ~ 0
BUS21
Text HLabel 7900 11950 2    50   Input ~ 0
BUS22
Text HLabel 7900 12050 2    50   Input ~ 0
BUS23
Text HLabel 9900 11350 2    50   Input ~ 0
BUS24
Text HLabel 9900 11450 2    50   Input ~ 0
BUS25
Text HLabel 9900 11550 2    50   Input ~ 0
BUS26
Text HLabel 9900 11650 2    50   Input ~ 0
BUS27
Text HLabel 9900 11750 2    50   Input ~ 0
BUS28
Text HLabel 9900 11850 2    50   Input ~ 0
BUS29
Text HLabel 9900 11950 2    50   Input ~ 0
BUS30
Text HLabel 9900 12050 2    50   Input ~ 0
BUS31
Text Label 2900 11350 2    50   ~ 0
NAND0
Text Label 2900 11450 2    50   ~ 0
NAND1
Text Label 2900 11550 2    50   ~ 0
NAND2
Text Label 2900 11650 2    50   ~ 0
NAND3
Text Label 2900 11750 2    50   ~ 0
NAND4
Text Label 2900 11850 2    50   ~ 0
NAND5
Text Label 2900 11950 2    50   ~ 0
NAND6
Text Label 2900 12050 2    50   ~ 0
NAND7
Text Label 4900 11350 2    50   ~ 0
NAND8
Text Label 4900 11450 2    50   ~ 0
NAND9
Text Label 4900 11550 2    50   ~ 0
NAND10
Text Label 4900 11650 2    50   ~ 0
NAND11
Text Label 4900 11750 2    50   ~ 0
NAND12
Text Label 4900 11850 2    50   ~ 0
NAND13
Text Label 4900 11950 2    50   ~ 0
NAND14
Text Label 4900 12050 2    50   ~ 0
NAND15
Text Label 6900 11350 2    50   ~ 0
NAND16
Text Label 6900 11450 2    50   ~ 0
NAND17
Text Label 6900 11550 2    50   ~ 0
NAND18
Text Label 6900 11650 2    50   ~ 0
NAND19
Text Label 6900 11750 2    50   ~ 0
NAND20
Text Label 6900 11850 2    50   ~ 0
NAND21
Text Label 6900 11950 2    50   ~ 0
NAND22
Text Label 6900 12050 2    50   ~ 0
NAND23
Text Label 8900 11350 2    50   ~ 0
NAND24
Text Label 8900 11450 2    50   ~ 0
NAND25
Text Label 8900 11550 2    50   ~ 0
NAND26
Text Label 8900 11650 2    50   ~ 0
NAND27
Text Label 8900 11750 2    50   ~ 0
NAND28
Text Label 8900 11850 2    50   ~ 0
NAND29
Text Label 8900 11950 2    50   ~ 0
NAND30
Text Label 8900 12050 2    50   ~ 0
NAND31
Text HLabel 2900 12350 0    50   Input ~ 0
~NAND_OUT
Text HLabel 4900 12350 0    50   Input ~ 0
~NAND_OUT
Text HLabel 6900 12350 0    50   Input ~ 0
~NAND_OUT
Text HLabel 8900 12350 0    50   Input ~ 0
~NAND_OUT
Text Label 3150 7800 2    50   ~ 0
A0
Text Label 3150 8000 2    50   ~ 0
B0
Text Label 3150 8350 2    50   ~ 0
A1
Text Label 3150 8550 2    50   ~ 0
B1
Text Label 3150 8900 2    50   ~ 0
A2
Text Label 3150 9100 2    50   ~ 0
B2
Text Label 3150 9450 2    50   ~ 0
A3
Text Label 3150 9650 2    50   ~ 0
B3
$Comp
L 74xx:74HC00 U26
U 1 1 5BA33977
P 5450 7900
F 0 "U26" H 5450 8225 50  0000 C CNN
F 1 "74HC00" H 5450 8134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5450 7900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 5450 7900 50  0001 C CNN
	1    5450 7900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U26
U 2 1 5BA3397E
P 5450 8450
F 0 "U26" H 5450 8775 50  0000 C CNN
F 1 "74HC00" H 5450 8684 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5450 8450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 5450 8450 50  0001 C CNN
	2    5450 8450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U26
U 3 1 5BA33985
P 5450 9000
F 0 "U26" H 5450 9325 50  0000 C CNN
F 1 "74HC00" H 5450 9234 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5450 9000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 5450 9000 50  0001 C CNN
	3    5450 9000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U26
U 4 1 5BA3398C
P 5450 9550
F 0 "U26" H 5450 9875 50  0000 C CNN
F 1 "74HC00" H 5450 9784 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5450 9550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 5450 9550 50  0001 C CNN
	4    5450 9550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U26
U 5 1 5BA33993
P 5450 10350
F 0 "U26" V 5083 10350 50  0000 C CNN
F 1 "74HC00" V 5174 10350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5450 10350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 5450 10350 50  0001 C CNN
	5    5450 10350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0220
U 1 1 5BA3399A
P 4950 10350
F 0 "#PWR0220" H 4950 10100 50  0001 C CNN
F 1 "GND" V 4955 10222 50  0000 R CNN
F 2 "" H 4950 10350 50  0001 C CNN
F 3 "" H 4950 10350 50  0001 C CNN
	1    4950 10350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C34
U 1 1 5BA339A0
P 6050 10350
F 0 "C34" V 6150 10350 50  0000 C CNN
F 1 "0.1uF" V 5900 10350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6050 10350 50  0001 C CNN
F 3 "~" H 6050 10350 50  0001 C CNN
	1    6050 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0221
U 1 1 5BA339A7
P 6150 10350
F 0 "#PWR0221" H 6150 10100 50  0001 C CNN
F 1 "GND" H 6155 10177 50  0000 C CNN
F 2 "" H 6150 10350 50  0001 C CNN
F 3 "" H 6150 10350 50  0001 C CNN
	1    6150 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0222
U 1 1 5BA339AD
P 5950 10350
F 0 "#PWR0222" H 5950 10200 50  0001 C CNN
F 1 "VCC" H 5967 10523 50  0000 C CNN
F 2 "" H 5950 10350 50  0001 C CNN
F 3 "" H 5950 10350 50  0001 C CNN
	1    5950 10350
	1    0    0    -1  
$EndComp
Connection ~ 5950 10350
$Comp
L 74xx:74HC00 U32
U 1 1 5BA36E32
P 7450 7900
F 0 "U32" H 7450 8225 50  0000 C CNN
F 1 "74HC00" H 7450 8134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7450 7900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7450 7900 50  0001 C CNN
	1    7450 7900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U32
U 2 1 5BA36E39
P 7450 8450
F 0 "U32" H 7450 8775 50  0000 C CNN
F 1 "74HC00" H 7450 8684 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7450 8450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7450 8450 50  0001 C CNN
	2    7450 8450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U32
U 3 1 5BA36E40
P 7450 9000
F 0 "U32" H 7450 9325 50  0000 C CNN
F 1 "74HC00" H 7450 9234 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7450 9000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7450 9000 50  0001 C CNN
	3    7450 9000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U32
U 4 1 5BA36E47
P 7450 9550
F 0 "U32" H 7450 9875 50  0000 C CNN
F 1 "74HC00" H 7450 9784 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7450 9550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7450 9550 50  0001 C CNN
	4    7450 9550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U32
U 5 1 5BA36E4E
P 7450 10350
F 0 "U32" V 7083 10350 50  0000 C CNN
F 1 "74HC00" V 7174 10350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7450 10350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7450 10350 50  0001 C CNN
	5    7450 10350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0232
U 1 1 5BA36E55
P 6950 10350
F 0 "#PWR0232" H 6950 10100 50  0001 C CNN
F 1 "GND" V 6955 10222 50  0000 R CNN
F 2 "" H 6950 10350 50  0001 C CNN
F 3 "" H 6950 10350 50  0001 C CNN
	1    6950 10350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C45
U 1 1 5BA36E5B
P 8050 10350
F 0 "C45" V 8150 10350 50  0000 C CNN
F 1 "0.1uF" V 7900 10350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8050 10350 50  0001 C CNN
F 3 "~" H 8050 10350 50  0001 C CNN
	1    8050 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0233
U 1 1 5BA36E62
P 8150 10350
F 0 "#PWR0233" H 8150 10100 50  0001 C CNN
F 1 "GND" H 8155 10177 50  0000 C CNN
F 2 "" H 8150 10350 50  0001 C CNN
F 3 "" H 8150 10350 50  0001 C CNN
	1    8150 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0234
U 1 1 5BA36E68
P 7950 10350
F 0 "#PWR0234" H 7950 10200 50  0001 C CNN
F 1 "VCC" H 7967 10523 50  0000 C CNN
F 2 "" H 7950 10350 50  0001 C CNN
F 3 "" H 7950 10350 50  0001 C CNN
	1    7950 10350
	1    0    0    -1  
$EndComp
Connection ~ 7950 10350
$Comp
L 74xx:74HC00 U43
U 1 1 5BA37409
P 9450 7900
F 0 "U43" H 9450 8225 50  0000 C CNN
F 1 "74HC00" H 9450 8134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 9450 7900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 9450 7900 50  0001 C CNN
	1    9450 7900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U43
U 2 1 5BA37410
P 9450 8450
F 0 "U43" H 9450 8775 50  0000 C CNN
F 1 "74HC00" H 9450 8684 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 9450 8450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 9450 8450 50  0001 C CNN
	2    9450 8450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U43
U 3 1 5BA37417
P 9450 9000
F 0 "U43" H 9450 9325 50  0000 C CNN
F 1 "74HC00" H 9450 9234 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 9450 9000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 9450 9000 50  0001 C CNN
	3    9450 9000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U43
U 4 1 5BA3741E
P 9450 9550
F 0 "U43" H 9450 9875 50  0000 C CNN
F 1 "74HC00" H 9450 9784 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 9450 9550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 9450 9550 50  0001 C CNN
	4    9450 9550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U43
U 5 1 5BA37425
P 9450 10350
F 0 "U43" V 9083 10350 50  0000 C CNN
F 1 "74HC00" V 9174 10350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 9450 10350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 9450 10350 50  0001 C CNN
	5    9450 10350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0235
U 1 1 5BA3742C
P 8950 10350
F 0 "#PWR0235" H 8950 10100 50  0001 C CNN
F 1 "GND" V 8955 10222 50  0000 R CNN
F 2 "" H 8950 10350 50  0001 C CNN
F 3 "" H 8950 10350 50  0001 C CNN
	1    8950 10350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C51
U 1 1 5BA37432
P 10050 10350
F 0 "C51" V 10150 10350 50  0000 C CNN
F 1 "0.1uF" V 9900 10350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10050 10350 50  0001 C CNN
F 3 "~" H 10050 10350 50  0001 C CNN
	1    10050 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0236
U 1 1 5BA37439
P 10150 10350
F 0 "#PWR0236" H 10150 10100 50  0001 C CNN
F 1 "GND" H 10155 10177 50  0000 C CNN
F 2 "" H 10150 10350 50  0001 C CNN
F 3 "" H 10150 10350 50  0001 C CNN
	1    10150 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0237
U 1 1 5BA3743F
P 9950 10350
F 0 "#PWR0237" H 9950 10200 50  0001 C CNN
F 1 "VCC" H 9967 10523 50  0000 C CNN
F 2 "" H 9950 10350 50  0001 C CNN
F 3 "" H 9950 10350 50  0001 C CNN
	1    9950 10350
	1    0    0    -1  
$EndComp
Connection ~ 9950 10350
$Comp
L 74xx:74HC00 U44
U 1 1 5BA37B29
P 11450 7900
F 0 "U44" H 11450 8225 50  0000 C CNN
F 1 "74HC00" H 11450 8134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 11450 7900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 11450 7900 50  0001 C CNN
	1    11450 7900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U44
U 2 1 5BA37B30
P 11450 8450
F 0 "U44" H 11450 8775 50  0000 C CNN
F 1 "74HC00" H 11450 8684 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 11450 8450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 11450 8450 50  0001 C CNN
	2    11450 8450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U44
U 3 1 5BA37B37
P 11450 9000
F 0 "U44" H 11450 9325 50  0000 C CNN
F 1 "74HC00" H 11450 9234 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 11450 9000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 11450 9000 50  0001 C CNN
	3    11450 9000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U44
U 4 1 5BA37B3E
P 11450 9550
F 0 "U44" H 11450 9875 50  0000 C CNN
F 1 "74HC00" H 11450 9784 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 11450 9550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 11450 9550 50  0001 C CNN
	4    11450 9550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U44
U 5 1 5BA37B45
P 11450 10350
F 0 "U44" V 11083 10350 50  0000 C CNN
F 1 "74HC00" V 11174 10350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 11450 10350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 11450 10350 50  0001 C CNN
	5    11450 10350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C52
U 1 1 5BA37B4C
P 12050 10350
F 0 "C52" V 12150 10350 50  0000 C CNN
F 1 "0.1uF" V 11900 10350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 12050 10350 50  0001 C CNN
F 3 "~" H 12050 10350 50  0001 C CNN
	1    12050 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0238
U 1 1 5BA37B53
P 12150 10350
F 0 "#PWR0238" H 12150 10100 50  0001 C CNN
F 1 "GND" H 12155 10177 50  0000 C CNN
F 2 "" H 12150 10350 50  0001 C CNN
F 3 "" H 12150 10350 50  0001 C CNN
	1    12150 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0239
U 1 1 5BA37B59
P 11950 10350
F 0 "#PWR0239" H 11950 10200 50  0001 C CNN
F 1 "VCC" H 11967 10523 50  0000 C CNN
F 2 "" H 11950 10350 50  0001 C CNN
F 3 "" H 11950 10350 50  0001 C CNN
	1    11950 10350
	1    0    0    -1  
$EndComp
Connection ~ 11950 10350
$Comp
L 74xx:74HC00 U45
U 1 1 5BA37B60
P 13450 7900
F 0 "U45" H 13450 8225 50  0000 C CNN
F 1 "74HC00" H 13450 8134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 13450 7900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 13450 7900 50  0001 C CNN
	1    13450 7900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U45
U 2 1 5BA37B67
P 13450 8450
F 0 "U45" H 13450 8775 50  0000 C CNN
F 1 "74HC00" H 13450 8684 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 13450 8450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 13450 8450 50  0001 C CNN
	2    13450 8450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U45
U 3 1 5BA37B6E
P 13450 9000
F 0 "U45" H 13450 9325 50  0000 C CNN
F 1 "74HC00" H 13450 9234 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 13450 9000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 13450 9000 50  0001 C CNN
	3    13450 9000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U45
U 4 1 5BA37B75
P 13450 9550
F 0 "U45" H 13450 9875 50  0000 C CNN
F 1 "74HC00" H 13450 9784 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 13450 9550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 13450 9550 50  0001 C CNN
	4    13450 9550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U45
U 5 1 5BA37B7C
P 13450 10350
F 0 "U45" V 13083 10350 50  0000 C CNN
F 1 "74HC00" V 13174 10350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 13450 10350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 13450 10350 50  0001 C CNN
	5    13450 10350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0240
U 1 1 5BA37B83
P 12950 10350
F 0 "#PWR0240" H 12950 10100 50  0001 C CNN
F 1 "GND" V 12955 10222 50  0000 R CNN
F 2 "" H 12950 10350 50  0001 C CNN
F 3 "" H 12950 10350 50  0001 C CNN
	1    12950 10350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C53
U 1 1 5BA37B89
P 14050 10350
F 0 "C53" V 14150 10350 50  0000 C CNN
F 1 "0.1uF" V 13900 10350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 14050 10350 50  0001 C CNN
F 3 "~" H 14050 10350 50  0001 C CNN
	1    14050 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0241
U 1 1 5BA37B90
P 14150 10350
F 0 "#PWR0241" H 14150 10100 50  0001 C CNN
F 1 "GND" H 14155 10177 50  0000 C CNN
F 2 "" H 14150 10350 50  0001 C CNN
F 3 "" H 14150 10350 50  0001 C CNN
	1    14150 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0242
U 1 1 5BA37B96
P 13950 10350
F 0 "#PWR0242" H 13950 10200 50  0001 C CNN
F 1 "VCC" H 13967 10523 50  0000 C CNN
F 2 "" H 13950 10350 50  0001 C CNN
F 3 "" H 13950 10350 50  0001 C CNN
	1    13950 10350
	1    0    0    -1  
$EndComp
Connection ~ 13950 10350
$Comp
L 74xx:74HC00 U46
U 1 1 5BA3919D
P 15450 7900
F 0 "U46" H 15450 8225 50  0000 C CNN
F 1 "74HC00" H 15450 8134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 15450 7900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 15450 7900 50  0001 C CNN
	1    15450 7900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U46
U 2 1 5BA391A4
P 15450 8450
F 0 "U46" H 15450 8775 50  0000 C CNN
F 1 "74HC00" H 15450 8684 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 15450 8450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 15450 8450 50  0001 C CNN
	2    15450 8450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U46
U 3 1 5BA391AB
P 15450 9000
F 0 "U46" H 15450 9325 50  0000 C CNN
F 1 "74HC00" H 15450 9234 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 15450 9000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 15450 9000 50  0001 C CNN
	3    15450 9000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U46
U 4 1 5BA391B2
P 15450 9550
F 0 "U46" H 15450 9875 50  0000 C CNN
F 1 "74HC00" H 15450 9784 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 15450 9550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 15450 9550 50  0001 C CNN
	4    15450 9550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U46
U 5 1 5BA391B9
P 15450 10350
F 0 "U46" V 15083 10350 50  0000 C CNN
F 1 "74HC00" V 15174 10350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 15450 10350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 15450 10350 50  0001 C CNN
	5    15450 10350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C54
U 1 1 5BA391C0
P 16050 10350
F 0 "C54" V 16150 10350 50  0000 C CNN
F 1 "0.1uF" V 15900 10350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 16050 10350 50  0001 C CNN
F 3 "~" H 16050 10350 50  0001 C CNN
	1    16050 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0243
U 1 1 5BA391C7
P 16150 10350
F 0 "#PWR0243" H 16150 10100 50  0001 C CNN
F 1 "GND" H 16155 10177 50  0000 C CNN
F 2 "" H 16150 10350 50  0001 C CNN
F 3 "" H 16150 10350 50  0001 C CNN
	1    16150 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0244
U 1 1 5BA391CD
P 15950 10350
F 0 "#PWR0244" H 15950 10200 50  0001 C CNN
F 1 "VCC" H 15967 10523 50  0000 C CNN
F 2 "" H 15950 10350 50  0001 C CNN
F 3 "" H 15950 10350 50  0001 C CNN
	1    15950 10350
	1    0    0    -1  
$EndComp
Connection ~ 15950 10350
$Comp
L 74xx:74HC00 U47
U 1 1 5BA391D4
P 17450 7900
F 0 "U47" H 17450 8225 50  0000 C CNN
F 1 "74HC00" H 17450 8134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 17450 7900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 17450 7900 50  0001 C CNN
	1    17450 7900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U47
U 2 1 5BA391DB
P 17450 8450
F 0 "U47" H 17450 8775 50  0000 C CNN
F 1 "74HC00" H 17450 8684 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 17450 8450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 17450 8450 50  0001 C CNN
	2    17450 8450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U47
U 3 1 5BA391E2
P 17450 9000
F 0 "U47" H 17450 9325 50  0000 C CNN
F 1 "74HC00" H 17450 9234 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 17450 9000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 17450 9000 50  0001 C CNN
	3    17450 9000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U47
U 4 1 5BA391E9
P 17450 9550
F 0 "U47" H 17450 9875 50  0000 C CNN
F 1 "74HC00" H 17450 9784 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 17450 9550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 17450 9550 50  0001 C CNN
	4    17450 9550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U47
U 5 1 5BA391F0
P 17450 10350
F 0 "U47" V 17083 10350 50  0000 C CNN
F 1 "74HC00" V 17174 10350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 17450 10350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 17450 10350 50  0001 C CNN
	5    17450 10350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0245
U 1 1 5BA391F7
P 16950 10350
F 0 "#PWR0245" H 16950 10100 50  0001 C CNN
F 1 "GND" V 16955 10222 50  0000 R CNN
F 2 "" H 16950 10350 50  0001 C CNN
F 3 "" H 16950 10350 50  0001 C CNN
	1    16950 10350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C55
U 1 1 5BA391FD
P 18050 10350
F 0 "C55" V 18150 10350 50  0000 C CNN
F 1 "0.1uF" V 17900 10350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 18050 10350 50  0001 C CNN
F 3 "~" H 18050 10350 50  0001 C CNN
	1    18050 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0246
U 1 1 5BA39204
P 18150 10350
F 0 "#PWR0246" H 18150 10100 50  0001 C CNN
F 1 "GND" H 18155 10177 50  0000 C CNN
F 2 "" H 18150 10350 50  0001 C CNN
F 3 "" H 18150 10350 50  0001 C CNN
	1    18150 10350
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0247
U 1 1 5BA3920A
P 17950 10350
F 0 "#PWR0247" H 17950 10200 50  0001 C CNN
F 1 "VCC" H 17967 10523 50  0000 C CNN
F 2 "" H 17950 10350 50  0001 C CNN
F 3 "" H 17950 10350 50  0001 C CNN
	1    17950 10350
	1    0    0    -1  
$EndComp
Connection ~ 17950 10350
Text Label 5150 7800 2    50   ~ 0
A4
Text Label 5150 8000 2    50   ~ 0
B4
Text Label 5150 8350 2    50   ~ 0
A5
Text Label 5150 8550 2    50   ~ 0
B5
Text Label 5150 8900 2    50   ~ 0
A6
Text Label 5150 9100 2    50   ~ 0
B6
Text Label 5150 9450 2    50   ~ 0
A7
Text Label 5150 9650 2    50   ~ 0
B7
Text Label 7150 7800 2    50   ~ 0
A8
Text Label 7150 8000 2    50   ~ 0
B8
Text Label 7150 8350 2    50   ~ 0
A9
Text Label 7150 8550 2    50   ~ 0
B9
Text Label 7150 8900 2    50   ~ 0
A10
Text Label 7150 9100 2    50   ~ 0
B10
Text Label 7150 9450 2    50   ~ 0
A11
Text Label 7150 9650 2    50   ~ 0
B11
Text Label 9150 7800 2    50   ~ 0
A12
Text Label 9150 8000 2    50   ~ 0
B12
Text Label 9150 8350 2    50   ~ 0
A13
Text Label 9150 8550 2    50   ~ 0
B13
Text Label 9150 8900 2    50   ~ 0
A14
Text Label 9150 9100 2    50   ~ 0
B14
Text Label 9150 9450 2    50   ~ 0
A15
Text Label 9150 9650 2    50   ~ 0
B15
Text Label 11150 7800 2    50   ~ 0
A16
Text Label 11150 8000 2    50   ~ 0
B16
Text Label 11150 8350 2    50   ~ 0
A17
Text Label 11150 8550 2    50   ~ 0
B17
Text Label 11150 8900 2    50   ~ 0
A18
Text Label 11150 9100 2    50   ~ 0
B18
Text Label 11150 9450 2    50   ~ 0
A19
Text Label 11150 9650 2    50   ~ 0
B19
Text Label 13150 7800 2    50   ~ 0
A20
Text Label 13150 8000 2    50   ~ 0
B20
Text Label 13150 8350 2    50   ~ 0
A21
Text Label 13150 8550 2    50   ~ 0
B21
Text Label 13150 8900 2    50   ~ 0
A22
Text Label 13150 9100 2    50   ~ 0
B22
Text Label 13150 9450 2    50   ~ 0
A23
Text Label 13150 9650 2    50   ~ 0
B23
Text Label 15150 7800 2    50   ~ 0
A24
Text Label 15150 8000 2    50   ~ 0
B24
Text Label 15150 8350 2    50   ~ 0
A25
Text Label 15150 8550 2    50   ~ 0
B25
Text Label 15150 8900 2    50   ~ 0
A26
Text Label 15150 9100 2    50   ~ 0
B26
Text Label 15150 9450 2    50   ~ 0
A27
Text Label 15150 9650 2    50   ~ 0
B27
Text Label 17150 7800 2    50   ~ 0
A28
Text Label 17150 8000 2    50   ~ 0
B28
Text Label 17150 8350 2    50   ~ 0
A29
Text Label 17150 8550 2    50   ~ 0
B29
Text Label 17150 8900 2    50   ~ 0
A30
Text Label 17150 9100 2    50   ~ 0
B30
Text Label 17150 9450 2    50   ~ 0
A31
Text Label 17150 9650 2    50   ~ 0
B31
Text Label 3750 7900 0    50   ~ 0
NAND0
Text Label 3750 8450 0    50   ~ 0
NAND1
Text Label 3750 9000 0    50   ~ 0
NAND2
Text Label 3750 9550 0    50   ~ 0
NAND3
Text Label 5750 7900 0    50   ~ 0
NAND4
Text Label 5750 8450 0    50   ~ 0
NAND5
Text Label 5750 9000 0    50   ~ 0
NAND6
Text Label 5750 9550 0    50   ~ 0
NAND7
Text Label 7750 7900 0    50   ~ 0
NAND8
Text Label 7750 8450 0    50   ~ 0
NAND9
Text Label 7750 9000 0    50   ~ 0
NAND10
Text Label 7750 9550 0    50   ~ 0
NAND11
Text Label 9750 7900 0    50   ~ 0
NAND12
Text Label 9750 8450 0    50   ~ 0
NAND13
Text Label 9750 9000 0    50   ~ 0
NAND14
Text Label 9750 9550 0    50   ~ 0
NAND15
Text Label 11750 7900 0    50   ~ 0
NAND16
Text Label 11750 8450 0    50   ~ 0
NAND17
Text Label 11750 9000 0    50   ~ 0
NAND18
Text Label 11750 9550 0    50   ~ 0
NAND19
Text Label 13750 7900 0    50   ~ 0
NAND20
Text Label 13750 8450 0    50   ~ 0
NAND21
Text Label 13750 9000 0    50   ~ 0
NAND22
Text Label 13750 9550 0    50   ~ 0
NAND23
$Comp
L power:GND #PWR0248
U 1 1 5BA48B7E
P 10950 10350
F 0 "#PWR0248" H 10950 10100 50  0001 C CNN
F 1 "GND" V 10955 10222 50  0000 R CNN
F 2 "" H 10950 10350 50  0001 C CNN
F 3 "" H 10950 10350 50  0001 C CNN
	1    10950 10350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0249
U 1 1 5BA4C379
P 14950 10350
F 0 "#PWR0249" H 14950 10100 50  0001 C CNN
F 1 "GND" V 14955 10222 50  0000 R CNN
F 2 "" H 14950 10350 50  0001 C CNN
F 3 "" H 14950 10350 50  0001 C CNN
	1    14950 10350
	0    1    1    0   
$EndComp
Text Label 15750 7900 0    50   ~ 0
NAND24
Text Label 15750 8450 0    50   ~ 0
NAND25
Text Label 15750 9000 0    50   ~ 0
NAND26
Text Label 15750 9550 0    50   ~ 0
NAND27
Text Label 17750 7900 0    50   ~ 0
NAND28
Text Label 17750 8450 0    50   ~ 0
NAND29
Text Label 17750 9000 0    50   ~ 0
NAND30
Text Label 17750 9550 0    50   ~ 0
NAND31
$Comp
L Device:D D7
U 1 1 5BA74DA5
P 11700 1650
F 0 "D7" H 11600 1600 50  0000 C CNN
F 1 "D" H 11800 1650 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 1650 50  0001 C CNN
F 3 "~" H 11700 1650 50  0001 C CNN
	1    11700 1650
	-1   0    0    1   
$EndComp
$Comp
L Device:D D8
U 1 1 5BA7519D
P 11700 1750
F 0 "D8" H 11600 1700 50  0000 C CNN
F 1 "D" H 11800 1750 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 1750 50  0001 C CNN
F 3 "~" H 11700 1750 50  0001 C CNN
	1    11700 1750
	-1   0    0    1   
$EndComp
$Comp
L Device:D D5
U 1 1 5BA75D9C
P 11700 1450
F 0 "D5" H 11600 1400 50  0000 C CNN
F 1 "D" H 11800 1450 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 1450 50  0001 C CNN
F 3 "~" H 11700 1450 50  0001 C CNN
	1    11700 1450
	-1   0    0    1   
$EndComp
$Comp
L Device:D D6
U 1 1 5BA75DA3
P 11700 1550
F 0 "D6" H 11600 1500 50  0000 C CNN
F 1 "D" H 11800 1550 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 1550 50  0001 C CNN
F 3 "~" H 11700 1550 50  0001 C CNN
	1    11700 1550
	-1   0    0    1   
$EndComp
$Comp
L Device:D D3
U 1 1 5BA76A12
P 11700 1250
F 0 "D3" H 11600 1200 50  0000 C CNN
F 1 "D" H 11800 1250 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 1250 50  0001 C CNN
F 3 "~" H 11700 1250 50  0001 C CNN
	1    11700 1250
	-1   0    0    1   
$EndComp
$Comp
L Device:D D4
U 1 1 5BA76A19
P 11700 1350
F 0 "D4" H 11600 1300 50  0000 C CNN
F 1 "D" H 11800 1350 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 1350 50  0001 C CNN
F 3 "~" H 11700 1350 50  0001 C CNN
	1    11700 1350
	-1   0    0    1   
$EndComp
$Comp
L Device:D D1
U 1 1 5BA76A20
P 11700 1050
F 0 "D1" H 11600 1000 50  0000 C CNN
F 1 "D" H 11800 1050 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 1050 50  0001 C CNN
F 3 "~" H 11700 1050 50  0001 C CNN
	1    11700 1050
	-1   0    0    1   
$EndComp
$Comp
L Device:D D2
U 1 1 5BA76A27
P 11700 1150
F 0 "D2" H 11600 1100 50  0000 C CNN
F 1 "D" H 11800 1150 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 1150 50  0001 C CNN
F 3 "~" H 11700 1150 50  0001 C CNN
	1    11700 1150
	-1   0    0    1   
$EndComp
$Comp
L Device:D D15
U 1 1 5BA77142
P 11700 2450
F 0 "D15" H 11600 2400 50  0000 C CNN
F 1 "D" H 11800 2450 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 2450 50  0001 C CNN
F 3 "~" H 11700 2450 50  0001 C CNN
	1    11700 2450
	-1   0    0    1   
$EndComp
$Comp
L Device:D D16
U 1 1 5BA77149
P 11700 2550
F 0 "D16" H 11600 2500 50  0000 C CNN
F 1 "D" H 11800 2550 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 2550 50  0001 C CNN
F 3 "~" H 11700 2550 50  0001 C CNN
	1    11700 2550
	-1   0    0    1   
$EndComp
$Comp
L Device:D D13
U 1 1 5BA77150
P 11700 2250
F 0 "D13" H 11600 2200 50  0000 C CNN
F 1 "D" H 11800 2250 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 2250 50  0001 C CNN
F 3 "~" H 11700 2250 50  0001 C CNN
	1    11700 2250
	-1   0    0    1   
$EndComp
$Comp
L Device:D D14
U 1 1 5BA77157
P 11700 2350
F 0 "D14" H 11600 2300 50  0000 C CNN
F 1 "D" H 11800 2350 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 2350 50  0001 C CNN
F 3 "~" H 11700 2350 50  0001 C CNN
	1    11700 2350
	-1   0    0    1   
$EndComp
$Comp
L Device:D D11
U 1 1 5BA7715E
P 11700 2050
F 0 "D11" H 11600 2000 50  0000 C CNN
F 1 "D" H 11800 2050 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 2050 50  0001 C CNN
F 3 "~" H 11700 2050 50  0001 C CNN
	1    11700 2050
	-1   0    0    1   
$EndComp
$Comp
L Device:D D12
U 1 1 5BA77165
P 11700 2150
F 0 "D12" H 11600 2100 50  0000 C CNN
F 1 "D" H 11800 2150 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 2150 50  0001 C CNN
F 3 "~" H 11700 2150 50  0001 C CNN
	1    11700 2150
	-1   0    0    1   
$EndComp
$Comp
L Device:D D9
U 1 1 5BA7716C
P 11700 1850
F 0 "D9" H 11600 1800 50  0000 C CNN
F 1 "D" H 11800 1850 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 1850 50  0001 C CNN
F 3 "~" H 11700 1850 50  0001 C CNN
	1    11700 1850
	-1   0    0    1   
$EndComp
$Comp
L Device:D D10
U 1 1 5BA77173
P 11700 1950
F 0 "D10" H 11600 1900 50  0000 C CNN
F 1 "D" H 11800 1950 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 1950 50  0001 C CNN
F 3 "~" H 11700 1950 50  0001 C CNN
	1    11700 1950
	-1   0    0    1   
$EndComp
$Comp
L Device:D D24
U 1 1 5BA78566
P 11700 3250
F 0 "D24" H 11600 3200 50  0000 C CNN
F 1 "D" H 11800 3250 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 3250 50  0001 C CNN
F 3 "~" H 11700 3250 50  0001 C CNN
	1    11700 3250
	-1   0    0    1   
$EndComp
$Comp
L Device:D D25
U 1 1 5BA7856D
P 11700 3350
F 0 "D25" H 11600 3300 50  0000 C CNN
F 1 "D" H 11800 3350 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 3350 50  0001 C CNN
F 3 "~" H 11700 3350 50  0001 C CNN
	1    11700 3350
	-1   0    0    1   
$EndComp
$Comp
L Device:D D22
U 1 1 5BA78574
P 11700 3050
F 0 "D22" H 11600 3000 50  0000 C CNN
F 1 "D" H 11800 3050 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 3050 50  0001 C CNN
F 3 "~" H 11700 3050 50  0001 C CNN
	1    11700 3050
	-1   0    0    1   
$EndComp
$Comp
L Device:D D23
U 1 1 5BA7857B
P 11700 3150
F 0 "D23" H 11600 3100 50  0000 C CNN
F 1 "D" H 11800 3150 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 3150 50  0001 C CNN
F 3 "~" H 11700 3150 50  0001 C CNN
	1    11700 3150
	-1   0    0    1   
$EndComp
$Comp
L Device:D D20
U 1 1 5BA78582
P 11700 2850
F 0 "D20" H 11600 2800 50  0000 C CNN
F 1 "D" H 11800 2850 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 2850 50  0001 C CNN
F 3 "~" H 11700 2850 50  0001 C CNN
	1    11700 2850
	-1   0    0    1   
$EndComp
$Comp
L Device:D D21
U 1 1 5BA78589
P 11700 2950
F 0 "D21" H 11600 2900 50  0000 C CNN
F 1 "D" H 11800 2950 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 2950 50  0001 C CNN
F 3 "~" H 11700 2950 50  0001 C CNN
	1    11700 2950
	-1   0    0    1   
$EndComp
$Comp
L Device:D D18
U 1 1 5BA78590
P 11700 2650
F 0 "D18" H 11600 2600 50  0000 C CNN
F 1 "D" H 11800 2650 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 2650 50  0001 C CNN
F 3 "~" H 11700 2650 50  0001 C CNN
	1    11700 2650
	-1   0    0    1   
$EndComp
$Comp
L Device:D D19
U 1 1 5BA78597
P 11700 2750
F 0 "D19" H 11600 2700 50  0000 C CNN
F 1 "D" H 11800 2750 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 2750 50  0001 C CNN
F 3 "~" H 11700 2750 50  0001 C CNN
	1    11700 2750
	-1   0    0    1   
$EndComp
$Comp
L Device:D D32
U 1 1 5BA7859E
P 11700 4050
F 0 "D32" H 11600 4000 50  0000 C CNN
F 1 "D" H 11800 4050 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 4050 50  0001 C CNN
F 3 "~" H 11700 4050 50  0001 C CNN
	1    11700 4050
	-1   0    0    1   
$EndComp
$Comp
L Device:D D33
U 1 1 5BA785A5
P 11700 4150
F 0 "D33" H 11600 4100 50  0000 C CNN
F 1 "D" H 11800 4150 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 4150 50  0001 C CNN
F 3 "~" H 11700 4150 50  0001 C CNN
	1    11700 4150
	-1   0    0    1   
$EndComp
$Comp
L Device:D D30
U 1 1 5BA785AC
P 11700 3850
F 0 "D30" H 11600 3800 50  0000 C CNN
F 1 "D" H 11800 3850 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 3850 50  0001 C CNN
F 3 "~" H 11700 3850 50  0001 C CNN
	1    11700 3850
	-1   0    0    1   
$EndComp
$Comp
L Device:D D31
U 1 1 5BA785B3
P 11700 3950
F 0 "D31" H 11600 3900 50  0000 C CNN
F 1 "D" H 11800 3950 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 3950 50  0001 C CNN
F 3 "~" H 11700 3950 50  0001 C CNN
	1    11700 3950
	-1   0    0    1   
$EndComp
$Comp
L Device:D D28
U 1 1 5BA785BA
P 11700 3650
F 0 "D28" H 11600 3600 50  0000 C CNN
F 1 "D" H 11800 3650 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 3650 50  0001 C CNN
F 3 "~" H 11700 3650 50  0001 C CNN
	1    11700 3650
	-1   0    0    1   
$EndComp
$Comp
L Device:D D29
U 1 1 5BA785C1
P 11700 3750
F 0 "D29" H 11600 3700 50  0000 C CNN
F 1 "D" H 11800 3750 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 3750 50  0001 C CNN
F 3 "~" H 11700 3750 50  0001 C CNN
	1    11700 3750
	-1   0    0    1   
$EndComp
$Comp
L Device:D D26
U 1 1 5BA785C8
P 11700 3450
F 0 "D26" H 11600 3400 50  0000 C CNN
F 1 "D" H 11800 3450 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 3450 50  0001 C CNN
F 3 "~" H 11700 3450 50  0001 C CNN
	1    11700 3450
	-1   0    0    1   
$EndComp
$Comp
L Device:D D27
U 1 1 5BA785CF
P 11700 3550
F 0 "D27" H 11600 3500 50  0000 C CNN
F 1 "D" H 11800 3550 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P7.62mm_Horizontal" H 11700 3550 50  0001 C CNN
F 3 "~" H 11700 3550 50  0001 C CNN
	1    11700 3550
	-1   0    0    1   
$EndComp
Text Label 11550 1050 2    50   ~ 0
A0
Text Label 11550 1150 2    50   ~ 0
A1
Text Label 11550 1250 2    50   ~ 0
A2
Text Label 11550 1350 2    50   ~ 0
A3
Text Label 11550 1450 2    50   ~ 0
A4
Text Label 11550 1550 2    50   ~ 0
A5
Text Label 11550 1650 2    50   ~ 0
A6
Text Label 11550 1750 2    50   ~ 0
A7
Text Label 11550 1850 2    50   ~ 0
A8
Text Label 11550 1950 2    50   ~ 0
A9
Text Label 11550 2050 2    50   ~ 0
A10
Text Label 11550 2150 2    50   ~ 0
A11
Text Label 11550 2250 2    50   ~ 0
A12
Text Label 11550 2350 2    50   ~ 0
A13
Text Label 11550 2450 2    50   ~ 0
A14
Text Label 11550 2550 2    50   ~ 0
A15
Text Label 11550 2650 2    50   ~ 0
A16
Text Label 11550 2750 2    50   ~ 0
A17
Text Label 11550 2850 2    50   ~ 0
A18
Text Label 11550 2950 2    50   ~ 0
A19
Text Label 11550 3050 2    50   ~ 0
A20
Text Label 11550 3150 2    50   ~ 0
A21
Text Label 11550 3250 2    50   ~ 0
A22
Text Label 11550 3350 2    50   ~ 0
A23
Text Label 11550 3450 2    50   ~ 0
A24
Text Label 11550 3550 2    50   ~ 0
A25
Text Label 11550 3650 2    50   ~ 0
A26
Text Label 11550 3750 2    50   ~ 0
A27
Text Label 11550 3850 2    50   ~ 0
A28
Text Label 11550 3950 2    50   ~ 0
A29
Text Label 11550 4050 2    50   ~ 0
A30
Text Label 11550 4150 2    50   ~ 0
A31
Text Notes 11950 2350 0    50   ~ 0
SPARE TAKEN: 74HC14 from Clock
Wire Wire Line
	11850 1050 11850 1150
Wire Wire Line
	11850 1150 11850 1250
Connection ~ 11850 1150
Wire Wire Line
	11850 1250 11850 1350
Connection ~ 11850 1250
Wire Wire Line
	11850 1350 11850 1450
Connection ~ 11850 1350
Wire Wire Line
	11850 1450 11850 1550
Connection ~ 11850 1450
Wire Wire Line
	11850 1550 11850 1650
Connection ~ 11850 1550
Wire Wire Line
	11850 1650 11850 1750
Connection ~ 11850 1650
Wire Wire Line
	11850 1750 11850 1850
Connection ~ 11850 1750
Wire Wire Line
	11850 1850 11850 1950
Connection ~ 11850 1850
Wire Wire Line
	11850 1950 11850 2050
Connection ~ 11850 1950
Wire Wire Line
	11850 2050 11850 2150
Connection ~ 11850 2050
Wire Wire Line
	11850 2150 11850 2250
Connection ~ 11850 2150
Wire Wire Line
	11850 2250 11850 2350
Connection ~ 11850 2250
Wire Wire Line
	11850 2350 11850 2450
Connection ~ 11850 2350
Wire Wire Line
	11850 2450 11850 2550
Connection ~ 11850 2450
Connection ~ 11850 2550
Wire Wire Line
	11850 4150 11850 4050
Wire Wire Line
	11850 4050 11850 3950
Connection ~ 11850 4050
Wire Wire Line
	11850 3950 11850 3850
Connection ~ 11850 3950
Wire Wire Line
	11850 3850 11850 3750
Connection ~ 11850 3850
Wire Wire Line
	11850 3750 11850 3650
Connection ~ 11850 3750
Wire Wire Line
	11850 3650 11850 3550
Connection ~ 11850 3650
Wire Wire Line
	11850 3550 11850 3450
Connection ~ 11850 3550
Wire Wire Line
	11850 3450 11850 3350
Connection ~ 11850 3450
Wire Wire Line
	11850 3250 11850 3350
Connection ~ 11850 3350
Wire Wire Line
	11850 3250 11850 3150
Connection ~ 11850 3250
Wire Wire Line
	11850 3150 11850 3050
Connection ~ 11850 3150
Wire Wire Line
	11850 3050 11850 2950
Connection ~ 11850 3050
Wire Wire Line
	11850 2850 11850 2750
Wire Wire Line
	11850 2850 11850 2950
Connection ~ 11850 2850
Connection ~ 11850 2950
Wire Wire Line
	11850 2750 11850 2650
Connection ~ 11850 2750
Wire Wire Line
	11850 2650 11850 2550
Connection ~ 11850 2650
$Comp
L power:VCC #PWR094
U 1 1 5BAC6C44
P 13150 5000
F 0 "#PWR094" H 13150 4850 50  0001 C CNN
F 1 "VCC" H 13167 5173 50  0000 C CNN
F 2 "" H 13150 5000 50  0001 C CNN
F 3 "" H 13150 5000 50  0001 C CNN
	1    13150 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR095
U 1 1 5BAC6C4A
P 13150 6600
F 0 "#PWR095" H 13150 6350 50  0001 C CNN
F 1 "GND" H 13155 6427 50  0000 C CNN
F 2 "" H 13150 6600 50  0001 C CNN
F 3 "" H 13150 6600 50  0001 C CNN
	1    13150 6600
	1    0    0    -1  
$EndComp
Text HLabel 12650 6300 0    50   Input ~ 0
~ALU_STATUS_OUT
$Comp
L power:VCC #PWR093
U 1 1 5BAC6C51
P 12650 6200
F 0 "#PWR093" H 12650 6050 50  0001 C CNN
F 1 "VCC" V 12668 6327 50  0000 L CNN
F 2 "" H 12650 6200 50  0001 C CNN
F 3 "" H 12650 6200 50  0001 C CNN
	1    12650 6200
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C103
U 1 1 5BAC6C57
P 13500 4850
F 0 "C103" V 13600 4850 50  0000 C CNN
F 1 "0.1uF" V 13350 4850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 13500 4850 50  0001 C CNN
F 3 "~" H 13500 4850 50  0001 C CNN
	1    13500 4850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	13150 5000 13300 5000
Wire Wire Line
	13300 5000 13300 4850
Wire Wire Line
	13300 4850 13400 4850
$Comp
L power:GND #PWR096
U 1 1 5BAC6C61
P 13600 4850
F 0 "#PWR096" H 13600 4600 50  0001 C CNN
F 1 "GND" H 13605 4677 50  0000 C CNN
F 2 "" H 13600 4850 50  0001 C CNN
F 3 "" H 13600 4850 50  0001 C CNN
	1    13600 4850
	0    -1   -1   0   
$EndComp
Connection ~ 13150 5000
$Comp
L 74xx:74HC245 U86
U 1 1 5BAC6C68
P 13150 5800
F 0 "U86" H 13250 6450 50  0000 C CNN
F 1 "74HC245" H 13150 5500 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 13150 5800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 13150 5800 50  0001 C CNN
	1    13150 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR092
U 1 1 5BAC9007
P 12650 6000
F 0 "#PWR092" H 12650 5750 50  0001 C CNN
F 1 "GND" V 12655 5872 50  0000 R CNN
F 2 "" H 12650 6000 50  0001 C CNN
F 3 "" H 12650 6000 50  0001 C CNN
	1    12650 6000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR091
U 1 1 5BAC9172
P 12650 5900
F 0 "#PWR091" H 12650 5650 50  0001 C CNN
F 1 "GND" V 12655 5772 50  0000 R CNN
F 2 "" H 12650 5900 50  0001 C CNN
F 3 "" H 12650 5900 50  0001 C CNN
	1    12650 5900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR090
U 1 1 5BAC9263
P 12650 5800
F 0 "#PWR090" H 12650 5550 50  0001 C CNN
F 1 "GND" V 12655 5672 50  0000 R CNN
F 2 "" H 12650 5800 50  0001 C CNN
F 3 "" H 12650 5800 50  0001 C CNN
	1    12650 5800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR088
U 1 1 5BAC9354
P 12650 5700
F 0 "#PWR088" H 12650 5450 50  0001 C CNN
F 1 "GND" V 12655 5572 50  0000 R CNN
F 2 "" H 12650 5700 50  0001 C CNN
F 3 "" H 12650 5700 50  0001 C CNN
	1    12650 5700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR087
U 1 1 5BAC95A8
P 12650 5600
F 0 "#PWR087" H 12650 5350 50  0001 C CNN
F 1 "GND" V 12655 5472 50  0000 R CNN
F 2 "" H 12650 5600 50  0001 C CNN
F 3 "" H 12650 5600 50  0001 C CNN
	1    12650 5600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR085
U 1 1 5BAC9699
P 12650 5500
F 0 "#PWR085" H 12650 5250 50  0001 C CNN
F 1 "GND" V 12655 5372 50  0000 R CNN
F 2 "" H 12650 5500 50  0001 C CNN
F 3 "" H 12650 5500 50  0001 C CNN
	1    12650 5500
	0    1    1    0   
$EndComp
Text Label 12450 2550 0    50   ~ 0
ZERO_OUT
Text Label 9900 3650 0    50   ~ 0
CARRY_OUT
Text Label 12650 5300 2    50   ~ 0
CARRY_OUT
Text Label 12650 5400 2    50   ~ 0
ZERO_OUT
Text HLabel 13650 5300 2    50   Input ~ 0
BUS0
Text HLabel 13650 5400 2    50   Input ~ 0
BUS1
Text HLabel 13650 5500 2    50   Input ~ 0
BUS2
Text HLabel 13650 5600 2    50   Input ~ 0
BUS3
Text HLabel 13650 5700 2    50   Input ~ 0
BUS4
Text HLabel 13650 5800 2    50   Input ~ 0
BUS5
Text HLabel 13650 5900 2    50   Input ~ 0
BUS6
Text HLabel 13650 6000 2    50   Input ~ 0
BUS7
$Comp
L 74xx:74HC14 U?
U 4 1 5BA70D29
P 12150 2550
AR Path="/5ADF0E03/5BA70D29" Ref="U?"  Part="4" 
AR Path="/5B9E2640/5BA70D29" Ref="U2"  Part="4" 
F 0 "U2" H 12100 2550 50  0000 C CNN
F 1 "74HC14" H 12150 2350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 12150 2550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 12150 2550 50  0001 C CNN
	4    12150 2550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
