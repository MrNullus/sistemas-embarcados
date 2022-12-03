// Sensor
const int trigger = 10; 
const int echo    = 9; 

// Leds
const int led_vermelho = 11;
const int led_amarelo  = 12;
const int led_verde    = 13;

float distancia;

void setup(){
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(led_vermelho,OUTPUT);
  pinMode(led_amarelo,OUTPUT);
  pinMode(led_verde,OUTPUT);
  pinMode(echo,INPUT);
}

void loop(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);      
  
  digitalWrite(trigger, HIGH);  
  delayMicroseconds(10);      
  
  digitalWrite(trigger, LOW); 
  distancia = pulseIn(echo, HIGH);   
  
  distancia = distancia/58;         
                                   
  Serial.print("Distancia = ");
  Serial.print(distancia);         
  Serial.print(" cm");                   
  
  if (distancia >= 2.1 && distancia < 79.0) {
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarelo, LOW);
  	digitalWrite(led_vermelho, HIGH);
    
    Serial.print("\nMuitoPerto\n");
  }
  
  if (distancia >= 79.0 && distancia < 189.0) {
  	digitalWrite(led_verde, LOW);
    digitalWrite(led_amarelo, HIGH);
  	digitalWrite(led_vermelho, LOW);
    
    Serial.print("\nPerto\n");
  }
  
  if (distancia >= 189.0) {
  	digitalWrite(led_verde, HIGH);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_vermelho, LOW);
    
    Serial.print("\nDistante\n");
  }
  
}                             


