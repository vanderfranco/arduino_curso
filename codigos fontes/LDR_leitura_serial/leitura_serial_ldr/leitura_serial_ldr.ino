// serial leitura 5v ldr
int AnalogValue;


//.............................................
// variavel de leitura

int leitura = 0;

void setup() {
  //inicio comunicacao serial - usb - arduino
  Serial.begin(9600);
}

void loop() {
  leitura = analogRead(A0);
  Serial.println(leitura);
  delay(100);
}
