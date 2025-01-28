//Codigo para controlar un led con un pulsador
int ledPin = 5;  
int buttonApin = 9;
int buttonBpin = 8;
//leds byte = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
  //eL pinMode del boton se configura en modo pullup, lo que significa que cuando no este activado el boton la señal en ese pin estará en Alto
  //Por esa razon se conecta a GND, para que en cuanto se presione el boton el valor se pongo en bajo.
}

void loop() {
  if(digitalRead(buttonApin) == LOW){
    digitalWrite(ledPin, HIGH);
  }

  if(digitalRead(buttonBpin) == LOW){
    digitalWrite(ledPin, LOW);  
  }
}
