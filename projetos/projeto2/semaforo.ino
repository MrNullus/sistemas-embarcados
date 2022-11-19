int vermelho=10;
int amarelo=11;
int verde=12;
int tempo=1000;

void setup()
{
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop()
{
  digitalWrite(vermelho, HIGH);
  delay(tempo); // Wait for 1000 millisecond(s)
  digitalWrite(vermelho, LOW);
 
  
  digitalWrite(amarelo, HIGH);
  delay(tempo); // tempo de execucao Wait for 1000 millisecond(s)
  digitalWrite(amarelo, LOW);
  
  
  digitalWrite(verde, HIGH);
  delay(tempo); // Wait for 1000 millisecond(s)
  digitalWrite(verde, LOW);
  
}