#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// led porta 13
int LED=13;
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  // LED 13
  pinMode(LED, OUTPUT);
}
 
void loop()
{
  digitalWrite(LED, HIGH);
  //int posC, int posL,int timeLCD,String texto
  writeLCD(2,0,400,"LED HIGH :)");
  // inicio delocamento
  //rolagem(1,6);
  
  digitalWrite(LED, LOW);
  //char L,int posC, int posL,int timeLCD,String texto
  writeLCD(0,1,400,"LED LOW :(");
  // inicio delocamento
  //rolagem(1,6);
  
   
  
}

void writeLCD(int posC, int posL,int timeLCD, String texto){
  //Limpa a tela
  lcd.clear();
  
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(posC, posL);
  //Envia o texto entre aspas para o LCD
  lcd.print(texto);
  delay(timeLCD);
}

void rolagem(int init, int pos){
  //Rolagem para a esquerda
  for (int posicao = init; posicao < pos; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  //Rolagem para a direita
  for (int posicao = init; posicao < pos; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }
}
