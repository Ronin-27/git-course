#include <RH_ASK.h>
#include <SPI.h>

const int ledPinOn = 8;  // LED indicador
const int ledPinOff = 7;
RH_ASK askRx(2000, 2, 3, 0); // 2000bps, Pin RX = 2, TX no se usa en receptor

void setup() {
  pinMode(ledPinOff, OUTPUT);
  Serial.begin(9600);
  Serial.println("Receptor RF Iniciado...");
  
  if (!askRx.init()) {
    Serial.println("Error al inicializar ASK");
    digitalWrite(ledPinOff, HIGH);
    delay(2000);
    digitalWrite(ledPinOff, LOW);
    while (1);
  }

  pinMode(ledPinOn, OUTPUT);
}

void loop() {
  uint8_t msg[10 + 1];
  uint8_t msgLen = 10;

  if (askRx.recv(msg, &msgLen)) {
    msg[msgLen] = '\0'; 
    Serial.print("Mensaje recibido: ");
    Serial.println((char*)msg);

    digitalWrite(ledPinOn, HIGH);
    delay(500);
    digitalWrite(ledPinOn, LOW);
  }

  delay(100);
}
