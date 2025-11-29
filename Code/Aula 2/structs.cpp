#include <iostream>
using namespace std;

// =================================================
// DEFINIÇÃO DA STRUCT
// =================================================
struct SensorData { // Existem outras formas de declarar structs,
// estará lá no final do código.
    // --- Atributos (Variáveis) ---
    int id;
    float temperatura;
    float pressao;
    
    // --- Métodos (Funções dentro da Struct) ---
    
    // 1. Função para exibir os dados (Encapsulamento)
    // O legal é que ela tem acesso direto às variáveis id, temperatura, etc.
    void imprimirRelatorio() {
        cout << "[Metodo Interno] Sensor ID " << id 
             << ": " << temperatura << "C | " << pressao << "hPa" << endl;
    }

    // 2. Função para alterar os dados (Lógica interna)
    void resetarLeituras() {
        temperatura = 0.0;
        pressao = 0.0;
        cout << "[Metodo Interno] Leituras resetadas para zero!" << endl;
    }

    
};


// =================================================
// 1. O JEITO BÁSICO (Cópia) - Função Externa
// =================================================
SensorData modoBasico(SensorData s) {
    cout << "[Funcao Externa/Copia] Lendo: " << s.temperatura << endl;
    s.temperatura = 999.9; // Não muda o original
    return s;
}

// =================================================
// 2. O JEITO PONTEIRO - Função Externa
// =================================================
void modoPonteiro(SensorData* ptr) {
    if (ptr == nullptr) return;
    (*ptr).temperatura = 50.0;
    ptr->temperatura = 50.0; // Muda o original
    cout << "[Funcao Externa/Ponteiro] Alterado para 50.0" << endl;
}

// =================================================
// 3. O JEITO REFERÊNCIA - Função Externa
// =================================================
void modoReferencia(SensorData& ref) {
    ref.pressao = 1020.5; // Muda o original
    cout << "[Funcao Externa/Referencia] Alterado para 1020.5" << endl;
}

// =================================================
// MAIN
// =================================================
int main() {
    // Criando a Struct
    SensorData meuSensor = {1, 25.0, 1000.0};

    // CENÁRIO 1: Variável Direta (Usa PONTO)
    SensorData sensorFisico;
    sensorFisico.id = 1;          // <--- PONTO
    sensorFisico.temperatura = 20.0;
    //cout sensorFisico.pressao

    // CENÁRIO 2: Ponteiro (Usa SETA)
    SensorData* ponteiro = &sensorFisico;
    ponteiro->id = 2;             // <--- SETA (Muda o original)
    ponteiro->temperatura = 30.0; // <--- SETA

    cout << "--- INICIO ---" << endl;
    
    // Usando a FUNÇÃO INTERNA da struct
    // Veja como fica limpo: o próprio objeto sabe se imprimir!

    meuSensor.imprimirRelatorio(); 
    cout << endl;

    modoBasico(meuSensor);
    // meuSensor.imprimirRelatorio(); // Se imprimir aqui, verá que não mudou
    cout << meuSensor.temperatura << endl;

    modoPonteiro(&meuSensor);
    meuSensor.imprimirRelatorio(); // Mudou a temperatura

    modoReferencia(meuSensor);
    meuSensor.imprimirRelatorio(); // Mudou a pressão

    cout << endl << "--- Usando metodo interno para alterar ---" << endl;
    
    // Chamando a função interna que zera tudo
    meuSensor.resetarLeituras();
    
    // Verificando o resultado
    meuSensor.imprimirRelatorio();

    return 0;
}
/*
 * =================================================================
 * 📝 DICA RÁPIDA: COMO ACESSAR DADOS DENTRO DA STRUCT (. vs ->)
 * =================================================================
 * A forma como você acessa as variáveis (id, temperatura...) depende
 * de COMO você tem a struct na sua mão:
 *
 * 1. ACESSO DIRETO (Você tem a Variável ou uma Referência &)
 * Use o PONTO ( . )
 * -> É como abrir a caixa com a mão.
 * Exemplo: 
 * meuSensor.id = 10;
 * referencia.temperatura = 25.5;
 *
 * 2. ACESSO INDIRETO (Você tem um Ponteiro *)
 * Use a SETA ( -> )
 * -> É como seguir uma placa de sinalização até o local da caixa.
 * Exemplo:
 * meuPonteiro->id = 10;
 * * 💡 MNEMÔNICO:
 * - Se é o Objeto: PONTO (.)
 * - Se APOPONTA (Ponteiro): SETA (->)
 * =================================================================
 */

 /* * CHEAT SHEET: STRUCTS & TYPEDEF 
 * Diferenças de declaração entre C e C++
 */

// =========================================================
// 1. SEM TYPEDEF (A forma "Crua")
// =========================================================

struct Robot {
    int id;
    float bateria;
};

// --- Como declarar variáveis (Instanciar): ---

// EM C -> OBRIGATÓRIO escrever 'struct' antes
struct Robot r1; 

// EM C++ -> O 'struct' é opcional (implícito)
Robot r2;         // Válido apenas em C++
struct Robot r3;  // Válido em ambos


// =========================================================
// 2. COM TYPEDEF (Criando um Apelido/Alias)
// =========================================================

typedef struct {
    int id;
    float velocidade;
} Android; // 'Android' agora é um tipo de dado

// --- Como declarar variáveis (Instanciar): ---

// EM C -> Pode usar direto o apelido (sem escrever struct)
Android a1;

// EM C++ -> Mesma coisa
Android a2;


// =========================================================
// 3. COMBO: NOME REAL + TYPEDEF (Comum em Listas/Árvores)
// =========================================================

typedef struct Node {
    int data;
    struct Node* next; // Dentro, ainda precisa de 'struct' (em C)
} NodePtr; // 'NodePtr' é o apelido final

// --- Como declarar variáveis (Instanciar): ---

// EM C:
struct Node n1; // Pelo nome original (precisa de 'struct')
NodePtr n2;     // Pelo apelido (NÃO precisa de 'struct')

// EM C++:
Node n3;        // Pelo nome original (NÃO precisa de 'struct')
NodePtr n4;     // Pelo apelido