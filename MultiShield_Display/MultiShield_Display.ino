// Exemplo de uso da Multi Function Shield - Display
// DQ, dez/2016
// http://dqsoft.blogspot.com

#include<TimerOne.h>

const int pinLatch = 4;
const int pinClock = 7;
const int pinDado = 8;

// Desenho dos numeros
const uint8_t numero[10] = {
  0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90
};

// Selecao dos digitos
const uint8_t digito[4] = {
  0x01, 0x02, 0x04, 0x08
};

// Valor a apresentar no display
uint8_t valor[4];

// Iniciação
void setup() {
  // Inicia os pinos ligados ao display
  pinMode (pinLatch, OUTPUT);
  pinMode (pinClock, OUTPUT);
  pinMode (pinDado, OUTPUT);
  
  // Inicia o timer
  Timer1.initialize(2000); // 2 ms
  Timer1.attachInterrupt (timerIsr);
}

// Programa principal
void loop() {
    static uint8_t cont = 0;
    
    // mudar cada digito do valor com um ritmo diferente
    cli();
    if (++valor[3] > 9) {
        valor[3] = 0;
    }
    if (((cont & 0x03) == 0) && (++valor[2] > 9)) {
        valor[2] = 0;
    }
    if (((cont & 0x0F) == 0) && (++valor[1] > 9)) {
        valor[1] = 0;
    }
    if (((cont & 0x03F) == 0) && (++valor[0] > 9)) {
        valor[0] = 0;
    }
    sei();
 
    cont++;
    delay (100);
}

// Interrupção do timer, atualiza o display a cada 2 ms
void timerIsr() {
  static uint8_t iDig = 0;
  
  digitalWrite(pinLatch, LOW);
  shiftOut(pinDado, pinClock, MSBFIRST, numero[valor[iDig]]);
  shiftOut(pinDado, pinClock, MSBFIRST, digito[iDig]);
  digitalWrite(pinLatch, HIGH);
  iDig = (iDig+1) & 3;
}

