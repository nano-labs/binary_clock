#include "Adafruit_TLC5947.h"
#include "RTClib.h"

#define NUM_TLC5947 1
#define data   5
#define clock   4
#define latch   6
#define oe  -1

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5947, clock, data, latch);
RTC_DS3231 rtc;

uint16_t H1 = 0;
uint16_t H2 = 4;
uint16_t M1 = 8;
uint16_t M2 = 12;
uint16_t S1 = 16;
uint16_t S2 = 20;

int BRIGHTNESS = 300; // 4095 max

void setup() {
  rtc.begin();
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  // testAll();
  tlc.begin();
  who();
}

void loop() {
  // testAll();
  setTime();
  delay(1000);
}

void testAll() {
  for (uint16_t pos = 0; pos <= 23; pos++) {
    tlc.setPWM(pos, BRIGHTNESS);
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
    if ((number >> (3-shift)) & 1) {
      tlc.setPWM(position + shift, BRIGHTNESS);
    } else {
      tlc.setPWM(position + shift, 0);
    }
  }
}

void setTime() {
  DateTime now = rtc.now();
  uint8_t hh = now.hour();
  uint8_t mm = now.minute();
  uint8_t ss = now.second();
  setDigit(H1, hh / 10);
  setDigit(H2, hh % 10);
  setDigit(M1, mm / 10);
  setDigit(M2, mm % 10);
  setDigit(S1, ss / 10);
  setDigit(S2, ss % 10);
  tlc.write();
}

void who() {
  // 0 1 2 3 4 5 6 7 8 9 A B C D E F
  setDigit(H1, 15);
  setDigit(H2, 10);
  setDigit(M1, 11);
  setDigit(M2, 1);
  setDigit(S1, 0);
  setDigit(S2, 0);
  tlc.write();
  delay(3000);
}
