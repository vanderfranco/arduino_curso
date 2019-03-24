
int x;

int soma(int a, int b){
  return a+b;
}

void setup() {   
 Serial.begin(9600);// abre a porta serial
}

void loop() {
  
  x=soma(1,3);

  
}
