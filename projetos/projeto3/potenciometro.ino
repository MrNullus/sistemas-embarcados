const int PinoPotenciometro = A0;
const int Led = 13;
const int ledb =10;
int ValorPot = 0;
void setup(){
  // exibir informações do arduino
  Serial.begin(9600); 

  //@ pinMode(portaAnalogica, modo) 
  //	-> define o modo de uma porta analogica input(entrada) ou output(saida)
  pinMode(Led,OUTPUT);
  pinMode(ledb,OUTPUT);

  // colocar a porta PinoPotenciometro = A0 no modo entrada
  pinMode(PinoPotenciometro,INPUT); 
}
 void loop() 
   { 
   // lendo a tensão (que podera ser de: 0 a 1023) vindo da porta analogica A0 
   ValorPot = analogRead(PinoPotenciometro);
   
   // @ digitalWrite(porta, ação)
   // -> irá executar(escrever) alguma ação na porta digital passada
   digitalWrite(Led,HIGH);
   delay(ValorPot);

   digitalWrite(Led,LOW);
   delay(ValorPot);

   // @ Serial.print(texto)
   // -> vai escerever na saída serial uma mensagem
   Serial.print("valor do potenciometro:\n");
   Serial.print(ValorPot);

   if (ValorPot>700){
    digitalWrite(ledb,HIGH);
   }
   else{
     digitalWrite(ledb,LOW);
   }
 }