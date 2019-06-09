  
#include <IRremote.h>  
  
int RECV_PIN = 11;  
float armazenavalor;  
int pinoledvermelho = 5;  
int pinoledverde = 7;  
  
IRrecv irrecv(RECV_PIN);  
decode_results results;  
  
void setup()  
{  
  pinMode(pinoledvermelho, OUTPUT);   
  pinMode(pinoledverde, OUTPUT);  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa o receptor IR  
}  
   
void loop()  
{  
  if (irrecv.decode(&results))  
  {  
    Serial.print("Valor lido : ");  
    Serial.println(results.value, HEX);  
    armazenavalor = (results.value);  
    if (armazenavalor == 0x511DBB) //Verifica se a tecla 1 foi acionada  
    {  
      digitalWrite(pinoledvermelho, HIGH);  //Acende o led vermelho  
    }  
    if (armazenavalor == 0xFFA25D) //Verifica se a tecla 2 foi acionada  
    {  
      digitalWrite(pinoledvermelho, LOW); //Apaga o led vermelho  
    }  
    
  irrecv.resume(); //Le o próximo valor  
  }  
}  
