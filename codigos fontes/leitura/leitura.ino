int pinoLed = 12; 
int status = 0;
void setup(){
  pinMode(pinoLed, OUTPUT); 
  digitalWrite(pinoLed, LOW); 
  Serial.begin(9600); 
}    
void loop(){
  
  
  while(Serial.available() > 0) {  
    int c = Serial.readStringUntil('\n').toInt();
    
    Serial.println(c); 
    if (c == 0){
      digitalWrite(pinoLed, LOW);
    }
    if (c == 1){
      digitalWrite(pinoLed, HIGH);
    }
     
  }
  
  
  
}
