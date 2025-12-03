#include <iostream>
#include <vector>   // Para Vector (Lista Dinâmica)
#include <stack>    // Para Pilha
#include <queue>    // Para Fila
#include <map>      // Para Hash/Map
#include <string>

using namespace std;

// =========================================================
// 1. ESTRUTURAS DE DADOS BÁSICAS
// =========================================================

void demoListas() {
    cout << "--- [1] LISTAS (Sequencias) ---" << endl;

    // A. Lista Estática (Array Clássico)
    // Memória: Stack. Tamanho: Fixo. Rápido e Seguro.
    int listaEstatica[5] = {10, 20, 30, 40, 50};
    cout << "Estatica [0]: " << listaEstatica[0] << " (Tamanho Fixo: 5)" << endl;

    // B. Lista Dinâmica (Vector)
    // Memória: Heap. Tamanho: Flexível. Cuidado com fragmentação em Arduino!
    vector<int> listaDinamica;
    listaDinamica.push_back(100);
    listaDinamica.push_back(200);
    listaDinamica.push_back(300); // O vetor cresce sozinho
    
    cout << "Dinamica [2]: " << listaDinamica[2];
    cout << " (Tamanho atual: " << listaDinamica.size() << ")" << endl << endl;
}

// C. Lista Ligada (Simplesmente Encadeada)
// Conceito: Um nó aponta para o próximo.
struct NoLista {
    int valor;
    NoLista* proximo;
};

void demoListaLigada() {
    cout << "--- [2] LISTA LIGADA (Linked List) ---" << endl;
    
    // Criando nós soltos
    NoLista n1 = {1, nullptr};
    NoLista n2 = {2, nullptr};
    NoLista n3 = {3, nullptr};

    // Ligando os nós (Corrente)
    n1.proximo = &n2; // n1 aponta para n2
    n2.proximo = &n3; // n2 aponta para n3

    // Percorrendo a lista
    NoLista* atual = &n1;
    while (atual != nullptr) {
        cout << "No: " << atual->valor << " -> ";
        atual = atual->proximo; // Pula para o próximo endereço
    }
    cout << "FIM" << endl << endl;
}

// =========================================================
// 2. ESTRUTURAS RESTRITAS (Pilha e Fila)
// =========================================================

void demoPilhaFila() {
    cout << "--- [3] PILHA (Stack) - LIFO ---" << endl;
    // LIFO: Last In, First Out (Pilha de Pratos)
    stack<int> pilha;
    pilha.push(10);
    pilha.push(20);
    pilha.push(30); // 30 foi o último a entrar

    cout << "Topo da Pilha: " << pilha.top() << endl;
    pilha.pop(); // Remove o 30
    cout << "Novo Topo apos pop: " << pilha.top() << endl << endl;


    cout << "--- [4] FILA (Queue) - FIFO ---" << endl;
    // FIFO: First In, First Out (Fila do Banco)
    queue<int> fila;
    fila.push(10); // 10 foi o primeiro a entrar
    fila.push(20);
    fila.push(30);

    cout << "Frente da Fila: " << fila.front() << endl;
    fila.pop(); // Remove o 10
    cout << "Nova Frente apos pop: " << fila.front() << endl << endl;
}

// =========================================================
// 3. BUSCA RÁPIDA (Map / Hash)
// =========================================================

void demoMap() {
    cout << "--- [5] MAPA (Chave -> Valor) ---" << endl;
    
    // Cria um dicionário onde a chave é String e o valor é Float
    map<string, float> sensores;

    sensores["BMP280"] = 25.5;
    sensores["MPU6050"] = 12.8;
    sensores["GPS"] = 500.0;

    // Acesso direto pelo nome (muito rápido)
    cout << "Leitura do GPS: " << sensores["GPS"] << endl;
    cout << "Leitura do BMP: " << sensores["BMP280"] << endl << endl;
}

// =========================================================
// 4. ESTRUTURAS COMPLEXAS (Árvore)
// =========================================================

// Estrutura básica de um nó de árvore binária
struct NoArvore {
    int valor;
    NoArvore* esquerda;
    NoArvore* direita;
};

void demoArvore() {
    cout << "--- [6] ARVORE BINARIA ---" << endl;
    
    // Criando a Raiz
    NoArvore raiz = {10, nullptr, nullptr};
    
    // Criando filhos (Folhas)
    NoArvore filhoEsq = {5, nullptr, nullptr};
    NoArvore filhoDir = {20, nullptr, nullptr};

    // Ligando a árvore
    raiz.esquerda = &filhoEsq; // Menores à esquerda
    raiz.direita = &filhoDir;  // Maiores à direita 

    cout << "Raiz: " << raiz.valor << endl;
    cout << "Esq (<): " << raiz.esquerda->valor << " | Dir (>): " << raiz.direita->valor << endl << endl;
}

// =========================================================
// 5. OOP AVANÇADO (Polimorfismo)
// =========================================================

// Classe Base (Genérica)
class Sensor {
public:
    // 'virtual' permite que filhos sobrescrevam este método
    virtual void ler() {
        cout << "[Sensor Generico] Lendo dados..." << endl;
    }
};

// Classe Filha 1
class SensorBMP : public Sensor {
public:
    void ler() override { // Sobrescreve o método do pai
        cout << "[BMP280] Lendo Pressao e Temperatura." << endl;
    }
};

// Classe Filha 2
class SensorGPS : public Sensor {
public:
    void ler() override {
        cout << "[GPS] Lendo Latitude e Longitude." << endl;
    }
};

void demoPolimorfismo() {
    cout << "--- [7] OOP AVANCADO (Polimorfismo) ---" << endl;

    // Vetor de ponteiros para a classe BASE
    // Aqui mora a mágica: O vetor é de 'Sensor', mas guarda 'BMP' e 'GPS'
    vector<Sensor*> listaSensores;

    listaSensores.push_back(new SensorBMP()); // Adiciona um BMP
    listaSensores.push_back(new SensorGPS()); // Adiciona um GPS

    // Loop polimórfico
    // O código trata todos como "Sensor", mas cada um age de forma diferente
    cout << "Loop de Leitura dos Sensores:" << endl;
    for (Sensor* s : listaSensores) {
        s->ler(); // O C++ decide qual função chamar em tempo de execução
    }

    // Limpeza de memória (importante quando usamos 'new')
    for (Sensor* s : listaSensores) {
        delete s;
    }
    cout << endl;
}

// =========================================================
// MAIN (Onde tudo acontece)
// =========================================================
int main() {
    demoListas();
    demoListaLigada();
    demoPilhaFila();
    demoMap();
    demoArvore();
    demoPolimorfismo();

    return 0;
}