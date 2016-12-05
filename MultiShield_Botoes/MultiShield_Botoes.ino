// Exemplo de uso da Multi Function Shield - Botoes
// DQ, dez/2016
// http://dqsoft.blogspot.com

const int pinLed1 = 10;
const int pinLed2 = 11;
const int pinLed3 = 12;
const int pinLed4 = 13;

const int pinBotao1 = A1;
const int pinBotao2 = A2;
const int pinBotao3 = A3;

const int leds[] = { pinLed1, pinLed2, pinLed3, pinLed4 };
#define NLEDS (sizeof(leds) / sizeof(leds[0]))

const int botoes[] = { pinBotao1, pinBotao2, pinBotao3 };
#define NBOTOES (sizeof(botoes) / sizeof(botoes[0]))

const int nAcoes = min(NLEDS, NBOTOES);

void setup() {
  for (int i = 0; i < NLEDS; i++) {
    pinMode (leds[i], OUTPUT);
    digitalWrite (leds[i], HIGH);
  }
}

void loop() {
  for (int i = 0; i < nAcoes; i++) {
    digitalWrite (leds[i], digitalRead(botoes[i]));
  }
  delay (50);
}
