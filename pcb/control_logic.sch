EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A2 23386 16535
encoding utf-8
Sheet 25 30
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
P 1900 3900
F 0 "U87" H 1900 3700 50  0000 C CNN
F 1 "74LS574" H 1950 3600 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 1900 3900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS574" H 1900 3900 50  0001 C CNN
	1    1900 3900
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0351
U 1 1 5B0C6FCF
P 1900 3100
F 0 "#PWR0351" H 1900 2950 50  0001 C CNN
F 1 "VCC" H 1917 3273 50  0000 C CNN
F 2 "" H 1900 3100 50  0001 C CNN
F 3 "" H 1900 3100 50  0001 C CNN
	1    1900 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0352
U 1 1 5B0C7016
P 1900 4700
F 0 "#PWR0352" H 1900 4450 50  0001 C CNN
F 1 "GND" H 1905 4527 50  0000 C CNN
F 2 "" H 1900 4700 50  0001 C CNN
F 3 "" H 1900 4700 50  0001 C CNN
	1    1900 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C98
U 1 1 5B0C7064
P 2150 3100
F 0 "C98" V 1921 3100 50  0000 C CNN
F 1 "0.1uF" V 2012 3100 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2150 3100 50  0001 C CNN
F 3 "~" H 2150 3100 50  0001 C CNN
	1    2150 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 3100 2050 3100
Connection ~ 1900 3100
$Comp
L power:GND #PWR0353
U 1 1 5B0C70CB
P 2250 3100
F 0 "#PWR0353" H 2250 2850 50  0001 C CNN
F 1 "GND" V 2255 2972 50  0000 R CNN
F 2 "" H 2250 3100 50  0001 C CNN
F 3 "" H 2250 3100 50  0001 C CNN
	1    2250 3100
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74LS574 U89
U 1 1 5B0C714D
P 3900 3900
F 0 "U89" H 3900 3700 50  0000 C CNN
F 1 "74LS574" H 3950 3600 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 3900 3900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS574" H 3900 3900 50  0001 C CNN
	1    3900 3900
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0354
U 1 1 5B0C7154
P 3900 3100
F 0 "#PWR0354" H 3900 2950 50  0001 C CNN
F 1 "VCC" H 3917 3273 50  0000 C CNN
F 2 "" H 3900 3100 50  0001 C CNN
F 3 "" H 3900 3100 50  0001 C CNN
	1    3900 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0355
U 1 1 5B0C715A
P 3900 4700
F 0 "#PWR0355" H 3900 4450 50  0001 C CNN
F 1 "GND" H 3905 4527 50  0000 C CNN
F 2 "" H 3900 4700 50  0001 C CNN
F 3 "" H 3900 4700 50  0001 C CNN
	1    3900 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C100
U 1 1 5B0C7160
P 4150 3100
F 0 "C100" V 3921 3100 50  0000 C CNN
F 1 "0.1uF" V 4012 3100 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4150 3100 50  0001 C CNN
F 3 "~" H 4150 3100 50  0001 C CNN
	1    4150 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	3900 3100 4050 3100
Connection ~ 3900 3100
$Comp
L power:GND #PWR0356
U 1 1 5B0C7169
P 4250 3100
F 0 "#PWR0356" H 4250 2850 50  0001 C CNN
F 1 "GND" V 4255 2972 50  0000 R CNN
F 2 "" H 4250 3100 50  0001 C CNN
F 3 "" H 4250 3100 50  0001 C CNN
	1    4250 3100
	0    -1   -1   0   
$EndComp
Wire Notes Line
	6900 5000 6900 2750
Text Notes 2650 2950 0    50   ~ 0
Control word latch
$Comp
L power:VCC #PWR0357
U 1 1 5B0C730F
P 2200 5700
F 0 "#PWR0357" H 2200 5550 50  0001 C CNN
F 1 "VCC" H 2217 5873 50  0000 C CNN
F 2 "" H 2200 5700 50  0001 C CNN
F 3 "" H 2200 5700 50  0001 C CNN
	1    2200 5700
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C99
U 1 1 5B0C7315
P 2500 5500
F 0 "C99" V 2271 5500 50  0000 C CNN
F 1 "0.1uF" V 2362 5500 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2500 5500 50  0001 C CNN
F 3 "~" H 2500 5500 50  0001 C CNN
	1    2500 5500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0358
U 1 1 5B0C731C
P 2600 5500
F 0 "#PWR0358" H 2600 5250 50  0001 C CNN
F 1 "GND" V 2605 5372 50  0000 R CNN
F 2 "" H 2600 5500 50  0001 C CNN
F 3 "" H 2600 5500 50  0001 C CNN
	1    2600 5500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2200 5700 2400 5700
Wire Wire Line
	2400 5700 2400 5500
$Comp
L power:GND #PWR0359
U 1 1 5B0C740B
P 2200 8200
F 0 "#PWR0359" H 2200 7950 50  0001 C CNN
F 1 "GND" H 2205 8027 50  0000 C CNN
F 2 "" H 2200 8200 50  0001 C CNN
F 3 "" H 2200 8200 50  0001 C CNN
	1    2200 8200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0360
U 1 1 5B0C7919
P 1600 7800
F 0 "#PWR0360" H 1600 7650 50  0001 C CNN
F 1 "VCC" V 1618 7927 50  0000 L CNN
F 2 "" H 1600 7800 50  0001 C CNN
F 3 "" H 1600 7800 50  0001 C CNN
	1    1600 7800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0361
U 1 1 5B0C7972
P 1600 8000
F 0 "#PWR0361" H 1600 7750 50  0001 C CNN
F 1 "GND" V 1605 7872 50  0000 R CNN
F 2 "" H 1600 8000 50  0001 C CNN
F 3 "" H 1600 8000 50  0001 C CNN
	1    1600 8000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0362
U 1 1 5B0C798F
P 1600 8100
F 0 "#PWR0362" H 1600 7850 50  0001 C CNN
F 1 "GND" V 1605 7972 50  0000 R CNN
F 2 "" H 1600 8100 50  0001 C CNN
F 3 "" H 1600 8100 50  0001 C CNN
	1    1600 8100
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0363
U 1 1 5B0C7CC9
P 4000 5700
F 0 "#PWR0363" H 4000 5550 50  0001 C CNN
F 1 "VCC" H 4017 5873 50  0000 C CNN
F 2 "" H 4000 5700 50  0001 C CNN
F 3 "" H 4000 5700 50  0001 C CNN
	1    4000 5700
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C101
U 1 1 5B0C7CCF
P 4300 5500
F 0 "C101" V 4071 5500 50  0000 C CNN
F 1 "0.1uF" V 4162 5500 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4300 5500 50  0001 C CNN
F 3 "~" H 4300 5500 50  0001 C CNN
	1    4300 5500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0364
U 1 1 5B0C7CD6
P 4400 5500
F 0 "#PWR0364" H 4400 5250 50  0001 C CNN
F 1 "GND" V 4405 5372 50  0000 R CNN
F 2 "" H 4400 5500 50  0001 C CNN
F 3 "" H 4400 5500 50  0001 C CNN
	1    4400 5500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4000 5700 4200 5700
Wire Wire Line
	4200 5700 4200 5500
$Comp
L power:GND #PWR0365
U 1 1 5B0C7CDF
P 4000 8200
F 0 "#PWR0365" H 4000 7950 50  0001 C CNN
F 1 "GND" H 4005 8027 50  0000 C CNN
F 2 "" H 4000 8200 50  0001 C CNN
F 3 "" H 4000 8200 50  0001 C CNN
	1    4000 8200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0366
U 1 1 5B0C7CE5
P 3400 7800
F 0 "#PWR0366" H 3400 7650 50  0001 C CNN
F 1 "VCC" V 3418 7927 50  0000 L CNN
F 2 "" H 3400 7800 50  0001 C CNN
F 3 "" H 3400 7800 50  0001 C CNN
	1    3400 7800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0367
U 1 1 5B0C7CEB
P 3400 8000
F 0 "#PWR0367" H 3400 7750 50  0001 C CNN
F 1 "GND" V 3405 7872 50  0000 R CNN
F 2 "" H 3400 8000 50  0001 C CNN
F 3 "" H 3400 8000 50  0001 C CNN
	1    3400 8000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0368
U 1 1 5B0C7CF1
P 3400 8100
F 0 "#PWR0368" H 3400 7850 50  0001 C CNN
F 1 "GND" V 3405 7972 50  0000 R CNN
F 2 "" H 3400 8100 50  0001 C CNN
F 3 "" H 3400 8100 50  0001 C CNN
	1    3400 8100
	0    1    1    0   
$EndComp
Text Notes 1350 5350 0    50   ~ 0
Control EEPROMs
Wire Wire Line
	2200 9700 2550 9700
Text Label 2800 5800 0    50   ~ 0
CTRL0
Text Label 2800 5900 0    50   ~ 0
CTRL1
Text Label 2800 6000 0    50   ~ 0
CTRL2
Text Label 2800 6100 0    50   ~ 0
CTRL3
Text Label 2800 6200 0    50   ~ 0
CTRL4
Text Label 2800 6300 0    50   ~ 0
CTRL5
Text Label 2800 6400 0    50   ~ 0
CTRL6
Text Label 2800 6500 0    50   ~ 0
CTRL7
Text Label 4600 5800 0    50   ~ 0
CTRL8
Text Label 4600 5900 0    50   ~ 0
CTRL9
Text Label 4600 6000 0    50   ~ 0
CTRL10
Text Label 4600 6100 0    50   ~ 0
CTRL11
Text Label 4600 6200 0    50   ~ 0
CTRL12
Text Label 4600 6300 0    50   ~ 0
CTRL13
Text Label 4600 6400 0    50   ~ 0
CTRL14
Text Label 4600 6500 0    50   ~ 0
CTRL15
Text Label 1400 3400 2    50   ~ 0
CTRL0
Text Label 1400 3500 2    50   ~ 0
CTRL1
Text Label 1400 3600 2    50   ~ 0
CTRL2
Text Label 1400 3700 2    50   ~ 0
CTRL3
Text Label 1400 3800 2    50   ~ 0
CTRL4
Text Label 1400 3900 2    50   ~ 0
CTRL5
Text Label 1400 4000 2    50   ~ 0
CTRL6
Text Label 1400 4100 2    50   ~ 0
CTRL7
Text Label 3400 3400 2    50   ~ 0
CTRL8
Text Label 3400 3500 2    50   ~ 0
CTRL9
Text Label 3400 3600 2    50   ~ 0
CTRL10
Text Label 3400 3700 2    50   ~ 0
CTRL11
Text Label 3400 3800 2    50   ~ 0
CTRL12
Text Label 3400 3900 2    50   ~ 0
CTRL13
Text Label 3400 4000 2    50   ~ 0
CTRL14
Text Label 3400 4100 2    50   ~ 0
CTRL15
Wire Wire Line
	8000 3400 8200 3400
NoConn ~ 8750 2900
Text Notes 8850 2900 0    50   ~ 0
(none)
$Comp
L 74xx:74LS154 U?
U 1 1 5B0D4909
P 8150 6850
AR Path="/5B0C6DCD/5B0C7EFE/5B0D4909" Ref="U?"  Part="1" 
AR Path="/5B0C6DCD/5B0D4909" Ref="U92"  Part="1" 
F 0 "U92" H 8100 6700 50  0000 C CNN
F 1 "74LS154" H 8100 6500 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W7.62mm_Socket" H 8150 6850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS154" H 8150 6850 50  0001 C CNN
	1    8150 6850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0372
U 1 1 5B0D4910
P 8150 7950
F 0 "#PWR0372" H 8150 7700 50  0001 C CNN
F 1 "GND" H 8155 7777 50  0000 C CNN
F 2 "" H 8150 7950 50  0001 C CNN
F 3 "" H 8150 7950 50  0001 C CNN
	1    8150 7950
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0373
U 1 1 5B0D4916
P 8150 5850
F 0 "#PWR0373" H 8150 5700 50  0001 C CNN
F 1 "VCC" H 8167 6023 50  0000 C CNN
F 2 "" H 8150 5850 50  0001 C CNN
F 3 "" H 8150 5850 50  0001 C CNN
	1    8150 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C102
U 1 1 5B0D491C
P 8500 5850
F 0 "C102" V 8271 5850 50  0000 C CNN
F 1 "0.1uF" V 8362 5850 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 8500 5850 50  0001 C CNN
F 3 "~" H 8500 5850 50  0001 C CNN
	1    8500 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	8400 5850 8150 5850
$Comp
L power:GND #PWR0374
U 1 1 5B0D4925
P 8600 5850
F 0 "#PWR0374" H 8600 5600 50  0001 C CNN
F 1 "GND" V 8605 5722 50  0000 R CNN
F 2 "" H 8600 5850 50  0001 C CNN
F 3 "" H 8600 5850 50  0001 C CNN
	1    8600 5850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0375
U 1 1 5B0D492B
P 7650 6750
F 0 "#PWR0375" H 7650 6500 50  0001 C CNN
F 1 "GND" V 7655 6622 50  0000 R CNN
F 2 "" H 7650 6750 50  0001 C CNN
F 3 "" H 7650 6750 50  0001 C CNN
	1    7650 6750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0376
U 1 1 5B0D4BCE
P 7650 6650
F 0 "#PWR0376" H 7650 6400 50  0001 C CNN
F 1 "GND" V 7655 6522 50  0000 R CNN
F 2 "" H 7650 6650 50  0001 C CNN
F 3 "" H 7650 6650 50  0001 C CNN
	1    7650 6650
	0    1    1    0   
$EndComp
Text HLabel 8750 3000 2    50   Input ~ 0
~A_OUT_NCLK
Text HLabel 8750 3100 2    50   Input ~ 0
~B_OUT_NCLK
Text HLabel 8750 3200 2    50   Input ~ 0
~M0_OUT_NCLK
Text HLabel 8750 3300 2    50   Input ~ 0
~M1_OUT_NCLK
Text HLabel 8750 3400 2    50   Input ~ 0
~M2_OUT_NCLK
Text HLabel 8750 3500 2    50   Input ~ 0
~S0_OUT_NCLK
Text HLabel 8750 3600 2    50   Input ~ 0
~S1_OUT_NCLK
Text HLabel 8750 3700 2    50   Input ~ 0
~S2_OUT_NCLK
Text HLabel 8750 4100 2    50   Input ~ 0
~STATUS_OUT_NCLK
Text HLabel 8750 4200 2    50   Input ~ 0
~INT_OUT_NCLK
Text HLabel 8750 4300 2    50   Input ~ 0
~MMU_OUT_NCLK
Text HLabel 8750 4400 2    50   Input ~ 0
~MMU_CONTROL_OUT_NCLK
Text HLabel 8750 4500 2    50   Input ~ 0
~TASK_OUT_NCLK
Text HLabel 8750 4600 2    50   Input ~ 0
~MLU_OUT_NCLK
NoConn ~ 8650 6150
Text Notes 8750 6150 0    50   ~ 0
(none)
Text HLabel 8650 6250 2    50   Input ~ 0
~RESET_NCLK
Text HLabel 8650 6450 2    50   Input ~ 0
~SET_INT_ENABLE_ASYNC
Text HLabel 8650 6550 2    50   Input ~ 0
~UNSET_INT_ENABLE_ASYNC
$Sheet
S 10600 2850 900  1500
U 5B0D66CF
F0 "Opcode Register" 50
F1 "opcode_register.sch" 50
F2 "BUS0" I L 10600 2950 50 
F3 "BUS1" I L 10600 3050 50 
F4 "BUS2" I L 10600 3150 50 
F5 "BUS3" I L 10600 3250 50 
F6 "BUS4" I L 10600 3350 50 
F7 "BUS5" I L 10600 3450 50 
F8 "BUS6" I L 10600 3550 50 
F9 "BUS7" I L 10600 3650 50 
F10 "~OPCODE0_IN" I L 10600 3750 50 
F11 "~RESET" I L 10600 4050 50 
F12 "CLK" I L 10600 3950 50 
F13 "~OPCODE1_IN" I L 10600 3850 50 
F14 "O0" I R 11500 2950 50 
F15 "O1" I R 11500 3050 50 
F16 "O2" I R 11500 3150 50 
F17 "O3" I R 11500 3250 50 
F18 "O4" I R 11500 3350 50 
F19 "O5" I R 11500 3450 50 
F20 "O6" I R 11500 3550 50 
F21 "O7" I R 11500 3650 50 
F22 "O8" I R 11500 3750 50 
F23 "O9" I R 11500 3850 50 
F24 "O10" I R 11500 3950 50 
F25 "O11" I R 11500 4050 50 
$EndSheet
Text HLabel 10600 2950 0    50   Input ~ 0
BUS0
Text HLabel 10600 3050 0    50   Input ~ 0
BUS1
Text HLabel 10600 3150 0    50   Input ~ 0
BUS2
Text HLabel 10600 3250 0    50   Input ~ 0
BUS3
Text HLabel 10600 3350 0    50   Input ~ 0
BUS4
Text HLabel 10600 3450 0    50   Input ~ 0
BUS5
Text HLabel 10600 3550 0    50   Input ~ 0
BUS6
Text HLabel 10600 3650 0    50   Input ~ 0
BUS7
Text Label 11500 2950 0    50   ~ 0
OP0
Text Label 11500 3050 0    50   ~ 0
OP1
Text Label 11500 3150 0    50   ~ 0
OP2
Text Label 11500 3250 0    50   ~ 0
OP3
Text Label 11500 3350 0    50   ~ 0
OP4
Text Label 11500 3450 0    50   ~ 0
OP5
Text Label 11500 3550 0    50   ~ 0
OP6
Text Label 11500 3650 0    50   ~ 0
OP7
Text Label 11500 3750 0    50   ~ 0
OP8
Text Label 11500 3850 0    50   ~ 0
OP9
Text Label 11500 3950 0    50   ~ 0
OP10
Text Label 11500 4050 0    50   ~ 0
OP11
Text Label 1600 5800 2    50   ~ 0
OP0
Text Label 1600 5900 2    50   ~ 0
OP1
Text Label 1600 6000 2    50   ~ 0
OP2
Text Label 1600 6100 2    50   ~ 0
OP3
Text Label 1600 6200 2    50   ~ 0
OP4
Text Label 1600 6300 2    50   ~ 0
OP5
Text Label 1600 6400 2    50   ~ 0
OP6
Text Label 1600 6500 2    50   ~ 0
OP7
Text Label 1600 6600 2    50   ~ 0
OP8
Text Label 1600 6700 2    50   ~ 0
OP9
Text Label 1600 6800 2    50   ~ 0
OP10
Text Label 1600 6900 2    50   ~ 0
OP11
Text Label 3400 5800 2    50   ~ 0
OP0
Text Label 3400 5900 2    50   ~ 0
OP1
Text Label 3400 6000 2    50   ~ 0
OP2
Text Label 3400 6100 2    50   ~ 0
OP3
Text Label 3400 6200 2    50   ~ 0
OP4
Text Label 3400 6300 2    50   ~ 0
OP5
Text Label 3400 6400 2    50   ~ 0
OP6
Text Label 3400 6500 2    50   ~ 0
OP7
Text Label 3400 6600 2    50   ~ 0
OP8
Text Label 3400 6700 2    50   ~ 0
OP9
Text Label 3400 6800 2    50   ~ 0
OP10
Text Label 3400 6900 2    50   ~ 0
OP11
$Sheet
S 12700 2850 550  500 
U 5B0D9D66
F0 "Micro Op Counter" 50
F1 "microop_counter.sch" 50
F2 "~RESET" I L 12700 2950 50 
F3 "CLK" I L 12700 3050 50 
F4 "O0" I R 13250 2950 50 
F5 "O1" I R 13250 3050 50 
F6 "O2" I R 13250 3150 50 
F7 "O3" I R 13250 3250 50 
$EndSheet
Text Label 13250 2950 0    50   ~ 0
MICROOP0
Text Label 13250 3050 0    50   ~ 0
MICROOP1
Text Label 13250 3150 0    50   ~ 0
MICROOP2
Text Label 13250 3250 0    50   ~ 0
MICROOP3
Text Label 1600 7000 2    50   ~ 0
MICROOP0
Text Label 1600 7100 2    50   ~ 0
MICROOP1
Text Label 1600 7200 2    50   ~ 0
MICROOP2
Text Label 1600 7300 2    50   ~ 0
MICROOP3
Text Label 3400 7000 2    50   ~ 0
MICROOP0
Text Label 3400 7100 2    50   ~ 0
MICROOP1
Text Label 3400 7200 2    50   ~ 0
MICROOP2
Text Label 3400 7300 2    50   ~ 0
MICROOP3
NoConn ~ 8650 7550
NoConn ~ 8650 7650
$Sheet
S 12650 3550 1050 1100
U 5B101C06
F0 "Flag Logic" 50
F1 "flag_logic.sch" 50
F2 "INT_FLAG" I R 13700 4150 50 
F3 "INT0" I L 12650 3650 50 
F4 "INT1" I L 12650 3750 50 
F5 "INT2" I L 12650 3850 50 
F6 "INT3" I L 12650 3950 50 
F7 "INT4" I L 12650 4050 50 
F8 "INT5" I L 12650 4150 50 
F9 "INT6" I L 12650 4250 50 
F10 "INT7" I L 12650 4350 50 
F11 "MMU_READ_FAULT" I L 12650 4450 50 
F12 "MMU_WRITE_FAULT" I L 12650 4550 50 
F13 "MMU_FAULT_FLAG" I R 13700 3750 50 
$EndSheet
Text Label 14500 4750 0    50   ~ 0
INT_FLAG
Text Label 1600 7400 2    50   ~ 0
INT_FLAG
Text Label 3400 7400 2    50   ~ 0
INT_FLAG
$Comp
L power:GND #PWR0369
U 1 1 5B1046F6
P 3400 7600
F 0 "#PWR0369" H 3400 7350 50  0001 C CNN
F 1 "GND" V 3405 7472 50  0000 R CNN
F 2 "" H 3400 7600 50  0001 C CNN
F 3 "" H 3400 7600 50  0001 C CNN
	1    3400 7600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0370
U 1 1 5B104719
P 1600 7600
F 0 "#PWR0370" H 1600 7350 50  0001 C CNN
F 1 "GND" V 1605 7472 50  0000 R CNN
F 2 "" H 1600 7600 50  0001 C CNN
F 3 "" H 1600 7600 50  0001 C CNN
	1    1600 7600
	0    1    1    0   
$EndComp
Text Label 3400 7500 2    50   ~ 0
MMU_FAULT_FLAG
Text Label 1600 7500 2    50   ~ 0
MMU_FAULT_FLAG
Text HLabel 12650 4450 0    50   Input ~ 0
MMU_READ_FAULT
Text HLabel 12650 4550 0    50   Input ~ 0
MMU_WRITE_FAULT
Text Label 13700 3750 0    50   ~ 0
MMU_FAULT_FLAG
NoConn ~ 8200 4200
$Comp
L power:VCC #PWR0371
U 1 1 5B10FF24
P 5950 5650
F 0 "#PWR0371" H 5950 5500 50  0001 C CNN
F 1 "VCC" H 5967 5823 50  0000 C CNN
F 2 "" H 5950 5650 50  0001 C CNN
F 3 "" H 5950 5650 50  0001 C CNN
	1    5950 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C124
U 1 1 5B10FF2A
P 6250 5450
F 0 "C124" V 6021 5450 50  0000 C CNN
F 1 "0.1uF" V 6112 5450 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 6250 5450 50  0001 C CNN
F 3 "~" H 6250 5450 50  0001 C CNN
	1    6250 5450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0417
U 1 1 5B10FF31
P 6350 5450
F 0 "#PWR0417" H 6350 5200 50  0001 C CNN
F 1 "GND" V 6355 5322 50  0000 R CNN
F 2 "" H 6350 5450 50  0001 C CNN
F 3 "" H 6350 5450 50  0001 C CNN
	1    6350 5450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5950 5650 6150 5650
Wire Wire Line
	6150 5650 6150 5450
Connection ~ 5950 5650
$Comp
L power:GND #PWR0418
U 1 1 5B10FF3A
P 5950 8150
F 0 "#PWR0418" H 5950 7900 50  0001 C CNN
F 1 "GND" H 5955 7977 50  0000 C CNN
F 2 "" H 5950 8150 50  0001 C CNN
F 3 "" H 5950 8150 50  0001 C CNN
	1    5950 8150
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0419
U 1 1 5B10FF40
P 5350 7750
F 0 "#PWR0419" H 5350 7600 50  0001 C CNN
F 1 "VCC" V 5368 7877 50  0000 L CNN
F 2 "" H 5350 7750 50  0001 C CNN
F 3 "" H 5350 7750 50  0001 C CNN
	1    5350 7750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0420
U 1 1 5B10FF46
P 5350 7950
F 0 "#PWR0420" H 5350 7700 50  0001 C CNN
F 1 "GND" V 5355 7822 50  0000 R CNN
F 2 "" H 5350 7950 50  0001 C CNN
F 3 "" H 5350 7950 50  0001 C CNN
	1    5350 7950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0421
U 1 1 5B10FF4C
P 5350 8050
F 0 "#PWR0421" H 5350 7800 50  0001 C CNN
F 1 "GND" V 5355 7922 50  0000 R CNN
F 2 "" H 5350 8050 50  0001 C CNN
F 3 "" H 5350 8050 50  0001 C CNN
	1    5350 8050
	0    1    1    0   
$EndComp
Text Label 5350 5750 2    50   ~ 0
OP0
Text Label 5350 5850 2    50   ~ 0
OP1
Text Label 5350 5950 2    50   ~ 0
OP2
Text Label 5350 6050 2    50   ~ 0
OP3
Text Label 5350 6150 2    50   ~ 0
OP4
Text Label 5350 6250 2    50   ~ 0
OP5
Text Label 5350 6350 2    50   ~ 0
OP6
Text Label 5350 6450 2    50   ~ 0
OP7
Text Label 5350 6550 2    50   ~ 0
OP8
Text Label 5350 6650 2    50   ~ 0
OP9
Text Label 5350 6750 2    50   ~ 0
OP10
Text Label 5350 6850 2    50   ~ 0
OP11
Text Label 5350 6950 2    50   ~ 0
MICROOP0
Text Label 5350 7050 2    50   ~ 0
MICROOP1
Text Label 5350 7150 2    50   ~ 0
MICROOP2
Text Label 5350 7250 2    50   ~ 0
MICROOP3
Text Label 5350 7350 2    50   ~ 0
INT_FLAG
$Comp
L power:GND #PWR0422
U 1 1 5B10FF6B
P 5350 7550
F 0 "#PWR0422" H 5350 7300 50  0001 C CNN
F 1 "GND" V 5355 7422 50  0000 R CNN
F 2 "" H 5350 7550 50  0001 C CNN
F 3 "" H 5350 7550 50  0001 C CNN
	1    5350 7550
	0    1    1    0   
$EndComp
Text Label 5350 7450 2    50   ~ 0
MMU_FAULT_FLAG
Text Label 6550 5750 0    50   ~ 0
CTRL16
Text Label 6550 5850 0    50   ~ 0
CTRL17
Text Label 6550 5950 0    50   ~ 0
CTRL18
Text Label 6550 6050 0    50   ~ 0
CTRL19
Text Label 6550 6150 0    50   ~ 0
CTRL20
Text Label 6550 6250 0    50   ~ 0
CTRL21
Text Label 6550 6350 0    50   ~ 0
CTRL22
Text Label 6550 6450 0    50   ~ 0
CTRL23
$Comp
L 74xx:74LS574 U112
U 1 1 5B1107FE
P 5950 3900
F 0 "U112" H 5950 3700 50  0000 C CNN
F 1 "74LS574" H 6000 3600 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 5950 3900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS574" H 5950 3900 50  0001 C CNN
	1    5950 3900
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0423
U 1 1 5B110805
P 5950 3100
F 0 "#PWR0423" H 5950 2950 50  0001 C CNN
F 1 "VCC" H 5967 3273 50  0000 C CNN
F 2 "" H 5950 3100 50  0001 C CNN
F 3 "" H 5950 3100 50  0001 C CNN
	1    5950 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0424
U 1 1 5B11080B
P 5950 4700
F 0 "#PWR0424" H 5950 4450 50  0001 C CNN
F 1 "GND" H 5955 4527 50  0000 C CNN
F 2 "" H 5950 4700 50  0001 C CNN
F 3 "" H 5950 4700 50  0001 C CNN
	1    5950 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C123
U 1 1 5B110811
P 6200 3100
F 0 "C123" V 5971 3100 50  0000 C CNN
F 1 "0.1uF" V 6062 3100 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 6200 3100 50  0001 C CNN
F 3 "~" H 6200 3100 50  0001 C CNN
	1    6200 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	5950 3100 6100 3100
Connection ~ 5950 3100
$Comp
L power:GND #PWR0425
U 1 1 5B11081A
P 6300 3100
F 0 "#PWR0425" H 6300 2850 50  0001 C CNN
F 1 "GND" V 6305 2972 50  0000 R CNN
F 2 "" H 6300 3100 50  0001 C CNN
F 3 "" H 6300 3100 50  0001 C CNN
	1    6300 3100
	0    -1   -1   0   
$EndComp
Text Label 5450 3400 2    50   ~ 0
CTRL16
Text Label 5450 3500 2    50   ~ 0
CTRL17
Text Label 5450 3600 2    50   ~ 0
CTRL18
Text Label 5450 3700 2    50   ~ 0
CTRL19
Text Label 5450 3800 2    50   ~ 0
CTRL20
Text Label 5450 3900 2    50   ~ 0
CTRL21
Text Label 5450 4000 2    50   ~ 0
CTRL22
Text Label 5450 4100 2    50   ~ 0
CTRL23
Text Label 6450 3400 0    50   ~ 0
CTRL_BUS0
Text Label 6450 3500 0    50   ~ 0
CTRL_BUS1
Text Label 6450 3600 0    50   ~ 0
CTRL_BUS2
Text Label 6450 3700 0    50   ~ 0
CTRL_BUS3
Text Label 6450 3800 0    50   ~ 0
CTRL_BUS4
Text Label 6450 3900 0    50   ~ 0
CTRL_BUS5
Text Label 6450 4000 0    50   ~ 0
CTRL_BUS6
Text Label 6450 4100 0    50   ~ 0
CTRL_BUS7
Text Label 4400 3400 0    50   ~ 0
CTRL_OUT0
Text Label 4400 3500 0    50   ~ 0
CTRL_OUT1
Text Label 4400 3600 0    50   ~ 0
CTRL_OUT2
Text Label 4400 3700 0    50   ~ 0
CTRL_OUT3
Text Label 4400 3800 0    50   ~ 0
CTRL_OUT4
Text Label 8200 2900 2    50   ~ 0
CTRL_OUT0
Text Label 8200 3000 2    50   ~ 0
CTRL_OUT1
Text Label 8200 3100 2    50   ~ 0
CTRL_OUT2
Text Label 8200 3200 2    50   ~ 0
CTRL_OUT3
Text Label 8200 3300 2    50   ~ 0
CTRL_OUT4
Text Label 7400 3400 1    50   ~ 0
CTRL_OUT4
Text Label 2550 9200 2    50   ~ 0
CTRL_IN0
Text Label 2550 9300 2    50   ~ 0
CTRL_IN1
Text Label 2550 9400 2    50   ~ 0
CTRL_IN2
Text Label 2550 9500 2    50   ~ 0
CTRL_IN3
Text Label 2550 9600 2    50   ~ 0
CTRL_IN4
Text Label 1600 9700 1    50   ~ 0
CTRL_IN4
Text Label 2400 3400 0    50   ~ 0
CTRL_IN0
Text Label 2400 3500 0    50   ~ 0
CTRL_IN1
Text Label 2400 3600 0    50   ~ 0
CTRL_IN2
Text Label 2400 3700 0    50   ~ 0
CTRL_IN3
Text Label 2400 3800 0    50   ~ 0
CTRL_IN4
Text Label 2400 3900 0    50   ~ 0
CTRL_MULTI0
Text Label 2400 4000 0    50   ~ 0
CTRL_MULTI1
Text Label 2400 4100 0    50   ~ 0
CTRL_MULTI2
Text Label 4400 3900 0    50   ~ 0
CTRL_MULTI3
Text Label 7650 6150 2    50   ~ 0
CTRL_MULTI0
Text Label 7650 6250 2    50   ~ 0
CTRL_MULTI1
Text Label 7650 6350 2    50   ~ 0
CTRL_MULTI2
Text Label 7650 6450 2    50   ~ 0
CTRL_MULTI3
Text HLabel 5450 4300 0    50   Input ~ 0
~CLK
Text HLabel 3400 4300 0    50   Input ~ 0
~CLK
Text HLabel 1400 4300 0    50   Input ~ 0
~CLK
$Comp
L power:GND #PWR0426
U 1 1 5B11424D
P 5450 4400
F 0 "#PWR0426" H 5450 4150 50  0001 C CNN
F 1 "GND" H 5455 4227 50  0000 C CNN
F 2 "" H 5450 4400 50  0001 C CNN
F 3 "" H 5450 4400 50  0001 C CNN
	1    5450 4400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0427
U 1 1 5B114288
P 3400 4400
F 0 "#PWR0427" H 3400 4150 50  0001 C CNN
F 1 "GND" H 3405 4227 50  0000 C CNN
F 2 "" H 3400 4400 50  0001 C CNN
F 3 "" H 3400 4400 50  0001 C CNN
	1    3400 4400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0428
U 1 1 5B1142B3
P 1400 4400
F 0 "#PWR0428" H 1400 4150 50  0001 C CNN
F 1 "GND" H 1405 4227 50  0000 C CNN
F 2 "" H 1400 4400 50  0001 C CNN
F 3 "" H 1400 4400 50  0001 C CNN
	1    1400 4400
	0    1    1    0   
$EndComp
$Comp
L 74xx:74HC245 U118
U 1 1 5B1149B5
P 15750 3650
F 0 "U118" H 15750 3450 50  0000 C CNN
F 1 "74HC245" H 15750 3350 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 15750 3650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 15750 3650 50  0001 C CNN
	1    15750 3650
	1    0    0    -1  
$EndComp
Text Label 8750 4700 0    50   ~ 0
~CTRLLOGIC_OUT_NCLK
Text Label 15250 4150 2    50   ~ 0
~CTRLLOGIC_OUT_NCLK
$Comp
L power:VCC #PWR0429
U 1 1 5B1152F0
P 15750 2850
F 0 "#PWR0429" H 15750 2700 50  0001 C CNN
F 1 "VCC" H 15767 3023 50  0000 C CNN
F 2 "" H 15750 2850 50  0001 C CNN
F 3 "" H 15750 2850 50  0001 C CNN
	1    15750 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C129
U 1 1 5B1152F6
P 16100 2850
F 0 "C129" V 15871 2850 50  0000 C CNN
F 1 "0.1uF" V 15962 2850 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 16100 2850 50  0001 C CNN
F 3 "~" H 16100 2850 50  0001 C CNN
	1    16100 2850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0430
U 1 1 5B1152FD
P 16200 2850
F 0 "#PWR0430" H 16200 2600 50  0001 C CNN
F 1 "GND" V 16205 2722 50  0000 R CNN
F 2 "" H 16200 2850 50  0001 C CNN
F 3 "" H 16200 2850 50  0001 C CNN
	1    16200 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	15750 2850 16000 2850
Connection ~ 15750 2850
Text Label 15250 3150 2    50   ~ 0
CTRL_BUS0
Text Label 15250 3250 2    50   ~ 0
CTRL_BUS1
Text Label 15250 3350 2    50   ~ 0
CTRL_BUS2
Text Label 15250 3450 2    50   ~ 0
CTRL_BUS3
Text Label 15250 3550 2    50   ~ 0
CTRL_BUS4
Text Label 15250 3650 2    50   ~ 0
CTRL_BUS5
Text Label 15250 3750 2    50   ~ 0
CTRL_BUS6
Text Label 15250 3850 2    50   ~ 0
CTRL_BUS7
$Comp
L power:VCC #PWR0431
U 1 1 5B11601B
P 15250 4050
F 0 "#PWR0431" H 15250 3900 50  0001 C CNN
F 1 "VCC" H 15267 4223 50  0000 C CNN
F 2 "" H 15250 4050 50  0001 C CNN
F 3 "" H 15250 4050 50  0001 C CNN
	1    15250 4050
	0    -1   -1   0   
$EndComp
Text HLabel 16250 3150 2    50   Input ~ 0
BUS0
Text HLabel 16250 3250 2    50   Input ~ 0
BUS1
Text HLabel 16250 3350 2    50   Input ~ 0
BUS2
Text HLabel 16250 3450 2    50   Input ~ 0
BUS3
Text HLabel 16250 3550 2    50   Input ~ 0
BUS4
Text HLabel 16250 3650 2    50   Input ~ 0
BUS5
Text HLabel 16250 3750 2    50   Input ~ 0
BUS6
Text HLabel 16250 3850 2    50   Input ~ 0
BUS7
$Comp
L power:GND #PWR0432
U 1 1 5B116610
P 15750 4450
F 0 "#PWR0432" H 15750 4200 50  0001 C CNN
F 1 "GND" V 15755 4322 50  0000 R CNN
F 2 "" H 15750 4450 50  0001 C CNN
F 3 "" H 15750 4450 50  0001 C CNN
	1    15750 4450
	1    0    0    -1  
$EndComp
Text Notes 16000 4400 0    50   ~ 0
Control Logic Bus Output
Wire Notes Line
	800  5100 800  8550
Wire Notes Line
	800  8550 7100 8550
Wire Notes Line
	850  2750 850  5000
Wire Notes Line
	850  2750 6900 2750
Wire Notes Line
	850  5000 6900 5000
$Comp
L 74xx:74HC04 U114
U 3 1 5B131C79
P 20250 3450
F 0 "U114" H 20250 3450 50  0000 C CNN
F 1 "74HC04" H 20400 3350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 20250 3450 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 20250 3450 50  0001 C CNN
	3    20250 3450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U114
U 4 1 5B131C80
P 7700 3400
F 0 "U114" H 7700 3400 50  0000 C CNN
F 1 "74HC04" H 7850 3300 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7700 3400 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 7700 3400 50  0001 C CNN
	4    7700 3400
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U114
U 7 1 5B1323FA
P 4650 1450
F 0 "U114" H 4880 1496 50  0000 L CNN
F 1 "74HC04" H 4880 1405 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 4650 1450 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 4650 1450 50  0001 C CNN
	7    4650 1450
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0445
U 1 1 5B132401
P 4650 950
F 0 "#PWR0445" H 4650 800 50  0001 C CNN
F 1 "VCC" H 4667 1123 50  0000 C CNN
F 2 "" H 4650 950 50  0001 C CNN
F 3 "" H 4650 950 50  0001 C CNN
	1    4650 950 
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C125
U 1 1 5B132407
P 5000 950
F 0 "C125" V 4771 950 50  0000 C CNN
F 1 "0.1uF" V 4862 950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 5000 950 50  0001 C CNN
F 3 "~" H 5000 950 50  0001 C CNN
	1    5000 950 
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0446
U 1 1 5B13240E
P 5100 950
F 0 "#PWR0446" H 5100 700 50  0001 C CNN
F 1 "GND" V 5105 822 50  0000 R CNN
F 2 "" H 5100 950 50  0001 C CNN
F 3 "" H 5100 950 50  0001 C CNN
	1    5100 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4650 950  4900 950 
Connection ~ 4650 950 
$Comp
L power:GND #PWR0447
U 1 1 5B132416
P 4650 1950
F 0 "#PWR0447" H 4650 1700 50  0001 C CNN
F 1 "GND" V 4655 1822 50  0000 R CNN
F 2 "" H 4650 1950 50  0001 C CNN
F 3 "" H 4650 1950 50  0001 C CNN
	1    4650 1950
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U114
U 1 1 5B141E1A
P 4900 9300
F 0 "U114" H 4900 9300 50  0000 C CNN
F 1 "74HC04" H 5050 9200 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 4900 9300 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 4900 9300 50  0001 C CNN
	1    4900 9300
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U114
U 2 1 5B141E21
P 4900 9600
F 0 "U114" H 4900 9600 50  0000 C CNN
F 1 "74HC04" H 5050 9500 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 4900 9600 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 4900 9600 50  0001 C CNN
	2    4900 9600
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U114
U 5 1 5B141E36
P 1900 9700
F 0 "U114" H 1900 9700 50  0000 C CNN
F 1 "74HC04" H 2050 9600 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1900 9700 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 1900 9700 50  0001 C CNN
	5    1900 9700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U114
U 6 1 5B141E3D
P 19750 2900
F 0 "U114" H 19750 2900 50  0000 C CNN
F 1 "74HC04" H 19900 2800 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 19750 2900 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 19750 2900 50  0001 C CNN
	6    19750 2900
	1    0    0    -1  
$EndComp
Text Label 10600 3750 2    50   ~ 0
~OPCODE0_IN_NCLK
Text Label 10600 3850 2    50   ~ 0
~OPCODE1_IN_NCLK
Connection ~ 8150 5850
Text HLabel 3100 9300 2    50   Input ~ 0
A_IN_CLK
Text HLabel 3100 9400 2    50   Input ~ 0
B_IN_CLK
Text HLabel 3100 9500 2    50   Input ~ 0
M0_IN_CLK
Text HLabel 3100 9600 2    50   Input ~ 0
M1_IN_CLK
Text HLabel 3100 9700 2    50   Input ~ 0
M2_IN_CLK
Text HLabel 3100 10400 2    50   Input ~ 0
MMU0_IN_CLK
Text HLabel 3100 10500 2    50   Input ~ 0
MMU1_IN_CLK
Text HLabel 3100 10900 2    50   Input ~ 0
DISP_IN_CLK
Text HLabel 3100 11000 2    50   Input ~ 0
TASK_IN_CLK
Text HLabel 2550 10700 0    50   Input ~ 0
INT0_IN_CLK
Text HLabel 2550 10600 0    50   Input ~ 0
INT1_IN_CLK
Text HLabel 2550 10500 0    50   Input ~ 0
INT2_IN_CLK
Text HLabel 2550 10400 0    50   Input ~ 0
INT3_IN_CLK
Text HLabel 2550 10300 0    50   Input ~ 0
INT4_IN_CLK
Text HLabel 2550 10200 0    50   Input ~ 0
INT5_IN_CLK
Text HLabel 2550 10100 0    50   Input ~ 0
INT6_IN_CLK
Text HLabel 2550 10000 0    50   Input ~ 0
INT7_IN_CLK
Text HLabel 12650 3650 0    50   Input ~ 0
INT0_LATCH
Text HLabel 12650 3750 0    50   Input ~ 0
INT1_LATCH
Text HLabel 12650 3850 0    50   Input ~ 0
INT2_LATCH
Text HLabel 12650 3950 0    50   Input ~ 0
INT3_LATCH
Text HLabel 12650 4050 0    50   Input ~ 0
INT4_LATCH
Text HLabel 12650 4150 0    50   Input ~ 0
INT5_LATCH
Text HLabel 12650 4250 0    50   Input ~ 0
INT6_LATCH
Text HLabel 12650 4350 0    50   Input ~ 0
INT7_LATCH
Wire Notes Line
	18300 1300 21000 1300
Wire Notes Line
	21000 1300 21000 4050
Wire Notes Line
	21000 4050 18300 4050
Wire Notes Line
	18300 4050 18300 1300
$Comp
L 74xx:74LS08 U117
U 1 1 5B1CD68C
P 14200 4750
F 0 "U117" H 14200 5075 50  0000 C CNN
F 1 "74LS08" H 14200 4984 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 14200 4750 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 14200 4750 50  0001 C CNN
	1    14200 4750
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS08 U117
U 2 1 5B1CD7DD
P 20400 2500
F 0 "U117" H 20400 2825 50  0000 C CNN
F 1 "74LS08" H 20400 2734 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 20400 2500 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 20400 2500 50  0001 C CNN
	2    20400 2500
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS08 U117
U 3 1 5B1CD8EF
P 19400 2100
F 0 "U117" H 19400 2425 50  0000 C CNN
F 1 "74LS08" H 19400 2334 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 19400 2100 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 19400 2100 50  0001 C CNN
	3    19400 2100
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS08 U117
U 5 1 5B1CDB22
P 7800 1450
F 0 "U117" H 8030 1496 50  0000 L CNN
F 1 "74LS08" H 8030 1405 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7800 1450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 7800 1450 50  0001 C CNN
	5    7800 1450
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0455
U 1 1 5B1CED2B
P 7800 950
F 0 "#PWR0455" H 7800 800 50  0001 C CNN
F 1 "VCC" H 7817 1123 50  0000 C CNN
F 2 "" H 7800 950 50  0001 C CNN
F 3 "" H 7800 950 50  0001 C CNN
	1    7800 950 
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C128
U 1 1 5B1CED31
P 8150 950
F 0 "C128" V 7921 950 50  0000 C CNN
F 1 "0.1uF" V 8012 950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 8150 950 50  0001 C CNN
F 3 "~" H 8150 950 50  0001 C CNN
	1    8150 950 
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0456
U 1 1 5B1CED38
P 8250 950
F 0 "#PWR0456" H 8250 700 50  0001 C CNN
F 1 "GND" V 8255 822 50  0000 R CNN
F 2 "" H 8250 950 50  0001 C CNN
F 3 "" H 8250 950 50  0001 C CNN
	1    8250 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7800 950  8050 950 
Connection ~ 7800 950 
Text HLabel 13900 4850 0    50   Input ~ 0
INTERRUPT_ENABLE_FLAG
Wire Wire Line
	13700 4150 13900 4150
Wire Wire Line
	13900 4150 13900 4650
Text Notes 13600 5200 0    50   ~ 0
This and isn't done inside the\nflag logic sheet since spare\nand gates get confusing.
Text Notes 19050 1600 0    50   ~ 0
SPARE AVAILABLE
Text HLabel 4400 4000 2    50   Input ~ 0
MLU_SEL0
Text HLabel 4400 4100 2    50   Input ~ 0
MLU_SEL1
Wire Wire Line
	6450 3400 6950 3400
Text HLabel 6950 3400 1    50   Input ~ 0
MLU_SEL2
$Sheet
S 8200 2800 550  2300
U 5B0CC7A2
F0 "OUT plane decoder" 50
F1 "5_32_decoder.sch" 50
F2 "S0" I L 8200 2900 50 
F3 "S1" I L 8200 3000 50 
F4 "S2" I L 8200 3100 50 
F5 "S3" I L 8200 3200 50 
F6 "O0" I R 8750 2900 50 
F7 "O1" I R 8750 3000 50 
F8 "O2" I R 8750 3100 50 
F9 "O3" I R 8750 3200 50 
F10 "O4" I R 8750 3300 50 
F11 "O5" I R 8750 3400 50 
F12 "O6" I R 8750 3500 50 
F13 "O7" I R 8750 3600 50 
F14 "O8" I R 8750 3700 50 
F15 "O9" I R 8750 3800 50 
F16 "O10" I R 8750 3900 50 
F17 "O11" I R 8750 4000 50 
F18 "O12" I R 8750 4100 50 
F19 "O13" I R 8750 4200 50 
F20 "O14" I R 8750 4300 50 
F21 "O15" I R 8750 4400 50 
F22 "O16" I R 8750 4500 50 
F23 "O17" I R 8750 4600 50 
F24 "O18" I R 8750 4700 50 
F25 "O19" I R 8750 4800 50 
F26 "O20" I R 8750 4900 50 
F27 "O21" I R 8750 5000 50 
F28 "O22" I L 8200 4100 50 
F29 "O23" I L 8200 4200 50 
F30 "O24" I L 8200 4300 50 
F31 "O25" I L 8200 4400 50 
F32 "O26" I L 8200 4500 50 
F33 "O27" I L 8200 4600 50 
F34 "O28" I L 8200 4700 50 
F35 "O29" I L 8200 4800 50 
F36 "O30" I L 8200 4900 50 
F37 "O31" I L 8200 5000 50 
F38 "S4" I L 8200 3300 50 
F39 "~S4" I L 8200 3400 50 
$EndSheet
Text HLabel 8750 3800 2    50   Input ~ 0
~PC0_OUT_NCLK
Text HLabel 8750 3900 2    50   Input ~ 0
~PC1_OUT_NCLK
Text HLabel 8750 4000 2    50   Input ~ 0
~PC2_OUT_NCLK
$Comp
L power:GND #PWR061
U 1 1 5B243822
P 7800 1950
F 0 "#PWR061" H 7800 1700 50  0001 C CNN
F 1 "GND" V 7805 1822 50  0000 R CNN
F 2 "" H 7800 1950 50  0001 C CNN
F 3 "" H 7800 1950 50  0001 C CNN
	1    7800 1950
	1    0    0    -1  
$EndComp
Text HLabel 3100 10600 2    50   Input ~ 0
MMU2_IN_CLK
Text HLabel 5200 9300 2    50   Input ~ 0
~MMU_IN_CLK
Text HLabel 5200 9600 2    50   Input ~ 0
~MMU_CONTROL_IN_CLK
Text HLabel 10600 4050 0    50   Input ~ 0
~RESET
Text HLabel 10600 3950 0    50   Input ~ 0
CLK
Text Label 8650 6350 0    50   ~ 0
~RESET_UOP_COUNT_NCLK
Text Label 12700 2950 2    50   ~ 0
~RESET_UOP_COUNT_NCLK
Text Notes 12150 2700 0    50   ~ 0
Update the micro-op counter on the rising edge so\nwe have enough time to latch the control word on\nthe falling edge (not trying to simultaneously \nupdate the micro op counter).
Text Label 12700 3050 2    50   ~ 0
CLK
Text HLabel 8200 4300 0    50   Input ~ 0
~INT0_OUT_NCLK
Text HLabel 8200 4400 0    50   Input ~ 0
~INT1_OUT_NCLK
Text HLabel 8200 4500 0    50   Input ~ 0
~INT2_OUT_NCLK
Text HLabel 8200 4600 0    50   Input ~ 0
~INT3_OUT_NCLK
Text HLabel 8200 4700 0    50   Input ~ 0
~INT4_OUT_NCLK
Text HLabel 8200 4800 0    50   Input ~ 0
~INT5_OUT_NCLK
Text HLabel 8200 4900 0    50   Input ~ 0
~INT6_OUT_NCLK
Text HLabel 8200 5000 0    50   Input ~ 0
~INT7_OUT_NCLK
$Comp
L Memory_Flash:SST39SF040 U113
U 1 1 5B5502C3
P 5950 6950
F 0 "U113" H 5950 7050 50  0000 C CNN
F 1 "SST39SF040" H 6000 6900 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 5950 7250 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 5950 7250 50  0001 C CNN
	1    5950 6950
	1    0    0    -1  
$EndComp
$Comp
L Memory_Flash:SST39SF040 U90
U 1 1 5B5526B8
P 4000 7000
F 0 "U90" H 4000 7100 50  0000 C CNN
F 1 "SST39SF040" H 4050 6950 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 4000 7300 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 4000 7300 50  0001 C CNN
	1    4000 7000
	1    0    0    -1  
$EndComp
Connection ~ 4000 5700
$Comp
L Memory_Flash:SST39SF040 U88
U 1 1 5B552AB5
P 2200 7000
F 0 "U88" H 2200 7100 50  0000 C CNN
F 1 "SST39SF040" H 2250 6950 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 2200 7300 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 2200 7300 50  0001 C CNN
	1    2200 7000
	1    0    0    -1  
$EndComp
Connection ~ 2200 5700
NoConn ~ 8750 4900
NoConn ~ 8750 5000
NoConn ~ 8200 4100
NoConn ~ 8650 7450
NoConn ~ 8650 7350
$Comp
L power:GND #PWR0217
U 1 1 5B5AB50A
P 19100 2000
F 0 "#PWR0217" H 19100 1750 50  0001 C CNN
F 1 "GND" V 19105 1872 50  0000 R CNN
F 2 "" H 19100 2000 50  0001 C CNN
F 3 "" H 19100 2000 50  0001 C CNN
	1    19100 2000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0218
U 1 1 5B5AB5AF
P 19100 2200
F 0 "#PWR0218" H 19100 1950 50  0001 C CNN
F 1 "GND" V 19105 2072 50  0000 R CNN
F 2 "" H 19100 2200 50  0001 C CNN
F 3 "" H 19100 2200 50  0001 C CNN
	1    19100 2200
	0    1    1    0   
$EndComp
NoConn ~ 19700 2100
NoConn ~ 8650 7150
NoConn ~ 8650 7250
$Comp
L power:GND #PWR0141
U 1 1 5B7989AB
P 20100 2400
F 0 "#PWR0141" H 20100 2150 50  0001 C CNN
F 1 "GND" V 20105 2272 50  0000 R CNN
F 2 "" H 20100 2400 50  0001 C CNN
F 3 "" H 20100 2400 50  0001 C CNN
	1    20100 2400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0144
U 1 1 5B7989B1
P 20100 2600
F 0 "#PWR0144" H 20100 2350 50  0001 C CNN
F 1 "GND" V 20105 2472 50  0000 R CNN
F 2 "" H 20100 2600 50  0001 C CNN
F 3 "" H 20100 2600 50  0001 C CNN
	1    20100 2600
	0    1    1    0   
$EndComp
NoConn ~ 20700 2500
NoConn ~ 8650 7050
NoConn ~ 8650 6950
NoConn ~ 8650 6850
Text HLabel 3100 9800 2    50   Input ~ 0
S0_IN_CLK
Text HLabel 3100 9900 2    50   Input ~ 0
S1_IN_CLK
Text HLabel 3100 10000 2    50   Input ~ 0
S2_IN_CLK
Text HLabel 3100 10100 2    50   Input ~ 0
PC0_IN_CLK
Text HLabel 3100 10200 2    50   Input ~ 0
PC1_IN_CLK
Text HLabel 3100 10300 2    50   Input ~ 0
PC2_IN_CLK
$Comp
L power:GND #PWR0187
U 1 1 5B6F885A
P 19450 2900
F 0 "#PWR0187" H 19450 2650 50  0001 C CNN
F 1 "GND" V 19455 2772 50  0000 R CNN
F 2 "" H 19450 2900 50  0001 C CNN
F 3 "" H 19450 2900 50  0001 C CNN
	1    19450 2900
	0    1    1    0   
$EndComp
NoConn ~ 20050 2900
$Comp
L 74xx:74LS08 U117
U 4 1 5B715A18
P 20400 1750
AR Path="/5B0C6DCD/5B715A18" Ref="U117"  Part="4" 
AR Path="/5ADF0E03/5B715A18" Ref="U?"  Part="4" 
F 0 "U117" H 20400 2075 50  0000 C CNN
F 1 "74LS08" H 20400 1984 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 20400 1750 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 20400 1750 50  0001 C CNN
	4    20400 1750
	1    0    0    -1  
$EndComp
NoConn ~ 8650 6750
NoConn ~ 8650 6650
Text Notes 8850 6800 0    50   ~ 0
TODO: Multi plane can be reduced in size?
$Comp
L power:GND #PWR056
U 1 1 5B723C76
P 19950 3450
F 0 "#PWR056" H 19950 3200 50  0001 C CNN
F 1 "GND" V 19955 3322 50  0000 R CNN
F 2 "" H 19950 3450 50  0001 C CNN
F 3 "" H 19950 3450 50  0001 C CNN
	1    19950 3450
	0    1    1    0   
$EndComp
NoConn ~ 20550 3450
$Comp
L power:GND #PWR057
U 1 1 5B7263CA
P 20100 1650
F 0 "#PWR057" H 20100 1400 50  0001 C CNN
F 1 "GND" V 20105 1522 50  0000 R CNN
F 2 "" H 20100 1650 50  0001 C CNN
F 3 "" H 20100 1650 50  0001 C CNN
	1    20100 1650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR058
U 1 1 5B726451
P 20100 1850
F 0 "#PWR058" H 20100 1600 50  0001 C CNN
F 1 "GND" V 20105 1722 50  0000 R CNN
F 2 "" H 20100 1850 50  0001 C CNN
F 3 "" H 20100 1850 50  0001 C CNN
	1    20100 1850
	0    1    1    0   
$EndComp
NoConn ~ 20700 1750
NoConn ~ 8750 4800
Text Notes 15200 2500 0    50   ~ 0
TODO: Use output enable on 574 instead of having a buffer here.
$Comp
L 74xx:74LS273 U13
U 1 1 5B74EE1E
P 11800 6850
F 0 "U13" H 11800 7828 50  0000 C CNN
F 1 "74LS273" H 11800 7737 50  0000 C CNN
F 2 "" H 11800 6850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS273" H 11800 6850 50  0001 C CNN
	1    11800 6850
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS273 U15
U 1 1 5B74F277
P 13500 6850
F 0 "U15" H 13500 7828 50  0000 C CNN
F 1 "74LS273" H 13500 7737 50  0000 C CNN
F 2 "" H 13500 6850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS273" H 13500 6850 50  0001 C CNN
	1    13500 6850
	1    0    0    -1  
$EndComp
Text HLabel 11300 7350 0    50   Input ~ 0
~RESET
Text HLabel 13000 7350 0    50   Input ~ 0
~RESET
Text Label 11300 7250 2    50   ~ 0
OPCODE0_IN_CLK
Text Label 13000 7250 2    50   ~ 0
OPCODE1_IN_CLK
Text Notes 11800 5750 0    50   ~ 0
TODO: Should switch opcode regs to these?
Wire Notes Line
	10450 5400 10450 7800
Wire Notes Line
	10450 7800 14250 7800
Wire Notes Line
	14250 7800 14250 5450
Wire Notes Line
	14250 5450 10450 5450
$Sheet
S 2550 9100 550  2100
U 5B6E8695
F0 "IN decoder" 50
F1 "in_plane_decoder.sch" 50
F2 "S0" I L 2550 9200 50 
F3 "S1" I L 2550 9300 50 
F4 "S2" I L 2550 9400 50 
F5 "O0" I R 3100 9200 50 
F6 "O1" I R 3100 9300 50 
F7 "O2" I R 3100 9400 50 
F8 "O3" I R 3100 9500 50 
F9 "O4" I R 3100 9600 50 
F10 "O5" I R 3100 9700 50 
F11 "O6" I R 3100 9800 50 
F12 "O7" I R 3100 9900 50 
F13 "O8" I R 3100 10000 50 
F14 "O9" I R 3100 10100 50 
F15 "O10" I R 3100 10200 50 
F16 "O11" I R 3100 10300 50 
F17 "O12" I R 3100 10400 50 
F18 "O13" I R 3100 10500 50 
F19 "O14" I R 3100 10600 50 
F20 "O15" I R 3100 10700 50 
F21 "O16" I R 3100 10800 50 
F22 "O17" I R 3100 10900 50 
F23 "O18" I R 3100 11000 50 
F24 "O19" I R 3100 11100 50 
F25 "O20" I L 2550 11100 50 
F26 "O21" I L 2550 11000 50 
F27 "O22" I L 2550 10900 50 
F28 "O23" I L 2550 10800 50 
F29 "O24" I L 2550 10700 50 
F30 "O25" I L 2550 10600 50 
F31 "O26" I L 2550 10500 50 
F32 "O27" I L 2550 10400 50 
F33 "O28" I L 2550 10300 50 
F34 "O29" I L 2550 10200 50 
F35 "O30" I L 2550 10100 50 
F36 "O31" I L 2550 10000 50 
F37 "S3" I L 2550 9500 50 
F38 "S4" I L 2550 9600 50 
F39 "~S4" I L 2550 9700 50 
F40 "CLK" I L 2550 9800 50 
F41 "~CLK" I L 2550 9900 50 
$EndSheet
Text HLabel 2550 9800 0    50   Input ~ 0
CLK
Text HLabel 2550 9900 0    50   Input ~ 0
~CLK
NoConn ~ 3100 9200
Text Notes 3200 9200 0    50   ~ 0
(none)
Text Label 3100 10700 0    50   ~ 0
MMU_IN_CLK
Text Label 3100 10800 0    50   ~ 0
MMU_CONTROL_IN_CLK
NoConn ~ 2550 10800
NoConn ~ 2550 10900
NoConn ~ 2550 11000
Text Label 3100 11100 0    50   ~ 0
OPCODE0_IN_CLK
Text Label 2550 11100 2    50   ~ 0
OPCODE1_IN_CLK
Text Label 4600 9300 2    50   ~ 0
MMU_IN_CLK
Text Label 4600 9600 2    50   ~ 0
MMU_CONTROL_IN_CLK
$EndSCHEMATC
