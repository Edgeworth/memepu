EESchema Schematic File Version 4
LIBS:
EELAYER 29 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "two_a_plus_b"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
NoConn ~ 4000 1500
NoConn ~ 2000 1500
Text HLabel 3000 1900 0 50 Input ~ 0
A0
Text HLabel 3000 1100 0 50 Input ~ 0
A0
Text HLabel 3000 1200 0 50 Input ~ 0
A1
Text HLabel 3000 2000 0 50 Input ~ 0
A1
Text HLabel 3000 1300 0 50 Input ~ 0
A2
Text HLabel 3000 2100 0 50 Input ~ 0
A2
Text HLabel 3000 1400 0 50 Input ~ 0
A3
Text HLabel 3000 2200 0 50 Input ~ 0
A3
Text HLabel 3000 1500 0 50 Input ~ 0
A4
Text HLabel 3000 2300 0 50 Input ~ 0
A4
Text HLabel 4000 1100 2 50 Input ~ 0
A5
Text HLabel 3000 1600 0 50 Input ~ 0
A5
Text HLabel 4000 1200 2 50 Input ~ 0
A6
Text HLabel 3000 1700 0 50 Input ~ 0
A6
Text HLabel 4000 1300 2 50 Input ~ 0
A7
Text HLabel 3000 1800 0 50 Input ~ 0
A7
Text HLabel 1000 1900 0 50 Input ~ 0
B0
Text HLabel 1000 2000 0 50 Input ~ 0
B1
Text HLabel 1000 2100 0 50 Input ~ 0
B2
Text HLabel 1000 2200 0 50 Input ~ 0
B3
Text HLabel 1000 2300 0 50 Input ~ 0
B4
Text HLabel 2000 1100 2 50 Input ~ 0
B5
Text HLabel 2000 1200 2 50 Input ~ 0
B6
Text HLabel 2000 1300 2 50 Input ~ 0
B7
Text Label 4000 1600 0 50 ~ 0
two_a0
Text Label 1000 1100 2 50 ~ 0
two_a0
Text Label 1000 1200 2 50 ~ 0
two_a1
Text Label 4000 1700 0 50 ~ 0
two_a1
Text Label 4000 1800 0 50 ~ 0
two_a2
Text Label 1000 1300 2 50 ~ 0
two_a2
Text Label 4000 1900 0 50 ~ 0
two_a3
Text Label 1000 1400 2 50 ~ 0
two_a3
Text Label 4000 2000 0 50 ~ 0
two_a4
Text Label 1000 1500 2 50 ~ 0
two_a4
Text Label 4000 2100 0 50 ~ 0
two_a5
Text Label 1000 1600 2 50 ~ 0
two_a5
Text Label 4000 2200 0 50 ~ 0
two_a6
Text Label 1000 1700 2 50 ~ 0
two_a6
Text Label 4000 2300 0 50 ~ 0
two_a7
Text Label 1000 1800 2 50 ~ 0
two_a7
Text HLabel 2000 1600 2 50 Output ~ 0
OUT0
Text HLabel 2000 1700 2 50 Output ~ 0
OUT1
Text HLabel 2000 1800 2 50 Output ~ 0
OUT2
Text HLabel 2000 1900 2 50 Output ~ 0
OUT3
Text HLabel 2000 2000 2 50 Output ~ 0
OUT4
Text HLabel 2000 2100 2 50 Output ~ 0
OUT5
Text HLabel 2000 2200 2 50 Output ~ 0
OUT6
Text HLabel 2000 2300 2 50 Output ~ 0
OUT7
Text GLabel 4000 1400 2 50 UnSpc ~ 0
GND
Text GLabel 2000 1400 2 50 UnSpc ~ 0
GND
$Sheet
S 1000 1000 1000 1400
U DEADBEEF
F0 "plus_b_adder" 50
F1 "full_adder.sch" 50
F2 "A0" I R 1000 1100 50
F3 "A1" I R 1000 1200 50
F4 "A2" I R 1000 1300 50
F5 "A3" I R 1000 1400 50
F6 "A4" I R 1000 1500 50
F7 "A5" I R 1000 1600 50
F8 "A6" I R 1000 1700 50
F9 "A7" I R 1000 1800 50
F10 "B0" I R 1000 1900 50
F11 "B1" I R 1000 2000 50
F12 "B2" I R 1000 2100 50
F13 "B3" I R 1000 2200 50
F14 "B4" I R 1000 2300 50
F15 "B5" I L 2000 1100 50
F16 "B6" I L 2000 1200 50
F17 "B7" I L 2000 1300 50
F18 "C_IN" I L 2000 1400 50
F19 "C_OUT" O L 2000 1500 50
F20 "Y0" O L 2000 1600 50
F21 "Y1" O L 2000 1700 50
F22 "Y2" O L 2000 1800 50
F23 "Y3" O L 2000 1900 50
F24 "Y4" O L 2000 2000 50
F25 "Y5" O L 2000 2100 50
F26 "Y6" O L 2000 2200 50
F27 "Y7" O L 2000 2300 50
$EndSheet
$Sheet
S 3000 1000 1000 1400
U DEADBEEF
F0 "two_a_adder" 50
F1 "full_adder.sch" 50
F2 "A0" I R 3000 1100 50
F3 "A1" I R 3000 1200 50
F4 "A2" I R 3000 1300 50
F5 "A3" I R 3000 1400 50
F6 "A4" I R 3000 1500 50
F7 "A5" I R 3000 1600 50
F8 "A6" I R 3000 1700 50
F9 "A7" I R 3000 1800 50
F10 "B0" I R 3000 1900 50
F11 "B1" I R 3000 2000 50
F12 "B2" I R 3000 2100 50
F13 "B3" I R 3000 2200 50
F14 "B4" I R 3000 2300 50
F15 "B5" I L 4000 1100 50
F16 "B6" I L 4000 1200 50
F17 "B7" I L 4000 1300 50
F18 "C_IN" I L 4000 1400 50
F19 "C_OUT" O L 4000 1500 50
F20 "Y0" O L 4000 1600 50
F21 "Y1" O L 4000 1700 50
F22 "Y2" O L 4000 1800 50
F23 "Y3" O L 4000 1900 50
F24 "Y4" O L 4000 2000 50
F25 "Y5" O L 4000 2100 50
F26 "Y6" O L 4000 2200 50
F27 "Y7" O L 4000 2300 50
$EndSheet
$EndSCHEMATC
