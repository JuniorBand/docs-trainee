#include "CaixaPreta.h"
#include "Globals.h" // Inclui para enxergar g_sistemaArmado
#include <iostream>

using namespace std;

CaixaPreta::CaixaPreta(int idVoo) : m_idVoo(idVoo) {
    //m_idVoo = idVoo;
    m_contadorEventos = 0;
    m_ultimoEvento = "Nenhum dado gravado.";
    cout << "[Sistema] Caixa Preta inicializada." << endl;
}

void CaixaPreta::registrarEvento(string mensagem) {
    // USANDO O EXTERN:
    // A classe verifica a variável global antes de agir
    if (g_sistemaArmado == false) {
        cout << "[AVISO] Sistema DESARMADO. Ignorando evento: " << mensagem << endl;
        return; // Sai da função sem gravar
    }

    m_contadorEventos++;
    m_ultimoEvento = mensagem;
    cout << "[GRAVANDO] Evento " << m_contadorEventos << ": " << mensagem << endl;
}

void CaixaPreta::exibirRelatorio() {
    cout << "\n--- RELATORIO DE VOO #" << m_idVoo << " ---" << endl;
    cout << "Status Final do Sistema: " << (g_sistemaArmado ? "ARMADO" : "DESARMADO") << endl;
    cout << "Total de eventos: " << m_contadorEventos << endl;
    cout << "Ultima leitura: " << m_ultimoEvento << endl;
    cout << "------------------------------" << endl;
}

int CaixaPreta::getTotalEventos() {
    return m_contadorEventos;
}