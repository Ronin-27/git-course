int buzzer = 12; //El pin del zumbador activo

void setup() {
  pinMode(buzzer, OUTPUT); //Iniciliza el pin del zumbador como una salida
}

void loop() {
  unsigned char i;
  while(1){
    for(i=0; i<80; i++){
      digitalWrite(buzzer, HIGH); //Pone en alto la salida digital
      delay(1); //Espera 1ms
      digitalWrite(buzzer,LOW); //Pone en bajo la salida digital
      delay(1); 
    }

    for(i=0; i<100; i++){
      digitalWrite(buzzer, HIGH);
      delay(2);
      digitalWrite(buzzer, LOW);
      delay(2);
    }
  }
}
