#include "Led.h"
#include <Arduino.h>

Led::Led(uint8_t pin) : m_pin(pin){
    pinMode(m_pin, OUTPUT);
}

void Led::on(){
    digitalWrite(m_pin, HIGH);
}

void Led::off(){
    digitalWrite(m_pin, LOW);
}
