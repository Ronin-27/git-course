//Codigo para sensor de temperatura, nos muestra los valores de temperatura en celsius y faranheit
//Cuando el valor de la temperatura baja del nivel indicado, un led se enciende

int tempPin = A0;
int ledPin = 8;

void setup() {
  Serial.begin(9600); //Se configura la velocidad de transmisión para el puerto serial
  pinMode(ledPin, OUTPUT);

}

void loop() {
  int tempReading = analogRead(tempPin);
  double tempK = log(10000.0 * (1024.0 / tempReading -1));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK)) * tempK);

  float tempC = tempK - 273.15;
  float tempF = (tempC * 9.0)/5.0 + 32.0;

  Serial.print("Temperatura en Celsius: ");
  Serial.println(tempC);

  Serial.print("Temperatura en Farenheit: ");
  Serial.println(tempF);
  
  

  if(tempC <= 18){
    digitalWrite(ledPin,HIGH);
    delay(500);
  }
  else{
    digitalWrite(ledPin,LOW);
    delay(500);
  }
}
