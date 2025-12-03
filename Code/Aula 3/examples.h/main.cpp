#include <iostream>
#include "CaixaPreta.h"
#include "Globals.h" // Inclui o cabeçalho

// (Certifique de estar no mesmo diretório dos arquivos👇)
// COMPILE ASSIM NO TERMINAL: g++ CaixaPreta.cpp main.cpp -o programa

using namespace std;

// DEFINIÇÃO DA VARIÁVEL GLOBAL
// Aqui nós criamos a variável de verdade. Só pode ser feito em UM arquivo .cpp.
bool g_sistemaArmado = false; 

int main() {
    cout << ">>> Iniciando Simulacao com Globais <<<" << endl << endl;

    CaixaPreta gravador(101);

    // Tenta gravar com o sistema DESARMADO
    // A CaixaPreta vai ler a global 'false' e bloquear.
    gravador.registrarEvento("Teste de sensores (Ignorado).");

    cout << "\n>>> COMANDO: ARMANDO O SISTEMA <<<\n" << endl;
    
    // Alteramos a variável global!
    // Como é 'extern', a CaixaPreta vai ver essa mudança instantaneamente.
    g_sistemaArmado = true;

    // Agora deve funcionar
    gravador.registrarEvento("Decolagem confirmada.");
    gravador.registrarEvento("Separacao de estagio.");

    gravador.exibirRelatorio();

    return 0;
}