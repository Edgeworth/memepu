EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 3 20
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
L Memory_RAM:628128 U72
U 1 1 5B096C3C
P 4750 2050
F 0 "U72" H 4750 2100 50  0000 C CNN
F 1 "628128" H 4750 1950 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 4750 2050 50  0001 C CNN
F 3 "" H 4750 2050 50  0001 C CNN
	1    4750 2050
	1    0    0    -1  
$EndComp
Text HLabel 5450 1000 2    50   Input ~ 0
BUS0
Text HLabel 5450 1100 2    50   Input ~ 0
BUS1
Text HLabel 5450 1200 2    50   Input ~ 0
BUS2
Text HLabel 5450 1300 2    50   Input ~ 0
BUS3
Text HLabel 5450 1400 2    50   Input ~ 0
BUS4
Text HLabel 5450 1500 2    50   Input ~ 0
BUS5
Text HLabel 5450 1600 2    50   Input ~ 0
BUS6
Text HLabel 5450 1700 2    50   Input ~ 0
BUS7
Text HLabel 4050 3000 0    50   Input ~ 0
~MMU_OUT
Text HLabel 4050 3100 0    50   Input ~ 0
~MMU_IN
$Comp
L Device:C_Small C78
U 1 1 5B0991AB
P 1750 4050
F 0 "C78" H 1842 4096 50  0000 L CNN
F 1 "0.1uF" H 1842 4005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1750 4050 50  0001 C CNN
F 3 "~" H 1750 4050 50  0001 C CNN
	1    1750 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0294
U 1 1 5B099211
P 1750 3950
F 0 "#PWR0294" H 1750 3700 50  0001 C CNN
F 1 "GND" H 1755 3777 50  0000 C CNN
F 2 "" H 1750 3950 50  0001 C CNN
F 3 "" H 1750 3950 50  0001 C CNN
	1    1750 3950
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C79
U 1 1 5B09925F
P 4750 850
F 0 "C79" H 4842 896 50  0000 L CNN
F 1 "0.1uF" H 4842 805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4750 850 50  0001 C CNN
F 3 "~" H 4750 850 50  0001 C CNN
	1    4750 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0295
U 1 1 5B09940C
P 4750 750
F 0 "#PWR0295" H 4750 500 50  0001 C CNN
F 1 "GND" H 4755 577 50  0000 C CNN
F 2 "" H 4750 750 50  0001 C CNN
F 3 "" H 4750 750 50  0001 C CNN
	1    4750 750 
	-1   0    0    1   
$EndComp
$Comp
L power:VCC #PWR0296
U 1 1 5B09A2B5
P 1150 6250
F 0 "#PWR0296" H 1150 6100 50  0001 C CNN
F 1 "VCC" V 1168 6377 50  0000 L CNN
F 2 "" H 1150 6250 50  0001 C CNN
F 3 "" H 1150 6250 50  0001 C CNN
	1    1150 6250
	0    -1   -1   0   
$EndComp
Text HLabel 2350 4250 2    50   Input ~ 0
BUS0
Text HLabel 2350 4350 2    50   Input ~ 0
BUS1
Text HLabel 2350 4450 2    50   Input ~ 0
BUS2
Text HLabel 2350 4550 2    50   Input ~ 0
BUS3
Text HLabel 2350 4650 2    50   Input ~ 0
BUS4
Text HLabel 2350 4750 2    50   Input ~ 0
BUS5
Text HLabel 2350 4850 2    50   Input ~ 0
BUS6
Text HLabel 2350 4950 2    50   Input ~ 0
BUS7
$Comp
L Memory_RAM:628128 U74
U 1 1 5B09B082
P 7100 2050
F 0 "U74" H 7100 2100 50  0000 C CNN
F 1 "628128" H 7100 1950 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 7100 2050 50  0001 C CNN
F 3 "" H 7100 2050 50  0001 C CNN
	1    7100 2050
	1    0    0    -1  
$EndComp
Text HLabel 6400 3000 0    50   Input ~ 0
~MMU_OUT
Text HLabel 6400 3100 0    50   Input ~ 0
~MMU_IN
$Comp
L Device:C_Small C81
U 1 1 5B09B0AA
P 7100 850
F 0 "C81" H 7192 896 50  0000 L CNN
F 1 "0.1uF" H 7192 805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7100 850 50  0001 C CNN
F 3 "~" H 7100 850 50  0001 C CNN
	1    7100 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0298
U 1 1 5B09B0B1
P 7100 750
F 0 "#PWR0298" H 7100 500 50  0001 C CNN
F 1 "GND" H 7105 577 50  0000 C CNN
F 2 "" H 7100 750 50  0001 C CNN
F 3 "" H 7100 750 50  0001 C CNN
	1    7100 750 
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U73
U 1 1 5B09B347
P 4750 4700
F 0 "U73" H 4750 4750 50  0000 C CNN
F 1 "628128" H 4750 4600 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 4750 4700 50  0001 C CNN
F 3 "" H 4750 4700 50  0001 C CNN
	1    4750 4700
	1    0    0    -1  
$EndComp
Text HLabel 4050 5650 0    50   Input ~ 0
~MMU_OUT
Text HLabel 4050 5750 0    50   Input ~ 0
~MMU_IN
$Comp
L Device:C_Small C80
U 1 1 5B09B36F
P 4750 3500
F 0 "C80" H 4842 3546 50  0000 L CNN
F 1 "0.1uF" H 4842 3455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4750 3500 50  0001 C CNN
F 3 "~" H 4750 3500 50  0001 C CNN
	1    4750 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0304
U 1 1 5B09B376
P 4750 3400
F 0 "#PWR0304" H 4750 3150 50  0001 C CNN
F 1 "GND" H 4755 3227 50  0000 C CNN
F 2 "" H 4750 3400 50  0001 C CNN
F 3 "" H 4750 3400 50  0001 C CNN
	1    4750 3400
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U75
U 1 1 5B09B37C
P 7100 4700
F 0 "U75" H 7100 4750 50  0000 C CNN
F 1 "628128" H 7100 4600 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 7100 4700 50  0001 C CNN
F 3 "" H 7100 4700 50  0001 C CNN
	1    7100 4700
	1    0    0    -1  
$EndComp
Text HLabel 6400 5650 0    50   Input ~ 0
~MMU_OUT
Text HLabel 6400 5750 0    50   Input ~ 0
~MMU_IN
$Comp
L Device:C_Small C82
U 1 1 5B09B3A4
P 7100 3500
F 0 "C82" H 7192 3546 50  0000 L CNN
F 1 "0.1uF" H 7192 3455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7100 3500 50  0001 C CNN
F 3 "~" H 7100 3500 50  0001 C CNN
	1    7100 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0306
U 1 1 5B09B3AB
P 7100 3400
F 0 "#PWR0306" H 7100 3150 50  0001 C CNN
F 1 "GND" H 7105 3227 50  0000 C CNN
F 2 "" H 7100 3400 50  0001 C CNN
F 3 "" H 7100 3400 50  0001 C CNN
	1    7100 3400
	-1   0    0    1   
$EndComp
$Comp
L Memory_Flash:SST39SF040 U?
U 1 1 5B553ACE
P 1750 5450
AR Path="/5B0C6DCD/5B553ACE" Ref="U?"  Part="1" 
AR Path="/5B09632F/5B553ACE" Ref="U71"  Part="1" 
F 0 "U71" H 1750 5550 50  0000 C CNN
F 1 "SST39SF040" H 1800 5400 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 1750 5750 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 1750 5750 50  0001 C CNN
	1    1750 5450
	1    0    0    -1  
$EndComp
Text Notes 800  3950 0    50   ~ 0
Boot EEPROM
Text HLabel 950  750  0    50   Input ~ 0
BUS0
Text HLabel 950  850  0    50   Input ~ 0
BUS1
Text HLabel 950  950  0    50   Input ~ 0
BUS2
Text HLabel 950  1050 0    50   Input ~ 0
BUS3
Text HLabel 950  1150 0    50   Input ~ 0
BUS4
Text HLabel 950  1250 0    50   Input ~ 0
BUS5
Text HLabel 950  1350 0    50   Input ~ 0
BUS6
Text HLabel 950  1450 0    50   Input ~ 0
BUS7
Text HLabel 950  3300 0    50   Input ~ 0
REG_ADDR_IN
Text HLabel 950  1550 0    50   Input ~ 0
BUS8
Text HLabel 950  1650 0    50   Input ~ 0
BUS9
Text HLabel 950  1750 0    50   Input ~ 0
BUS10
Text HLabel 950  1850 0    50   Input ~ 0
BUS11
Text HLabel 950  1950 0    50   Input ~ 0
BUS12
Text HLabel 950  2050 0    50   Input ~ 0
BUS13
Text HLabel 950  2150 0    50   Input ~ 0
BUS14
Text HLabel 950  2250 0    50   Input ~ 0
BUS15
Text HLabel 950  2350 0    50   Input ~ 0
BUS16
Text HLabel 950  2450 0    50   Input ~ 0
BUS17
Text HLabel 950  2550 0    50   Input ~ 0
BUS18
Text HLabel 950  2650 0    50   Input ~ 0
BUS19
Text HLabel 950  2750 0    50   Input ~ 0
BUS20
Text HLabel 950  2850 0    50   Input ~ 0
BUS21
Text HLabel 950  2950 0    50   Input ~ 0
BUS22
Text HLabel 950  3050 0    50   Input ~ 0
BUS23
Text HLabel 1500 750  2    50   Input ~ 0
ADDR0
Text HLabel 1500 850  2    50   Input ~ 0
ADDR1
Text HLabel 1500 950  2    50   Input ~ 0
ADDR2
Text HLabel 1500 1050 2    50   Input ~ 0
ADDR3
Text HLabel 1500 1150 2    50   Input ~ 0
ADDR4
Text HLabel 1500 1250 2    50   Input ~ 0
ADDR5
Text HLabel 1500 1350 2    50   Input ~ 0
ADDR6
Text HLabel 1500 1450 2    50   Input ~ 0
ADDR7
Text HLabel 1500 1550 2    50   Input ~ 0
ADDR8
Text HLabel 1500 1650 2    50   Input ~ 0
ADDR9
Text HLabel 1500 1750 2    50   Input ~ 0
ADDR10
Text HLabel 1500 1850 2    50   Input ~ 0
ADDR11
Text HLabel 1500 1950 2    50   Input ~ 0
ADDR12
Text HLabel 1500 2050 2    50   Input ~ 0
ADDR13
Text HLabel 1500 2150 2    50   Input ~ 0
ADDR14
Text HLabel 1500 2250 2    50   Input ~ 0
ADDR15
Text HLabel 1500 2350 2    50   Input ~ 0
ADDR16
Text HLabel 1500 2450 2    50   Input ~ 0
ADDR17
Text HLabel 1500 2550 2    50   Input ~ 0
ADDR18
Text HLabel 1500 2650 2    50   Input ~ 0
ADDR19
Text HLabel 1500 2750 2    50   Input ~ 0
ADDR20
Text HLabel 1500 2850 2    50   Input ~ 0
ADDR21
Text HLabel 1500 2950 2    50   Input ~ 0
ADDR22
Text HLabel 1500 3050 2    50   Input ~ 0
ADDR23
Text HLabel 5450 3650 2    50   Input ~ 0
BUS8
Text HLabel 5450 3750 2    50   Input ~ 0
BUS9
Text HLabel 5450 3850 2    50   Input ~ 0
BUS10
Text HLabel 5450 3950 2    50   Input ~ 0
BUS11
Text HLabel 5450 4050 2    50   Input ~ 0
BUS12
Text HLabel 5450 4150 2    50   Input ~ 0
BUS13
Text HLabel 5450 4250 2    50   Input ~ 0
BUS14
Text HLabel 5450 4350 2    50   Input ~ 0
BUS15
Text HLabel 7800 1000 2    50   Input ~ 0
BUS16
Text HLabel 7800 1100 2    50   Input ~ 0
BUS17
Text HLabel 7800 1200 2    50   Input ~ 0
BUS18
Text HLabel 7800 1300 2    50   Input ~ 0
BUS19
Text HLabel 7800 1400 2    50   Input ~ 0
BUS20
Text HLabel 7800 1500 2    50   Input ~ 0
BUS21
Text HLabel 7800 1600 2    50   Input ~ 0
BUS22
Text HLabel 7800 1700 2    50   Input ~ 0
BUS23
Text HLabel 7800 3650 2    50   Input ~ 0
BUS24
Text HLabel 7800 3750 2    50   Input ~ 0
BUS25
Text HLabel 7800 3850 2    50   Input ~ 0
BUS26
Text HLabel 7800 3950 2    50   Input ~ 0
BUS27
Text HLabel 7800 4050 2    50   Input ~ 0
BUS28
Text HLabel 7800 4150 2    50   Input ~ 0
BUS29
Text HLabel 7800 4250 2    50   Input ~ 0
BUS30
Text HLabel 7800 4350 2    50   Input ~ 0
BUS31
Text HLabel 1150 6550 0    50   Input ~ 0
~EEPROM_OUT
$Comp
L power:GND #PWR0110
U 1 1 5B9F8B45
P 1150 6450
F 0 "#PWR0110" H 1150 6200 50  0001 C CNN
F 1 "GND" V 1155 6322 50  0000 R CNN
F 2 "" H 1150 6450 50  0001 C CNN
F 3 "" H 1150 6450 50  0001 C CNN
	1    1150 6450
	0    1    1    0   
$EndComp
Text HLabel 4050 1000 0    50   Input ~ 0
ADDR2
Text HLabel 4050 1100 0    50   Input ~ 0
ADDR3
Text HLabel 4050 1200 0    50   Input ~ 0
ADDR4
Text HLabel 4050 1300 0    50   Input ~ 0
ADDR5
Text HLabel 4050 1400 0    50   Input ~ 0
ADDR6
Text HLabel 4050 1500 0    50   Input ~ 0
ADDR7
Text HLabel 4050 1600 0    50   Input ~ 0
ADDR8
Text HLabel 4050 1700 0    50   Input ~ 0
ADDR9
Text HLabel 4050 1800 0    50   Input ~ 0
ADDR10
Text HLabel 4050 1900 0    50   Input ~ 0
ADDR11
Text HLabel 4050 2000 0    50   Input ~ 0
ADDR12
Text HLabel 4050 2100 0    50   Input ~ 0
ADDR13
Text HLabel 4050 2200 0    50   Input ~ 0
ADDR14
Text HLabel 4050 2300 0    50   Input ~ 0
ADDR15
Text HLabel 4050 2400 0    50   Input ~ 0
ADDR16
Text HLabel 4050 2500 0    50   Input ~ 0
ADDR17
Text HLabel 4050 2600 0    50   Input ~ 0
ADDR18
Text HLabel 6400 1000 0    50   Input ~ 0
ADDR2
Text HLabel 6400 1100 0    50   Input ~ 0
ADDR3
Text HLabel 6400 1200 0    50   Input ~ 0
ADDR4
Text HLabel 6400 1300 0    50   Input ~ 0
ADDR5
Text HLabel 6400 1400 0    50   Input ~ 0
ADDR6
Text HLabel 6400 1500 0    50   Input ~ 0
ADDR7
Text HLabel 6400 1600 0    50   Input ~ 0
ADDR8
Text HLabel 6400 1700 0    50   Input ~ 0
ADDR9
Text HLabel 6400 1800 0    50   Input ~ 0
ADDR10
Text HLabel 6400 1900 0    50   Input ~ 0
ADDR11
Text HLabel 6400 2000 0    50   Input ~ 0
ADDR12
Text HLabel 6400 2100 0    50   Input ~ 0
ADDR13
Text HLabel 6400 2200 0    50   Input ~ 0
ADDR14
Text HLabel 6400 2300 0    50   Input ~ 0
ADDR15
Text HLabel 6400 2400 0    50   Input ~ 0
ADDR16
Text HLabel 6400 2500 0    50   Input ~ 0
ADDR17
Text HLabel 6400 2600 0    50   Input ~ 0
ADDR18
Text HLabel 4050 3650 0    50   Input ~ 0
ADDR2
Text HLabel 4050 3750 0    50   Input ~ 0
ADDR3
Text HLabel 4050 3850 0    50   Input ~ 0
ADDR4
Text HLabel 4050 3950 0    50   Input ~ 0
ADDR5
Text HLabel 4050 4050 0    50   Input ~ 0
ADDR6
Text HLabel 4050 4150 0    50   Input ~ 0
ADDR7
Text HLabel 4050 4250 0    50   Input ~ 0
ADDR8
Text HLabel 4050 4350 0    50   Input ~ 0
ADDR9
Text HLabel 4050 4450 0    50   Input ~ 0
ADDR10
Text HLabel 4050 4550 0    50   Input ~ 0
ADDR11
Text HLabel 4050 4650 0    50   Input ~ 0
ADDR12
Text HLabel 4050 4750 0    50   Input ~ 0
ADDR13
Text HLabel 4050 4850 0    50   Input ~ 0
ADDR14
Text HLabel 4050 4950 0    50   Input ~ 0
ADDR15
Text HLabel 4050 5050 0    50   Input ~ 0
ADDR16
Text HLabel 4050 5150 0    50   Input ~ 0
ADDR17
Text HLabel 4050 5250 0    50   Input ~ 0
ADDR18
Text HLabel 6400 3650 0    50   Input ~ 0
ADDR2
Text HLabel 6400 3750 0    50   Input ~ 0
ADDR3
Text HLabel 6400 3850 0    50   Input ~ 0
ADDR4
Text HLabel 6400 3950 0    50   Input ~ 0
ADDR5
Text HLabel 6400 4050 0    50   Input ~ 0
ADDR6
Text HLabel 6400 4150 0    50   Input ~ 0
ADDR7
Text HLabel 6400 4250 0    50   Input ~ 0
ADDR8
Text HLabel 6400 4350 0    50   Input ~ 0
ADDR9
Text HLabel 6400 4450 0    50   Input ~ 0
ADDR10
Text HLabel 6400 4550 0    50   Input ~ 0
ADDR11
Text HLabel 6400 4650 0    50   Input ~ 0
ADDR12
Text HLabel 6400 4750 0    50   Input ~ 0
ADDR13
Text HLabel 6400 4850 0    50   Input ~ 0
ADDR14
Text HLabel 6400 4950 0    50   Input ~ 0
ADDR15
Text HLabel 6400 5050 0    50   Input ~ 0
ADDR16
Text HLabel 6400 5150 0    50   Input ~ 0
ADDR17
Text HLabel 6400 5250 0    50   Input ~ 0
ADDR18
Text HLabel 4050 2800 0    50   Input ~ 0
ADDR22
Text HLabel 4050 2900 0    50   Input ~ 0
ADDR23
Text HLabel 6400 2800 0    50   Input ~ 0
ADDR22
Text HLabel 6400 2900 0    50   Input ~ 0
ADDR23
Text HLabel 6400 5450 0    50   Input ~ 0
ADDR22
Text HLabel 6400 5550 0    50   Input ~ 0
ADDR23
Text HLabel 4050 5450 0    50   Input ~ 0
ADDR22
Text HLabel 4050 5550 0    50   Input ~ 0
ADDR23
$Sheet
S 950  650  550  2750
U 5B9EE1D1
F0 "ADDR" 50
F1 "address_register.sch" 50
F2 "REG_IN" I L 950 3300 50 
F3 "I0" I L 950 750 50 
F4 "I1" I L 950 850 50 
F5 "I2" I L 950 950 50 
F6 "I3" I L 950 1050 50 
F7 "I4" I L 950 1150 50 
F8 "I5" I L 950 1250 50 
F9 "I6" I L 950 1350 50 
F10 "I7" I L 950 1450 50 
F11 "~REG_OUT" I R 1500 3200 50 
F12 "O0" I R 1500 750 50 
F13 "O1" I R 1500 850 50 
F14 "O2" I R 1500 950 50 
F15 "O3" I R 1500 1050 50 
F16 "O4" I R 1500 1150 50 
F17 "O5" I R 1500 1250 50 
F18 "O6" I R 1500 1350 50 
F19 "O7" I R 1500 1450 50 
F20 "I8" I L 950 1550 50 
F21 "I9" I L 950 1650 50 
F22 "I10" I L 950 1750 50 
F23 "I11" I L 950 1850 50 
F24 "I12" I L 950 1950 50 
F25 "I13" I L 950 2050 50 
F26 "I14" I L 950 2150 50 
F27 "I15" I L 950 2250 50 
F28 "I16" I L 950 2350 50 
F29 "I17" I L 950 2450 50 
F30 "I18" I L 950 2550 50 
F31 "I19" I L 950 2650 50 
F32 "I20" I L 950 2750 50 
F33 "I21" I L 950 2850 50 
F34 "I22" I L 950 2950 50 
F35 "I23" I L 950 3050 50 
F36 "O8" I R 1500 1550 50 
F37 "O9" I R 1500 1650 50 
F38 "O10" I R 1500 1750 50 
F39 "O11" I R 1500 1850 50 
F40 "O12" I R 1500 1950 50 
F41 "O13" I R 1500 2050 50 
F42 "O14" I R 1500 2150 50 
F43 "O15" I R 1500 2250 50 
F44 "O16" I R 1500 2350 50 
F45 "O17" I R 1500 2450 50 
F46 "O18" I R 1500 2550 50 
F47 "O19" I R 1500 2650 50 
F48 "O20" I R 1500 2750 50 
F49 "O21" I R 1500 2850 50 
F50 "O22" I R 1500 2950 50 
F51 "O23" I R 1500 3050 50 
$EndSheet
$Comp
L power:GND #PWR0111
U 1 1 5BA071D0
P 1500 3200
F 0 "#PWR0111" H 1500 2950 50  0001 C CNN
F 1 "GND" V 1505 3072 50  0000 R CNN
F 2 "" H 1500 3200 50  0001 C CNN
F 3 "" H 1500 3200 50  0001 C CNN
	1    1500 3200
	0    -1   -1   0   
$EndComp
Text HLabel 1150 4250 0    50   Input ~ 0
ADDR0
Text HLabel 1150 4350 0    50   Input ~ 0
ADDR1
Text HLabel 1150 4450 0    50   Input ~ 0
ADDR2
Text HLabel 1150 4550 0    50   Input ~ 0
ADDR3
Text HLabel 1150 4650 0    50   Input ~ 0
ADDR4
Text HLabel 1150 4750 0    50   Input ~ 0
ADDR5
Text HLabel 1150 4850 0    50   Input ~ 0
ADDR6
Text HLabel 1150 4950 0    50   Input ~ 0
ADDR7
Text HLabel 1150 5050 0    50   Input ~ 0
ADDR8
Text HLabel 1150 5150 0    50   Input ~ 0
ADDR9
Text HLabel 1150 5250 0    50   Input ~ 0
ADDR10
Text HLabel 1150 5350 0    50   Input ~ 0
ADDR11
Text HLabel 1150 5450 0    50   Input ~ 0
ADDR12
Text HLabel 1150 5550 0    50   Input ~ 0
ADDR13
Text HLabel 1150 5650 0    50   Input ~ 0
ADDR14
Text HLabel 1150 5750 0    50   Input ~ 0
ADDR15
Text HLabel 1150 5850 0    50   Input ~ 0
ADDR16
Text HLabel 1150 5950 0    50   Input ~ 0
ADDR17
Text HLabel 1150 6050 0    50   Input ~ 0
ADDR18
$EndSCHEMATC
