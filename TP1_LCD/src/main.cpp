#include <Arduino.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const byte ledPin = 13;
const byte interruptPin = 0;
volatile byte counter = 0;
unsigned long int lastISR = 0;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;

void counterUp(){
  unsigned long int time = micros();
  if(time - lastISR > 300000){
    lastISR = time;
    counter++;
  }
}

void setup() 
{
    pinMode(ledPin, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), counterUp, CHANGE);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    lcd.print("Click counter:");

    delay(1000);
}

void loop() 
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(counter);

    if(counter == 5){
      lcd.setRGB(255, 0, 0);
    }

    delay(100);
}