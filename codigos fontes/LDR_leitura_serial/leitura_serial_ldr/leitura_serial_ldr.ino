// serial leitura 5v ldr
int AnalogValue;



void setup() {
  Serial.begin(9600);
  
}

void loop() {
  if (AnalogValue <=900 && AnalogValue >=500) serial();
}
//..............................................
//funcoes.......................................

void serial(){
  AnalogValue = analogRead(A0);
  Serial.println(AnalogValue);
  delay(50);
}
