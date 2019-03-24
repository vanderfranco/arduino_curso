String recebido = "";
  
void setup() { 
 
 Serial.begin(9600);
}
  
/**
 * Função que lê uma string da Serial
 * e retorna-a
 */
String leStringSerial(){
  String conteudo = "";
  char caractere;
  
  // Enquanto receber algo pela serial
  while(Serial.available() > 0) {
    // Lê byte da serial
    caractere = Serial.read();
    // Ignora caractere de quebra de linha
    if (caractere != '\n'){
      // Concatena valores
      conteudo.concat(caractere);
    }
    // Aguarda buffer serial ler próximo caractere
    delay(10);
  }
    
  Serial.print("Recebi: ");
  Serial.println(conteudo);
    
  return conteudo;
}
  
void loop() {
  // varialve x
  int x = 0;
  // Se receber algo pela serial
  if (Serial.available() > 0){
    // Lê toda string recebida
    recebido = leStringSerial();
      
    Serial.println(recebido); 
   
    
 
  x = recebido.toInt();

  x= x * x;

          
    Serial.println(x); 
     
}
  
}
