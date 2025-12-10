//Arquivo para ser colado no Tinkercad

class Generica {
    public:
        Generica(uint8_t pin) : m_pin(pin), m_previousMillis(0), m_state(0) {
            pinMode(m_pin, OUTPUT);
        }

        virtual void update() = 0; // Função virtual pura
        
    protected: 
        uint8_t m_pin;
        uint8_t m_state;
        unsigned long m_previousMillis; 
};

class StrobeLight : public Generica {
    public:

        StrobeLight(uint8_t pin) : Generica(pin) {} 
        
        void update() override;
};

void StrobeLight::update() {
    unsigned long currentMillis = millis();
    
    switch (m_state) {
        case 0:
            digitalWrite(m_pin, HIGH);
            if(currentMillis - m_previousMillis >= 200){
                m_state++;
                m_previousMillis = currentMillis; 
                Serial.println(F("Strobe: 1 (ON)"));
            }
            break;
        case 1:
            digitalWrite(m_pin, LOW);
            if(currentMillis - m_previousMillis >= 100){
                m_state++;
                m_previousMillis = currentMillis;
                Serial.println(F("Strobe: 2 (OFF)"));
            }
            break;
        case 2:
            digitalWrite(m_pin, HIGH);
            if(currentMillis - m_previousMillis >= 200){
                m_state++;
                m_previousMillis = currentMillis;
                Serial.println(F("Strobe: 3 (ON)"));
            }
            break;
        case 3:
            digitalWrite(m_pin, LOW);
            if(currentMillis - m_previousMillis >= 850){
                m_state = 0;
                m_previousMillis = currentMillis;
                Serial.println(F("Strobe: 4 (PAUSA)"));
            }
            break;
    }
}


class Beacon : public Generica {
    public:
        Beacon(uint8_t pin) : Generica(pin) {}

        void update() override;
};

void Beacon::update() {
    unsigned long currentMillis = millis();
    
    switch (m_state) {
        case 0:
            digitalWrite(m_pin, HIGH);
            if(currentMillis - m_previousMillis >= 400){
                m_state++;
                m_previousMillis = currentMillis;
                Serial.println(F("Beacon: 1 (ON)"));
            }
            break;
        case 1:
            digitalWrite(m_pin, LOW);
            if(currentMillis - m_previousMillis >= 600){
                m_state = 0;
                m_previousMillis = currentMillis;
                Serial.println(F("Beacon: 2 (OFF)"));
            }
            break;
    }
}

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