#include "Adafruit_TLC5947.h"

#define NUM_TLC5947 1

#define data   5
#define clock   4
#define latch   6
#define oe  -1

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5947, clock, data, latch);

uint16_t H1 = 0;
uint16_t H2 = 4;

uint16_t M1 = 8;
uint16_t M2 = 12;

uint16_t S1 = 16;
uint16_t S2 = 20;

void setup() {
  // testAll();
  tlc.begin();
}

void loop() {
  // testAll();
  setDigit(M1, 0);
  tlc.write();
  delay(1000);
  setDigit(M1, 1);
  tlc.write();
  delay(1000);
  setDigit(M1, 2);
  tlc.write();
  delay(1000);
  setDigit(M1, 3);
  tlc.write();
  delay(1000);
  setDigit(M1, 4);
  tlc.write();
  delay(1000);
  setDigit(M1, 5);
  tlc.write();
  delay(1000);
  setDigit(M1, 6);
  tlc.write();
  delay(1000);
  setDigit(M1, 7);
  tlc.write();
  delay(1000);
  setDigit(M1, 8);
  tlc.write();
  delay(1000);
  setDigit(M1, 9);
  tlc.write();
  delay(1000);
}

void testAll() {
  for (uint16_t pos = 0; pos <= 23; pos++) {
    tlc.setPWM(pos, 500);
  }
  tlc.write();
  delay(3000);
  for (uint16_t pos = 0; pos <= 23; pos++) {
    tlc.setPWM(pos, 0);
  }
  tlc.write();
  delay(3000);
}

void setDigit(uint16_t position, uint8_t number) {
  for (uint8_t shift = 0; shift <= 3; shift++) {
    if ((number >> shift) & 1) {
      tlc.setPWM(position + shift, 1000);
    } else {
      tlc.setPWM(position + shift, 0);
    }
  }
}
