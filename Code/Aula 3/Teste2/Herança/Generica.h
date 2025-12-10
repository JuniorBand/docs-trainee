#ifndef GENERICA_H
#define GENERICA_H

#include <Arduino.h>

// ==========================================
// CLASSE MÃE (Abstrata)
// ==========================================
class Generica {
    public:
        Generica(uint8_t pin);
        virtual void update() = 0; // Função virtual pura
        
    // MUDANÇA 1: 'protected' em vez de 'private'
    // Agora os filhos (Strobe e Beacon) podem ler/escrever essas variáveis
    protected: 
        uint8_t m_pin;
        uint8_t m_state;
        unsigned long m_previousMillis; 
};

// Implementação do Construtor da Mãe
Generica::Generica(uint8_t pin) : m_pin(pin), m_previousMillis(0), m_state(0) {
    pinMode(m_pin, OUTPUT);
}



#endif