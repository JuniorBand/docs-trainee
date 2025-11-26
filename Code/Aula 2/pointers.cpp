#include <iostream>
//#include <cstdlib>
#include <cstring> // Necessário para funções C-style (strcpy, strcat)
#include <string>  // Necessário para std::string

// Usamos o namespace padrão para evitar escrever std::cout toda hora
using namespace std;

// ==========================================
// AULA 2: PONTEIROS E MEMÓRIA (DEMO C++)
// ==========================================

// Uma struct simples para nossos testes
struct DadosVoo {
    float altitude;
    float velocidade;
};

void exemploMalloc();
void exemploRealloc();
void demonstrarStrings();

int main(char argc, char **argv) {
    cout << "--- INICIO DA DEMONSTRACAO ---" << endl << endl;

    // ==================================================
    // PARTE 1: Ponteiros Simples (Na Stack)
    // O conceito de "Endereço" vs "Valor"
    // ==================================================
    cout << "1. PONTEIROS NA STACK (BASICO)" << endl;

    int numero = 42;          // Variável normal (vive na Stack)
    int* ponteiro = &numero;  // Ponteiro que guarda o ENDEREÇO de 'numero'

    cout << "Valor de 'numero': " << numero << endl;
    
    // Em C++ no PC, o endereço é um número hexadecimal longo (ex: 0x7ff...)
    cout << "Endereco de 'numero' (&numero): " << &numero << endl;
    cout << "Valor do 'ponteiro': " << ponteiro << endl; // É o mesmo endereço!
    
    // A Mágica: Mudando o valor à distância (Desreferência)
    *ponteiro = 100; // "Vá até o endereço apontado e escreva 100"

    cout << "Novo valor de 'numero' (alterado via ponteiro): " << numero << endl;
    cout << "-----------------------------------" << endl << endl;


    // ==================================================
    // PARTE 2: Ponteiros com Structs (Eficiência)
    // Por que usamos setas '->' em vez de pontos '.'
    // ==================================================
    cout << "2. PONTEIROS COM STRUCTS" << endl;

    DadosVoo telemetria = {150.5, 30.0}; // Cria a struct na Stack
    DadosVoo* ptrTelemetria = &telemetria; // Cria um ponteiro para ela

    // Acessando via variável normal (usa PONTO)
    cout << "Altitude (via ponto): " << telemetria.altitude << endl;

    // Acessando via ponteiro (usa SETA)
    // A seta '->' é um atalho para: (*ptrTelemetria).altitude
    ptrTelemetria->altitude = 200.0; 

    cout << "Nova Altitude (alterada via seta ->): " << telemetria.altitude << endl;
    cout << "-----------------------------------" << endl << endl;


    // ==================================================
    // PARTE 3: Alocação Dinâmica (No Heap)
    // O Perigo: new e delete
    // ==================================================
    cout << "3. ALOCACAO DINAMICA (HEAP) - CUIDADO!" << endl;

    // Pedimos memória ao Heap "manualmente"
    // O sistema operacional procura um espaço livre na RAM e nos dá o endereço
    int* memoriaDinamica = new int; 
    int* ptr = new int(10);

    cout << "Valor no Heap (Não inicializado): " << *memoriaDinamica << endl;

    *memoriaDinamica = 999; // Guardamos um valor lá dentro

    cout << "Valor no Heap: " << *memoriaDinamica << endl;
    cout << "Endereco no Heap: " << memoriaDinamica << endl;

    // OBRIGATÓRIO: Devolver a memória!
    // Se esquecer isso aqui, temos um "Memory Leak" (Vazamento)
    delete memoriaDinamica; 

    cout << "Memoria devolvida (delete)." << endl;

    // OBS: Se tentarmos acessar *memoriaDinamica agora, o programa pode travar (SegFault)!
    // Isso é um "Dangling Pointer" (Ponteiro Solto).

    cout << endl << "--- FIM DA DEMONSTRACAO ---" << endl;

    char x {}; // assume this is assigned memory address 140
    char& ref { x }; // ref is an lvalue reference to x (when used with a type, & means lvalue reference)

    x = 'a';
    cout << x << endl;
    ref = 'b';
    cout << x << endl;

    int* ptr1, ptr2;   // incorrect: ptr1 is a pointer to an int, but ptr2 is just a plain int!
    int* ptr3, * ptr4; // correct: ptr3 and ptr4 are both pointers to an int


    // QUIZ
    // short value{ 7 }; // &value = 0012FF60
	// short otherValue{ 3 }; // &otherValue = 0012FF54

	// short* ptr{ &value };

	// cout << &value << '\n';
	// cout << value << '\n';
	// cout << ptr << '\n';
	// cout << '\n';
	// cout << *ptr << '\n';

	// *ptr = 9;

	// cout << &value << '\n';
	// cout << value << '\n';
	// cout << ptr << '\n';
	// cout << *ptr << '\n';
	// cout << '\n';

	// ptr = &otherValue;

	// cout << &otherValue << '\n';
	// cout << otherValue << '\n';
	// cout << ptr << '\n';
	// cout << *ptr << '\n';
	// cout << '\n';

	// cout << sizeof(ptr) << '\n';
	// cout << sizeof(*ptr) << '\n';


    //demonstrarStrings();

    return 0;
}

void exemploMalloc() {
    // Quero um array dinâmico de 5 inteiros
    // 5 * 2 bytes (no Uno) = 10 bytes requisitados
    int* vetor = (int*) malloc(5 * sizeof(int));

    // SEMPRE verifique se a alocação funcionou!
    if (vetor == NULL) {
        // Sem memória suficiente! Tratar erro aqui.
        return;
    }

    // Usando como um array normal
    for (int i = 0; i < 5; i++) {
        vetor[i] = i * 10;
    }
    
    // ... uso do vetor ...
    
    free(vetor); // Nunca esqueça de liberar!
}

void exemploRealloc() {
    // 1. Alocamos 2 inteiros
    int* ptr = (int*) malloc(2 * sizeof(int));
    
    // 2. Ops, precisamos de mais espaço! Queremos 10 inteiros.
    // CUIDADO: Não sobrescreva 'ptr' diretamente, pois se falhar, você perde o endereço original.
    int* tempPtr = (int*) realloc(ptr, 10 * sizeof(int));
    
    if (tempPtr == NULL) {
        // Falhou! A memória original (ptr) ainda existe e é válida.
        // Trate o erro.
    } else {
        // Sucesso! O sistema moveu os dados.
        ptr = tempPtr; // Atualizamos nosso ponteiro principal
    }

    // Agora 'ptr' aponta para um espaço que cabe 10 inteiros.
    // Os dados antigos (0 e 1) foram preservados/copiados.
    
    free(ptr);
}

void demonstrarStrings() {
    cout << "--- INICIO: demonstrarStrings() ---" << endl << endl;
    
    // =================================================
    // 1. O JEITO 'SEGURO' (char[]) - Stack
    // =================================================
    cout << "[1] char[] (Array de Caracteres)" << endl;
    
    // Reserva 50 bytes na Stack. Tamanho fixo e garantido.
    char buffer[50]; 
    
    // Em C puro, não usamos '=', usamos funções de cópia
    strcpy(buffer, "Temperatura: "); 
    
    // Para concatenar (juntar), usamos strcat
    strcat(buffer, "25 C"); 

    cout << "   Valor: " << buffer << endl;
    cout << "   Tamanho ocupado na memoria: " << sizeof(buffer) << " bytes (Fixo)" << endl;
    cout << "-----------------------------------" << endl;


    // =================================================
    // 2. O ACESSO (char*) - Ponteiro
    // =================================================
    cout << "[2] char* (Ponteiro para Caractere)" << endl;

    // Caso A: Apontando para uma string literal (Read-Only / Flash no Arduino)
    const char* ponteiroFixo = "Ola Mundo"; 

    // Caso B: Apontando para o nosso buffer modificável
    char* ponteiroMovel = buffer; 
    //&buffer[0]
    
    cout << "   Ponteiro fixo aponta para: " << ponteiroFixo << endl;
    
    // Podemos usar o ponteiro para ler o buffer
    cout << "   Ponteiro movel leu do buffer: " << ponteiroMovel << endl;

    //(void*)p
    
    // Avançando o ponteiro na memória (Aritmética de Ponteiros)
    ponteiroMovel += 13; // Pula "Temperatura: "
    cout << "   Ponteiro avancou e leu: " << ponteiroMovel << endl; // Imprime "25 C"
    cout << "-----------------------------------" << endl;


    // =================================================
    // 3. O JEITO DINÂMICO (std::string) - Heap
    // =================================================
    cout << "[3] std::string (Objeto C++)" << endl;
    
    // Esta é a versão PC do "String" do Arduino.
    // Parece mágica, mas aloca memória no Heap.
    string texto = "Sistema: ";
    
    
    // A concatenação é fácil, mas causa realloc por trás dos panos
    texto += "Ligado"; 
    
    cout << "   Valor: " << texto << endl;
    cout << "   Tamanho atual: " << texto.length() << " caracteres" << endl;
    
    // OBS: No PC (com Gigabytes de RAM), isso é ótimo. 
    // No Arduino (com 2KB), isso causa fragmentação.
    
    cout << endl << "--- FIM ---" << endl;
}