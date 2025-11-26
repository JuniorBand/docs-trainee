### Aula 2: Gerenciamento de Dados (O Recurso Mais Crítico)

* **Objetivo:** Ensinar como organizar e passar dados sem esgotar a minúscula memória SRAM.
* **Tópicos (Geral):**
    * **Structs:** Como agrupar dados.
    * **Ponteiros (Conceito):** O que é `*` (ponteiro) e `&` (endereço/referência).
    * **Referências (`&`):** Conceito crítico para passar `structs` para funções de forma eficiente (`MinhaStruct& dados`).
    * Arrays estáticos (ex: `int meus_dados[10];`).
* **Tópicos (Arduino):**
    * Memória (Flash vs. SRAM) - Onde as coisas vivem. 
    * O Macro `F()` (A solução prática para salvar SRAM).

---

### ✍️ Teste 1 (Avaliação das Aulas 1 e 2)

* **Formato:** "Para casa". Entregar após a Aula 2.
* **Problema Proposto:** "Crie um 'Dimmer Digital'."
    1.  Você terá dois botões: 'Aumentar' e 'Diminuir'.
    2.  Você terá um LED conectado a uma saída PWM.
    3.  Crie uma `struct` chamada `ControleLED` que armazena o pino do LED e o brilho atual (0-255).
    4.  No `loop()`, você deve ler os botões (sem `delay()`).
    5.  Ao clicar em 'Aumentar', o brilho sobe (ex: +10). Ao clicar em 'Diminuir', o brilho desce (ex: -10). O brilho deve respeitar os limites 0 e 255.
    6.  Crie uma função `void atualizaLED(ControleLED& led)` que recebe a `struct` por **referência** e aplica o brilho (`analogWrite`).
    7.  **Bônus:** Use `Serial.println(F("..."))` para imprimir o brilho atual, mas apenas quando ele mudar.
* **Avalia:** Lógica não-bloqueante (`millis`/leitura de botão), `structs`, passagem por referência (`&`), uso de PWM (`analogWrite`) e economia de SRAM (`F()`).

---

### 📚 PDF 2: Tópicos Avançados de Memória

Este PDF é o mergulho profundo na **Aula 2**. Ele detalha o que `malloc` faz e por que `ponteiros` são tão poderosos e perigosos.

**1. 🗺️ O Mapa de Memória (Detalhado)**
* Um diagrama visual  mostrando as 5 seções:
    * **1. Text (Code):** Seu código compilado (Flash no Arduino).
    * **2. Data:** Variáveis globais/estáticas *inicializadas*.
    * **3. BSS:** Variáveis globais/estáticas *não inicializadas*.
    * **4. Heap:** Memória dinâmica (`malloc`/`new`). **A causa da fragmentação!**
    * **5. Stack:** Variáveis locais e chamadas de função.
* **O que é "Stack Overflow"?** (O erro, não o site): Explicando o que acontece quando o Stack e o Heap colidem.

**2. 📌 Ponteiros (O Mergulho Profundo)**
* Revisão de `*` (conteúdo de) e `&` (endereço de).
* **Aritmética de Ponteiros:** O que acontece quando você faz `ptr++` e por que isso funciona com arrays.
* **Ponteiros vs. Arrays:** A relação entre `meu_array[3]` e `*(meu_array + 3)`.
* **Ponteiros de Função:** O conceito de passar uma função como argumento para outra.

**3. 💥 Alocação Dinâmica (O "Heap")**
* **O Jeito C:** `malloc()` e `free()`.
* **O Jeito C++:** `new` e `delete`.
* **O Problema:** Por que isso é **terrível** para microcontroladores.
    * **Fragmentação:** O "queijo suíço". Explicar como `malloc()` deixa "buracos" na SRAM que, eventualmente, quebram o programa, mesmo que haja memória livre.
    * **Memory Leaks:** O que acontece se você der `new` e esquecer de dar `delete`.

---