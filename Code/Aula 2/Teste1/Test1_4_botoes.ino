// // ======================
// // PORTAS DOS BOTÕES
// // ======================
// #define LIMITE        255
// #define BOTAO_AUM     7
// #define BOTAO_DIM     12
// #define BOTAO_ZERAR   4
// #define BOTAO_MAX     8

// // ======================
// // STRUCT DO LED
// // ======================
// typedef struct {
//     const uint8_t LED_PIN;
//     uint8_t brilho;
// } ControleLED;

// ControleLED led = {9, 0};

// // Estado anterior
// bool bAum_ant = HIGH;
// bool bDim_ant = HIGH;
// bool bZero_ant = HIGH;
// bool bMax_ant = HIGH;

// // Debounce
// unsigned long tAum = 0;
// unsigned long tDim = 0;
// unsigned long tZero = 0;
// unsigned long tMax = 0;

// // Protótipo
// void atualizaLED(ControleLED& led);

// // ======================
// // SETUP
// // ======================
// void setup() {
//     Serial.begin(9600);

//     pinMode(BOTAO_AUM,   INPUT_PULLUP);
//     pinMode(BOTAO_DIM,   INPUT_PULLUP);
//     pinMode(BOTAO_ZERAR, INPUT_PULLUP);
//     pinMode(BOTAO_MAX,   INPUT_PULLUP);

//     pinMode(led.LED_PIN, OUTPUT);
//     digitalWrite(led.LED_PIN, LOW);
// }

// // ======================
// // LOOP
// // ======================
// void loop() {

//     int16_t brilho = led.brilho;

//     // ----------- AUMENTAR -----------
//     bool bAum = digitalRead(BOTAO_AUM);
//     if (bAum == LOW && bAum_ant == HIGH && millis() - tAum > 200
//     && led.brilho != LIMITE) {
//         brilho += 10;
//         if (brilho > LIMITE) {brilho = LIMITE;}
//         led.brilho = brilho;
//         atualizaLED(led);
//         tAum = millis();
//     }
//     bAum_ant = bAum;

//     // ----------- DIMINUIR -----------
//     bool bDim = digitalRead(BOTAO_DIM);
//     if (bDim == LOW && bDim_ant == HIGH && millis() - tDim > 200
//     && led.brilho != 0) {
//         brilho -= 10;
//         if (brilho < 0) {brilho = 0;}
//         led.brilho = brilho;
//         atualizaLED(led);
//         tDim = millis();
//     }
//     bDim_ant = bDim;

//     // ----------- ZERAR -----------
//     bool bZero = digitalRead(BOTAO_ZERAR);
//     if (bZero == LOW && bZero_ant == HIGH && millis() - tZero > 200
//     && led.brilho != 0) {
//         led.brilho = 0;
//         atualizaLED(led);
//         tZero = millis();
//     }
//     bZero_ant = bZero;

//     // ----------- MÁXIMO -----------
//     bool bMax = digitalRead(BOTAO_MAX);
//     if (bMax == LOW && bMax_ant == HIGH && millis() - tMax > 200
//     && led.brilho != LIMITE) {
//         led.brilho = LIMITE;
//         atualizaLED(led);
//         tMax = millis();
//     }
//     bMax_ant = bMax;
// }

// // ======================
// // FUNÇÃO ATUALIZA LED
// // ======================
// void atualizaLED(ControleLED& led) {
//     analogWrite(led.LED_PIN, led.brilho);
//     Serial.print(F("Brilho atual: "));
//     Serial.print(led.brilho/2.55);
//     Serial.print(F(" "));
//     Serial.println(F("%"));
// }