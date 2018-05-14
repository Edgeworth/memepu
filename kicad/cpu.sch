EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
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
S 1000 950  650  400 
U 5ADF0E03
F0 "Clock" 50
F1 "clock.sch" 50
$EndSheet
$Comp
L power:+5V #PWR?
U 1 1 5AE2925B
P 2550 950
F 0 "#PWR?" H 2550 800 50  0001 C CNN
F 1 "+5V" H 2565 1123 50  0000 C CNN
F 2 "" H 2550 950 50  0001 C CNN
F 3 "" H 2550 950 50  0001 C CNN
	1    2550 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5AE29284
P 2850 950
F 0 "#PWR?" H 2850 700 50  0001 C CNN
F 1 "GND" H 2855 777 50  0000 C CNN
F 2 "" H 2850 950 50  0001 C CNN
F 3 "" H 2850 950 50  0001 C CNN
	1    2850 950 
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5AE292E5
P 2550 950
F 0 "#FLG?" H 2550 1025 50  0001 C CNN
F 1 "PWR_FLAG" H 2550 1123 50  0000 C CNN
F 2 "" H 2550 950 50  0001 C CNN
F 3 "~" H 2550 950 50  0001 C CNN
	1    2550 950 
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5AE292FC
P 2850 950
F 0 "#FLG?" H 2850 1025 50  0001 C CNN
F 1 "PWR_FLAG" H 2850 1124 50  0000 C CNN
F 2 "" H 2850 950 50  0001 C CNN
F 3 "~" H 2850 950 50  0001 C CNN
	1    2850 950 
	1    0    0    -1  
$EndComp
$EndSCHEMATC
