// Exemplo de uso da Multi Function Shield - Buzzer
// DQ, dez/2016
// http://dqsoft.blogspot.com

const int pinBotao1 = A1;
const int pinBuzzer = 3;

void setup() {
  pinMode (pinBuzzer, OUTPUT);
  digitalWrite (pinBuzzer, HIGH);
}

void loop() {
  digitalWrite (pinBuzzer, digitalRead(pinBotao1));
}
