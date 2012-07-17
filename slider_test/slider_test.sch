EESchema Schematic File Version 2  date Tue 17 Jul 2012 11:11:34 AM CEST
LIBS:my_parts
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:slider_test-cache
EELAYER 25  0
EELAYER END
$Descr User 6000 4330
encoding utf-8
Sheet 1 1
Title "capsense slider"
Date "17 jul 2012"
Rev "0.1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3150 2450 3150 2350
Wire Wire Line
	3150 2350 3250 2350
Wire Wire Line
	2250 1050 1850 1050
Wire Wire Line
	1250 1050 1350 1050
Wire Wire Line
	3150 2250 3250 2250
Wire Wire Line
	850  1050 750  1050
Wire Wire Line
	750  1050 750  900 
Wire Wire Line
	3150 2150 3250 2150
Wire Wire Line
	1350 1050 1350 750 
$Comp
L CONN_3 CS1
U 1 1 50052C20
P 3600 2250
F 0 "CS1" V 3550 2250 50  0000 C CNN
F 1 "slider" V 3650 2250 40  0000 C CNN
	1    3600 2250
	1    0    0    -1  
$EndComp
$Comp
L TST TP1
U 1 1 50052699
P 2250 1050
F 0 "TP1" H 2250 1350 40  0000 C CNN
F 1 "TST" H 2250 1300 30  0000 C CNN
	1    2250 1050
	1    0    0    -1  
$EndComp
Text Label 3150 2150 2    60   ~ 0
pad_a_sense
Text Label 3150 2250 2    60   ~ 0
pad_a_store
$Comp
L GND #PWR01
U 1 1 50052303
P 3150 2450
F 0 "#PWR01" H 3150 2450 30  0001 C CNN
F 1 "GND" H 3150 2380 30  0001 C CNN
	1    3150 2450
	1    0    0    -1  
$EndComp
Text Label 750  900  0    60   ~ 0
pad_a_store
Text Label 1350 750  0    60   ~ 0
pad_a_sense
Text Label 1950 1050 0    60   ~ 0
pad_a
$Comp
L R R1
U 1 1 50051D72
P 1600 1050
F 0 "R1" V 1680 1050 50  0000 C CNN
F 1 "R" V 1600 1050 50  0000 C CNN
	1    1600 1050
	0    -1   -1   0   
$EndComp
$Comp
L C C1
U 1 1 50051D64
P 1050 1050
F 0 "C1" V 1100 1150 50  0000 L CNN
F 1 "C" V 1100 950 50  0000 L CNN
	1    1050 1050
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
