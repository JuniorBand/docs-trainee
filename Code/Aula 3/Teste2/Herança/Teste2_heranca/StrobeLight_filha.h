#ifndef STROBELIGHT_FILHA_H
#define STROBELIGHT_FILHA_H

#include "Generica.h"

// ==========================================
// CLASSE FILHA 1: StrobeLight
// ==========================================

class StrobeLight : public Generica {
    public:
        // MUDANÇA 3: O Construtor Obrigatório
        // Ele recebe o pino e repassa para a Generica(pin)
        StrobeLight(uint8_t pin) : Generica(pin) {} 
        
        void update() override;
};



#endif