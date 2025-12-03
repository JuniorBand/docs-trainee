#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
    public:
        Led(uint8_t pin);
        void on();
        void off();
    private:
        uint8_t m_pin = 0;
};


#endif