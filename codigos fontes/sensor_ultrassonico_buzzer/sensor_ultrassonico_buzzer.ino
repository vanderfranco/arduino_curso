/*******************************************************************************
**Distancia / Sensor
*******************************************************************************/
// #include <Ultrasonic.h>  // caso seja necessario incluir a biblioteca no menu Sketch
const int TRIG = 3;
const int ECHO = 2;
const int distancia_obstaculo = 40; 
//buzzer
float seno;
int frequencia;


void setup() {
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  Serial.println("Lendo dados do sensor...");
  //define o pino 9 como saída
  pinMode(9,OUTPUT);
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
    if(distancia<40){
        for(int x=0;x<180;x++){
          //converte graus para radiando e depois obtém o valor do seno
          seno=(sin(x*3.1416/180));
          //gera uma frequência a partir do valor do seno
          frequencia = 2000+(int(seno*1000));
          tone(9,frequencia);
          delay(2);
        }      
    }
    noTone(9);
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
