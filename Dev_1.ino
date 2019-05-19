#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`


SSD1306Wire  display(0x3c, 18, 19);  //18=SDK  19=SCK  As per labeling on ESP32 DevKit

int Xin= 34; // X Input Pin
int Yin = 33; // Y Input Pin
int KEYin = 5; // Push Button
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

  if(xVal==4095 && yVal<=2120)  //Condition for right direction                 
  {
  display.clear();
  display.drawString( 105, 30, "Right");
  display.display();
 
  }
  
  else if(xVal==0 && yVal<=2120)  //Condition for left direction
  {
  display.clear();
  display.drawString( 2, 30, "Left");
  display.display();
  }
  
  else if(xVal<=2120 && yVal==4095)  //Condition for down direction
  {
  display.clear();
  display.drawString(58, 48, "Down");
  display.display();
  }
  
  else if(xVal<=2120 && yVal==0)    //Condition for Up direction
  {
  display.clear();
  display.drawString( 58, 2, "Up");
  display.display();
  }
  
  if (buttonVal == LOW){
    display.clear();
    display.drawString( 57, 30, "Button");
    display.display();
  }
    delay(50);
}
