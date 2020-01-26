#include <Arduino.h>

int val = 0;
const byte ledPin = 13;
const byte interruptPin = 0;
volatile byte state = LOW;

void blink() {
  state = !state;
}

void setup() {
  // put your setup code here, to run once:
  /*
  pinMode(0, INPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  */
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  //BLINK 
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
   // wait for a second
  delay(1000);
  */
 /*
 val = digitalRead(0);
 digitalWrite(LED_BUILTIN, val);
 */
  digitalWrite(ledPin, state);
}

