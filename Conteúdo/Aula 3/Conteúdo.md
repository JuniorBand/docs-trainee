### Aula 3: Organização de Código (OOP e Código de Equipe)

* **Objetivo:** Mostrar como o código da equipe é organizado e como eles podem contribuir de forma limpa.
* **Tópicos (Geral):**
    * `.h` e `.cpp` (Por que separar declaração de implementação).
    * **Classes (O Básico):** O que são? (Juntar dados + funções).
    * Encapsulamento (`public` vs. `private`).
    * Construtores (a "função `setup()`" do seu objeto).
    * **`static`:** Variáveis/métodos da classe.
    * **`extern`:** Como compartilhar variáveis globais entre arquivos (crítico para flags de estado).
* **Tópicos (Arduino):**
    * Máquinas de Estado (O conceito que organiza o `loop()`).
    * Análise do Código da Equipe (O "Grand Finale").
* **💡 Atividade Prática (Em Aula):**
    * Converter o "Blink sem Delay" em uma Classe `Led.h` e `Led.cpp`.
* **🛠️ Ferramenta de Aula (Tinkercad):**
    * **Uso: ✅ Perfeito.**
    * **Por quê:** O Tinkercad suporta múltiplos arquivos. Os trainees podem:
        1.  Clicar no gerenciador de arquivos do Tinkercad.
        2.  Criar os arquivos `Led.h` e `Led.cpp`.
        3.  Escrever o código da classe.
        4.  Incluir (`#include "Led.h"`) no arquivo `.ino` principal.
        5.  Rodar a simulação e ver o código orientado a objetos funcionando.

---

### ✍️ Teste 2 (Avaliação da Aula 3)

* **Formato:** "Para casa". Entregar após a Aula 3.
* **Problema Proposto:** "Crie uma classe `StrobeLight` (`.h` e `.cpp`) que simula uma luz estroboscópica de aviônica e controla um circuito de potência (MOSFET)."
    1.  **Circuito (Tinkercad):** Monte um circuito de potência. O Pino ~9 do Arduino deve controlar o **Gate** de um **MOSFET Canal-N**.
    2.  O MOSFET, por sua vez, deve controlar um LED (que representa sua carga de potência, como um ignitor ou farol). O LED deve ser alimentado por uma fonte de energia separada (ex: Bateria 9V).
    3.  **Classe (`StrobeLight.h`):** Crie a classe `StrobeLight`. Ela deve ter, no mínimo:
        * `public: StrobeLight(int pin);` (Construtor)
        * `public: void update();`
        * `private: int m_pin;`
        * `private: int m_state;` (Para a máquina de estados)
        * `private: unsigned long m_previousMillis;`
    4.  **Lógica (`StrobeLight.cpp`):** Implemente o construtor (que faz o `pinMode`) e o método `update()`.
    5.  O método `update()` deve implementar uma **Máquina de Estados** (use um `switch-case`) não-bloqueante (usando `millis()`).
    6.  O padrão deve ser um **flash-duplo** de aviação: 50ms LIGADO, 50ms DESLIGADO, 50ms LIGADO, 850ms DESLIGADO (pausa longa).
    7.  **Programa Principal (`.ino`):** Seu arquivo `.ino` deve ser limpo. O `setup()` deve estar vazio (o construtor da classe faz o trabalho).
    8.  O `loop()` deve conter apenas uma linha de lógica principal: `strobe.update();`.
    9.  **Bônus (Criatividade):** Crie uma segunda classe (ex: `BeaconLight.cpp`) com um padrão *diferente* (ex: pulso longo) e controle um segundo circuito de LED/MOSFET no Pino ~10. O `loop()` principal deve rodar os dois (`strobe.update();` e `beacon.update();`) provando que são independentes.
* **Avalia:** Criação de Classes (`.h`/`.cpp`), encapsulamento (`private`), lógica não-bloqueante (`millis()`) dentro de um objeto, **implementação de Máquina de Estados Finita (FSM)**, e **separação de Lógica de Controle e Lógica de Potência (MOSFET)**.

---

### 📚 PDF 3: Estruturas de Dados e OOP Avançado

Este PDF é o material de "próximo nível" para quem quer ser um arquiteto de software, cobrindo o que vem depois da **Aula 3**.

**1. 🏗️ Estruturas de Dados (Conceitos)**
* **O que é um TAD?** (Tipo Abstrato de Dado): A ideia de separar o "o que faz" do "como faz".
* **Conceitos de Listas:**
    * **Pilha (Stack):** Conceito LIFO (Last-In, First-Out). Ex: O histórico de "Voltar" do navegador.
    * **Fila (Queue):** Conceito FIFO (First-In, First-Out). Ex: Uma fila de impressão.
* **Conceitos de Busca Rápida:**
    * **Hash/Map:** A ideia de "Chave-Valor". Ex: Dicionário.
* **Conceitos de Hierarquia:**
    * **Árvore (Tree):** Nós, folhas, raiz. Ex: Sistema de arquivos (pastas).
    * **Grafo (Graph):** Nós e arestas. Ex: Google Maps ou redes sociais.
* **Nota:** O foco é em *o que são* e *quando usar*, não em como implementar do zero.

**2. 🏛️ OOP Avançado (Herança e Polimorfismo)**
* **Herança:**
    * **O que é?** Reutilização de código.
    * **Sintaxe:** `class Filha : public Mae { ... };`
    * **Exemplo Prático:**
        * `class Sensor { ... };` (Classe base)
        * `class SensorBMP : public Sensor { ... };` (Herda de Sensor)
        * `class SensorMPU : public Sensor { ... };` (Herda de Sensor)
* **Polimorfismo:**
    * **O que é?** "Muitas formas". O conceito mais poderoso do OOP.
    * **Funções Virtuais (`virtual`):** A palavra-chave que permite o polimorfismo.
    * **Exemplo Prático:**
        * `Sensor* meuArrayDeSensores[2];`
        * `meuArrayDeSensores[0] = new SensorBMP();`
        * `meuArrayDeSensores[1] = new SensorMPU();`
        * `meuArrayDeSensores[0]->update();` // Chama o update() do BMP
        * `meuArrayDeSensores[1]->update();` // Chama o update() do MPU
    * **Classes Abstratas:** O conceito de `virtual void update() = 0;` (uma função que *deve* ser implementada pela classe filha).

