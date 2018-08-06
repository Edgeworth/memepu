EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 33
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
S 1000 950  650  600 
U 5ADF0E03
F0 "Clock" 50
F1 "clock.sch" 50
F2 "CLK" I R 1650 1050 50 
F3 "~RESET" I R 1650 1250 50 
F4 "~CLK" I R 1650 1150 50 
F5 "~RESET_NCLK" I L 1000 1400 50 
$EndSheet
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5AE292E5
P 2550 950
F 0 "#FLG01" H 2550 1025 50  0001 C CNN
F 1 "PWR_FLAG" H 2550 1123 50  0000 C CNN
F 2 "" H 2550 950 50  0001 C CNN
F 3 "~" H 2550 950 50  0001 C CNN
	1    2550 950 
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5AE292FC
P 2850 950
F 0 "#FLG02" H 2850 1025 50  0001 C CNN
F 1 "PWR_FLAG" H 2850 1124 50  0000 C CNN
F 2 "" H 2850 950 50  0001 C CNN
F 3 "~" H 2850 950 50  0001 C CNN
	1    2850 950 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0109
U 1 1 5B05E238
P 2550 950
F 0 "#PWR0109" H 2550 800 50  0001 C CNN
F 1 "VCC" H 2567 1123 50  0000 C CNN
F 2 "" H 2550 950 50  0001 C CNN
F 3 "" H 2550 950 50  0001 C CNN
	1    2550 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5AE29284
P 2850 950
F 0 "#PWR02" H 2850 700 50  0001 C CNN
F 1 "GND" H 2855 777 50  0000 C CNN
F 2 "" H 2850 950 50  0001 C CNN
F 3 "" H 2850 950 50  0001 C CNN
	1    2850 950 
	1    0    0    -1  
$EndComp
$Sheet
S 6350 2500 900  2550
U 5AFD5CE2
F0 "Registers" 50
F1 "registers.sch" 50
F2 "BUS0" I L 6350 2600 50 
F3 "BUS1" I L 6350 2700 50 
F4 "BUS2" I L 6350 2800 50 
F5 "BUS3" I L 6350 2900 50 
F6 "BUS4" I L 6350 3000 50 
F7 "BUS5" I L 6350 3100 50 
F8 "BUS6" I L 6350 3200 50 
F9 "BUS7" I L 6350 3300 50 
F10 "REG_A_IN" I R 7250 2600 50 
F11 "~REG_A_OUT" I R 7250 2700 50 
F12 "REG_B_IN" I R 7250 2800 50 
F13 "~REG_B_OUT" I R 7250 2900 50 
F14 "REG_M0_IN" I R 7250 3000 50 
F15 "~REG_M0_OUT" I R 7250 3100 50 
F16 "REG_M1_IN" I R 7250 3200 50 
F17 "~REG_M1_OUT" I R 7250 3300 50 
F18 "REG_M2_IN" I R 7250 3400 50 
F19 "~REG_M2_OUT" I R 7250 3500 50 
F20 "REG_T_IN" I R 7250 3600 50 
F21 "~REG_T_OUT" I R 7250 3700 50 
F22 "A0" I L 6350 3450 50 
F23 "A1" I L 6350 3550 50 
F24 "A2" I L 6350 3650 50 
F25 "A3" I L 6350 3750 50 
F26 "A4" I L 6350 3850 50 
F27 "A5" I L 6350 3950 50 
F28 "A6" I L 6350 4050 50 
F29 "A7" I L 6350 4150 50 
F30 "B0" I R 7250 4250 50 
F31 "B1" I R 7250 4350 50 
F32 "B2" I R 7250 4450 50 
F33 "B3" I R 7250 4550 50 
F34 "B4" I R 7250 4650 50 
F35 "B5" I R 7250 4750 50 
F36 "B6" I R 7250 4850 50 
F37 "B7" I R 7250 4950 50 
F38 "TASK0" I L 6350 4250 50 
F39 "TASK1" I L 6350 4350 50 
F40 "TASK2" I L 6350 4450 50 
F41 "TASK3" I L 6350 4550 50 
F42 "TASK4" I L 6350 4650 50 
F43 "TASK5" I L 6350 4750 50 
F44 "TASK6" I L 6350 4850 50 
F45 "TASK7" I L 6350 4950 50 
$EndSheet
Text Label 6350 2600 2    50   ~ 0
BUS0
Text Label 6350 2700 2    50   ~ 0
BUS1
Text Label 6350 2800 2    50   ~ 0
BUS2
Text Label 6350 2900 2    50   ~ 0
BUS3
Text Label 6350 3000 2    50   ~ 0
BUS4
Text Label 6350 3100 2    50   ~ 0
BUS5
Text Label 6350 3200 2    50   ~ 0
BUS6
Text Label 6350 3300 2    50   ~ 0
BUS7
$Comp
L power:VCC #PWR038
U 1 1 5AFD3766
P 3500 950
F 0 "#PWR038" H 3500 800 50  0001 C CNN
F 1 "VCC" H 3517 1123 50  0000 C CNN
F 2 "" H 3500 950 50  0001 C CNN
F 3 "" H 3500 950 50  0001 C CNN
	1    3500 950 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR039
U 1 1 5AFD387B
P 3500 1350
F 0 "#PWR039" H 3500 1100 50  0001 C CNN
F 1 "GND" H 3505 1177 50  0000 C CNN
F 2 "" H 3500 1350 50  0001 C CNN
F 3 "" H 3500 1350 50  0001 C CNN
	1    3500 1350
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J1
U 1 1 5AFD7056
P 4150 1150
F 0 "J1" H 4230 1192 50  0000 L CNN
F 1 "Conn_01x05" H 4230 1101 50  0000 L CNN
F 2 "Connector_USB:USB_Micro-B_Wuerth_629105150521" H 4150 1150 50  0001 C CNN
F 3 "~" H 4150 1150 50  0001 C CNN
	1    4150 1150
	1    0    0    -1  
$EndComp
NoConn ~ 3950 1050
NoConn ~ 3950 1150
NoConn ~ 3950 1250
$Sheet
S 9500 2850 550  1950
U 5AFDA122
F0 "ALU" 50
F1 "alu.sch" 50
F2 "SUB" I L 9500 2950 50 
F3 "A0" I L 9500 3050 50 
F4 "A1" I L 9500 3150 50 
F5 "A2" I L 9500 3250 50 
F6 "A3" I L 9500 3350 50 
F7 "O0" I R 10050 2950 50 
F8 "O1" I R 10050 3050 50 
F9 "O2" I R 10050 3150 50 
F10 "O3" I R 10050 3250 50 
F11 "B0" I L 9500 3850 50 
F12 "B1" I L 9500 3950 50 
F13 "B2" I L 9500 4050 50 
F14 "B3" I L 9500 4150 50 
F15 "A4" I L 9500 3450 50 
F16 "A5" I L 9500 3550 50 
F17 "A6" I L 9500 3650 50 
F18 "A7" I L 9500 3750 50 
F19 "O4" I R 10050 3350 50 
F20 "O5" I R 10050 3450 50 
F21 "O6" I R 10050 3550 50 
F22 "O7" I R 10050 3650 50 
F23 "CARRY" I R 10050 3750 50 
F24 "~SUM_OUT" I L 9500 4650 50 
F25 "B4" I L 9500 4250 50 
F26 "B5" I L 9500 4350 50 
F27 "B6" I L 9500 4450 50 
F28 "B7" I L 9500 4550 50 
F29 "ZERO" I R 10050 3850 50 
$EndSheet
Text Label 6350 3450 2    50   ~ 0
A0
Text Label 6350 3550 2    50   ~ 0
A1
Text Label 6350 3650 2    50   ~ 0
A2
Text Label 6350 3750 2    50   ~ 0
A3
Text Label 6350 3850 2    50   ~ 0
A4
Text Label 6350 3950 2    50   ~ 0
A5
Text Label 6350 4050 2    50   ~ 0
A6
Text Label 6350 4150 2    50   ~ 0
A7
Text Label 7250 4250 0    50   ~ 0
B0
Text Label 7250 4350 0    50   ~ 0
B1
Text Label 7250 4450 0    50   ~ 0
B2
Text Label 7250 4550 0    50   ~ 0
B3
Text Label 7250 4650 0    50   ~ 0
B4
Text Label 7250 4750 0    50   ~ 0
B5
Text Label 7250 4850 0    50   ~ 0
B6
Text Label 7250 4950 0    50   ~ 0
B7
Text Label 9500 3050 2    50   ~ 0
A0
Text Label 9500 3150 2    50   ~ 0
A1
Text Label 9500 3250 2    50   ~ 0
A2
Text Label 9500 3350 2    50   ~ 0
A3
Text Label 9500 3450 2    50   ~ 0
A4
Text Label 9500 3550 2    50   ~ 0
A5
Text Label 9500 3650 2    50   ~ 0
A6
Text Label 9500 3750 2    50   ~ 0
A7
Text Label 9500 3850 2    50   ~ 0
B0
Text Label 9500 3950 2    50   ~ 0
B1
Text Label 9500 4050 2    50   ~ 0
B2
Text Label 9500 4150 2    50   ~ 0
B3
Text Label 9500 4250 2    50   ~ 0
B4
Text Label 9500 4350 2    50   ~ 0
B5
Text Label 9500 4450 2    50   ~ 0
B6
Text Label 9500 4550 2    50   ~ 0
B7
Text Label 10050 2950 0    50   ~ 0
BUS0
Text Label 10050 3050 0    50   ~ 0
BUS1
Text Label 10050 3150 0    50   ~ 0
BUS2
Text Label 10050 3250 0    50   ~ 0
BUS3
Text Label 10050 3350 0    50   ~ 0
BUS4
Text Label 10050 3450 0    50   ~ 0
BUS5
Text Label 10050 3550 0    50   ~ 0
BUS6
Text Label 10050 3650 0    50   ~ 0
BUS7
$Sheet
S 8550 1000 550  1000
U 5AFEE19A
F0 "Display" 50
F1 "display_module.sch" 50
F2 "BUS0" I L 8550 1100 50 
F3 "BUS1" I L 8550 1200 50 
F4 "BUS2" I L 8550 1300 50 
F5 "BUS3" I L 8550 1400 50 
F6 "BUS4" I L 8550 1500 50 
F7 "BUS5" I L 8550 1600 50 
F8 "BUS6" I L 8550 1700 50 
F9 "BUS7" I L 8550 1800 50 
F10 "DISP_IN" I L 8550 1900 50 
$EndSheet
$Sheet
S 6600 7450 550  1650
U 5B04243E
F0 "MLU" 50
F1 "mlu.sch" 50
F2 "A0" I L 6600 7500 50 
F3 "A1" I L 6600 7600 50 
F4 "A2" I L 6600 7700 50 
F5 "A3" I L 6600 7800 50 
F6 "A4" I L 6600 7900 50 
F7 "A5" I L 6600 8000 50 
F8 "A6" I L 6600 8100 50 
F9 "A7" I L 6600 8200 50 
F10 "B0" I L 6600 8300 50 
F11 "B1" I L 6600 8400 50 
F12 "B2" I L 6600 8500 50 
F13 "B3" I L 6600 8600 50 
F14 "B4" I L 6600 8700 50 
F15 "B5" I L 6600 8800 50 
F16 "B6" I L 6600 8900 50 
F17 "B7" I L 6600 9000 50 
F18 "~OUT" I R 7150 8400 50 
F19 "O0" I R 7150 7500 50 
F20 "O1" I R 7150 7600 50 
F21 "O2" I R 7150 7700 50 
F22 "O3" I R 7150 7800 50 
F23 "O4" I R 7150 7900 50 
F24 "O5" I R 7150 8000 50 
F25 "O6" I R 7150 8100 50 
F26 "O7" I R 7150 8200 50 
F27 "MLU0" I R 7150 8500 50 
F28 "MLU1" I R 7150 8600 50 
F29 "MLU2" I R 7150 8700 50 
$EndSheet
Text Label 6600 7500 2    50   ~ 0
A0
Text Label 6600 7600 2    50   ~ 0
A1
Text Label 6600 7700 2    50   ~ 0
A2
Text Label 6600 7800 2    50   ~ 0
A3
Text Label 6600 7900 2    50   ~ 0
A4
Text Label 6600 8000 2    50   ~ 0
A5
Text Label 6600 8100 2    50   ~ 0
A6
Text Label 6600 8200 2    50   ~ 0
A7
Text Label 6600 8300 2    50   ~ 0
B0
Text Label 6600 8400 2    50   ~ 0
B1
Text Label 6600 8500 2    50   ~ 0
B2
Text Label 6600 8600 2    50   ~ 0
B3
Text Label 6600 8700 2    50   ~ 0
B4
Text Label 6600 8800 2    50   ~ 0
B5
Text Label 6600 8900 2    50   ~ 0
B6
Text Label 6600 9000 2    50   ~ 0
B7
Text Label 7150 7500 0    50   ~ 0
BUS0
Text Label 7150 7600 0    50   ~ 0
BUS1
Text Label 7150 7700 0    50   ~ 0
BUS2
Text Label 7150 7800 0    50   ~ 0
BUS3
Text Label 7150 7900 0    50   ~ 0
BUS4
Text Label 7150 8000 0    50   ~ 0
BUS5
Text Label 7150 8100 0    50   ~ 0
BUS6
Text Label 7150 8200 0    50   ~ 0
BUS7
Text Label 8550 1100 2    50   ~ 0
BUS0
Text Label 8550 1200 2    50   ~ 0
BUS1
Text Label 8550 1300 2    50   ~ 0
BUS2
Text Label 8550 1400 2    50   ~ 0
BUS3
Text Label 8550 1500 2    50   ~ 0
BUS4
Text Label 8550 1600 2    50   ~ 0
BUS5
Text Label 8550 1700 2    50   ~ 0
BUS6
Text Label 8550 1800 2    50   ~ 0
BUS7
$Sheet
S 12550 2700 1600 1200
U 5B094E56
F0 "Status/Control Register" 50
F1 "sc_register.sch" 50
F2 "INTERRUPT_ENABLE_FLAG" I R 14150 2800 50 
F3 "CARRY_FLAG" I R 14150 2900 50 
F4 "ZERO_FLAG" I R 14150 3000 50 
F5 "~RESET" I L 12550 3050 50 
F6 "~SET_INTERRUPT_ENABLE_ASYNC" I L 12550 3350 50 
F7 "~UNSET_INTERRUPT_ENABLE_ASYNC" I L 12550 3450 50 
F8 "CARRY_CLK" I L 12550 3550 50 
F9 "ZERO_CLK" I L 12550 3650 50 
F10 "ZERO" I L 12550 3250 50 
F11 "CARRY" I L 12550 3150 50 
F12 "~REG_OUT" I L 12550 3750 50 
F13 "BUS0" I R 14150 3100 50 
F14 "BUS1" I R 14150 3200 50 
F15 "BUS2" I R 14150 3300 50 
F16 "BUS3" I R 14150 3400 50 
F17 "BUS4" I R 14150 3500 50 
F18 "BUS5" I R 14150 3600 50 
F19 "BUS6" I R 14150 3700 50 
F20 "BUS7" I R 14150 3800 50 
$EndSheet
$Sheet
S 6400 5400 700  1550
U 5B096BDD
F0 "Program Counter" 50
F1 "program_counter.sch" 50
F2 "~PC0_OUT" I L 6400 6650 50 
F3 "BUS0" I R 7100 5500 50 
F4 "BUS1" I R 7100 5600 50 
F5 "BUS2" I R 7100 5700 50 
F6 "BUS3" I R 7100 5800 50 
F7 "BUS4" I R 7100 5900 50 
F8 "BUS5" I R 7100 6000 50 
F9 "BUS6" I R 7100 6100 50 
F10 "BUS7" I R 7100 6200 50 
F11 "~PC1_OUT" I L 6400 6750 50 
F12 "~PC2_OUT" I L 6400 6850 50 
F13 "~PC0_IN_NCLK" I L 6400 6300 50 
F14 "~PC1_IN_NCLK" I L 6400 6400 50 
F15 "~PC2_IN_NCLK" I L 6400 6500 50 
F16 "~RESET" I L 6400 6150 50 
F17 "CLK" I L 6400 6050 50 
F18 "PC_INC" I L 6400 5950 50 
$EndSheet
Text Label 7100 5500 0    50   ~ 0
BUS0
Text Label 7100 5600 0    50   ~ 0
BUS1
Text Label 7100 5700 0    50   ~ 0
BUS2
Text Label 7100 5800 0    50   ~ 0
BUS3
Text Label 7100 5900 0    50   ~ 0
BUS4
Text Label 7100 6000 0    50   ~ 0
BUS5
Text Label 7100 6100 0    50   ~ 0
BUS6
Text Label 7100 6200 0    50   ~ 0
BUS7
Text Label 1650 1250 0    50   ~ 0
~RESET
Text Label 12550 3050 2    50   ~ 0
~RESET
Text Label 6400 6150 2    50   ~ 0
~RESET
Text Label 1650 1050 0    50   ~ 0
CLK
Text Label 6400 6050 2    50   ~ 0
CLK
Text Label 13750 4500 0    50   ~ 0
BUS0
Text Label 13750 4600 0    50   ~ 0
BUS1
Text Label 13750 4700 0    50   ~ 0
BUS2
Text Label 13750 4800 0    50   ~ 0
BUS3
Text Label 13750 4900 0    50   ~ 0
BUS4
Text Label 13750 5000 0    50   ~ 0
BUS5
Text Label 13750 5100 0    50   ~ 0
BUS6
Text Label 13750 5200 0    50   ~ 0
BUS7
$Sheet
S 6600 9350 1150 1600
U 5B09632F
F0 "MMU" 50
F1 "mmu.sch" 50
F2 "BUS0" I R 7750 9450 50 
F3 "BUS1" I R 7750 9550 50 
F4 "BUS2" I R 7750 9650 50 
F5 "BUS3" I R 7750 9750 50 
F6 "BUS4" I R 7750 9850 50 
F7 "BUS5" I R 7750 9950 50 
F8 "BUS6" I R 7750 10050 50 
F9 "BUS7" I R 7750 10150 50 
F10 "~MMU_OUT" I L 6600 9450 50 
F11 "~MMU_CONTROL_IN" I L 6600 9650 50 
F12 "TASK0" I L 6600 9850 50 
F13 "TASK1" I L 6600 9950 50 
F14 "TASK2" I L 6600 10050 50 
F15 "TASK3" I L 6600 10150 50 
F16 "TASK4" I L 6600 10250 50 
F17 "TASK5" I L 6600 10350 50 
F18 "TASK6" I L 6600 10450 50 
F19 "TASK7" I L 6600 10550 50 
F20 "~MMU_CONTROL_OUT" I L 6600 9750 50 
F21 "MMU_READ_FAULT" I R 7750 10250 50 
F22 "MMU_WRITE_FAULT" I R 7750 10350 50 
F23 "~MMU_IN" I L 6600 9550 50 
F24 "MMU0_IN" I L 6600 10650 50 
F25 "MMU1_IN" I L 6600 10750 50 
F26 "MMU2_IN" I L 6600 10850 50 
$EndSheet
Text Label 6350 4250 2    50   ~ 0
TASK0
Text Label 6350 4350 2    50   ~ 0
TASK1
Text Label 6350 4450 2    50   ~ 0
TASK2
Text Label 6350 4550 2    50   ~ 0
TASK3
Text Label 6350 4650 2    50   ~ 0
TASK4
Text Label 6350 4750 2    50   ~ 0
TASK5
Text Label 6350 4850 2    50   ~ 0
TASK6
Text Label 6350 4950 2    50   ~ 0
TASK7
Text Label 6600 9850 2    50   ~ 0
TASK0
Text Label 6600 9950 2    50   ~ 0
TASK1
Text Label 6600 10050 2    50   ~ 0
TASK2
Text Label 6600 10150 2    50   ~ 0
TASK3
Text Label 6600 10250 2    50   ~ 0
TASK4
Text Label 6600 10350 2    50   ~ 0
TASK5
Text Label 6600 10450 2    50   ~ 0
TASK6
Text Label 6600 10550 2    50   ~ 0
TASK7
Text Label 7750 9450 0    50   ~ 0
BUS0
Text Label 7750 9550 0    50   ~ 0
BUS1
Text Label 7750 9650 0    50   ~ 0
BUS2
Text Label 7750 9750 0    50   ~ 0
BUS3
Text Label 7750 9850 0    50   ~ 0
BUS4
Text Label 7750 9950 0    50   ~ 0
BUS5
Text Label 7750 10050 0    50   ~ 0
BUS6
Text Label 7750 10150 0    50   ~ 0
BUS7
$Comp
L Device:CP C95
U 1 1 5B0C2BBB
P 6050 1150
F 0 "C95" H 6168 1196 50  0000 L CNN
F 1 "10uF" H 6168 1105 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P2.00mm" H 6088 1000 50  0001 C CNN
F 3 "~" H 6050 1150 50  0001 C CNN
	1    6050 1150
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C96
U 1 1 5B0C2BF7
P 6500 1150
F 0 "C96" H 6618 1196 50  0000 L CNN
F 1 "100uF" H 6618 1105 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 6538 1000 50  0001 C CNN
F 3 "~" H 6500 1150 50  0001 C CNN
	1    6500 1150
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C97
U 1 1 5B0C2C19
P 7000 1150
F 0 "C97" H 7118 1196 50  0000 L CNN
F 1 "470uF" H 7118 1105 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P3.80mm" H 7038 1000 50  0001 C CNN
F 3 "~" H 7000 1150 50  0001 C CNN
	1    7000 1150
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0347
U 1 1 5B0C2C3B
P 6050 1000
F 0 "#PWR0347" H 6050 850 50  0001 C CNN
F 1 "VCC" H 6067 1173 50  0000 C CNN
F 2 "" H 6050 1000 50  0001 C CNN
F 3 "" H 6050 1000 50  0001 C CNN
	1    6050 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 1000 6500 1000
Connection ~ 6050 1000
Wire Wire Line
	6500 1000 7000 1000
Connection ~ 6500 1000
$Comp
L power:GND #PWR0348
U 1 1 5B0C2C63
P 7000 1300
F 0 "#PWR0348" H 7000 1050 50  0001 C CNN
F 1 "GND" H 7005 1127 50  0000 C CNN
F 2 "" H 7000 1300 50  0001 C CNN
F 3 "" H 7000 1300 50  0001 C CNN
	1    7000 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 1300 6500 1300
Connection ~ 7000 1300
Wire Wire Line
	6500 1300 6050 1300
Connection ~ 6500 1300
Wire Wire Line
	7000 1000 7450 1000
Connection ~ 7000 1000
Wire Wire Line
	7000 1300 7450 1300
Text Notes 6500 900  0    50   ~ 0
Zener for overvoltage protection.
$Comp
L Device:Polyfuse F1
U 1 1 5B0C553B
P 3700 950
F 0 "F1" V 3475 950 50  0000 C CNN
F 1 "0.65A" V 3566 950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D10.0mm_W2.5mm_P5.00mm" H 3750 750 50  0001 L CNN
F 3 "~" H 3700 950 50  0001 C CNN
	1    3700 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	3500 950  3550 950 
Wire Wire Line
	3850 950  3950 950 
Wire Wire Line
	3500 1350 3950 1350
$Comp
L Device:D_Zener D17
U 1 1 5B0C4FC8
P 7450 1150
F 0 "D17" V 7404 1229 50  0000 L CNN
F 1 "5.6V" V 7495 1229 50  0000 L CNN
F 2 "Diode_THT:D_5W_P12.70mm_Horizontal" H 7450 1150 50  0001 C CNN
F 3 "~" H 7450 1150 50  0001 C CNN
	1    7450 1150
	0    1    1    0   
$EndComp
Text Label 1650 1150 0    50   ~ 0
~CLK
Text Label 1850 3450 2    50   ~ 0
MMU_READ_FAULT
Text Label 1850 3550 2    50   ~ 0
MMU_WRITE_FAULT
Text Label 9550 6650 2    50   ~ 0
~INT_OUT_NCLK
Text Label 10300 6000 0    50   ~ 0
BUS0
Text Label 10300 6100 0    50   ~ 0
BUS1
Text Label 10300 6200 0    50   ~ 0
BUS2
Text Label 10300 6300 0    50   ~ 0
BUS3
Text Label 10300 6400 0    50   ~ 0
BUS4
Text Label 10300 6500 0    50   ~ 0
BUS5
Text Label 10300 6600 0    50   ~ 0
BUS6
Text Label 10300 6700 0    50   ~ 0
BUS7
Text Label 9550 5200 2    50   ~ 0
INT0
Text Label 9550 5300 2    50   ~ 0
INT1
Text Label 9550 5400 2    50   ~ 0
INT2
Text Label 9550 5500 2    50   ~ 0
INT3
Text Label 9550 5600 2    50   ~ 0
INT4
Text Label 9550 5700 2    50   ~ 0
INT5
Text Label 9550 5800 2    50   ~ 0
INT6
Text Label 9550 5900 2    50   ~ 0
INT7
$Sheet
S 9550 5100 750  1750
U 5B0FEA60
F0 "Interrupt Register" 50
F1 "register_with_bus_transceiver.sch" 50
F2 "REG_IN" I L 9550 6750 50 
F3 "I0" I L 9550 5200 50 
F4 "I1" I L 9550 5300 50 
F5 "I2" I L 9550 5400 50 
F6 "I3" I L 9550 5500 50 
F7 "I4" I L 9550 5600 50 
F8 "I5" I L 9550 5700 50 
F9 "I6" I L 9550 5800 50 
F10 "I7" I L 9550 5900 50 
F11 "~REG_OUT" I L 9550 6650 50 
F12 "O0" I R 10300 5200 50 
F13 "O1" I R 10300 5300 50 
F14 "O2" I R 10300 5400 50 
F15 "O3" I R 10300 5500 50 
F16 "O4" I R 10300 5600 50 
F17 "O5" I R 10300 5700 50 
F18 "O6" I R 10300 5800 50 
F19 "O7" I R 10300 5900 50 
F20 "BUS0" I R 10300 6000 50 
F21 "BUS1" I R 10300 6100 50 
F22 "BUS2" I R 10300 6200 50 
F23 "BUS3" I R 10300 6300 50 
F24 "BUS4" I R 10300 6400 50 
F25 "BUS5" I R 10300 6500 50 
F26 "BUS6" I R 10300 6600 50 
F27 "BUS7" I R 10300 6700 50 
$EndSheet
Text Label 10300 5200 0    50   ~ 0
INT0_LATCH
Text Label 10300 5300 0    50   ~ 0
INT1_LATCH
Text Label 10300 5400 0    50   ~ 0
INT2_LATCH
Text Label 10300 5500 0    50   ~ 0
INT3_LATCH
Text Label 10300 5600 0    50   ~ 0
INT4_LATCH
Text Label 10300 5700 0    50   ~ 0
INT5_LATCH
Text Label 10300 5800 0    50   ~ 0
INT6_LATCH
Text Label 10300 5900 0    50   ~ 0
INT7_LATCH
Text Label 3900 2650 0    50   ~ 0
~A_OUT_NCLK
Text Label 3900 2750 0    50   ~ 0
~B_OUT_NCLK
Text Label 3900 2850 0    50   ~ 0
~M0_OUT_NCLK
Text Label 3900 2950 0    50   ~ 0
~M1_OUT_NCLK
Text Label 3900 3050 0    50   ~ 0
~M2_OUT_NCLK
Text Label 3900 3150 0    50   ~ 0
~S0_OUT_NCLK
Text Label 3900 3250 0    50   ~ 0
~S1_OUT_NCLK
Text Label 3900 3350 0    50   ~ 0
~S2_OUT_NCLK
Text Label 3900 3450 0    50   ~ 0
~STATUS_OUT_NCLK
Text Label 3900 3850 0    50   ~ 0
~INT_OUT_NCLK
Text Label 3900 3950 0    50   ~ 0
~SUM_OUT_NCLK
Text Label 3900 4050 0    50   ~ 0
~MMU_OUT_NCLK
Text Label 3900 4150 0    50   ~ 0
~MMU_CONTROL_OUT_NCLK
Text Label 3900 4250 0    50   ~ 0
~TASK_OUT_NCLK
Text Label 3900 4350 0    50   ~ 0
~MLU_OUT_NCLK
Text Label 3900 4550 0    50   ~ 0
~RESET_NCLK
Text Label 3900 4650 0    50   ~ 0
~SET_INT_ENABLE_ASYNC
Text Label 3900 4750 0    50   ~ 0
~UNSET_INT_ENABLE_ASYNC
Text Label 3900 4850 0    50   ~ 0
A_IN_CLK
Text Label 3900 4950 0    50   ~ 0
B_IN_CLK
Text Label 3900 5050 0    50   ~ 0
M0_IN_CLK
Text Label 3900 5150 0    50   ~ 0
M1_IN_CLK
Text Label 3900 5250 0    50   ~ 0
M2_IN_CLK
Text Label 3900 5950 0    50   ~ 0
MMU0_IN_CLK
Text Label 3900 6050 0    50   ~ 0
MMU1_IN_CLK
Text Label 3900 6150 0    50   ~ 0
MMU2_IN_CLK
Text Label 3900 6250 0    50   ~ 0
~MMU_IN_CLK
Text Label 3900 6350 0    50   ~ 0
~MMU_CONTROL_IN_CLK
Text Label 3900 6450 0    50   ~ 0
DISP_IN_CLK
Text Label 3900 6550 0    50   ~ 0
TASK_IN_CLK
Text Label 3900 6650 0    50   ~ 0
INT0_IN_CLK
Text Label 3900 6750 0    50   ~ 0
INT1_IN_CLK
Text Label 3900 6850 0    50   ~ 0
INT2_IN_CLK
Text Label 3900 6950 0    50   ~ 0
INT3_IN_CLK
Text Label 3900 7050 0    50   ~ 0
INT4_IN_CLK
Text Label 3900 7150 0    50   ~ 0
INT5_IN_CLK
Text Label 3900 7250 0    50   ~ 0
INT6_IN_CLK
Text Label 3900 7350 0    50   ~ 0
INT7_IN_CLK
Text Label 3900 7750 0    50   ~ 0
ALU_FLAG_SET_CLK
Text Label 7150 8400 0    50   ~ 0
~MLU_OUT_NCLK
Text Label 3900 7850 0    50   ~ 0
MLU_SEL0
Text Label 3900 7950 0    50   ~ 0
MLU_SEL1
Text Label 3900 8050 0    50   ~ 0
MLU_SEL2
Text Label 7150 8500 0    50   ~ 0
MLU_SEL0
Text Label 7150 8600 0    50   ~ 0
MLU_SEL1
Text Label 7150 8700 0    50   ~ 0
MLU_SEL2
Text Label 6600 9450 2    50   ~ 0
~MMU_OUT_NCLK
Text Label 6600 9750 2    50   ~ 0
~MMU_CONTROL_OUT_NCLK
Text Label 6600 9550 2    50   ~ 0
~MMU_IN_CLK
Text Label 6600 9650 2    50   ~ 0
~MMU_CONTROL_IN_CLK
Text Label 6600 10650 2    50   ~ 0
MMU0_IN_CLK
Text Label 6600 10750 2    50   ~ 0
MMU1_IN_CLK
Text Label 6600 10850 2    50   ~ 0
MMU2_IN_CLK
Text Label 3900 3550 0    50   ~ 0
~PC0_OUT_NCLK
Text Label 3900 3650 0    50   ~ 0
~PC1_OUT_NCLK
Text Label 3900 3750 0    50   ~ 0
~PC2_OUT_NCLK
Text Label 6400 6650 2    50   ~ 0
~PC0_OUT_NCLK
Text Label 6400 6750 2    50   ~ 0
~PC1_OUT_NCLK
Text Label 6400 6850 2    50   ~ 0
~PC2_OUT_NCLK
Text Label 7250 2600 0    50   ~ 0
A_IN_CLK
Text Label 7250 2800 0    50   ~ 0
B_IN_CLK
Text Label 7250 3000 0    50   ~ 0
M0_IN_CLK
Text Label 7250 3200 0    50   ~ 0
M1_IN_CLK
Text Label 7250 3400 0    50   ~ 0
M2_IN_CLK
Text Label 7250 3600 0    50   ~ 0
TASK_IN_CLK
Text Label 7250 2700 0    50   ~ 0
~A_OUT_NCLK
Text Label 7250 2900 0    50   ~ 0
~B_OUT_NCLK
Text Label 7250 3100 0    50   ~ 0
~M0_OUT_NCLK
Text Label 7250 3300 0    50   ~ 0
~M1_OUT_NCLK
Text Label 7250 3500 0    50   ~ 0
~M2_OUT_NCLK
Text Label 7250 3700 0    50   ~ 0
~TASK_OUT_NCLK
Text Label 9500 4650 2    50   ~ 0
~SUM_OUT_NCLK
Text Label 10050 3750 0    50   ~ 0
CARRY
Text Label 10050 3850 0    50   ~ 0
ZERO
Text Label 12550 3150 2    50   ~ 0
CARRY
Text Label 12550 3250 2    50   ~ 0
ZERO
Text Label 12550 3350 2    50   ~ 0
~SET_INT_ENABLE_ASYNC
Text Label 12550 3450 2    50   ~ 0
~UNSET_INT_ENABLE_ASYNC
Text Label 14150 2800 0    50   ~ 0
INTERRUPT_ENABLE_FLAG
Text Label 1850 4650 2    50   ~ 0
INTERRUPT_ENABLE_FLAG
Text Label 1850 3850 2    50   ~ 0
INT0_LATCH
Text Label 1850 3950 2    50   ~ 0
INT1_LATCH
Text Label 1850 4050 2    50   ~ 0
INT2_LATCH
Text Label 1850 4150 2    50   ~ 0
INT3_LATCH
Text Label 1850 4250 2    50   ~ 0
INT4_LATCH
Text Label 1850 4350 2    50   ~ 0
INT5_LATCH
Text Label 1850 4450 2    50   ~ 0
INT6_LATCH
Text Label 1850 4550 2    50   ~ 0
INT7_LATCH
Text Label 1850 3650 2    50   ~ 0
~CLK
Text Label 7750 10250 0    50   ~ 0
MMU_READ_FAULT
Text Label 7750 10350 0    50   ~ 0
MMU_WRITE_FAULT
Text Label 12550 3550 2    50   ~ 0
ALU_FLAG_SET_CLK
Text Label 12550 3650 2    50   ~ 0
ALU_FLAG_SET_CLK
Text Label 12800 4500 2    50   ~ 0
~S0_OUT_NCLK
Text Label 12800 4600 2    50   ~ 0
~S1_OUT_NCLK
Text Label 12800 4700 2    50   ~ 0
~S2_OUT_NCLK
Text Label 8550 1900 2    50   ~ 0
DISP_IN_CLK
Text Label 1850 2650 2    50   ~ 0
BUS0
Text Label 1850 2750 2    50   ~ 0
BUS1
Text Label 1850 2850 2    50   ~ 0
BUS2
Text Label 1850 2950 2    50   ~ 0
BUS3
Text Label 1850 3050 2    50   ~ 0
BUS4
Text Label 1850 3150 2    50   ~ 0
BUS5
Text Label 1850 3250 2    50   ~ 0
BUS6
Text Label 1850 3350 2    50   ~ 0
BUS7
Text Label 1850 3750 2    50   ~ 0
CLK
Text Label 3900 4450 0    50   ~ 0
SUB_NCLK
Text Label 9500 2950 2    50   ~ 0
SUB_NCLK
Text Label 3900 5650 0    50   ~ 0
~PC0_IN_NCLK
Text Label 3900 5750 0    50   ~ 0
~PC1_IN_NCLK
Text Label 3900 5850 0    50   ~ 0
~PC2_IN_NCLK
Text Label 6400 6300 2    50   ~ 0
~PC0_IN_NCLK
Text Label 6400 6400 2    50   ~ 0
~PC1_IN_NCLK
Text Label 6400 6500 2    50   ~ 0
~PC2_IN_NCLK
Text Label 3900 5350 0    50   ~ 0
~S0_IN_CLK
Text Label 3900 5450 0    50   ~ 0
~S1_IN_CLK
Text Label 3900 5550 0    50   ~ 0
~S2_IN_CLK
Text Label 12800 5000 2    50   ~ 0
~S0_IN_CLK
Text Label 12800 5100 2    50   ~ 0
~S1_IN_CLK
Text Label 12800 5200 2    50   ~ 0
~S2_IN_CLK
Text Label 3900 7450 0    50   ~ 0
PC_INC_NCLK
Text Label 6400 5950 2    50   ~ 0
PC_INC_NCLK
$Sheet
S 12800 4400 950  1000
U 5B0B7FFA
F0 "User Stack Register" 50
F1 "stack_register.sch" 50
F2 "~R0_IN" I L 12800 5000 50 
F3 "~R2_IN" I L 12800 5200 50 
F4 "BUS0" I R 13750 4500 50 
F5 "BUS1" I R 13750 4600 50 
F6 "BUS2" I R 13750 4700 50 
F7 "BUS3" I R 13750 4800 50 
F8 "BUS4" I R 13750 4900 50 
F9 "BUS5" I R 13750 5000 50 
F10 "BUS6" I R 13750 5100 50 
F11 "BUS7" I R 13750 5200 50 
F12 "~R0_OUT" I L 12800 4500 50 
F13 "~R1_OUT" I L 12800 4600 50 
F14 "~R2_OUT" I L 12800 4700 50 
F15 "~R1_IN" I L 12800 5100 50 
F16 "CLK" I L 12800 4800 50 
F17 "~COUNT_ENABLE" I L 12800 5300 50 
F18 "~UP" I L 12800 4900 50 
$EndSheet
Text Label 12800 4800 2    50   ~ 0
CLK
Text Label 3900 7550 0    50   ~ 0
~SP_COUNT_NCLK
Text Label 3900 7650 0    50   ~ 0
~SP_INC_NCLK
Text Label 12800 5300 2    50   ~ 0
~SP_COUNT_NCLK
Text Label 12800 4900 2    50   ~ 0
~SP_INC_NCLK
Text Notes 12000 7750 0    50   ~ 0
Spare parts:\n74hc04: Stack register, Clock\n74hc08: Control Logic\n74hc14: Clock\n74hc74: Status/Control Register
Text Label 12550 3750 2    50   ~ 0
~STATUS_OUT_NCLK
Text Label 1000 1400 2    50   ~ 0
~RESET_NCLK
Text Notes 1450 2300 0    50   ~ 0
TODO: Reset uop counter flag - check and remove from Control logic hierarchy.\n
Text Label 1850 4750 2    50   ~ 0
~RESET
Text Label 14150 3100 0    50   ~ 0
BUS0
Text Label 14150 3200 0    50   ~ 0
BUS1
Text Label 14150 3300 0    50   ~ 0
BUS2
Text Label 14150 3400 0    50   ~ 0
BUS3
Text Label 14150 3500 0    50   ~ 0
BUS4
Text Label 14150 3600 0    50   ~ 0
BUS5
Text Label 14150 3700 0    50   ~ 0
BUS6
Text Label 14150 3800 0    50   ~ 0
BUS7
Text Label 10450 8800 2    50   ~ 0
CLK
Text Label 10450 8900 2    50   ~ 0
~CLK
Text Label 10450 9000 2    50   ~ 0
BUS0
Text Label 10450 9100 2    50   ~ 0
BUS1
Text Label 10450 9200 2    50   ~ 0
BUS2
Text Label 10450 9300 2    50   ~ 0
BUS3
Text Label 10450 9400 2    50   ~ 0
BUS4
Text Label 10450 9500 2    50   ~ 0
BUS5
Text Label 10450 9600 2    50   ~ 0
BUS6
Text Label 10450 9700 2    50   ~ 0
BUS7
Text Label 10450 8600 2    50   ~ 0
VCC
Text Label 10950 8700 0    50   ~ 0
GND
Text Label 10950 9000 0    50   ~ 0
INT0_IN_CLK
Text Label 10950 9100 0    50   ~ 0
INT1_IN_CLK
Text Label 10950 9200 0    50   ~ 0
INT2_IN_CLK
Text Label 10950 9300 0    50   ~ 0
INT3_IN_CLK
Text Label 10950 9400 0    50   ~ 0
INT4_IN_CLK
Text Label 10950 9500 0    50   ~ 0
INT5_IN_CLK
Text Label 10950 9600 0    50   ~ 0
INT6_IN_CLK
Text Label 10950 9700 0    50   ~ 0
INT7_IN_CLK
Text Label 10950 9800 0    50   ~ 0
~INT0_OUT_NCLK
Text Label 10950 9900 0    50   ~ 0
~INT1_OUT_NCLK
Text Label 10950 10000 0    50   ~ 0
~INT2_OUT_NCLK
Text Label 10950 10100 0    50   ~ 0
~INT3_OUT_NCLK
Text Label 10950 10200 0    50   ~ 0
~INT4_OUT_NCLK
Text Label 10950 10300 0    50   ~ 0
~INT5_OUT_NCLK
Text Label 10950 10400 0    50   ~ 0
~INT6_OUT_NCLK
Text Label 10950 10500 0    50   ~ 0
~INT7_OUT_NCLK
Text Label 10950 8600 0    50   ~ 0
VCC
Text Label 10950 8800 0    50   ~ 0
GND
Text Label 3900 8150 0    50   ~ 0
~INT0_OUT_NCLK
Text Label 3900 8250 0    50   ~ 0
~INT1_OUT_NCLK
Text Label 3900 8350 0    50   ~ 0
~INT2_OUT_NCLK
Text Label 3900 8450 0    50   ~ 0
~INT3_OUT_NCLK
Text Label 3900 8550 0    50   ~ 0
~INT4_OUT_NCLK
Text Label 3900 8650 0    50   ~ 0
~INT5_OUT_NCLK
Text Label 3900 8750 0    50   ~ 0
~INT6_OUT_NCLK
Text Label 3900 8850 0    50   ~ 0
~INT7_OUT_NCLK
Text Label 10450 8700 2    50   ~ 0
VCC
Text Label 10950 8900 0    50   ~ 0
GND
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J2
U 1 1 5B1BB7C0
P 10650 9500
F 0 "J2" H 10700 10617 50  0000 C CNN
F 1 "Conn_02x20_Odd_Even" H 10700 10526 50  0000 C CNN
F 2 "Connector_IDC:IDC-Header_2x20_P2.54mm_Vertical" H 10650 9500 50  0001 C CNN
F 3 "~" H 10650 9500 50  0001 C CNN
	1    10650 9500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J3
U 1 1 5B1CC982
P 5150 1150
F 0 "J3" H 5230 1192 50  0000 L CNN
F 1 "Conn_01x03" H 5230 1101 50  0000 L CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 5150 1150 50  0001 C CNN
F 3 "~" H 5150 1150 50  0001 C CNN
	1    5150 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5B1CCAB4
P 4950 1150
F 0 "#PWR01" H 4950 900 50  0001 C CNN
F 1 "GND" H 4955 977 50  0000 C CNN
F 2 "" H 4950 1150 50  0001 C CNN
F 3 "" H 4950 1150 50  0001 C CNN
	1    4950 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	4950 1050 4950 750 
Wire Wire Line
	4950 750  3950 750 
Wire Wire Line
	3950 750  3950 950 
Connection ~ 3950 950 
NoConn ~ 4950 1250
Text Label 10450 9800 2    50   ~ 0
INT0
Text Label 10450 9900 2    50   ~ 0
INT1
Text Label 10450 10000 2    50   ~ 0
INT2
Text Label 10450 10100 2    50   ~ 0
INT3
Text Label 10450 10200 2    50   ~ 0
INT4
Text Label 10450 10300 2    50   ~ 0
INT5
Text Label 10450 10400 2    50   ~ 0
INT6
Text Label 10450 10500 2    50   ~ 0
INT7
NoConn ~ 9550 6750
Text Notes 9000 7100 0    50   ~ 0
TODO: Connect this up\n
Text Notes 13550 7550 0    50   ~ 0
Used spares:\n74hc04: 1 In Control Logic from Clock\n74hc08: 1 in Clock from Control Logic, 3 in ALU from Clock
$Sheet
S 1850 2550 2050 6450
U 5B0C6DCD
F0 "Control Logic" 50
F1 "control_logic.sch" 50
F2 "~A_OUT_NCLK" I R 3900 2650 50 
F3 "~B_OUT_NCLK" I R 3900 2750 50 
F4 "~M0_OUT_NCLK" I R 3900 2850 50 
F5 "~M1_OUT_NCLK" I R 3900 2950 50 
F6 "~M2_OUT_NCLK" I R 3900 3050 50 
F7 "~S0_OUT_NCLK" I R 3900 3150 50 
F8 "~S1_OUT_NCLK" I R 3900 3250 50 
F9 "~S2_OUT_NCLK" I R 3900 3350 50 
F10 "~STATUS_OUT_NCLK" I R 3900 3450 50 
F11 "~INT_OUT_NCLK" I R 3900 3850 50 
F12 "~SUM_OUT_NCLK" I R 3900 3950 50 
F13 "~MMU_OUT_NCLK" I R 3900 4050 50 
F14 "~MMU_CONTROL_OUT_NCLK" I R 3900 4150 50 
F15 "~TASK_OUT_NCLK" I R 3900 4250 50 
F16 "~MLU_OUT_NCLK" I R 3900 4350 50 
F17 "~RESET_NCLK" I R 3900 4550 50 
F18 "~SET_INT_ENABLE_ASYNC" I R 3900 4650 50 
F19 "~UNSET_INT_ENABLE_ASYNC" I R 3900 4750 50 
F20 "BUS0" I L 1850 2650 50 
F21 "BUS1" I L 1850 2750 50 
F22 "BUS2" I L 1850 2850 50 
F23 "BUS3" I L 1850 2950 50 
F24 "BUS4" I L 1850 3050 50 
F25 "BUS5" I L 1850 3150 50 
F26 "BUS6" I L 1850 3250 50 
F27 "BUS7" I L 1850 3350 50 
F28 "MMU_READ_FAULT" I L 1850 3450 50 
F29 "MMU_WRITE_FAULT" I L 1850 3550 50 
F30 "~CLK" I L 1850 3650 50 
F31 "A_IN_CLK" I R 3900 4850 50 
F32 "B_IN_CLK" I R 3900 4950 50 
F33 "M0_IN_CLK" I R 3900 5050 50 
F34 "M1_IN_CLK" I R 3900 5150 50 
F35 "M2_IN_CLK" I R 3900 5250 50 
F36 "MMU0_IN_CLK" I R 3900 5950 50 
F37 "MMU1_IN_CLK" I R 3900 6050 50 
F38 "MMU2_IN_CLK" I R 3900 6150 50 
F39 "~MMU_IN_CLK" I R 3900 6250 50 
F40 "~MMU_CONTROL_IN_CLK" I R 3900 6350 50 
F41 "DISP_IN_CLK" I R 3900 6450 50 
F42 "TASK_IN_CLK" I R 3900 6550 50 
F43 "INT0_IN_CLK" I R 3900 6650 50 
F44 "INT1_IN_CLK" I R 3900 6750 50 
F45 "INT2_IN_CLK" I R 3900 6850 50 
F46 "INT3_IN_CLK" I R 3900 6950 50 
F47 "INT4_IN_CLK" I R 3900 7050 50 
F48 "INT5_IN_CLK" I R 3900 7150 50 
F49 "INT6_IN_CLK" I R 3900 7250 50 
F50 "INT7_IN_CLK" I R 3900 7350 50 
F51 "ALU_FLAG_SET_CLK" I R 3900 7750 50 
F52 "INT0_LATCH" I L 1850 3850 50 
F53 "INT1_LATCH" I L 1850 3950 50 
F54 "INT2_LATCH" I L 1850 4050 50 
F55 "INT3_LATCH" I L 1850 4150 50 
F56 "INT4_LATCH" I L 1850 4250 50 
F57 "INT5_LATCH" I L 1850 4350 50 
F58 "INT6_LATCH" I L 1850 4450 50 
F59 "INT7_LATCH" I L 1850 4550 50 
F60 "INTERRUPT_ENABLE_FLAG" I L 1850 4650 50 
F61 "MLU_SEL0" I R 3900 7850 50 
F62 "MLU_SEL1" I R 3900 7950 50 
F63 "MLU_SEL2" I R 3900 8050 50 
F64 "~PC0_OUT_NCLK" I R 3900 3550 50 
F65 "~PC1_OUT_NCLK" I R 3900 3650 50 
F66 "~PC2_OUT_NCLK" I R 3900 3750 50 
F67 "CLK" I L 1850 3750 50 
F68 "SUB_NCLK" I R 3900 4450 50 
F69 "~S0_IN_CLK" I R 3900 5350 50 
F70 "~S1_IN_CLK" I R 3900 5450 50 
F71 "~S2_IN_CLK" I R 3900 5550 50 
F72 "~PC0_IN_NCLK" I R 3900 5650 50 
F73 "~PC1_IN_NCLK" I R 3900 5750 50 
F74 "~PC2_IN_NCLK" I R 3900 5850 50 
F75 "PC_INC_NCLK" I R 3900 7450 50 
F76 "~SP_COUNT_NCLK" I R 3900 7550 50 
F77 "~SP_INC_NCLK" I R 3900 7650 50 
F78 "~RESET" I L 1850 4750 50 
F79 "~INT0_OUT_NCLK" I R 3900 8150 50 
F80 "~INT1_OUT_NCLK" I R 3900 8250 50 
F81 "~INT2_OUT_NCLK" I R 3900 8350 50 
F82 "~INT3_OUT_NCLK" I R 3900 8450 50 
F83 "~INT4_OUT_NCLK" I R 3900 8550 50 
F84 "~INT5_OUT_NCLK" I R 3900 8650 50 
F85 "~INT6_OUT_NCLK" I R 3900 8750 50 
F86 "~INT7_OUT_NCLK" I R 3900 8850 50 
$EndSheet
$EndSCHEMATC
