EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 2 37
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
L Timer:LM555 U4
U 1 1 5ADF4FEB
P 5700 1600
F 0 "U4" H 5850 2000 50  0000 C CNN
F 1 "LM555 - Button Clock" H 5700 2300 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 5700 1600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm555.pdf" H 5700 1600 50  0001 C CNN
	1    5700 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C9
U 1 1 5ADF4FF2
P 5750 2450
F 0 "C9" H 5842 2496 50  0000 L CNN
F 1 "0.1uF" H 5842 2405 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 5750 2450 50  0001 C CNN
F 3 "~" H 5750 2450 50  0001 C CNN
	1    5750 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 2450 5850 2450
Wire Wire Line
	5650 2450 5200 2450
$Comp
L power:GND #PWR015
U 1 1 5ADF500C
P 5200 2450
F 0 "#PWR015" H 5200 2200 50  0001 C CNN
F 1 "GND" H 5205 2277 50  0000 C CNN
F 2 "" H 5200 2450 50  0001 C CNN
F 3 "" H 5200 2450 50  0001 C CNN
	1    5200 2450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5ADF5012
P 5700 2000
F 0 "#PWR017" H 5700 1750 50  0001 C CNN
F 1 "GND" H 5705 1827 50  0000 C CNN
F 2 "" H 5700 2000 50  0001 C CNN
F 3 "" H 5700 2000 50  0001 C CNN
	1    5700 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C8
U 1 1 5ADF501E
P 4800 1900
F 0 "C8" V 4571 1900 50  0000 C CNN
F 1 "10nF" V 4662 1900 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 4800 1900 50  0001 C CNN
F 3 "~" H 4800 1900 50  0001 C CNN
	1    4800 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5ADF5025
P 4800 2000
F 0 "#PWR013" H 4800 1750 50  0001 C CNN
F 1 "GND" V 4805 1872 50  0000 R CNN
F 2 "" H 4800 2000 50  0001 C CNN
F 3 "" H 4800 2000 50  0001 C CNN
	1    4800 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 1600 4800 1600
Wire Wire Line
	4800 1600 4800 1800
Wire Notes Line
	3900 650  3900 3200
Wire Notes Line
	3900 3200 7250 3200
Wire Notes Line
	7250 3200 7250 650 
Wire Notes Line
	7250 650  3900 650 
Text Label 6200 1400 0    50   ~ 0
BTN_CLK
Wire Wire Line
	6450 1800 6200 1800
$Comp
L power:GND #PWR012
U 1 1 5ADF5049
P 4350 2050
F 0 "#PWR012" H 4350 1800 50  0001 C CNN
F 1 "GND" H 4355 1877 50  0000 C CNN
F 2 "" H 4350 2050 50  0001 C CNN
F 3 "" H 4350 2050 50  0001 C CNN
	1    4350 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 1950 4350 2050
$Comp
L Switch:SW_Push SW2
U 1 1 5ADF3C8D
P 4350 1750
F 0 "SW2" H 4350 2035 50  0000 C CNN
F 1 "SW_Push" H 4350 1944 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H7.3mm" H 4350 1950 50  0001 C CNN
F 3 "" H 4350 1950 50  0001 C CNN
	1    4350 1750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4350 950  4350 1000
$Comp
L Device:R R10
U 1 1 5ADF6F9C
P 4350 1150
F 0 "R10" H 4280 1104 50  0000 R CNN
F 1 "100K" H 4280 1195 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4280 1150 50  0001 C CNN
F 3 "~" H 4350 1150 50  0001 C CNN
	1    4350 1150
	-1   0    0    1   
$EndComp
Wire Wire Line
	4350 1300 4350 1400
Wire Wire Line
	4350 1400 4350 1550
Connection ~ 4350 1400
Wire Wire Line
	4350 1400 5200 1400
$Comp
L Device:C_Small C11
U 1 1 5ADF5040
P 6450 1900
F 0 "C11" H 6358 1854 50  0000 R CNN
F 1 "0.1uF" H 6358 1945 50  0000 R CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 6450 1900 50  0001 C CNN
F 3 "~" H 6450 1900 50  0001 C CNN
	1    6450 1900
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR019
U 1 1 5ADFE1CA
P 6450 2000
F 0 "#PWR019" H 6450 1750 50  0001 C CNN
F 1 "GND" H 6455 1827 50  0000 C CNN
F 2 "" H 6450 2000 50  0001 C CNN
F 3 "" H 6450 2000 50  0001 C CNN
	1    6450 2000
	1    0    0    -1  
$EndComp
Connection ~ 6450 1800
Wire Wire Line
	6450 1600 6450 1800
Wire Wire Line
	6450 1600 6200 1600
Connection ~ 6450 1600
Wire Wire Line
	6650 1600 6450 1600
$Comp
L Device:R R11
U 1 1 5ADF5037
P 6650 1450
F 0 "R11" H 6720 1496 50  0000 L CNN
F 1 "1M" H 6720 1405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6580 1450 50  0001 C CNN
F 3 "~" H 6650 1450 50  0001 C CNN
	1    6650 1450
	1    0    0    -1  
$EndComp
Text Notes 4400 1350 0    20   ~ 0
On push, pullls TRIGGER down to GND,\nturning the output on. DISCHARGE is then\ndisconnected, allowing the cap to charge.
Text Notes 6500 1800 0    20   ~ 0
When button is pressed, C charges up\nuntil THRESHOLD is passed. The output\nis disabled, and it instantly discharges.\nCurrently set for 100ms ON time.\ndischarges turning 
Text Notes 5350 600  0    50   ~ 0
Button Clock\n
$Comp
L Device:R R4
U 1 1 5AE2A155
P 950 3950
F 0 "R4" H 1020 3996 50  0000 L CNN
F 1 "100K" H 1020 3905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 880 3950 50  0001 C CNN
F 3 "~" H 950 3950 50  0001 C CNN
	1    950  3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5AE2A2D1
P 1300 3950
F 0 "R5" H 1370 3996 50  0000 L CNN
F 1 "100K" H 1370 3905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1230 3950 50  0001 C CNN
F 3 "~" H 1300 3950 50  0001 C CNN
	1    1300 3950
	1    0    0    -1  
$EndComp
$Comp
L 74xx_IEEE:74151 U3
U 1 1 5AE2A47F
P 3950 4800
F 0 "U3" H 3950 5666 50  0000 C CNN
F 1 "74151" H 3950 5575 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 3950 4800 50  0001 C CNN
F 3 "" H 3950 4800 50  0001 C CNN
	1    3950 4800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x03 SW1
U 1 1 5AE2A76E
P 1150 6150
F 0 "SW1" H 1150 6617 50  0000 C CNN
F 1 "SW_DIP_x03 - Clock Source Select" H 1150 6526 50  0000 C CNN
F 2 "Button_Switch_THT:SW_DIP_SPSTx03_Slide_9.78x9.8mm_W7.62mm_P2.54mm" H 1150 6150 50  0001 C CNN
F 3 "" H 1150 6150 50  0001 C CNN
	1    1150 6150
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R9
U 1 1 5AE2F8E7
P 1650 3950
F 0 "R9" H 1720 3996 50  0000 L CNN
F 1 "100K" H 1720 3905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1580 3950 50  0001 C CNN
F 3 "~" H 1650 3950 50  0001 C CNN
	1    1650 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5AE2FAD9
P 1150 6450
F 0 "#PWR04" H 1150 6200 50  0001 C CNN
F 1 "GND" H 1155 6277 50  0000 C CNN
F 2 "" H 1150 6450 50  0001 C CNN
F 3 "" H 1150 6450 50  0001 C CNN
	1    1150 6450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5AE353DF
P 3100 4250
F 0 "#PWR010" H 3100 4000 50  0001 C CNN
F 1 "GND" H 3105 4077 50  0000 C CNN
F 2 "" H 3100 4250 50  0001 C CNN
F 3 "" H 3100 4250 50  0001 C CNN
	1    3100 4250
	0    1    1    0   
$EndComp
Text Label 3400 5300 2    50   ~ 0
ADJ_CLK
Text Label 3400 5400 2    50   ~ 0
BTN_CLK
$Comp
L Device:C_Small C7
U 1 1 5AE38673
P 1800 5750
F 0 "C7" V 1571 5750 50  0000 C CNN
F 1 "0.1uF" V 1662 5750 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 1800 5750 50  0001 C CNN
F 3 "~" H 1800 5750 50  0001 C CNN
	1    1800 5750
	-1   0    0    1   
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 5AE6D74C
P 8400 2050
F 0 "Y1" H 8400 2318 50  0000 C CNN
F 1 "12MHz" H 8400 2227 50  0000 C CNN
F 2 "Crystal:Crystal_HC49-U_Vertical" H 8400 2050 50  0001 C CNN
F 3 "~" H 8400 2050 50  0001 C CNN
	1    8400 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C12
U 1 1 5AE6D889
P 7950 2500
F 0 "C12" H 8042 2546 50  0000 L CNN
F 1 "27pF" H 8042 2455 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 7950 2500 50  0001 C CNN
F 3 "~" H 7950 2500 50  0001 C CNN
	1    7950 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C13
U 1 1 5AE6D8E9
P 8800 2500
F 0 "C13" H 8892 2546 50  0000 L CNN
F 1 "27pF" H 8892 2455 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 8800 2500 50  0001 C CNN
F 3 "~" H 8800 2500 50  0001 C CNN
	1    8800 2500
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U5
U 1 1 5AE6E8B5
P 8350 1200
F 0 "U5" H 8350 1517 50  0000 C CNN
F 1 "74HC04" H 8350 1426 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 8350 1200 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 8350 1200 50  0001 C CNN
	1    8350 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 5AE6E9D6
P 8400 1600
F 0 "R12" V 8193 1600 50  0000 C CNN
F 1 "1M" V 8284 1600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 8330 1600 50  0001 C CNN
F 3 "~" H 8400 1600 50  0001 C CNN
	1    8400 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	7950 2400 7950 2050
Wire Wire Line
	7950 1200 8050 1200
Wire Wire Line
	8650 1200 8800 1200
Wire Wire Line
	8800 1200 8800 1600
$Comp
L power:GND #PWR021
U 1 1 5AE736E3
P 7950 2600
F 0 "#PWR021" H 7950 2350 50  0001 C CNN
F 1 "GND" H 7955 2427 50  0000 C CNN
F 2 "" H 7950 2600 50  0001 C CNN
F 3 "" H 7950 2600 50  0001 C CNN
	1    7950 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5AE73739
P 8800 2600
F 0 "#PWR022" H 8800 2350 50  0001 C CNN
F 1 "GND" H 8805 2427 50  0000 C CNN
F 2 "" H 8800 2600 50  0001 C CNN
F 3 "" H 8800 2600 50  0001 C CNN
	1    8800 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 1600 8250 1600
Connection ~ 7950 1600
Wire Wire Line
	7950 1600 7950 1200
Wire Wire Line
	8550 1600 8800 1600
Wire Wire Line
	7950 2050 8250 2050
Connection ~ 7950 2050
Wire Wire Line
	7950 2050 7950 1600
Wire Wire Line
	8550 2050 8800 2050
Wire Wire Line
	8800 2050 8800 2400
Wire Wire Line
	950  6450 1050 6450
Wire Wire Line
	1150 6450 1050 6450
Connection ~ 1150 6450
Connection ~ 1050 6450
Wire Wire Line
	1300 4100 1050 4100
Wire Wire Line
	1650 4200 1150 4200
$Comp
L power:GND #PWR09
U 1 1 5AEC4517
P 1800 5850
F 0 "#PWR09" H 1800 5600 50  0001 C CNN
F 1 "GND" H 1805 5677 50  0000 C CNN
F 2 "" H 1800 5850 50  0001 C CNN
F 3 "" H 1800 5850 50  0001 C CNN
	1    1800 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5AEC45B5
P 1450 5650
F 0 "R8" V 1243 5650 50  0000 C CNN
F 1 "1M" V 1334 5650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 5650 50  0001 C CNN
F 3 "~" H 1450 5650 50  0001 C CNN
	1    1450 5650
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 5650 1600 5650
Connection ~ 1800 5650
Wire Wire Line
	1300 5650 1150 5650
Connection ~ 1150 5650
Wire Wire Line
	1150 5650 1150 5850
Wire Wire Line
	1050 4100 1050 5100
Wire Wire Line
	950  4100 950  4550
$Comp
L Device:C_Small C6
U 1 1 5AED5F66
P 1800 5200
F 0 "C6" V 1571 5200 50  0000 C CNN
F 1 "0.1uF" V 1662 5200 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 1800 5200 50  0001 C CNN
F 3 "~" H 1800 5200 50  0001 C CNN
	1    1800 5200
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5AED5F6D
P 1800 5300
F 0 "#PWR08" H 1800 5050 50  0001 C CNN
F 1 "GND" H 1805 5127 50  0000 C CNN
F 2 "" H 1800 5300 50  0001 C CNN
F 3 "" H 1800 5300 50  0001 C CNN
	1    1800 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5AED5F73
P 1450 5100
F 0 "R7" V 1243 5100 50  0000 C CNN
F 1 "1M" V 1334 5100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 5100 50  0001 C CNN
F 3 "~" H 1450 5100 50  0001 C CNN
	1    1450 5100
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 5100 1600 5100
Connection ~ 1800 5100
$Comp
L Device:C_Small C5
U 1 1 5AED7965
P 1800 4650
F 0 "C5" V 1571 4650 50  0000 C CNN
F 1 "0.1uF" V 1662 4650 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 1800 4650 50  0001 C CNN
F 3 "~" H 1800 4650 50  0001 C CNN
	1    1800 4650
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5AED796C
P 1800 4750
F 0 "#PWR07" H 1800 4500 50  0001 C CNN
F 1 "GND" H 1805 4577 50  0000 C CNN
F 2 "" H 1800 4750 50  0001 C CNN
F 3 "" H 1800 4750 50  0001 C CNN
	1    1800 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5AED7972
P 1450 4550
F 0 "R6" V 1243 4550 50  0000 C CNN
F 1 "1M" V 1334 4550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 4550 50  0001 C CNN
F 3 "~" H 1450 4550 50  0001 C CNN
	1    1450 4550
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 4550 1600 4550
Connection ~ 1800 4550
Wire Wire Line
	1650 4200 1650 4100
Connection ~ 1050 5100
Wire Wire Line
	1050 5100 1050 5850
Wire Wire Line
	950  4550 950  5850
$Comp
L Device:R R13
U 1 1 5AFB2532
P 8800 1800
F 0 "R13" H 8870 1846 50  0000 L CNN
F 1 "1K" H 8870 1755 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 8730 1800 50  0001 C CNN
F 3 "~" H 8800 1800 50  0001 C CNN
	1    8800 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 1600 8800 1650
Connection ~ 8800 1600
Wire Wire Line
	8800 1950 8800 2050
Connection ~ 8800 2050
$Comp
L 74xx:74HC04 U5
U 2 1 5AFC895D
P 9100 1200
F 0 "U5" H 9100 1517 50  0000 C CNN
F 1 "74HC04" H 9100 1426 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 9100 1200 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 9100 1200 50  0001 C CNN
	2    9100 1200
	1    0    0    -1  
$EndComp
Connection ~ 8800 1200
Text Label 9400 1200 0    50   ~ 0
12MHZ_CLK
Wire Notes Line
	7600 650  7600 3200
Wire Notes Line
	7600 3200 10050 3200
Wire Notes Line
	10050 3200 10050 650 
Text Notes 8500 600  0    50   ~ 0
12 MHz Clock
Text Notes 8000 1550 0    20   ~ 0
Resistor puts inverter\ninto linear region for\namplification.
Text Notes 2100 3300 0    50   ~ 0
Clock Selector
Wire Notes Line
	550  3350 4950 3350
Wire Notes Line
	550  7350 4950 7350
$Comp
L 74xx:74HC04 U5
U 7 1 5B093398
P 9650 2100
F 0 "U5" H 9880 2146 50  0000 L CNN
F 1 "74HC04" H 9880 2055 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 9650 2100 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 9650 2100 50  0001 C CNN
	7    9650 2100
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0101
U 1 1 5B094A12
P 9650 1600
F 0 "#PWR0101" H 9650 1450 50  0001 C CNN
F 1 "VCC" H 9667 1773 50  0000 C CNN
F 2 "" H 9650 1600 50  0001 C CNN
F 3 "" H 9650 1600 50  0001 C CNN
	1    9650 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5B0964B9
P 9650 2600
F 0 "#PWR0104" H 9650 2350 50  0001 C CNN
F 1 "GND" H 9655 2427 50  0000 C CNN
F 2 "" H 9650 2600 50  0001 C CNN
F 3 "" H 9650 2600 50  0001 C CNN
	1    9650 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C10
U 1 1 5B09FE3C
P 3450 3900
F 0 "C10" H 3542 3946 50  0000 L CNN
F 1 "0.1uF" H 3542 3855 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 3450 3900 50  0001 C CNN
F 3 "~" H 3450 3900 50  0001 C CNN
	1    3450 3900
	-1   0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0112
U 1 1 5B0AB5CC
P 3450 3800
F 0 "#PWR0112" H 3450 3650 50  0001 C CNN
F 1 "VCC" H 3467 3973 50  0000 C CNN
F 2 "" H 3450 3800 50  0001 C CNN
F 3 "" H 3450 3800 50  0001 C CNN
	1    3450 3800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0114
U 1 1 5B0AEC1F
P 4350 950
F 0 "#PWR0114" H 4350 800 50  0001 C CNN
F 1 "VCC" H 4367 1123 50  0000 C CNN
F 2 "" H 4350 950 50  0001 C CNN
F 3 "" H 4350 950 50  0001 C CNN
	1    4350 950 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0115
U 1 1 5B0AF305
P 5700 1200
F 0 "#PWR0115" H 5700 1050 50  0001 C CNN
F 1 "VCC" H 5717 1373 50  0000 C CNN
F 2 "" H 5700 1200 50  0001 C CNN
F 3 "" H 5700 1200 50  0001 C CNN
	1    5700 1200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0116
U 1 1 5B0AF94F
P 6650 1300
F 0 "#PWR0116" H 6650 1150 50  0001 C CNN
F 1 "VCC" H 6667 1473 50  0000 C CNN
F 2 "" H 6650 1300 50  0001 C CNN
F 3 "" H 6650 1300 50  0001 C CNN
	1    6650 1300
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0118
U 1 1 5B0B117B
P 6100 2450
F 0 "#PWR0118" H 6100 2300 50  0001 C CNN
F 1 "VCC" V 6117 2578 50  0000 L CNN
F 2 "" H 6100 2450 50  0001 C CNN
F 3 "" H 6100 2450 50  0001 C CNN
	1    6100 2450
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0119
U 1 1 5B0B7B5D
P 1650 3800
F 0 "#PWR0119" H 1650 3650 50  0001 C CNN
F 1 "VCC" H 1667 3973 50  0000 C CNN
F 2 "" H 1650 3800 50  0001 C CNN
F 3 "" H 1650 3800 50  0001 C CNN
	1    1650 3800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0120
U 1 1 5B0B8534
P 1300 3800
F 0 "#PWR0120" H 1300 3650 50  0001 C CNN
F 1 "VCC" H 1317 3973 50  0000 C CNN
F 2 "" H 1300 3800 50  0001 C CNN
F 3 "" H 1300 3800 50  0001 C CNN
	1    1300 3800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0121
U 1 1 5B0B9AA9
P 950 3800
F 0 "#PWR0121" H 950 3650 50  0001 C CNN
F 1 "VCC" H 967 3973 50  0000 C CNN
F 2 "" H 950 3800 50  0001 C CNN
F 3 "" H 950 3800 50  0001 C CNN
	1    950  3800
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C14
U 1 1 5B0BB303
P 9250 2100
F 0 "C14" H 9342 2146 50  0000 L CNN
F 1 "0.1uF" H 9342 2055 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 9250 2100 50  0001 C CNN
F 3 "~" H 9250 2100 50  0001 C CNN
	1    9250 2100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9250 2000 9250 1600
Wire Wire Line
	9250 1600 9650 1600
Connection ~ 9650 1600
Wire Wire Line
	9250 2200 9250 2600
Wire Wire Line
	9250 2600 9650 2600
Connection ~ 9650 2600
Wire Wire Line
	3450 4000 3400 4000
$Comp
L power:VCC #PWR0122
U 1 1 5B0D7A44
P 5200 1800
F 0 "#PWR0122" H 5200 1650 50  0001 C CNN
F 1 "VCC" V 5218 1927 50  0000 L CNN
F 2 "" H 5200 1800 50  0001 C CNN
F 3 "" H 5200 1800 50  0001 C CNN
	1    5200 1800
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74HC14 U2
U 2 1 5B0FAF2B
P 2400 5100
F 0 "U2" H 2400 5417 50  0000 C CNN
F 1 "74HC14" H 2400 5326 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 2400 5100 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 2400 5100 50  0001 C CNN
	2    2400 5100
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U2
U 3 1 5B0FBD9B
P 2400 5650
F 0 "U2" H 2400 5967 50  0000 C CNN
F 1 "74HC14" H 2400 5876 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 2400 5650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 2400 5650 50  0001 C CNN
	3    2400 5650
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U2
U 7 1 5B0FD3BF
P 2150 6600
F 0 "U2" V 1783 6600 50  0000 C CNN
F 1 "74HC14" V 1874 6600 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 2150 6600 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 2150 6600 50  0001 C CNN
	7    2150 6600
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 5650 2100 5650
Wire Wire Line
	1800 5100 2100 5100
Wire Wire Line
	1800 4550 2100 4550
$Comp
L Device:C_Small C15
U 1 1 5B132134
P 2150 6900
F 0 "C15" H 2242 6946 50  0000 L CNN
F 1 "0.1uF" H 2242 6855 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 2150 6900 50  0001 C CNN
F 3 "~" H 2150 6900 50  0001 C CNN
	1    2150 6900
	0    -1   1    0   
$EndComp
Wire Wire Line
	2650 6600 2650 6900
Wire Wire Line
	2650 6900 2250 6900
Wire Wire Line
	2050 6900 1650 6900
Wire Wire Line
	1650 6900 1650 6600
Wire Wire Line
	1150 4200 1150 4550
Wire Notes Line
	4950 3350 4950 7350
Wire Notes Line
	550  3350 550  7350
$Comp
L power:GND #PWR0123
U 1 1 5B2A620D
P 1650 6600
F 0 "#PWR0123" H 1650 6350 50  0001 C CNN
F 1 "GND" H 1655 6427 50  0000 C CNN
F 2 "" H 1650 6600 50  0001 C CNN
F 3 "" H 1650 6600 50  0001 C CNN
	1    1650 6600
	0    1    1    0   
$EndComp
Connection ~ 1650 6600
$Comp
L power:VCC #PWR0124
U 1 1 5B2A8ABC
P 2650 6600
F 0 "#PWR0124" H 2650 6450 50  0001 C CNN
F 1 "VCC" H 2667 6773 50  0000 C CNN
F 2 "" H 2650 6600 50  0001 C CNN
F 3 "" H 2650 6600 50  0001 C CNN
	1    2650 6600
	0    1    1    0   
$EndComp
Connection ~ 2650 6600
Text Label 3400 5000 2    50   ~ 0
1.5MHZ_CLK
Text Label 3400 4900 2    50   ~ 0
3MHZ_CLK
$Comp
L 74xx:74HC86 U30
U 1 1 5B0DDF74
P 5850 4950
F 0 "U30" H 5850 5275 50  0000 C CNN
F 1 "74HC86" H 5850 5184 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5850 4950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 5850 4950 50  0001 C CNN
	1    5850 4950
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U30
U 2 1 5B0DE833
P 6500 5200
F 0 "U30" H 6500 5525 50  0000 C CNN
F 1 "74HC86" H 6500 5434 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 6500 5200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 6500 5200 50  0001 C CNN
	2    6500 5200
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U30
U 3 1 5B0DFB0E
P 9350 5100
F 0 "U30" H 9350 5100 50  0000 C CNN
F 1 "74HC86" H 9350 4900 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 9350 5100 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 9350 5100 50  0001 C CNN
	3    9350 5100
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC86 U30
U 5 1 5B0E1732
P 6050 4000
F 0 "U30" V 5683 4000 50  0000 C CNN
F 1 "74HC86" V 5774 4000 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 6050 4000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 6050 4000 50  0001 C CNN
	5    6050 4000
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C37
U 1 1 5B0E8BCD
P 6050 4350
F 0 "C37" H 6142 4396 50  0000 L CNN
F 1 "0.1uF" H 6142 4305 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 6050 4350 50  0001 C CNN
F 3 "~" H 6050 4350 50  0001 C CNN
	1    6050 4350
	0    -1   1    0   
$EndComp
Wire Wire Line
	5550 4350 5950 4350
Wire Wire Line
	6150 4350 6550 4350
Wire Wire Line
	6550 4350 6550 4000
$Comp
L power:GND #PWR047
U 1 1 5B0F1419
P 5550 4000
F 0 "#PWR047" H 5550 3750 50  0001 C CNN
F 1 "GND" H 5555 3827 50  0000 C CNN
F 2 "" H 5550 4000 50  0001 C CNN
F 3 "" H 5550 4000 50  0001 C CNN
	1    5550 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	5550 4000 5550 4350
Connection ~ 5550 4000
$Comp
L power:VCC #PWR048
U 1 1 5B0F5515
P 6550 4000
F 0 "#PWR048" H 6550 3850 50  0001 C CNN
F 1 "VCC" H 6567 4173 50  0000 C CNN
F 2 "" H 6550 4000 50  0001 C CNN
F 3 "" H 6550 4000 50  0001 C CNN
	1    6550 4000
	0    1    1    0   
$EndComp
Connection ~ 6550 4000
NoConn ~ 4500 5150
Text Notes 1900 4150 0    39   ~ 0
Debounce button changes with an\nRC network and a schmitt trigger.
$Comp
L 74xx:74HC14 U2
U 1 1 5B0FA031
P 2400 4550
F 0 "U2" H 2400 4867 50  0000 C CNN
F 1 "74HC14" H 2400 4776 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 2400 4550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 2400 4550 50  0001 C CNN
	1    2400 4550
	1    0    0    -1  
$EndComp
Text Label 2700 4550 0    50   ~ 0
SEL0
Text Label 2700 5100 0    50   ~ 0
SEL1
Text Label 2700 5650 0    50   ~ 0
SEL2
Text Label 3400 4350 2    50   ~ 0
SEL0
Wire Wire Line
	3100 4250 3400 4250
Wire Wire Line
	3400 4250 3400 4000
Connection ~ 3400 4250
Text Label 3400 4450 2    50   ~ 0
SEL1
Text Label 3400 4550 2    50   ~ 0
SEL2
Text Label 5550 4850 2    50   ~ 0
SEL0
Text Label 5550 5050 2    50   ~ 0
SEL1
Text Label 5550 5350 2    50   ~ 0
SEL2
$Comp
L 74xx:74HC14 U2
U 4 1 5B15778B
P 13400 5250
F 0 "U2" H 13350 5250 50  0000 C CNN
F 1 "74HC14" H 13400 5050 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 13400 5250 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 13400 5250 50  0001 C CNN
	4    13400 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 5200 6850 5200
Wire Wire Line
	6850 5200 7500 5200
Connection ~ 6850 5200
$Comp
L Device:C_Small C39
U 1 1 5B18DBE9
P 8450 5400
F 0 "C39" H 8542 5446 50  0000 L CNN
F 1 "1nF" H 8542 5355 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 8450 5400 50  0001 C CNN
F 3 "~" H 8450 5400 50  0001 C CNN
	1    8450 5400
	-1   0    0    -1  
$EndComp
Text Label 3400 4700 2    50   ~ 0
12MHZ_CLK
Text Label 3400 4800 2    50   ~ 0
6MHZ_CLK
$Comp
L 74xx:74LS08 U33
U 1 1 5B23B9F8
P 9950 5000
F 0 "U33" H 9950 5325 50  0000 C CNN
F 1 "74LS08" H 9950 5234 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 9950 5000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 9950 5000 50  0001 C CNN
	1    9950 5000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS08 U33
U 5 1 5B23CCF9
P 7550 4000
F 0 "U33" V 7183 4000 50  0000 C CNN
F 1 "74LS08" V 7274 4000 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7550 4000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 7550 4000 50  0001 C CNN
	5    7550 4000
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C40
U 1 1 5B23EA46
P 7500 4400
F 0 "C40" H 7592 4446 50  0000 L CNN
F 1 "0.1uF" H 7592 4355 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 7500 4400 50  0001 C CNN
F 3 "~" H 7500 4400 50  0001 C CNN
	1    7500 4400
	0    -1   1    0   
$EndComp
Wire Wire Line
	7050 4000 7050 4400
Wire Wire Line
	7050 4400 7400 4400
Wire Wire Line
	7600 4400 8050 4400
Wire Wire Line
	8050 4400 8050 4000
$Comp
L power:GND #PWR054
U 1 1 5B246975
P 7050 4000
F 0 "#PWR054" H 7050 3750 50  0001 C CNN
F 1 "GND" H 7055 3827 50  0000 C CNN
F 2 "" H 7050 4000 50  0001 C CNN
F 3 "" H 7050 4000 50  0001 C CNN
	1    7050 4000
	0    1    1    0   
$EndComp
Connection ~ 7050 4000
$Comp
L power:VCC #PWR055
U 1 1 5B248282
P 8050 4000
F 0 "#PWR055" H 8050 3850 50  0001 C CNN
F 1 "VCC" H 8067 4173 50  0000 C CNN
F 2 "" H 8050 4000 50  0001 C CNN
F 3 "" H 8050 4000 50  0001 C CNN
	1    8050 4000
	0    1    1    0   
$EndComp
Connection ~ 8050 4000
$Comp
L 74xx:74HC14 U2
U 5 1 5B25C050
P 8750 5200
AR Path="/5ADF0E03/5B25C050" Ref="U2"  Part="5" 
AR Path="/5B25C050" Ref="U?"  Part="5" 
F 0 "U2" H 8700 5200 50  0000 C CNN
F 1 "74HC14" H 8750 5000 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 8750 5200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 8750 5200 50  0001 C CNN
	5    8750 5200
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U2
U 6 1 5B25C057
P 7050 7150
AR Path="/5ADF0E03/5B25C057" Ref="U2"  Part="6" 
AR Path="/5B25C057" Ref="U?"  Part="6" 
F 0 "U2" H 7000 7150 50  0000 C CNN
F 1 "74HC14" H 7050 6950 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7050 7150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 7050 7150 50  0001 C CNN
	6    7050 7150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U5
U 3 1 5B25C05E
P 7150 5550
AR Path="/5ADF0E03/5B25C05E" Ref="U5"  Part="3" 
AR Path="/5B25C05E" Ref="U?"  Part="3" 
F 0 "U5" H 7100 5550 50  0000 C CNN
F 1 "74HC04" H 7100 5350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7150 5550 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 7150 5550 50  0001 C CNN
	3    7150 5550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U5
U 6 1 5B25C07A
P 10600 5350
AR Path="/5ADF0E03/5B25C07A" Ref="U5"  Part="6" 
AR Path="/5B25C07A" Ref="U?"  Part="6" 
F 0 "U5" H 10600 5667 50  0000 C CNN
F 1 "74HC04" H 10600 5576 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 10600 5350 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 10600 5350 50  0001 C CNN
	6    10600 5350
	1    0    0    -1  
$EndComp
Text Notes 13700 4950 0    50   ~ 0
SPARE AVAILABLE
Text HLabel 10250 5000 2    50   Input ~ 0
CLK
Text Label 4500 4450 0    50   ~ 0
PRE_CLK
Text Label 7500 5300 2    50   ~ 0
PRE_CLK
Text Label 9650 4900 2    50   ~ 0
PRE_CLK
Text Label 11700 1450 0    50   ~ 0
6MHZ_CLK
Text Label 11700 1550 0    50   ~ 0
3MHZ_CLK
$Comp
L 74xx:74LS107 U35
U 2 1 5B32D351
P 7800 5300
F 0 "U35" H 7800 5300 50  0000 C CNN
F 1 "74LS107" H 7800 5576 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 7800 5300 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS107" H 7800 5300 50  0001 C CNN
	2    7800 5300
	1    0    0    -1  
$EndComp
Text Label 11700 1650 0    50   ~ 0
1.5MHZ_CLK
$Comp
L Timer:LM555 U1
U 1 1 5ADF0EF3
P 2000 1250
F 0 "U1" H 2150 1650 50  0000 C CNN
F 1 "LM555" H 2000 1900 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 2000 1250 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm555.pdf" H 2000 1250 50  0001 C CNN
	1    2000 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5ADF19B9
P 1950 2050
F 0 "C1" H 2042 2096 50  0000 L CNN
F 1 "0.1uF" H 2042 2005 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 1950 2050 50  0001 C CNN
F 3 "~" H 1950 2050 50  0001 C CNN
	1    1950 2050
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5ADF19F1
P 1950 2450
F 0 "C2" H 1858 2404 50  0000 R CNN
F 1 "1uF" H 1858 2495 50  0000 R CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 1950 2450 50  0001 C CNN
F 3 "~" H 1950 2450 50  0001 C CNN
	1    1950 2450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2300 2050 2050 2050
Connection ~ 2050 2050
Wire Wire Line
	2050 2050 2050 2450
Wire Wire Line
	1850 2450 1850 2050
Connection ~ 1850 2050
Wire Wire Line
	1850 2050 1400 2050
$Comp
L power:GND #PWR0102
U 1 1 5ADF1BB9
P 1400 2050
F 0 "#PWR0102" H 1400 1800 50  0001 C CNN
F 1 "GND" H 1405 1877 50  0000 C CNN
F 2 "" H 1400 2050 50  0001 C CNN
F 3 "" H 1400 2050 50  0001 C CNN
	1    1400 2050
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5ADF1E11
P 1100 1550
F 0 "C4" H 1192 1596 50  0000 L CNN
F 1 "10nF" H 1192 1505 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 1100 1550 50  0001 C CNN
F 3 "~" H 1100 1550 50  0001 C CNN
	1    1100 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5ADF1E95
P 1100 1650
F 0 "#PWR0105" H 1100 1400 50  0001 C CNN
F 1 "GND" V 1105 1522 50  0000 R CNN
F 2 "" H 1100 1650 50  0001 C CNN
F 3 "" H 1100 1650 50  0001 C CNN
	1    1100 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5ADF206F
P 3000 1100
F 0 "R1" H 3070 1146 50  0000 L CNN
F 1 "1K" H 3070 1055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2930 1100 50  0001 C CNN
F 3 "~" H 3000 1100 50  0001 C CNN
	1    3000 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 5ADF22E9
P 1100 1050
F 0 "C3" V 871 1050 50  0000 C CNN
F 1 "1uF" V 962 1050 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 1100 1050 50  0001 C CNN
F 3 "~" H 1100 1050 50  0001 C CNN
	1    1100 1050
	0    1    1    0   
$EndComp
Wire Wire Line
	1500 1250 1100 1250
Wire Wire Line
	1100 1250 1100 1450
$Comp
L power:GND #PWR0108
U 1 1 5ADF24BB
P 1000 1050
F 0 "#PWR0108" H 1000 800 50  0001 C CNN
F 1 "GND" H 1005 877 50  0000 C CNN
F 2 "" H 1000 1050 50  0001 C CNN
F 3 "" H 1000 1050 50  0001 C CNN
	1    1000 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1050 1200 1050
Text Label 1500 1050 2    50   ~ 0
AC_TR
Text Label 2750 1850 3    50   ~ 0
AC_TR
Wire Wire Line
	3000 1250 2750 1250
Wire Wire Line
	2750 1250 2500 1250
Connection ~ 2750 1250
$Comp
L Device:R R3
U 1 1 5ADF2B89
P 2750 1400
F 0 "R3" H 2820 1446 50  0000 L CNN
F 1 "10K" H 2820 1355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2680 1400 50  0001 C CNN
F 3 "~" H 2750 1400 50  0001 C CNN
	1    2750 1400
	1    0    0    -1  
$EndComp
Text Notes 2900 1950 0    20   ~ 0
Impose a minimum value on the \nvariable resistor to keep duty \ncycle close to 50%. Current\nvalues give min 0.7 Hz, max 70 Hz.
Text Label 2500 1050 0    50   ~ 0
ADJ_CLK
Wire Notes Line
	500  550  500  2900
Wire Notes Line
	500  2900 3550 2900
Wire Notes Line
	3550 2900 3550 550 
Wire Notes Line
	3550 550  500  550 
Text Notes 1700 500  0    50   ~ 0
Adjustable Clock\n
$Comp
L power:GND #PWR0103
U 1 1 5ADF1D70
P 2000 1650
F 0 "#PWR0103" H 2000 1400 50  0001 C CNN
F 1 "GND" H 2005 1477 50  0000 C CNN
F 2 "" H 2000 1650 50  0001 C CNN
F 3 "" H 2000 1650 50  0001 C CNN
	1    2000 1650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0113
U 1 1 5B0AE691
P 2000 850
F 0 "#PWR0113" H 2000 700 50  0001 C CNN
F 1 "VCC" H 2017 1023 50  0000 C CNN
F 2 "" H 2000 850 50  0001 C CNN
F 3 "" H 2000 850 50  0001 C CNN
	1    2000 850 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0117
U 1 1 5B0B0C42
P 2300 2050
F 0 "#PWR0117" H 2300 1900 50  0001 C CNN
F 1 "VCC" V 2317 2178 50  0000 L CNN
F 2 "" H 2300 2050 50  0001 C CNN
F 3 "" H 2300 2050 50  0001 C CNN
	1    2300 2050
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0107
U 1 1 5B0C5280
P 3000 950
F 0 "#PWR0107" H 3000 800 50  0001 C CNN
F 1 "VCC" H 3017 1123 50  0000 C CNN
F 2 "" H 3000 950 50  0001 C CNN
F 3 "" H 3000 950 50  0001 C CNN
	1    3000 950 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0106
U 1 1 5B0DA39C
P 1500 1450
F 0 "#PWR0106" H 1500 1300 50  0001 C CNN
F 1 "VCC" V 1518 1577 50  0000 L CNN
F 2 "" H 1500 1450 50  0001 C CNN
F 3 "" H 1500 1450 50  0001 C CNN
	1    1500 1450
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Variable R2
U 1 1 5ADF287B
P 2750 1700
F 0 "R2" H 2878 1746 50  0000 L CNN
F 1 "1M" H 2878 1655 50  0000 L CNN
F 2 "cpu:Akizuki-Denshi Potentiometer" V 2680 1700 50  0001 C CNN
F 3 "~" H 2750 1700 50  0001 C CNN
	1    2750 1700
	1    0    0    -1  
$EndComp
Text Label 11700 1750 0    50   ~ 0
750KHZ_CLK
$Comp
L 74xx:74LS107 U35
U 3 1 5B352CCE
P 14000 2750
F 0 "U35" V 13900 2750 50  0000 C CNN
F 1 "74LS107" V 14100 2750 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 14000 2750 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS107" H 14000 2750 50  0001 C CNN
	3    14000 2750
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR089
U 1 1 5B352CD5
P 14400 2750
F 0 "#PWR089" H 14400 2600 50  0001 C CNN
F 1 "VCC" H 14417 2923 50  0000 C CNN
F 2 "" H 14400 2750 50  0001 C CNN
F 3 "" H 14400 2750 50  0001 C CNN
	1    14400 2750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR086
U 1 1 5B352CDB
P 13600 2750
F 0 "#PWR086" H 13600 2500 50  0001 C CNN
F 1 "GND" H 13605 2577 50  0000 C CNN
F 2 "" H 13600 2750 50  0001 C CNN
F 3 "" H 13600 2750 50  0001 C CNN
	1    13600 2750
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C43
U 1 1 5B352CE1
P 14000 3150
F 0 "C43" H 14092 3196 50  0000 L CNN
F 1 "0.1uF" H 14092 3105 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 14000 3150 50  0001 C CNN
F 3 "~" H 14000 3150 50  0001 C CNN
	1    14000 3150
	0    -1   1    0   
$EndComp
Wire Wire Line
	14400 2750 14400 3150
Wire Wire Line
	14400 3150 14100 3150
Wire Wire Line
	13900 3150 13600 3150
Wire Wire Line
	13600 3150 13600 2750
Connection ~ 14400 2750
$Comp
L 74xx:74LS107 U35
U 1 1 5B352CED
P 14900 5200
F 0 "U35" H 14900 5200 50  0000 C CNN
F 1 "74LS107" H 14900 5476 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 14900 5200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS107" H 14900 5200 50  0001 C CNN
	1    14900 5200
	1    0    0    -1  
$EndComp
Connection ~ 13600 2750
Text Label 11700 1850 0    50   ~ 0
375KHZ_CLK
$Comp
L 74xx:74HC86 U30
U 4 1 5B01B286
P 5850 5450
F 0 "U30" H 5850 5500 50  0000 C CNN
F 1 "74HC86" H 6100 5350 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5850 5450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC86" H 5850 5450 50  0001 C CNN
	4    5850 5450
	1    0    0    -1  
$EndComp
NoConn ~ 13700 5250
$Comp
L power:GND #PWR074
U 1 1 5B022397
P 13100 5250
F 0 "#PWR074" H 13100 5000 50  0001 C CNN
F 1 "GND" H 13105 5077 50  0000 C CNN
F 2 "" H 13100 5250 50  0001 C CNN
F 3 "" H 13100 5250 50  0001 C CNN
	1    13100 5250
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR068
U 1 1 5B02331A
P 7800 5600
F 0 "#PWR068" H 7800 5450 50  0001 C CNN
F 1 "VCC" H 7817 5773 50  0000 C CNN
F 2 "" H 7800 5600 50  0001 C CNN
F 3 "" H 7800 5600 50  0001 C CNN
	1    7800 5600
	-1   0    0    1   
$EndComp
Wire Wire Line
	7500 5400 7500 5550
Wire Wire Line
	7500 5550 7450 5550
Wire Notes Line
	10250 650  10250 3300
Wire Notes Line
	10250 3300 12450 3300
Wire Notes Line
	12450 3300 12450 650 
Text Notes 11000 600  0    50   ~ 0
Frequency Dividers
$Comp
L Device:R R40
U 1 1 5B05DCB8
P 8300 5200
F 0 "R40" V 8093 5200 50  0000 C CNN
F 1 "1M" V 8184 5200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 8230 5200 50  0001 C CNN
F 3 "~" H 8300 5200 50  0001 C CNN
	1    8300 5200
	0    1    1    0   
$EndComp
NoConn ~ 8100 5400
Wire Wire Line
	8450 5200 8450 5300
$Comp
L power:GND #PWR0166
U 1 1 5B065E4E
P 8450 5500
F 0 "#PWR0166" H 8450 5250 50  0001 C CNN
F 1 "GND" H 8455 5327 50  0000 C CNN
F 2 "" H 8450 5500 50  0001 C CNN
F 3 "" H 8450 5500 50  0001 C CNN
	1    8450 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 5200 8100 5200
Connection ~ 8450 5200
Wire Wire Line
	9050 5000 8500 5000
Wire Wire Line
	8500 5000 8500 4850
Wire Wire Line
	8500 4850 8100 4850
Wire Wire Line
	8100 4850 8100 5200
Connection ~ 8100 5200
Wire Wire Line
	6150 4950 6150 5100
Wire Wire Line
	6150 5100 6200 5100
Wire Wire Line
	6150 5450 6150 5300
Wire Wire Line
	6150 5300 6200 5300
Text Notes 8650 5600 0    50   ~ 0
Schmitt trigger here to deal\nwith slow edge from RC.
Wire Wire Line
	6850 5200 6850 5550
Text HLabel 5550 5550 0    50   Input ~ 0
~RESET
Text Notes 5450 5900 0    50   ~ 0
Simulate a clock source change on\nreset to pull CLK low for a bit while\nmachine state is reset.
Wire Wire Line
	10250 5000 10250 5350
Wire Wire Line
	10250 5350 10300 5350
Text HLabel 10900 5350 2    50   Input ~ 0
~CLK
Wire Wire Line
	1150 4550 1150 5100
Wire Wire Line
	1150 5100 1150 5650
Wire Notes Line
	5150 3350 5150 6150
Wire Notes Line
	5150 6150 11300 6150
Wire Notes Line
	11300 6150 11300 3350
Wire Notes Line
	11300 3350 5150 3350
Text Notes 8950 3800 0    50   ~ 0
Clock Frontend
Connection ~ 950  4550
$Comp
L Device:R R15
U 1 1 5B38C9B9
P 5600 7550
F 0 "R15" H 5670 7596 50  0000 L CNN
F 1 "100K" H 5670 7505 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5530 7550 50  0001 C CNN
F 3 "~" H 5600 7550 50  0001 C CNN
	1    5600 7550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 7050 5600 7150
$Comp
L power:VCC #PWR0126
U 1 1 5B38C9C1
P 5600 6650
F 0 "#PWR0126" H 5600 6500 50  0001 C CNN
F 1 "VCC" H 5617 6823 50  0000 C CNN
F 2 "" H 5600 6650 50  0001 C CNN
F 3 "" H 5600 6650 50  0001 C CNN
	1    5600 6650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C114
U 1 1 5B391B45
P 6450 7250
F 0 "C114" V 6221 7250 50  0000 C CNN
F 1 "0.1uF" V 6312 7250 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 6450 7250 50  0001 C CNN
F 3 "~" H 6450 7250 50  0001 C CNN
	1    6450 7250
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0128
U 1 1 5B391B4C
P 6450 7350
F 0 "#PWR0128" H 6450 7100 50  0001 C CNN
F 1 "GND" H 6455 7177 50  0000 C CNN
F 2 "" H 6450 7350 50  0001 C CNN
F 3 "" H 6450 7350 50  0001 C CNN
	1    6450 7350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 5B391B52
P 6100 7150
F 0 "R16" V 5893 7150 50  0000 C CNN
F 1 "1M" V 5984 7150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6030 7150 50  0001 C CNN
F 3 "~" H 6100 7150 50  0001 C CNN
	1    6100 7150
	0    1    1    0   
$EndComp
Wire Wire Line
	6450 7150 6250 7150
Connection ~ 6450 7150
Wire Wire Line
	6450 7150 6750 7150
Wire Wire Line
	5600 7150 5950 7150
Connection ~ 5600 7150
Wire Wire Line
	5600 7150 5600 7400
$Comp
L power:GND #PWR0129
U 1 1 5B39CA00
P 5600 7700
F 0 "#PWR0129" H 5600 7450 50  0001 C CNN
F 1 "GND" H 5605 7527 50  0000 C CNN
F 2 "" H 5600 7700 50  0001 C CNN
F 3 "" H 5600 7700 50  0001 C CNN
	1    5600 7700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 5100 1300 5100
Wire Wire Line
	950  4550 1300 4550
Text HLabel 8150 7350 0    50   Input ~ 0
~RESET_NCLK
$Comp
L 74xx:74LS08 U?
U 4 1 5B3C7132
P 8450 7250
AR Path="/5B0C6DCD/5B3C7132" Ref="U?"  Part="4" 
AR Path="/5ADF0E03/5B3C7132" Ref="U117"  Part="4" 
F 0 "U117" H 8450 7575 50  0000 C CNN
F 1 "74LS08" H 8450 7484 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 8450 7250 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS08" H 8450 7250 50  0001 C CNN
	4    8450 7250
	1    0    0    -1  
$EndComp
Text Notes 8150 6800 0    50   ~ 0
SPARE TAKEN: AND taken \nfrom control logic
Wire Wire Line
	7350 7150 8150 7150
Text Notes 8000 7750 0    50   ~ 0
If either goes low (i.e. ~RESET),\nthen AND will go low.
Text HLabel 8750 7250 2    50   Input ~ 0
~RESET
Wire Notes Line
	5200 6350 5200 8150
Wire Notes Line
	5200 8150 9350 8150
Wire Notes Line
	9350 8150 9350 6350
Wire Notes Line
	9350 6350 5200 6350
Text Notes 6700 6600 0    50   ~ 0
Reset Button
$Comp
L Switch:SW_Push SW4
U 1 1 5B1382CD
P 5600 6850
F 0 "SW4" H 5600 7135 50  0000 C CNN
F 1 "SW_Push" H 5600 7044 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H7.3mm" H 5600 7050 50  0001 C CNN
F 3 "" H 5600 7050 50  0001 C CNN
	1    5600 6850
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74HC04 U5
U 5 1 5B6B88E1
P 14300 5750
AR Path="/5ADF0E03/5B6B88E1" Ref="U5"  Part="5" 
AR Path="/5B6B88E1" Ref="U?"  Part="5" 
AR Path="/5B0C6DCD/5B6B88E1" Ref="U?"  Part="5" 
F 0 "U5" H 14300 6067 50  0000 C CNN
F 1 "74HC04" H 14300 5976 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 14300 5750 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 14300 5750 50  0001 C CNN
	5    14300 5750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0459
U 1 1 5B6BDB28
P 14000 5750
F 0 "#PWR0459" H 14000 5500 50  0001 C CNN
F 1 "GND" H 14005 5577 50  0000 C CNN
F 2 "" H 14000 5750 50  0001 C CNN
F 3 "" H 14000 5750 50  0001 C CNN
	1    14000 5750
	0    1    1    0   
$EndComp
NoConn ~ 14600 5750
Wire Wire Line
	2750 1850 2500 1850
Wire Wire Line
	2500 1850 2500 1450
Text Notes 1950 3900 0    50   ~ 0
Make sure that when the computer\nis turned on, SEL0,1,2 start out\nselecting BTN_CLK so we don't\nget spurious clocks while the\nclock sources are stabilising.
$Comp
L 74xx:74HC590 U6
U 1 1 5B6EDC8B
P 11300 1950
F 0 "U6" H 11300 1950 50  0000 C CNN
F 1 "74HC590" H 11300 1700 50  0000 C CNN
F 2 "" H 11300 2000 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC590.pdf" H 11300 2000 50  0001 C CNN
	1    11300 1950
	1    0    0    -1  
$EndComp
Text Label 10900 1650 2    50   ~ 0
12MHZ_CLK
Wire Wire Line
	10900 1650 10900 1750
$Comp
L power:GND #PWR0139
U 1 1 5B6F1B83
P 10900 1450
F 0 "#PWR0139" H 10900 1200 50  0001 C CNN
F 1 "GND" V 10905 1322 50  0000 R CNN
F 2 "" H 10900 1450 50  0001 C CNN
F 3 "" H 10900 1450 50  0001 C CNN
	1    10900 1450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0219
U 1 1 5B6F4180
P 10900 2150
F 0 "#PWR0219" H 10900 1900 50  0001 C CNN
F 1 "GND" V 10905 2022 50  0000 R CNN
F 2 "" H 10900 2150 50  0001 C CNN
F 3 "" H 10900 2150 50  0001 C CNN
	1    10900 2150
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0223
U 1 1 5B6F4697
P 11300 1250
F 0 "#PWR0223" H 11300 1100 50  0001 C CNN
F 1 "VCC" H 11317 1423 50  0000 C CNN
F 2 "" H 11300 1250 50  0001 C CNN
F 3 "" H 11300 1250 50  0001 C CNN
	1    11300 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C41
U 1 1 5B6F4C38
P 11750 1100
F 0 "C41" H 11842 1146 50  0000 L CNN
F 1 "0.1uF" H 11842 1055 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 11750 1100 50  0001 C CNN
F 3 "~" H 11750 1100 50  0001 C CNN
	1    11750 1100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	11300 1250 11750 1250
Wire Wire Line
	11750 1250 11750 1200
Connection ~ 11300 1250
$Comp
L power:GND #PWR0224
U 1 1 5B6F8869
P 11750 1000
F 0 "#PWR0224" H 11750 750 50  0001 C CNN
F 1 "GND" H 11755 827 50  0000 C CNN
F 2 "" H 11750 1000 50  0001 C CNN
F 3 "" H 11750 1000 50  0001 C CNN
	1    11750 1000
	-1   0    0    1   
$EndComp
$Comp
L power:VCC #PWR0225
U 1 1 5B6F8E78
P 10900 1950
F 0 "#PWR0225" H 10900 1800 50  0001 C CNN
F 1 "VCC" H 10917 2123 50  0000 C CNN
F 2 "" H 10900 1950 50  0001 C CNN
F 3 "" H 10900 1950 50  0001 C CNN
	1    10900 1950
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0226
U 1 1 5B6F90F5
P 11300 2550
F 0 "#PWR0226" H 11300 2300 50  0001 C CNN
F 1 "GND" H 11305 2377 50  0000 C CNN
F 2 "" H 11300 2550 50  0001 C CNN
F 3 "" H 11300 2550 50  0001 C CNN
	1    11300 2550
	1    0    0    -1  
$EndComp
NoConn ~ 11700 2350
Text Label 11700 1950 0    50   ~ 0
187KHZ_CLK
Text Label 3400 5100 2    50   ~ 0
187KHZ_CLK
Wire Notes Line
	12450 650  10250 650 
Wire Notes Line
	10050 650  7600 650 
NoConn ~ 15200 5300
NoConn ~ 15200 5100
$Comp
L power:GND #PWR0227
U 1 1 5B754A6A
P 14900 5500
F 0 "#PWR0227" H 14900 5250 50  0001 C CNN
F 1 "GND" H 14905 5327 50  0000 C CNN
F 2 "" H 14900 5500 50  0001 C CNN
F 3 "" H 14900 5500 50  0001 C CNN
	1    14900 5500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0228
U 1 1 5B754BCE
P 14600 5200
F 0 "#PWR0228" H 14600 4950 50  0001 C CNN
F 1 "GND" H 14605 5027 50  0000 C CNN
F 2 "" H 14600 5200 50  0001 C CNN
F 3 "" H 14600 5200 50  0001 C CNN
	1    14600 5200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0229
U 1 1 5B754E50
P 14600 5100
F 0 "#PWR0229" H 14600 4850 50  0001 C CNN
F 1 "GND" H 14605 4927 50  0000 C CNN
F 2 "" H 14600 5100 50  0001 C CNN
F 3 "" H 14600 5100 50  0001 C CNN
	1    14600 5100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0230
U 1 1 5B754EE5
P 14600 5300
F 0 "#PWR0230" H 14600 5050 50  0001 C CNN
F 1 "GND" H 14605 5127 50  0000 C CNN
F 2 "" H 14600 5300 50  0001 C CNN
F 3 "" H 14600 5300 50  0001 C CNN
	1    14600 5300
	0    1    1    0   
$EndComp
NoConn ~ 11700 1750
NoConn ~ 11700 1850
Text HLabel 11700 2150 2    50   Input ~ 0
47KHZ_CLK
Text HLabel 11700 2050 2    50   Input ~ 0
94KHZ_CLK
Text HLabel 3400 5200 0    50   Input ~ 0
47KHZ_CLK
$EndSCHEMATC
