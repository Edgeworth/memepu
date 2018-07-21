EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 17 35
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 5600 950  550  1200
U 5B0966DC
F0 "MMU0" 50
F1 "register.sch" 50
F2 "REG_IN" I L 5600 2050 50 
F3 "I0" I L 5600 1050 50 
F4 "I1" I L 5600 1150 50 
F5 "I2" I L 5600 1250 50 
F6 "I3" I L 5600 1350 50 
F7 "I4" I L 5600 1450 50 
F8 "I5" I L 5600 1550 50 
F9 "I6" I L 5600 1650 50 
F10 "I7" I L 5600 1750 50 
F11 "~REG_OUT" I L 5600 1950 50 
F12 "O0" I R 6150 1050 50 
F13 "O1" I R 6150 1150 50 
F14 "O2" I R 6150 1250 50 
F15 "O3" I R 6150 1350 50 
F16 "O4" I R 6150 1450 50 
F17 "O5" I R 6150 1550 50 
F18 "O6" I R 6150 1650 50 
F19 "O7" I R 6150 1750 50 
$EndSheet
$Sheet
S 6750 950  550  1200
U 5B096830
F0 "MMU1" 50
F1 "register.sch" 50
F2 "REG_IN" I L 6750 2050 50 
F3 "I0" I L 6750 1050 50 
F4 "I1" I L 6750 1150 50 
F5 "I2" I L 6750 1250 50 
F6 "I3" I L 6750 1350 50 
F7 "I4" I L 6750 1450 50 
F8 "I5" I L 6750 1550 50 
F9 "I6" I L 6750 1650 50 
F10 "I7" I L 6750 1750 50 
F11 "~REG_OUT" I L 6750 1950 50 
F12 "O0" I R 7300 1050 50 
F13 "O1" I R 7300 1150 50 
F14 "O2" I R 7300 1250 50 
F15 "O3" I R 7300 1350 50 
F16 "O4" I R 7300 1450 50 
F17 "O5" I R 7300 1550 50 
F18 "O6" I R 7300 1650 50 
F19 "O7" I R 7300 1750 50 
$EndSheet
$Sheet
S 8000 950  550  1200
U 5B096845
F0 "MMU2" 50
F1 "register.sch" 50
F2 "REG_IN" I L 8000 2050 50 
F3 "I0" I L 8000 1050 50 
F4 "I1" I L 8000 1150 50 
F5 "I2" I L 8000 1250 50 
F6 "I3" I L 8000 1350 50 
F7 "I4" I L 8000 1450 50 
F8 "I5" I L 8000 1550 50 
F9 "I6" I L 8000 1650 50 
F10 "I7" I L 8000 1750 50 
F11 "~REG_OUT" I L 8000 1950 50 
F12 "O0" I R 8550 1050 50 
F13 "O1" I R 8550 1150 50 
F14 "O2" I R 8550 1250 50 
F15 "O3" I R 8550 1350 50 
F16 "O4" I R 8550 1450 50 
F17 "O5" I R 8550 1550 50 
F18 "O6" I R 8550 1650 50 
F19 "O7" I R 8550 1750 50 
$EndSheet
$Comp
L Memory_RAM:628128 U72
U 1 1 5B096C3C
P 9900 2100
F 0 "U72" H 9900 2150 50  0000 C CNN
F 1 "628128" H 9900 2000 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 9900 2100 50  0001 C CNN
F 3 "" H 9900 2100 50  0001 C CNN
	1    9900 2100
	1    0    0    -1  
$EndComp
Text Label 6150 1050 0    50   ~ 0
M0
Text Label 6150 1150 0    50   ~ 0
M1
Text Label 6150 1250 0    50   ~ 0
M2
Text Label 6150 1350 0    50   ~ 0
M3
Text Label 6150 1450 0    50   ~ 0
M4
Text Label 6150 1550 0    50   ~ 0
M5
Text Label 6150 1650 0    50   ~ 0
M6
Text Label 6150 1750 0    50   ~ 0
M7
Text Label 7300 1050 0    50   ~ 0
M8
Text Label 7300 1150 0    50   ~ 0
M9
Text Label 7300 1250 0    50   ~ 0
M10
Text Label 7300 1350 0    50   ~ 0
M11
Text Label 7300 1450 0    50   ~ 0
M12
Text Label 7300 1550 0    50   ~ 0
M13
Text Label 7300 1650 0    50   ~ 0
M14
Text Label 7300 1750 0    50   ~ 0
M15
Text Label 8550 1050 0    50   ~ 0
M16
Text Label 8550 1150 0    50   ~ 0
M17
Text Label 8550 1250 0    50   ~ 0
M18
Text Label 8550 1350 0    50   ~ 0
M19
Text Label 8550 1450 0    50   ~ 0
M20
Text Label 8550 1550 0    50   ~ 0
M21
Text Label 8550 1650 0    50   ~ 0
M22
Text Label 8550 1750 0    50   ~ 0
M23
$Comp
L power:VCC #PWR0289
U 1 1 5B097BEB
P 6000 3400
F 0 "#PWR0289" H 6000 3250 50  0001 C CNN
F 1 "VCC" H 6017 3573 50  0000 C CNN
F 2 "" H 6000 3400 50  0001 C CNN
F 3 "" H 6000 3400 50  0001 C CNN
	1    6000 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0290
U 1 1 5B097C44
P 6000 5500
F 0 "#PWR0290" H 6000 5250 50  0001 C CNN
F 1 "GND" H 6005 5327 50  0000 C CNN
F 2 "" H 6000 5500 50  0001 C CNN
F 3 "" H 6000 5500 50  0001 C CNN
	1    6000 5500
	1    0    0    -1  
$EndComp
Text Label 9200 1050 2    50   ~ 0
M0
Text Label 9200 1150 2    50   ~ 0
M1
Text Label 9200 1250 2    50   ~ 0
M2
Text Label 9200 1350 2    50   ~ 0
M3
Text Label 9200 1450 2    50   ~ 0
M4
Text Label 9200 1550 2    50   ~ 0
M5
Text Label 9200 1650 2    50   ~ 0
M6
Text Label 9200 1750 2    50   ~ 0
M7
Text Label 9200 1850 2    50   ~ 0
M8
Text Label 9200 1950 2    50   ~ 0
M9
Text Label 9200 2050 2    50   ~ 0
M10
Text Label 9200 2150 2    50   ~ 0
M11
Text Label 9200 2250 2    50   ~ 0
M12
Text Label 9200 2350 2    50   ~ 0
M13
Text Label 9200 2450 2    50   ~ 0
M14
Text Label 9200 2550 2    50   ~ 0
M15
Text Label 9200 2650 2    50   ~ 0
M16
Text HLabel 10600 1050 2    50   Input ~ 0
BUS0
Text HLabel 10600 1150 2    50   Input ~ 0
BUS1
Text HLabel 10600 1250 2    50   Input ~ 0
BUS2
Text HLabel 10600 1350 2    50   Input ~ 0
BUS3
Text HLabel 10600 1450 2    50   Input ~ 0
BUS4
Text HLabel 10600 1550 2    50   Input ~ 0
BUS5
Text HLabel 10600 1650 2    50   Input ~ 0
BUS6
Text HLabel 10600 1750 2    50   Input ~ 0
BUS7
Text HLabel 9200 3050 0    50   Input ~ 0
~MMU_OUT
Text HLabel 9200 3150 0    50   Input ~ 0
~MMU_IN
$Comp
L power:GND #PWR0292
U 1 1 5B0985CB
P 5500 4200
F 0 "#PWR0292" H 5500 3950 50  0001 C CNN
F 1 "GND" V 5505 4072 50  0000 R CNN
F 2 "" H 5500 4200 50  0001 C CNN
F 3 "" H 5500 4200 50  0001 C CNN
	1    5500 4200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0293
U 1 1 5B0985DC
P 5500 4300
F 0 "#PWR0293" H 5500 4050 50  0001 C CNN
F 1 "GND" V 5505 4172 50  0000 R CNN
F 2 "" H 5500 4300 50  0001 C CNN
F 3 "" H 5500 4300 50  0001 C CNN
	1    5500 4300
	0    1    1    0   
$EndComp
$Comp
L Memory_Flash:SST39SF040 U71
U 1 1 5B098A2E
P 7900 4800
F 0 "U71" H 7900 5200 50  0000 C CNN
F 1 "SST39SF040" H 8000 4950 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 7900 5100 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 7900 5100 50  0001 C CNN
	1    7900 4800
	1    0    0    -1  
$EndComp
Text Label 5500 3700 2    50   ~ 0
M17
Text Label 5500 3800 2    50   ~ 0
M18
Text Label 5500 3900 2    50   ~ 0
M19
$Comp
L Device:C_Small C78
U 1 1 5B0991AB
P 7900 3400
F 0 "C78" H 7992 3446 50  0000 L CNN
F 1 "0.1uF" H 7992 3355 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 7900 3400 50  0001 C CNN
F 3 "~" H 7900 3400 50  0001 C CNN
	1    7900 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0294
U 1 1 5B099211
P 7900 3300
F 0 "#PWR0294" H 7900 3050 50  0001 C CNN
F 1 "GND" H 7905 3127 50  0000 C CNN
F 2 "" H 7900 3300 50  0001 C CNN
F 3 "" H 7900 3300 50  0001 C CNN
	1    7900 3300
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C79
U 1 1 5B09925F
P 9900 900
F 0 "C79" H 9992 946 50  0000 L CNN
F 1 "0.1uF" H 9992 855 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 9900 900 50  0001 C CNN
F 3 "~" H 9900 900 50  0001 C CNN
	1    9900 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0295
U 1 1 5B09940C
P 9900 800
F 0 "#PWR0295" H 9900 550 50  0001 C CNN
F 1 "GND" H 9905 627 50  0000 C CNN
F 2 "" H 9900 800 50  0001 C CNN
F 3 "" H 9900 800 50  0001 C CNN
	1    9900 800 
	-1   0    0    1   
$EndComp
$Comp
L 74xx:74LS154 U70
U 1 1 5B099625
P 6000 4400
F 0 "U70" H 6000 4450 50  0000 C CNN
F 1 "74LS154" H 6000 4200 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W7.62mm_Socket" H 6000 4400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS154" H 6000 4400 50  0001 C CNN
	1    6000 4400
	1    0    0    -1  
$EndComp
Text Label 5500 4000 2    50   ~ 0
M20
NoConn ~ 6500 4500
NoConn ~ 6500 4600
NoConn ~ 6500 4700
NoConn ~ 6500 4800
NoConn ~ 6500 4900
NoConn ~ 6500 5000
NoConn ~ 6500 5100
NoConn ~ 6500 5200
Text Label 7300 5900 2    50   ~ 0
M20
Text Label 7300 3600 2    50   ~ 0
M0
Text Label 7300 3700 2    50   ~ 0
M1
Text Label 7300 3800 2    50   ~ 0
M2
Text Label 7300 3900 2    50   ~ 0
M3
Text Label 7300 4000 2    50   ~ 0
M4
Text Label 7300 4100 2    50   ~ 0
M5
Text Label 7300 4200 2    50   ~ 0
M6
Text Label 7300 4300 2    50   ~ 0
M7
Text Label 7300 4400 2    50   ~ 0
M8
Text Label 7300 4500 2    50   ~ 0
M9
Text Label 7300 4600 2    50   ~ 0
M10
Text Label 7300 4700 2    50   ~ 0
M11
Text Label 7300 4800 2    50   ~ 0
M12
Text Label 7300 4900 2    50   ~ 0
M13
Text Label 7300 5000 2    50   ~ 0
M14
Text Label 7300 5100 2    50   ~ 0
M15
Text Label 7300 5200 2    50   ~ 0
M16
Text Label 7300 5300 2    50   ~ 0
M17
Text Label 7300 5400 2    50   ~ 0
M18
$Comp
L power:VCC #PWR0296
U 1 1 5B09A2B5
P 7300 5600
F 0 "#PWR0296" H 7300 5450 50  0001 C CNN
F 1 "VCC" V 7318 5727 50  0000 L CNN
F 2 "" H 7300 5600 50  0001 C CNN
F 3 "" H 7300 5600 50  0001 C CNN
	1    7300 5600
	0    -1   -1   0   
$EndComp
Text HLabel 8500 3600 2    50   Input ~ 0
BUS0
Text HLabel 8500 3700 2    50   Input ~ 0
BUS1
Text HLabel 8500 3800 2    50   Input ~ 0
BUS2
Text HLabel 8500 3900 2    50   Input ~ 0
BUS3
Text HLabel 8500 4000 2    50   Input ~ 0
BUS4
Text HLabel 8500 4100 2    50   Input ~ 0
BUS5
Text HLabel 8500 4200 2    50   Input ~ 0
BUS6
Text HLabel 8500 4300 2    50   Input ~ 0
BUS7
Text HLabel 7300 5800 0    50   Input ~ 0
~MMU_OUT
$Comp
L Memory_RAM:628128 U74
U 1 1 5B09B082
P 11750 2100
F 0 "U74" H 11750 2150 50  0000 C CNN
F 1 "628128" H 11750 2000 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 11750 2100 50  0001 C CNN
F 3 "" H 11750 2100 50  0001 C CNN
	1    11750 2100
	1    0    0    -1  
$EndComp
Text Label 11050 1050 2    50   ~ 0
M0
Text Label 11050 1150 2    50   ~ 0
M1
Text Label 11050 1250 2    50   ~ 0
M2
Text Label 11050 1350 2    50   ~ 0
M3
Text Label 11050 1450 2    50   ~ 0
M4
Text Label 11050 1550 2    50   ~ 0
M5
Text Label 11050 1650 2    50   ~ 0
M6
Text Label 11050 1750 2    50   ~ 0
M7
Text Label 11050 1850 2    50   ~ 0
M8
Text Label 11050 1950 2    50   ~ 0
M9
Text Label 11050 2050 2    50   ~ 0
M10
Text Label 11050 2150 2    50   ~ 0
M11
Text Label 11050 2250 2    50   ~ 0
M12
Text Label 11050 2350 2    50   ~ 0
M13
Text Label 11050 2450 2    50   ~ 0
M14
Text Label 11050 2550 2    50   ~ 0
M15
Text Label 11050 2650 2    50   ~ 0
M16
Text HLabel 12450 1050 2    50   Input ~ 0
BUS0
Text HLabel 12450 1150 2    50   Input ~ 0
BUS1
Text HLabel 12450 1250 2    50   Input ~ 0
BUS2
Text HLabel 12450 1350 2    50   Input ~ 0
BUS3
Text HLabel 12450 1450 2    50   Input ~ 0
BUS4
Text HLabel 12450 1550 2    50   Input ~ 0
BUS5
Text HLabel 12450 1650 2    50   Input ~ 0
BUS6
Text HLabel 12450 1750 2    50   Input ~ 0
BUS7
Text HLabel 11050 3050 0    50   Input ~ 0
~MMU_OUT
Text HLabel 11050 3150 0    50   Input ~ 0
~MMU_IN
$Comp
L Device:C_Small C81
U 1 1 5B09B0AA
P 11750 900
F 0 "C81" H 11842 946 50  0000 L CNN
F 1 "0.1uF" H 11842 855 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 11750 900 50  0001 C CNN
F 3 "~" H 11750 900 50  0001 C CNN
	1    11750 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0298
U 1 1 5B09B0B1
P 11750 800
F 0 "#PWR0298" H 11750 550 50  0001 C CNN
F 1 "GND" H 11755 627 50  0000 C CNN
F 2 "" H 11750 800 50  0001 C CNN
F 3 "" H 11750 800 50  0001 C CNN
	1    11750 800 
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U76
U 1 1 5B09B16B
P 13650 2150
F 0 "U76" H 13650 2200 50  0000 C CNN
F 1 "628128" H 13650 2050 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 13650 2150 50  0001 C CNN
F 3 "" H 13650 2150 50  0001 C CNN
	1    13650 2150
	1    0    0    -1  
$EndComp
Text Label 12950 1100 2    50   ~ 0
M0
Text Label 12950 1200 2    50   ~ 0
M1
Text Label 12950 1300 2    50   ~ 0
M2
Text Label 12950 1400 2    50   ~ 0
M3
Text Label 12950 1500 2    50   ~ 0
M4
Text Label 12950 1600 2    50   ~ 0
M5
Text Label 12950 1700 2    50   ~ 0
M6
Text Label 12950 1800 2    50   ~ 0
M7
Text Label 12950 1900 2    50   ~ 0
M8
Text Label 12950 2000 2    50   ~ 0
M9
Text Label 12950 2100 2    50   ~ 0
M10
Text Label 12950 2200 2    50   ~ 0
M11
Text Label 12950 2300 2    50   ~ 0
M12
Text Label 12950 2400 2    50   ~ 0
M13
Text Label 12950 2500 2    50   ~ 0
M14
Text Label 12950 2600 2    50   ~ 0
M15
Text Label 12950 2700 2    50   ~ 0
M16
Text HLabel 14350 1100 2    50   Input ~ 0
BUS0
Text HLabel 14350 1200 2    50   Input ~ 0
BUS1
Text HLabel 14350 1300 2    50   Input ~ 0
BUS2
Text HLabel 14350 1400 2    50   Input ~ 0
BUS3
Text HLabel 14350 1500 2    50   Input ~ 0
BUS4
Text HLabel 14350 1600 2    50   Input ~ 0
BUS5
Text HLabel 14350 1700 2    50   Input ~ 0
BUS6
Text HLabel 14350 1800 2    50   Input ~ 0
BUS7
Text HLabel 12950 3100 0    50   Input ~ 0
~MMU_OUT
Text HLabel 12950 3200 0    50   Input ~ 0
~MMU_IN
$Comp
L Device:C_Small C83
U 1 1 5B09B193
P 13650 950
F 0 "C83" H 13742 996 50  0000 L CNN
F 1 "0.1uF" H 13742 905 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 13650 950 50  0001 C CNN
F 3 "~" H 13650 950 50  0001 C CNN
	1    13650 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0300
U 1 1 5B09B19A
P 13650 850
F 0 "#PWR0300" H 13650 600 50  0001 C CNN
F 1 "GND" H 13655 677 50  0000 C CNN
F 2 "" H 13650 850 50  0001 C CNN
F 3 "" H 13650 850 50  0001 C CNN
	1    13650 850 
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U78
U 1 1 5B09B1A0
P 15500 2150
F 0 "U78" H 15500 2200 50  0000 C CNN
F 1 "628128" H 15500 2050 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 15500 2150 50  0001 C CNN
F 3 "" H 15500 2150 50  0001 C CNN
	1    15500 2150
	1    0    0    -1  
$EndComp
Text Label 14800 1100 2    50   ~ 0
M0
Text Label 14800 1200 2    50   ~ 0
M1
Text Label 14800 1300 2    50   ~ 0
M2
Text Label 14800 1400 2    50   ~ 0
M3
Text Label 14800 1500 2    50   ~ 0
M4
Text Label 14800 1600 2    50   ~ 0
M5
Text Label 14800 1700 2    50   ~ 0
M6
Text Label 14800 1800 2    50   ~ 0
M7
Text Label 14800 1900 2    50   ~ 0
M8
Text Label 14800 2000 2    50   ~ 0
M9
Text Label 14800 2100 2    50   ~ 0
M10
Text Label 14800 2200 2    50   ~ 0
M11
Text Label 14800 2300 2    50   ~ 0
M12
Text Label 14800 2400 2    50   ~ 0
M13
Text Label 14800 2500 2    50   ~ 0
M14
Text Label 14800 2600 2    50   ~ 0
M15
Text Label 14800 2700 2    50   ~ 0
M16
Text HLabel 16200 1100 2    50   Input ~ 0
BUS0
Text HLabel 16200 1200 2    50   Input ~ 0
BUS1
Text HLabel 16200 1300 2    50   Input ~ 0
BUS2
Text HLabel 16200 1400 2    50   Input ~ 0
BUS3
Text HLabel 16200 1500 2    50   Input ~ 0
BUS4
Text HLabel 16200 1600 2    50   Input ~ 0
BUS5
Text HLabel 16200 1700 2    50   Input ~ 0
BUS6
Text HLabel 16200 1800 2    50   Input ~ 0
BUS7
Text HLabel 14800 3100 0    50   Input ~ 0
~MMU_OUT
Text HLabel 14800 3200 0    50   Input ~ 0
~MMU_IN
$Comp
L Device:C_Small C85
U 1 1 5B09B1C8
P 15500 950
F 0 "C85" H 15592 996 50  0000 L CNN
F 1 "0.1uF" H 15592 905 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 15500 950 50  0001 C CNN
F 3 "~" H 15500 950 50  0001 C CNN
	1    15500 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0302
U 1 1 5B09B1CF
P 15500 850
F 0 "#PWR0302" H 15500 600 50  0001 C CNN
F 1 "GND" H 15505 677 50  0000 C CNN
F 2 "" H 15500 850 50  0001 C CNN
F 3 "" H 15500 850 50  0001 C CNN
	1    15500 850 
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U73
U 1 1 5B09B347
P 9900 4750
F 0 "U73" H 9900 4800 50  0000 C CNN
F 1 "628128" H 9900 4650 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 9900 4750 50  0001 C CNN
F 3 "" H 9900 4750 50  0001 C CNN
	1    9900 4750
	1    0    0    -1  
$EndComp
Text Label 9200 3700 2    50   ~ 0
M0
Text Label 9200 3800 2    50   ~ 0
M1
Text Label 9200 3900 2    50   ~ 0
M2
Text Label 9200 4000 2    50   ~ 0
M3
Text Label 9200 4100 2    50   ~ 0
M4
Text Label 9200 4200 2    50   ~ 0
M5
Text Label 9200 4300 2    50   ~ 0
M6
Text Label 9200 4400 2    50   ~ 0
M7
Text Label 9200 4500 2    50   ~ 0
M8
Text Label 9200 4600 2    50   ~ 0
M9
Text Label 9200 4700 2    50   ~ 0
M10
Text Label 9200 4800 2    50   ~ 0
M11
Text Label 9200 4900 2    50   ~ 0
M12
Text Label 9200 5000 2    50   ~ 0
M13
Text Label 9200 5100 2    50   ~ 0
M14
Text Label 9200 5200 2    50   ~ 0
M15
Text Label 9200 5300 2    50   ~ 0
M16
Text HLabel 10600 3700 2    50   Input ~ 0
BUS0
Text HLabel 10600 3800 2    50   Input ~ 0
BUS1
Text HLabel 10600 3900 2    50   Input ~ 0
BUS2
Text HLabel 10600 4000 2    50   Input ~ 0
BUS3
Text HLabel 10600 4100 2    50   Input ~ 0
BUS4
Text HLabel 10600 4200 2    50   Input ~ 0
BUS5
Text HLabel 10600 4300 2    50   Input ~ 0
BUS6
Text HLabel 10600 4400 2    50   Input ~ 0
BUS7
Text HLabel 9200 5700 0    50   Input ~ 0
~MMU_OUT
Text HLabel 9200 5800 0    50   Input ~ 0
~MMU_IN
$Comp
L Device:C_Small C80
U 1 1 5B09B36F
P 9900 3550
F 0 "C80" H 9992 3596 50  0000 L CNN
F 1 "0.1uF" H 9992 3505 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 9900 3550 50  0001 C CNN
F 3 "~" H 9900 3550 50  0001 C CNN
	1    9900 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0304
U 1 1 5B09B376
P 9900 3450
F 0 "#PWR0304" H 9900 3200 50  0001 C CNN
F 1 "GND" H 9905 3277 50  0000 C CNN
F 2 "" H 9900 3450 50  0001 C CNN
F 3 "" H 9900 3450 50  0001 C CNN
	1    9900 3450
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U75
U 1 1 5B09B37C
P 11750 4750
F 0 "U75" H 11750 4800 50  0000 C CNN
F 1 "628128" H 11750 4650 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 11750 4750 50  0001 C CNN
F 3 "" H 11750 4750 50  0001 C CNN
	1    11750 4750
	1    0    0    -1  
$EndComp
Text Label 11050 3700 2    50   ~ 0
M0
Text Label 11050 3800 2    50   ~ 0
M1
Text Label 11050 3900 2    50   ~ 0
M2
Text Label 11050 4000 2    50   ~ 0
M3
Text Label 11050 4100 2    50   ~ 0
M4
Text Label 11050 4200 2    50   ~ 0
M5
Text Label 11050 4300 2    50   ~ 0
M6
Text Label 11050 4400 2    50   ~ 0
M7
Text Label 11050 4500 2    50   ~ 0
M8
Text Label 11050 4600 2    50   ~ 0
M9
Text Label 11050 4700 2    50   ~ 0
M10
Text Label 11050 4800 2    50   ~ 0
M11
Text Label 11050 4900 2    50   ~ 0
M12
Text Label 11050 5000 2    50   ~ 0
M13
Text Label 11050 5100 2    50   ~ 0
M14
Text Label 11050 5200 2    50   ~ 0
M15
Text Label 11050 5300 2    50   ~ 0
M16
Text HLabel 12450 3700 2    50   Input ~ 0
BUS0
Text HLabel 12450 3800 2    50   Input ~ 0
BUS1
Text HLabel 12450 3900 2    50   Input ~ 0
BUS2
Text HLabel 12450 4000 2    50   Input ~ 0
BUS3
Text HLabel 12450 4100 2    50   Input ~ 0
BUS4
Text HLabel 12450 4200 2    50   Input ~ 0
BUS5
Text HLabel 12450 4300 2    50   Input ~ 0
BUS6
Text HLabel 12450 4400 2    50   Input ~ 0
BUS7
Text HLabel 11050 5700 0    50   Input ~ 0
~MMU_OUT
Text HLabel 11050 5800 0    50   Input ~ 0
~MMU_IN
$Comp
L Device:C_Small C82
U 1 1 5B09B3A4
P 11750 3550
F 0 "C82" H 11842 3596 50  0000 L CNN
F 1 "0.1uF" H 11842 3505 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 11750 3550 50  0001 C CNN
F 3 "~" H 11750 3550 50  0001 C CNN
	1    11750 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0306
U 1 1 5B09B3AB
P 11750 3450
F 0 "#PWR0306" H 11750 3200 50  0001 C CNN
F 1 "GND" H 11755 3277 50  0000 C CNN
F 2 "" H 11750 3450 50  0001 C CNN
F 3 "" H 11750 3450 50  0001 C CNN
	1    11750 3450
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U77
U 1 1 5B09B3B1
P 13650 4800
F 0 "U77" H 13650 4850 50  0000 C CNN
F 1 "628128" H 13650 4700 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 13650 4800 50  0001 C CNN
F 3 "" H 13650 4800 50  0001 C CNN
	1    13650 4800
	1    0    0    -1  
$EndComp
Text Label 12950 3750 2    50   ~ 0
M0
Text Label 12950 3850 2    50   ~ 0
M1
Text Label 12950 3950 2    50   ~ 0
M2
Text Label 12950 4050 2    50   ~ 0
M3
Text Label 12950 4150 2    50   ~ 0
M4
Text Label 12950 4250 2    50   ~ 0
M5
Text Label 12950 4350 2    50   ~ 0
M6
Text Label 12950 4450 2    50   ~ 0
M7
Text Label 12950 4550 2    50   ~ 0
M8
Text Label 12950 4650 2    50   ~ 0
M9
Text Label 12950 4750 2    50   ~ 0
M10
Text Label 12950 4850 2    50   ~ 0
M11
Text Label 12950 4950 2    50   ~ 0
M12
Text Label 12950 5050 2    50   ~ 0
M13
Text Label 12950 5150 2    50   ~ 0
M14
Text Label 12950 5250 2    50   ~ 0
M15
Text Label 12950 5350 2    50   ~ 0
M16
Text HLabel 14350 3750 2    50   Input ~ 0
BUS0
Text HLabel 14350 3850 2    50   Input ~ 0
BUS1
Text HLabel 14350 3950 2    50   Input ~ 0
BUS2
Text HLabel 14350 4050 2    50   Input ~ 0
BUS3
Text HLabel 14350 4150 2    50   Input ~ 0
BUS4
Text HLabel 14350 4250 2    50   Input ~ 0
BUS5
Text HLabel 14350 4350 2    50   Input ~ 0
BUS6
Text HLabel 14350 4450 2    50   Input ~ 0
BUS7
Text HLabel 12950 5750 0    50   Input ~ 0
~MMU_OUT
Text HLabel 12950 5850 0    50   Input ~ 0
~MMU_IN
$Comp
L Device:C_Small C84
U 1 1 5B09B3D9
P 13650 3600
F 0 "C84" H 13742 3646 50  0000 L CNN
F 1 "0.1uF" H 13742 3555 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 13650 3600 50  0001 C CNN
F 3 "~" H 13650 3600 50  0001 C CNN
	1    13650 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0308
U 1 1 5B09B3E0
P 13650 3500
F 0 "#PWR0308" H 13650 3250 50  0001 C CNN
F 1 "GND" H 13655 3327 50  0000 C CNN
F 2 "" H 13650 3500 50  0001 C CNN
F 3 "" H 13650 3500 50  0001 C CNN
	1    13650 3500
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U79
U 1 1 5B09B3E6
P 15500 4800
F 0 "U79" H 15500 4850 50  0000 C CNN
F 1 "628128" H 15500 4700 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 15500 4800 50  0001 C CNN
F 3 "" H 15500 4800 50  0001 C CNN
	1    15500 4800
	1    0    0    -1  
$EndComp
Text Label 14800 3750 2    50   ~ 0
M0
Text Label 14800 3850 2    50   ~ 0
M1
Text Label 14800 3950 2    50   ~ 0
M2
Text Label 14800 4050 2    50   ~ 0
M3
Text Label 14800 4150 2    50   ~ 0
M4
Text Label 14800 4250 2    50   ~ 0
M5
Text Label 14800 4350 2    50   ~ 0
M6
Text Label 14800 4450 2    50   ~ 0
M7
Text Label 14800 4550 2    50   ~ 0
M8
Text Label 14800 4650 2    50   ~ 0
M9
Text Label 14800 4750 2    50   ~ 0
M10
Text Label 14800 4850 2    50   ~ 0
M11
Text Label 14800 4950 2    50   ~ 0
M12
Text Label 14800 5050 2    50   ~ 0
M13
Text Label 14800 5150 2    50   ~ 0
M14
Text Label 14800 5250 2    50   ~ 0
M15
Text Label 14800 5350 2    50   ~ 0
M16
Text HLabel 16200 3750 2    50   Input ~ 0
BUS0
Text HLabel 16200 3850 2    50   Input ~ 0
BUS1
Text HLabel 16200 3950 2    50   Input ~ 0
BUS2
Text HLabel 16200 4050 2    50   Input ~ 0
BUS3
Text HLabel 16200 4150 2    50   Input ~ 0
BUS4
Text HLabel 16200 4250 2    50   Input ~ 0
BUS5
Text HLabel 16200 4350 2    50   Input ~ 0
BUS6
Text HLabel 16200 4450 2    50   Input ~ 0
BUS7
Text HLabel 14800 5750 0    50   Input ~ 0
~MMU_OUT
Text HLabel 14800 5850 0    50   Input ~ 0
~MMU_IN
$Comp
L Device:C_Small C86
U 1 1 5B09B40E
P 15500 3600
F 0 "C86" H 15592 3646 50  0000 L CNN
F 1 "0.1uF" H 15592 3555 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 15500 3600 50  0001 C CNN
F 3 "~" H 15500 3600 50  0001 C CNN
	1    15500 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0310
U 1 1 5B09B415
P 15500 3500
F 0 "#PWR0310" H 15500 3250 50  0001 C CNN
F 1 "GND" H 15505 3327 50  0000 C CNN
F 2 "" H 15500 3500 50  0001 C CNN
F 3 "" H 15500 3500 50  0001 C CNN
	1    15500 3500
	-1   0    0    1   
$EndComp
Text Label 6500 3700 0    50   ~ 0
~SEL0
Text Label 6500 3800 0    50   ~ 0
~SEL1
Text Label 6500 3900 0    50   ~ 0
~SEL2
Text Label 6500 4000 0    50   ~ 0
~SEL3
Text Label 6500 4100 0    50   ~ 0
~SEL4
Text Label 6500 4200 0    50   ~ 0
~SEL5
Text Label 6500 4300 0    50   ~ 0
~SEL6
Text Label 6500 4400 0    50   ~ 0
~SEL7
Text Label 9200 2850 2    50   ~ 0
~SEL0
Text Label 11050 2850 2    50   ~ 0
~SEL1
Text Label 12950 2900 2    50   ~ 0
~SEL2
Text Label 14800 2900 2    50   ~ 0
~SEL3
Text Label 9200 5500 2    50   ~ 0
~SEL4
Text Label 11050 5500 2    50   ~ 0
~SEL5
Text Label 12950 5550 2    50   ~ 0
~SEL6
Text Label 14800 5550 2    50   ~ 0
~SEL7
$Comp
L Memory_RAM:628128 U84
U 1 1 5B0AD995
P 2000 1950
F 0 "U84" H 2000 2000 50  0000 C CNN
F 1 "628128" H 2000 1850 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 2000 1950 50  0001 C CNN
F 3 "" H 2000 1950 50  0001 C CNN
	1    2000 1950
	1    0    0    -1  
$EndComp
Text HLabel 1300 3000 0    50   Input ~ 0
~MMU_CONTROL_IN
$Comp
L power:GND #PWR0291
U 1 1 5B0AD9B7
P 1300 2700
F 0 "#PWR0291" H 1300 2450 50  0001 C CNN
F 1 "GND" V 1305 2572 50  0000 R CNN
F 2 "" H 1300 2700 50  0001 C CNN
F 3 "" H 1300 2700 50  0001 C CNN
	1    1300 2700
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C91
U 1 1 5B0AD9BD
P 2000 750
F 0 "C91" H 2092 796 50  0000 L CNN
F 1 "0.1uF" H 2092 705 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2000 750 50  0001 C CNN
F 3 "~" H 2000 750 50  0001 C CNN
	1    2000 750 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0297
U 1 1 5B0AD9C4
P 2000 650
F 0 "#PWR0297" H 2000 400 50  0001 C CNN
F 1 "GND" H 2005 477 50  0000 C CNN
F 2 "" H 2000 650 50  0001 C CNN
F 3 "" H 2000 650 50  0001 C CNN
	1    2000 650 
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0299
U 1 1 5B0ADBC7
P 1300 2900
F 0 "#PWR0299" H 1300 2650 50  0001 C CNN
F 1 "GND" V 1305 2772 50  0000 R CNN
F 2 "" H 1300 2900 50  0001 C CNN
F 3 "" H 1300 2900 50  0001 C CNN
	1    1300 2900
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0301
U 1 1 5B0ADEC6
P 9200 2950
F 0 "#PWR0301" H 9200 2800 50  0001 C CNN
F 1 "VCC" H 9217 3123 50  0000 C CNN
F 2 "" H 9200 2950 50  0001 C CNN
F 3 "" H 9200 2950 50  0001 C CNN
	1    9200 2950
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0303
U 1 1 5B0AE1C2
P 11050 2950
F 0 "#PWR0303" H 11050 2800 50  0001 C CNN
F 1 "VCC" H 11067 3123 50  0000 C CNN
F 2 "" H 11050 2950 50  0001 C CNN
F 3 "" H 11050 2950 50  0001 C CNN
	1    11050 2950
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0305
U 1 1 5B0AE1F7
P 12950 3000
F 0 "#PWR0305" H 12950 2850 50  0001 C CNN
F 1 "VCC" H 12967 3173 50  0000 C CNN
F 2 "" H 12950 3000 50  0001 C CNN
F 3 "" H 12950 3000 50  0001 C CNN
	1    12950 3000
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0307
U 1 1 5B0AE22C
P 14800 3000
F 0 "#PWR0307" H 14800 2850 50  0001 C CNN
F 1 "VCC" H 14817 3173 50  0000 C CNN
F 2 "" H 14800 3000 50  0001 C CNN
F 3 "" H 14800 3000 50  0001 C CNN
	1    14800 3000
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0309
U 1 1 5B0AE2AA
P 14800 5650
F 0 "#PWR0309" H 14800 5500 50  0001 C CNN
F 1 "VCC" H 14817 5823 50  0000 C CNN
F 2 "" H 14800 5650 50  0001 C CNN
F 3 "" H 14800 5650 50  0001 C CNN
	1    14800 5650
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0333
U 1 1 5B0AE2DF
P 12950 5650
F 0 "#PWR0333" H 12950 5500 50  0001 C CNN
F 1 "VCC" H 12967 5823 50  0000 C CNN
F 2 "" H 12950 5650 50  0001 C CNN
F 3 "" H 12950 5650 50  0001 C CNN
	1    12950 5650
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0334
U 1 1 5B0AE314
P 11050 5600
F 0 "#PWR0334" H 11050 5450 50  0001 C CNN
F 1 "VCC" H 11067 5773 50  0000 C CNN
F 2 "" H 11050 5600 50  0001 C CNN
F 3 "" H 11050 5600 50  0001 C CNN
	1    11050 5600
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0335
U 1 1 5B0AE349
P 9200 5600
F 0 "#PWR0335" H 9200 5450 50  0001 C CNN
F 1 "VCC" H 9217 5773 50  0000 C CNN
F 2 "" H 9200 5600 50  0001 C CNN
F 3 "" H 9200 5600 50  0001 C CNN
	1    9200 5600
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0336
U 1 1 5B0AE561
P 1300 2800
F 0 "#PWR0336" H 1300 2650 50  0001 C CNN
F 1 "VCC" H 1317 2973 50  0000 C CNN
F 2 "" H 1300 2800 50  0001 C CNN
F 3 "" H 1300 2800 50  0001 C CNN
	1    1300 2800
	0    -1   -1   0   
$EndComp
Text HLabel 1300 1800 0    50   Input ~ 0
TASK0
Text HLabel 1300 1900 0    50   Input ~ 0
TASK1
Text HLabel 1300 2000 0    50   Input ~ 0
TASK2
Text HLabel 1300 2100 0    50   Input ~ 0
TASK3
Text HLabel 1300 2200 0    50   Input ~ 0
TASK4
Text HLabel 1300 2300 0    50   Input ~ 0
TASK5
Text HLabel 1300 2400 0    50   Input ~ 0
TASK6
Text HLabel 1300 2500 0    50   Input ~ 0
TASK7
Text Label 1300 1400 2    50   ~ 0
M17
Text Label 1300 1500 2    50   ~ 0
M18
Text Label 1300 1600 2    50   ~ 0
M19
Text Label 1300 1700 2    50   ~ 0
M20
Text Label 1300 1000 2    50   ~ 0
M13
Text Label 1300 1100 2    50   ~ 0
M14
Text Label 1300 1200 2    50   ~ 0
M15
Text Label 1300 1300 2    50   ~ 0
M16
Text Label 1300 900  2    50   ~ 0
M12
$Comp
L 74xx:74LS153 U85
U 1 1 5B0AF55A
P 3450 4600
F 0 "U85" H 3450 4400 50  0000 C CNN
F 1 "74LS153" H 3450 4200 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 3450 4600 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS153" H 3450 4600 50  0001 C CNN
	1    3450 4600
	1    0    0    -1  
$EndComp
Text Label 2700 900  0    50   ~ 0
READ0
Text Label 2700 1100 0    50   ~ 0
READ1
Text Label 2700 1300 0    50   ~ 0
READ2
Text Label 2700 1500 0    50   ~ 0
READ3
Text Label 2700 1000 0    50   ~ 0
WRITE0
Text Label 2700 1200 0    50   ~ 0
WRITE1
Text Label 2700 1400 0    50   ~ 0
WRITE2
Text Label 2700 1600 0    50   ~ 0
WRITE3
Text Label 2950 3900 2    50   ~ 0
READ0
Text Label 2950 4000 2    50   ~ 0
READ1
Text Label 2950 4100 2    50   ~ 0
READ2
Text Label 2950 4200 2    50   ~ 0
READ3
Text Label 2950 4600 2    50   ~ 0
WRITE0
Text Label 2950 4700 2    50   ~ 0
WRITE1
Text Label 2950 4800 2    50   ~ 0
WRITE2
Text Label 2950 4900 2    50   ~ 0
WRITE3
$Comp
L power:GND #PWR0337
U 1 1 5B0AFD3A
P 2950 5100
F 0 "#PWR0337" H 2950 4850 50  0001 C CNN
F 1 "GND" V 2955 4972 50  0000 R CNN
F 2 "" H 2950 5100 50  0001 C CNN
F 3 "" H 2950 5100 50  0001 C CNN
	1    2950 5100
	0    1    1    0   
$EndComp
Text Label 2950 5300 2    50   ~ 0
M10
Text Label 2950 5400 2    50   ~ 0
M11
$Comp
L power:GND #PWR0338
U 1 1 5B0B02CA
P 2950 4400
F 0 "#PWR0338" H 2950 4150 50  0001 C CNN
F 1 "GND" V 2955 4272 50  0000 R CNN
F 2 "" H 2950 4400 50  0001 C CNN
F 3 "" H 2950 4400 50  0001 C CNN
	1    2950 4400
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C92
U 1 1 5B0B0540
P 3750 3600
F 0 "C92" V 3979 3600 50  0000 C CNN
F 1 "0.1uF" V 3888 3600 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 3750 3600 50  0001 C CNN
F 3 "~" H 3750 3600 50  0001 C CNN
	1    3750 3600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3450 3600 3650 3600
$Comp
L power:VCC #PWR0339
U 1 1 5B0B061D
P 3450 3600
F 0 "#PWR0339" H 3450 3450 50  0001 C CNN
F 1 "VCC" H 3467 3773 50  0000 C CNN
F 2 "" H 3450 3600 50  0001 C CNN
F 3 "" H 3450 3600 50  0001 C CNN
	1    3450 3600
	1    0    0    -1  
$EndComp
Connection ~ 3450 3600
$Comp
L power:GND #PWR0340
U 1 1 5B0B0656
P 3850 3600
F 0 "#PWR0340" H 3850 3350 50  0001 C CNN
F 1 "GND" H 3855 3427 50  0000 C CNN
F 2 "" H 3850 3600 50  0001 C CNN
F 3 "" H 3850 3600 50  0001 C CNN
	1    3850 3600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0341
U 1 1 5B0B06A6
P 3450 5700
F 0 "#PWR0341" H 3450 5450 50  0001 C CNN
F 1 "GND" H 3455 5527 50  0000 C CNN
F 2 "" H 3450 5700 50  0001 C CNN
F 3 "" H 3450 5700 50  0001 C CNN
	1    3450 5700
	1    0    0    -1  
$EndComp
Text Notes 5350 3100 0    50   ~ 0
Use 4-16 line decoder to select\nwhich memory chip to use. 
Text Notes 7350 6300 0    50   ~ 0
M20 reads from memory \nmapped eeprom instead.\nNote that ~OE is active low\nso M20 low = read from EEPROM.
$Comp
L 74xx:74HC245 U86
U 1 1 5B0B7D74
P 4000 1400
F 0 "U86" H 4000 1250 50  0000 C CNN
F 1 "74HC245" H 4050 1100 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 4000 1400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 4000 1400 50  0001 C CNN
	1    4000 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C93
U 1 1 5B0B7FD7
P 4300 600
F 0 "C93" V 4529 600 50  0000 C CNN
F 1 "0.1uF" V 4438 600 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4300 600 50  0001 C CNN
F 3 "~" H 4300 600 50  0001 C CNN
	1    4300 600 
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0342
U 1 1 5B0B7FDE
P 4000 600
F 0 "#PWR0342" H 4000 450 50  0001 C CNN
F 1 "VCC" H 4017 773 50  0000 C CNN
F 2 "" H 4000 600 50  0001 C CNN
F 3 "" H 4000 600 50  0001 C CNN
	1    4000 600 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0343
U 1 1 5B0B7FE4
P 4400 600
F 0 "#PWR0343" H 4400 350 50  0001 C CNN
F 1 "GND" H 4405 427 50  0000 C CNN
F 2 "" H 4400 600 50  0001 C CNN
F 3 "" H 4400 600 50  0001 C CNN
	1    4400 600 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4000 600  4200 600 
Connection ~ 4000 600 
$Comp
L Device:C_Small C94
U 1 1 5B0B9313
P 6300 3400
F 0 "C94" V 6529 3400 50  0000 C CNN
F 1 "0.1uF" V 6438 3400 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 6300 3400 50  0001 C CNN
F 3 "~" H 6300 3400 50  0001 C CNN
	1    6300 3400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0344
U 1 1 5B0B93A5
P 6400 3400
F 0 "#PWR0344" H 6400 3150 50  0001 C CNN
F 1 "GND" H 6405 3227 50  0000 C CNN
F 2 "" H 6400 3400 50  0001 C CNN
F 3 "" H 6400 3400 50  0001 C CNN
	1    6400 3400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6200 3400 6000 3400
Connection ~ 6000 3400
$Comp
L power:VCC #PWR0345
U 1 1 5B0B9FA5
P 3500 1800
F 0 "#PWR0345" H 3500 1650 50  0001 C CNN
F 1 "VCC" H 3517 1973 50  0000 C CNN
F 2 "" H 3500 1800 50  0001 C CNN
F 3 "" H 3500 1800 50  0001 C CNN
	1    3500 1800
	0    -1   -1   0   
$EndComp
Text HLabel 3500 1900 0    50   Input ~ 0
~MMU_CONTROL_OUT
$Comp
L power:GND #PWR0346
U 1 1 5B0BA16C
P 4000 2200
F 0 "#PWR0346" H 4000 1950 50  0001 C CNN
F 1 "GND" H 4005 2027 50  0000 C CNN
F 2 "" H 4000 2200 50  0001 C CNN
F 3 "" H 4000 2200 50  0001 C CNN
	1    4000 2200
	1    0    0    -1  
$EndComp
Text HLabel 4500 900  2    50   Input ~ 0
BUS0
Text HLabel 4500 1000 2    50   Input ~ 0
BUS1
Text HLabel 4500 1100 2    50   Input ~ 0
BUS2
Text HLabel 4500 1200 2    50   Input ~ 0
BUS3
Text HLabel 4500 1300 2    50   Input ~ 0
BUS4
Text HLabel 4500 1400 2    50   Input ~ 0
BUS5
Text HLabel 4500 1500 2    50   Input ~ 0
BUS6
Text HLabel 4500 1600 2    50   Input ~ 0
BUS7
Wire Wire Line
	2700 900  3500 900 
Wire Wire Line
	2700 1000 3500 1000
Wire Wire Line
	2700 1100 3500 1100
Wire Wire Line
	2700 1200 3500 1200
Wire Wire Line
	2700 1300 3500 1300
Wire Wire Line
	2700 1400 3500 1400
Wire Wire Line
	2700 1500 3500 1500
Wire Wire Line
	2700 1600 3500 1600
Text HLabel 3950 3900 2    50   Input ~ 0
MMU_READ_FAULT
Text HLabel 3950 4600 2    50   Input ~ 0
MMU_WRITE_FAULT
Text HLabel 5600 1050 0    50   Input ~ 0
BUS0
Text HLabel 5600 1150 0    50   Input ~ 0
BUS1
Text HLabel 5600 1250 0    50   Input ~ 0
BUS2
Text HLabel 5600 1350 0    50   Input ~ 0
BUS3
Text HLabel 5600 1450 0    50   Input ~ 0
BUS4
Text HLabel 5600 1550 0    50   Input ~ 0
BUS5
Text HLabel 5600 1650 0    50   Input ~ 0
BUS6
Text HLabel 5600 1750 0    50   Input ~ 0
BUS7
Text HLabel 6750 1050 0    50   Input ~ 0
BUS0
Text HLabel 6750 1150 0    50   Input ~ 0
BUS1
Text HLabel 6750 1250 0    50   Input ~ 0
BUS2
Text HLabel 6750 1350 0    50   Input ~ 0
BUS3
Text HLabel 6750 1450 0    50   Input ~ 0
BUS4
Text HLabel 6750 1550 0    50   Input ~ 0
BUS5
Text HLabel 6750 1650 0    50   Input ~ 0
BUS6
Text HLabel 6750 1750 0    50   Input ~ 0
BUS7
Text HLabel 8000 1050 0    50   Input ~ 0
BUS0
Text HLabel 8000 1150 0    50   Input ~ 0
BUS1
Text HLabel 8000 1250 0    50   Input ~ 0
BUS2
Text HLabel 8000 1350 0    50   Input ~ 0
BUS3
Text HLabel 8000 1450 0    50   Input ~ 0
BUS4
Text HLabel 8000 1550 0    50   Input ~ 0
BUS5
Text HLabel 8000 1650 0    50   Input ~ 0
BUS6
Text HLabel 8000 1750 0    50   Input ~ 0
BUS7
$Comp
L power:GND #PWR0414
U 1 1 5B1F8EE4
P 5600 1950
F 0 "#PWR0414" H 5600 1700 50  0001 C CNN
F 1 "GND" H 5605 1777 50  0000 C CNN
F 2 "" H 5600 1950 50  0001 C CNN
F 3 "" H 5600 1950 50  0001 C CNN
	1    5600 1950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0415
U 1 1 5B1F8F3D
P 6750 1950
F 0 "#PWR0415" H 6750 1700 50  0001 C CNN
F 1 "GND" H 6755 1777 50  0000 C CNN
F 2 "" H 6750 1950 50  0001 C CNN
F 3 "" H 6750 1950 50  0001 C CNN
	1    6750 1950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0416
U 1 1 5B1F902C
P 8000 1950
F 0 "#PWR0416" H 8000 1700 50  0001 C CNN
F 1 "GND" H 8005 1777 50  0000 C CNN
F 2 "" H 8000 1950 50  0001 C CNN
F 3 "" H 8000 1950 50  0001 C CNN
	1    8000 1950
	0    1    1    0   
$EndComp
Text HLabel 5600 2050 0    50   Input ~ 0
MMU0_IN
Text HLabel 6750 2050 0    50   Input ~ 0
MMU1_IN
Text HLabel 8000 2050 0    50   Input ~ 0
MMU2_IN
$EndSCHEMATC
