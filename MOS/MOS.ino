#define MEGA_SOFT_SPI 1
#define SOFTWARE_SPI

#include "pins.h"

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>
#include <SPI.h>

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 308); //644
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);


#define BOXSIZE 40

#define MINPRESSURE 10 // was origionally 1
#define MAXPRESSURE 1000

// start of non final variables
int tlx = 0;
int tly = 0;

double tc = 150;
int tt = 230;
int ms = 100;
float dt = 1.75;
float dc = 0.00;

int otc = 0;
int ott = 0;
int oms = 0;
float odt = 0;
float odc = 0;
int ofs = 0;

boolean firstdraw = true;
boolean firstdrawdata = false;
int motoron = 0;
int heateron = 1;
int currentpage = 0;

int variableheat = 1;
unsigned long TimerA;
unsigned long timerdelay =1000UL;
int natc = 0;
int oatc = 0;

// start of methods

boolean touchbox(int xl, int xh, int yl, int yh) //method that handles all of the touch input prams: 2D start of x axis, end of x axis, start of y, end of y
{
   if(tlx > xl && tlx < xh && tly  > yl && tly < yh) //if the touch is inbetween x start and x end aswell as y start and y end then return true
   {
     tlx = 0;
     tly = 0;
     return true;
   }
     return false;
 }
void motorcontrol()
{
  digitalWrite(IN1_MOTOR1,HIGH); 
    digitalWrite(IN2_MOTOR1,LOW); // counter clock wise rotation is set
  
  analogWrite(PWM_MOTOR1, 125 + ((255-125) * (ms / 100))); // changing from motor speed percantage to 255
   Serial.println(125 + ((255-125) * (ms / 100)));
}
void heatercontrol(int state)
{
   if(state != 0)
  {
     if( ((tt - variableheat) < tc)) // if temperature current is less than temperature target by the variable heat aka hysterisis
     { 
         digitalWrite(SSR1_HEATER, HIGH);
     }
     else
     {
       digitalWrite(SSR1_HEATER, LOW);
     }
  }   
}
void automaticalgorithm(double cdc, double changedone, String whatchange)
{
  double calileft = dt - dc;
   if(cdc > 0)
   {
      (calileft / cdc) * changedone;
   } 
   else if(cdc < 0)
   {
     
   }
}
// end of methods

//start needed header files to break up the code
#include "coarsecali.h"
#include "finecali.h"
#include "config.h"

//run code

void setup(void)
{
  Serial.begin(9600);
  
  //  tft.reset();
  uint16_t identifier = 0x9341;
  
  tft.begin(identifier);

  tft.fillScreen(BLACK);
 
  pinMode(13, OUTPUT);
  pinMode(PWM_MOTOR1, OUTPUT);
  pinMode(IN1_MOTOR1, OUTPUT);
   pinMode(IN2_MOTOR1, OUTPUT);
  pinMode(SSR1_HEATER, OUTPUT);
  
  ms = 0;
}

void loop()
{
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);
  
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
 
if(currentpage == 0)
  statuspagedraw();
 if(currentpage == 1)
  setuppagedraw();
  
if(millis() - TimerA >=  timerdelay)
{
  tc = analogRead(Thermo);
 Serial.print(tc);
 tc = tc / 1023;
 Serial.print(" ");
  Serial.print(tc);
  tc = tc * 4.95;
  Serial.print(" ");
  Serial.print(tc);
   tc = tc - 1.25;
  Serial.print(" ");
  Serial.print(tc);
    tc = tc / .005;
  Serial.print(" ");
  Serial.print(tc);
  
  natc = tc;
  tc = (natc + oatc) / 2;
  oatc = natc; 
  Serial.print(" ");
  Serial.print(tc);
  
   tc = tc - 30;
     Serial.print(" ");
  Serial.println(tc);
 
TimerA = millis();
}
  
  
 if(heateron == 1)
 {
    heatercontrol(1);
 }
 else
 {
   digitalWrite(SSR1_HEATER, HIGH);
 }
 if(motoron == 1)
 {
   motorcontrol();
 }
 else
 {
    analogWrite(PWM_MOTOR1, 0); 
 }
  if (p.z > MINPRESSURE) 
  {
    Serial.print("\tPressure = "); Serial.println(p.z);
  int tx;
  int ty;
    // scale from 0->1023 to tft.width
    tx = map(p.y, TS_MAXX, TS_MINX, 0, tft.width());
    ty = map(p.x, TS_MINY, TS_MAXY, tft.height(), 0);
    p.x = tx;
    p.y = ty;
    tlx = p.x;
    tly = p.y;
    Serial.print("("); Serial.print(p.x);
    Serial.print(", "); Serial.print(p.y);
    Serial.println(")");
  }
}


