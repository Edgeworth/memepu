EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 14 33
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
L 74xx:74HC74 U37
U 1 1 5B094EC2
P 1600 2200
F 0 "U37" H 1600 2200 50  0000 C CNN
F 1 "74HC74" H 1800 1950 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1600 2200 50  0001 C CNN
F 3 "74xx/74hc_hct74.pdf" H 1600 2200 50  0001 C CNN
	1    1600 2200
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC74 U37
U 2 1 5B094F1D
P 1550 3250
F 0 "U37" H 1550 3250 50  0000 C CNN
F 1 "74HC74" H 1700 2950 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1550 3250 50  0001 C CNN
F 3 "74xx/74hc_hct74.pdf" H 1550 3250 50  0001 C CNN
	2    1550 3250
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC74 U37
U 3 1 5B094F94
P 1150 950
F 0 "U37" H 1380 996 50  0000 L CNN
F 1 "74HC74" H 1380 905 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1150 950 50  0001 C CNN
F 3 "74xx/74hc_hct74.pdf" H 1150 950 50  0001 C CNN
	3    1150 950 
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C45
U 1 1 5B09548E
P 550 950
F 0 "C45" H 458 904 50  0000 R CNN
F 1 "0.1uF" H 458 995 50  0000 R CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 550 950 50  0001 C CNN
F 3 "~" H 550 950 50  0001 C CNN
	1    550  950 
	-1   0    0    1   
$EndComp
Wire Wire Line
	550  850  550  550 
Wire Wire Line
	550  550  1150 550 
Wire Wire Line
	1150 1350 550  1350
Wire Wire Line
	550  1350 550  1050
$Comp
L power:VCC #PWR0177
U 1 1 5B0955EF
P 1150 550
F 0 "#PWR0177" H 1150 400 50  0001 C CNN
F 1 "VCC" H 1167 723 50  0000 C CNN
F 2 "" H 1150 550 50  0001 C CNN
F 3 "" H 1150 550 50  0001 C CNN
	1    1150 550 
	1    0    0    -1  
$EndComp
Connection ~ 1150 550 
$Comp
L power:GND #PWR0178
U 1 1 5B09563D
P 1150 1350
F 0 "#PWR0178" H 1150 1100 50  0001 C CNN
F 1 "GND" H 1155 1177 50  0000 C CNN
F 2 "" H 1150 1350 50  0001 C CNN
F 3 "" H 1150 1350 50  0001 C CNN
	1    1150 1350
	1    0    0    -1  
$EndComp
Connection ~ 1150 1350
Text HLabel 4400 2100 2    50   Input ~ 0
INTERRUPT_ENABLE_FLAG
Text HLabel 1900 2100 2    50   Input ~ 0
CARRY_FLAG
NoConn ~ 1900 2300
NoConn ~ 4400 2300
Text HLabel 1300 2200 0    50   Input ~ 0
CARRY_CLK
Text HLabel 1250 3250 0    50   Input ~ 0
ZERO_CLK
Text HLabel 1250 3150 0    50   Input ~ 0
ZERO
Text HLabel 1850 3150 2    50   Input ~ 0
ZERO_FLAG
NoConn ~ 1850 3350
Text HLabel 4100 1900 0    50   Input ~ 0
~SET_INTERRUPT_ENABLE_ASYNC
Text HLabel 4100 2500 0    50   Input ~ 0
~UNSET_INTERRUPT_ENABLE_ASYNC
Text HLabel 1300 2100 0    50   Input ~ 0
CARRY
Text HLabel 1600 2500 0    50   Input ~ 0
~RESET
Text HLabel 1550 3550 0    50   Input ~ 0
~RESET
$Comp
L power:VCC #PWR0184
U 1 1 5B095C6B
P 1600 1900
F 0 "#PWR0184" H 1600 1750 50  0001 C CNN
F 1 "VCC" H 1617 2073 50  0000 C CNN
F 2 "" H 1600 1900 50  0001 C CNN
F 3 "" H 1600 1900 50  0001 C CNN
	1    1600 1900
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0185
U 1 1 5B095C86
P 1550 2950
F 0 "#PWR0185" H 1550 2800 50  0001 C CNN
F 1 "VCC" H 1567 3123 50  0000 C CNN
F 2 "" H 1550 2950 50  0001 C CNN
F 3 "" H 1550 2950 50  0001 C CNN
	1    1550 2950
	1    0    0    -1  
$EndComp
Wire Notes Line
	850  3900 850  5050
Wire Notes Line
	850  5050 2200 5050
Wire Notes Line
	2200 5050 2200 3900
Wire Notes Line
	2200 3900 850  3900
Text Notes 950  4050 0    50   ~ 0
Spares
$Comp
L 74xx:74HC74 U38
U 3 1 5B0D5613
P 2450 950
F 0 "U38" H 2680 996 50  0000 L CNN
F 1 "74HC74" H 2680 905 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 2450 950 50  0001 C CNN
F 3 "74xx/74hc_hct74.pdf" H 2450 950 50  0001 C CNN
	3    2450 950 
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C46
U 1 1 5B0D561A
P 1850 950
F 0 "C46" H 1758 904 50  0000 R CNN
F 1 "0.1uF" H 1758 995 50  0000 R CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 1850 950 50  0001 C CNN
F 3 "~" H 1850 950 50  0001 C CNN
	1    1850 950 
	-1   0    0    1   
$EndComp
Wire Wire Line
	1850 850  1850 550 
Wire Wire Line
	1850 550  2450 550 
Wire Wire Line
	2450 1350 1850 1350
Wire Wire Line
	1850 1350 1850 1050
$Comp
L power:VCC #PWR0176
U 1 1 5B0D5625
P 2450 550
F 0 "#PWR0176" H 2450 400 50  0001 C CNN
F 1 "VCC" H 2467 723 50  0000 C CNN
F 2 "" H 2450 550 50  0001 C CNN
F 3 "" H 2450 550 50  0001 C CNN
	1    2450 550 
	1    0    0    -1  
$EndComp
Connection ~ 2450 550 
$Comp
L power:GND #PWR0179
U 1 1 5B0D562C
P 2450 1350
F 0 "#PWR0179" H 2450 1100 50  0001 C CNN
F 1 "GND" H 2455 1177 50  0000 C CNN
F 2 "" H 2450 1350 50  0001 C CNN
F 3 "" H 2450 1350 50  0001 C CNN
	1    2450 1350
	1    0    0    -1  
$EndComp
Connection ~ 2450 1350
$Comp
L 74xx:74HC74 U38
U 1 1 5B0D567F
P 4100 2200
F 0 "U38" H 4100 2200 50  0000 C CNN
F 1 "74HC74" H 4300 1950 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 4100 2200 50  0001 C CNN
F 3 "74xx/74hc_hct74.pdf" H 4100 2200 50  0001 C CNN
	1    4100 2200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0183
U 1 1 5B095949
P 1550 4800
F 0 "#PWR0183" H 1550 4650 50  0001 C CNN
F 1 "VCC" H 1568 4973 50  0000 C CNN
F 2 "" H 1550 4800 50  0001 C CNN
F 3 "" H 1550 4800 50  0001 C CNN
	1    1550 4800
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0181
U 1 1 5B095913
P 1250 4400
F 0 "#PWR0181" H 1250 4150 50  0001 C CNN
F 1 "GND" V 1255 4272 50  0000 R CNN
F 2 "" H 1250 4400 50  0001 C CNN
F 3 "" H 1250 4400 50  0001 C CNN
	1    1250 4400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0180
U 1 1 5B0958F0
P 1250 4500
F 0 "#PWR0180" H 1250 4250 50  0001 C CNN
F 1 "GND" V 1255 4372 50  0000 R CNN
F 2 "" H 1250 4500 50  0001 C CNN
F 3 "" H 1250 4500 50  0001 C CNN
	1    1250 4500
	0    1    1    0   
$EndComp
NoConn ~ 1850 4600
NoConn ~ 1850 4400
$Comp
L 74xx:74HC74 U38
U 2 1 5B0D57A6
P 1550 4500
F 0 "U38" H 1550 4500 50  0000 C CNN
F 1 "74HC74" H 1700 4200 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1550 4500 50  0001 C CNN
F 3 "74xx/74hc_hct74.pdf" H 1550 4500 50  0001 C CNN
	2    1550 4500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0182
U 1 1 5B0D57F7
P 1550 4200
F 0 "#PWR0182" H 1550 4050 50  0001 C CNN
F 1 "VCC" H 1567 4373 50  0000 C CNN
F 2 "" H 1550 4200 50  0001 C CNN
F 3 "" H 1550 4200 50  0001 C CNN
	1    1550 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0349
U 1 1 5B0D5D09
P 3800 2200
F 0 "#PWR0349" H 3800 1950 50  0001 C CNN
F 1 "GND" V 3805 2072 50  0000 R CNN
F 2 "" H 3800 2200 50  0001 C CNN
F 3 "" H 3800 2200 50  0001 C CNN
	1    3800 2200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0350
U 1 1 5B0D5D4F
P 3800 2100
F 0 "#PWR0350" H 3800 1850 50  0001 C CNN
F 1 "GND" V 3805 1972 50  0000 R CNN
F 2 "" H 3800 2100 50  0001 C CNN
F 3 "" H 3800 2100 50  0001 C CNN
	1    3800 2100
	0    1    1    0   
$EndComp
Text Notes 3450 3000 0    50   ~ 0
Set interrupt flag here asynchronously.\nIf we set it with the clock, then there\nis less time for the control logic to receive\na changed interrupt signal.
Text HLabel 3900 4950 0    50   Input ~ 0
~REG_OUT
$Comp
L 74xx:74HC245 U?
U 1 1 5B3B3A63
P 4400 4450
AR Path="/5AFD5CE2/5AFCCD08/5B3B3A63" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFD336A/5B3B3A63" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5B0AB8A7/5B3B3A63" Ref="U?"  Part="1" 
AR Path="/5B0FE4FF/5B3B3A63" Ref="U?"  Part="1" 
AR Path="/5B0FE82A/5B3B3A63" Ref="U?"  Part="1" 
AR Path="/5B0FEA60/5B3B3A63" Ref="U?"  Part="1" 
AR Path="/5B094E56/5B3B3A63" Ref="U7"  Part="1" 
F 0 "U7" H 4500 5150 50  0000 C CNN
F 1 "74HC245" H 4450 4150 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 4400 4450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 4400 4450 50  0001 C CNN
	1    4400 4450
	1    0    0    -1  
$EndComp
Text HLabel 4900 3950 2    50   Input ~ 0
BUS0
Text HLabel 4900 4050 2    50   Input ~ 0
BUS1
Text HLabel 4900 4150 2    50   Input ~ 0
BUS2
Text HLabel 4900 4250 2    50   Input ~ 0
BUS3
Text HLabel 4900 4350 2    50   Input ~ 0
BUS4
Text HLabel 4900 4450 2    50   Input ~ 0
BUS5
Text HLabel 4900 4550 2    50   Input ~ 0
BUS6
Text HLabel 4900 4650 2    50   Input ~ 0
BUS7
$Comp
L power:GND #PWR0231
U 1 1 5B3B3A7A
P 4400 5250
F 0 "#PWR0231" H 4400 5000 50  0001 C CNN
F 1 "GND" H 4405 5077 50  0000 C CNN
F 2 "" H 4400 5250 50  0001 C CNN
F 3 "" H 4400 5250 50  0001 C CNN
	1    4400 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C115
U 1 1 5B3B3A80
P 3350 4350
F 0 "C115" H 3442 4396 50  0000 L CNN
F 1 "0.1uF" H 3442 4305 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 3350 4350 50  0001 C CNN
F 3 "~" H 3350 4350 50  0001 C CNN
	1    3350 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 4250 3350 3650
Wire Wire Line
	3350 3650 4400 3650
Wire Wire Line
	4400 5250 3350 5250
Wire Wire Line
	3350 5250 3350 4450
Connection ~ 4400 5250
$Comp
L power:VCC #PWR0264
U 1 1 5B3B3A8C
P 4400 3650
F 0 "#PWR0264" H 4400 3500 50  0001 C CNN
F 1 "VCC" H 4417 3823 50  0000 C CNN
F 2 "" H 4400 3650 50  0001 C CNN
F 3 "" H 4400 3650 50  0001 C CNN
	1    4400 3650
	1    0    0    -1  
$EndComp
Connection ~ 4400 3650
$Comp
L power:VCC #PWR0411
U 1 1 5B3B3A93
P 3900 4850
F 0 "#PWR0411" H 3900 4700 50  0001 C CNN
F 1 "VCC" H 3917 5023 50  0000 C CNN
F 2 "" H 3900 4850 50  0001 C CNN
F 3 "" H 3900 4850 50  0001 C CNN
	1    3900 4850
	0    -1   -1   0   
$EndComp
Text HLabel 3900 3950 0    50   Input ~ 0
INTERRUPT_ENABLE_FLAG
Text HLabel 3900 4050 0    50   Input ~ 0
CARRY_FLAG
Text HLabel 3900 4150 0    50   Input ~ 0
ZERO_FLAG
$Comp
L power:GND #PWR0412
U 1 1 5B3B3D6D
P 3900 4250
F 0 "#PWR0412" H 3900 4000 50  0001 C CNN
F 1 "GND" H 3905 4077 50  0000 C CNN
F 2 "" H 3900 4250 50  0001 C CNN
F 3 "" H 3900 4250 50  0001 C CNN
	1    3900 4250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0413
U 1 1 5B3B3D96
P 3900 4350
F 0 "#PWR0413" H 3900 4100 50  0001 C CNN
F 1 "GND" H 3905 4177 50  0000 C CNN
F 2 "" H 3900 4350 50  0001 C CNN
F 3 "" H 3900 4350 50  0001 C CNN
	1    3900 4350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0451
U 1 1 5B3B3DB5
P 3900 4450
F 0 "#PWR0451" H 3900 4200 50  0001 C CNN
F 1 "GND" H 3905 4277 50  0000 C CNN
F 2 "" H 3900 4450 50  0001 C CNN
F 3 "" H 3900 4450 50  0001 C CNN
	1    3900 4450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0452
U 1 1 5B3B3DD4
P 3900 4550
F 0 "#PWR0452" H 3900 4300 50  0001 C CNN
F 1 "GND" H 3905 4377 50  0000 C CNN
F 2 "" H 3900 4550 50  0001 C CNN
F 3 "" H 3900 4550 50  0001 C CNN
	1    3900 4550
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0453
U 1 1 5B3B3DF3
P 3900 4650
F 0 "#PWR0453" H 3900 4400 50  0001 C CNN
F 1 "GND" H 3905 4477 50  0000 C CNN
F 2 "" H 3900 4650 50  0001 C CNN
F 3 "" H 3900 4650 50  0001 C CNN
	1    3900 4650
	0    1    1    0   
$EndComp
$EndSCHEMATC
