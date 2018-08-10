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
P 6900 1650
F 0 "U23" H 6900 2017 50  0000 C CNN
F 1 "74LS139" H 6900 1926 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 6900 1650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS139" H 6900 1650 50  0001 C CNN
	1    6900 1650
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS139 U23
U 3 1 5B01669A
P 7150 750
F 0 "U23" V 7050 750 50  0000 C CNN
F 1 "74LS139" V 7250 750 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 7150 750 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS139" H 7150 750 50  0001 C CNN
	3    7150 750 
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C34
U 1 1 5B017125
P 7100 450
F 0 "C34" V 6871 450 50  0000 C CNN
F 1 "0.1uF" V 6962 450 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 7100 450 50  0001 C CNN
F 3 "~" H 7100 450 50  0001 C CNN
	1    7100 450 
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 750  7650 450 
Wire Wire Line
	7650 450  7200 450 
Wire Wire Line
	7000 450  6650 450 
Wire Wire Line
	6650 450  6650 750 
$Comp
L power:GND #PWR0153
U 1 1 5B017D87
P 6650 750
F 0 "#PWR0153" H 6650 500 50  0001 C CNN
F 1 "GND" V 6655 622 50  0000 R CNN
F 2 "" H 6650 750 50  0001 C CNN
F 3 "" H 6650 750 50  0001 C CNN
	1    6650 750 
	0    1    1    0   
$EndComp
Connection ~ 6650 750 
$Comp
L power:VCC #PWR0154
U 1 1 5B017F36
P 7650 750
F 0 "#PWR0154" H 7650 600 50  0001 C CNN
F 1 "VCC" V 7667 878 50  0000 L CNN
F 2 "" H 7650 750 50  0001 C CNN
F 3 "" H 7650 750 50  0001 C CNN
	1    7650 750 
	0    1    1    0   
$EndComp
Connection ~ 7650 750 
$Comp
L power:GND #PWR0155
U 1 1 5B019BEB
P 6400 1850
F 0 "#PWR0155" H 6400 1600 50  0001 C CNN
F 1 "GND" V 6405 1722 50  0000 R CNN
F 2 "" H 6400 1850 50  0001 C CNN
F 3 "" H 6400 1850 50  0001 C CNN
	1    6400 1850
	0    1    1    0   
$EndComp
Text Notes 5250 2950 0    50   ~ 0
Two JK flipflops form a 2 bit binary counter
$Comp
L Display_Character:HDSP-7803 U25
U 1 1 5B029BDE
P 8400 1700
F 0 "U25" H 8400 2367 50  0000 C CNN
F 1 "HDSP-7803" H 8400 2276 50  0000 C CNN
F 2 "Display_7Segment:HDSP-7801" H 8400 1150 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 8400 1700 50  0001 C CNN
	1    8400 1700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x03 SW5
U 1 1 5B02B242
P 5150 3850
F 0 "SW5" V 5196 3720 50  0000 R CNN
F 1 "SW_DIP_x03" V 5105 3720 50  0000 R CNN
F 2 "Button_Switch_THT:SW_DIP_SPSTx03_Slide_9.78x9.8mm_W7.62mm_P2.54mm" H 5150 3850 50  0001 C CNN
F 3 "" H 5150 3850 50  0001 C CNN
	1    5150 3850
	0    -1   -1   0   
$EndComp
$Comp
L Display_Character:HDSP-7803 U26
U 1 1 5B02CD83
P 9200 1700
F 0 "U26" H 9200 2367 50  0000 C CNN
F 1 "HDSP-7803" H 9200 2276 50  0000 C CNN
F 2 "Display_7Segment:HDSP-7801" H 9200 1150 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 9200 1700 50  0001 C CNN
	1    9200 1700
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:HDSP-7803 U27
U 1 1 5B02D341
P 10000 1700
F 0 "U27" H 10000 2367 50  0000 C CNN
F 1 "HDSP-7803" H 10000 2276 50  0000 C CNN
F 2 "Display_7Segment:HDSP-7801" H 10000 1150 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 10000 1700 50  0001 C CNN
	1    10000 1700
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:HDSP-7803 U28
U 1 1 5B02D694
P 10800 1700
F 0 "U28" H 10800 2367 50  0000 C CNN
F 1 "HDSP-7803" H 10800 2276 50  0000 C CNN
F 2 "Display_7Segment:HDSP-7801" H 10800 1150 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 10800 1700 50  0001 C CNN
	1    10800 1700
	1    0    0    -1  
$EndComp
Text Label 7700 1550 0    50   ~ 0
L0
Text Label 7700 1650 0    50   ~ 0
L1
Text Label 7700 1750 0    50   ~ 0
L2
Text Label 7700 1850 0    50   ~ 0
L3
Text Label 8700 2000 0    50   ~ 0
L0
Wire Wire Line
	8700 2000 8700 2100
Wire Wire Line
	9500 2000 9500 2100
Wire Wire Line
	10300 2000 10300 2100
Wire Wire Line
	11100 2000 11100 2100
Text Label 9500 2000 0    50   ~ 0
L1
Text Label 10300 2000 0    50   ~ 0
L2
Text Label 11100 2000 0    50   ~ 0
L3
Text Label 8200 3150 0    50   ~ 0
O0
Text Label 8200 3250 0    50   ~ 0
O1
Text Label 8200 3350 0    50   ~ 0
O2
Text Label 8200 3450 0    50   ~ 0
O3
Text Label 8200 3550 0    50   ~ 0
O4
Text Label 8200 3650 0    50   ~ 0
O5
Text Label 8200 3750 0    50   ~ 0
O6
Text Label 8200 3850 0    50   ~ 0
O7
Text Label 8100 1400 2    50   ~ 0
O0
Text Label 8100 1500 2    50   ~ 0
O1
Text Label 8100 1600 2    50   ~ 0
O2
Text Label 8100 1700 2    50   ~ 0
O3
Text Label 8100 1800 2    50   ~ 0
O4
Text Label 8100 1900 2    50   ~ 0
O5
Text Label 8100 2000 2    50   ~ 0
O6
Text Label 8100 2100 2    50   ~ 0
O7
Text Label 8900 1400 2    50   ~ 0
O0
Text Label 8900 1500 2    50   ~ 0
O1
Text Label 8900 1600 2    50   ~ 0
O2
Text Label 8900 1700 2    50   ~ 0
O3
Text Label 8900 1800 2    50   ~ 0
O4
Text Label 8900 1900 2    50   ~ 0
O5
Text Label 8900 2000 2    50   ~ 0
O6
Text Label 8900 2100 2    50   ~ 0
O7
Text Label 9700 1400 2    50   ~ 0
O0
Text Label 9700 1500 2    50   ~ 0
O1
Text Label 9700 1600 2    50   ~ 0
O2
Text Label 9700 1700 2    50   ~ 0
O3
Text Label 9700 1800 2    50   ~ 0
O4
Text Label 9700 1900 2    50   ~ 0
O5
Text Label 9700 2000 2    50   ~ 0
O6
Text Label 9700 2100 2    50   ~ 0
O7
Text Label 10500 1400 2    50   ~ 0
O0
Text Label 10500 1500 2    50   ~ 0
O1
Text Label 10500 1600 2    50   ~ 0
O2
Text Label 10500 1700 2    50   ~ 0
O3
Text Label 10500 1800 2    50   ~ 0
O4
Text Label 10500 1900 2    50   ~ 0
O5
Text Label 10500 2000 2    50   ~ 0
O6
Text Label 10500 2100 2    50   ~ 0
O7
$Comp
L power:VCC #PWR0156
U 1 1 5B0394DF
P 7800 2950
F 0 "#PWR0156" H 7800 2800 50  0001 C CNN
F 1 "VCC" H 7817 3123 50  0000 C CNN
F 2 "" H 7800 2950 50  0001 C CNN
F 3 "" H 7800 2950 50  0001 C CNN
	1    7800 2950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0157
U 1 1 5B039CBA
P 7800 5150
F 0 "#PWR0157" H 7800 4900 50  0001 C CNN
F 1 "GND" H 7805 4977 50  0000 C CNN
F 2 "" H 7800 5150 50  0001 C CNN
F 3 "" H 7800 5150 50  0001 C CNN
	1    7800 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C35
U 1 1 5B03AAB7
P 8250 2750
F 0 "C35" H 8158 2704 50  0000 R CNN
F 1 "0.1uF" H 8158 2795 50  0000 R CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 8250 2750 50  0001 C CNN
F 3 "~" H 8250 2750 50  0001 C CNN
	1    8250 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0158
U 1 1 5B03F28E
P 7400 4950
F 0 "#PWR0158" H 7400 4700 50  0001 C CNN
F 1 "GND" V 7405 4822 50  0000 R CNN
F 2 "" H 7400 4950 50  0001 C CNN
F 3 "" H 7400 4950 50  0001 C CNN
	1    7400 4950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0159
U 1 1 5B040B10
P 7400 4850
F 0 "#PWR0159" H 7400 4600 50  0001 C CNN
F 1 "GND" V 7405 4722 50  0000 R CNN
F 2 "" H 7400 4850 50  0001 C CNN
F 3 "" H 7400 4850 50  0001 C CNN
	1    7400 4850
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0160
U 1 1 5B040FF2
P 7400 4750
F 0 "#PWR0160" H 7400 4600 50  0001 C CNN
F 1 "VCC" V 7418 4877 50  0000 L CNN
F 2 "" H 7400 4750 50  0001 C CNN
F 3 "" H 7400 4750 50  0001 C CNN
	1    7400 4750
	0    -1   -1   0   
$EndComp
Text HLabel 6150 3150 0    50   Input ~ 0
BUS0
Text HLabel 6150 3250 0    50   Input ~ 0
BUS1
Text HLabel 6150 3350 0    50   Input ~ 0
BUS2
Text HLabel 6150 3450 0    50   Input ~ 0
BUS3
Text HLabel 6150 3550 0    50   Input ~ 0
BUS4
Text HLabel 6150 3650 0    50   Input ~ 0
BUS5
Text HLabel 6150 3750 0    50   Input ~ 0
BUS6
Text HLabel 6150 3850 0    50   Input ~ 0
BUS7
Wire Wire Line
	6700 3150 7400 3150
Wire Wire Line
	6700 3250 7400 3250
Wire Wire Line
	6700 3350 7400 3350
Wire Wire Line
	6700 3450 7400 3450
Wire Wire Line
	6700 3550 7400 3550
Wire Wire Line
	6700 3650 7400 3650
Wire Wire Line
	6700 3750 7400 3750
Wire Wire Line
	6700 3850 7400 3850
Text HLabel 6150 4050 0    50   Input ~ 0
DISP_IN
$Comp
L Device:R R33
U 1 1 5B064869
P 6050 4600
F 0 "R33" V 5950 4600 50  0000 C CNN
F 1 "100K" V 6050 4600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5980 4600 50  0001 C CNN
F 3 "~" H 6050 4600 50  0001 C CNN
	1    6050 4600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R34
U 1 1 5B067DBC
P 6250 4600
F 0 "R34" V 6150 4600 50  0000 C CNN
F 1 "100K" V 6250 4600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6180 4600 50  0001 C CNN
F 3 "~" H 6250 4600 50  0001 C CNN
	1    6250 4600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R35
U 1 1 5B068448
P 6450 4600
F 0 "R35" V 6350 4600 50  0000 C CNN
F 1 "100K" V 6450 4600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6380 4600 50  0001 C CNN
F 3 "~" H 6450 4600 50  0001 C CNN
	1    6450 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 4150 6900 4150
Wire Wire Line
	6900 4150 6900 4250
Wire Wire Line
	6950 4300 6950 4250
Wire Wire Line
	6950 4250 7400 4250
$Comp
L power:VCC #PWR0162
U 1 1 5B0742D0
P 4950 3550
F 0 "#PWR0162" H 4950 3400 50  0001 C CNN
F 1 "VCC" H 4967 3723 50  0000 C CNN
F 2 "" H 4950 3550 50  0001 C CNN
F 3 "" H 4950 3550 50  0001 C CNN
	1    4950 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3550 5050 3550
Connection ~ 4950 3550
Wire Wire Line
	5050 3550 5150 3550
Connection ~ 5050 3550
Wire Wire Line
	4950 4150 4950 4250
Wire Wire Line
	4950 4250 6050 4250
Wire Wire Line
	5050 4150 5050 4300
Wire Wire Line
	5050 4300 6250 4300
Wire Wire Line
	5150 4150 5150 4350
Wire Wire Line
	5150 4350 6450 4350
Wire Wire Line
	6050 4250 6050 4450
Connection ~ 6050 4250
Wire Wire Line
	6050 4250 6900 4250
Wire Wire Line
	6250 4300 6250 4450
Connection ~ 6250 4300
Wire Wire Line
	6250 4300 6950 4300
Wire Wire Line
	6450 4350 6450 4450
Connection ~ 6450 4350
Wire Wire Line
	6450 4350 7400 4350
$Comp
L power:GND #PWR0163
U 1 1 5B07E43B
P 6050 4750
F 0 "#PWR0163" H 6050 4500 50  0001 C CNN
F 1 "GND" H 6055 4577 50  0000 C CNN
F 2 "" H 6050 4750 50  0001 C CNN
F 3 "" H 6050 4750 50  0001 C CNN
	1    6050 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4750 6250 4750
Connection ~ 6050 4750
Wire Wire Line
	6250 4750 6450 4750
Connection ~ 6250 4750
$Comp
L Device:R R36
U 1 1 5B091D6D
P 7550 1550
F 0 "R36" V 7500 1400 50  0000 C CNN
F 1 "100" V 7550 1550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7480 1550 50  0001 C CNN
F 3 "~" H 7550 1550 50  0001 C CNN
	1    7550 1550
	0    1    1    0   
$EndComp
$Comp
L Device:R R37
U 1 1 5B092FA5
P 7550 1650
F 0 "R37" V 7500 1500 50  0000 C CNN
F 1 "100" V 7550 1650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7480 1650 50  0001 C CNN
F 3 "~" H 7550 1650 50  0001 C CNN
	1    7550 1650
	0    1    1    0   
$EndComp
$Comp
L Device:R R38
U 1 1 5B0930D3
P 7550 1750
F 0 "R38" V 7500 1600 50  0000 C CNN
F 1 "100" V 7550 1750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7480 1750 50  0001 C CNN
F 3 "~" H 7550 1750 50  0001 C CNN
	1    7550 1750
	0    1    1    0   
$EndComp
$Comp
L Device:R R39
U 1 1 5B093278
P 7550 1850
F 0 "R39" V 7500 1700 50  0000 C CNN
F 1 "100" V 7550 1850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7480 1850 50  0001 C CNN
F 3 "~" H 7550 1850 50  0001 C CNN
	1    7550 1850
	0    1    1    0   
$EndComp
$Sheet
S 6150 3050 550  1100
U 5B043D5C
F0 "sheet5B043D48" 50
F1 "register.sch" 50
F2 "REG_IN" I L 6150 4050 50 
F3 "I0" I L 6150 3150 50 
F4 "I1" I L 6150 3250 50 
F5 "I2" I L 6150 3350 50 
F6 "I3" I L 6150 3450 50 
F7 "I4" I L 6150 3550 50 
F8 "I5" I L 6150 3650 50 
F9 "I6" I L 6150 3750 50 
F10 "I7" I L 6150 3850 50 
F11 "~REG_OUT" I R 6700 3950 50 
F12 "O0" I R 6700 3150 50 
F13 "O1" I R 6700 3250 50 
F14 "O2" I R 6700 3350 50 
F15 "O3" I R 6700 3450 50 
F16 "O4" I R 6700 3550 50 
F17 "O5" I R 6700 3650 50 
F18 "O6" I R 6700 3750 50 
F19 "O7" I R 6700 3850 50 
$EndSheet
$Comp
L power:GND #PWR049
U 1 1 5B0A97E2
P 6700 3950
F 0 "#PWR049" H 6700 3700 50  0001 C CNN
F 1 "GND" H 6705 3777 50  0000 C CNN
F 2 "" H 6700 3950 50  0001 C CNN
F 3 "" H 6700 3950 50  0001 C CNN
	1    6700 3950
	0    -1   -1   0   
$EndComp
$Comp
L Memory_EEPROM:28C256 U24
U 1 1 5B5448BD
P 7800 4050
F 0 "U24" H 7800 4000 50  0000 C CNN
F 1 "28C256" H 7900 3800 50  0000 C CNN
F 2 "Package_DIP:DIP-28_W15.24mm_Socket" H 7800 4050 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc0006.pdf" H 7800 4050 50  0001 C CNN
	1    7800 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0461
U 1 1 5B548238
P 7400 4450
F 0 "#PWR0461" H 7400 4200 50  0001 C CNN
F 1 "GND" V 7405 4322 50  0000 R CNN
F 2 "" H 7400 4450 50  0001 C CNN
F 3 "" H 7400 4450 50  0001 C CNN
	1    7400 4450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0462
U 1 1 5B5482D9
P 7400 4550
F 0 "#PWR0462" H 7400 4300 50  0001 C CNN
F 1 "GND" V 7405 4422 50  0000 R CNN
F 2 "" H 7400 4550 50  0001 C CNN
F 3 "" H 7400 4550 50  0001 C CNN
	1    7400 4550
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0469
U 1 1 5B54AF62
P 8250 2650
F 0 "#PWR0469" H 8250 2400 50  0001 C CNN
F 1 "GND" H 8255 2477 50  0000 C CNN
F 2 "" H 8250 2650 50  0001 C CNN
F 3 "" H 8250 2650 50  0001 C CNN
	1    8250 2650
	-1   0    0    1   
$EndComp
Wire Wire Line
	7800 2950 8250 2950
Wire Wire Line
	8250 2950 8250 2850
Connection ~ 7800 2950
Text HLabel 6400 1550 0    50   Input ~ 0
DISP_CLK0
Text HLabel 6400 1650 0    50   Input ~ 0
DISP_CLK1
Text HLabel 7400 3950 0    50   Input ~ 0
DISP_CLK0
Text HLabel 7400 4050 0    50   Input ~ 0
DISP_CLK1
$EndSCHEMATC
