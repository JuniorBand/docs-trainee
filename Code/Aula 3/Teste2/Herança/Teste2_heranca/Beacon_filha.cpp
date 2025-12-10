#include "Beacon_filha.h"
#include <Arduino.h>


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