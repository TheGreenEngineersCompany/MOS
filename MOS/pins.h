/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Pin Ussage       //// PWM Pins: 2-13 and 44-46

0 Extrusion Motor Direction Control
1 SSR Heater Relay
2 Thermocouple CLK
3 PWM for Motor 
4 Thermocouple CS
5                   // used for hall effect sensor for dimensional control
6 X TouchScreen Plate 
7 Y TouchScreen Plate 
8 Thermocouple DO
9                    // used for pwm motor control of the automatic spooler
10 SD_CS
11 SD_DI
12 SD_DO
13 SD_SCK

A0 LCD_RD 
A1 LCD_WR also YP which is a part of the Y panel
A2 LCD_CD also XM which is a part of the X panel
A3 LCD_CS
A4 LCD_RESET
A5               /// will later be used on dimensional control as pressure control

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

#if defined(__SAM3X8E__)
    #undef __FlashStringHelper::F(string_literal)
    #define F(string_literal) string_literal
#endif

#define YP A1  // Other Sheild with yellow pins is A3
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 7  // other sheild uses pin 9
#define XP 6   // other sheild uses pin 8 

#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
// optional
#define LCD_RESET A4
#define Thermo A15

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// start of stuff for L298N Dual H Bridge
#define PWM_MOTOR1 35

#define IN1_MOTOR1 34// pin to change motor direction that attaches to mechanical relay
#define IN2_MOTOR1 36

// start of stuff for 2 solid state relay board
#define SSR1_HEATER 33

// start of stuff for thermocouple digital amp AD8495 1 analog pins required
#define Thermo A15


