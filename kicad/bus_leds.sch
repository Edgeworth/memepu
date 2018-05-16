EESchema Schematic File Version 4
LIBS:cpu-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 9
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
L Device:LED D9
U 1 1 5AFB9E04
P 1150 800
AR Path="/5AFB9CBF/5AFB9E04" Ref="D9"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFB9E04" Ref="D17"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFB9E04" Ref="D25"  Part="1" 
F 0 "D9" H 1250 750 50  0000 C CNN
F 1 "LED" H 1300 850 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 1150 800 50  0001 C CNN
F 3 "~" H 1150 800 50  0001 C CNN
	1    1150 800 
	-1   0    0    1   
$EndComp
$Comp
L Device:R R23
U 1 1 5AFBCADD
P 1450 800
AR Path="/5AFB9CBF/5AFBCADD" Ref="R23"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBCADD" Ref="R31"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBCADD" Ref="R39"  Part="1" 
F 0 "R23" V 1500 650 50  0000 C CNN
F 1 "1K" V 1450 800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 800 50  0001 C CNN
F 3 "~" H 1450 800 50  0001 C CNN
	1    1450 800 
	0    1    1    0   
$EndComp
Text GLabel 1600 800  2    50   Input ~ 0
LED_GND
Wire Wire Line
	1000 800  800  800 
$Comp
L Device:LED D10
U 1 1 5AFBDCCC
P 1150 1000
AR Path="/5AFB9CBF/5AFBDCCC" Ref="D10"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBDCCC" Ref="D18"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBDCCC" Ref="D26"  Part="1" 
F 0 "D10" H 1250 950 50  0000 C CNN
F 1 "LED" H 1300 1050 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 1150 1000 50  0001 C CNN
F 3 "~" H 1150 1000 50  0001 C CNN
	1    1150 1000
	-1   0    0    1   
$EndComp
$Comp
L Device:R R24
U 1 1 5AFBDCD3
P 1450 1000
AR Path="/5AFB9CBF/5AFBDCD3" Ref="R24"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBDCD3" Ref="R32"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBDCD3" Ref="R40"  Part="1" 
F 0 "R24" V 1500 850 50  0000 C CNN
F 1 "1K" V 1450 1000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 1000 50  0001 C CNN
F 3 "~" H 1450 1000 50  0001 C CNN
	1    1450 1000
	0    1    1    0   
$EndComp
Text GLabel 1600 1000 2    50   Input ~ 0
LED_GND
Wire Wire Line
	1000 1000 800  1000
$Comp
L Device:LED D11
U 1 1 5AFBE535
P 1150 1200
AR Path="/5AFB9CBF/5AFBE535" Ref="D11"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBE535" Ref="D19"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBE535" Ref="D27"  Part="1" 
F 0 "D11" H 1250 1150 50  0000 C CNN
F 1 "LED" H 1300 1250 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 1150 1200 50  0001 C CNN
F 3 "~" H 1150 1200 50  0001 C CNN
	1    1150 1200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R25
U 1 1 5AFBE53C
P 1450 1200
AR Path="/5AFB9CBF/5AFBE53C" Ref="R25"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBE53C" Ref="R33"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBE53C" Ref="R41"  Part="1" 
F 0 "R25" V 1500 1050 50  0000 C CNN
F 1 "1K" V 1450 1200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 1200 50  0001 C CNN
F 3 "~" H 1450 1200 50  0001 C CNN
	1    1450 1200
	0    1    1    0   
$EndComp
Text GLabel 1600 1200 2    50   Input ~ 0
LED_GND
Wire Wire Line
	1000 1200 800  1200
$Comp
L Device:LED D12
U 1 1 5AFBE545
P 1150 1400
AR Path="/5AFB9CBF/5AFBE545" Ref="D12"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBE545" Ref="D20"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBE545" Ref="D28"  Part="1" 
F 0 "D12" H 1250 1350 50  0000 C CNN
F 1 "LED" H 1300 1450 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 1150 1400 50  0001 C CNN
F 3 "~" H 1150 1400 50  0001 C CNN
	1    1150 1400
	-1   0    0    1   
$EndComp
$Comp
L Device:R R26
U 1 1 5AFBE54C
P 1450 1400
AR Path="/5AFB9CBF/5AFBE54C" Ref="R26"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBE54C" Ref="R34"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBE54C" Ref="R42"  Part="1" 
F 0 "R26" V 1500 1250 50  0000 C CNN
F 1 "1K" V 1450 1400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 1400 50  0001 C CNN
F 3 "~" H 1450 1400 50  0001 C CNN
	1    1450 1400
	0    1    1    0   
$EndComp
Text GLabel 1600 1400 2    50   Input ~ 0
LED_GND
Wire Wire Line
	1000 1400 800  1400
$Comp
L Device:LED D13
U 1 1 5AFBEE0F
P 1150 1600
AR Path="/5AFB9CBF/5AFBEE0F" Ref="D13"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBEE0F" Ref="D21"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBEE0F" Ref="D29"  Part="1" 
F 0 "D13" H 1250 1550 50  0000 C CNN
F 1 "LED" H 1300 1650 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 1150 1600 50  0001 C CNN
F 3 "~" H 1150 1600 50  0001 C CNN
	1    1150 1600
	-1   0    0    1   
$EndComp
$Comp
L Device:R R27
U 1 1 5AFBEE16
P 1450 1600
AR Path="/5AFB9CBF/5AFBEE16" Ref="R27"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBEE16" Ref="R35"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBEE16" Ref="R43"  Part="1" 
F 0 "R27" V 1500 1450 50  0000 C CNN
F 1 "1K" V 1450 1600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 1600 50  0001 C CNN
F 3 "~" H 1450 1600 50  0001 C CNN
	1    1450 1600
	0    1    1    0   
$EndComp
Text GLabel 1600 1600 2    50   Input ~ 0
LED_GND
Wire Wire Line
	1000 1600 800  1600
$Comp
L Device:LED D14
U 1 1 5AFBEE1F
P 1150 1800
AR Path="/5AFB9CBF/5AFBEE1F" Ref="D14"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBEE1F" Ref="D22"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBEE1F" Ref="D30"  Part="1" 
F 0 "D14" H 1250 1750 50  0000 C CNN
F 1 "LED" H 1300 1850 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 1150 1800 50  0001 C CNN
F 3 "~" H 1150 1800 50  0001 C CNN
	1    1150 1800
	-1   0    0    1   
$EndComp
$Comp
L Device:R R28
U 1 1 5AFBEE26
P 1450 1800
AR Path="/5AFB9CBF/5AFBEE26" Ref="R28"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBEE26" Ref="R36"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBEE26" Ref="R44"  Part="1" 
F 0 "R28" V 1500 1650 50  0000 C CNN
F 1 "1K" V 1450 1800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 1800 50  0001 C CNN
F 3 "~" H 1450 1800 50  0001 C CNN
	1    1450 1800
	0    1    1    0   
$EndComp
Text GLabel 1600 1800 2    50   Input ~ 0
LED_GND
Wire Wire Line
	1000 1800 800  1800
$Comp
L Device:LED D15
U 1 1 5AFBEE2F
P 1150 2000
AR Path="/5AFB9CBF/5AFBEE2F" Ref="D15"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBEE2F" Ref="D23"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBEE2F" Ref="D31"  Part="1" 
F 0 "D15" H 1250 1950 50  0000 C CNN
F 1 "LED" H 1300 2050 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 1150 2000 50  0001 C CNN
F 3 "~" H 1150 2000 50  0001 C CNN
	1    1150 2000
	-1   0    0    1   
$EndComp
$Comp
L Device:R R29
U 1 1 5AFBEE36
P 1450 2000
AR Path="/5AFB9CBF/5AFBEE36" Ref="R29"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBEE36" Ref="R37"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBEE36" Ref="R45"  Part="1" 
F 0 "R29" V 1500 1850 50  0000 C CNN
F 1 "1K" V 1450 2000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 2000 50  0001 C CNN
F 3 "~" H 1450 2000 50  0001 C CNN
	1    1450 2000
	0    1    1    0   
$EndComp
Text GLabel 1600 2000 2    50   Input ~ 0
LED_GND
Wire Wire Line
	1000 2000 800  2000
$Comp
L Device:LED D16
U 1 1 5AFBEE3F
P 1150 2200
AR Path="/5AFB9CBF/5AFBEE3F" Ref="D16"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBEE3F" Ref="D24"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBEE3F" Ref="D32"  Part="1" 
F 0 "D16" H 1250 2150 50  0000 C CNN
F 1 "LED" H 1300 2250 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 1150 2200 50  0001 C CNN
F 3 "~" H 1150 2200 50  0001 C CNN
	1    1150 2200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R30
U 1 1 5AFBEE46
P 1450 2200
AR Path="/5AFB9CBF/5AFBEE46" Ref="R30"  Part="1" 
AR Path="/5AFD5CE2/5AFDC184/5AFDC22F/5AFBEE46" Ref="R38"  Part="1" 
AR Path="/5AFD5CE2/5AFDFFA6/5AFDC22F/5AFBEE46" Ref="R46"  Part="1" 
F 0 "R30" V 1500 2050 50  0000 C CNN
F 1 "1K" V 1450 2200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1380 2200 50  0001 C CNN
F 3 "~" H 1450 2200 50  0001 C CNN
	1    1450 2200
	0    1    1    0   
$EndComp
Text GLabel 1600 2200 2    50   Input ~ 0
LED_GND
Wire Wire Line
	1000 2200 800  2200
Text HLabel 800  800  0    50   Input ~ 0
I0
Text HLabel 800  1000 0    50   Input ~ 0
I1
Text HLabel 800  1200 0    50   Input ~ 0
I2
Text HLabel 800  1400 0    50   Input ~ 0
I3
Text HLabel 800  1600 0    50   Input ~ 0
I4
Text HLabel 800  1800 0    50   Input ~ 0
I5
Text HLabel 800  2000 0    50   Input ~ 0
I6
Text HLabel 800  2200 0    50   Input ~ 0
I7
$EndSCHEMATC
