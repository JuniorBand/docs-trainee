//Link do Tinkercad: https://www.tinkercad.com/things/8ch6BaUFIGM-dimmer

#define LIMIT 255
#define LED_PIN 11
#define ANALOG_PIN A0

unsigned long contador = 0;
//uint8_t uinteiro_8_bits = 255;
//int8_t inteiro_8_bits = 127;
//byte byte_1 = 255;

void setup() {
    Serial.begin(9600);

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    
}

void loop(){

  if ((millis() - contador) > 50){
    int valor_analog = analogRead(ANALOG_PIN);
    
    Serial.println("Valor ADC (0-1023): ");
    Serial.println(valor_analog);

    analogWrite(LED_PIN, valor_analog/4); 

    Serial.println("Valor LED (0-255): ");
    Serial.println(valor_analog/4);
    Serial.println("-------------------");
    // analogRead retorna valores de 0 a 1023, analogWrite recebe de 0 a 255
	contador = millis();
  }
  

}