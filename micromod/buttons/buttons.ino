#include "Wire.h"       //import Wire library

void setup() {
  Serial.begin(9600);
  
  Wire2.begin();
  
  Wire2.beginTransmission(0x20);
  Wire2.write(0x00);
  Wire2.write(0xFF);
  Wire2.endTransmission();

  Wire2.beginTransmission(0x20);
  Wire2.write(0x06);
  Wire2.write(0xFF);
  Wire2.endTransmission();
}

void loop() {
  byte inputs;
  Wire2.beginTransmission(0x20);
  Wire2.write(0x09);
  Wire2.endTransmission();
  Wire2.requestFrom(0x20, 1);
  inputs = Wire2.read();
  Serial.println(inputs, BIN);
  delay(500);
} 
