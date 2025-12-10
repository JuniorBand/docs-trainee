#include "StrobeLight_filha.h"
#include <Arduino.h>


void StrobeLight::update() {
    unsigned long currentMillis = millis();
    
    // Agora funciona porque m_state é 'protected'
    switch (m_state) {
        case 0:
            digitalWrite(m_pin, HIGH);
            if(currentMillis - m_previousMillis >= 200){
                m_state++;
                m_previousMillis = currentMillis; // Lógica corrigida aqui (ordem)
                Serial.println(F("Strobe: 1 (ON)"));
            }
            break;
        case 1:
            digitalWrite(m_pin, LOW);
            if(currentMillis - m_previousMillis >= 100){
                m_state++;
                m_previousMillis = currentMillis;
                Serial.println(F("Strobe: 2 (OFF)"));
            }
            break;
        case 2:
            digitalWrite(m_pin, HIGH);
            if(currentMillis - m_previousMillis >= 200){
                m_state++;
                m_previousMillis = currentMillis;
                Serial.println(F("Strobe: 3 (ON)"));
            }
            break;
        case 3:
            digitalWrite(m_pin, LOW);
            if(currentMillis - m_previousMillis >= 850){
                m_state = 0;
                m_previousMillis = currentMillis;
                Serial.println(F("Strobe: 4 (PAUSA)"));
            }
            break;
    }
}