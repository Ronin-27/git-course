int ledPin = 8; //El pasador del led

void setup() {
  pinMode(ledPin, OUTPUT); //Inicializar LED_BUILTIN pin digital como salida
}

void loop() {
  digitalWrite (ledPin, HIGH); //Enciende el Led (High es el nivel de voltaje)
  delay(10000); //Espera un segundo
  digitalWrite (ledPin, LOW); //Apagar el led haciendo el voltaje LOW
  delay(10000); 
}
