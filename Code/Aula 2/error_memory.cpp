#include <iostream>

using namespace std;

// =========================================================
// CENÁRIO 1: STACK OVERFLOW (Estouro de Pilha)
// =========================================================
// Como funciona: 
// Cada vez que uma função é chamada, o computador empilha dados 
// (endereço de retorno, variáveis locais) na memória Stack.
// Se chamarmos a função infinitamente, a Stack enche até acabar a RAM.
// =========================================================
void causarStackOverflow(int contador) {
    // Criamos uma variável local para "ocupar espaço" na pilha
    int arrayInutil[100]; 
    
    // Imprime a cada 1000 chamadas para não poluir o terminal
    if (contador % 1000 == 0) {
        cout << "Profundidade da Pilha: " << contador << endl;
    }

    // A CHAMADA RECURSIVA INFINITA
    // Não há condição de parada (if). Ela chama a si mesma para sempre.
    causarStackOverflow(contador + 1);
    // Para ver diferença entre a recursividade e loops, ver pdf da Aula 2.
}

// =========================================================
// CENÁRIO 2: SEGMENTATION FAULT (Violação de Acesso)
// =========================================================
// Como funciona:
// O endereço 0 (NULL ou nullptr) é protegido pelo sistema operacional.
// Tentar ler ou escrever nesse endereço é proibido.
// Quando tentamos, a CPU avisa o SO, que mata o programa imediatamente.
// =========================================================
void causarSegFault() {
    cout << "Tentando acessar memoria proibida..." << endl;

    // 1. Criamos um ponteiro que aponta para NADA (Endereço 0x0)
    int* ponteiroProibido = nullptr; 

    // 2. Tentamos ESCREVER o valor 42 lá dentro
    // ISSO É O CRIME: Desreferenciar um ponteiro nulo
    *ponteiroProibido = 42; 

    // Esta linha nunca será executada
    cout << "Sucesso! (Voce nunca vera essa mensagem)" << endl;
}

// =========================================================
// MAIN
// =========================================================
int main() {
    int opcao;

    cout << "--- ESCOLHA SEU CRASH ---" << endl;
    cout << "1. Causar Stack Overflow (Recursao Infinita)" << endl;
    cout << "2. Causar Segmentation Fault (Ponteiro Null)" << endl;
    cout << "Digite a opcao: ";
    cin >> opcao;

    if (opcao == 1) {
        cout << "Iniciando loop infinito..." << endl;
        causarStackOverflow(1);
    } 
    else if (opcao == 2) {
        causarSegFault();
    } 
    else {
        cout << "Opcao valida. O programa sobreviveu." << endl;
    }

    return 0;
}