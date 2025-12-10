#ifndef BEACON_FILHA_H
#define BEACON_FILHA_H

#include "Generica.h"

// ==========================================
// CLASSE FILHA 2: Beacon
// ==========================================

class Beacon : public Generica {
    public:
        // MUDANÇA 3: O Construtor Obrigatório
        Beacon(uint8_t pin) : Generica(pin) {}

        void update() override;
};

#endif