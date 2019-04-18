/*-----------------------------------------------------------------------------------------------------------------/*******************************************************************************
**Distancia / Sensor / Acionar servo
*******************************************************************************/

#include <Servo.h>

// servor motor
#define SERVO 6 // Porta Digital 6 PWM
// sensor ultrassonico
#define TRIG 3 // Porta Digital 3 PWM 
#define ECHO 2 // Porta Digital 2 PWM

//BUZZER
#define BUZZER 9 // som buzzer

// distancia ultrassom 
int distancia_obstaculo = 20; 

//buzzer variaveis
float seno = 0;
int frequencia = 0;

//servo variaveis
Servo s; // Variável Servo
int pos = 0; // Posição Servo


void setup() {
  Serial.begin(9600);
  //servo
  s.attach(SERVO);
  //ultra
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  Serial.println("Lendo dados do sensor...");
  //define o pino 9 como saída para BUZZER
  pinMode(BUZZER,OUTPUT);
  
}

void loop() {
  int distancia = sensor_distancia(TRIG,ECHO); // retorno da funcao 
    if(distancia <= distancia_obstaculo){
      Serial.print("Com obstaculo: ");
      Serial.print(distancia);
      Serial.println("cm");
      //funcao
      motor(180);
      som_buzzer(); 
      
    }
    else{
      Serial.print("Sem obstaculo: ");
      Serial.print(distancia);
      Serial.println("cm");
    }
  
    noTone(BUZZER);
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

void som_buzzer(){
  for(int x=0;x<180;x++){
          //converte graus para radiando e depois obtém o valor do seno
          seno=(sin(x*3.1416/180));
          //gera uma frequência a partir do valor do seno
          frequencia = 2000+(int(seno*1000));
          tone(BUZZER,frequencia);
          delay(2);
        }
}

void motor(int grau){
 for(pos = 0; pos < grau; pos++)
  {
    s.write(pos);
    delay(15);
  }
  
  //for(pos = 180; pos >= 0; pos--)
  //{
  //  s.write(pos);
  //  delay(15);
  //}
  //delay(2000); 
   
}
