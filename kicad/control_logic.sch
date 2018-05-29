EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 24 36
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
L 74xx:74LS574 U87
U 1 1 5B0C6E46
P 1600 1700
F 0 "U87" H 1600 1500 50  0000 C CNN
F 1 "74LS574" H 1650 1400 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 1600 1700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS574" H 1600 1700 50  0001 C CNN
	1    1600 1700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0351
U 1 1 5B0C6FCF
P 1600 900
F 0 "#PWR0351" H 1600 750 50  0001 C CNN
F 1 "VCC" H 1617 1073 50  0000 C CNN
F 2 "" H 1600 900 50  0001 C CNN
F 3 "" H 1600 900 50  0001 C CNN
	1    1600 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0352
U 1 1 5B0C7016
P 1600 2500
F 0 "#PWR0352" H 1600 2250 50  0001 C CNN
F 1 "GND" H 1605 2327 50  0000 C CNN
F 2 "" H 1600 2500 50  0001 C CNN
F 3 "" H 1600 2500 50  0001 C CNN
	1    1600 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C98
U 1 1 5B0C7064
P 1850 900
F 0 "C98" V 1621 900 50  0000 C CNN
F 1 "0.1uF" V 1712 900 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 1850 900 50  0001 C CNN
F 3 "~" H 1850 900 50  0001 C CNN
	1    1850 900 
	0    1    1    0   
$EndComp
Wire Wire Line
	1600 900  1750 900 
Connection ~ 1600 900 
$Comp
L power:GND #PWR0353
U 1 1 5B0C70CB
P 1950 900
F 0 "#PWR0353" H 1950 650 50  0001 C CNN
F 1 "GND" V 1955 772 50  0000 R CNN
F 2 "" H 1950 900 50  0001 C CNN
F 3 "" H 1950 900 50  0001 C CNN
	1    1950 900 
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74LS574 U89
U 1 1 5B0C714D
P 3300 1700
F 0 "U89" H 3300 1500 50  0000 C CNN
F 1 "74LS574" H 3350 1400 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 3300 1700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS574" H 3300 1700 50  0001 C CNN
	1    3300 1700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0354
U 1 1 5B0C7154
P 3300 900
F 0 "#PWR0354" H 3300 750 50  0001 C CNN
F 1 "VCC" H 3317 1073 50  0000 C CNN
F 2 "" H 3300 900 50  0001 C CNN
F 3 "" H 3300 900 50  0001 C CNN
	1    3300 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0355
U 1 1 5B0C715A
P 3000 2500
F 0 "#PWR0355" H 3000 2250 50  0001 C CNN
F 1 "GND" H 3005 2327 50  0000 C CNN
F 2 "" H 3000 2500 50  0001 C CNN
F 3 "" H 3000 2500 50  0001 C CNN
	1    3000 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C100
U 1 1 5B0C7160
P 3550 900
F 0 "C100" V 3321 900 50  0000 C CNN
F 1 "0.1uF" V 3412 900 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 3550 900 50  0001 C CNN
F 3 "~" H 3550 900 50  0001 C CNN
	1    3550 900 
	0    1    1    0   
$EndComp
Wire Wire Line
	3300 900  3450 900 
Connection ~ 3300 900 
$Comp
L power:GND #PWR0356
U 1 1 5B0C7169
P 3650 900
F 0 "#PWR0356" H 3650 650 50  0001 C CNN
F 1 "GND" V 3655 772 50  0000 R CNN
F 2 "" H 3650 900 50  0001 C CNN
F 3 "" H 3650 900 50  0001 C CNN
	1    3650 900 
	0    -1   -1   0   
$EndComp
Wire Notes Line
	550  550  550  2800
Wire Notes Line
	4300 2800 4300 550 
Text Notes 1950 2600 0    50   ~ 0
Control word latch
$Comp
L Memory_Flash:SST39SF040 U88
U 1 1 5B0C7203
P 1600 4800
F 0 "U88" H 1650 4600 50  0000 C CNN
F 1 "SST39SF040" H 1700 4400 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 1600 5100 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 1600 5100 50  0001 C CNN
	1    1600 4800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0357
U 1 1 5B0C730F
P 1600 3500
F 0 "#PWR0357" H 1600 3350 50  0001 C CNN
F 1 "VCC" H 1617 3673 50  0000 C CNN
F 2 "" H 1600 3500 50  0001 C CNN
F 3 "" H 1600 3500 50  0001 C CNN
	1    1600 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C99
U 1 1 5B0C7315
P 1900 3300
F 0 "C99" V 1671 3300 50  0000 C CNN
F 1 "0.1uF" V 1762 3300 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 1900 3300 50  0001 C CNN
F 3 "~" H 1900 3300 50  0001 C CNN
	1    1900 3300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0358
U 1 1 5B0C731C
P 2000 3300
F 0 "#PWR0358" H 2000 3050 50  0001 C CNN
F 1 "GND" V 2005 3172 50  0000 R CNN
F 2 "" H 2000 3300 50  0001 C CNN
F 3 "" H 2000 3300 50  0001 C CNN
	1    2000 3300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1600 3500 1800 3500
Wire Wire Line
	1800 3500 1800 3300
Connection ~ 1600 3500
$Comp
L power:GND #PWR0359
U 1 1 5B0C740B
P 1600 6000
F 0 "#PWR0359" H 1600 5750 50  0001 C CNN
F 1 "GND" H 1605 5827 50  0000 C CNN
F 2 "" H 1600 6000 50  0001 C CNN
F 3 "" H 1600 6000 50  0001 C CNN
	1    1600 6000
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0360
U 1 1 5B0C7919
P 1000 5600
F 0 "#PWR0360" H 1000 5450 50  0001 C CNN
F 1 "VCC" V 1018 5727 50  0000 L CNN
F 2 "" H 1000 5600 50  0001 C CNN
F 3 "" H 1000 5600 50  0001 C CNN
	1    1000 5600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0361
U 1 1 5B0C7972
P 1000 5800
F 0 "#PWR0361" H 1000 5550 50  0001 C CNN
F 1 "GND" V 1005 5672 50  0000 R CNN
F 2 "" H 1000 5800 50  0001 C CNN
F 3 "" H 1000 5800 50  0001 C CNN
	1    1000 5800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0362
U 1 1 5B0C798F
P 1000 5900
F 0 "#PWR0362" H 1000 5650 50  0001 C CNN
F 1 "GND" V 1005 5772 50  0000 R CNN
F 2 "" H 1000 5900 50  0001 C CNN
F 3 "" H 1000 5900 50  0001 C CNN
	1    1000 5900
	0    1    1    0   
$EndComp
$Comp
L Memory_Flash:SST39SF040 U90
U 1 1 5B0C7CC2
P 3400 4800
F 0 "U90" H 3450 4600 50  0000 C CNN
F 1 "SST39SF040" H 3500 4400 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 3400 5100 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 3400 5100 50  0001 C CNN
	1    3400 4800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0363
U 1 1 5B0C7CC9
P 3400 3500
F 0 "#PWR0363" H 3400 3350 50  0001 C CNN
F 1 "VCC" H 3417 3673 50  0000 C CNN
F 2 "" H 3400 3500 50  0001 C CNN
F 3 "" H 3400 3500 50  0001 C CNN
	1    3400 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C101
U 1 1 5B0C7CCF
P 3700 3300
F 0 "C101" V 3471 3300 50  0000 C CNN
F 1 "0.1uF" V 3562 3300 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 3700 3300 50  0001 C CNN
F 3 "~" H 3700 3300 50  0001 C CNN
	1    3700 3300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0364
U 1 1 5B0C7CD6
P 3800 3300
F 0 "#PWR0364" H 3800 3050 50  0001 C CNN
F 1 "GND" V 3805 3172 50  0000 R CNN
F 2 "" H 3800 3300 50  0001 C CNN
F 3 "" H 3800 3300 50  0001 C CNN
	1    3800 3300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3400 3500 3600 3500
Wire Wire Line
	3600 3500 3600 3300
Connection ~ 3400 3500
$Comp
L power:GND #PWR0365
U 1 1 5B0C7CDF
P 3400 6000
F 0 "#PWR0365" H 3400 5750 50  0001 C CNN
F 1 "GND" H 3405 5827 50  0000 C CNN
F 2 "" H 3400 6000 50  0001 C CNN
F 3 "" H 3400 6000 50  0001 C CNN
	1    3400 6000
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0366
U 1 1 5B0C7CE5
P 2800 5600
F 0 "#PWR0366" H 2800 5450 50  0001 C CNN
F 1 "VCC" V 2818 5727 50  0000 L CNN
F 2 "" H 2800 5600 50  0001 C CNN
F 3 "" H 2800 5600 50  0001 C CNN
	1    2800 5600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0367
U 1 1 5B0C7CEB
P 2800 5800
F 0 "#PWR0367" H 2800 5550 50  0001 C CNN
F 1 "GND" V 2805 5672 50  0000 R CNN
F 2 "" H 2800 5800 50  0001 C CNN
F 3 "" H 2800 5800 50  0001 C CNN
	1    2800 5800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0368
U 1 1 5B0C7CF1
P 2800 5900
F 0 "#PWR0368" H 2800 5650 50  0001 C CNN
F 1 "GND" V 2805 5772 50  0000 R CNN
F 2 "" H 2800 5900 50  0001 C CNN
F 3 "" H 2800 5900 50  0001 C CNN
	1    2800 5900
	0    1    1    0   
$EndComp
Wire Notes Line
	500  2900 500  6350
Wire Notes Line
	4500 6350 4500 2900
Text Notes 750  3150 0    50   ~ 0
Control EEPROMs
$Sheet
S 5450 600  550  2300
U 5B0C7EFE
F0 "IN plane decoder" 50
F1 "5_32_decoder.sch" 50
F2 "S0" I L 5450 700 50 
F3 "S1" I L 5450 800 50 
F4 "S2" I L 5450 900 50 
F5 "S3" I L 5450 1000 50 
F6 "O0" I R 6000 700 50 
F7 "O1" I R 6000 800 50 
F8 "O2" I R 6000 900 50 
F9 "O3" I R 6000 1000 50 
F10 "O4" I R 6000 1100 50 
F11 "O5" I R 6000 1200 50 
F12 "O6" I R 6000 1300 50 
F13 "O7" I R 6000 1400 50 
F14 "O8" I R 6000 1500 50 
F15 "O9" I R 6000 1600 50 
F16 "O10" I R 6000 1700 50 
F17 "O11" I R 6000 1800 50 
F18 "O12" I R 6000 1900 50 
F19 "O13" I R 6000 2000 50 
F20 "O14" I R 6000 2100 50 
F21 "O15" I R 6000 2200 50 
F22 "O16" I R 6000 2300 50 
F23 "O17" I R 6000 2400 50 
F24 "O18" I R 6000 2500 50 
F25 "O19" I R 6000 2600 50 
F26 "O20" I R 6000 2700 50 
F27 "O21" I R 6000 2800 50 
F28 "O22" I L 5450 1900 50 
F29 "O23" I L 5450 2000 50 
F30 "O24" I L 5450 2100 50 
F31 "O25" I L 5450 2200 50 
F32 "O26" I L 5450 2300 50 
F33 "O27" I L 5450 2400 50 
F34 "O28" I L 5450 2500 50 
F35 "O29" I L 5450 2600 50 
F36 "O30" I L 5450 2700 50 
F37 "O31" I L 5450 2800 50 
F38 "S4" I L 5450 1100 50 
F39 "~S4" I L 5450 1200 50 
$EndSheet
Text Label 2100 1200 0    50   ~ 0
IN0
Text Label 2100 1300 0    50   ~ 0
IN1
Text Label 2100 1400 0    50   ~ 0
IN2
Text Label 2100 1500 0    50   ~ 0
IN3
Text Label 2100 1600 0    50   ~ 0
IN4
Text Label 3800 1200 0    50   ~ 0
OUT0
Text Label 3800 1300 0    50   ~ 0
OUT1
Text Label 3800 1400 0    50   ~ 0
OUT2
Text Label 3800 1500 0    50   ~ 0
OUT3
Text Label 3800 1600 0    50   ~ 0
OUT4
Text Label 2100 1700 0    50   ~ 0
MULTI0
Text Label 2100 1800 0    50   ~ 0
MULTI1
Text Label 2100 1900 0    50   ~ 0
MULTI2
Text Label 3800 1700 0    50   ~ 0
MULTI3
Text Label 3800 1800 0    50   ~ 0
MULTI_SEL0
Text Label 3800 1900 0    50   ~ 0
MULTI_SEL1
Wire Notes Line
	500  2900 4500 2900
Wire Notes Line
	500  6350 4500 6350
Text Label 5450 700  2    50   ~ 0
IN0
Text Label 5450 800  2    50   ~ 0
IN1
Text Label 5450 900  2    50   ~ 0
IN2
Text Label 5450 1000 2    50   ~ 0
IN3
Text Label 5450 1100 2    50   ~ 0
IN4
Text Label 4500 1200 2    50   ~ 0
IN4
Wire Wire Line
	5100 1200 5450 1200
Text Label 2200 3600 0    50   ~ 0
CTRL0
Text Label 2200 3700 0    50   ~ 0
CTRL1
Text Label 2200 3800 0    50   ~ 0
CTRL2
Text Label 2200 3900 0    50   ~ 0
CTRL3
Text Label 2200 4000 0    50   ~ 0
CTRL4
Text Label 2200 4100 0    50   ~ 0
CTRL5
Text Label 2200 4200 0    50   ~ 0
CTRL6
Text Label 2200 4300 0    50   ~ 0
CTRL7
Text Label 4000 3600 0    50   ~ 0
CTRL8
Text Label 4000 3700 0    50   ~ 0
CTRL9
Text Label 4000 3800 0    50   ~ 0
CTRL10
Text Label 4000 3900 0    50   ~ 0
CTRL11
Text Label 4000 4000 0    50   ~ 0
CTRL12
Text Label 4000 4100 0    50   ~ 0
CTRL13
Text Label 4000 4200 0    50   ~ 0
CTRL14
Text Label 4000 4300 0    50   ~ 0
CTRL15
Text Label 1100 1200 2    50   ~ 0
CTRL0
Text Label 1100 1300 2    50   ~ 0
CTRL1
Text Label 1100 1400 2    50   ~ 0
CTRL2
Text Label 1100 1500 2    50   ~ 0
CTRL3
Text Label 1100 1600 2    50   ~ 0
CTRL4
Text Label 1100 1700 2    50   ~ 0
CTRL5
Text Label 1100 1800 2    50   ~ 0
CTRL6
Text Label 1100 1900 2    50   ~ 0
CTRL7
Text Label 2800 1200 2    50   ~ 0
CTRL8
Text Label 2800 1300 2    50   ~ 0
CTRL9
Text Label 2800 1400 2    50   ~ 0
CTRL10
Text Label 2800 1500 2    50   ~ 0
CTRL11
Text Label 2800 1600 2    50   ~ 0
CTRL12
Text Label 2800 1700 2    50   ~ 0
CTRL13
Text Label 2800 1800 2    50   ~ 0
CTRL14
Text Label 2800 1900 2    50   ~ 0
CTRL15
Wire Notes Line
	550  550  4300 550 
Wire Notes Line
	550  2800 4300 2800
$Sheet
S 5500 3200 550  2300
U 5B0CC7A2
F0 "OUT plane decoder" 50
F1 "5_32_decoder.sch" 50
F2 "S0" I L 5500 3300 50 
F3 "S1" I L 5500 3400 50 
F4 "S2" I L 5500 3500 50 
F5 "S3" I L 5500 3600 50 
F6 "O0" I R 6050 3300 50 
F7 "O1" I R 6050 3400 50 
F8 "O2" I R 6050 3500 50 
F9 "O3" I R 6050 3600 50 
F10 "O4" I R 6050 3700 50 
F11 "O5" I R 6050 3800 50 
F12 "O6" I R 6050 3900 50 
F13 "O7" I R 6050 4000 50 
F14 "O8" I R 6050 4100 50 
F15 "O9" I R 6050 4200 50 
F16 "O10" I R 6050 4300 50 
F17 "O11" I R 6050 4400 50 
F18 "O12" I R 6050 4500 50 
F19 "O13" I R 6050 4600 50 
F20 "O14" I R 6050 4700 50 
F21 "O15" I R 6050 4800 50 
F22 "O16" I R 6050 4900 50 
F23 "O17" I R 6050 5000 50 
F24 "O18" I R 6050 5100 50 
F25 "O19" I R 6050 5200 50 
F26 "O20" I R 6050 5300 50 
F27 "O21" I R 6050 5400 50 
F28 "O22" I L 5500 4500 50 
F29 "O23" I L 5500 4600 50 
F30 "O24" I L 5500 4700 50 
F31 "O25" I L 5500 4800 50 
F32 "O26" I L 5500 4900 50 
F33 "O27" I L 5500 5000 50 
F34 "O28" I L 5500 5100 50 
F35 "O29" I L 5500 5200 50 
F36 "O30" I L 5500 5300 50 
F37 "O31" I L 5500 5400 50 
F38 "S4" I L 5500 3700 50 
F39 "~S4" I L 5500 3800 50 
$EndSheet
Text Label 5500 3300 2    50   ~ 0
OUT0
Text Label 5500 3400 2    50   ~ 0
OUT1
Text Label 5500 3500 2    50   ~ 0
OUT2
Text Label 5500 3600 2    50   ~ 0
OUT3
Text Label 5500 3700 2    50   ~ 0
OUT4
Text Label 4700 3800 2    50   ~ 0
OUT4
Wire Wire Line
	5300 3800 5500 3800
NoConn ~ 6000 700 
NoConn ~ 6050 3300
Text Notes 6100 700  0    50   ~ 0
(none)
Text Notes 6150 3300 0    50   ~ 0
(none)
$Comp
L 74xx:74LS154 U?
U 1 1 5B0D4909
P 7600 4150
AR Path="/5B0C6DCD/5B0C7EFE/5B0D4909" Ref="U?"  Part="1" 
AR Path="/5B0C6DCD/5B0D4909" Ref="U92"  Part="1" 
F 0 "U92" H 7550 4000 50  0000 C CNN
F 1 "74LS154" H 7550 3800 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W7.62mm_Socket" H 7600 4150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS154" H 7600 4150 50  0001 C CNN
	1    7600 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0372
U 1 1 5B0D4910
P 7600 5250
F 0 "#PWR0372" H 7600 5000 50  0001 C CNN
F 1 "GND" H 7605 5077 50  0000 C CNN
F 2 "" H 7600 5250 50  0001 C CNN
F 3 "" H 7600 5250 50  0001 C CNN
	1    7600 5250
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0373
U 1 1 5B0D4916
P 7600 3150
F 0 "#PWR0373" H 7600 3000 50  0001 C CNN
F 1 "VCC" H 7617 3323 50  0000 C CNN
F 2 "" H 7600 3150 50  0001 C CNN
F 3 "" H 7600 3150 50  0001 C CNN
	1    7600 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C102
U 1 1 5B0D491C
P 7950 3150
F 0 "C102" V 7721 3150 50  0000 C CNN
F 1 "0.1uF" V 7812 3150 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 7950 3150 50  0001 C CNN
F 3 "~" H 7950 3150 50  0001 C CNN
	1    7950 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	7850 3150 7600 3150
Connection ~ 7600 3150
$Comp
L power:GND #PWR0374
U 1 1 5B0D4925
P 8050 3150
F 0 "#PWR0374" H 8050 2900 50  0001 C CNN
F 1 "GND" V 8055 3022 50  0000 R CNN
F 2 "" H 8050 3150 50  0001 C CNN
F 3 "" H 8050 3150 50  0001 C CNN
	1    8050 3150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0375
U 1 1 5B0D492B
P 7100 4050
F 0 "#PWR0375" H 7100 3800 50  0001 C CNN
F 1 "GND" V 7105 3922 50  0000 R CNN
F 2 "" H 7100 4050 50  0001 C CNN
F 3 "" H 7100 4050 50  0001 C CNN
	1    7100 4050
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0376
U 1 1 5B0D4BCE
P 7100 3950
F 0 "#PWR0376" H 7100 3700 50  0001 C CNN
F 1 "GND" V 7105 3822 50  0000 R CNN
F 2 "" H 7100 3950 50  0001 C CNN
F 3 "" H 7100 3950 50  0001 C CNN
	1    7100 3950
	0    1    1    0   
$EndComp
Text Label 7100 3450 2    50   ~ 0
MULTI0
Text Label 7100 3550 2    50   ~ 0
MULTI1
Text Label 7100 3650 2    50   ~ 0
MULTI2
Text Label 7100 3750 2    50   ~ 0
MULTI3
Text Label 6000 800  0    50   ~ 0
~A_IN_NCLK
Text Label 6000 900  0    50   ~ 0
~B_IN_NCLK
Text Label 6000 1000 0    50   ~ 0
~M0_IN_NCLK
Text Label 6000 1100 0    50   ~ 0
~M1_IN_NCLK
Text Label 6000 1200 0    50   ~ 0
~M2_IN_NCLK
Text Label 6000 1300 0    50   ~ 0
~S0_IN_NCLK
Text Label 6000 1400 0    50   ~ 0
~S1_IN_NCLK
Text Label 6000 1500 0    50   ~ 0
~S2_IN_NCLK
Text Label 6000 1600 0    50   ~ 0
~K0_IN_NCLK
Text Label 6000 1700 0    50   ~ 0
~K1_IN_NCLK
Text Label 6000 1800 0    50   ~ 0
~K2_IN_NCLK
Text Label 6000 1900 0    50   ~ 0
~PC0_IN_NCLK
Text Label 6000 2000 0    50   ~ 0
~PC1_IN_NCLK
Text Label 6000 2100 0    50   ~ 0
~PC2_IN_NCLK
Text Label 6000 2200 0    50   ~ 0
~MMU0_IN_NCLK
Text Label 6000 2300 0    50   ~ 0
~MMU1_IN_NCLK
Text Label 6000 2400 0    50   ~ 0
~MMU2_IN_NCLK
Text Label 6000 2500 0    50   ~ 0
~MMU_IN_NCLK
Text Label 6000 2600 0    50   ~ 0
~MMU_CONTROL_IN_NCLK
Text Label 6000 2700 0    50   ~ 0
~DISP_IN_NCLK
Text Label 6000 2800 0    50   ~ 0
~TASK_IN_NCLK
Text Label 5450 1900 2    50   ~ 0
~OPCODE0_IN_NCLK
$Sheet
S 7500 550  550  550 
U 5B0C40C8
F0 "IN plane ander 1" 50
F1 "clk_and.sch" 50
F2 "CLK" I L 7500 600 50 
F3 "I0" I L 7500 700 50 
F4 "I1" I L 7500 800 50 
F5 "I2" I L 7500 900 50 
F6 "I3" I L 7500 1000 50 
F7 "O0" I R 8050 600 50 
F8 "O1" I R 8050 700 50 
F9 "O2" I R 8050 800 50 
F10 "O3" I R 8050 900 50 
$EndSheet
$Sheet
S 7500 1250 550  550 
U 5B0C4FE7
F0 "IN plane ander 2" 50
F1 "clk_and.sch" 50
F2 "CLK" I L 7500 1300 50 
F3 "I0" I L 7500 1400 50 
F4 "I1" I L 7500 1500 50 
F5 "I2" I L 7500 1600 50 
F6 "I3" I L 7500 1700 50 
F7 "O0" I R 8050 1300 50 
F8 "O1" I R 8050 1400 50 
F9 "O2" I R 8050 1500 50 
F10 "O3" I R 8050 1600 50 
$EndSheet
$Sheet
S 7500 1950 550  550 
U 5B0C509F
F0 "IN plane ander 3" 50
F1 "clk_and.sch" 50
F2 "CLK" I L 7500 2000 50 
F3 "I0" I L 7500 2100 50 
F4 "I1" I L 7500 2200 50 
F5 "I2" I L 7500 2300 50 
F6 "I3" I L 7500 2400 50 
F7 "O0" I R 8050 2000 50 
F8 "O1" I R 8050 2100 50 
F9 "O2" I R 8050 2200 50 
F10 "O3" I R 8050 2300 50 
$EndSheet
$Sheet
S 9550 550  550  550 
U 5B0C5157
F0 "IN plane ander 4" 50
F1 "clk_and.sch" 50
F2 "CLK" I L 9550 600 50 
F3 "I0" I L 9550 700 50 
F4 "I1" I L 9550 800 50 
F5 "I2" I L 9550 900 50 
F6 "I3" I L 9550 1000 50 
F7 "O0" I R 10100 600 50 
F8 "O1" I R 10100 700 50 
F9 "O2" I R 10100 800 50 
F10 "O3" I R 10100 900 50 
$EndSheet
$Sheet
S 9550 1250 550  550 
U 5B0C520F
F0 "IN plane ander 5" 50
F1 "clk_and.sch" 50
F2 "CLK" I L 9550 1300 50 
F3 "I0" I L 9550 1400 50 
F4 "I1" I L 9550 1500 50 
F5 "I2" I L 9550 1600 50 
F6 "I3" I L 9550 1700 50 
F7 "O0" I R 10100 1300 50 
F8 "O1" I R 10100 1400 50 
F9 "O2" I R 10100 1500 50 
F10 "O3" I R 10100 1600 50 
$EndSheet
$Sheet
S 9550 1950 550  550 
U 5B0C52C7
F0 "IN plane ander 6" 50
F1 "clk_and.sch" 50
F2 "CLK" I L 9550 2000 50 
F3 "I0" I L 9550 2100 50 
F4 "I1" I L 9550 2200 50 
F5 "I2" I L 9550 2300 50 
F6 "I3" I L 9550 2400 50 
F7 "O0" I R 10100 2000 50 
F8 "O1" I R 10100 2100 50 
F9 "O2" I R 10100 2200 50 
F10 "O3" I R 10100 2300 50 
$EndSheet
Text Label 7500 600  2    50   ~ 0
CLK
Text Label 7500 700  2    50   ~ 0
~A_IN_NCLK
Text HLabel 8050 600  2    50   Input ~ 0
~A_IN_CLK
Text Label 7500 800  2    50   ~ 0
~B_IN_NCLK
Text HLabel 8050 700  2    50   Input ~ 0
~B_IN_CLK
Text Label 7500 900  2    50   ~ 0
~M0_IN_NCLK
Text HLabel 8050 800  2    50   Input ~ 0
~M0_IN_CLK
Text Label 7500 1000 2    50   ~ 0
~M1_IN_NCLK
Text HLabel 8050 900  2    50   Input ~ 0
~M1_IN_CLK
Text Label 7500 1300 2    50   ~ 0
CLK
Text Label 7500 1400 2    50   ~ 0
~M2_IN_NCLK
Text HLabel 8050 1300 2    50   Input ~ 0
~M2_IN_CLK
Text Label 7500 1500 2    50   ~ 0
~S0_IN_NCLK
Text HLabel 8050 1400 2    50   Input ~ 0
~S0_IN_CLK
Text Label 7500 1600 2    50   ~ 0
~S1_IN_NCLK
Text HLabel 8050 1500 2    50   Input ~ 0
~S1_IN_CLK
Text Label 7500 1700 2    50   ~ 0
~S2_IN_NCLK
Text HLabel 8050 1600 2    50   Input ~ 0
~S2_IN_CLK
Text Label 7500 2000 2    50   ~ 0
CLK
Text Label 7500 2100 2    50   ~ 0
~K0_IN_NCLK
Text HLabel 8050 2000 2    50   Input ~ 0
~K0_IN_CLK
Text Label 7500 2200 2    50   ~ 0
~K1_IN_NCLK
Text HLabel 8050 2100 2    50   Input ~ 0
~K1_IN_CLK
Text Label 7500 2300 2    50   ~ 0
~K2_IN_NCLK
Text HLabel 8050 2200 2    50   Input ~ 0
~K2_IN_CLK
Text Label 7500 2400 2    50   ~ 0
~PC0_IN_NCLK
Text HLabel 8050 2300 2    50   Input ~ 0
~PC0_IN_CLK
Text Label 9550 600  2    50   ~ 0
CLK
Text Label 9550 700  2    50   ~ 0
~PC1_IN_NCLK
Text HLabel 10100 600  2    50   Input ~ 0
~PC1_IN_CLK
Text Label 9550 800  2    50   ~ 0
~PC2_IN_NCLK
Text HLabel 10100 700  2    50   Input ~ 0
~PC2_IN_CLK
Text Label 9550 900  2    50   ~ 0
~MMU0_IN_NCLK
Text HLabel 10100 800  2    50   Input ~ 0
~MMU0_IN_CLK
Text Label 9550 1000 2    50   ~ 0
~MMU1_IN_NCLK
Text HLabel 10100 900  2    50   Input ~ 0
~MMU1_IN_CLK
Text Label 9550 1300 2    50   ~ 0
CLK
Text Label 9550 1400 2    50   ~ 0
~MMU2_IN_NCLK
Text HLabel 10100 1300 2    50   Input ~ 0
~MMU2_IN_CLK
Text Label 9550 1500 2    50   ~ 0
~MMU_IN_NCLK
Text HLabel 10100 1400 2    50   Input ~ 0
~MMU_IN_CLK
Text Label 9550 1600 2    50   ~ 0
~MMU_CONTROL_IN_NCLK
Text HLabel 10100 1500 2    50   Input ~ 0
~MMU_CONTROL_IN_CLK
Text Label 9550 1700 2    50   ~ 0
~DISP_IN_NCLK
Text HLabel 10100 1600 2    50   Input ~ 0
~DISP_IN_CLK
Text Label 9550 2000 2    50   ~ 0
CLK
Text Label 9550 2100 2    50   ~ 0
~TASK_IN_NCLK
Text HLabel 10100 2000 2    50   Input ~ 0
~TASK_IN_CLK
Text Label 9550 2200 2    50   ~ 0
~OPCODE0_IN_NCLK
Text HLabel 10100 2100 2    50   Input ~ 0
~OPCODE0_IN_CLK
Text HLabel 6050 3400 2    50   Input ~ 0
~A_OUT_NCLK
Text HLabel 6050 3500 2    50   Input ~ 0
~B_OUT_NCLK
Text HLabel 6050 3600 2    50   Input ~ 0
~M0_OUT_NCLK
Text HLabel 6050 3700 2    50   Input ~ 0
~M1_OUT_NCLK
Text HLabel 6050 3800 2    50   Input ~ 0
~M2_OUT_NCLK
Text HLabel 6050 3900 2    50   Input ~ 0
~S0_OUT_NCLK
Text HLabel 6050 4000 2    50   Input ~ 0
~S1_OUT_NCLK
Text HLabel 6050 4100 2    50   Input ~ 0
~S2_OUT_NCLK
Text HLabel 6050 4200 2    50   Input ~ 0
~K0_OUT_NCLK
Text HLabel 6050 4300 2    50   Input ~ 0
~K1_OUT_NCLK
Text HLabel 6050 4400 2    50   Input ~ 0
~K2_OUT_NCLK
Text HLabel 6050 4500 2    50   Input ~ 0
~STATUS_OUT_NCLK
Text HLabel 6050 4600 2    50   Input ~ 0
~INTERRUPT_OUT_NCLK
Text HLabel 6050 4700 2    50   Input ~ 0
~SUM_OUT_NCLK
Text HLabel 6050 4800 2    50   Input ~ 0
~MMU_OUT_NCLK
Text HLabel 6050 4900 2    50   Input ~ 0
~MMU_CONTROL_OUT_NCLK
Text HLabel 6050 5000 2    50   Input ~ 0
~TASK_OUT_NCLK
Text HLabel 6050 5100 2    50   Input ~ 0
~MLU_OUT_NCLK
NoConn ~ 8100 3450
Text Notes 8200 3450 0    50   ~ 0
(none)
Text HLabel 8100 3550 2    50   Input ~ 0
~SUB_NCLK
Text HLabel 8100 3650 2    50   Input ~ 0
~RESET_NCLK
Text HLabel 8100 3750 2    50   Input ~ 0
~RESET_UOP_COUNT_NCLK
Text HLabel 8100 3850 2    50   Input ~ 0
~SET_INT_ENABLE_SYNC
Text HLabel 8100 3950 2    50   Input ~ 0
~UNSET_INT_ENABLE_SYNC
$Sheet
S 9800 3300 550  550 
U 5B0D9773
F0 "CTRL plane ander 1" 50
F1 "clk_and.sch" 50
F2 "CLK" I L 9800 3350 50 
F3 "I0" I L 9800 3450 50 
F4 "I1" I L 9800 3550 50 
F5 "I2" I L 9800 3650 50 
F6 "I3" I L 9800 3750 50 
F7 "O0" I R 10350 3350 50 
F8 "O1" I R 10350 3450 50 
F9 "O2" I R 10350 3550 50 
F10 "O3" I R 10350 3650 50 
$EndSheet
$Sheet
S 9800 4000 550  550 
U 5B0D9954
F0 "CTRL plane ander 2" 50
F1 "clk_and.sch" 50
F2 "CLK" I L 9800 4050 50 
F3 "I0" I L 9800 4150 50 
F4 "I1" I L 9800 4250 50 
F5 "I2" I L 9800 4350 50 
F6 "I3" I L 9800 4450 50 
F7 "O0" I R 10350 4050 50 
F8 "O1" I R 10350 4150 50 
F9 "O2" I R 10350 4250 50 
F10 "O3" I R 10350 4350 50 
$EndSheet
Text Label 8100 4050 0    50   ~ 0
~PC_INC_NCLK
Text Label 8100 4150 0    50   ~ 0
~OPCODE0_INC_NCLK
Text Label 8100 4250 0    50   ~ 0
~OPCODE1_INC_NCLK
Text Label 8100 4350 0    50   ~ 0
~SP_INC_NCLK
Text Label 8100 4450 0    50   ~ 0
~SP_DEC_NCLK
Text Label 8100 4550 0    50   ~ 0
~KSP_INC_NCLK
Text Label 8100 4650 0    50   ~ 0
~KSP_DEC_NCLK
Text Label 8100 4750 0    50   ~ 0
~ALU_FLAG_SET_NCLK
$Comp
L 74xx:74HC04 U?
U 4 1 5B0E60C2
P 4800 1200
AR Path="/5ADF0E03/5B0E60C2" Ref="U?"  Part="4" 
AR Path="/5B0E60C2" Ref="U?"  Part="4" 
AR Path="/5B0C6DCD/5B0E60C2" Ref="U5"  Part="4" 
F 0 "U5" H 4800 1517 50  0000 C CNN
F 1 "74HC04" H 4800 1426 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 4800 1200 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 4800 1200 50  0001 C CNN
	4    4800 1200
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 5 1 5B0E60C9
P 5000 3800
AR Path="/5ADF0E03/5B0E60C9" Ref="U?"  Part="5" 
AR Path="/5B0E60C9" Ref="U?"  Part="5" 
AR Path="/5B0C6DCD/5B0E60C9" Ref="U5"  Part="5" 
F 0 "U5" H 5000 4117 50  0000 C CNN
F 1 "74HC04" H 5000 4026 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5000 3800 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 5000 3800 50  0001 C CNN
	5    5000 3800
	1    0    0    -1  
$EndComp
Text Notes 4300 650  0    50   ~ 0
Note: Not gates on decoders\ntaken from CLK sheet.
Text Notes 3650 250  0    50   ~ 0
TODO: if add more nots, replace these nots with closer ones.
Text Notes -1000 9200 0    197  ~ 0
TODO: Interrupt logic\nPage fault logic\nSelect MULTI based on MULTI_SEL\nMicro-op counter
Text Label 5450 2000 2    50   ~ 0
~OPCODE1_IN_NCLK
Text Label 9550 2300 2    50   ~ 0
~OPCODE1_IN_NCLK
Text HLabel 10100 2200 2    50   Input ~ 0
~OPCODE1_IN_CLK
Text Label 9800 3350 2    50   ~ 0
CLK
Text Label 9800 3450 2    50   ~ 0
~PC_INC_NCLK
Text HLabel 10350 3350 2    50   Input ~ 0
~PC_INC_CLK
Text Label 9800 3550 2    50   ~ 0
~OPCODE0_INC_NCLK
Text HLabel 10350 3450 2    50   Input ~ 0
~OPCODE0_INC_CLK
Text Label 9800 3650 2    50   ~ 0
~OPCODE1_INC_NCLK
Text HLabel 10350 3550 2    50   Input ~ 0
~OPCODE1_INC_CLK
Text Label 9800 3750 2    50   ~ 0
~SP_INC_NCLK
Text HLabel 10350 3650 2    50   Input ~ 0
~SP_INC_CLK
Text Label 9800 4050 2    50   ~ 0
CLK
Text Label 9800 4150 2    50   ~ 0
~SP_DEC_NCLK
Text HLabel 10350 4050 2    50   Input ~ 0
~SP_DEC_CLK
Text Label 9800 4250 2    50   ~ 0
~KSP_INC_NCLK
Text HLabel 10350 4150 2    50   Input ~ 0
~KSP_INC_CLK
Text Label 9800 4350 2    50   ~ 0
~KSP_DEC_NCLK
Text HLabel 10350 4250 2    50   Input ~ 0
~KSP_DEC_CLK
Text Label 9800 4450 2    50   ~ 0
~ALU_FLAG_SET_NCLK
Text HLabel 10350 4350 2    50   Input ~ 0
~ALU_FLAG_SET_CLK
$Sheet
S 5400 5850 900  1500
U 5B0D66CF
F0 "Opcode Register" 50
F1 "opcode_register.sch" 50
F2 "BUS0" I L 5400 5950 50 
F3 "BUS1" I L 5400 6050 50 
F4 "BUS2" I L 5400 6150 50 
F5 "BUS3" I L 5400 6250 50 
F6 "BUS4" I L 5400 6350 50 
F7 "BUS5" I L 5400 6450 50 
F8 "BUS6" I L 5400 6550 50 
F9 "BUS7" I L 5400 6650 50 
F10 "~OPCODE0_IN" I L 5400 6750 50 
F11 "~RESET" I L 5400 6850 50 
F12 "CLK" I L 5400 6950 50 
F13 "OPCODE0_INC" I L 5400 7050 50 
F14 "~OPCODE1_IN" I L 5400 7150 50 
F15 "OPCODE1_INC" I L 5400 7250 50 
F16 "O0" I R 6300 5950 50 
F17 "O1" I R 6300 6050 50 
F18 "O2" I R 6300 6150 50 
F19 "O3" I R 6300 6250 50 
F20 "O4" I R 6300 6350 50 
F21 "O5" I R 6300 6450 50 
F22 "O6" I R 6300 6550 50 
F23 "O7" I R 6300 6650 50 
F24 "O8" I R 6300 6750 50 
F25 "O9" I R 6300 6850 50 
F26 "O10" I R 6300 6950 50 
F27 "O11" I R 6300 7050 50 
$EndSheet
Text HLabel 5400 5950 0    50   Input ~ 0
BUS0
Text HLabel 5400 6050 0    50   Input ~ 0
BUS1
Text HLabel 5400 6150 0    50   Input ~ 0
BUS2
Text HLabel 5400 6250 0    50   Input ~ 0
BUS3
Text HLabel 5400 6350 0    50   Input ~ 0
BUS4
Text HLabel 5400 6450 0    50   Input ~ 0
BUS5
Text HLabel 5400 6550 0    50   Input ~ 0
BUS6
Text HLabel 5400 6650 0    50   Input ~ 0
BUS7
Text Label 6300 5950 0    50   ~ 0
OP0
Text Label 6300 6050 0    50   ~ 0
OP1
Text Label 6300 6150 0    50   ~ 0
OP2
Text Label 6300 6250 0    50   ~ 0
OP3
Text Label 6300 6350 0    50   ~ 0
OP4
Text Label 6300 6450 0    50   ~ 0
OP5
Text Label 6300 6550 0    50   ~ 0
OP6
Text Label 6300 6650 0    50   ~ 0
OP7
Text Label 6300 6750 0    50   ~ 0
OP8
Text Label 6300 6850 0    50   ~ 0
OP9
Text Label 6300 6950 0    50   ~ 0
OP10
Text Label 6300 7050 0    50   ~ 0
OP11
Text Label 1000 3600 2    50   ~ 0
OP0
Text Label 1000 3700 2    50   ~ 0
OP1
Text Label 1000 3800 2    50   ~ 0
OP2
Text Label 1000 3900 2    50   ~ 0
OP3
Text Label 1000 4000 2    50   ~ 0
OP4
Text Label 1000 4100 2    50   ~ 0
OP5
Text Label 1000 4200 2    50   ~ 0
OP6
Text Label 1000 4300 2    50   ~ 0
OP7
Text Label 1000 4400 2    50   ~ 0
OP8
Text Label 1000 4500 2    50   ~ 0
OP9
Text Label 1000 4600 2    50   ~ 0
OP10
Text Label 1000 4700 2    50   ~ 0
OP11
Text Label 2800 3600 2    50   ~ 0
OP0
Text Label 2800 3700 2    50   ~ 0
OP1
Text Label 2800 3800 2    50   ~ 0
OP2
Text Label 2800 3900 2    50   ~ 0
OP3
Text Label 2800 4000 2    50   ~ 0
OP4
Text Label 2800 4100 2    50   ~ 0
OP5
Text Label 2800 4200 2    50   ~ 0
OP6
Text Label 2800 4300 2    50   ~ 0
OP7
Text Label 2800 4400 2    50   ~ 0
OP8
Text Label 2800 4500 2    50   ~ 0
OP9
Text Label 2800 4600 2    50   ~ 0
OP10
Text Label 2800 4700 2    50   ~ 0
OP11
$Sheet
S 6950 5800 550  500 
U 5B0D9D66
F0 "Micro Op Counter" 50
F1 "microop_counter.sch" 50
F2 "~RESET" I L 6950 5900 50 
F3 "~CLK" I L 6950 6000 50 
F4 "O0" I R 7500 5900 50 
F5 "O1" I R 7500 6000 50 
F6 "O2" I R 7500 6100 50 
F7 "O3" I R 7500 6200 50 
$EndSheet
Text Label 7500 5900 0    50   ~ 0
MICROOP0
Text Label 7500 6000 0    50   ~ 0
MICROOP1
Text Label 7500 6100 0    50   ~ 0
MICROOP2
Text Label 7500 6200 0    50   ~ 0
MICROOP3
Text Label 1000 4800 2    50   ~ 0
MICROOP0
Text Label 1000 4900 2    50   ~ 0
MICROOP1
Text Label 1000 5000 2    50   ~ 0
MICROOP2
Text Label 1000 5100 2    50   ~ 0
MICROOP3
Text Label 2800 4800 2    50   ~ 0
MICROOP0
Text Label 2800 4900 2    50   ~ 0
MICROOP1
Text Label 2800 5000 2    50   ~ 0
MICROOP2
Text Label 2800 5100 2    50   ~ 0
MICROOP3
$EndSCHEMATC
