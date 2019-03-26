int pinoLed = 12; 
int status = 0;
void setup(){
  pinMode(pinoLed, OUTPUT); 
  digitalWrite(pinoLed, LOW); 
  Serial.begin(9600); 
}    
void loop(){
  char c = Serial.read(); 
 
  if (c == 'l'){ 
      digitalWrite(pinoLed, HIGH); 
      Serial.println("LED LIGADO"); 
  
  }
  if (c == 'd'){ 
      digitalWrite(pinoLed, LOW); 
      Serial.println("LED DESLIGADO"); 
    
  }   
}
