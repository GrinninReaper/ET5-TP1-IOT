#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_L3GD20_U.h>
#include <Wire.h>

// Define the pins for SPI
#define GYRO_CS 4 // labeled CS
#define GYRO_DO 5 // labeled SA0
#define GYRO_DI 6  // labeled SDA
#define GYRO_CLK 7 // labeled SCL
#define out SerialUSB
  
Adafruit_L3GD20 gyro;

const byte interruptPin = 0;
const byte ledPin = 13;

int dataX = 0;
int dataY = 0;
int dataZ = 0;

void readValue(){
  gyro.read();
  out.println("X: "); out.println((int)gyro.data.x * SENSORS_DPS_TO_RADS);   out.println(" ");
  out.println("Y: "); out.println((int)gyro.data.y * SENSORS_DPS_TO_RADS);   out.println(" ");
  out.println("Z: "); out.println((int)gyro.data.z * SENSORS_DPS_TO_RADS); out.println(" ");
}

void setup() {
  // put your setup code here, to run once
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), readValue, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);

}