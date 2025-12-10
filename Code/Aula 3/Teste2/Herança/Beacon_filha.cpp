#include "Generica.h"
#include <Arduino.h>

// ==========================================
// CLASSE FILHA 2: Beacon
// ==========================================
class Beacon : public Generica {
    public:
        // MUDANÇA 3: O Construtor Obrigatório
        Beacon(uint8_t pin) : Generica(pin) {}

        void update() override;
};

void Beacon::update() {
    unsigned long currentMillis = millis();
    
    switch (m_state) {
        case 0:
            digitalWrite(m_pin, HIGH);
            if(currentMillis - m_previousMillis >= 400){
                m_state++;
                m_previousMillis = currentMillis;
                Serial.println(F("Beacon: 1 (ON)"));
            }
            break;
        case 1:
            digitalWrite(m_pin, LOW);
            if(currentMillis - m_previousMillis >= 600){
                m_state = 0;
                m_previousMillis = currentMillis;
                Serial.println(F("Beacon: 2 (OFF)"));
            }
            break;
    }
}