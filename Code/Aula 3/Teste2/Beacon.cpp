#include "Beacon.h"
#include <Arduino.h>

Beacon::Beacon(uint8_t pin)  : m_pin(pin), m_previousMillis(0), m_state(0) {
    pinMode(m_pin, OUTPUT);
}

void Beacon::update() {
    unsigned long currentMillis = millis();
    
    switch (m_state) {
        case 0:
            digitalWrite(m_pin, HIGH);
            if(currentMillis - m_previousMillis >= 400){
                m_state++;
                Serial.println(F("1"));
                Serial.print(F("Tempo: "));
                Serial.println(currentMillis - m_previousMillis);
                m_previousMillis = currentMillis;
            }
            break;
        case 1:
            digitalWrite(m_pin, LOW);
            if(currentMillis - m_previousMillis >= 600){
                m_state = 0;
                Serial.println(F("2"));
                Serial.print(F("Tempo: "));
                Serial.println(currentMillis - m_previousMillis);
                m_previousMillis = currentMillis;
            }
            break;

    }

}