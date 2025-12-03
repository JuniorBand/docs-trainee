#ifndef CAIXA_PRETA_H
#define CAIXA_PRETA_H

#include <string> // Precisamos incluir string pois usamos std::string aqui

// Apenas a DECLARAÇÃO da classe
class CaixaPreta {
public:
    // Construtor
    CaixaPreta(int idVoo);

    // Métodos (Ações públicas)
    void registrarEvento(std::string mensagem);
    void exibirRelatorio();
    int getTotalEventos();

private:
    // Membros (Dados internos)
    int m_idVoo;
    int m_contadorEventos;
    std::string m_ultimoEvento;
};

#endif