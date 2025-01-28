int latchPin = 4; //Pin 12(RCLK) del registro de desplazamiento al pin 4 en arduino "Pin de seguridad"
int clockPin = 5; //Pin 11(SRCLK) del registro de desplazamiento al pin 5 de arduino "Pin de reloj"
int dataPin = 2; //Pin 14(SER) del registro de desplazamiento al pin 2 de arduino "pin de datos"
byte leds = 0;  //Variable leds, se utiliará para guardar el patro de los leds que estan actualmente encendidos o apagados. 
                //Los datos del tipo "byte" representan números usando 8 bits. Cada bit puede estar encendido o apagad
                //Lo anterior es perfecto para mantener un registro de cuales de nuestros 8 leds estanc encendidos
int currentLED = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  leds = 0;  
}

void loop() {
  
  leds = 0;
  if(currentLED == 7){
    currentLED = 0;
  }
  else{
    currentLED++; //Bucle para incrementar el valor de la variable
  }

  bitSet(leds, currentLED); //Pone en 1 el bit indicado por el currentLED
  digitalWrite(latchPin, LOW); //Pone en bajo el pin latch para indicar el inicio de los datos
  shiftOut(dataPin, clockPin, LSBFIRST, leds); //Indica los pines de data, de clock, el orden de los bits, y la información que mandará
  digitalWrite(latchPin, HIGH); //Pone en alto el pin latch para indicar que finaliza la tranferencia de datos
  delay(250);
}
