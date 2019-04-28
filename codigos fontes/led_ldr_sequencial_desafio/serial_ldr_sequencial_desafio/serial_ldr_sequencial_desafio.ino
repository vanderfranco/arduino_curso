// serial leitura 5v ldr (DIVISOR DE TENSAO)
int AnalogValue;

// leds verde 10 amarelo 9 branco 8
int v = 10;
int a = 9;
int b = 8;

void setup() {
  Serial.begin(9600);
   pinMode(v, OUTPUT);
   pinMode(a, OUTPUT);
   pinMode(b, OUTPUT);
}

void loop() {
  AnalogValue = analogRead(A0);
  // LED verde
  if (AnalogValue <40 ){
      apagaLeds();
      digitalWrite(v, HIGH);
      delay(50);     
  }
  // LED amarelo
  if (AnalogValue <=800 && AnalogValue >=40 ){
      apagaLeds();
      digitalWrite(a, HIGH);
      delay(500);        
  }
  
  // LED branco
  if (AnalogValue >800 ){
      apagaLeds();
      digitalWrite(b, HIGH);
      delay(50);            
  }
  Serial.println(AnalogValue);
  
  //acendeLeds();
  
}

// funcoes 
void apagaLeds(){
  digitalWrite(b, LOW);
  digitalWrite(a, LOW);
  digitalWrite(v, LOW);
}
void acendeLeds(){
  digitalWrite(b, HIGH);
  digitalWrite(a, HIGH);
  digitalWrite(v, HIGH);
  delay(500);
}
