EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 20
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
S 10450 950  650  850 
U 5ADF0E03
F0 "Clock" 50
F1 "clock.sch" 50
F2 "CLK" I R 11100 1050 50 
F3 "~RESET" I R 11100 1250 50 
F4 "~CLK" I R 11100 1150 50 
F5 "~RESET_NCLK" I L 10450 1700 50 
$EndSheet
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5AE292E5
P 12900 950
F 0 "#FLG01" H 12900 1025 50  0001 C CNN
F 1 "PWR_FLAG" H 12900 1123 50  0000 C CNN
F 2 "" H 12900 950 50  0001 C CNN
F 3 "~" H 12900 950 50  0001 C CNN
	1    12900 950 
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5AE292FC
P 13200 950
F 0 "#FLG02" H 13200 1025 50  0001 C CNN
F 1 "PWR_FLAG" H 13200 1124 50  0000 C CNN
F 2 "" H 13200 950 50  0001 C CNN
F 3 "~" H 13200 950 50  0001 C CNN
	1    13200 950 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0109
U 1 1 5B05E238
P 12900 950
F 0 "#PWR0109" H 12900 800 50  0001 C CNN
F 1 "VCC" H 12917 1123 50  0000 C CNN
F 2 "" H 12900 950 50  0001 C CNN
F 3 "" H 12900 950 50  0001 C CNN
	1    12900 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5AE29284
P 13200 950
F 0 "#PWR02" H 13200 700 50  0001 C CNN
F 1 "GND" H 13205 777 50  0000 C CNN
F 2 "" H 13200 950 50  0001 C CNN
F 3 "" H 13200 950 50  0001 C CNN
	1    13200 950 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR038
U 1 1 5AFD3766
P 13850 950
F 0 "#PWR038" H 13850 800 50  0001 C CNN
F 1 "VCC" H 13867 1123 50  0000 C CNN
F 2 "" H 13850 950 50  0001 C CNN
F 3 "" H 13850 950 50  0001 C CNN
	1    13850 950 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR039
U 1 1 5AFD387B
P 13850 1350
F 0 "#PWR039" H 13850 1100 50  0001 C CNN
F 1 "GND" H 13855 1177 50  0000 C CNN
F 2 "" H 13850 1350 50  0001 C CNN
F 3 "" H 13850 1350 50  0001 C CNN
	1    13850 1350
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J1
U 1 1 5AFD7056
P 14500 1150
F 0 "J1" H 14580 1192 50  0000 L CNN
F 1 "Conn_01x05" H 14580 1101 50  0000 L CNN
F 2 "Connector_USB:USB_Micro-B_Wuerth_629105150521" H 14500 1150 50  0001 C CNN
F 3 "~" H 14500 1150 50  0001 C CNN
	1    14500 1150
	1    0    0    -1  
$EndComp
NoConn ~ 14300 1050
NoConn ~ 14300 1150
NoConn ~ 14300 1250
Text Label 11100 1250 0    50   ~ 0
~RESET
Text Label 11100 1050 0    50   ~ 0
CLK
$Sheet
S 5750 4550 1150 3300
U 5B09632F
F0 "MMU" 50
F1 "mmu.sch" 50
F2 "BUS0" I R 6900 4650 50 
F3 "BUS1" I R 6900 4750 50 
F4 "BUS2" I R 6900 4850 50 
F5 "BUS3" I R 6900 4950 50 
F6 "BUS4" I R 6900 5050 50 
F7 "BUS5" I R 6900 5150 50 
F8 "BUS6" I R 6900 5250 50 
F9 "BUS7" I R 6900 5350 50 
F10 "~MMU_OUT" I L 5750 4650 50 
F11 "~MMU_IN" I L 5750 4750 50 
F12 "REG_ADDR_IN" I L 5750 4850 50 
F13 "BUS8" I R 6900 5450 50 
F14 "BUS9" I R 6900 5550 50 
F15 "BUS10" I R 6900 5650 50 
F16 "BUS11" I R 6900 5750 50 
F17 "BUS12" I R 6900 5850 50 
F18 "BUS13" I R 6900 5950 50 
F19 "BUS14" I R 6900 6050 50 
F20 "BUS15" I R 6900 6150 50 
F21 "BUS16" I R 6900 6250 50 
F22 "BUS17" I R 6900 6350 50 
F23 "BUS18" I R 6900 6450 50 
F24 "BUS19" I R 6900 6550 50 
F25 "BUS20" I R 6900 6650 50 
F26 "BUS21" I R 6900 6750 50 
F27 "BUS22" I R 6900 6850 50 
F28 "BUS23" I R 6900 6950 50 
F29 "ADDR0" I L 5750 5050 50 
F30 "ADDR1" I L 5750 5150 50 
F31 "ADDR2" I L 5750 5250 50 
F32 "ADDR3" I L 5750 5350 50 
F33 "ADDR4" I L 5750 5450 50 
F34 "ADDR5" I L 5750 5550 50 
F35 "ADDR6" I L 5750 5650 50 
F36 "ADDR7" I L 5750 5750 50 
F37 "ADDR8" I L 5750 5850 50 
F38 "ADDR9" I L 5750 5950 50 
F39 "ADDR10" I L 5750 6050 50 
F40 "ADDR11" I L 5750 6150 50 
F41 "ADDR12" I L 5750 6250 50 
F42 "ADDR13" I L 5750 6350 50 
F43 "ADDR14" I L 5750 6450 50 
F44 "ADDR15" I L 5750 6550 50 
F45 "ADDR16" I L 5750 6650 50 
F46 "ADDR17" I L 5750 6750 50 
F47 "ADDR18" I L 5750 6850 50 
F48 "ADDR19" I L 5750 6950 50 
F49 "ADDR20" I L 5750 7050 50 
F50 "ADDR21" I L 5750 7150 50 
F51 "ADDR22" I L 5750 7250 50 
F52 "ADDR23" I L 5750 7350 50 
F53 "BUS24" I R 6900 7050 50 
F54 "BUS25" I R 6900 7150 50 
F55 "BUS26" I R 6900 7250 50 
F56 "BUS27" I R 6900 7350 50 
F57 "BUS28" I R 6900 7450 50 
F58 "BUS29" I R 6900 7550 50 
F59 "BUS30" I R 6900 7650 50 
F60 "BUS31" I R 6900 7750 50 
F61 "~EEPROM_OUT" I L 5750 4950 50 
$EndSheet
Text Label 6900 4650 0    50   ~ 0
BUS0
Text Label 6900 4750 0    50   ~ 0
BUS1
Text Label 6900 4850 0    50   ~ 0
BUS2
Text Label 6900 4950 0    50   ~ 0
BUS3
Text Label 6900 5050 0    50   ~ 0
BUS4
Text Label 6900 5150 0    50   ~ 0
BUS5
Text Label 6900 5250 0    50   ~ 0
BUS6
Text Label 6900 5350 0    50   ~ 0
BUS7
$Comp
L Device:CP C95
U 1 1 5B0C2BBB
P 13950 2000
F 0 "C95" H 14068 2046 50  0000 L CNN
F 1 "10uF" H 14068 1955 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P2.00mm" H 13988 1850 50  0001 C CNN
F 3 "~" H 13950 2000 50  0001 C CNN
	1    13950 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C96
U 1 1 5B0C2BF7
P 14400 2000
F 0 "C96" H 14518 2046 50  0000 L CNN
F 1 "100uF" H 14518 1955 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 14438 1850 50  0001 C CNN
F 3 "~" H 14400 2000 50  0001 C CNN
	1    14400 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C97
U 1 1 5B0C2C19
P 14900 2000
F 0 "C97" H 15018 2046 50  0000 L CNN
F 1 "470uF" H 15018 1955 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P3.80mm" H 14938 1850 50  0001 C CNN
F 3 "~" H 14900 2000 50  0001 C CNN
	1    14900 2000
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0347
U 1 1 5B0C2C3B
P 13950 1850
F 0 "#PWR0347" H 13950 1700 50  0001 C CNN
F 1 "VCC" H 13967 2023 50  0000 C CNN
F 2 "" H 13950 1850 50  0001 C CNN
F 3 "" H 13950 1850 50  0001 C CNN
	1    13950 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	13950 1850 14400 1850
Connection ~ 13950 1850
Wire Wire Line
	14400 1850 14900 1850
Connection ~ 14400 1850
$Comp
L power:GND #PWR0348
U 1 1 5B0C2C63
P 14900 2150
F 0 "#PWR0348" H 14900 1900 50  0001 C CNN
F 1 "GND" H 14905 1977 50  0000 C CNN
F 2 "" H 14900 2150 50  0001 C CNN
F 3 "" H 14900 2150 50  0001 C CNN
	1    14900 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	14900 2150 14400 2150
Connection ~ 14900 2150
Wire Wire Line
	14400 2150 13950 2150
Connection ~ 14400 2150
Wire Wire Line
	14900 1850 15350 1850
Connection ~ 14900 1850
Wire Wire Line
	14900 2150 15350 2150
Text Notes 14400 1750 0    50   ~ 0
Zener for overvoltage protection.
$Comp
L Device:Polyfuse F1
U 1 1 5B0C553B
P 14050 950
F 0 "F1" V 13825 950 50  0000 C CNN
F 1 "0.65A" V 13916 950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D10.5mm_W5.0mm_P5.00mm" H 14100 750 50  0001 L CNN
F 3 "~" H 14050 950 50  0001 C CNN
	1    14050 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	13850 950  13900 950 
Wire Wire Line
	14200 950  14300 950 
Wire Wire Line
	13850 1350 14300 1350
$Comp
L Device:D_Zener D17
U 1 1 5B0C4FC8
P 15350 2000
F 0 "D17" V 15304 2079 50  0000 L CNN
F 1 "5.6V" V 15395 2079 50  0000 L CNN
F 2 "Diode_THT:D_5W_P12.70mm_Horizontal" H 15350 2000 50  0001 C CNN
F 3 "~" H 15350 2000 50  0001 C CNN
	1    15350 2000
	0    1    1    0   
$EndComp
Text Label 11100 1150 0    50   ~ 0
~CLK
Text Label 7850 2000 2    50   ~ 0
~INT_OUT_NCLK
Text Label 8900 1100 0    50   ~ 0
BUS0
Text Label 8900 1200 0    50   ~ 0
BUS1
Text Label 8900 1300 0    50   ~ 0
BUS2
Text Label 8900 1400 0    50   ~ 0
BUS3
Text Label 8900 1500 0    50   ~ 0
BUS4
Text Label 8900 1600 0    50   ~ 0
BUS5
Text Label 8900 1700 0    50   ~ 0
BUS6
Text Label 8900 1800 0    50   ~ 0
BUS7
Text Label 7850 1100 2    50   ~ 0
INT0
Text Label 7850 1200 2    50   ~ 0
INT1
Text Label 7850 1300 2    50   ~ 0
INT2
Text Label 7850 1400 2    50   ~ 0
INT3
Text Label 7850 1500 2    50   ~ 0
INT4
Text Label 7850 1600 2    50   ~ 0
INT5
Text Label 7850 1700 2    50   ~ 0
INT6
Text Label 7850 1800 2    50   ~ 0
INT7
$Sheet
S 7850 1000 1050 1200
U 5B0FEA60
F0 "Interrupt Register" 50
F1 "register_one_byte.sch" 50
F2 "REG_IN" I L 7850 2100 50 
F3 "I0" I L 7850 1100 50 
F4 "I1" I L 7850 1200 50 
F5 "I2" I L 7850 1300 50 
F6 "I3" I L 7850 1400 50 
F7 "I4" I L 7850 1500 50 
F8 "I5" I L 7850 1600 50 
F9 "I6" I L 7850 1700 50 
F10 "I7" I L 7850 1800 50 
F11 "~REG_OUT" I L 7850 2000 50 
F12 "BUS0" I R 8900 1100 50 
F13 "BUS1" I R 8900 1200 50 
F14 "BUS2" I R 8900 1300 50 
F15 "BUS3" I R 8900 1400 50 
F16 "BUS4" I R 8900 1500 50 
F17 "BUS5" I R 8900 1600 50 
F18 "BUS6" I R 8900 1700 50 
F19 "BUS7" I R 8900 1800 50 
$EndSheet
Text Label 5750 4650 2    50   ~ 0
~MMU_OUT_NCLK
Text Label 5750 4750 2    50   ~ 0
~MMU_IN_CLK
Text Label 1650 1050 2    50   ~ 0
~CLK
Text Label 1650 1150 2    50   ~ 0
CLK
Text Notes 12000 8200 0    50   ~ 0
Spare parts:\n74hc04: Clock, Control Logic\n74hc08: Clock (2) - TODO: can optimise?\n74hc14: Clock\n74hc107: Clock
Text Label 10450 1700 2    50   ~ 0
~RESET_NCLK
Text Label 1650 1250 2    50   ~ 0
~RESET
Text Label 14800 3250 2    50   ~ 0
CLK
Text Label 14800 3350 2    50   ~ 0
~CLK
Text Label 14800 3050 2    50   ~ 0
VCC
$Comp
L Connector_Generic:Conn_01x03 J3
U 1 1 5B1CC982
P 15500 1150
F 0 "J3" H 15580 1192 50  0000 L CNN
F 1 "Conn_01x03" H 15580 1101 50  0000 L CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 15500 1150 50  0001 C CNN
F 3 "~" H 15500 1150 50  0001 C CNN
	1    15500 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5B1CCAB4
P 15300 1150
F 0 "#PWR01" H 15300 900 50  0001 C CNN
F 1 "GND" H 15305 977 50  0000 C CNN
F 2 "" H 15300 1150 50  0001 C CNN
F 3 "" H 15300 1150 50  0001 C CNN
	1    15300 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	15300 1050 15300 750 
Wire Wire Line
	15300 750  14300 750 
Wire Wire Line
	14300 750  14300 950 
Connection ~ 14300 950 
NoConn ~ 15300 1250
Text Notes 14350 7850 0    50   ~ 0
Used spares:\n74hc04: 1 in ALU from Clock
$Sheet
S 1650 950  2050 6450
U 5B0C6DCD
F0 "Control Logic" 50
F1 "control_logic.sch" 50
F2 "~CLK" I L 1650 1050 50 
F3 "CLK" I L 1650 1150 50 
F4 "~RESET" I L 1650 1250 50 
F5 "~RESET_NCLK" I R 3700 1050 50 
F6 "BUS0" I L 1650 1350 50 
F7 "BUS1" I L 1650 1450 50 
F8 "BUS2" I L 1650 1550 50 
F9 "BUS3" I L 1650 1650 50 
F10 "BUS4" I L 1650 1750 50 
F11 "BUS5" I L 1650 1850 50 
F12 "BUS6" I L 1650 1950 50 
F13 "BUS7" I L 1650 2050 50 
F14 "~MMU_IN_CLK" I R 3700 3650 50 
F15 "~A_OUT_NCLK" I R 3700 1450 50 
F16 "~B_OUT_NCLK" I R 3700 1550 50 
F17 "~SP_OUT_NCLK" I R 3700 1650 50 
F18 "~PC_OUT_NCLK" I R 3700 1750 50 
F19 "~SUM_OUT_NCLK" I R 3700 1850 50 
F20 "~NAND_OUT_NCLK" I R 3700 1950 50 
F21 "~MMU_OUT_NCLK" I R 3700 2050 50 
F22 "~INT_OUT_NCLK" I R 3700 2150 50 
F23 "~STATUS_OUT_NCLK" I R 3700 2250 50 
F24 "~EEPROM_OUT_NCLK" I R 3700 2350 50 
F25 "~M_OUT_NCLK" I R 3700 2450 50 
F26 "A_IN_CLK" I R 3700 2950 50 
F27 "B_IN_CLK" I R 3700 3050 50 
F28 "M_IN_CLK" I R 3700 3750 50 
F29 "SP_IN_CLK" I R 3700 3150 50 
F30 "PC_IN_CLK" I R 3700 3250 50 
F31 "ALU0_IN_CLK" I R 3700 3350 50 
F32 "ALU1_IN_CLK" I R 3700 3450 50 
F33 "ADDR_IN_CLK" I R 3700 3550 50 
F34 "M0_IN_CLK" I R 3700 3850 50 
F35 "M1_IN_CLK" I R 3700 3950 50 
F36 "M2_IN_CLK" I R 3700 4050 50 
F37 "M3_IN_CLK" I R 3700 4150 50 
F38 "~PAGE_OUT_NCLK" I R 3700 2550 50 
F39 "PAGE_IN_CLK" I R 3700 4250 50 
F40 "BUS8" I L 1650 2150 50 
F41 "BUS9" I L 1650 2250 50 
F42 "BUS10" I L 1650 2350 50 
F43 "BUS11" I L 1650 2450 50 
F44 "BUS12" I L 1650 2550 50 
F45 "BUS13" I L 1650 2650 50 
F46 "BUS14" I L 1650 2750 50 
F47 "BUS15" I L 1650 2850 50 
F48 "BUS16" I L 1650 2950 50 
F49 "BUS17" I L 1650 3050 50 
F50 "BUS18" I L 1650 3150 50 
F51 "BUS19" I L 1650 3250 50 
F52 "BUS20" I L 1650 3350 50 
F53 "BUS21" I L 1650 3450 50 
F54 "BUS22" I L 1650 3550 50 
F55 "BUS23" I L 1650 3650 50 
F56 "BUS24" I L 1650 3750 50 
F57 "BUS25" I L 1650 3850 50 
F58 "BUS26" I L 1650 3950 50 
F59 "BUS27" I L 1650 4050 50 
F60 "BUS28" I L 1650 4150 50 
F61 "BUS29" I L 1650 4250 50 
F62 "BUS30" I L 1650 4350 50 
F63 "BUS31" I L 1650 4450 50 
F64 "STATUS_IN_CLK" I R 3700 4350 50 
F65 "CARRY_IN" I R 3700 1150 50 
F66 "INT_IN_CLK" I R 3700 4450 50 
F67 "~ALU_STATUS_OUT_NCLK" I R 3700 2650 50 
$EndSheet
Text Label 13000 1950 0    50   ~ 0
INT0
Text Label 13000 2050 0    50   ~ 0
INT1
Text Label 13000 2150 0    50   ~ 0
INT2
Text Label 13000 2250 0    50   ~ 0
INT3
Text Label 13000 2350 0    50   ~ 0
INT4
Text Label 13000 2450 0    50   ~ 0
INT5
Text Label 13000 2550 0    50   ~ 0
INT6
Text Label 13000 2650 0    50   ~ 0
INT7
$Comp
L Device:R_Network08 RN1
U 1 1 5B786556
P 12800 2250
F 0 "RN1" V 13317 2250 50  0000 C CNN
F 1 "10K" V 13226 2250 50  0000 C CNN
F 2 "Resistor_THT:R_Array_SIP9" V 13275 2250 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 12800 2250 50  0001 C CNN
	1    12800 2250
	0    -1   -1   0   
$EndComp
Text Notes 12500 2850 0    50   ~ 0
Pull interrupt lines low.
Text Label 7850 2100 2    50   ~ 0
INT_IN_CLK
$Sheet
S 8100 4500 1100 3300
U 5B9E2640
F0 "ALU" 50
F1 "alu.sch" 50
F2 "CARRY_IN" I L 8100 4800 50 
F3 "~SUM_OUT" I L 8100 5200 50 
F4 "BUS0" I R 9200 4600 50 
F5 "BUS1" I R 9200 4700 50 
F6 "BUS2" I R 9200 4800 50 
F7 "BUS3" I R 9200 4900 50 
F8 "BUS4" I R 9200 5000 50 
F9 "BUS5" I R 9200 5100 50 
F10 "BUS6" I R 9200 5200 50 
F11 "BUS7" I R 9200 5300 50 
F12 "REG_ALU0_IN" I L 8100 4900 50 
F13 "BUS8" I R 9200 5400 50 
F14 "BUS9" I R 9200 5500 50 
F15 "BUS10" I R 9200 5600 50 
F16 "BUS11" I R 9200 5700 50 
F17 "BUS12" I R 9200 5800 50 
F18 "BUS13" I R 9200 5900 50 
F19 "BUS14" I R 9200 6000 50 
F20 "BUS15" I R 9200 6100 50 
F21 "BUS16" I R 9200 6200 50 
F22 "BUS17" I R 9200 6300 50 
F23 "BUS18" I R 9200 6400 50 
F24 "BUS19" I R 9200 6500 50 
F25 "BUS20" I R 9200 6600 50 
F26 "BUS21" I R 9200 6700 50 
F27 "BUS22" I R 9200 6800 50 
F28 "BUS23" I R 9200 6900 50 
F29 "BUS24" I R 9200 7000 50 
F30 "BUS25" I R 9200 7100 50 
F31 "BUS26" I R 9200 7200 50 
F32 "BUS27" I R 9200 7300 50 
F33 "BUS28" I R 9200 7400 50 
F34 "BUS29" I R 9200 7500 50 
F35 "BUS30" I R 9200 7600 50 
F36 "BUS31" I R 9200 7700 50 
F37 "REG_ALU1_IN" I L 8100 5000 50 
F38 "~NAND_OUT" I L 8100 5100 50 
F39 "~ALU_STATUS_OUT" I L 8100 4700 50 
$EndSheet
$Sheet
S 5750 1000 1100 3300
U 5AFD5CE2
F0 "Registers" 50
F1 "registers.sch" 50
F2 "BUS0" I R 6850 1100 50 
F3 "BUS1" I R 6850 1200 50 
F4 "BUS2" I R 6850 1300 50 
F5 "BUS3" I R 6850 1400 50 
F6 "BUS4" I R 6850 1500 50 
F7 "BUS5" I R 6850 1600 50 
F8 "BUS6" I R 6850 1700 50 
F9 "BUS7" I R 6850 1800 50 
F10 "REG_A_IN" I L 5750 1100 50 
F11 "~REG_A_OUT" I L 5750 1200 50 
F12 "BUS8" I R 6850 1900 50 
F13 "BUS9" I R 6850 2000 50 
F14 "BUS10" I R 6850 2100 50 
F15 "BUS11" I R 6850 2200 50 
F16 "BUS12" I R 6850 2300 50 
F17 "BUS13" I R 6850 2400 50 
F18 "BUS14" I R 6850 2500 50 
F19 "BUS15" I R 6850 2600 50 
F20 "BUS16" I R 6850 2700 50 
F21 "BUS17" I R 6850 2800 50 
F22 "BUS18" I R 6850 2900 50 
F23 "BUS19" I R 6850 3000 50 
F24 "BUS20" I R 6850 3100 50 
F25 "BUS21" I R 6850 3200 50 
F26 "BUS22" I R 6850 3300 50 
F27 "BUS23" I R 6850 3400 50 
F28 "BUS24" I R 6850 3500 50 
F29 "BUS25" I R 6850 3600 50 
F30 "BUS26" I R 6850 3700 50 
F31 "BUS27" I R 6850 3800 50 
F32 "BUS28" I R 6850 3900 50 
F33 "BUS29" I R 6850 4000 50 
F34 "BUS30" I R 6850 4100 50 
F35 "BUS31" I R 6850 4200 50 
F36 "REG_B_IN" I L 5750 1300 50 
F37 "~REG_B_OUT" I L 5750 1400 50 
F38 "REG_SP_IN" I L 5750 1500 50 
F39 "~REG_SP_OUT" I L 5750 1600 50 
F40 "REG_PC_IN" I L 5750 1700 50 
F41 "~REG_PC_OUT" I L 5750 1800 50 
F42 "REG_M_IN" I L 5750 1900 50 
F43 "~REG_M_OUT" I L 5750 2000 50 
F44 "REG_M0_IN" I L 5750 2100 50 
F45 "REG_M1_IN" I L 5750 2200 50 
F46 "REG_M2_IN" I L 5750 2300 50 
F47 "REG_M3_IN" I L 5750 2400 50 
F48 "REG_PAGE_IN" I L 5750 2500 50 
F49 "~REG_PAGE_OUT" I L 5750 2600 50 
$EndSheet
Text Label 6850 1100 0    50   ~ 0
BUS0
Text Label 6850 1200 0    50   ~ 0
BUS1
Text Label 6850 1300 0    50   ~ 0
BUS2
Text Label 6850 1400 0    50   ~ 0
BUS3
Text Label 6850 1500 0    50   ~ 0
BUS4
Text Label 6850 1600 0    50   ~ 0
BUS5
Text Label 6850 1700 0    50   ~ 0
BUS6
Text Label 6850 1800 0    50   ~ 0
BUS7
Text Label 6850 1900 0    50   ~ 0
BUS8
Text Label 6850 2000 0    50   ~ 0
BUS9
Text Label 6850 2100 0    50   ~ 0
BUS10
Text Label 6850 2200 0    50   ~ 0
BUS11
Text Label 6850 2300 0    50   ~ 0
BUS12
Text Label 6850 2400 0    50   ~ 0
BUS13
Text Label 6850 2500 0    50   ~ 0
BUS14
Text Label 6850 2600 0    50   ~ 0
BUS15
Text Label 6850 2700 0    50   ~ 0
BUS16
Text Label 6850 2800 0    50   ~ 0
BUS17
Text Label 6850 2900 0    50   ~ 0
BUS18
Text Label 6850 3000 0    50   ~ 0
BUS19
Text Label 6850 3100 0    50   ~ 0
BUS20
Text Label 6850 3200 0    50   ~ 0
BUS21
Text Label 6850 3300 0    50   ~ 0
BUS22
Text Label 6850 3400 0    50   ~ 0
BUS23
Text Label 6850 3500 0    50   ~ 0
BUS24
Text Label 6850 3600 0    50   ~ 0
BUS25
Text Label 6850 3700 0    50   ~ 0
BUS26
Text Label 6850 3800 0    50   ~ 0
BUS27
Text Label 6850 3900 0    50   ~ 0
BUS28
Text Label 6850 4000 0    50   ~ 0
BUS29
Text Label 6850 4100 0    50   ~ 0
BUS30
Text Label 6850 4200 0    50   ~ 0
BUS31
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J2
U 1 1 5B1BB7C0
P 15000 3950
F 0 "J2" H 15050 5067 50  0000 C CNN
F 1 "Conn_02x20_Odd_Even" H 15050 4976 50  0000 C CNN
F 2 "Connector_IDC:IDC-Header_2x20_P2.54mm_Vertical" H 15000 3950 50  0001 C CNN
F 3 "~" H 15000 3950 50  0001 C CNN
	1    15000 3950
	1    0    0    -1  
$EndComp
Text Label 14800 3150 2    50   ~ 0
GND
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J4
U 1 1 5BA02487
P 15000 6000
F 0 "J4" H 15050 6000 50  0000 C CNN
F 1 "Conn_02x20_Odd_Even" H 15050 4850 50  0000 C CNN
F 2 "Connector_IDC:IDC-Header_2x20_P2.54mm_Vertical" H 15000 6000 50  0001 C CNN
F 3 "~" H 15000 6000 50  0001 C CNN
	1    15000 6000
	1    0    0    -1  
$EndComp
Text Label 14800 3450 2    50   ~ 0
~MMU_IN_CLK
Text Label 14800 3550 2    50   ~ 0
~MMU_OUT_NCLK
Text Label 6900 5450 0    50   ~ 0
BUS8
Text Label 6900 5550 0    50   ~ 0
BUS9
Text Label 6900 5650 0    50   ~ 0
BUS10
Text Label 6900 5750 0    50   ~ 0
BUS11
Text Label 6900 5850 0    50   ~ 0
BUS12
Text Label 6900 5950 0    50   ~ 0
BUS13
Text Label 6900 6050 0    50   ~ 0
BUS14
Text Label 6900 6150 0    50   ~ 0
BUS15
Text Label 6900 6250 0    50   ~ 0
BUS16
Text Label 6900 6350 0    50   ~ 0
BUS17
Text Label 6900 6450 0    50   ~ 0
BUS18
Text Label 6900 6550 0    50   ~ 0
BUS19
Text Label 6900 6650 0    50   ~ 0
BUS20
Text Label 6900 6750 0    50   ~ 0
BUS21
Text Label 6900 6850 0    50   ~ 0
BUS22
Text Label 6900 6950 0    50   ~ 0
BUS23
Text Label 6900 7050 0    50   ~ 0
BUS24
Text Label 6900 7150 0    50   ~ 0
BUS25
Text Label 6900 7250 0    50   ~ 0
BUS26
Text Label 6900 7350 0    50   ~ 0
BUS27
Text Label 6900 7450 0    50   ~ 0
BUS28
Text Label 6900 7550 0    50   ~ 0
BUS29
Text Label 6900 7650 0    50   ~ 0
BUS30
Text Label 6900 7750 0    50   ~ 0
BUS31
Text Label 5750 5050 2    50   ~ 0
ADDR0
Text Label 5750 5150 2    50   ~ 0
ADDR1
Text Label 5750 5250 2    50   ~ 0
ADDR2
Text Label 5750 5350 2    50   ~ 0
ADDR3
Text Label 5750 5450 2    50   ~ 0
ADDR4
Text Label 5750 5550 2    50   ~ 0
ADDR5
Text Label 5750 5650 2    50   ~ 0
ADDR6
Text Label 5750 5750 2    50   ~ 0
ADDR7
Text Label 5750 5850 2    50   ~ 0
ADDR8
Text Label 5750 5950 2    50   ~ 0
ADDR9
Text Label 5750 6050 2    50   ~ 0
ADDR10
Text Label 5750 6150 2    50   ~ 0
ADDR11
Text Label 5750 6250 2    50   ~ 0
ADDR12
Text Label 5750 6350 2    50   ~ 0
ADDR13
Text Label 5750 6450 2    50   ~ 0
ADDR14
Text Label 5750 6550 2    50   ~ 0
ADDR15
Text Label 5750 6650 2    50   ~ 0
ADDR16
Text Label 5750 6750 2    50   ~ 0
ADDR17
Text Label 5750 6850 2    50   ~ 0
ADDR18
Text Label 5750 6950 2    50   ~ 0
ADDR19
Text Label 5750 7050 2    50   ~ 0
ADDR20
Text Label 5750 7150 2    50   ~ 0
ADDR21
Text Label 5750 7250 2    50   ~ 0
ADDR22
Text Label 5750 7350 2    50   ~ 0
ADDR23
Text Label 5750 4950 2    50   ~ 0
~EEPROM_OUT_NCLK
Text Label 5750 4850 2    50   ~ 0
ADDR_IN_CLK
Text Label 3700 2950 0    50   ~ 0
A_IN_CLK
Text Label 3700 3050 0    50   ~ 0
B_IN_CLK
Text Label 3700 3150 0    50   ~ 0
SP_IN_CLK
Text Label 3700 3250 0    50   ~ 0
PC_IN_CLK
Text Label 3700 3350 0    50   ~ 0
ALU0_IN_CLK
Text Label 3700 3450 0    50   ~ 0
ALU1_IN_CLK
Text Label 3700 3550 0    50   ~ 0
ADDR_IN_CLK
Text Label 3700 3650 0    50   ~ 0
~MMU_IN_CLK
Text Label 3700 3750 0    50   ~ 0
M_IN_CLK
Text Label 3700 3850 0    50   ~ 0
M0_IN_CLK
Text Label 3700 3950 0    50   ~ 0
M1_IN_CLK
Text Label 3700 4050 0    50   ~ 0
M2_IN_CLK
Text Label 3700 4150 0    50   ~ 0
M3_IN_CLK
Text Label 3700 1450 0    50   ~ 0
~A_OUT_NCLK
Text Label 3700 1550 0    50   ~ 0
~B_OUT_NCLK
Text Label 3700 1650 0    50   ~ 0
~SP_OUT_NCLK
Text Label 3700 1750 0    50   ~ 0
~PC_OUT_NCLK
Text Label 3700 1850 0    50   ~ 0
~SUM_OUT_NCLK
Text Label 3700 1950 0    50   ~ 0
~NAND_OUT_NCLK
Text Label 3700 2050 0    50   ~ 0
~MMU_OUT_NCLK
Text Label 3700 2150 0    50   ~ 0
~INT_OUT_NCLK
Text Label 3700 2250 0    50   ~ 0
~STATUS_OUT_NCLK
Text Label 3700 2350 0    50   ~ 0
~EEPROM_OUT_NCLK
Text Label 3700 2450 0    50   ~ 0
~M_OUT_NCLK
Text Label 5750 1200 2    50   ~ 0
~A_OUT_NCLK
Text Label 5750 1400 2    50   ~ 0
~B_OUT_NCLK
Text Label 5750 1600 2    50   ~ 0
~SP_OUT_NCLK
Text Label 5750 1800 2    50   ~ 0
~PC_OUT_NCLK
Text Label 8100 5200 2    50   ~ 0
~SUM_OUT_NCLK
Text Label 8100 5100 2    50   ~ 0
~NAND_OUT_NCLK
Text Label 5750 2000 2    50   ~ 0
~M_OUT_NCLK
Text Label 5750 1100 2    50   ~ 0
A_IN_CLK
Text Label 5750 1300 2    50   ~ 0
B_IN_CLK
Text Label 5750 1500 2    50   ~ 0
SP_IN_CLK
Text Label 5750 1700 2    50   ~ 0
PC_IN_CLK
Text Label 8100 4900 2    50   ~ 0
ALU0_IN_CLK
Text Label 8100 5000 2    50   ~ 0
ALU1_IN_CLK
Text Label 5750 1900 2    50   ~ 0
M_IN_CLK
Text Label 5750 2100 2    50   ~ 0
M0_IN_CLK
Text Label 5750 2200 2    50   ~ 0
M1_IN_CLK
Text Label 5750 2300 2    50   ~ 0
M2_IN_CLK
Text Label 5750 2400 2    50   ~ 0
M3_IN_CLK
Text Label 3700 2550 0    50   ~ 0
~PAGE_OUT_NCLK
Text Label 3700 4250 0    50   ~ 0
PAGE_IN_CLK
Text Label 5750 2600 2    50   ~ 0
~PAGE_OUT_NCLK
Text Label 5750 2500 2    50   ~ 0
PAGE_IN_CLK
NoConn ~ 15300 6300
NoConn ~ 15300 6400
NoConn ~ 15300 6500
NoConn ~ 15300 6600
NoConn ~ 15300 6700
NoConn ~ 15300 6800
NoConn ~ 15300 6900
NoConn ~ 15300 7000
Text Label 7850 3550 2    50   ~ 0
~STATUS_OUT_NCLK
Text Label 8900 2650 0    50   ~ 0
BUS0
Text Label 8900 2750 0    50   ~ 0
BUS1
Text Label 8900 2850 0    50   ~ 0
BUS2
Text Label 8900 2950 0    50   ~ 0
BUS3
Text Label 8900 3050 0    50   ~ 0
BUS4
Text Label 8900 3150 0    50   ~ 0
BUS5
Text Label 8900 3250 0    50   ~ 0
BUS6
Text Label 8900 3350 0    50   ~ 0
BUS7
$Sheet
S 7850 2550 1050 1200
U 5BA101FE
F0 "Status Register" 50
F1 "register_one_byte.sch" 50
F2 "REG_IN" I L 7850 3650 50 
F3 "I0" I L 7850 2650 50 
F4 "I1" I L 7850 2750 50 
F5 "I2" I L 7850 2850 50 
F6 "I3" I L 7850 2950 50 
F7 "I4" I L 7850 3050 50 
F8 "I5" I L 7850 3150 50 
F9 "I6" I L 7850 3250 50 
F10 "I7" I L 7850 3350 50 
F11 "~REG_OUT" I L 7850 3550 50 
F12 "BUS0" I R 8900 2650 50 
F13 "BUS1" I R 8900 2750 50 
F14 "BUS2" I R 8900 2850 50 
F15 "BUS3" I R 8900 2950 50 
F16 "BUS4" I R 8900 3050 50 
F17 "BUS5" I R 8900 3150 50 
F18 "BUS6" I R 8900 3250 50 
F19 "BUS7" I R 8900 3350 50 
$EndSheet
Text Label 7850 3650 2    50   ~ 0
STATUS_IN_CLK
Text Label 7850 2650 2    50   ~ 0
BUS0
Text Label 7850 2750 2    50   ~ 0
BUS1
Text Label 7850 2850 2    50   ~ 0
BUS2
Text Label 7850 2950 2    50   ~ 0
BUS3
Text Label 7850 3050 2    50   ~ 0
BUS4
Text Label 7850 3150 2    50   ~ 0
BUS5
Text Label 7850 3250 2    50   ~ 0
BUS6
Text Label 7850 3350 2    50   ~ 0
BUS7
Text Label 3700 4350 0    50   ~ 0
STATUS_IN_CLK
Text Label 1650 1350 2    50   ~ 0
BUS0
Text Label 1650 1450 2    50   ~ 0
BUS1
Text Label 1650 1550 2    50   ~ 0
BUS2
Text Label 1650 1650 2    50   ~ 0
BUS3
Text Label 1650 1750 2    50   ~ 0
BUS4
Text Label 1650 1850 2    50   ~ 0
BUS5
Text Label 1650 1950 2    50   ~ 0
BUS6
Text Label 1650 2050 2    50   ~ 0
BUS7
Text Label 1650 2150 2    50   ~ 0
BUS8
Text Label 1650 2250 2    50   ~ 0
BUS9
Text Label 1650 2350 2    50   ~ 0
BUS10
Text Label 1650 2450 2    50   ~ 0
BUS11
Text Label 1650 2550 2    50   ~ 0
BUS12
Text Label 1650 2650 2    50   ~ 0
BUS13
Text Label 1650 2750 2    50   ~ 0
BUS14
Text Label 1650 2850 2    50   ~ 0
BUS15
Text Label 1650 2950 2    50   ~ 0
BUS16
Text Label 1650 3050 2    50   ~ 0
BUS17
Text Label 1650 3150 2    50   ~ 0
BUS18
Text Label 1650 3250 2    50   ~ 0
BUS19
Text Label 1650 3350 2    50   ~ 0
BUS20
Text Label 1650 3450 2    50   ~ 0
BUS21
Text Label 1650 3550 2    50   ~ 0
BUS22
Text Label 1650 3650 2    50   ~ 0
BUS23
Text Label 1650 3750 2    50   ~ 0
BUS24
Text Label 1650 3850 2    50   ~ 0
BUS25
Text Label 1650 3950 2    50   ~ 0
BUS26
Text Label 1650 4050 2    50   ~ 0
BUS27
Text Label 1650 4150 2    50   ~ 0
BUS28
Text Label 1650 4250 2    50   ~ 0
BUS29
Text Label 1650 4350 2    50   ~ 0
BUS30
Text Label 1650 4450 2    50   ~ 0
BUS31
Text Label 9200 4600 0    50   ~ 0
BUS0
Text Label 9200 4700 0    50   ~ 0
BUS1
Text Label 9200 4800 0    50   ~ 0
BUS2
Text Label 9200 4900 0    50   ~ 0
BUS3
Text Label 9200 5000 0    50   ~ 0
BUS4
Text Label 9200 5100 0    50   ~ 0
BUS5
Text Label 9200 5200 0    50   ~ 0
BUS6
Text Label 9200 5300 0    50   ~ 0
BUS7
Text Label 9200 5400 0    50   ~ 0
BUS8
Text Label 9200 5500 0    50   ~ 0
BUS9
Text Label 9200 5600 0    50   ~ 0
BUS10
Text Label 9200 5700 0    50   ~ 0
BUS11
Text Label 9200 5800 0    50   ~ 0
BUS12
Text Label 9200 5900 0    50   ~ 0
BUS13
Text Label 9200 6000 0    50   ~ 0
BUS14
Text Label 9200 6100 0    50   ~ 0
BUS15
Text Label 9200 6200 0    50   ~ 0
BUS16
Text Label 9200 6300 0    50   ~ 0
BUS17
Text Label 9200 6400 0    50   ~ 0
BUS18
Text Label 9200 6500 0    50   ~ 0
BUS19
Text Label 9200 6600 0    50   ~ 0
BUS20
Text Label 9200 6700 0    50   ~ 0
BUS21
Text Label 9200 6800 0    50   ~ 0
BUS22
Text Label 9200 6900 0    50   ~ 0
BUS23
Text Label 9200 7000 0    50   ~ 0
BUS24
Text Label 9200 7100 0    50   ~ 0
BUS25
Text Label 9200 7200 0    50   ~ 0
BUS26
Text Label 9200 7300 0    50   ~ 0
BUS27
Text Label 9200 7400 0    50   ~ 0
BUS28
Text Label 9200 7500 0    50   ~ 0
BUS29
Text Label 9200 7600 0    50   ~ 0
BUS30
Text Label 9200 7700 0    50   ~ 0
BUS31
Text Notes 12300 3300 0    50   ~ 0
Pull bus lines low
Text Label 3700 1050 0    50   ~ 0
~RESET_NCLK
Text Label 3700 1150 0    50   ~ 0
CARRY_IN
Text Label 8100 4800 2    50   ~ 0
CARRY_IN
Text Label 3700 4450 0    50   ~ 0
INT_IN_CLK
$Comp
L Device:R_Network08 RN4
U 1 1 5BAB97B6
P 13550 3950
F 0 "RN4" V 14067 3950 50  0000 C CNN
F 1 "100K" V 13976 3950 50  0000 C CNN
F 2 "Resistor_THT:R_Array_SIP9" V 14025 3950 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 13550 3950 50  0001 C CNN
	1    13550 3950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Network08 RN5
U 1 1 5BAB9838
P 13550 5000
F 0 "RN5" V 14067 5000 50  0000 C CNN
F 1 "100K" V 13976 5000 50  0000 C CNN
F 2 "Resistor_THT:R_Array_SIP9" V 14025 5000 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 13550 5000 50  0001 C CNN
	1    13550 5000
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Network08 RN3
U 1 1 5BAB9C4B
P 12650 5000
F 0 "RN3" V 13167 5000 50  0000 C CNN
F 1 "100K" V 13076 5000 50  0000 C CNN
F 2 "Resistor_THT:R_Array_SIP9" V 13125 5000 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 12650 5000 50  0001 C CNN
	1    12650 5000
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Network08 RN2
U 1 1 5BAB9CA5
P 12650 3950
F 0 "RN2" V 13167 3950 50  0000 C CNN
F 1 "100K" V 13076 3950 50  0000 C CNN
F 2 "Resistor_THT:R_Array_SIP9" V 13125 3950 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 12650 3950 50  0001 C CNN
	1    12650 3950
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR061
U 1 1 5BAB9DF2
P 12600 2650
F 0 "#PWR061" H 12600 2400 50  0001 C CNN
F 1 "GND" V 12605 2522 50  0000 R CNN
F 2 "" H 12600 2650 50  0001 C CNN
F 3 "" H 12600 2650 50  0001 C CNN
	1    12600 2650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR057
U 1 1 5BAB9E2E
P 12450 4350
F 0 "#PWR057" H 12450 4100 50  0001 C CNN
F 1 "GND" V 12455 4222 50  0000 R CNN
F 2 "" H 12450 4350 50  0001 C CNN
F 3 "" H 12450 4350 50  0001 C CNN
	1    12450 4350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR058
U 1 1 5BAB9F7B
P 12450 5400
F 0 "#PWR058" H 12450 5150 50  0001 C CNN
F 1 "GND" V 12455 5272 50  0000 R CNN
F 2 "" H 12450 5400 50  0001 C CNN
F 3 "" H 12450 5400 50  0001 C CNN
	1    12450 5400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR081
U 1 1 5BAB9FA2
P 13350 4350
F 0 "#PWR081" H 13350 4100 50  0001 C CNN
F 1 "GND" V 13355 4222 50  0000 R CNN
F 2 "" H 13350 4350 50  0001 C CNN
F 3 "" H 13350 4350 50  0001 C CNN
	1    13350 4350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR084
U 1 1 5BABA0FD
P 13350 5400
F 0 "#PWR084" H 13350 5150 50  0001 C CNN
F 1 "GND" V 13355 5272 50  0000 R CNN
F 2 "" H 13350 5400 50  0001 C CNN
F 3 "" H 13350 5400 50  0001 C CNN
	1    13350 5400
	0    1    1    0   
$EndComp
Text Label 12850 3650 0    50   ~ 0
BUS0
Text Label 12850 3750 0    50   ~ 0
BUS1
Text Label 12850 3850 0    50   ~ 0
BUS2
Text Label 12850 3950 0    50   ~ 0
BUS3
Text Label 12850 4050 0    50   ~ 0
BUS4
Text Label 12850 4150 0    50   ~ 0
BUS5
Text Label 12850 4250 0    50   ~ 0
BUS6
Text Label 12850 4350 0    50   ~ 0
BUS7
Text Label 12850 4700 0    50   ~ 0
BUS8
Text Label 12850 4800 0    50   ~ 0
BUS9
Text Label 12850 4900 0    50   ~ 0
BUS10
Text Label 12850 5000 0    50   ~ 0
BUS11
Text Label 12850 5100 0    50   ~ 0
BUS12
Text Label 12850 5200 0    50   ~ 0
BUS13
Text Label 12850 5300 0    50   ~ 0
BUS14
Text Label 12850 5400 0    50   ~ 0
BUS15
Text Label 13750 3650 0    50   ~ 0
BUS16
Text Label 13750 3750 0    50   ~ 0
BUS17
Text Label 13750 3850 0    50   ~ 0
BUS18
Text Label 13750 3950 0    50   ~ 0
BUS19
Text Label 13750 4050 0    50   ~ 0
BUS20
Text Label 13750 4150 0    50   ~ 0
BUS21
Text Label 13750 4250 0    50   ~ 0
BUS22
Text Label 13750 4350 0    50   ~ 0
BUS23
Text Label 13750 4700 0    50   ~ 0
BUS24
Text Label 13750 4800 0    50   ~ 0
BUS25
Text Label 13750 4900 0    50   ~ 0
BUS26
Text Label 13750 5000 0    50   ~ 0
BUS27
Text Label 13750 5100 0    50   ~ 0
BUS28
Text Label 13750 5200 0    50   ~ 0
BUS29
Text Label 13750 5300 0    50   ~ 0
BUS30
Text Label 13750 5400 0    50   ~ 0
BUS31
Text Label 8100 4700 2    50   ~ 0
~ALU_STATUS_OUT_NCLK
Text Label 3700 2650 0    50   ~ 0
~ALU_STATUS_OUT_NCLK
NoConn ~ 14800 6900
NoConn ~ 14800 7000
Text Label 14800 3650 2    50   ~ 0
INT0
Text Label 14800 3750 2    50   ~ 0
INT1
Text Label 14800 3850 2    50   ~ 0
INT2
Text Label 14800 3950 2    50   ~ 0
INT3
Text Label 14800 4050 2    50   ~ 0
INT4
Text Label 14800 4150 2    50   ~ 0
INT5
Text Label 14800 4250 2    50   ~ 0
INT6
Text Label 14800 4350 2    50   ~ 0
INT7
Text Label 14800 4450 2    50   ~ 0
ADDR0
Text Label 14800 4550 2    50   ~ 0
ADDR1
Text Label 14800 4650 2    50   ~ 0
ADDR2
Text Label 14800 4750 2    50   ~ 0
ADDR3
Text Label 14800 4850 2    50   ~ 0
ADDR4
Text Label 14800 4950 2    50   ~ 0
ADDR5
Text Label 14800 5100 2    50   ~ 0
ADDR6
Text Label 14800 5200 2    50   ~ 0
ADDR7
Text Label 14800 5300 2    50   ~ 0
ADDR8
Text Label 14800 5400 2    50   ~ 0
ADDR9
Text Label 14800 5500 2    50   ~ 0
ADDR10
Text Label 14800 5600 2    50   ~ 0
ADDR11
Text Label 14800 5700 2    50   ~ 0
ADDR12
Text Label 14800 5800 2    50   ~ 0
ADDR13
Text Label 14800 5900 2    50   ~ 0
ADDR14
Text Label 14800 6000 2    50   ~ 0
ADDR15
Text Label 14800 6100 2    50   ~ 0
ADDR16
Text Label 14800 6200 2    50   ~ 0
ADDR17
Text Label 14800 6300 2    50   ~ 0
ADDR18
Text Label 14800 6400 2    50   ~ 0
ADDR19
Text Label 14800 6500 2    50   ~ 0
ADDR20
Text Label 14800 6600 2    50   ~ 0
ADDR21
Text Label 14800 6700 2    50   ~ 0
ADDR22
Text Label 14800 6800 2    50   ~ 0
ADDR23
Text Label 15300 3050 0    50   ~ 0
BUS0
Text Label 15300 3150 0    50   ~ 0
BUS1
Text Label 15300 3250 0    50   ~ 0
BUS2
Text Label 15300 3350 0    50   ~ 0
BUS3
Text Label 15300 3450 0    50   ~ 0
BUS4
Text Label 15300 3550 0    50   ~ 0
BUS5
Text Label 15300 3650 0    50   ~ 0
BUS6
Text Label 15300 3750 0    50   ~ 0
BUS7
Text Label 15300 3850 0    50   ~ 0
BUS8
Text Label 15300 3950 0    50   ~ 0
BUS9
Text Label 15300 4050 0    50   ~ 0
BUS10
Text Label 15300 4150 0    50   ~ 0
BUS11
Text Label 15300 4250 0    50   ~ 0
BUS12
Text Label 15300 4350 0    50   ~ 0
BUS13
Text Label 15300 4450 0    50   ~ 0
BUS14
Text Label 15300 4550 0    50   ~ 0
BUS15
Text Label 15300 4650 0    50   ~ 0
BUS16
Text Label 15300 4750 0    50   ~ 0
BUS17
Text Label 15300 4850 0    50   ~ 0
BUS18
Text Label 15300 4950 0    50   ~ 0
BUS19
Text Label 15300 5100 0    50   ~ 0
BUS20
Text Label 15300 5200 0    50   ~ 0
BUS21
Text Label 15300 5300 0    50   ~ 0
BUS22
Text Label 15300 5400 0    50   ~ 0
BUS23
Text Label 15300 5500 0    50   ~ 0
BUS24
Text Label 15300 5600 0    50   ~ 0
BUS25
Text Label 15300 5700 0    50   ~ 0
BUS26
Text Label 15300 5800 0    50   ~ 0
BUS27
Text Label 15300 5900 0    50   ~ 0
BUS28
Text Label 15300 6000 0    50   ~ 0
BUS29
Text Label 15300 6100 0    50   ~ 0
BUS30
Text Label 15300 6200 0    50   ~ 0
BUS31
$EndSCHEMATC
