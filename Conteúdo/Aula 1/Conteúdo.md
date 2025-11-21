### 🚀 Cronograma Híbrido de Treinamento (3 Aulas)

Este plano equilibra conceitos fundamentais de C++ (computação básica) com a aplicação prática em sistemas embarcados (Arduino), preparando os trainees para entender e contribuir com o código da equipe.

---

### Aula 1: Fundamentos (O "Hello World" Geral e Embarcado)

* **Objetivo:** Sair sabendo ler um sensor e acender um LED *sem travar o foguete* (lógica não-bloqueante).
* **Tópicos (Geral):**
    * Compilador vs. Interpretador (Conceito de 2 minutos).
    * Estrutura básica (`main` vs. `setup/loop`, `cout` vs. `Serial.println`).
    * Tipos Primitivos (`int`, `float`, `bool`).
    * Funções (como criar e chamar).
* **Tópicos (Arduino):**
    * Setup da IDE e `Serial.println()` (A "ferramenta de depuração").
    * I/O Digital (`pinMode`, `digitalWrite/Read`).
    * I/O Analógico (`analogRead`, Conceito de ADC).
    * PWM (`analogWrite`, Conceito de Duty Cycle).
    * **O Inimigo:** `delay()`.
    * **A Solução:** `millis()`.
* **💡 Atividade Prática (Em Aula):**
    * O "Dimmer com LED piscante".
* **🛠️ Ferramenta de Aula (Tinkercad):**
    * **Uso: ✅ Perfeito.**
    * **Por quê:** O Tinkercad simula perfeitamente a *lógica* desta aula. Os trainees podem:
        1.  Montar o circuito virtual (LED, potenciômetro).
        2.  Ver o LED piscar com `millis()`.
        3.  Ver o brilho do LED mudar com o potenciômetro.
        4.  Usar o `Serial Monitor` do Tinkercad para depurar e ver os valores.

---

### 📚 PDF 1: Guia de Setup, Compilação e Git

Este PDF é o "guia de sobrevivência" do desenvolvedor. Ele cobre como configurar o ambiente fora do Arduino e como usar ferramentas essenciais.

**1. 🚀 Setup do Ambiente de Desenvolvimento (Fora do Arduino)**
* **Instalando Compiladores:**
    * **Windows:** Guia para instalar o `gcc`/`g++` (via MinGW ou MSYS2).
    * **Linux/macOS:** Como verificar se o `gcc` e `git` já estão instalados.
* **Configurando o VSCode:**
    * Instalando o editor.
    * Extensões essenciais (C/C++, GitLens).
* **Instalando o Git:**
    * Como baixar e instalar.
    * Configuração inicial (`git config --global user.name ...`).

**2. ⚙️ Compilação Manual (O "Por Trás dos Panos")**
* **O que o Compilador Faz:** As 4 etapas (Pré-processamento, Compilação, Montagem, Linkagem).
* **Compilando com `gcc`/`g++`:**
    * Compilando um arquivo único: `g++ main.cpp -o meu_programa`.
    * Compilando múltiplos arquivos: `g++ main.cpp utils.cpp -o meu_programa`.
* **Flags Essenciais:**
    * `-o`: Nomeia o arquivo de saída.
    * `-c`: Compila, mas não "linka" (gera um arquivo `.o`).
    * `-I`: (`-I /caminho/include`) Adiciona um diretório de *headers*.
    * `-L`: (`-L /caminho/lib`) Adiciona um diretório de *bibliotecas*.
    * `-l`: (`-l nome_lib`) "Linka" uma biblioteca.

**3. 🌿 Comandos Essenciais do Git**
* **Conceitos:** Repositório, Commit, Branch, Pull/Push.
* **Cheat Sheet de Comandos:**
    * `git clone [url]`
    * `git branch [nome-branch]`
    * `git checkout [nome-branch]`
    * `git add [arquivo]`
    * `git commit -m "Minha mensagem"`
    * `git push`
    * `git pull`

**4. 📦 Tópicos Extras de C++ Básico**
* **Argumentos da Main:** O que são `int argc` e `char* argv[]`.
* **Namespaces:** O que `using namespace std;` realmente faz e por que pode ser ruim.
* **Enums:** Como usar `enum` para criar constantes nomeadas.
* **Unions:** O que são e como diferem de `structs`.
* **Funções Lambda:** O que é a sintaxe `[](){}` (conceito básico).

---