int led = 13; // variavel inteira valor 13

void setup() {   
  pinMode(led, OUTPUT); // funcao pinmode que recebe dois valores 
}

void loop() {
  digitalWrite(led, HIGH);  
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
