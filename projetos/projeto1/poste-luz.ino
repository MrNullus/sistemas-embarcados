// C++ code
//
const int led_vermelho = 10; 
const int led_ama      = 9; 
const int led_verde    = 8; 
const int ldrPin       = A1;  
int valorldr           = 0;

void setup() {

  Serial.begin(9600);
  
  pinMode(led_vermelho, OUTPUT); 
  pinMode(led_ama, OUTPUT);
  pinMode(led_verde, OUTPUT);
  
  pinMode(ldrPin, INPUT);  
  
}

void loop() {

  valorldr = analogRead(ldrPin);   

  Serial.println("valor do LDR");
  Serial.println(valorldr);

  	// < 300 -> vermelho
  if (valorldr <=300) {
    digitalWrite(led_vermelho, HIGH);               
  } else {
    digitalWrite(led_vermelho, LOW);
  }
  
  // > 300 <= 800 -> amarelo 
  if (valorldr > 300 && valorldr <= 800) {
    digitalWrite(led_ama, HIGH);
  } else {
    digitalWrite(led_ama, LOW);
  }
  
  // > 800 -> verde
  if (valorldr > 800) {
  	digitalWrite(led_verde, HIGH);
  } else {
  	digitalWrite(led_verde, LOW);
  }
  
  
  
  
}