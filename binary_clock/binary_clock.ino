#include "Adafruit_TLC5947.h"
#include "RTClib.h"

#define NUM_TLC5947 1
#define data   4
#define clock   3
#define latch   5
#define oe  -1

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5947, clock, data, latch);
RTC_DS3231 rtc;

uint16_t H1[] = {23, 22, 21, 20};
uint16_t H2[] = {19, 18, 17, 16};
uint16_t M1[] = {15, 12, 13, 14};
uint16_t M2[] = {0, 1, 2, 3};
uint16_t S1[] = {4, 5, 6, 7};
uint16_t S2[] = {8, 9, 10, 11};

int BRIGHTNESS = 300; // 4095 max

void setup() {
  Serial.begin(9600);

  rtc.begin();
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  // testAll();
  tlc.begin();
  who();
}

void loop() {
  // allOff();
  // testNumbers();
  // testAll();
  setTime();
  delay(200);
  // read();

}

void read() {
  char message[3];
  if (Serial.available()) {
    int bytesRead = Serial.readBytesUntil('\n', message, sizeof(message) - 1);
    message[bytesRead] = '\0';

    Serial.print("You said: ");
    Serial.println(message);
    uint16_t i;
    sscanf(message, "%d", &i);
    allOff();
    tlc.setPWM(i, BRIGHTNESS);
    tlc.write();
  }
}

void testAll() {
  for (uint16_t pos = 0; pos <= 23; pos++) {
    tlc.setPWM(pos, BRIGHTNESS);
  }
  tlc.write();
  delay(3000);
  allOff();
  delay(3000);
}

void testNumbers() {
  allOff();
  for (int n = 0; n <= 9; n++) {
    setDigit(H1, n);
    setDigit(H2, n);
    setDigit(M1, n);
    setDigit(M2, n);
    setDigit(S1, n);
    setDigit(S2, n);
    tlc.write();
    delay(2000);
  }
}

void setDigit(uint16_t position[], uint8_t number) {
  for (uint8_t shift = 0; shift <= 3; shift++) {
    if ((number >> (3-shift)) & 1) {
      tlc.setPWM(position[shift], BRIGHTNESS);
    } else {
      tlc.setPWM(position[shift], 0);
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

void allOff() {
  for (uint16_t pos = 0; pos <= 23; pos++) {
    tlc.setPWM(pos, 0);
  }
  tlc.write();
}

void who() {
  allOff();
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
