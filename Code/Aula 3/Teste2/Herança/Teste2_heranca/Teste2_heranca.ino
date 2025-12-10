#include "StrobeLight_filha.h"
#include "Beacon_filha.h"

// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================
StrobeLight luzEstroboscopica(3);
Beacon farol(5);

void setup() {
    Serial.begin(9600); 
    Serial.println("Iniciando Sistema de Luzes...");
}

void loop(){
    luzEstroboscopica.update();
    farol.update();
}