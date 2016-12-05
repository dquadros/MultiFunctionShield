// Exemplo de uso da Multi Function Shield - LEDs
// DQ, dez/2016
// http://dqsoft.blogspot.com

const int pinLed1 = 10;
const int pinLed2 = 11;
const int pinLed3 = 12;
const int pinLed4 = 13;

const int leds[] = { pinLed1, pinLed2, pinLed3, pinLed4 };
#define NLEDS (sizeof(leds) / sizeof(leds[0]))

void setup() {
  for (int i = 0; i < NLEDS; i++) {
    pinMode (leds[i], OUTPUT);
    digitalWrite (leds[i], HIGH);
  }
}

void loop() {
  for (int i = 0; i < NLEDS; i++) {
    digitalWrite (leds[i], LOW);
    delay (500);
    digitalWrite (leds[i], HIGH);
  }
}

