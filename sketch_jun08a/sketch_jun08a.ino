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
    if (armazenavalor == 0xE0E020DF) //Verifica se a tecla 1 foi acionada  
    {  
      digitalWrite(pinoledvermelho, HIGH);  //Acende o led vermelho  
    }  
    if (armazenavalor == 0xE0E0A05F) //Verifica se a tecla 2 foi acionada  
    {  
      digitalWrite(pinoledvermelho, LOW); //Apaga o led vermelho  
    }  
    if (armazenavalor == 0xE0E0609F) //Verifica se a tecla 4 foi acionada  
    {  
      digitalWrite(pinoledverde, HIGH); //Acende o led verde  
    }  
    if (armazenavalor == 0xE0E010EF) //Verifica se a tecla 5 foi acionada  
    {  
      digitalWrite(pinoledverde, LOW); //Apaga o led verde  
    }  
    if (armazenavalor == 0xF3EAEB56) //Verifica se a tecla 9 foi acionada  
    {  
      digitalWrite(pinoledvermelho, LOW); //Apaga todos os leds  
      digitalWrite(pinoledverde, LOW);  
    }  
  irrecv.resume(); //Le o próximo valor  
  }  
}  
