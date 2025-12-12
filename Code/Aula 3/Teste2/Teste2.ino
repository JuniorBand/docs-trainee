#include "Beacon.h"
#include "StrobeLight.h"

StrobeLight luzEstroboscopica(7);
Beacon farol(8);


void setup() {
    Serial.begin(9600);
    Serial.println("Iniciando...");
}

void loop(){
    luzEstroboscopica.update();
    farol.update();
}