// C++ code
//
#define pino_led_vermelho 0
#define pino_1_ponte 9
#define pino_ponte_input_1 4
#define pino_ponte_input_2 3
#define pino_sensor 11

void setup()
{
  Serial.begin(9600);
  
  /*
  * Define o pino do sensor no modo entada
  */ 
  pinMode(pino_sensor, INPUT)
  
  /*
  * Definir que as portas estão no modo saída
  * ou seja, vai mandar uma corrente para essas portas
  */ 
  // -> Pinos ponte
  pinMode(pino_1_ponte, OUTPUT);
  pinMode(pino_ponte_input_1, OUTPUT);
  pinMode(pino_ponte_input_2, OUTPUT);
  
  // -> Pinos LEDs e Motor
  pinMode(pino_led_vermelho, OUTPUT); 
  pinMode(pino_led_amarelo, OUTPUT);
  pinMode(pino_motor, OUTPUT);
  
  /* 
  * Iniciar LEDs e motor desligados 
  */
  apagaleds();
  desligarMotor();
}

void loop()
{
   Serial.print("Leitura do sensor: "); Serial.print(pino_sensor); 
   
	if (digitalWrite(pino_sensor) == LOW) 
	{ 
		// -> Estender varal
		apagaleds();
		Serial.println(" Status: Chuvendo"); 
		
		ligarLed(pino_led_amarelo); 
		controlarVaral("estenda", 200);
	} else 
	{
		// -> Retrair varal
		apagaleds(); 
		Serial.println(" Status: Sem chuva"); 
		
		ligarLed(pino_led_vermelho); 
		controlarVaral("retraia", 200);
		// digitalWrite(pino_motor, LOW); 
	}			
}


/*
* Funções auxiliares
*/
void ligarLed(int led) {
	digitalWrite(led, HIGH); 
}
void apagaleds() { 
	digitalWrite(pino_led_vermelho, LOW); 
	digitalWrite(pino_led_amarelo, LOW); 
}	

void desligarMotor() {
  analogWrite(9, 0);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
}

void controlarVaral(string acao, int velocidade) {
	int status_input_1, status_input_2;
		
	switch(acao) {
		case "estenda":
			status_input_1 = HIGH;
			status_input_2 = LOW;
			break;
			
		case "retraia":
			status_input_1 = LOW;
			status_input_2 = HIGH;
			break
			
		default:
			Serial.println("FIZ ALGO ERRADO"); 
			break;
	}
	
	delay(5000); 
	analogWrite(pino_1_ponte, velocidade);
	digitalWrite(pino_ponte_input_1, status_input_1);
	digitalWrite(pino_ponte_input_2, status_input_2);
}