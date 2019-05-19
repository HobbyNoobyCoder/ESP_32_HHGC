#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`

SSD1306Wire  display(0x3c, 18, 19);  //18=SDK  19=SCK  As per labeling on ESP32 DevKit

#define Xin 34 // X Input Pin
#define Yin  33 // Y Input Pin
#define KEYin  5 // Push Button

int pix_x=63,pix_y=31;

void setup ()
{

  pinMode (KEYin, INPUT);
  pinMode(Xin, INPUT);
  pinMode(Yin, INPUT);
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}
void loop ()
{
  int xVal, yVal, buttonVal; 
  xVal = analogRead (Xin);
  yVal = analogRead (Yin);
  buttonVal = digitalRead (KEYin);

display.clear();
display.setPixel(pix_x,pix_y);
display.display();

  if(xVal==4095 && yVal<=2120)  //Condition for right direction                 
  {
  
 pix_x=(pix_x+1)%127;
 
  }
  
  else if(xVal==0 && yVal<=2120)  //Condition for left direction
  {
    if(pix_x==0)
      { pix_x=128;}
    pix_x--;
  }
  
  else if(xVal<=2120 && yVal==4095)  //Condition for down direction
  {
  pix_y=(pix_y+1)%63;
  }
  
  else if(xVal<=2120 && yVal==0)    //Condition for Up direction
  {
  if(pix_y==0)
      { pix_y=64;}
    pix_y--;
  }
  
  if (buttonVal == LOW){
    pix_x=63;
    pix_y=31;
  }
    delay(50);
}
