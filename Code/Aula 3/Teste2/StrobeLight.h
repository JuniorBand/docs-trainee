#ifndef STROBELIGHT_H
#define STROBELIGHT_H

#include <Arduino.h>


//typedef void (*meuPrint)(const char *);

class StrobeLight {
    public:
        StrobeLight(uint8_t pin);
        void update();
    private:
        uint8_t m_pin;
        uint8_t m_state;
        unsigned long m_previousMillis;
};



#endif