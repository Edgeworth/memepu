EESchema Schematic File Version 4
LIBS:eeprom_programmer-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Device:C C1
U 1 1 5AD2D725
P 5700 1500
F 0 "C1" H 5815 1546 50  0000 L CNN
F 1 "0.1uF" H 5815 1455 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 5738 1350 50  0001 C CNN
F 3 "~" H 5700 1500 50  0001 C CNN
	1    5700 1500
	1    0    0    -1  
$EndComp
$Comp
L eeprom_programmer-rescue:74HC595-74xx U1
U 1 1 5AD2D7E6
P 1300 1600
F 0 "U1" H 1300 2478 50  0000 C CNN
F 1 "74HC595" H 1300 2387 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 1300 1600 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT595.pdf" H 1300 1600 50  0001 C CNN
	1    1300 1600
	1    0    0    -1  
$EndComp
$Comp
L eeprom_programmer-rescue:74HC595-74xx U2
U 1 1 5AD2D89E
P 2850 1600
F 0 "U2" H 2850 2478 50  0000 C CNN
F 1 "74HC595" H 2850 2387 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 2850 1600 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT595.pdf" H 2850 1600 50  0001 C CNN
	1    2850 1600
	1    0    0    -1  
$EndComp
$Comp
L eeprom_programmer-rescue:74HC595-74xx U3
U 1 1 5AD2D95A
P 4350 1600
F 0 "U3" H 4350 2478 50  0000 C CNN
F 1 "74HC595" H 4350 2387 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 4350 1600 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT595.pdf" H 4350 1600 50  0001 C CNN
	1    4350 1600
	1    0    0    -1  
$EndComp
$Comp
L kicad:AT28C64B U5
U 1 1 5AD2FB52
P 5200 4300
F 0 "U5" H 5200 5778 50  0000 C CNN
F 1 "AT28C64B" H 5200 5687 50  0000 C CNN
F 2 "Package_DIP:DIP-28_W15.24mm_Socket" H 5200 4600 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc0270.pdf" H 5200 4600 50  0001 C CNN
	1    5200 4300
	1    0    0    -1  
$EndComp
Text Label 2450 4250 0    50   ~ 0
D0
Text Label 2450 4350 0    50   ~ 0
D1
Text Label 2450 4450 0    50   ~ 0
D2
Text Label 2450 4550 0    50   ~ 0
D3
Text Label 2450 4650 0    50   ~ 0
D4
Text Label 2450 4750 0    50   ~ 0
D5
Text Label 1450 4550 2    50   ~ 0
D6
Text Label 1450 4650 2    50   ~ 0
D7
Text Label 4300 3100 0    50   ~ 0
D0
Text Label 4300 3200 0    50   ~ 0
D1
Text Label 4300 3300 0    50   ~ 0
D2
Text Label 4300 3400 0    50   ~ 0
D3
Text Label 4300 3500 0    50   ~ 0
D4
Text Label 4300 3600 0    50   ~ 0
D5
Text Label 4300 3700 0    50   ~ 0
D6
Text Label 4300 3800 0    50   ~ 0
D7
Text Label 5800 3100 0    50   ~ 0
D0
Text Label 5800 3200 0    50   ~ 0
D1
Text Label 5800 3300 0    50   ~ 0
D2
Text Label 5800 3400 0    50   ~ 0
D3
Text Label 5800 3500 0    50   ~ 0
D4
Text Label 5800 3600 0    50   ~ 0
D5
Text Label 5800 3700 0    50   ~ 0
D6
Text Label 5800 3800 0    50   ~ 0
D7
NoConn ~ 2450 3750
NoConn ~ 2450 3650
NoConn ~ 2050 3250
NoConn ~ 1450 3650
NoConn ~ 1450 3750
NoConn ~ 2450 4850
NoConn ~ 2450 4950
NoConn ~ 2450 4050
Text Label 1800 1200 0    50   ~ 0
A0
Text Label 1800 1300 0    50   ~ 0
A1
Text Label 1800 1400 0    50   ~ 0
A2
Text Label 1800 1500 0    50   ~ 0
A3
Text Label 1800 1600 0    50   ~ 0
A4
Text Label 1800 1700 0    50   ~ 0
A5
Text Label 1800 1800 0    50   ~ 0
A6
Text Label 1800 1900 0    50   ~ 0
A7
Text Label 3350 1200 0    50   ~ 0
A8
Text Label 3350 1300 0    50   ~ 0
A9
Text Label 3350 1400 0    50   ~ 0
A10
Text Label 3350 1500 0    50   ~ 0
A11
Text Label 3350 1600 0    50   ~ 0
A12
Text Label 3350 1700 0    50   ~ 0
A13
Text Label 3350 1800 0    50   ~ 0
A14
Text Label 3350 1900 0    50   ~ 0
A15
Text Label 4850 1200 0    50   ~ 0
A16
Text Label 4850 1300 0    50   ~ 0
A17
Text Label 4850 1400 0    50   ~ 0
A18
NoConn ~ 4850 2100
Text Label 3100 3100 2    50   ~ 0
A0
Text Label 3100 3200 2    50   ~ 0
A1
Text Label 3100 3300 2    50   ~ 0
A2
Text Label 3100 3400 2    50   ~ 0
A3
Text Label 3100 3500 2    50   ~ 0
A4
Text Label 3100 3600 2    50   ~ 0
A5
Text Label 3100 3700 2    50   ~ 0
A6
Text Label 3100 3800 2    50   ~ 0
A7
Text Label 3100 3900 2    50   ~ 0
A8
Text Label 3100 4000 2    50   ~ 0
A9
Text Label 3100 4100 2    50   ~ 0
A10
Text Label 3100 4200 2    50   ~ 0
A11
Text Label 3100 4300 2    50   ~ 0
A12
Text Label 3100 4400 2    50   ~ 0
A13
Text Label 3100 4500 2    50   ~ 0
A14
Text Label 3100 4600 2    50   ~ 0
A15
Text Label 3100 4700 2    50   ~ 0
A16
Text Label 3100 4800 2    50   ~ 0
A17
Text Label 3100 4900 2    50   ~ 0
A18
Text Label 4600 3100 2    50   ~ 0
A0
Text Label 4600 3200 2    50   ~ 0
A1
Text Label 4600 3300 2    50   ~ 0
A2
Text Label 4600 3400 2    50   ~ 0
A3
Text Label 4600 3500 2    50   ~ 0
A4
Text Label 4600 3600 2    50   ~ 0
A5
Text Label 4600 3700 2    50   ~ 0
A6
Text Label 4600 3800 2    50   ~ 0
A7
Text Label 4600 3900 2    50   ~ 0
A8
Text Label 4600 4000 2    50   ~ 0
A9
Text Label 4600 4100 2    50   ~ 0
A10
Text Label 4600 4200 2    50   ~ 0
A11
Text Label 4600 4300 2    50   ~ 0
A12
$Comp
L Device:LED D1
U 1 1 5AD31642
P 750 4850
F 0 "D1" H 741 5066 50  0000 C CNN
F 1 "LED" H 741 4975 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 750 4850 50  0001 C CNN
F 3 "~" H 750 4850 50  0001 C CNN
	1    750  4850
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 5AD317E8
P 750 5150
F 0 "R1" V 543 5150 50  0000 C CNN
F 1 "1K" V 634 5150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 680 5150 50  0001 C CNN
F 3 "~" H 750 5150 50  0001 C CNN
	1    750  5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 2100 2150 2100
Wire Wire Line
	2150 2100 2150 1200
Wire Wire Line
	2150 1200 2350 1200
Wire Wire Line
	3350 2100 3600 2100
Wire Wire Line
	3600 2100 3600 1200
Wire Wire Line
	3600 1200 3850 1200
$Comp
L power:+5V #PWR0101
U 1 1 5AD320D1
P 3850 1500
F 0 "#PWR0101" H 3850 1350 50  0001 C CNN
F 1 "+5V" V 3865 1628 50  0000 L CNN
F 2 "" H 3850 1500 50  0001 C CNN
F 3 "" H 3850 1500 50  0001 C CNN
	1    3850 1500
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5AD3211A
P 2350 1500
F 0 "#PWR0102" H 2350 1350 50  0001 C CNN
F 1 "+5V" V 2365 1628 50  0000 L CNN
F 2 "" H 2350 1500 50  0001 C CNN
F 3 "" H 2350 1500 50  0001 C CNN
	1    2350 1500
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5AD3213B
P 800 1500
F 0 "#PWR0103" H 800 1350 50  0001 C CNN
F 1 "+5V" V 815 1628 50  0000 L CNN
F 2 "" H 800 1500 50  0001 C CNN
F 3 "" H 800 1500 50  0001 C CNN
	1    800  1500
	0    -1   -1   0   
$EndComp
Text Label 800  1200 2    50   ~ 0
SER
Text Label 1450 3850 2    50   ~ 0
SER
Text Label 1450 3950 2    50   ~ 0
SRCLK
Text Label 800  1400 2    50   ~ 0
SRCLK
Text Label 2350 1400 2    50   ~ 0
SRCLK
Text Label 3850 1400 2    50   ~ 0
SRCLK
Text Label 1450 4050 2    50   ~ 0
RCLK
Text Label 800  1700 2    50   ~ 0
RCLK
Text Label 2350 1700 2    50   ~ 0
RCLK
Text Label 3850 1700 2    50   ~ 0
RCLK
$Comp
L power:GND #PWR0104
U 1 1 5AD32424
P 800 1800
F 0 "#PWR0104" H 800 1550 50  0001 C CNN
F 1 "GND" V 805 1672 50  0000 R CNN
F 2 "" H 800 1800 50  0001 C CNN
F 3 "" H 800 1800 50  0001 C CNN
	1    800  1800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5AD32457
P 2350 1800
F 0 "#PWR0105" H 2350 1550 50  0001 C CNN
F 1 "GND" V 2355 1672 50  0000 R CNN
F 2 "" H 2350 1800 50  0001 C CNN
F 3 "" H 2350 1800 50  0001 C CNN
	1    2350 1800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5AD32478
P 3850 1800
F 0 "#PWR0106" H 3850 1550 50  0001 C CNN
F 1 "GND" V 3855 1672 50  0000 R CNN
F 2 "" H 3850 1800 50  0001 C CNN
F 3 "" H 3850 1800 50  0001 C CNN
	1    3850 1800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5AD326C4
P 4600 4500
F 0 "#PWR0107" H 4600 4250 50  0001 C CNN
F 1 "GND" V 4605 4372 50  0000 R CNN
F 2 "" H 4600 4500 50  0001 C CNN
F 3 "" H 4600 4500 50  0001 C CNN
	1    4600 4500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5AD326F7
P 3100 5300
F 0 "#PWR0108" H 3100 5050 50  0001 C CNN
F 1 "GND" V 3105 5172 50  0000 R CNN
F 2 "" H 3100 5300 50  0001 C CNN
F 3 "" H 3100 5300 50  0001 C CNN
	1    3100 5300
	0    1    1    0   
$EndComp
Text Label 1450 4150 2    50   ~ 0
~WE
Text Label 3100 5100 2    50   ~ 0
~WE
Text Label 4600 4400 2    50   ~ 0
~WE
Text Label 1450 4250 2    50   ~ 0
~OE
Text Label 3100 5400 2    50   ~ 0
~OE
Text Label 4600 4600 2    50   ~ 0
~OE
$Comp
L Device:R R2
U 1 1 5AD32EC5
P 1150 5150
F 0 "R2" V 943 5150 50  0000 C CNN
F 1 "1K" V 1034 5150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1080 5150 50  0001 C CNN
F 3 "~" H 1150 5150 50  0001 C CNN
	1    1150 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 5AD32F0B
P 1150 4850
F 0 "D2" H 1141 5066 50  0000 C CNN
F 1 "LED" H 1141 4975 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 1150 4850 50  0001 C CNN
F 3 "~" H 1150 4850 50  0001 C CNN
	1    1150 4850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5AD3307C
P 750 5300
F 0 "#PWR0109" H 750 5050 50  0001 C CNN
F 1 "GND" V 755 5172 50  0000 R CNN
F 2 "" H 750 5300 50  0001 C CNN
F 3 "" H 750 5300 50  0001 C CNN
	1    750  5300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5AD330AF
P 1150 5300
F 0 "#PWR0110" H 1150 5050 50  0001 C CNN
F 1 "GND" V 1155 5172 50  0000 R CNN
F 2 "" H 1150 5300 50  0001 C CNN
F 3 "" H 1150 5300 50  0001 C CNN
	1    1150 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 4350 750  4350
Wire Wire Line
	750  4350 750  4700
Wire Wire Line
	1450 4450 1150 4450
Wire Wire Line
	1150 4450 1150 4700
NoConn ~ 4850 1500
NoConn ~ 4850 1600
NoConn ~ 4850 1700
NoConn ~ 4850 1800
NoConn ~ 4850 1900
$Comp
L power:GND #PWR0111
U 1 1 5AD33989
P 5700 1650
F 0 "#PWR0111" H 5700 1400 50  0001 C CNN
F 1 "GND" H 5705 1477 50  0000 C CNN
F 2 "" H 5700 1650 50  0001 C CNN
F 3 "" H 5700 1650 50  0001 C CNN
	1    5700 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5AD339F3
P 2050 5250
F 0 "#PWR0112" H 2050 5000 50  0001 C CNN
F 1 "GND" H 2055 5077 50  0000 C CNN
F 2 "" H 2050 5250 50  0001 C CNN
F 3 "" H 2050 5250 50  0001 C CNN
	1    2050 5250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5AD33A14
P 1950 5250
F 0 "#PWR0113" H 1950 5000 50  0001 C CNN
F 1 "GND" H 1955 5077 50  0000 C CNN
F 2 "" H 1950 5250 50  0001 C CNN
F 3 "" H 1950 5250 50  0001 C CNN
	1    1950 5250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5AD33A61
P 4350 2400
F 0 "#PWR0114" H 4350 2150 50  0001 C CNN
F 1 "GND" H 4355 2227 50  0000 C CNN
F 2 "" H 4350 2400 50  0001 C CNN
F 3 "" H 4350 2400 50  0001 C CNN
	1    4350 2400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 5AD33A82
P 2850 2400
F 0 "#PWR0115" H 2850 2150 50  0001 C CNN
F 1 "GND" H 2855 2227 50  0000 C CNN
F 2 "" H 2850 2400 50  0001 C CNN
F 3 "" H 2850 2400 50  0001 C CNN
	1    2850 2400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5AD33ADA
P 1300 2400
F 0 "#PWR0116" H 1300 2150 50  0001 C CNN
F 1 "GND" H 1305 2227 50  0000 C CNN
F 2 "" H 1300 2400 50  0001 C CNN
F 3 "" H 1300 2400 50  0001 C CNN
	1    1300 2400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0117
U 1 1 5AD33C6C
P 5700 1350
F 0 "#PWR0117" H 5700 1200 50  0001 C CNN
F 1 "+5V" H 5715 1523 50  0000 C CNN
F 2 "" H 5700 1350 50  0001 C CNN
F 3 "" H 5700 1350 50  0001 C CNN
	1    5700 1350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0118
U 1 1 5AD33CC0
P 2150 3250
F 0 "#PWR0118" H 2150 3100 50  0001 C CNN
F 1 "+5V" H 2165 3423 50  0000 C CNN
F 2 "" H 2150 3250 50  0001 C CNN
F 3 "" H 2150 3250 50  0001 C CNN
	1    2150 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0119
U 1 1 5AD33CE1
P 4350 900
F 0 "#PWR0119" H 4350 750 50  0001 C CNN
F 1 "+5V" H 4365 1073 50  0000 C CNN
F 2 "" H 4350 900 50  0001 C CNN
F 3 "" H 4350 900 50  0001 C CNN
	1    4350 900 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0120
U 1 1 5AD33D70
P 2850 900
F 0 "#PWR0120" H 2850 750 50  0001 C CNN
F 1 "+5V" H 2865 1073 50  0000 C CNN
F 2 "" H 2850 900 50  0001 C CNN
F 3 "" H 2850 900 50  0001 C CNN
	1    2850 900 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0121
U 1 1 5AD33D91
P 1300 900
F 0 "#PWR0121" H 1300 750 50  0001 C CNN
F 1 "+5V" H 1315 1073 50  0000 C CNN
F 2 "" H 1300 900 50  0001 C CNN
F 3 "" H 1300 900 50  0001 C CNN
	1    1300 900 
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5AD3408D
P 1850 3250
F 0 "#FLG0101" H 1850 3325 50  0001 C CNN
F 1 "PWR_FLAG" H 1850 3424 50  0000 C CNN
F 2 "" H 1850 3250 50  0001 C CNN
F 3 "" H 1850 3250 50  0001 C CNN
	1    1850 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0122
U 1 1 5AD346A9
P 5800 4400
F 0 "#PWR0122" H 5800 4150 50  0001 C CNN
F 1 "GND" V 5805 4272 50  0000 R CNN
F 2 "" H 5800 4400 50  0001 C CNN
F 3 "" H 5800 4400 50  0001 C CNN
	1    5800 4400
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0123
U 1 1 5AD3472C
P 5800 4300
F 0 "#PWR0123" H 5800 4150 50  0001 C CNN
F 1 "+5V" V 5815 4428 50  0000 L CNN
F 2 "" H 5800 4300 50  0001 C CNN
F 3 "" H 5800 4300 50  0001 C CNN
	1    5800 4300
	0    1    1    0   
$EndComp
$Comp
L kicad:SST39SF040 U4
U 1 1 5AD354F7
P 3700 4300
F 0 "U4" H 3700 5725 50  0000 C CNN
F 1 "SST39SF040" H 3700 5634 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm_Socket" H 3700 4600 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 3700 4600 50  0001 C CNN
	1    3700 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0124
U 1 1 5AD35531
P 4300 5350
F 0 "#PWR0124" H 4300 5100 50  0001 C CNN
F 1 "GND" V 4305 5222 50  0000 R CNN
F 2 "" H 4300 5350 50  0001 C CNN
F 3 "" H 4300 5350 50  0001 C CNN
	1    4300 5350
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0125
U 1 1 5AD35568
P 4300 5250
F 0 "#PWR0125" H 4300 5100 50  0001 C CNN
F 1 "+5V" V 4315 5378 50  0000 L CNN
F 2 "" H 4300 5250 50  0001 C CNN
F 3 "" H 4300 5250 50  0001 C CNN
	1    4300 5250
	0    1    1    0   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5AD35B7E
P 5700 1650
F 0 "#FLG0102" H 5700 1725 50  0001 C CNN
F 1 "PWR_FLAG" V 5700 1778 50  0000 L CNN
F 2 "" H 5700 1650 50  0001 C CNN
F 3 "" H 5700 1650 50  0001 C CNN
	1    5700 1650
	0    1    1    0   
$EndComp
Connection ~ 5700 1650
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5AD2C8CB
P 1950 4250
F 0 "A1" H 1950 3164 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 1950 3073 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 2100 3300 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 1950 3250 50  0001 C CNN
	1    1950 4250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x03 SW1
U 1 1 5AF911FD
P 1450 6000
F 0 "SW1" V 1404 6330 50  0000 L CNN
F 1 "SW_DIP_x03" V 1495 6330 50  0000 L CNN
F 2 "Button_Switch_THT:SW_DIP_SPSTx03_Slide_9.78x9.8mm_W7.62mm_P2.54mm" H 1450 6000 50  0001 C CNN
F 3 "" H 1450 6000 50  0001 C CNN
	1    1450 6000
	0    1    1    0   
$EndComp
Wire Wire Line
	1450 4750 1300 4750
Wire Wire Line
	1300 4750 1300 5700
Wire Wire Line
	1300 5700 1450 5700
Wire Wire Line
	1450 4850 1350 4850
Wire Wire Line
	1350 4850 1350 5600
Wire Wire Line
	1350 5600 1550 5600
Wire Wire Line
	1550 5600 1550 5700
Wire Wire Line
	1450 4950 1450 5500
Wire Wire Line
	1450 5500 1650 5500
Wire Wire Line
	1650 5500 1650 5700
$Comp
L power:GND #PWR0126
U 1 1 5AF916B7
P 1450 6300
F 0 "#PWR0126" H 1450 6050 50  0001 C CNN
F 1 "GND" H 1455 6127 50  0000 C CNN
F 2 "" H 1450 6300 50  0001 C CNN
F 3 "" H 1450 6300 50  0001 C CNN
	1    1450 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 6300 1550 6300
Wire Wire Line
	1550 6300 1450 6300
Connection ~ 1550 6300
Connection ~ 1450 6300
$EndSCHEMATC
