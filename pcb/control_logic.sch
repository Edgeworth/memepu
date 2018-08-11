EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A2 23386 16535
encoding utf-8
Sheet 26 30
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
P 1900 2200
F 0 "U87" H 1900 2000 50  0000 C CNN
F 1 "74LS574" H 1950 1900 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 1900 2200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS574" H 1900 2200 50  0001 C CNN
	1    1900 2200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0351
U 1 1 5B0C6FCF
P 1900 1400
F 0 "#PWR0351" H 1900 1250 50  0001 C CNN
F 1 "VCC" H 1917 1573 50  0000 C CNN
F 2 "" H 1900 1400 50  0001 C CNN
F 3 "" H 1900 1400 50  0001 C CNN
	1    1900 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0352
U 1 1 5B0C7016
P 1900 3000
F 0 "#PWR0352" H 1900 2750 50  0001 C CNN
F 1 "GND" H 1905 2827 50  0000 C CNN
F 2 "" H 1900 3000 50  0001 C CNN
F 3 "" H 1900 3000 50  0001 C CNN
	1    1900 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C98
U 1 1 5B0C7064
P 2150 1400
F 0 "C98" V 1921 1400 50  0000 C CNN
F 1 "0.1uF" V 2012 1400 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2150 1400 50  0001 C CNN
F 3 "~" H 2150 1400 50  0001 C CNN
	1    2150 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 1400 2050 1400
Connection ~ 1900 1400
$Comp
L power:GND #PWR0353
U 1 1 5B0C70CB
P 2250 1400
F 0 "#PWR0353" H 2250 1150 50  0001 C CNN
F 1 "GND" V 2255 1272 50  0000 R CNN
F 2 "" H 2250 1400 50  0001 C CNN
F 3 "" H 2250 1400 50  0001 C CNN
	1    2250 1400
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74LS574 U89
U 1 1 5B0C714D
P 3900 2200
F 0 "U89" H 3900 2000 50  0000 C CNN
F 1 "74LS574" H 3950 1900 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 3900 2200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS574" H 3900 2200 50  0001 C CNN
	1    3900 2200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0354
U 1 1 5B0C7154
P 3900 1400
F 0 "#PWR0354" H 3900 1250 50  0001 C CNN
F 1 "VCC" H 3917 1573 50  0000 C CNN
F 2 "" H 3900 1400 50  0001 C CNN
F 3 "" H 3900 1400 50  0001 C CNN
	1    3900 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0355
U 1 1 5B0C715A
P 3900 3000
F 0 "#PWR0355" H 3900 2750 50  0001 C CNN
F 1 "GND" H 3905 2827 50  0000 C CNN
F 2 "" H 3900 3000 50  0001 C CNN
F 3 "" H 3900 3000 50  0001 C CNN
	1    3900 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C100
U 1 1 5B0C7160
P 4150 1400
F 0 "C100" V 3921 1400 50  0000 C CNN
F 1 "0.1uF" V 4012 1400 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4150 1400 50  0001 C CNN
F 3 "~" H 4150 1400 50  0001 C CNN
	1    4150 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	3900 1400 4050 1400
Connection ~ 3900 1400
$Comp
L power:GND #PWR0356
U 1 1 5B0C7169
P 4250 1400
F 0 "#PWR0356" H 4250 1150 50  0001 C CNN
F 1 "GND" V 4255 1272 50  0000 R CNN
F 2 "" H 4250 1400 50  0001 C CNN
F 3 "" H 4250 1400 50  0001 C CNN
	1    4250 1400
	0    -1   -1   0   
$EndComp
Wire Notes Line
	6900 3300 6900 1050
Text Notes 2650 1250 0    50   ~ 0
Control word latch
$Comp
L power:VCC #PWR0357
U 1 1 5B0C730F
P 2200 4000
F 0 "#PWR0357" H 2200 3850 50  0001 C CNN
F 1 "VCC" H 2217 4173 50  0000 C CNN
F 2 "" H 2200 4000 50  0001 C CNN
F 3 "" H 2200 4000 50  0001 C CNN
	1    2200 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C99
U 1 1 5B0C7315
P 2500 3800
F 0 "C99" V 2271 3800 50  0000 C CNN
F 1 "0.1uF" V 2362 3800 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2500 3800 50  0001 C CNN
F 3 "~" H 2500 3800 50  0001 C CNN
	1    2500 3800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0358
U 1 1 5B0C731C
P 2600 3800
F 0 "#PWR0358" H 2600 3550 50  0001 C CNN
F 1 "GND" V 2605 3672 50  0000 R CNN
F 2 "" H 2600 3800 50  0001 C CNN
F 3 "" H 2600 3800 50  0001 C CNN
	1    2600 3800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2200 4000 2400 4000
Wire Wire Line
	2400 4000 2400 3800
$Comp
L power:GND #PWR0359
U 1 1 5B0C740B
P 2200 6500
F 0 "#PWR0359" H 2200 6250 50  0001 C CNN
F 1 "GND" H 2205 6327 50  0000 C CNN
F 2 "" H 2200 6500 50  0001 C CNN
F 3 "" H 2200 6500 50  0001 C CNN
	1    2200 6500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0360
U 1 1 5B0C7919
P 1600 6100
F 0 "#PWR0360" H 1600 5950 50  0001 C CNN
F 1 "VCC" V 1618 6227 50  0000 L CNN
F 2 "" H 1600 6100 50  0001 C CNN
F 3 "" H 1600 6100 50  0001 C CNN
	1    1600 6100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0361
U 1 1 5B0C7972
P 1600 6300
F 0 "#PWR0361" H 1600 6050 50  0001 C CNN
F 1 "GND" V 1605 6172 50  0000 R CNN
F 2 "" H 1600 6300 50  0001 C CNN
F 3 "" H 1600 6300 50  0001 C CNN
	1    1600 6300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0362
U 1 1 5B0C798F
P 1600 6400
F 0 "#PWR0362" H 1600 6150 50  0001 C CNN
F 1 "GND" V 1605 6272 50  0000 R CNN
F 2 "" H 1600 6400 50  0001 C CNN
F 3 "" H 1600 6400 50  0001 C CNN
	1    1600 6400
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0363
U 1 1 5B0C7CC9
P 4000 4000
F 0 "#PWR0363" H 4000 3850 50  0001 C CNN
F 1 "VCC" H 4017 4173 50  0000 C CNN
F 2 "" H 4000 4000 50  0001 C CNN
F 3 "" H 4000 4000 50  0001 C CNN
	1    4000 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C101
U 1 1 5B0C7CCF
P 4300 3800
F 0 "C101" V 4071 3800 50  0000 C CNN
F 1 "0.1uF" V 4162 3800 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4300 3800 50  0001 C CNN
F 3 "~" H 4300 3800 50  0001 C CNN
	1    4300 3800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0364
U 1 1 5B0C7CD6
P 4400 3800
F 0 "#PWR0364" H 4400 3550 50  0001 C CNN
F 1 "GND" V 4405 3672 50  0000 R CNN
F 2 "" H 4400 3800 50  0001 C CNN
F 3 "" H 4400 3800 50  0001 C CNN
	1    4400 3800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4000 4000 4200 4000
Wire Wire Line
	4200 4000 4200 3800
$Comp
L power:GND #PWR0365
U 1 1 5B0C7CDF
P 4000 6500
F 0 "#PWR0365" H 4000 6250 50  0001 C CNN
F 1 "GND" H 4005 6327 50  0000 C CNN
F 2 "" H 4000 6500 50  0001 C CNN
F 3 "" H 4000 6500 50  0001 C CNN
	1    4000 6500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0366
U 1 1 5B0C7CE5
P 3400 6100
F 0 "#PWR0366" H 3400 5950 50  0001 C CNN
F 1 "VCC" V 3418 6227 50  0000 L CNN
F 2 "" H 3400 6100 50  0001 C CNN
F 3 "" H 3400 6100 50  0001 C CNN
	1    3400 6100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0367
U 1 1 5B0C7CEB
P 3400 6300
F 0 "#PWR0367" H 3400 6050 50  0001 C CNN
F 1 "GND" V 3405 6172 50  0000 R CNN
F 2 "" H 3400 6300 50  0001 C CNN
F 3 "" H 3400 6300 50  0001 C CNN
	1    3400 6300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0368
U 1 1 5B0C7CF1
P 3400 6400
F 0 "#PWR0368" H 3400 6150 50  0001 C CNN
F 1 "GND" V 3405 6272 50  0000 R CNN
F 2 "" H 3400 6400 50  0001 C CNN
F 3 "" H 3400 6400 50  0001 C CNN
	1    3400 6400
	0    1    1    0   
$EndComp
Text Notes 1350 3650 0    50   ~ 0
Control EEPROMs
Wire Wire Line
	8150 6550 8500 6550
Text Label 2800 4100 0    50   ~ 0
CTRL0
Text Label 2800 4200 0    50   ~ 0
CTRL1
Text Label 2800 4300 0    50   ~ 0
CTRL2
Text Label 2800 4400 0    50   ~ 0
CTRL3
Text Label 2800 4500 0    50   ~ 0
CTRL4
Text Label 2800 4600 0    50   ~ 0
CTRL5
Text Label 2800 4700 0    50   ~ 0
CTRL6
Text Label 2800 4800 0    50   ~ 0
CTRL7
Text Label 4600 4100 0    50   ~ 0
CTRL8
Text Label 4600 4200 0    50   ~ 0
CTRL9
Text Label 4600 4300 0    50   ~ 0
CTRL10
Text Label 4600 4400 0    50   ~ 0
CTRL11
Text Label 4600 4500 0    50   ~ 0
CTRL12
Text Label 4600 4600 0    50   ~ 0
CTRL13
Text Label 4600 4700 0    50   ~ 0
CTRL14
Text Label 4600 4800 0    50   ~ 0
CTRL15
Text Label 1400 1700 2    50   ~ 0
CTRL0
Text Label 1400 1800 2    50   ~ 0
CTRL1
Text Label 1400 1900 2    50   ~ 0
CTRL2
Text Label 1400 2000 2    50   ~ 0
CTRL3
Text Label 1400 2100 2    50   ~ 0
CTRL4
Text Label 1400 2200 2    50   ~ 0
CTRL5
Text Label 1400 2300 2    50   ~ 0
CTRL6
Text Label 1400 2400 2    50   ~ 0
CTRL7
Text Label 3400 1700 2    50   ~ 0
CTRL8
Text Label 3400 1800 2    50   ~ 0
CTRL9
Text Label 3400 1900 2    50   ~ 0
CTRL10
Text Label 3400 2000 2    50   ~ 0
CTRL11
Text Label 3400 2100 2    50   ~ 0
CTRL12
Text Label 3400 2200 2    50   ~ 0
CTRL13
Text Label 3400 2300 2    50   ~ 0
CTRL14
Text Label 3400 2400 2    50   ~ 0
CTRL15
Wire Wire Line
	8000 1700 8200 1700
NoConn ~ 8750 1200
Text Notes 8850 1200 0    50   ~ 0
(none)
$Comp
L power:GND #PWR0372
U 1 1 5B0D4910
P 8550 5400
F 0 "#PWR0372" H 8550 5150 50  0001 C CNN
F 1 "GND" H 8555 5227 50  0000 C CNN
F 2 "" H 8550 5400 50  0001 C CNN
F 3 "" H 8550 5400 50  0001 C CNN
	1    8550 5400
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0373
U 1 1 5B0D4916
P 8550 4100
F 0 "#PWR0373" H 8550 3950 50  0001 C CNN
F 1 "VCC" H 8567 4273 50  0000 C CNN
F 2 "" H 8550 4100 50  0001 C CNN
F 3 "" H 8550 4100 50  0001 C CNN
	1    8550 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C102
U 1 1 5B0D491C
P 8900 4100
F 0 "C102" V 8671 4100 50  0000 C CNN
F 1 "0.1uF" V 8762 4100 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 8900 4100 50  0001 C CNN
F 3 "~" H 8900 4100 50  0001 C CNN
	1    8900 4100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0374
U 1 1 5B0D4925
P 9000 4100
F 0 "#PWR0374" H 9000 3850 50  0001 C CNN
F 1 "GND" V 9005 3972 50  0000 R CNN
F 2 "" H 9000 4100 50  0001 C CNN
F 3 "" H 9000 4100 50  0001 C CNN
	1    9000 4100
	0    -1   -1   0   
$EndComp
Text HLabel 8750 1300 2    50   Input ~ 0
~A_OUT_NCLK
Text HLabel 8750 1400 2    50   Input ~ 0
~B_OUT_NCLK
Text HLabel 8750 1500 2    50   Input ~ 0
~M0_OUT_NCLK
Text HLabel 8750 1600 2    50   Input ~ 0
~M1_OUT_NCLK
Text HLabel 8750 1700 2    50   Input ~ 0
~M2_OUT_NCLK
Text HLabel 8750 1800 2    50   Input ~ 0
~S0_OUT_NCLK
Text HLabel 8750 1900 2    50   Input ~ 0
~S1_OUT_NCLK
Text HLabel 8750 2000 2    50   Input ~ 0
~S2_OUT_NCLK
Text HLabel 8750 2400 2    50   Input ~ 0
~STATUS_OUT_NCLK
Text HLabel 8750 2500 2    50   Input ~ 0
~INT_OUT_NCLK
Text HLabel 8750 2600 2    50   Input ~ 0
~MMU_OUT_NCLK
Text HLabel 8750 2700 2    50   Input ~ 0
~MMU_CONTROL_OUT_NCLK
Text HLabel 8750 2800 2    50   Input ~ 0
~TASK_OUT_NCLK
Text HLabel 8750 2900 2    50   Input ~ 0
~MLU_OUT_NCLK
Text Notes 9150 4400 0    50   ~ 0
(none)
Text HLabel 9050 4500 2    50   Input ~ 0
~RESET_NCLK
Text HLabel 9050 4700 2    50   Input ~ 0
~SET_INT_ENABLE_ASYNC
Text HLabel 9050 4800 2    50   Input ~ 0
~UNSET_INT_ENABLE_ASYNC
Text Label 2800 8250 0    50   ~ 0
OP0
Text Label 2800 8350 0    50   ~ 0
OP1
Text Label 2800 8450 0    50   ~ 0
OP2
Text Label 2800 8550 0    50   ~ 0
OP3
Text Label 2800 8650 0    50   ~ 0
OP4
Text Label 2800 8750 0    50   ~ 0
OP5
Text Label 2800 8850 0    50   ~ 0
OP6
Text Label 2800 8950 0    50   ~ 0
OP7
Text Label 4500 8250 0    50   ~ 0
OP8
Text Label 4500 8350 0    50   ~ 0
OP9
Text Label 4500 8450 0    50   ~ 0
OP10
Text Label 4500 8550 0    50   ~ 0
OP11
Text Label 1600 4100 2    50   ~ 0
OP0
Text Label 1600 4200 2    50   ~ 0
OP1
Text Label 1600 4300 2    50   ~ 0
OP2
Text Label 1600 4400 2    50   ~ 0
OP3
Text Label 1600 4500 2    50   ~ 0
OP4
Text Label 1600 4600 2    50   ~ 0
OP5
Text Label 1600 4700 2    50   ~ 0
OP6
Text Label 1600 4800 2    50   ~ 0
OP7
Text Label 1600 4900 2    50   ~ 0
OP8
Text Label 1600 5000 2    50   ~ 0
OP9
Text Label 1600 5100 2    50   ~ 0
OP10
Text Label 1600 5200 2    50   ~ 0
OP11
Text Label 3400 4100 2    50   ~ 0
OP0
Text Label 3400 4200 2    50   ~ 0
OP1
Text Label 3400 4300 2    50   ~ 0
OP2
Text Label 3400 4400 2    50   ~ 0
OP3
Text Label 3400 4500 2    50   ~ 0
OP4
Text Label 3400 4600 2    50   ~ 0
OP5
Text Label 3400 4700 2    50   ~ 0
OP6
Text Label 3400 4800 2    50   ~ 0
OP7
Text Label 3400 4900 2    50   ~ 0
OP8
Text Label 3400 5000 2    50   ~ 0
OP9
Text Label 3400 5100 2    50   ~ 0
OP10
Text Label 3400 5200 2    50   ~ 0
OP11
$Sheet
S 12700 1150 550  600 
U 5B0D9D66
F0 "Micro Op Counter" 50
F1 "microop_counter.sch" 50
F2 "~RESET" I L 12700 1250 50 
F3 "CLK" I L 12700 1350 50 
F4 "O0" I R 13250 1250 50 
F5 "O1" I R 13250 1350 50 
F6 "O2" I R 13250 1450 50 
F7 "O3" I R 13250 1550 50 
F8 "O4" I R 13250 1650 50 
$EndSheet
Text Label 13250 1250 0    50   ~ 0
MICROOP0
Text Label 13250 1350 0    50   ~ 0
MICROOP1
Text Label 13250 1450 0    50   ~ 0
MICROOP2
Text Label 13250 1550 0    50   ~ 0
MICROOP3
Text Label 1600 5300 2    50   ~ 0
MICROOP0
Text Label 1600 5400 2    50   ~ 0
MICROOP1
Text Label 1600 5500 2    50   ~ 0
MICROOP2
Text Label 1600 5600 2    50   ~ 0
MICROOP3
Text Label 3400 5300 2    50   ~ 0
MICROOP0
Text Label 3400 5400 2    50   ~ 0
MICROOP1
Text Label 3400 5500 2    50   ~ 0
MICROOP2
Text Label 3400 5600 2    50   ~ 0
MICROOP3
$Sheet
S 12300 2450 1050 1100
U 5B101C06
F0 "Flag Logic" 50
F1 "flag_logic.sch" 50
F2 "INT_FLAG" I R 13350 3050 50 
F3 "INT0" I L 12300 2550 50 
F4 "INT1" I L 12300 2650 50 
F5 "INT2" I L 12300 2750 50 
F6 "INT3" I L 12300 2850 50 
F7 "INT4" I L 12300 2950 50 
F8 "INT5" I L 12300 3050 50 
F9 "INT6" I L 12300 3150 50 
F10 "INT7" I L 12300 3250 50 
F11 "MMU_READ_FAULT" I L 12300 3350 50 
F12 "MMU_WRITE_FAULT" I L 12300 3450 50 
F13 "MMU_FAULT_FLAG" I R 13350 2650 50 
$EndSheet
Text Label 14150 3650 0    50   ~ 0
INT_FLAG
Text Label 1600 5800 2    50   ~ 0
INT_FLAG
Text Label 3400 5800 2    50   ~ 0
INT_FLAG
Text Label 3400 5900 2    50   ~ 0
MMU_FAULT_FLAG
Text Label 1600 5900 2    50   ~ 0
MMU_FAULT_FLAG
Text HLabel 12300 3350 0    50   Input ~ 0
MMU_READ_FAULT
Text HLabel 12300 3450 0    50   Input ~ 0
MMU_WRITE_FAULT
Text Label 13350 2650 0    50   ~ 0
MMU_FAULT_FLAG
NoConn ~ 8200 2500
$Comp
L power:VCC #PWR0371
U 1 1 5B10FF24
P 5950 3950
F 0 "#PWR0371" H 5950 3800 50  0001 C CNN
F 1 "VCC" H 5967 4123 50  0000 C CNN
F 2 "" H 5950 3950 50  0001 C CNN
F 3 "" H 5950 3950 50  0001 C CNN
	1    5950 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C124
U 1 1 5B10FF2A
P 6250 3750
F 0 "C124" V 6021 3750 50  0000 C CNN
F 1 "0.1uF" V 6112 3750 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 6250 3750 50  0001 C CNN
F 3 "~" H 6250 3750 50  0001 C CNN
	1    6250 3750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0417
U 1 1 5B10FF31
P 6350 3750
F 0 "#PWR0417" H 6350 3500 50  0001 C CNN
F 1 "GND" V 6355 3622 50  0000 R CNN
F 2 "" H 6350 3750 50  0001 C CNN
F 3 "" H 6350 3750 50  0001 C CNN
	1    6350 3750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5950 3950 6150 3950
Wire Wire Line
	6150 3950 6150 3750
Connection ~ 5950 3950
$Comp
L power:GND #PWR0418
U 1 1 5B10FF3A
P 5950 6450
F 0 "#PWR0418" H 5950 6200 50  0001 C CNN
F 1 "GND" H 5955 6277 50  0000 C CNN
F 2 "" H 5950 6450 50  0001 C CNN
F 3 "" H 5950 6450 50  0001 C CNN
	1    5950 6450
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0419
U 1 1 5B10FF40
P 5350 6050
F 0 "#PWR0419" H 5350 5900 50  0001 C CNN
F 1 "VCC" V 5368 6177 50  0000 L CNN
F 2 "" H 5350 6050 50  0001 C CNN
F 3 "" H 5350 6050 50  0001 C CNN
	1    5350 6050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0420
U 1 1 5B10FF46
P 5350 6250
F 0 "#PWR0420" H 5350 6000 50  0001 C CNN
F 1 "GND" V 5355 6122 50  0000 R CNN
F 2 "" H 5350 6250 50  0001 C CNN
F 3 "" H 5350 6250 50  0001 C CNN
	1    5350 6250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0421
U 1 1 5B10FF4C
P 5350 6350
F 0 "#PWR0421" H 5350 6100 50  0001 C CNN
F 1 "GND" V 5355 6222 50  0000 R CNN
F 2 "" H 5350 6350 50  0001 C CNN
F 3 "" H 5350 6350 50  0001 C CNN
	1    5350 6350
	0    1    1    0   
$EndComp
Text Label 5350 4050 2    50   ~ 0
OP0
Text Label 5350 4150 2    50   ~ 0
OP1
Text Label 5350 4250 2    50   ~ 0
OP2
Text Label 5350 4350 2    50   ~ 0
OP3
Text Label 5350 4450 2    50   ~ 0
OP4
Text Label 5350 4550 2    50   ~ 0
OP5
Text Label 5350 4650 2    50   ~ 0
OP6
Text Label 5350 4750 2    50   ~ 0
OP7
Text Label 5350 4850 2    50   ~ 0
OP8
Text Label 5350 4950 2    50   ~ 0
OP9
Text Label 5350 5050 2    50   ~ 0
OP10
Text Label 5350 5150 2    50   ~ 0
OP11
Text Label 5350 5250 2    50   ~ 0
MICROOP0
Text Label 5350 5350 2    50   ~ 0
MICROOP1
Text Label 5350 5450 2    50   ~ 0
MICROOP2
Text Label 5350 5550 2    50   ~ 0
MICROOP3
Text Label 5350 5750 2    50   ~ 0
INT_FLAG
Text Label 5350 5850 2    50   ~ 0
MMU_FAULT_FLAG
Text Label 6550 4050 0    50   ~ 0
CTRL16
Text Label 6550 4150 0    50   ~ 0
CTRL17
Text Label 6550 4250 0    50   ~ 0
CTRL18
Text Label 6550 4350 0    50   ~ 0
CTRL19
Text Label 6550 4450 0    50   ~ 0
CTRL20
Text Label 6550 4550 0    50   ~ 0
CTRL21
Text Label 6550 4650 0    50   ~ 0
CTRL22
Text Label 6550 4750 0    50   ~ 0
CTRL23
$Comp
L 74xx:74LS574 U112
U 1 1 5B1107FE
P 5950 2200
F 0 "U112" H 5950 2000 50  0000 C CNN
F 1 "74LS574" H 6000 1900 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 5950 2200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS574" H 5950 2200 50  0001 C CNN
	1    5950 2200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0423
U 1 1 5B110805
P 5950 1400
F 0 "#PWR0423" H 5950 1250 50  0001 C CNN
F 1 "VCC" H 5967 1573 50  0000 C CNN
F 2 "" H 5950 1400 50  0001 C CNN
F 3 "" H 5950 1400 50  0001 C CNN
	1    5950 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0424
U 1 1 5B11080B
P 5950 3000
F 0 "#PWR0424" H 5950 2750 50  0001 C CNN
F 1 "GND" H 5955 2827 50  0000 C CNN
F 2 "" H 5950 3000 50  0001 C CNN
F 3 "" H 5950 3000 50  0001 C CNN
	1    5950 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C123
U 1 1 5B110811
P 6200 1400
F 0 "C123" V 5971 1400 50  0000 C CNN
F 1 "0.1uF" V 6062 1400 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 6200 1400 50  0001 C CNN
F 3 "~" H 6200 1400 50  0001 C CNN
	1    6200 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	5950 1400 6100 1400
Connection ~ 5950 1400
$Comp
L power:GND #PWR0425
U 1 1 5B11081A
P 6300 1400
F 0 "#PWR0425" H 6300 1150 50  0001 C CNN
F 1 "GND" V 6305 1272 50  0000 R CNN
F 2 "" H 6300 1400 50  0001 C CNN
F 3 "" H 6300 1400 50  0001 C CNN
	1    6300 1400
	0    -1   -1   0   
$EndComp
Text Label 5450 1700 2    50   ~ 0
CTRL16
Text Label 5450 1800 2    50   ~ 0
CTRL17
Text Label 5450 1900 2    50   ~ 0
CTRL18
Text Label 5450 2000 2    50   ~ 0
CTRL19
Text Label 5450 2100 2    50   ~ 0
CTRL20
Text Label 5450 2200 2    50   ~ 0
CTRL21
Text Label 5450 2300 2    50   ~ 0
CTRL22
Text Label 5450 2400 2    50   ~ 0
CTRL23
Text Label 4400 1700 0    50   ~ 0
CTRL_OUT0
Text Label 4400 1800 0    50   ~ 0
CTRL_OUT1
Text Label 4400 1900 0    50   ~ 0
CTRL_OUT2
Text Label 4400 2000 0    50   ~ 0
CTRL_OUT3
Text Label 4400 2100 0    50   ~ 0
CTRL_OUT4
Text Label 8200 1200 2    50   ~ 0
CTRL_OUT0
Text Label 8200 1300 2    50   ~ 0
CTRL_OUT1
Text Label 8200 1400 2    50   ~ 0
CTRL_OUT2
Text Label 8200 1500 2    50   ~ 0
CTRL_OUT3
Text Label 8200 1600 2    50   ~ 0
CTRL_OUT4
Text Label 7400 1700 1    50   ~ 0
CTRL_OUT4
Text Label 8500 6050 2    50   ~ 0
CTRL_IN0
Text Label 8500 6150 2    50   ~ 0
CTRL_IN1
Text Label 8500 6250 2    50   ~ 0
CTRL_IN2
Text Label 8500 6350 2    50   ~ 0
CTRL_IN3
Text Label 8500 6450 2    50   ~ 0
CTRL_IN4
Text Label 7550 6550 2    50   ~ 0
CTRL_IN4
Text Label 2400 1700 0    50   ~ 0
CTRL_IN0
Text Label 2400 1800 0    50   ~ 0
CTRL_IN1
Text Label 2400 1900 0    50   ~ 0
CTRL_IN2
Text Label 2400 2000 0    50   ~ 0
CTRL_IN3
Text Label 2400 2100 0    50   ~ 0
CTRL_IN4
Text Label 2400 2200 0    50   ~ 0
CTRL_MULTI0
Text Label 2400 2300 0    50   ~ 0
CTRL_MULTI1
Text Label 2400 2400 0    50   ~ 0
CTRL_MULTI2
Text Label 8050 4400 2    50   ~ 0
CTRL_MULTI0
Text Label 8050 4500 2    50   ~ 0
CTRL_MULTI1
Text Label 8050 4600 2    50   ~ 0
CTRL_MULTI2
Text HLabel 5450 2600 0    50   Input ~ 0
~CLK
Text HLabel 3400 2600 0    50   Input ~ 0
~CLK
Text HLabel 1400 2600 0    50   Input ~ 0
~CLK
$Comp
L power:GND #PWR0427
U 1 1 5B114288
P 3400 2700
F 0 "#PWR0427" H 3400 2450 50  0001 C CNN
F 1 "GND" H 3405 2527 50  0000 C CNN
F 2 "" H 3400 2700 50  0001 C CNN
F 3 "" H 3400 2700 50  0001 C CNN
	1    3400 2700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0428
U 1 1 5B1142B3
P 1400 2700
F 0 "#PWR0428" H 1400 2450 50  0001 C CNN
F 1 "GND" H 1405 2527 50  0000 C CNN
F 2 "" H 1400 2700 50  0001 C CNN
F 3 "" H 1400 2700 50  0001 C CNN
	1    1400 2700
	0    1    1    0   
$EndComp
Text Label 8750 3000 0    50   ~ 0
~CTRLLOGIC_OUT_NCLK
Text Label 5450 2700 2    50   ~ 0
~CTRLLOGIC_OUT_NCLK
Text HLabel 6450 1700 2    50   Input ~ 0
BUS0
Text HLabel 6450 1800 2    50   Input ~ 0
BUS1
Text HLabel 6450 1900 2    50   Input ~ 0
BUS2
Text HLabel 6450 2000 2    50   Input ~ 0
BUS3
Text HLabel 6450 2100 2    50   Input ~ 0
BUS4
Text HLabel 6450 2200 2    50   Input ~ 0
BUS5
Text HLabel 6450 2300 2    50   Input ~ 0
BUS6
Text HLabel 6450 2400 2    50   Input ~ 0
BUS7
Wire Notes Line
	800  3400 800  6850
Wire Notes Line
	800  6850 7100 6850
Wire Notes Line
	850  1050 850  3300
Wire Notes Line
	850  1050 6900 1050
Wire Notes Line
	850  3300 6900 3300
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
P 7700 1700
F 0 "U114" H 7700 1700 50  0000 C CNN
F 1 "74HC04" H 7850 1600 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7700 1700 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 7700 1700 50  0001 C CNN
	4    7700 1700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U114
U 7 1 5B1323FA
P 13650 5500
F 0 "U114" H 13880 5546 50  0000 L CNN
F 1 "74HC04" H 13880 5455 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 13650 5500 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 13650 5500 50  0001 C CNN
	7    13650 5500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0445
U 1 1 5B132401
P 13650 5000
F 0 "#PWR0445" H 13650 4850 50  0001 C CNN
F 1 "VCC" H 13667 5173 50  0000 C CNN
F 2 "" H 13650 5000 50  0001 C CNN
F 3 "" H 13650 5000 50  0001 C CNN
	1    13650 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C125
U 1 1 5B132407
P 14000 5000
F 0 "C125" V 13771 5000 50  0000 C CNN
F 1 "0.1uF" V 13862 5000 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 14000 5000 50  0001 C CNN
F 3 "~" H 14000 5000 50  0001 C CNN
	1    14000 5000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0446
U 1 1 5B13240E
P 14100 5000
F 0 "#PWR0446" H 14100 4750 50  0001 C CNN
F 1 "GND" V 14105 4872 50  0000 R CNN
F 2 "" H 14100 5000 50  0001 C CNN
F 3 "" H 14100 5000 50  0001 C CNN
	1    14100 5000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	13650 5000 13900 5000
Connection ~ 13650 5000
$Comp
L power:GND #PWR0447
U 1 1 5B132416
P 13650 6000
F 0 "#PWR0447" H 13650 5750 50  0001 C CNN
F 1 "GND" V 13655 5872 50  0000 R CNN
F 2 "" H 13650 6000 50  0001 C CNN
F 3 "" H 13650 6000 50  0001 C CNN
	1    13650 6000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U114
U 1 1 5B141E1A
P 10850 6150
F 0 "U114" H 10850 6150 50  0000 C CNN
F 1 "74HC04" H 11000 6050 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 10850 6150 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 10850 6150 50  0001 C CNN
	1    10850 6150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U114
U 2 1 5B141E21
P 10850 6450
F 0 "U114" H 10850 6450 50  0000 C CNN
F 1 "74HC04" H 11000 6350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 10850 6450 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 10850 6450 50  0001 C CNN
	2    10850 6450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U114
U 5 1 5B141E36
P 7850 6550
F 0 "U114" H 7850 6550 50  0000 C CNN
F 1 "74HC04" H 8000 6450 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7850 6550 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 7850 6550 50  0001 C CNN
	5    7850 6550
	1    0    0    -1  
$EndComp
Text HLabel 9050 6150 2    50   Input ~ 0
A_IN_CLK
Text HLabel 9050 6250 2    50   Input ~ 0
B_IN_CLK
Text HLabel 9050 6350 2    50   Input ~ 0
M0_IN_CLK
Text HLabel 9050 6450 2    50   Input ~ 0
M1_IN_CLK
Text HLabel 9050 6550 2    50   Input ~ 0
M2_IN_CLK
Text HLabel 9050 7250 2    50   Input ~ 0
MMU0_IN_CLK
Text HLabel 9050 7350 2    50   Input ~ 0
MMU1_IN_CLK
Text HLabel 9050 7750 2    50   Input ~ 0
DISP_IN_CLK
Text HLabel 9050 7950 2    50   Input ~ 0
TASK_IN_CLK
Text HLabel 8500 7550 0    50   Input ~ 0
INT0_IN_CLK
Text HLabel 8500 7450 0    50   Input ~ 0
INT1_IN_CLK
Text HLabel 8500 7350 0    50   Input ~ 0
INT2_IN_CLK
Text HLabel 8500 7250 0    50   Input ~ 0
INT3_IN_CLK
Text HLabel 8500 7150 0    50   Input ~ 0
INT4_IN_CLK
Text HLabel 8500 7050 0    50   Input ~ 0
INT5_IN_CLK
Text HLabel 8500 6950 0    50   Input ~ 0
INT6_IN_CLK
Text HLabel 8500 6850 0    50   Input ~ 0
INT7_IN_CLK
Text HLabel 12300 2550 0    50   Input ~ 0
INT0_LATCH
Text HLabel 12300 2650 0    50   Input ~ 0
INT1_LATCH
Text HLabel 12300 2750 0    50   Input ~ 0
INT2_LATCH
Text HLabel 12300 2850 0    50   Input ~ 0
INT3_LATCH
Text HLabel 12300 2950 0    50   Input ~ 0
INT4_LATCH
Text HLabel 12300 3050 0    50   Input ~ 0
INT5_LATCH
Text HLabel 12300 3150 0    50   Input ~ 0
INT6_LATCH
Text HLabel 12300 3250 0    50   Input ~ 0
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
P 13850 3650
F 0 "U117" H 13850 3975 50  0000 C CNN
F 1 "74LS08" H 13850 3884 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 13850 3650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 13850 3650 50  0001 C CNN
	1    13850 3650
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
P 14650 5500
F 0 "U117" H 14880 5546 50  0000 L CNN
F 1 "74LS08" H 14880 5455 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 14650 5500 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 14650 5500 50  0001 C CNN
	5    14650 5500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0455
U 1 1 5B1CED2B
P 14650 5000
F 0 "#PWR0455" H 14650 4850 50  0001 C CNN
F 1 "VCC" H 14667 5173 50  0000 C CNN
F 2 "" H 14650 5000 50  0001 C CNN
F 3 "" H 14650 5000 50  0001 C CNN
	1    14650 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C128
U 1 1 5B1CED31
P 15000 5000
F 0 "C128" V 14771 5000 50  0000 C CNN
F 1 "0.1uF" V 14862 5000 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 15000 5000 50  0001 C CNN
F 3 "~" H 15000 5000 50  0001 C CNN
	1    15000 5000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0456
U 1 1 5B1CED38
P 15100 5000
F 0 "#PWR0456" H 15100 4750 50  0001 C CNN
F 1 "GND" V 15105 4872 50  0000 R CNN
F 2 "" H 15100 5000 50  0001 C CNN
F 3 "" H 15100 5000 50  0001 C CNN
	1    15100 5000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	14650 5000 14900 5000
Connection ~ 14650 5000
Text HLabel 13550 3750 0    50   Input ~ 0
INTERRUPT_ENABLE_FLAG
Wire Wire Line
	13350 3050 13550 3050
Wire Wire Line
	13550 3050 13550 3550
Text Notes 13250 4100 0    50   ~ 0
This and isn't done inside the\nflag logic sheet since spare\nand gates get confusing.
Text Notes 19050 1600 0    50   ~ 0
SPARE AVAILABLE
Text HLabel 4400 2200 2    50   Input ~ 0
MLU_SEL0
Text HLabel 4400 2300 2    50   Input ~ 0
MLU_SEL1
Text HLabel 4400 2400 2    50   Input ~ 0
MLU_SEL2
$Sheet
S 8200 1100 550  2300
U 5B0CC7A2
F0 "OUT plane decoder" 50
F1 "5_32_decoder.sch" 50
F2 "S0" I L 8200 1200 50 
F3 "S1" I L 8200 1300 50 
F4 "S2" I L 8200 1400 50 
F5 "S3" I L 8200 1500 50 
F6 "O0" I R 8750 1200 50 
F7 "O1" I R 8750 1300 50 
F8 "O2" I R 8750 1400 50 
F9 "O3" I R 8750 1500 50 
F10 "O4" I R 8750 1600 50 
F11 "O5" I R 8750 1700 50 
F12 "O6" I R 8750 1800 50 
F13 "O7" I R 8750 1900 50 
F14 "O8" I R 8750 2000 50 
F15 "O9" I R 8750 2100 50 
F16 "O10" I R 8750 2200 50 
F17 "O11" I R 8750 2300 50 
F18 "O12" I R 8750 2400 50 
F19 "O13" I R 8750 2500 50 
F20 "O14" I R 8750 2600 50 
F21 "O15" I R 8750 2700 50 
F22 "O16" I R 8750 2800 50 
F23 "O17" I R 8750 2900 50 
F24 "O18" I R 8750 3000 50 
F25 "O19" I R 8750 3100 50 
F26 "O20" I R 8750 3200 50 
F27 "O21" I R 8750 3300 50 
F28 "O22" I L 8200 2400 50 
F29 "O23" I L 8200 2500 50 
F30 "O24" I L 8200 2600 50 
F31 "O25" I L 8200 2700 50 
F32 "O26" I L 8200 2800 50 
F33 "O27" I L 8200 2900 50 
F34 "O28" I L 8200 3000 50 
F35 "O29" I L 8200 3100 50 
F36 "O30" I L 8200 3200 50 
F37 "O31" I L 8200 3300 50 
F38 "S4" I L 8200 1600 50 
F39 "~S4" I L 8200 1700 50 
$EndSheet
Text HLabel 8750 2100 2    50   Input ~ 0
~PC0_OUT_NCLK
Text HLabel 8750 2200 2    50   Input ~ 0
~PC1_OUT_NCLK
Text HLabel 8750 2300 2    50   Input ~ 0
~PC2_OUT_NCLK
$Comp
L power:GND #PWR061
U 1 1 5B243822
P 14650 6000
F 0 "#PWR061" H 14650 5750 50  0001 C CNN
F 1 "GND" V 14655 5872 50  0000 R CNN
F 2 "" H 14650 6000 50  0001 C CNN
F 3 "" H 14650 6000 50  0001 C CNN
	1    14650 6000
	1    0    0    -1  
$EndComp
Text HLabel 9050 7450 2    50   Input ~ 0
MMU2_IN_CLK
Text HLabel 11150 6150 2    50   Input ~ 0
~MMU_IN_CLK
Text HLabel 11150 6450 2    50   Input ~ 0
~MMU_CONTROL_IN_CLK
Text Label 9050 4600 0    50   ~ 0
~RESET_UOP_COUNT_NCLK
Text Label 12700 1250 2    50   ~ 0
~RESET_UOP_COUNT_NCLK
Text Notes 12150 1000 0    50   ~ 0
Update the micro-op counter on the rising edge so\nwe have enough time to latch the control word on\nthe falling edge (not trying to simultaneously \nupdate the micro op counter).
Text Label 12700 1350 2    50   ~ 0
CLK
Text HLabel 8200 2600 0    50   Input ~ 0
~INT0_OUT_NCLK
Text HLabel 8200 2700 0    50   Input ~ 0
~INT1_OUT_NCLK
Text HLabel 8200 2800 0    50   Input ~ 0
~INT2_OUT_NCLK
Text HLabel 8200 2900 0    50   Input ~ 0
~INT3_OUT_NCLK
Text HLabel 8200 3000 0    50   Input ~ 0
~INT4_OUT_NCLK
Text HLabel 8200 3100 0    50   Input ~ 0
~INT5_OUT_NCLK
Text HLabel 8200 3200 0    50   Input ~ 0
~INT6_OUT_NCLK
Text HLabel 8200 3300 0    50   Input ~ 0
~INT7_OUT_NCLK
$Comp
L Memory_Flash:SST39SF040 U113
U 1 1 5B5502C3
P 5950 5250
F 0 "U113" H 5950 5350 50  0000 C CNN
F 1 "SST39SF040" H 6000 5200 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 5950 5550 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 5950 5550 50  0001 C CNN
	1    5950 5250
	1    0    0    -1  
$EndComp
$Comp
L Memory_Flash:SST39SF040 U90
U 1 1 5B5526B8
P 4000 5300
F 0 "U90" H 4000 5400 50  0000 C CNN
F 1 "SST39SF040" H 4050 5250 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 4000 5600 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 4000 5600 50  0001 C CNN
	1    4000 5300
	1    0    0    -1  
$EndComp
Connection ~ 4000 4000
$Comp
L Memory_Flash:SST39SF040 U88
U 1 1 5B552AB5
P 2200 5300
F 0 "U88" H 2200 5400 50  0000 C CNN
F 1 "SST39SF040" H 2250 5250 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 2200 5600 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 2200 5600 50  0001 C CNN
	1    2200 5300
	1    0    0    -1  
$EndComp
Connection ~ 2200 4000
NoConn ~ 8750 3200
NoConn ~ 8750 3300
NoConn ~ 8200 2400
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
Text HLabel 9050 6650 2    50   Input ~ 0
S0_IN_CLK
Text HLabel 9050 6750 2    50   Input ~ 0
S1_IN_CLK
Text HLabel 9050 6850 2    50   Input ~ 0
S2_IN_CLK
Text HLabel 9050 6950 2    50   Input ~ 0
PC0_IN_CLK
Text HLabel 9050 7050 2    50   Input ~ 0
PC1_IN_CLK
Text HLabel 9050 7150 2    50   Input ~ 0
PC2_IN_CLK
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
NoConn ~ 8750 3100
$Comp
L 74xx:74LS273 U13
U 1 1 5B74EE1E
P 2300 8750
F 0 "U13" H 2300 8750 50  0000 C CNN
F 1 "74LS273" H 2350 8450 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 2300 8750 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS273" H 2300 8750 50  0001 C CNN
	1    2300 8750
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS273 U15
U 1 1 5B74F277
P 4000 8750
F 0 "U15" H 4000 8800 50  0000 C CNN
F 1 "74LS273" H 4050 8450 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 4000 8750 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS273" H 4000 8750 50  0001 C CNN
	1    4000 8750
	1    0    0    -1  
$EndComp
Text HLabel 1800 9250 0    50   Input ~ 0
~RESET
Text HLabel 3500 9250 0    50   Input ~ 0
~RESET
Text Label 1800 9150 2    50   ~ 0
OPCODE0_IN_CLK
Text Label 3500 9150 2    50   ~ 0
OPCODE1_IN_CLK
$Sheet
S 8500 5950 550  2100
U 5B6E8695
F0 "IN decoder" 50
F1 "in_plane_decoder.sch" 50
F2 "S0" I L 8500 6050 50 
F3 "S1" I L 8500 6150 50 
F4 "S2" I L 8500 6250 50 
F5 "O0" I R 9050 6050 50 
F6 "O1" I R 9050 6150 50 
F7 "O2" I R 9050 6250 50 
F8 "O3" I R 9050 6350 50 
F9 "O4" I R 9050 6450 50 
F10 "O5" I R 9050 6550 50 
F11 "O6" I R 9050 6650 50 
F12 "O7" I R 9050 6750 50 
F13 "O8" I R 9050 6850 50 
F14 "O9" I R 9050 6950 50 
F15 "O10" I R 9050 7050 50 
F16 "O11" I R 9050 7150 50 
F17 "O12" I R 9050 7250 50 
F18 "O13" I R 9050 7350 50 
F19 "O14" I R 9050 7450 50 
F20 "O15" I R 9050 7550 50 
F21 "O16" I R 9050 7650 50 
F22 "O17" I R 9050 7750 50 
F23 "O18" I R 9050 7850 50 
F24 "O19" I R 9050 7950 50 
F25 "O20" I L 8500 7950 50 
F26 "O21" I L 8500 7850 50 
F27 "O22" I L 8500 7750 50 
F28 "O23" I L 8500 7650 50 
F29 "O24" I L 8500 7550 50 
F30 "O25" I L 8500 7450 50 
F31 "O26" I L 8500 7350 50 
F32 "O27" I L 8500 7250 50 
F33 "O28" I L 8500 7150 50 
F34 "O29" I L 8500 7050 50 
F35 "O30" I L 8500 6950 50 
F36 "O31" I L 8500 6850 50 
F37 "S3" I L 8500 6350 50 
F38 "S4" I L 8500 6450 50 
F39 "~S4" I L 8500 6550 50 
F40 "CLK" I L 8500 6650 50 
F41 "~CLK" I L 8500 6750 50 
$EndSheet
Text HLabel 8500 6650 0    50   Input ~ 0
CLK
Text HLabel 8500 6750 0    50   Input ~ 0
~CLK
NoConn ~ 9050 6050
Text Notes 9150 6050 0    50   ~ 0
(none)
Text Label 9050 7550 0    50   ~ 0
MMU_IN_CLK
Text Label 9050 7650 0    50   ~ 0
MMU_CONTROL_IN_CLK
NoConn ~ 8500 7650
Text Label 8500 7950 2    50   ~ 0
OPCODE0_IN_CLK
Text Label 8500 7850 2    50   ~ 0
OPCODE1_IN_CLK
Text Label 10550 6150 2    50   ~ 0
MMU_IN_CLK
Text Label 10550 6450 2    50   ~ 0
MMU_CONTROL_IN_CLK
Text HLabel 1800 8250 0    50   Input ~ 0
BUS0
Text HLabel 1800 8350 0    50   Input ~ 0
BUS1
Text HLabel 1800 8450 0    50   Input ~ 0
BUS2
Text HLabel 1800 8550 0    50   Input ~ 0
BUS3
Text HLabel 1800 8650 0    50   Input ~ 0
BUS4
Text HLabel 1800 8750 0    50   Input ~ 0
BUS5
Text HLabel 1800 8850 0    50   Input ~ 0
BUS6
Text HLabel 1800 8950 0    50   Input ~ 0
BUS7
Text HLabel 3500 8250 0    50   Input ~ 0
BUS0
Text HLabel 3500 8350 0    50   Input ~ 0
BUS1
Text HLabel 3500 8450 0    50   Input ~ 0
BUS2
Text HLabel 3500 8550 0    50   Input ~ 0
BUS3
Text HLabel 3500 8650 0    50   Input ~ 0
BUS4
Text HLabel 3500 8750 0    50   Input ~ 0
BUS5
Text HLabel 3500 8850 0    50   Input ~ 0
BUS6
Text HLabel 3500 8950 0    50   Input ~ 0
BUS7
$Comp
L power:GND #PWR0125
U 1 1 5B6E7D95
P 2300 9550
F 0 "#PWR0125" H 2300 9300 50  0001 C CNN
F 1 "GND" H 2305 9377 50  0000 C CNN
F 2 "" H 2300 9550 50  0001 C CNN
F 3 "" H 2300 9550 50  0001 C CNN
	1    2300 9550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0130
U 1 1 5B6E7DE0
P 4000 9550
F 0 "#PWR0130" H 4000 9300 50  0001 C CNN
F 1 "GND" H 4005 9377 50  0000 C CNN
F 2 "" H 4000 9550 50  0001 C CNN
F 3 "" H 4000 9550 50  0001 C CNN
	1    4000 9550
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0131
U 1 1 5B6E8319
P 2300 7950
F 0 "#PWR0131" H 2300 7800 50  0001 C CNN
F 1 "VCC" H 2317 8123 50  0000 C CNN
F 2 "" H 2300 7950 50  0001 C CNN
F 3 "" H 2300 7950 50  0001 C CNN
	1    2300 7950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C24
U 1 1 5B6E831F
P 2650 7950
F 0 "C24" V 2421 7950 50  0000 C CNN
F 1 "0.1uF" V 2512 7950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2650 7950 50  0001 C CNN
F 3 "~" H 2650 7950 50  0001 C CNN
	1    2650 7950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0132
U 1 1 5B6E8326
P 2750 7950
F 0 "#PWR0132" H 2750 7700 50  0001 C CNN
F 1 "GND" V 2755 7822 50  0000 R CNN
F 2 "" H 2750 7950 50  0001 C CNN
F 3 "" H 2750 7950 50  0001 C CNN
	1    2750 7950
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0133
U 1 1 5B6E857A
P 4000 7950
F 0 "#PWR0133" H 4000 7800 50  0001 C CNN
F 1 "VCC" H 4017 8123 50  0000 C CNN
F 2 "" H 4000 7950 50  0001 C CNN
F 3 "" H 4000 7950 50  0001 C CNN
	1    4000 7950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C25
U 1 1 5B6E8580
P 4350 7950
F 0 "C25" V 4121 7950 50  0000 C CNN
F 1 "0.1uF" V 4212 7950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4350 7950 50  0001 C CNN
F 3 "~" H 4350 7950 50  0001 C CNN
	1    4350 7950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0134
U 1 1 5B6E8587
P 4450 7950
F 0 "#PWR0134" H 4450 7700 50  0001 C CNN
F 1 "GND" V 4455 7822 50  0000 R CNN
F 2 "" H 4450 7950 50  0001 C CNN
F 3 "" H 4450 7950 50  0001 C CNN
	1    4450 7950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4250 7950 4000 7950
Connection ~ 4000 7950
Wire Wire Line
	2550 7950 2300 7950
Connection ~ 2300 7950
NoConn ~ 4500 8650
NoConn ~ 4500 8750
NoConn ~ 4500 8850
NoConn ~ 4500 8950
Text Notes 2800 7550 0    50   ~ 0
Opcode Registers
Wire Notes Line
	1050 7350 1050 9850
Wire Notes Line
	1050 9850 4850 9850
Wire Notes Line
	4850 9850 4850 7350
Wire Notes Line
	4850 7350 1050 7350
$Comp
L 74xx:74LS138 U37
U 1 1 5B6ED658
P 8550 4700
F 0 "U37" H 8550 4750 50  0000 C CNN
F 1 "74LS138" H 8550 4650 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 8550 4700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS138" H 8550 4700 50  0001 C CNN
	1    8550 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 4100 8550 4100
Connection ~ 8550 4100
NoConn ~ 9050 4400
NoConn ~ 9050 4900
NoConn ~ 9050 5000
NoConn ~ 9050 5100
$Comp
L power:GND #PWR0135
U 1 1 5B6EFF03
P 8050 5000
F 0 "#PWR0135" H 8050 4750 50  0001 C CNN
F 1 "GND" V 8055 4872 50  0000 R CNN
F 2 "" H 8050 5000 50  0001 C CNN
F 3 "" H 8050 5000 50  0001 C CNN
	1    8050 5000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0136
U 1 1 5B6EFF54
P 8050 5100
F 0 "#PWR0136" H 8050 4850 50  0001 C CNN
F 1 "GND" V 8055 4972 50  0000 R CNN
F 2 "" H 8050 5100 50  0001 C CNN
F 3 "" H 8050 5100 50  0001 C CNN
	1    8050 5100
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0149
U 1 1 5B6EFFA5
P 8050 4900
F 0 "#PWR0149" H 8050 4750 50  0001 C CNN
F 1 "VCC" H 8067 5073 50  0000 C CNN
F 2 "" H 8050 4900 50  0001 C CNN
F 3 "" H 8050 4900 50  0001 C CNN
	1    8050 4900
	0    -1   -1   0   
$EndComp
Wire Notes Line
	7100 6850 7100 3400
Wire Notes Line
	7100 3400 800  3400
Text Label 13250 1650 0    50   ~ 0
MICROOP4
Text Label 5350 5650 2    50   ~ 0
MICROOP4
Text Label 3400 5700 2    50   ~ 0
MICROOP4
Text Label 1600 5700 2    50   ~ 0
MICROOP4
Text HLabel 9050 7850 2    50   Input ~ 0
DISP_MODE_IN_CLK
Text HLabel 8500 7750 0    50   Input ~ 0
INT_IN_CLK
$EndSCHEMATC
