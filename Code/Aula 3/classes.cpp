#include <iostream>
#include <string>
#include <vector>

using namespace std;

// =========================================================
// DEFINIÇÃO DA CLASSE
// =========================================================
class MotorFoguete {
private:
    string m_nome;
    int m_potencia;
    bool m_ligado;

    // STATIC: Pertence à classe, não ao objeto individual.
    // Compartilhado por todos os motores.
    static int s_contadorMotores; 

public:
    // CONSTRUTOR
    MotorFoguete(string nome, int potenciaMaxima){
        m_nome = nome;
        m_potencia = 0;
        m_ligado = false;
        
        // Incrementa o contador global
        s_contadorMotores++; 
        cout << "[Construtor] Motor '" << m_nome << "' criado. Total: " << s_contadorMotores << endl;
    }

    // DESTRUTOR (O Ceifador)
    // Chamado automaticamente quando o objeto sai de escopo ou é deletado.
    ~MotorFoguete() {
        s_contadorMotores--;
        cout << "[Destrutor] Motor '" << m_nome << "' destruido/reciclado. Restam: " << s_contadorMotores << endl;
    }

    // MÉTODOS DE AÇÃO
    void ligar() {
        m_ligado = true;
        m_potencia = 10; 
        cout << ">> " << m_nome << ": IGNICAO!" << endl;
    }

    void desligar() {
        m_ligado = false;
        m_potencia = 0;
        cout << ">> " << m_nome << ": CORTE." << endl;
    }

    void setPotencia(int novaPotencia) {
        if (!m_ligado) {
            cout << "Erro: Ligue o motor " << m_nome << " primeiro!" << endl;
            return;
        }
        if (novaPotencia > 100) novaPotencia = 100;
        m_potencia = novaPotencia;
        cout << ">> " << m_nome << ": Potencia " << m_potencia << "%" << endl;
    }

    // CONST: Promessa de que este método NÃO vai alterar nada na classe.
    int getPotencia() const {
        return m_potencia;
    }

    // MÉTODO ESTÁTICO: Pode ser chamado sem criar nenhum objeto.
    static void imprimirTotalMotores() {
        cout << "=== Relatorio: Existem " << s_contadorMotores << " motores ativos no sistema. ===" << endl;
    }
};

// Inicialização da variável estática (Obrigatório fazer fora da classe)
int MotorFoguete::s_contadorMotores = 0;

namespace junior {

    void qualquer(){}

}


// =========================================================
// MAIN
// =========================================================
int main() {
    cout << "--- INICIO DA SIMULACAO ---" << endl;

    // Chamando método estático antes de ter objetos
    MotorFoguete::imprimirTotalMotores();
 
    // Criando objetos dinamicamente (Heap)
    MotorFoguete* m1 = new MotorFoguete("Merlin 1D", 100);
    MotorFoguete* m2 = new MotorFoguete("Raptor 2", 100);

    MotorFoguete::imprimirTotalMotores(); // Agora deve mostrar 2
   
    m1->ligar();
    m1->setPotencia(80);

    cout << endl << "--- DESTRUINDO UM MOTOR ---" << endl;
    delete m1; // Chama o destrutor de m1 manualmente

    MotorFoguete::imprimirTotalMotores(); // Agora deve mostrar 1 (só o m2)

    cout << endl << "--- FIM DO PROGRAMA (m2 sera destruido aqui pelo SO) ---" << endl;
    // Nota: Como m2 foi alocado com 'new', o correto seria 'delete m2'.
    // O SO limpa a memória, mas o destrutor só roda se dermos delete.
    delete m2; 
    
    return 0;
}