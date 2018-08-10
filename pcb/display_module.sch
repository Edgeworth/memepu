EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 11 33
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
L 74xx:74LS139 U23
U 1 1 5B016052
P 1600 2200
F 0 "U23" H 1600 2567 50  0000 C CNN
F 1 "74LS139" H 1600 2476 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 1600 2200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS139" H 1600 2200 50  0001 C CNN
	1    1600 2200
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS139 U23
U 3 1 5B01669A
P 1850 1300
F 0 "U23" V 1750 1300 50  0000 C CNN
F 1 "74LS139" V 1950 1300 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 1850 1300 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS139" H 1850 1300 50  0001 C CNN
	3    1850 1300
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C34
U 1 1 5B017125
P 1800 1000
F 0 "C34" V 1571 1000 50  0000 C CNN
F 1 "0.1uF" V 1662 1000 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 1800 1000 50  0001 C CNN
F 3 "~" H 1800 1000 50  0001 C CNN
	1    1800 1000
	0    1    1    0   
$EndComp
Wire Wire Line
	2350 1300 2350 1000
Wire Wire Line
	2350 1000 1900 1000
Wire Wire Line
	1700 1000 1350 1000
Wire Wire Line
	1350 1000 1350 1300
$Comp
L power:GND #PWR0153
U 1 1 5B017D87
P 1350 1300
F 0 "#PWR0153" H 1350 1050 50  0001 C CNN
F 1 "GND" V 1355 1172 50  0000 R CNN
F 2 "" H 1350 1300 50  0001 C CNN
F 3 "" H 1350 1300 50  0001 C CNN
	1    1350 1300
	0    1    1    0   
$EndComp
Connection ~ 1350 1300
$Comp
L power:VCC #PWR0154
U 1 1 5B017F36
P 2350 1300
F 0 "#PWR0154" H 2350 1150 50  0001 C CNN
F 1 "VCC" V 2367 1428 50  0000 L CNN
F 2 "" H 2350 1300 50  0001 C CNN
F 3 "" H 2350 1300 50  0001 C CNN
	1    2350 1300
	0    1    1    0   
$EndComp
Connection ~ 2350 1300
$Comp
L power:GND #PWR0155
U 1 1 5B019BEB
P 1100 2400
F 0 "#PWR0155" H 1100 2150 50  0001 C CNN
F 1 "GND" V 1105 2272 50  0000 R CNN
F 2 "" H 1100 2400 50  0001 C CNN
F 3 "" H 1100 2400 50  0001 C CNN
	1    1100 2400
	0    1    1    0   
$EndComp
Text Notes 1200 3350 0    50   ~ 0
Two JK flipflops form a 2 bit binary counter
$Comp
L Display_Character:HDSP-7803 U25
U 1 1 5B029BDE
P 3100 2250
F 0 "U25" H 3100 2917 50  0000 C CNN
F 1 "HDSP-7803" H 3100 2826 50  0000 C CNN
F 2 "Display_7Segment:HDSP-7801" H 3100 1700 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 3100 2250 50  0001 C CNN
	1    3100 2250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x03 SW5
U 1 1 5B02B242
P 1100 4250
F 0 "SW5" V 1146 4120 50  0000 R CNN
F 1 "SW_DIP_x03" V 1055 4120 50  0000 R CNN
F 2 "Button_Switch_THT:SW_DIP_SPSTx03_Slide_9.78x9.8mm_W7.62mm_P2.54mm" H 1100 4250 50  0001 C CNN
F 3 "" H 1100 4250 50  0001 C CNN
	1    1100 4250
	0    -1   -1   0   
$EndComp
$Comp
L Display_Character:HDSP-7803 U26
U 1 1 5B02CD83
P 3900 2250
F 0 "U26" H 3900 2917 50  0000 C CNN
F 1 "HDSP-7803" H 3900 2826 50  0000 C CNN
F 2 "Display_7Segment:HDSP-7801" H 3900 1700 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 3900 2250 50  0001 C CNN
	1    3900 2250
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:HDSP-7803 U27
U 1 1 5B02D341
P 4700 2250
F 0 "U27" H 4700 2917 50  0000 C CNN
F 1 "HDSP-7803" H 4700 2826 50  0000 C CNN
F 2 "Display_7Segment:HDSP-7801" H 4700 1700 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 4700 2250 50  0001 C CNN
	1    4700 2250
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:HDSP-7803 U28
U 1 1 5B02D694
P 5500 2250
F 0 "U28" H 5500 2917 50  0000 C CNN
F 1 "HDSP-7803" H 5500 2826 50  0000 C CNN
F 2 "Display_7Segment:HDSP-7801" H 5500 1700 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 5500 2250 50  0001 C CNN
	1    5500 2250
	1    0    0    -1  
$EndComp
Text Label 2400 2100 0    50   ~ 0
L0
Text Label 2400 2200 0    50   ~ 0
L1
Text Label 2400 2300 0    50   ~ 0
L2
Text Label 2400 2400 0    50   ~ 0
L3
Text Label 3400 2550 0    50   ~ 0
L0
Wire Wire Line
	3400 2550 3400 2650
Wire Wire Line
	4200 2550 4200 2650
Wire Wire Line
	5000 2550 5000 2650
Wire Wire Line
	5800 2550 5800 2650
Text Label 4200 2550 0    50   ~ 0
L1
Text Label 5000 2550 0    50   ~ 0
L2
Text Label 5800 2550 0    50   ~ 0
L3
Text Label 4150 3550 0    50   ~ 0
O0
Text Label 4150 3650 0    50   ~ 0
O1
Text Label 4150 3750 0    50   ~ 0
O2
Text Label 4150 3850 0    50   ~ 0
O3
Text Label 4150 3950 0    50   ~ 0
O4
Text Label 4150 4050 0    50   ~ 0
O5
Text Label 4150 4150 0    50   ~ 0
O6
Text Label 4150 4250 0    50   ~ 0
O7
Text Label 2800 1950 2    50   ~ 0
O0
Text Label 2800 2050 2    50   ~ 0
O1
Text Label 2800 2150 2    50   ~ 0
O2
Text Label 2800 2250 2    50   ~ 0
O3
Text Label 2800 2350 2    50   ~ 0
O4
Text Label 2800 2450 2    50   ~ 0
O5
Text Label 2800 2550 2    50   ~ 0
O6
Text Label 2800 2650 2    50   ~ 0
O7
Text Label 3600 1950 2    50   ~ 0
O0
Text Label 3600 2050 2    50   ~ 0
O1
Text Label 3600 2150 2    50   ~ 0
O2
Text Label 3600 2250 2    50   ~ 0
O3
Text Label 3600 2350 2    50   ~ 0
O4
Text Label 3600 2450 2    50   ~ 0
O5
Text Label 3600 2550 2    50   ~ 0
O6
Text Label 3600 2650 2    50   ~ 0
O7
Text Label 4400 1950 2    50   ~ 0
O0
Text Label 4400 2050 2    50   ~ 0
O1
Text Label 4400 2150 2    50   ~ 0
O2
Text Label 4400 2250 2    50   ~ 0
O3
Text Label 4400 2350 2    50   ~ 0
O4
Text Label 4400 2450 2    50   ~ 0
O5
Text Label 4400 2550 2    50   ~ 0
O6
Text Label 4400 2650 2    50   ~ 0
O7
Text Label 5200 1950 2    50   ~ 0
O0
Text Label 5200 2050 2    50   ~ 0
O1
Text Label 5200 2150 2    50   ~ 0
O2
Text Label 5200 2250 2    50   ~ 0
O3
Text Label 5200 2350 2    50   ~ 0
O4
Text Label 5200 2450 2    50   ~ 0
O5
Text Label 5200 2550 2    50   ~ 0
O6
Text Label 5200 2650 2    50   ~ 0
O7
$Comp
L power:VCC #PWR0156
U 1 1 5B0394DF
P 3750 3350
F 0 "#PWR0156" H 3750 3200 50  0001 C CNN
F 1 "VCC" H 3767 3523 50  0000 C CNN
F 2 "" H 3750 3350 50  0001 C CNN
F 3 "" H 3750 3350 50  0001 C CNN
	1    3750 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0157
U 1 1 5B039CBA
P 3750 5550
F 0 "#PWR0157" H 3750 5300 50  0001 C CNN
F 1 "GND" H 3755 5377 50  0000 C CNN
F 2 "" H 3750 5550 50  0001 C CNN
F 3 "" H 3750 5550 50  0001 C CNN
	1    3750 5550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C35
U 1 1 5B03AAB7
P 4200 3150
F 0 "C35" H 4108 3104 50  0000 R CNN
F 1 "0.1uF" H 4108 3195 50  0000 R CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 4200 3150 50  0001 C CNN
F 3 "~" H 4200 3150 50  0001 C CNN
	1    4200 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0158
U 1 1 5B03F28E
P 3350 5350
F 0 "#PWR0158" H 3350 5100 50  0001 C CNN
F 1 "GND" V 3355 5222 50  0000 R CNN
F 2 "" H 3350 5350 50  0001 C CNN
F 3 "" H 3350 5350 50  0001 C CNN
	1    3350 5350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0159
U 1 1 5B040B10
P 3350 5250
F 0 "#PWR0159" H 3350 5000 50  0001 C CNN
F 1 "GND" V 3355 5122 50  0000 R CNN
F 2 "" H 3350 5250 50  0001 C CNN
F 3 "" H 3350 5250 50  0001 C CNN
	1    3350 5250
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0160
U 1 1 5B040FF2
P 3350 5150
F 0 "#PWR0160" H 3350 5000 50  0001 C CNN
F 1 "VCC" V 3368 5277 50  0000 L CNN
F 2 "" H 3350 5150 50  0001 C CNN
F 3 "" H 3350 5150 50  0001 C CNN
	1    3350 5150
	0    -1   -1   0   
$EndComp
Text HLabel 2100 3550 0    50   Input ~ 0
BUS0
Text HLabel 2100 3650 0    50   Input ~ 0
BUS1
Text HLabel 2100 3750 0    50   Input ~ 0
BUS2
Text HLabel 2100 3850 0    50   Input ~ 0
BUS3
Text HLabel 2100 3950 0    50   Input ~ 0
BUS4
Text HLabel 2100 4050 0    50   Input ~ 0
BUS5
Text HLabel 2100 4150 0    50   Input ~ 0
BUS6
Text HLabel 2100 4250 0    50   Input ~ 0
BUS7
Wire Wire Line
	2650 3550 3350 3550
Wire Wire Line
	2650 3650 3350 3650
Wire Wire Line
	2650 3750 3350 3750
Wire Wire Line
	2650 3850 3350 3850
Wire Wire Line
	2650 3950 3350 3950
Wire Wire Line
	2650 4050 3350 4050
Wire Wire Line
	2650 4150 3350 4150
Wire Wire Line
	2650 4250 3350 4250
Text HLabel 2100 4450 0    50   Input ~ 0
DISP_IN
$Comp
L Device:R R33
U 1 1 5B064869
P 2000 5000
F 0 "R33" V 1900 5000 50  0000 C CNN
F 1 "100K" V 2000 5000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1930 5000 50  0001 C CNN
F 3 "~" H 2000 5000 50  0001 C CNN
	1    2000 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R34
U 1 1 5B067DBC
P 2200 5000
F 0 "R34" V 2100 5000 50  0000 C CNN
F 1 "100K" V 2200 5000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2130 5000 50  0001 C CNN
F 3 "~" H 2200 5000 50  0001 C CNN
	1    2200 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R35
U 1 1 5B068448
P 2400 5000
F 0 "R35" V 2300 5000 50  0000 C CNN
F 1 "100K" V 2400 5000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2330 5000 50  0001 C CNN
F 3 "~" H 2400 5000 50  0001 C CNN
	1    2400 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 4550 2850 4550
Wire Wire Line
	2850 4550 2850 4650
Wire Wire Line
	2900 4700 2900 4650
Wire Wire Line
	2900 4650 3350 4650
$Comp
L power:VCC #PWR0162
U 1 1 5B0742D0
P 900 3950
F 0 "#PWR0162" H 900 3800 50  0001 C CNN
F 1 "VCC" H 917 4123 50  0000 C CNN
F 2 "" H 900 3950 50  0001 C CNN
F 3 "" H 900 3950 50  0001 C CNN
	1    900  3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  3950 1000 3950
Connection ~ 900  3950
Wire Wire Line
	1000 3950 1100 3950
Connection ~ 1000 3950
Wire Wire Line
	900  4550 900  4650
Wire Wire Line
	900  4650 2000 4650
Wire Wire Line
	1000 4550 1000 4700
Wire Wire Line
	1000 4700 2200 4700
Wire Wire Line
	1100 4550 1100 4750
Wire Wire Line
	1100 4750 2400 4750
Wire Wire Line
	2000 4650 2000 4850
Connection ~ 2000 4650
Wire Wire Line
	2000 4650 2850 4650
Wire Wire Line
	2200 4700 2200 4850
Connection ~ 2200 4700
Wire Wire Line
	2200 4700 2900 4700
Wire Wire Line
	2400 4750 2400 4850
Connection ~ 2400 4750
Wire Wire Line
	2400 4750 3350 4750
$Comp
L power:GND #PWR0163
U 1 1 5B07E43B
P 2000 5150
F 0 "#PWR0163" H 2000 4900 50  0001 C CNN
F 1 "GND" H 2005 4977 50  0000 C CNN
F 2 "" H 2000 5150 50  0001 C CNN
F 3 "" H 2000 5150 50  0001 C CNN
	1    2000 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 5150 2200 5150
Connection ~ 2000 5150
Wire Wire Line
	2200 5150 2400 5150
Connection ~ 2200 5150
$Comp
L Device:R R36
U 1 1 5B091D6D
P 2250 2100
F 0 "R36" V 2200 1950 50  0000 C CNN
F 1 "100" V 2250 2100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2180 2100 50  0001 C CNN
F 3 "~" H 2250 2100 50  0001 C CNN
	1    2250 2100
	0    1    1    0   
$EndComp
$Comp
L Device:R R37
U 1 1 5B092FA5
P 2250 2200
F 0 "R37" V 2200 2050 50  0000 C CNN
F 1 "100" V 2250 2200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2180 2200 50  0001 C CNN
F 3 "~" H 2250 2200 50  0001 C CNN
	1    2250 2200
	0    1    1    0   
$EndComp
$Comp
L Device:R R38
U 1 1 5B0930D3
P 2250 2300
F 0 "R38" V 2200 2150 50  0000 C CNN
F 1 "100" V 2250 2300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2180 2300 50  0001 C CNN
F 3 "~" H 2250 2300 50  0001 C CNN
	1    2250 2300
	0    1    1    0   
$EndComp
$Comp
L Device:R R39
U 1 1 5B093278
P 2250 2400
F 0 "R39" V 2200 2250 50  0000 C CNN
F 1 "100" V 2250 2400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2180 2400 50  0001 C CNN
F 3 "~" H 2250 2400 50  0001 C CNN
	1    2250 2400
	0    1    1    0   
$EndComp
$Sheet
S 2100 3450 550  1100
U 5B043D5C
F0 "sheet5B043D48" 50
F1 "register.sch" 50
F2 "REG_IN" I L 2100 4450 50 
F3 "I0" I L 2100 3550 50 
F4 "I1" I L 2100 3650 50 
F5 "I2" I L 2100 3750 50 
F6 "I3" I L 2100 3850 50 
F7 "I4" I L 2100 3950 50 
F8 "I5" I L 2100 4050 50 
F9 "I6" I L 2100 4150 50 
F10 "I7" I L 2100 4250 50 
F11 "~REG_OUT" I R 2650 4350 50 
F12 "O0" I R 2650 3550 50 
F13 "O1" I R 2650 3650 50 
F14 "O2" I R 2650 3750 50 
F15 "O3" I R 2650 3850 50 
F16 "O4" I R 2650 3950 50 
F17 "O5" I R 2650 4050 50 
F18 "O6" I R 2650 4150 50 
F19 "O7" I R 2650 4250 50 
$EndSheet
$Comp
L power:GND #PWR049
U 1 1 5B0A97E2
P 2650 4350
F 0 "#PWR049" H 2650 4100 50  0001 C CNN
F 1 "GND" H 2655 4177 50  0000 C CNN
F 2 "" H 2650 4350 50  0001 C CNN
F 3 "" H 2650 4350 50  0001 C CNN
	1    2650 4350
	0    -1   -1   0   
$EndComp
$Comp
L Memory_EEPROM:28C256 U24
U 1 1 5B5448BD
P 3750 4450
F 0 "U24" H 3750 4400 50  0000 C CNN
F 1 "28C256" H 3850 4200 50  0000 C CNN
F 2 "Package_DIP:DIP-28_W15.24mm_Socket" H 3750 4450 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc0006.pdf" H 3750 4450 50  0001 C CNN
	1    3750 4450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0461
U 1 1 5B548238
P 3350 4850
F 0 "#PWR0461" H 3350 4600 50  0001 C CNN
F 1 "GND" V 3355 4722 50  0000 R CNN
F 2 "" H 3350 4850 50  0001 C CNN
F 3 "" H 3350 4850 50  0001 C CNN
	1    3350 4850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0462
U 1 1 5B5482D9
P 3350 4950
F 0 "#PWR0462" H 3350 4700 50  0001 C CNN
F 1 "GND" V 3355 4822 50  0000 R CNN
F 2 "" H 3350 4950 50  0001 C CNN
F 3 "" H 3350 4950 50  0001 C CNN
	1    3350 4950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0469
U 1 1 5B54AF62
P 4200 3050
F 0 "#PWR0469" H 4200 2800 50  0001 C CNN
F 1 "GND" H 4205 2877 50  0000 C CNN
F 2 "" H 4200 3050 50  0001 C CNN
F 3 "" H 4200 3050 50  0001 C CNN
	1    4200 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	3750 3350 4200 3350
Wire Wire Line
	4200 3350 4200 3250
Connection ~ 3750 3350
Text HLabel 1100 2100 0    50   Input ~ 0
DISP_CLK0
Text HLabel 1100 2200 0    50   Input ~ 0
DISP_CLK1
Text HLabel 3350 4350 0    50   Input ~ 0
DISP_CLK0
Text HLabel 3350 4450 0    50   Input ~ 0
DISP_CLK1
$EndSCHEMATC
