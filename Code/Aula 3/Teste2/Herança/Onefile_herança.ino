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

// ==========================================
// CLASSE FILHA 1: StrobeLight
// ==========================================
// MUDANÇA 2: Adicionado ': public'
class StrobeLight : public Generica {
    public:
        // MUDANÇA 3: O Construtor Obrigatório
        // Ele recebe o pino e repassa para a Generica(pin)
        StrobeLight(uint8_t pin) : Generica(pin) {} 
        
        void update() override;
};

void StrobeLight::update() {
    unsigned long currentMillis = millis();
    
    // Agora funciona porque m_state é 'protected'
    switch (m_state) {
        case 0:
            digitalWrite(m_pin, HIGH);
            if(currentMillis - m_previousMillis >= 200){
                m_state++;
                m_previousMillis = currentMillis; // Lógica corrigida aqui (ordem)
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

// ==========================================
// CLASSE FILHA 2: Beacon
// ==========================================
class Beacon : public Generica {
    public:
        // MUDANÇA 3: O Construtor Obrigatório
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