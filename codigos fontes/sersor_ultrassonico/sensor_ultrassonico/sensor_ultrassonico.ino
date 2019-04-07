/*******************************************************************************
**Distancia / Sensor
*******************************************************************************/
// #include <Ultrasonic.h>  // caso seja necessario incluir a biblioteca no menu Sketch
const int TRIG = 3;
const int ECHO = 2;
const int distancia_obstaculo = 20; 
void setup() {
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  Serial.println("Lendo dados do sensor...");
}

void loop() {
  int distancia = sensor_distancia(TRIG,ECHO); // retorno da funcao 
    if(distancia <= distancia_obstaculo){
      Serial.print("Com obstaculo: ");
      Serial.print(distancia);
      Serial.println("cm");
    }
    else{
      Serial.print("Sem obstaculo: ");
      Serial.print(distancia);
      Serial.println("cm");
    }
  delay(100);
}

int sensor_distancia(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}
