### ✍️ Teste 2 (Avaliação da Aula 3)

* **Formato:** "Para casa". Entregar após a Aula 3.
* **Problema Proposto:** "Crie uma classe `StrobeLight` (`.h` e `.cpp`) que simula uma luz estroboscópica de aviônica e controla um circuito de potência (MOSFET)."
#### 1.  **Circuito (Tinkercad):** Monte um circuito de potência. O Pino ~5, por exemplo, do Arduino deve controlar o **Gate** de um **MOSFET Canal-N**.
#### 2.  O MOSFET, por sua vez, deve controlar um LED (que representa sua carga de potência, como um ignitor ou farol). O LED deve ser alimentado por uma fonte de energia separada (ex: Bateria 9V).
#### 3.  **Classe (`StrobeLight.h`):** Crie a classe `StrobeLight`. Ela deve ter, no mínimo:
  * `public: StrobeLight(uint8_t pin);` (Construtor)
  * `public: void update();`
  * `private: uint8_t m_pin;`
  * `private: uint8_t m_state;` (Para a máquina de estados)
  * `private: unsigned long m_previousMillis;`
#### 4.  **Lógica (`StrobeLight.cpp`):** Implemente o construtor (que faz o `pinMode`) e o método `update()`.
#### 5. **Como escrever o construtor e o `update()`:**
Inicialize os seus membros no construtor: `m_pin = pin`, `m_previousMillis = 0`, `m_state = 0`. Além disso, faça o pinMode() da `<Arduino.h>` receber seu `m_pin` como `OUTPUT`.

Já o método `update()` deve implementar uma **Máquina de Estados** (use um `switch-case`) não-bloqueante (usando `millis()`). Como fazer:

Primeiro, inicialize uma variável que receba o tempo atual (`millis()`), por exemplo: `tempo_atual`. Depois, faça o switch-case, em cada caso você deve:

* Fazer o LED acender ou apagar, dependendo do caso.
* Em seguida, faça um condicional que assegura que se o tempo atual menos o tempo anterior (`m_previousMillis`) é maior ou igual ao intervalo proposto no caso.
* Dentro do condicional, adicione 1 ao seu m_state (exceto no último caso), print na tela o estado atual (1, 2, 3...) e a diferença entre os tempos (`Tempo: `...). Por fim, faça o `m_previousMillis` ser igual ao `tempo_atual`.

#### 6. O Padrão de Pisca (Flash Duplo)
* **Estado 0:** LIGADO (200ms)
* **Estado 1:** DESLIGADO (100ms)
* **Estado 2:** LIGADO (200ms)
* **Estado 3:** DESLIGADO (850ms - Pausa Longa) -> Volta para 0.

#### 7.  **Programa Principal (`.ino`):** Seu arquivo `.ino` deve ser limpo. O `setup()` deve estar vazio (o construtor da classe faz o trabalho).

#### 8.  O `loop()` deve conter apenas uma linha de lógica principal: `strobe.update();`.

#### 9. Crie uma segunda classe (ex: `BeaconLight.h` e `BeaconLight.cpp`) com um padrão *diferente* (ex: pulso longo):

  O Padrão de Pisca (Flash Duplo)
  * **Estado 0:** LIGADO (400ms)
  * **Estado 1:** DESLIGADO (600ms)

E controle um segundo circuito de LED/MOSFET no Pino ~3, por exemplo. O `loop()` principal deve rodar os dois (`strobe.update();` e `beacon.update();`) provando que são independentes.

* **Avalia:** Criação de Classes (`.h`/`.cpp`), encapsulamento (`private`), lógica não-bloqueante (`millis()`) dentro de um objeto, **implementação de Máquina de Estados Finita (FSM)**, e **separação de Lógica de Controle e Lógica de Potência (MOSFET)**.

-----

### 🔍 Dicas de Sobrevivência (Hardware e Lógica)

**1. O Segredo da Máquina de Estados (Switch-Case):**
Não tente fazer sequências complexas com `if`. Use um `switch(m_state)` como um roteiro passo-a-passo.

  * **Case 0:** Liga LED. Passou 200ms? Vai pro Case 1.
  * **Case 1:** Desliga LED. Passou 100ms? Vai pro Case 2.
  * ... e assim por diante.

**2. O Hardware "Porteiro" (Entendendo o MOSFET):**
O MOSFET é um interruptor. Se ligar errado, não funciona.

  * **Gate (Esq):** Liga no pino do Arduino (Sinal). Use um resistor de 10k pro GND.
  * **Drain (Meio):** Liga no **NEGATIVO** do LED (Cátodo).
  * **Source (Dir):** Liga no **GND**.

**3. O Erro do "Terra Flutuante" (Common Ground):**
Este é o erro nº 1. Você tem duas fontes de energia (USB e Bateria 9V).

  * **A Regra:** Você **OBRIGATORIAMENTE** deve conectar o pino GND do Arduino ao pino Negativo (-) da Bateria. Isso cria uma referência comum. Sem isso, o MOSFET não entende o sinal do Arduino.

**4. Arquivo Único no Tinkercad:**
O simulador não aceita abas `.h` e `.cpp` separadas.

  * **Como entregar:** Escreva suas classes no topo do arquivo `.ino`, antes do `setup()`. Mantenha a organização visual (Definição da Classe -\> Implementação dos Métodos -\> Setup -\> Loop).

-----

### 🏆 Parte 2: O Bônus (Nível Arquiteto - Herança)

Aqui é onde você ganha destaque. Você vai notar que `StrobeLight` e `Beacon` têm muito código repetido (ambas têm `m_pin`, `m_state`, `m_previousMillis`).

**O Desafio:** Refatore seu código usando **Herança**.

1.  Crie uma classe mãe chamada `Generica` (ou `LuzBase`).
2.  Mova as variáveis comuns e a inicialização (`pinMode`) para ela.
3.  Faça `StrobeLight` e `Beacon` herdarem de `Generica`.

**⚠️ Guia de Sobrevivência da Herança (Erros Clássicos):**

Ao tentar isso, o compilador vai reclamar. Aqui está como resolver:

  * **Erro de Acesso ("is private"):** Se você declarar `int m_pin` como `private` na classe Mãe, os Filhos não conseguem ler\!
      * *Solução:* Mude para **`protected`** na classe Mãe.
  * **Erro de Construção ("no matching function"):** O Filho não nasce sozinho; ele precisa construir a Mãe.
      * *Solução:* Chame o construtor da Mãe na lista de inicialização:
        `StrobeLight(int pin) : Generica(pin) { }`
  * **Erro de Permissão ("inaccessible base"):** A herança é privada por padrão.
      * *Solução:* Use `class Strobe : public Generica` para chamar métodos/variáveis públicas da Mãe a partir do Filho.
