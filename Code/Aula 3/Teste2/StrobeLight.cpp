#include "StrobeLight.h"
#include <Arduino.h>

StrobeLight::StrobeLight(uint8_t pin) : m_pin(pin), m_previousMillis(0), m_state(0) {
    pinMode(m_pin, OUTPUT);
}

void StrobeLight::update() {
    unsigned long currentMillis = millis();
    
    switch (m_state) {
        case 0:
            digitalWrite(m_pin, HIGH);
            if(currentMillis - m_previousMillis >= 200){
                m_state++;
                Serial.println(F("1"));
                Serial.print(F("Tempo: "));
                Serial.println(currentMillis - m_previousMillis);
                m_previousMillis = currentMillis;
            }
            break;
        case 1:
            digitalWrite(m_pin, LOW);
            if(currentMillis - m_previousMillis >= 100){
                m_state++;
                Serial.println(F("2"));
                Serial.print(F("Tempo: "));
                Serial.println(currentMillis - m_previousMillis);
                m_previousMillis = currentMillis;
            }
            break;
        case 2:
            digitalWrite(m_pin, HIGH);
            if(currentMillis - m_previousMillis >= 200){
                m_state++;
                Serial.println(F("3"));
                Serial.print(F("Tempo: "));
                Serial.println(currentMillis - m_previousMillis);
                m_previousMillis = currentMillis;
            }
            break;
        case 3:
            digitalWrite(m_pin, LOW);
            if(currentMillis - m_previousMillis >= 850){
                m_state = 0;
                Serial.println(F("4"));
                Serial.print(F("Tempo: "));
                Serial.println(currentMillis - m_previousMillis);
                m_previousMillis = currentMillis;
            }
            break;
    }
}