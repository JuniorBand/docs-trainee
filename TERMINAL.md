# Terminal

## 📖 Sumário

* [**3. O Terminal**](#🐧-o-terminal)
  * [O que é o Terminal?](#o-que-é-o-terminal)
  * [O que ele pode fazer?](#🚀-o-que-ele-pode-fazer)
  * [Como Abrir o Terminal](#🚪-como-abrir-o-terminal)
  * [Comandos Essenciais (Foco no CMD)](#⌨️-comandos-essenciais-foco-no-cmd)
  * [Dica Rápida: Autocompletar](#⭐-dica-rápida-autocompletar)
  * [Exemplos Práticos no Windows (CMD)](#💻-exemplos-práticos-no-windows-cmd)

---

## 🐧 O que é o Terminal?

O terminal (ou "linha de comando") é uma interface baseada em texto para interagir com o seu computador.

Pense assim:
* A **Interface Gráfica (GUI)** é como você usa o computador com um mouse (clicando em ícones, pastas e botões).
* A **Interface de Linha de Comando (CLI)**, que é o terminal, é como você usa o computador digitando comandos.

É uma ferramenta poderosa, direta e essencial para programadores, pois muitas ferramentas de desenvolvimento (como compiladores, Git e servidores) são feitas para serem executadas por comandos.

No Windows, o terminal mais tradicional é o **Prompt de Comando (CMD)**. Você também tem o **PowerShell** (mais moderno e poderoso) e, em sistemas Linux/macOS, é comum usar o **Bash** ou **Zsh**.

## 🚀 O que ele pode fazer?

Quase tudo que você faz com o mouse, e muito mais! De forma breve, você pode:

* **Navegar** entre pastas.
* **Gerenciar arquivos** (criar, copiar, mover, renomear e deletar).
* **Executar programas** (como o compilador `gcc` ou `g++` que acabamos de instalar).
* **Gerenciar processos** do sistema e redes.
* **Automatizar tarefas** através de *scripts* (arquivos `.bat` no CMD).

---

### 🚪 Como Abrir o Terminal

A forma de acessar o terminal varia um pouco entre os sistemas:

* **No Windows:**
    1.  Pressione a **Tecla Windows + R** para abrir a caixa "Executar".
    2.  Digite `cmd` e pressione Enter (para o Prompt de Comando clássico).
    3.  Ou digite `powershell` e pressione Enter (para o terminal mais moderno).
    * (Você também pode encontrá-los pesquisando no Menu Iniciar).

* **No macOS:**
    1.  Pressione **Cmd + Espaço** para abrir o Spotlight.
    2.  Digite `Terminal` e pressione Enter.
    * (Ele também fica na pasta "Utilitários" dentro de "Aplicativos").

* **No Linux (Ubuntu/Fedora/etc.):**
    1.  O atalho mais comum é **Ctrl + Alt + T**.
    2.  Ou procure por "Terminal" no menu de aplicativos.

---

## ⌨️ Comandos Essenciais (Foco no CMD)

Para um programador C/C++, os comandos mais importantes são para navegar até a pasta do seu projeto e executar o compilador.

Aqui está uma tabela com os comandos essenciais do **CMD (Windows)** e seus equivalentes em **Bash (Linux/macOS)**, que você usará no WSL ou na maioria dos servidores.

| Ação | Comando CMD (Windows) | Comando Bash (Linux/macOS) |
| :--- | :--- | :--- |
| **Listar arquivos e pastas** | `dir` | `ls` |
| **Mudar de pasta** | `cd MeuProjeto` | `cd MeuProjeto` |
| **Voltar uma pasta** | `cd ..` | `cd ..` |
| **Ir para a raiz (Disco C:)** | `cd C:\` | `cd /` |
| **Limpar a tela** | `cls` | `clear` |
| **Criar uma nova pasta** | `mkdir NovoProjeto` | `mkdir NovoProjeto` |
| **Remover uma pasta vazia** | `rmdir PastaVazia` | `rmdir PastaVazia` |
| **Copiar um arquivo** | `copy arquivo.txt destino\` | `cp arquivo.txt destino/` |
| **Mover/Renomear** | `move antigo.txt novo.txt` | `mv antigo.txt novo.txt` |
| **Deletar um arquivo** | `del arquivo.txt` | `rm arquivo.txt` |
| **Ver o conteúdo de um arquivo** | `type arquivo.txt` | `cat arquivo.txt` |
| **Executar um programa** | `meu_programa.exe` | `./meu_programa` |
| **Compilar (Exemplo)** | `g++ main.cpp -o main.exe`| `g++ main.cpp -o main` |

### Notas importantes sobre o CMD:

* **Navegação entre Discos:** Se você está no `C:\` e quer ir para o disco `D:\`, o comando `cd D:\` **não** funciona. Você deve apenas digitar o nome do disco:
    ```cmd
    D:
    ```
* **Barras:** O Windows usa a barra invertida (`\`) para caminhos (ex: `C:\Users\Admin`), enquanto Linux/macOS usam a barra normal (`/`) (ex: `/home/admin`).

---

## ⭐ Dica Rápida: Autocompletar

Este é o truque mais importante que você vai aprender:

> Pressione a tecla **TAB** para autocompletar nomes de arquivos e pastas.

Se você quer entrar na pasta `Documentos`, em vez de digitar `cd Documentos`, você pode digitar `cd Doc` e apertar **TAB**. O terminal completará o nome para você. Isso economiza muito tempo e evita erros de digitação.
## 💻 Exemplos Práticos no Windows (CMD)

### Exemplo 1: Navegar, Compilar e Executar
![alt text](compilar.gif)
### Exemplo 2: Criar um novo projeto do zero
![alt text](criar_projeto_cmd.gif)
### Exemplo 3: Renomear e Deletar arquivos (Limpeza)
![alt text](renomear_cmd.gif)
![alt text](renomear_wsl.gif)