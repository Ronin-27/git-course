// Incluir librerías necesarias
#include <RH_ASK.h>
#include <SPI.h>

// Definir los pines de transmisión (TX), recepción (RX) y Push-To-Talk (PTT)
#define TX_PIN 3  // Pin de transmisión
#define RX_PIN 2  // No se usa en el transmisor, pero debe definirse
#define PTT_PIN 0 // No se usa, pero requerido por la librería

const int ledPinError = 5;

// Crear el objeto de transmisión con velocidad 2000 bps y pines personalizados
RH_ASK askTx(2000, RX_PIN, TX_PIN, PTT_PIN);

void setup() {
  // Iniciar comunicación serial para depuración
  Serial.begin(9600);
  Serial.println("Inicializando módulo ASK...");
  pinMode(ledPinError, OUTPUT);

  // Inicializar el transmisor y verificar que se inicie correctamente
  if (!askTx.init()) {
    Serial.println("Error al inicializar ASK");
    digitalWrite(ledPinError, HIGH);
    delay(2000);
    digitalWrite(ledPinError, LOW);
    while (1); // Detener ejecución si falla
  }
  
  Serial.println("Módulo ASK inicializado correctamente.");
}

void loop() {
  // Mensaje a enviar (máximo 27 caracteres)
  const char *msg = "Hola mundo";

  // Enviar el mensaje
  askTx.send((uint8_t *)msg, strlen(msg));

  // Esperar hasta que el paquete se haya enviado completamente
  askTx.waitPacketSent();

  // Mensaje de depuración
  Serial.println("Mensaje enviado: " + String(msg));

  // Esperar 1 segundo antes de la próxima transmisión
  delay(1000);
}