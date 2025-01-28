int redPin = 3; //Color rojo al pin 3 en el arduino
int greenPin = 5; //Color verde al pin 5 en el arduino
int bluePin = 6; //Color azul al pin 6 en el arduino
//En la seccipon de configuración necesitamos definir los pines como salidas

void setup() {
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);
}

//Los siguientes argumentos representan el brillo de los LED´s o el ciclo de trabajo de la señal PWM que se crea mediante la función analogWrite().
//Estos valores pueden variar de 0 a 255 representando el ciclo de trabjo del 100% de la señal PWM o el brillo maximo del led.
//Haremo nuestro programa que cambiara el brillo del led por cada uno cada segundo.

void loop() {
  setColor(255,0,0); //Color rojo
  delay(1000);
  setColor(0,255,0); //Color verde
  delay(1000);
  setColor(0,0,255);
  delay(1000);
  setColor(255,255,255);
  delay(1000);
  setColor(180,0,255);
  delay(1000);
}

//Vamos a declarar ka funcion setColor que se utiliza en el loop principal

void setColor(int redValue, int greenValue, int blueValue){
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
