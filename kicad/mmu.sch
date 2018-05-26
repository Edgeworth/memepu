EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 20 23
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
S 900  950  550  1200
U 5B0966DC
F0 "MMU0" 50
F1 "register.sch" 50
F2 "REG_IN" I L 900 2050 50 
F3 "I0" I L 900 1050 50 
F4 "I1" I L 900 1150 50 
F5 "I2" I L 900 1250 50 
F6 "I3" I L 900 1350 50 
F7 "I4" I L 900 1450 50 
F8 "I5" I L 900 1550 50 
F9 "I6" I L 900 1650 50 
F10 "I7" I L 900 1750 50 
F11 "~REG_OUT" I L 900 1950 50 
F12 "O0" I R 1450 1050 50 
F13 "O1" I R 1450 1150 50 
F14 "O2" I R 1450 1250 50 
F15 "O3" I R 1450 1350 50 
F16 "O4" I R 1450 1450 50 
F17 "O5" I R 1450 1550 50 
F18 "O6" I R 1450 1650 50 
F19 "O7" I R 1450 1750 50 
$EndSheet
$Sheet
S 2050 950  550  1200
U 5B096830
F0 "MMU1" 50
F1 "register.sch" 50
F2 "REG_IN" I L 2050 2050 50 
F3 "I0" I L 2050 1050 50 
F4 "I1" I L 2050 1150 50 
F5 "I2" I L 2050 1250 50 
F6 "I3" I L 2050 1350 50 
F7 "I4" I L 2050 1450 50 
F8 "I5" I L 2050 1550 50 
F9 "I6" I L 2050 1650 50 
F10 "I7" I L 2050 1750 50 
F11 "~REG_OUT" I L 2050 1950 50 
F12 "O0" I R 2600 1050 50 
F13 "O1" I R 2600 1150 50 
F14 "O2" I R 2600 1250 50 
F15 "O3" I R 2600 1350 50 
F16 "O4" I R 2600 1450 50 
F17 "O5" I R 2600 1550 50 
F18 "O6" I R 2600 1650 50 
F19 "O7" I R 2600 1750 50 
$EndSheet
$Sheet
S 3300 950  550  1200
U 5B096845
F0 "MMU2" 50
F1 "register.sch" 50
F2 "REG_IN" I L 3300 2050 50 
F3 "I0" I L 3300 1050 50 
F4 "I1" I L 3300 1150 50 
F5 "I2" I L 3300 1250 50 
F6 "I3" I L 3300 1350 50 
F7 "I4" I L 3300 1450 50 
F8 "I5" I L 3300 1550 50 
F9 "I6" I L 3300 1650 50 
F10 "I7" I L 3300 1750 50 
F11 "~REG_OUT" I L 3300 1950 50 
F12 "O0" I R 3850 1050 50 
F13 "O1" I R 3850 1150 50 
F14 "O2" I R 3850 1250 50 
F15 "O3" I R 3850 1350 50 
F16 "O4" I R 3850 1450 50 
F17 "O5" I R 3850 1550 50 
F18 "O6" I R 3850 1650 50 
F19 "O7" I R 3850 1750 50 
$EndSheet
$Comp
L Memory_RAM:628128 U72
U 1 1 5B096C3C
P 5200 2100
F 0 "U72" H 5200 2150 50  0000 C CNN
F 1 "628128" H 5200 2000 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 5200 2100 50  0001 C CNN
F 3 "" H 5200 2100 50  0001 C CNN
	1    5200 2100
	1    0    0    -1  
$EndComp
Text Label 1450 1050 0    50   ~ 0
M0
Text Label 1450 1150 0    50   ~ 0
M1
Text Label 1450 1250 0    50   ~ 0
M2
Text Label 1450 1350 0    50   ~ 0
M3
Text Label 1450 1450 0    50   ~ 0
M4
Text Label 1450 1550 0    50   ~ 0
M5
Text Label 1450 1650 0    50   ~ 0
M6
Text Label 1450 1750 0    50   ~ 0
M7
Text Label 2600 1050 0    50   ~ 0
M8
Text Label 2600 1150 0    50   ~ 0
M9
Text Label 2600 1250 0    50   ~ 0
M10
Text Label 2600 1350 0    50   ~ 0
M11
Text Label 2600 1450 0    50   ~ 0
M12
Text Label 2600 1550 0    50   ~ 0
M13
Text Label 2600 1650 0    50   ~ 0
M14
Text Label 2600 1750 0    50   ~ 0
M15
Text Label 3850 1050 0    50   ~ 0
M16
Text Label 3850 1150 0    50   ~ 0
M17
Text Label 3850 1250 0    50   ~ 0
M18
Text Label 3850 1350 0    50   ~ 0
M19
Text Label 3850 1450 0    50   ~ 0
M20
Text Label 3850 1550 0    50   ~ 0
M21
Text Label 3850 1650 0    50   ~ 0
M22
Text Label 3850 1750 0    50   ~ 0
M23
$Comp
L power:VCC #PWR0289
U 1 1 5B097BEB
P 1300 3400
F 0 "#PWR0289" H 1300 3250 50  0001 C CNN
F 1 "VCC" H 1317 3573 50  0000 C CNN
F 2 "" H 1300 3400 50  0001 C CNN
F 3 "" H 1300 3400 50  0001 C CNN
	1    1300 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0290
U 1 1 5B097C44
P 1300 5500
F 0 "#PWR0290" H 1300 5250 50  0001 C CNN
F 1 "GND" H 1305 5327 50  0000 C CNN
F 2 "" H 1300 5500 50  0001 C CNN
F 3 "" H 1300 5500 50  0001 C CNN
	1    1300 5500
	1    0    0    -1  
$EndComp
Text Label 4500 1050 2    50   ~ 0
M0
Text Label 4500 1150 2    50   ~ 0
M1
Text Label 4500 1250 2    50   ~ 0
M2
Text Label 4500 1350 2    50   ~ 0
M3
Text Label 4500 1450 2    50   ~ 0
M4
Text Label 4500 1550 2    50   ~ 0
M5
Text Label 4500 1650 2    50   ~ 0
M6
Text Label 4500 1750 2    50   ~ 0
M7
Text Label 4500 1850 2    50   ~ 0
M8
Text Label 4500 1950 2    50   ~ 0
M9
Text Label 4500 2050 2    50   ~ 0
M10
Text Label 4500 2150 2    50   ~ 0
M11
Text Label 4500 2250 2    50   ~ 0
M12
Text Label 4500 2350 2    50   ~ 0
M13
Text Label 4500 2450 2    50   ~ 0
M14
Text Label 4500 2550 2    50   ~ 0
M15
Text Label 4500 2650 2    50   ~ 0
M16
Text HLabel 5900 1050 2    50   Input ~ 0
BUS0
Text HLabel 5900 1150 2    50   Input ~ 0
BUS1
Text HLabel 5900 1250 2    50   Input ~ 0
BUS2
Text HLabel 5900 1350 2    50   Input ~ 0
BUS3
Text HLabel 5900 1450 2    50   Input ~ 0
BUS4
Text HLabel 5900 1550 2    50   Input ~ 0
BUS5
Text HLabel 5900 1650 2    50   Input ~ 0
BUS6
Text HLabel 5900 1750 2    50   Input ~ 0
BUS7
Text Notes 700  500  0    50   ~ 0
TODO: Need to make task register have a bus transceiver to plug into memory protection hardware.
Text HLabel 4500 3050 0    50   Input ~ 0
~MMU_OUT
Text HLabel 4500 3150 0    50   Input ~ 0
~MMU_IN
$Comp
L power:GND #PWR0291
U 1 1 5B0985A8
P 4500 2950
F 0 "#PWR0291" H 4500 2700 50  0001 C CNN
F 1 "GND" V 4505 2822 50  0000 R CNN
F 2 "" H 4500 2950 50  0001 C CNN
F 3 "" H 4500 2950 50  0001 C CNN
	1    4500 2950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0292
U 1 1 5B0985CB
P 800 4200
F 0 "#PWR0292" H 800 3950 50  0001 C CNN
F 1 "GND" V 805 4072 50  0000 R CNN
F 2 "" H 800 4200 50  0001 C CNN
F 3 "" H 800 4200 50  0001 C CNN
	1    800  4200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0293
U 1 1 5B0985DC
P 800 4300
F 0 "#PWR0293" H 800 4050 50  0001 C CNN
F 1 "GND" V 805 4172 50  0000 R CNN
F 2 "" H 800 4300 50  0001 C CNN
F 3 "" H 800 4300 50  0001 C CNN
	1    800  4300
	0    1    1    0   
$EndComp
$Comp
L Memory_Flash:SST39SF040 U71
U 1 1 5B098A2E
P 3200 4800
F 0 "U71" H 3200 5200 50  0000 C CNN
F 1 "SST39SF040" H 3300 4950 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 3200 5100 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 3200 5100 50  0001 C CNN
	1    3200 4800
	1    0    0    -1  
$EndComp
Text Notes 750  600  0    50   ~ 0
TODO: Check VCC and GND are connected for hidden pins on sram, eeprom
Text Label 800  3700 2    50   ~ 0
M17
Text Label 800  3800 2    50   ~ 0
M18
Text Label 800  3900 2    50   ~ 0
M19
$Comp
L Device:C_Small C78
U 1 1 5B0991AB
P 3200 3400
F 0 "C78" H 3292 3446 50  0000 L CNN
F 1 "C_Small" H 3292 3355 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 3200 3400 50  0001 C CNN
F 3 "~" H 3200 3400 50  0001 C CNN
	1    3200 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0294
U 1 1 5B099211
P 3200 3300
F 0 "#PWR0294" H 3200 3050 50  0001 C CNN
F 1 "GND" H 3205 3127 50  0000 C CNN
F 2 "" H 3200 3300 50  0001 C CNN
F 3 "" H 3200 3300 50  0001 C CNN
	1    3200 3300
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C79
U 1 1 5B09925F
P 5200 900
F 0 "C79" H 5292 946 50  0000 L CNN
F 1 "C_Small" H 5292 855 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 5200 900 50  0001 C CNN
F 3 "~" H 5200 900 50  0001 C CNN
	1    5200 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0295
U 1 1 5B09940C
P 5200 800
F 0 "#PWR0295" H 5200 550 50  0001 C CNN
F 1 "GND" H 5205 627 50  0000 C CNN
F 2 "" H 5200 800 50  0001 C CNN
F 3 "" H 5200 800 50  0001 C CNN
	1    5200 800 
	-1   0    0    1   
$EndComp
$Comp
L 74xx:74LS154 U70
U 1 1 5B099625
P 1300 4400
F 0 "U70" H 1300 4450 50  0000 C CNN
F 1 "74LS154" H 1300 4200 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W7.62mm_Socket" H 1300 4400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS154" H 1300 4400 50  0001 C CNN
	1    1300 4400
	1    0    0    -1  
$EndComp
Text Label 800  4000 2    50   ~ 0
M20
NoConn ~ 1800 4500
NoConn ~ 1800 4600
NoConn ~ 1800 4700
NoConn ~ 1800 4800
NoConn ~ 1800 4900
NoConn ~ 1800 5000
NoConn ~ 1800 5100
NoConn ~ 1800 5200
Text Label 2600 5900 2    50   ~ 0
M20
Text Label 2600 3600 2    50   ~ 0
M0
Text Label 2600 3700 2    50   ~ 0
M1
Text Label 2600 3800 2    50   ~ 0
M2
Text Label 2600 3900 2    50   ~ 0
M3
Text Label 2600 4000 2    50   ~ 0
M4
Text Label 2600 4100 2    50   ~ 0
M5
Text Label 2600 4200 2    50   ~ 0
M6
Text Label 2600 4300 2    50   ~ 0
M7
Text Label 2600 4400 2    50   ~ 0
M8
Text Label 2600 4500 2    50   ~ 0
M9
Text Label 2600 4600 2    50   ~ 0
M10
Text Label 2600 4700 2    50   ~ 0
M11
Text Label 2600 4800 2    50   ~ 0
M12
Text Label 2600 4900 2    50   ~ 0
M13
Text Label 2600 5000 2    50   ~ 0
M14
Text Label 2600 5100 2    50   ~ 0
M15
Text Label 2600 5200 2    50   ~ 0
M16
Text Label 2600 5300 2    50   ~ 0
M17
Text Label 2600 5400 2    50   ~ 0
M18
$Comp
L power:VCC #PWR0296
U 1 1 5B09A2B5
P 2600 5600
F 0 "#PWR0296" H 2600 5450 50  0001 C CNN
F 1 "VCC" V 2618 5727 50  0000 L CNN
F 2 "" H 2600 5600 50  0001 C CNN
F 3 "" H 2600 5600 50  0001 C CNN
	1    2600 5600
	0    -1   -1   0   
$EndComp
Text HLabel 3800 3600 2    50   Input ~ 0
BUS0
Text HLabel 3800 3700 2    50   Input ~ 0
BUS1
Text HLabel 3800 3800 2    50   Input ~ 0
BUS2
Text HLabel 3800 3900 2    50   Input ~ 0
BUS3
Text HLabel 3800 4000 2    50   Input ~ 0
BUS4
Text HLabel 3800 4100 2    50   Input ~ 0
BUS5
Text HLabel 3800 4200 2    50   Input ~ 0
BUS6
Text HLabel 3800 4300 2    50   Input ~ 0
BUS7
Text HLabel 2600 5800 0    50   Input ~ 0
~MMU_OUT
$Comp
L Memory_RAM:628128 U74
U 1 1 5B09B082
P 7050 2100
F 0 "U74" H 7050 2150 50  0000 C CNN
F 1 "628128" H 7050 2000 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 7050 2100 50  0001 C CNN
F 3 "" H 7050 2100 50  0001 C CNN
	1    7050 2100
	1    0    0    -1  
$EndComp
Text Label 6350 1050 2    50   ~ 0
M0
Text Label 6350 1150 2    50   ~ 0
M1
Text Label 6350 1250 2    50   ~ 0
M2
Text Label 6350 1350 2    50   ~ 0
M3
Text Label 6350 1450 2    50   ~ 0
M4
Text Label 6350 1550 2    50   ~ 0
M5
Text Label 6350 1650 2    50   ~ 0
M6
Text Label 6350 1750 2    50   ~ 0
M7
Text Label 6350 1850 2    50   ~ 0
M8
Text Label 6350 1950 2    50   ~ 0
M9
Text Label 6350 2050 2    50   ~ 0
M10
Text Label 6350 2150 2    50   ~ 0
M11
Text Label 6350 2250 2    50   ~ 0
M12
Text Label 6350 2350 2    50   ~ 0
M13
Text Label 6350 2450 2    50   ~ 0
M14
Text Label 6350 2550 2    50   ~ 0
M15
Text Label 6350 2650 2    50   ~ 0
M16
Text HLabel 7750 1050 2    50   Input ~ 0
BUS0
Text HLabel 7750 1150 2    50   Input ~ 0
BUS1
Text HLabel 7750 1250 2    50   Input ~ 0
BUS2
Text HLabel 7750 1350 2    50   Input ~ 0
BUS3
Text HLabel 7750 1450 2    50   Input ~ 0
BUS4
Text HLabel 7750 1550 2    50   Input ~ 0
BUS5
Text HLabel 7750 1650 2    50   Input ~ 0
BUS6
Text HLabel 7750 1750 2    50   Input ~ 0
BUS7
Text HLabel 6350 3050 0    50   Input ~ 0
~MMU_OUT
Text HLabel 6350 3150 0    50   Input ~ 0
~MMU_IN
$Comp
L power:GND #PWR0297
U 1 1 5B09B0A4
P 6350 2950
F 0 "#PWR0297" H 6350 2700 50  0001 C CNN
F 1 "GND" V 6355 2822 50  0000 R CNN
F 2 "" H 6350 2950 50  0001 C CNN
F 3 "" H 6350 2950 50  0001 C CNN
	1    6350 2950
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C81
U 1 1 5B09B0AA
P 7050 900
F 0 "C81" H 7142 946 50  0000 L CNN
F 1 "C_Small" H 7142 855 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 7050 900 50  0001 C CNN
F 3 "~" H 7050 900 50  0001 C CNN
	1    7050 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0298
U 1 1 5B09B0B1
P 7050 800
F 0 "#PWR0298" H 7050 550 50  0001 C CNN
F 1 "GND" H 7055 627 50  0000 C CNN
F 2 "" H 7050 800 50  0001 C CNN
F 3 "" H 7050 800 50  0001 C CNN
	1    7050 800 
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U76
U 1 1 5B09B16B
P 8950 2150
F 0 "U76" H 8950 2200 50  0000 C CNN
F 1 "628128" H 8950 2050 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 8950 2150 50  0001 C CNN
F 3 "" H 8950 2150 50  0001 C CNN
	1    8950 2150
	1    0    0    -1  
$EndComp
Text Label 8250 1100 2    50   ~ 0
M0
Text Label 8250 1200 2    50   ~ 0
M1
Text Label 8250 1300 2    50   ~ 0
M2
Text Label 8250 1400 2    50   ~ 0
M3
Text Label 8250 1500 2    50   ~ 0
M4
Text Label 8250 1600 2    50   ~ 0
M5
Text Label 8250 1700 2    50   ~ 0
M6
Text Label 8250 1800 2    50   ~ 0
M7
Text Label 8250 1900 2    50   ~ 0
M8
Text Label 8250 2000 2    50   ~ 0
M9
Text Label 8250 2100 2    50   ~ 0
M10
Text Label 8250 2200 2    50   ~ 0
M11
Text Label 8250 2300 2    50   ~ 0
M12
Text Label 8250 2400 2    50   ~ 0
M13
Text Label 8250 2500 2    50   ~ 0
M14
Text Label 8250 2600 2    50   ~ 0
M15
Text Label 8250 2700 2    50   ~ 0
M16
Text HLabel 9650 1100 2    50   Input ~ 0
BUS0
Text HLabel 9650 1200 2    50   Input ~ 0
BUS1
Text HLabel 9650 1300 2    50   Input ~ 0
BUS2
Text HLabel 9650 1400 2    50   Input ~ 0
BUS3
Text HLabel 9650 1500 2    50   Input ~ 0
BUS4
Text HLabel 9650 1600 2    50   Input ~ 0
BUS5
Text HLabel 9650 1700 2    50   Input ~ 0
BUS6
Text HLabel 9650 1800 2    50   Input ~ 0
BUS7
Text HLabel 8250 3100 0    50   Input ~ 0
~MMU_OUT
Text HLabel 8250 3200 0    50   Input ~ 0
~MMU_IN
$Comp
L power:GND #PWR0299
U 1 1 5B09B18D
P 8250 3000
F 0 "#PWR0299" H 8250 2750 50  0001 C CNN
F 1 "GND" V 8255 2872 50  0000 R CNN
F 2 "" H 8250 3000 50  0001 C CNN
F 3 "" H 8250 3000 50  0001 C CNN
	1    8250 3000
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C83
U 1 1 5B09B193
P 8950 950
F 0 "C83" H 9042 996 50  0000 L CNN
F 1 "C_Small" H 9042 905 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 8950 950 50  0001 C CNN
F 3 "~" H 8950 950 50  0001 C CNN
	1    8950 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0300
U 1 1 5B09B19A
P 8950 850
F 0 "#PWR0300" H 8950 600 50  0001 C CNN
F 1 "GND" H 8955 677 50  0000 C CNN
F 2 "" H 8950 850 50  0001 C CNN
F 3 "" H 8950 850 50  0001 C CNN
	1    8950 850 
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U78
U 1 1 5B09B1A0
P 10800 2150
F 0 "U78" H 10800 2200 50  0000 C CNN
F 1 "628128" H 10800 2050 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 10800 2150 50  0001 C CNN
F 3 "" H 10800 2150 50  0001 C CNN
	1    10800 2150
	1    0    0    -1  
$EndComp
Text Label 10100 1100 2    50   ~ 0
M0
Text Label 10100 1200 2    50   ~ 0
M1
Text Label 10100 1300 2    50   ~ 0
M2
Text Label 10100 1400 2    50   ~ 0
M3
Text Label 10100 1500 2    50   ~ 0
M4
Text Label 10100 1600 2    50   ~ 0
M5
Text Label 10100 1700 2    50   ~ 0
M6
Text Label 10100 1800 2    50   ~ 0
M7
Text Label 10100 1900 2    50   ~ 0
M8
Text Label 10100 2000 2    50   ~ 0
M9
Text Label 10100 2100 2    50   ~ 0
M10
Text Label 10100 2200 2    50   ~ 0
M11
Text Label 10100 2300 2    50   ~ 0
M12
Text Label 10100 2400 2    50   ~ 0
M13
Text Label 10100 2500 2    50   ~ 0
M14
Text Label 10100 2600 2    50   ~ 0
M15
Text Label 10100 2700 2    50   ~ 0
M16
Text HLabel 11500 1100 2    50   Input ~ 0
BUS0
Text HLabel 11500 1200 2    50   Input ~ 0
BUS1
Text HLabel 11500 1300 2    50   Input ~ 0
BUS2
Text HLabel 11500 1400 2    50   Input ~ 0
BUS3
Text HLabel 11500 1500 2    50   Input ~ 0
BUS4
Text HLabel 11500 1600 2    50   Input ~ 0
BUS5
Text HLabel 11500 1700 2    50   Input ~ 0
BUS6
Text HLabel 11500 1800 2    50   Input ~ 0
BUS7
Text HLabel 10100 3100 0    50   Input ~ 0
~MMU_OUT
Text HLabel 10100 3200 0    50   Input ~ 0
~MMU_IN
$Comp
L power:GND #PWR0301
U 1 1 5B09B1C2
P 10100 3000
F 0 "#PWR0301" H 10100 2750 50  0001 C CNN
F 1 "GND" V 10105 2872 50  0000 R CNN
F 2 "" H 10100 3000 50  0001 C CNN
F 3 "" H 10100 3000 50  0001 C CNN
	1    10100 3000
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C85
U 1 1 5B09B1C8
P 10800 950
F 0 "C85" H 10892 996 50  0000 L CNN
F 1 "C_Small" H 10892 905 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 10800 950 50  0001 C CNN
F 3 "~" H 10800 950 50  0001 C CNN
	1    10800 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0302
U 1 1 5B09B1CF
P 10800 850
F 0 "#PWR0302" H 10800 600 50  0001 C CNN
F 1 "GND" H 10805 677 50  0000 C CNN
F 2 "" H 10800 850 50  0001 C CNN
F 3 "" H 10800 850 50  0001 C CNN
	1    10800 850 
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U73
U 1 1 5B09B347
P 5200 4750
F 0 "U73" H 5200 4800 50  0000 C CNN
F 1 "628128" H 5200 4650 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 5200 4750 50  0001 C CNN
F 3 "" H 5200 4750 50  0001 C CNN
	1    5200 4750
	1    0    0    -1  
$EndComp
Text Label 4500 3700 2    50   ~ 0
M0
Text Label 4500 3800 2    50   ~ 0
M1
Text Label 4500 3900 2    50   ~ 0
M2
Text Label 4500 4000 2    50   ~ 0
M3
Text Label 4500 4100 2    50   ~ 0
M4
Text Label 4500 4200 2    50   ~ 0
M5
Text Label 4500 4300 2    50   ~ 0
M6
Text Label 4500 4400 2    50   ~ 0
M7
Text Label 4500 4500 2    50   ~ 0
M8
Text Label 4500 4600 2    50   ~ 0
M9
Text Label 4500 4700 2    50   ~ 0
M10
Text Label 4500 4800 2    50   ~ 0
M11
Text Label 4500 4900 2    50   ~ 0
M12
Text Label 4500 5000 2    50   ~ 0
M13
Text Label 4500 5100 2    50   ~ 0
M14
Text Label 4500 5200 2    50   ~ 0
M15
Text Label 4500 5300 2    50   ~ 0
M16
Text HLabel 5900 3700 2    50   Input ~ 0
BUS0
Text HLabel 5900 3800 2    50   Input ~ 0
BUS1
Text HLabel 5900 3900 2    50   Input ~ 0
BUS2
Text HLabel 5900 4000 2    50   Input ~ 0
BUS3
Text HLabel 5900 4100 2    50   Input ~ 0
BUS4
Text HLabel 5900 4200 2    50   Input ~ 0
BUS5
Text HLabel 5900 4300 2    50   Input ~ 0
BUS6
Text HLabel 5900 4400 2    50   Input ~ 0
BUS7
Text HLabel 4500 5700 0    50   Input ~ 0
~MMU_OUT
Text HLabel 4500 5800 0    50   Input ~ 0
~MMU_IN
$Comp
L power:GND #PWR0303
U 1 1 5B09B369
P 4500 5600
F 0 "#PWR0303" H 4500 5350 50  0001 C CNN
F 1 "GND" V 4505 5472 50  0000 R CNN
F 2 "" H 4500 5600 50  0001 C CNN
F 3 "" H 4500 5600 50  0001 C CNN
	1    4500 5600
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C80
U 1 1 5B09B36F
P 5200 3550
F 0 "C80" H 5292 3596 50  0000 L CNN
F 1 "C_Small" H 5292 3505 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 5200 3550 50  0001 C CNN
F 3 "~" H 5200 3550 50  0001 C CNN
	1    5200 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0304
U 1 1 5B09B376
P 5200 3450
F 0 "#PWR0304" H 5200 3200 50  0001 C CNN
F 1 "GND" H 5205 3277 50  0000 C CNN
F 2 "" H 5200 3450 50  0001 C CNN
F 3 "" H 5200 3450 50  0001 C CNN
	1    5200 3450
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U75
U 1 1 5B09B37C
P 7050 4750
F 0 "U75" H 7050 4800 50  0000 C CNN
F 1 "628128" H 7050 4650 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 7050 4750 50  0001 C CNN
F 3 "" H 7050 4750 50  0001 C CNN
	1    7050 4750
	1    0    0    -1  
$EndComp
Text Label 6350 3700 2    50   ~ 0
M0
Text Label 6350 3800 2    50   ~ 0
M1
Text Label 6350 3900 2    50   ~ 0
M2
Text Label 6350 4000 2    50   ~ 0
M3
Text Label 6350 4100 2    50   ~ 0
M4
Text Label 6350 4200 2    50   ~ 0
M5
Text Label 6350 4300 2    50   ~ 0
M6
Text Label 6350 4400 2    50   ~ 0
M7
Text Label 6350 4500 2    50   ~ 0
M8
Text Label 6350 4600 2    50   ~ 0
M9
Text Label 6350 4700 2    50   ~ 0
M10
Text Label 6350 4800 2    50   ~ 0
M11
Text Label 6350 4900 2    50   ~ 0
M12
Text Label 6350 5000 2    50   ~ 0
M13
Text Label 6350 5100 2    50   ~ 0
M14
Text Label 6350 5200 2    50   ~ 0
M15
Text Label 6350 5300 2    50   ~ 0
M16
Text HLabel 7750 3700 2    50   Input ~ 0
BUS0
Text HLabel 7750 3800 2    50   Input ~ 0
BUS1
Text HLabel 7750 3900 2    50   Input ~ 0
BUS2
Text HLabel 7750 4000 2    50   Input ~ 0
BUS3
Text HLabel 7750 4100 2    50   Input ~ 0
BUS4
Text HLabel 7750 4200 2    50   Input ~ 0
BUS5
Text HLabel 7750 4300 2    50   Input ~ 0
BUS6
Text HLabel 7750 4400 2    50   Input ~ 0
BUS7
Text HLabel 6350 5700 0    50   Input ~ 0
~MMU_OUT
Text HLabel 6350 5800 0    50   Input ~ 0
~MMU_IN
$Comp
L power:GND #PWR0305
U 1 1 5B09B39E
P 6350 5600
F 0 "#PWR0305" H 6350 5350 50  0001 C CNN
F 1 "GND" V 6355 5472 50  0000 R CNN
F 2 "" H 6350 5600 50  0001 C CNN
F 3 "" H 6350 5600 50  0001 C CNN
	1    6350 5600
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C82
U 1 1 5B09B3A4
P 7050 3550
F 0 "C82" H 7142 3596 50  0000 L CNN
F 1 "C_Small" H 7142 3505 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 7050 3550 50  0001 C CNN
F 3 "~" H 7050 3550 50  0001 C CNN
	1    7050 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0306
U 1 1 5B09B3AB
P 7050 3450
F 0 "#PWR0306" H 7050 3200 50  0001 C CNN
F 1 "GND" H 7055 3277 50  0000 C CNN
F 2 "" H 7050 3450 50  0001 C CNN
F 3 "" H 7050 3450 50  0001 C CNN
	1    7050 3450
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U77
U 1 1 5B09B3B1
P 8950 4800
F 0 "U77" H 8950 4850 50  0000 C CNN
F 1 "628128" H 8950 4700 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 8950 4800 50  0001 C CNN
F 3 "" H 8950 4800 50  0001 C CNN
	1    8950 4800
	1    0    0    -1  
$EndComp
Text Label 8250 3750 2    50   ~ 0
M0
Text Label 8250 3850 2    50   ~ 0
M1
Text Label 8250 3950 2    50   ~ 0
M2
Text Label 8250 4050 2    50   ~ 0
M3
Text Label 8250 4150 2    50   ~ 0
M4
Text Label 8250 4250 2    50   ~ 0
M5
Text Label 8250 4350 2    50   ~ 0
M6
Text Label 8250 4450 2    50   ~ 0
M7
Text Label 8250 4550 2    50   ~ 0
M8
Text Label 8250 4650 2    50   ~ 0
M9
Text Label 8250 4750 2    50   ~ 0
M10
Text Label 8250 4850 2    50   ~ 0
M11
Text Label 8250 4950 2    50   ~ 0
M12
Text Label 8250 5050 2    50   ~ 0
M13
Text Label 8250 5150 2    50   ~ 0
M14
Text Label 8250 5250 2    50   ~ 0
M15
Text Label 8250 5350 2    50   ~ 0
M16
Text HLabel 9650 3750 2    50   Input ~ 0
BUS0
Text HLabel 9650 3850 2    50   Input ~ 0
BUS1
Text HLabel 9650 3950 2    50   Input ~ 0
BUS2
Text HLabel 9650 4050 2    50   Input ~ 0
BUS3
Text HLabel 9650 4150 2    50   Input ~ 0
BUS4
Text HLabel 9650 4250 2    50   Input ~ 0
BUS5
Text HLabel 9650 4350 2    50   Input ~ 0
BUS6
Text HLabel 9650 4450 2    50   Input ~ 0
BUS7
Text HLabel 8250 5750 0    50   Input ~ 0
~MMU_OUT
Text HLabel 8250 5850 0    50   Input ~ 0
~MMU_IN
$Comp
L power:GND #PWR0307
U 1 1 5B09B3D3
P 8250 5650
F 0 "#PWR0307" H 8250 5400 50  0001 C CNN
F 1 "GND" V 8255 5522 50  0000 R CNN
F 2 "" H 8250 5650 50  0001 C CNN
F 3 "" H 8250 5650 50  0001 C CNN
	1    8250 5650
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C84
U 1 1 5B09B3D9
P 8950 3600
F 0 "C84" H 9042 3646 50  0000 L CNN
F 1 "C_Small" H 9042 3555 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 8950 3600 50  0001 C CNN
F 3 "~" H 8950 3600 50  0001 C CNN
	1    8950 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0308
U 1 1 5B09B3E0
P 8950 3500
F 0 "#PWR0308" H 8950 3250 50  0001 C CNN
F 1 "GND" H 8955 3327 50  0000 C CNN
F 2 "" H 8950 3500 50  0001 C CNN
F 3 "" H 8950 3500 50  0001 C CNN
	1    8950 3500
	-1   0    0    1   
$EndComp
$Comp
L Memory_RAM:628128 U79
U 1 1 5B09B3E6
P 10800 4800
F 0 "U79" H 10800 4850 50  0000 C CNN
F 1 "628128" H 10800 4700 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 10800 4800 50  0001 C CNN
F 3 "" H 10800 4800 50  0001 C CNN
	1    10800 4800
	1    0    0    -1  
$EndComp
Text Label 10100 3750 2    50   ~ 0
M0
Text Label 10100 3850 2    50   ~ 0
M1
Text Label 10100 3950 2    50   ~ 0
M2
Text Label 10100 4050 2    50   ~ 0
M3
Text Label 10100 4150 2    50   ~ 0
M4
Text Label 10100 4250 2    50   ~ 0
M5
Text Label 10100 4350 2    50   ~ 0
M6
Text Label 10100 4450 2    50   ~ 0
M7
Text Label 10100 4550 2    50   ~ 0
M8
Text Label 10100 4650 2    50   ~ 0
M9
Text Label 10100 4750 2    50   ~ 0
M10
Text Label 10100 4850 2    50   ~ 0
M11
Text Label 10100 4950 2    50   ~ 0
M12
Text Label 10100 5050 2    50   ~ 0
M13
Text Label 10100 5150 2    50   ~ 0
M14
Text Label 10100 5250 2    50   ~ 0
M15
Text Label 10100 5350 2    50   ~ 0
M16
Text HLabel 11500 3750 2    50   Input ~ 0
BUS0
Text HLabel 11500 3850 2    50   Input ~ 0
BUS1
Text HLabel 11500 3950 2    50   Input ~ 0
BUS2
Text HLabel 11500 4050 2    50   Input ~ 0
BUS3
Text HLabel 11500 4150 2    50   Input ~ 0
BUS4
Text HLabel 11500 4250 2    50   Input ~ 0
BUS5
Text HLabel 11500 4350 2    50   Input ~ 0
BUS6
Text HLabel 11500 4450 2    50   Input ~ 0
BUS7
Text HLabel 10100 5750 0    50   Input ~ 0
~MMU_OUT
Text HLabel 10100 5850 0    50   Input ~ 0
~MMU_IN
$Comp
L power:GND #PWR0309
U 1 1 5B09B408
P 10100 5650
F 0 "#PWR0309" H 10100 5400 50  0001 C CNN
F 1 "GND" V 10105 5522 50  0000 R CNN
F 2 "" H 10100 5650 50  0001 C CNN
F 3 "" H 10100 5650 50  0001 C CNN
	1    10100 5650
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C86
U 1 1 5B09B40E
P 10800 3600
F 0 "C86" H 10892 3646 50  0000 L CNN
F 1 "C_Small" H 10892 3555 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 10800 3600 50  0001 C CNN
F 3 "~" H 10800 3600 50  0001 C CNN
	1    10800 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0310
U 1 1 5B09B415
P 10800 3500
F 0 "#PWR0310" H 10800 3250 50  0001 C CNN
F 1 "GND" H 10805 3327 50  0000 C CNN
F 2 "" H 10800 3500 50  0001 C CNN
F 3 "" H 10800 3500 50  0001 C CNN
	1    10800 3500
	-1   0    0    1   
$EndComp
Text Label 1800 3700 0    50   ~ 0
~SEL0
Text Label 1800 3800 0    50   ~ 0
~SEL1
Text Label 1800 3900 0    50   ~ 0
~SEL2
Text Label 1800 4000 0    50   ~ 0
~SEL3
Text Label 1800 4100 0    50   ~ 0
~SEL4
Text Label 1800 4200 0    50   ~ 0
~SEL5
Text Label 1800 4300 0    50   ~ 0
~SEL6
Text Label 1800 4400 0    50   ~ 0
~SEL7
Text Label 4500 2850 2    50   ~ 0
~SEL0
Text Label 6350 2850 2    50   ~ 0
~SEL1
Text Label 8250 2900 2    50   ~ 0
~SEL2
Text Label 10100 2900 2    50   ~ 0
~SEL3
Text Label 4500 5500 2    50   ~ 0
~SEL4
Text Label 6350 5500 2    50   ~ 0
~SEL5
Text Label 8250 5550 2    50   ~ 0
~SEL6
Text Label 10100 5550 2    50   ~ 0
~SEL7
$EndSCHEMATC
