#include <iostream>
#include <string>

using namespace std;

// =========================================================
// 1. O CONCEITO DE "DRIVER" EM C (Struct com Funções)
// =========================================================
// Imagine que você tem sensores diferentes (GPS, Barômetro),
// mas quer tratá-los de forma igual.

// typedef int* ptr;
// typedef int Integer;

// int *ptr(); Nãooooo
// int (*ptr)(); Simmm

// Definimos um "tipo" para a função de leitura
// (Recebe nada, retorna float)
typedef float (*FuncaoLeitura)();
// using FuncaoLeitura = float(*)();

typedef char Character;
using Character = char;

// Definimos um "tipo" para a função de calibração
// (Recebe int nivel, retorna void)
typedef void (*FuncaoCalibrar)(int);

// A STRUCT MÁGICA
struct DriverSensor {
    string nome;
    // A struct guarda PONTEIROS para as funções que fazem o trabalho
    // float (*ler)();
    // void (*calibrar)(int);
    FuncaoLeitura ler;
    FuncaoCalibrar calibrar;
};

// =========================================================
// 2. IMPLEMENTAÇÃO DAS FUNÇÕES REAIS
// =========================================================

// --- Funções do GPS ---
float lerGPS() {
    cout << "[Hardware] Lendo satelites..." << endl;
    return -23.5505; // Latitude falsa
}
void calibrarGPS(int nivel) {
    cout << "[Hardware] Calibrando GPS nivel " << nivel << "..." << endl;
}

// --- Funções do Barômetro ---
float lerBarometro() {
    cout << "[Hardware] Medindo pressao..." << endl;
    return 1013.25; // hPa falso
}
void calibrarBarometro(int nivel) {
    cout << "[Hardware] Zerando Barometro (Offset " << nivel << ")..." << endl;
}

// =========================================================
// 3. A FUNÇÃO GENÉRICA (O "Cliente")
// =========================================================
// Esta função não sabe se é GPS ou Barômetro. Ela só sabe
// que recebe um "DriverSensor" e sabe como usá-lo.
void executarDiagnostico(DriverSensor& driver) {
    cout << "\n--- Diagnostico: " << driver.nome << " ---" << endl;
    
    // Chama a função de calibração guardada na struct
    driver.calibrar(5); 
    
    // Chama a função de leitura guardada na struct
    float val = driver.ler();
    
    cout << "Valor lido: " << val << endl;
    cout << "---------------------------------" << endl;
}

void processar(void (*f)(int)){
    f(431);
}

// =========================================================
// MAIN
// =========================================================
int main() {
    // 1. Configurando o Driver do GPS
    // Estamos "conectando" as funções do GPS na struct
    DriverSensor driverGPS;
    driverGPS.nome = "GPS Ublox";
    driverGPS.ler = &lerGPS;           // Aponta para a função lerGPS
    driverGPS.calibrar = &calibrarGPS; // Aponta para a função calibrarGPS

    // 2. Configurando o Driver do Barômetro
    DriverSensor driverBaro;
    driverBaro.nome = "BMP280";
    driverBaro.ler = &lerBarometro;
    driverBaro.calibrar = &calibrarBarometro;

    // 3. Usando o sistema genérico
    // O mesmo código roda lógicas completamente diferentes!
    executarDiagnostico(driverGPS);
    executarDiagnostico(driverBaro);

    void (*f)(int) = &calibrarBarometro;
    processar(f);

    return 0;
}

