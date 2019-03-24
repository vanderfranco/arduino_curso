int x;
int soma(int a, int b){
  return a+b;
}
void setup() {   
 Serial.begin(9600);// abre a porta serial
}
void loop() {
  x=soma(1,7);
  Serial.print("soma = "); // imprime um rótulo
  Serial.print("\t");
  //imprimi a variavel x 
  Serial.print(x); 
  Serial.print("\n");
  delay(1000);
  //alterando o resultado da soma
  x=x+10;
  Serial.print("soma = "); // imprime um rótulo
  Serial.print("\t");
  Serial.print(x); 
  Serial.print("\n");
  delay(1000);
}
