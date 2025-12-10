#ifndef BEACON_H
#define BEACON_H

#include <Arduino.h>

class Beacon {
    public:
        Beacon(uint8_t pin);
        void update();
    private:
        uint8_t m_pin;
        uint8_t m_state;
        unsigned long m_previousMillis; 
};



#endif