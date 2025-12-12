// //Arquivo para ser colado no Tinkercad

// class StrobeLight {
//     public:
//         StrobeLight(uint8_t pin);
//         void update();
//     private:
//         uint8_t m_pin;
//         uint8_t m_state;
//         unsigned long m_previousMillis; 
// };

// class Beacon {
//     public:
//         Beacon(uint8_t pin);
//         void update();
//     private:
//         uint8_t m_pin;
//         uint8_t m_state;
//         unsigned long m_previousMillis; 
// };

// StrobeLight::StrobeLight(uint8_t pin) : m_pin(pin), m_previousMillis(0), m_state(0) {
//     pinMode(m_pin, OUTPUT);
// }

// void StrobeLight::update() {
//     unsigned long currentMillis = millis();
    
//     switch (m_state) {
//         case 0:
//             digitalWrite(m_pin, HIGH);
//             if(currentMillis - m_previousMillis >= 200){
//                 m_state++;
//               	Serial.println(F("1 (StrobeLight)"));
//               	Serial.print(F("Tempo: "));
//                 Serial.println(currentMillis - m_previousMillis);
//             	m_previousMillis = currentMillis;
//             }
//             break;
//         case 1:
//             digitalWrite(m_pin, LOW);
//             if(currentMillis - m_previousMillis >= 100){
//                 m_state++;
//               	Serial.println(F("2 (StrobeLight)"));
//                 Serial.print(F("Tempo: "));
//                 Serial.println(currentMillis - m_previousMillis);
//             	m_previousMillis = currentMillis;
//             }
//             break;
//         case 2:
//             digitalWrite(m_pin, HIGH);
//             if(currentMillis - m_previousMillis >= 200){
//                 m_state++;
//               	Serial.println(F("3 (StrobeLight)"));
//                 Serial.print(F("Tempo: "));
//               	Serial.println(currentMillis - m_previousMillis);
//               	m_previousMillis = currentMillis;
//             }
//             break;
//         case 3:
//             digitalWrite(m_pin, LOW);
//             if(currentMillis - m_previousMillis >= 1000){
//                 m_state = 0;
//               	Serial.println(F("4 (StrobeLight)"));
//                 Serial.print(F("Tempo: "));
//                 Serial.println(currentMillis - m_previousMillis);
//             	m_previousMillis = currentMillis;
//             }
//             break;
//     }
// }

// Beacon::Beacon(uint8_t pin)  : m_pin(pin), m_previousMillis(0), m_state(0) {
//     pinMode(m_pin, OUTPUT);
// }

// void Beacon::update() {
//     unsigned long currentMillis = millis();
    
//     switch (m_state) {
//         case 0:
//             digitalWrite(m_pin, HIGH);
//             if(currentMillis - m_previousMillis >= 400){
//                 m_state++;
//               	Serial.println(F("1 (Beaper)"));
//                 Serial.print(F("Tempo: "));
//                 Serial.println(currentMillis - m_previousMillis);
//                 m_previousMillis = currentMillis;

//             }
//             break;
//         case 1:
//             digitalWrite(m_pin, LOW);
//             if(currentMillis - m_previousMillis >= 600){
//                 m_state = 0;
//               	Serial.println(F("2 (Beaper)"));
//                 Serial.print(F("Tempo: "));
//                 Serial.println(currentMillis - m_previousMillis);
//             	m_previousMillis = currentMillis;
//             }
//             break;

//     }

// }

// StrobeLight luzEstroboscopica(3);
// Beacon farol(5);


// void setup() {
//     Serial.begin(9600);
//     Serial.println("Iniciando...");
// }

// void loop(){
//     luzEstroboscopica.update();
//     farol.update();
// }