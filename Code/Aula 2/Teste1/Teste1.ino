#define LIMITE 255
#define BOTAO_AUM 7
#define BOTAO_DIM 12


// ============
// 1. DEFINIÇÃO DE TIPO (Struct)
// ============
typedef struct {
    const uint8_t LED_PIN;
    uint8_t brilho;
} ControleLED;

// ============
// 2. VARIÁVEIS GLOBAIS
// ============
ControleLED led = {9, 0};
bool bAum_ant = HIGH;
bool bDim_ant = HIGH;
unsigned long tAum = 0;
unsigned long tDim = 0;

// ============
// 3. PROTÓTIPO DA FUNÇÃO (A CORREÇÃO MÁGICA)
// ============
// Dizemos ao compilador: "Prometo que esta função existe.
// Confie em mim. O corpo dela está lá embaixo."
void atualizaLED(ControleLED& led);

// ============
// 4. SETUP
// ============
void setup() {
    Serial.begin(9600);
    
    pinMode(BOTAO_AUM, INPUT); // Primeiro botão
    pinMode(BOTAO_DIM, INPUT); // Para o segundo botão
    digitalWrite(BOTAO_AUM, HIGH);
  	digitalWrite(BOTAO_DIM, HIGH);
  	//pinMode(BOTAO_AUM, INPUT_PULLUP); // Primeiro botão
    //pinMode(BOTAO_DIM, INPUT_PULLUP); // Para o segundo botão
  
    pinMode(led.LED_PIN, OUTPUT);
    digitalWrite(led.LED_PIN, LOW);
}

// ============
// 5. LOOP
// ============
// O loop pode chamar atualizaLED() porque ele já viu o protótipo acima
void loop() {
    int16_t brilho = led.brilho; //-32.768 a 32.767

    bool bAum_agora = digitalRead(BOTAO_AUM);
    if ((bAum_agora == LOW) && (bAum_ant == HIGH)) {
        if ((millis() - tAum) > 2000) {
            brilho += 10;
            if (brilho > LIMITE) {brilho = LIMITE;}
            led.brilho = brilho;
            tAum = millis();
            atualizaLED(led);
        }
    }
    bAum_ant = bAum_agora;
    
    bool bDim_agora = digitalRead(BOTAO_DIM);
    if ((bDim_agora == LOW) && (bDim_ant == HIGH)) {
        if ((millis() - tDim) > 200) {
            brilho -= 10;  
            if (brilho < 0) {brilho = 0;}
            led.brilho = brilho;
            atualizaLED(led);
            tDim = millis();
        }
    }
    bDim_ant = bDim_agora;
}

// ============
// 6. IMPLEMENTAÇÃO DA FUNÇÃO
// ============
// O corpo da função foi movido para o final.
void atualizaLED(ControleLED& led) {
    uint8_t brilho = led.brilho;
    analogWrite(led.LED_PIN, brilho);
    Serial.print(F("Novo brilho do LED: "));
    Serial.println(brilho);
}