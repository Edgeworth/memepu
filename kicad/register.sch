EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 11 11
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
L 74xx:74HCT574 U?
U 1 1 5AFDC202
P 1500 1900
AR Path="/5AFD5CE2/5AFDC202" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC202" Ref="U8"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC202" Ref="U10"  Part="1" 
AR Path="/5AFD5CE2/5AFCB536/5AFDC202" Ref="U12"  Part="1" 
AR Path="/5AFD5CE2/5AFCB55D/5AFDC202" Ref="U14"  Part="1" 
AR Path="/5AFD5CE2/5AFCB584/5AFDC202" Ref="U16"  Part="1" 
AR Path="/5AFD5CE2/5AFD86BE/5AFDC202" Ref="U18"  Part="1" 
F 0 "U18" H 1600 2600 50  0000 C CNN
F 1 "74HCT574" H 1500 1600 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 1500 1900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HCT574" H 1500 1900 50  0001 C CNN
	1    1500 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0130
U 1 1 5AFDC209
P 1500 2700
AR Path="/5AFD5CE2/5AFDC184/5AFDC209" Ref="#PWR0130"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC209" Ref="#PWR0136"  Part="1" 
AR Path="/5AFD5CE2/5AFCB536/5AFDC209" Ref="#PWR020"  Part="1" 
AR Path="/5AFD5CE2/5AFCB55D/5AFDC209" Ref="#PWR028"  Part="1" 
AR Path="/5AFD5CE2/5AFCB584/5AFDC209" Ref="#PWR034"  Part="1" 
AR Path="/5AFD5CE2/5AFD86BE/5AFDC209" Ref="#PWR0142"  Part="1" 
F 0 "#PWR0142" H 1500 2450 50  0001 C CNN
F 1 "GND" H 1505 2527 50  0000 C CNN
F 2 "" H 1500 2700 50  0001 C CNN
F 3 "" H 1500 2700 50  0001 C CNN
	1    1500 2700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0131
U 1 1 5AFDC20F
P 1500 1100
AR Path="/5AFD5CE2/5AFDC184/5AFDC20F" Ref="#PWR0131"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC20F" Ref="#PWR0137"  Part="1" 
AR Path="/5AFD5CE2/5AFCB536/5AFDC20F" Ref="#PWR018"  Part="1" 
AR Path="/5AFD5CE2/5AFCB55D/5AFDC20F" Ref="#PWR027"  Part="1" 
AR Path="/5AFD5CE2/5AFCB584/5AFDC20F" Ref="#PWR033"  Part="1" 
AR Path="/5AFD5CE2/5AFD86BE/5AFDC20F" Ref="#PWR0143"  Part="1" 
F 0 "#PWR0143" H 1500 950 50  0001 C CNN
F 1 "VCC" H 1517 1273 50  0000 C CNN
F 2 "" H 1500 1100 50  0001 C CNN
F 3 "" H 1500 1100 50  0001 C CNN
	1    1500 1100
	1    0    0    -1  
$EndComp
Text HLabel 1000 2300 0    50   Input ~ 0
REG_IN
Text HLabel 1000 1400 0    50   Input ~ 0
I0
Text HLabel 1000 1500 0    50   Input ~ 0
I1
Text HLabel 1000 1600 0    50   Input ~ 0
I2
Text HLabel 1000 1700 0    50   Input ~ 0
I3
Text HLabel 1000 1800 0    50   Input ~ 0
I4
Text HLabel 1000 1900 0    50   Input ~ 0
I5
Text HLabel 1000 2000 0    50   Input ~ 0
I6
Text HLabel 1000 2100 0    50   Input ~ 0
I7
$Comp
L 74xx:74HC245 U?
U 1 1 5AFDC21E
P 2750 1900
AR Path="/5AFD5CE2/5AFDC21E" Ref="U?"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC21E" Ref="U9"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC21E" Ref="U11"  Part="1" 
AR Path="/5AFD5CE2/5AFCB536/5AFDC21E" Ref="U13"  Part="1" 
AR Path="/5AFD5CE2/5AFCB55D/5AFDC21E" Ref="U15"  Part="1" 
AR Path="/5AFD5CE2/5AFCB584/5AFDC21E" Ref="U17"  Part="1" 
AR Path="/5AFD5CE2/5AFD86BE/5AFDC21E" Ref="U19"  Part="1" 
F 0 "U19" H 2850 2600 50  0000 C CNN
F 1 "74HC245" H 2800 1600 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 2750 1900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 2750 1900 50  0001 C CNN
	1    2750 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0132
U 1 1 5AFDC225
P 1000 2400
AR Path="/5AFD5CE2/5AFDC184/5AFDC225" Ref="#PWR0132"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC225" Ref="#PWR0138"  Part="1" 
AR Path="/5AFD5CE2/5AFCB536/5AFDC225" Ref="#PWR016"  Part="1" 
AR Path="/5AFD5CE2/5AFCB55D/5AFDC225" Ref="#PWR026"  Part="1" 
AR Path="/5AFD5CE2/5AFCB584/5AFDC225" Ref="#PWR032"  Part="1" 
AR Path="/5AFD5CE2/5AFD86BE/5AFDC225" Ref="#PWR0144"  Part="1" 
F 0 "#PWR0144" H 1000 2150 50  0001 C CNN
F 1 "GND" H 1005 2227 50  0000 C CNN
F 2 "" H 1000 2400 50  0001 C CNN
F 3 "" H 1000 2400 50  0001 C CNN
	1    1000 2400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0133
U 1 1 5AFDC23D
P 2750 2700
AR Path="/5AFD5CE2/5AFDC184/5AFDC23D" Ref="#PWR0133"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC23D" Ref="#PWR0139"  Part="1" 
AR Path="/5AFD5CE2/5AFCB536/5AFDC23D" Ref="#PWR025"  Part="1" 
AR Path="/5AFD5CE2/5AFCB55D/5AFDC23D" Ref="#PWR031"  Part="1" 
AR Path="/5AFD5CE2/5AFCB584/5AFDC23D" Ref="#PWR037"  Part="1" 
AR Path="/5AFD5CE2/5AFD86BE/5AFDC23D" Ref="#PWR0145"  Part="1" 
F 0 "#PWR0145" H 2750 2450 50  0001 C CNN
F 1 "GND" H 2755 2527 50  0000 C CNN
F 2 "" H 2750 2700 50  0001 C CNN
F 3 "" H 2750 2700 50  0001 C CNN
	1    2750 2700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0134
U 1 1 5AFDC243
P 2250 2300
AR Path="/5AFD5CE2/5AFDC184/5AFDC243" Ref="#PWR0134"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC243" Ref="#PWR0140"  Part="1" 
AR Path="/5AFD5CE2/5AFCB536/5AFDC243" Ref="#PWR023"  Part="1" 
AR Path="/5AFD5CE2/5AFCB55D/5AFDC243" Ref="#PWR029"  Part="1" 
AR Path="/5AFD5CE2/5AFCB584/5AFDC243" Ref="#PWR035"  Part="1" 
AR Path="/5AFD5CE2/5AFD86BE/5AFDC243" Ref="#PWR0146"  Part="1" 
F 0 "#PWR0146" H 2250 2150 50  0001 C CNN
F 1 "VCC" H 2267 2473 50  0000 C CNN
F 2 "" H 2250 2300 50  0001 C CNN
F 3 "" H 2250 2300 50  0001 C CNN
	1    2250 2300
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0135
U 1 1 5AFDC249
P 2750 1100
AR Path="/5AFD5CE2/5AFDC184/5AFDC249" Ref="#PWR0135"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC249" Ref="#PWR0141"  Part="1" 
AR Path="/5AFD5CE2/5AFCB536/5AFDC249" Ref="#PWR024"  Part="1" 
AR Path="/5AFD5CE2/5AFCB55D/5AFDC249" Ref="#PWR030"  Part="1" 
AR Path="/5AFD5CE2/5AFCB584/5AFDC249" Ref="#PWR036"  Part="1" 
AR Path="/5AFD5CE2/5AFD86BE/5AFDC249" Ref="#PWR0147"  Part="1" 
F 0 "#PWR0147" H 2750 950 50  0001 C CNN
F 1 "VCC" H 2767 1273 50  0000 C CNN
F 2 "" H 2750 1100 50  0001 C CNN
F 3 "" H 2750 1100 50  0001 C CNN
	1    2750 1100
	1    0    0    -1  
$EndComp
Text HLabel 2250 2400 0    50   Input ~ 0
REG_OUT
Text HLabel 3250 1400 2    50   Input ~ 0
O0
Text HLabel 3250 1500 2    50   Input ~ 0
O1
Text HLabel 3250 1600 2    50   Input ~ 0
O2
Text HLabel 3250 1700 2    50   Input ~ 0
O3
Text HLabel 3250 1800 2    50   Input ~ 0
O4
Text HLabel 3250 1900 2    50   Input ~ 0
O5
Text HLabel 3250 2000 2    50   Input ~ 0
O6
Text HLabel 3250 2100 2    50   Input ~ 0
O7
Wire Wire Line
	2000 1400 2250 1400
Wire Wire Line
	2000 1500 2250 1500
Wire Wire Line
	2000 1600 2250 1600
Wire Wire Line
	2000 1700 2250 1700
Wire Wire Line
	2000 1800 2250 1800
Wire Wire Line
	2000 1900 2250 1900
Wire Wire Line
	2000 2000 2250 2000
Wire Wire Line
	2000 2100 2250 2100
$EndSCHEMATC
