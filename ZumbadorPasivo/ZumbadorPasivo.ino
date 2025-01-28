//Zumbador pasivo con 8 tonos
//El proposito es generar 8 diferentes sonidos, cada sonido durara 1s
int Do = 262, Re = 294, Mi = 330, Fa = 349, Sol = 392, La = 440, Si = 494, Do2 = 524;
int buzz = 12; //No es necesario un pin PWM, cualquier pin funcionará

void setup() {
  pinMode(buzz, OUTPUT); //Inicializa el pin del zumbador como una salida
}

void loop() {
  int wait = 500;
  tone(buzz, Do, wait);
  delay(1000); //Espera 1s

  tone(buzz, Re, wait);
  delay(1000);

  tone(buzz, Mi, wait);
  delay(1000);

  tone(buzz, Fa, wait);
  delay(1000);

  tone(buzz, Sol, wait);
  delay(1000);

  tone(buzz, La, wait);
  delay(1000);

  tone(buzz, Si, wait);
  delay(1000);

  tone(buzz, Do2, wait);
  delay(1000);

  noTone(buzz);
}
