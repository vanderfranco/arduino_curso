//variaveis globais

String red;
float pot = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  
  while (Serial.available() > 0) {
    red = Serial.readStringUntil("\n");
    pot = red.toFloat() * red.toFloat();
    Serial.println(pot);
  }
  
}
