## 📖 Sumário

* [**1. Instalando Compiladores**](#instalando-compiladores)
  * [Em Linux](#em-linux)
  * [Em Windows](#💻-em-windows)
  * [Em macOS](#em-macos)
  * [Verificando a Instalação](#verificando-a-instalação)
  * [Opcional: Verificando/Instalando o GDB (Debugger)](#opcional-verificandoinstalando-o-gdb-debugger)

* [**2. VSCode e Arduino IDE**](#vscode-e-arduino-ide)
  * [Instalando VSCode](#instalando-vscode)
  * [Setando VSCode](#setando-vscode)
  * [Instalando a Arduino IDE](#⚡-instalando-a-arduino-ide)
  * [Setando a Arduino IDE](#⚙️-setando-a-arduino-ide)

* [**3. O Terminal**](#🐧-o-terminal)
  * [O que é o Terminal?](#o-que-é-o-terminal)
  * [O que ele pode fazer?](#🚀-o-que-ele-pode-fazer)
  * [Como Abrir o Terminal](#🚪-como-abrir-o-terminal)
  * [Comandos Essenciais (Foco no CMD)](#⌨️-comandos-essenciais-foco-no-cmd)
  * [Dica Rápida: Autocompletar](#⭐-dica-rápida-autocompletar)
  * [Exemplos Práticos no Windows (CMD)](#💻-exemplos-práticos-no-windows-cmd)

* [**4. Git e Controle de Versão**](#🐙-git-e-controle-de-versão)
  * [O que é Git?](#o-que-é-git)
  * [Instalando o Git](#instalando-o-git)
  * [Os Comandos Essenciais para Iniciar](#⚙️-os-comandos-essenciais-para-iniciar)
  * [Tabela Rápida: Resumo dos Comandos](#📝-tabela-rápida-resumo-dos-comandos)

---

# Instalando Compiladores
Os compiladores C/C++ que iremos utilizar são o `gcc` (para C) e o `g++` (para C++) da GNU. Esse conjunto de compiladores pode ser baixado seguindo as seguintes instruções:
...A instalação varia significativamente dependendo do seu sistema operacional.

---

## Em Linux

Na maioria das distribuições Linux, as ferramentas de compilação C e C++ são agrupadas.

* **Para distribuições baseadas em Debian (Ubuntu, Linux Mint, etc.):**
    Abra o terminal e execute:
    ```bash
    sudo apt update
    sudo apt install build-essential
    ```
    O pacote `build-essential` instala o **GCC** (C), **G++** (C++), `make` e outras bibliotecas e ferramentas essenciais para compilação.

* **Para distribuições baseadas em Red Hat (Fedora, CentOS, RHEL):**
    Abra o terminal e execute:
    ```bash
    sudo dnf install gcc gcc-c++
    ```
    (Em versões mais antigas, pode ser `yum install gcc gcc-c++`). Nesses sistemas, muitas vezes é necessário pedir o `gcc-c++` explicitamente.

* **Para distribuições baseadas em Arch (Manjaro, Arch Linux):**
    Abra o terminal e execute:
    ```bash
    sudo pacman -S gcc
    ```
    O pacote `gcc` no Arch já inclui o **G++** (C++) e outras ferramentas do conjunto GNU.

---

## 💻 Em Windows

O Windows não possui GCC/G++ nativamente. A maneira recomendada é usar o **MSYS2**.

* **MinGW-w64 (via MSYS2):** O MSYS2 fornece um ambiente que facilita a instalação e atualização dos compiladores MinGW (uma versão do GCC/G++ para Windows).

### 1. Baixar e Instalar o MSYS2

1.  Vá para o site oficial: [https://www.msys2.org/](https://www.msys2.org/)
2.  Baixe e execute o instalador (`.exe`).
3.  Siga os passos, mantendo o local de instalação padrão (geralmente `C:\msys64`).

### 2. Atualizar o Ambiente MSYS2

1.  Abra o "**MSYS2 MSYS**" pelo Menu Iniciar.
2.  Digite o seguinte comando para atualizar o sistema base:
    ```bash
    pacman -Syu
    ```
3.  **Importante:** O terminal pode fechar sozinho. Se isso acontecer, abra-o novamente e execute o mesmo comando **mais uma vez** para garantir que tudo foi atualizado:
    ```bash
    pacman -Syu
    ```

### 3. Instalar os Compiladores (Toolchain)

1.  Agora, instale o conjunto de ferramentas (toolchain) completo. A opção recomendada é a **UCRT64**. Este comando instala **ambos `gcc` e `g++`**, além de `make`, `gdb` (debugger) e outras ferramentas.
    ```bash
    pacman -S mingw-w64-ucrt-x86_64-gcc
    ```
2.  O `pacman` perguntará quais pacotes do grupo você deseja. Você pode simplesmente pressionar **Enter** para selecionar a opção padrão (instalar todos).
3.  Confirme a instalação digitando **Y** (ou **S**) e pressionando Enter.

### 4. Adicionar ao PATH do Windows (Crucial!)

Isso permite que o Windows encontre `gcc.exe` e `g++.exe` de qualquer terminal.

1.  O caminho que você precisa adicionar é: `C:\msys64\ucrt64\bin`
    *(Ajuste se você instalou o MSYS2 em outro lugar.)*
2.  **Como adicionar ao PATH:**
    * Pressione a tecla Windows e digite "variáveis de ambiente".
    * Clique em "Editar as variáveis de ambiente do sistema".
    * Clique em "Variáveis de Ambiente...".
    * Na seção "Variáveis do sistema", selecione **Path** e clique em "Editar...".
    * Clique em "Novo" e cole o caminho: `C:\msys64\ucrt64\bin`
    * Clique "OK" em todas as janelas.

* **WSL (Windows Subsystem for Linux):**
    Como alternativa, você pode habilitar o WSL, instalar uma distribuição Linux (como o Ubuntu) e seguir as instruções da seção Linux, dentro do terminal do WSL.

---
## Em macOS

O macOS usa o **Clang** como seu compilador padrão, que é fornecido pela Apple e é altamente compatível com o GCC/G++.

* **Xcode Command Line Tools (Recomendado):**
    Esta é a forma mais fácil de obter compiladores C e C++ no macOS.
    1.  Abra o Terminal.
    2.  Digite o comando:
        ```bash
        xcode-select --install
        ```
    3.  Siga as instruções na tela.
    *Observação: Isso instalará o **Clang** (compilador C) e o **Clang++** (compilador C++). O macOS também cria "aliases" (atalhos) para que os comandos `gcc` e `g++` funcionem, mas eles apontarão para o Clang.*

* **Homebrew (Para o GCC/G++ real da GNU):**
    Se você precisar especificamente da versão da GNU (e não do Clang):
    1.  Instale o Homebrew (se ainda não o tiver) do [site oficial](https://brew.sh/index_pt-br).
    2.  Instale o GCC (isso inclui C e C++):
        ```bash
        brew install gcc
        ```

---

## Verificando a Instalação

Após seguir os passos, **abra um novo terminal** e verifique ambos os compiladores:

Verifique o compilador C:
```bash
gcc --version
```

Verifique o compilador C++:

```bash
g++ --version
```

-----

## Opcional: Verificando/Instalando o GDB (Debugger)

O **GDB (GNU Debugger)** é uma ferramenta essencial para depurar seu código (encontrar e corrigir erros).

> [\!NOTE]
> Na maioria dos casos, os pacotes que instalam o `gcc`/`g++` (como `build-essential` ou o toolchain do MSYS2) **já incluem o GDB**.

**1. Verifique se o GDB está instalado:**
Abra um novo terminal e digite:

```bash
gdb --version
```

**2. Se não estiver instalado (comando não encontrado):**

  * **Debian/Ubuntu:**
    ```bash
    sudo apt install gdb
    ```
  * **Red Hat/Fedora:**
    ```bash
    sudo dnf install gdb
    ```
  * **Arch/Manjaro:**
    ```bash
    sudo pacman -S gdb
    ```
  * **Windows (MSYS2 - UCRT):** O `gdb` já deve ter sido instalado com o toolchain `mingw-w64-ucrt-x86_64-gcc`. Se por algum motivo ele não estiver, ou se você o removeu acidentalmente, pode instalá-lo separadamente com:
    ```bash
    pacman -S mingw-w64-ucrt-x86_64-gdb
    ```
  * **macOS (Xcode):** O Xcode **não** usa o GDB, ele usa o **LLDB**. A extensão C/C++ do VSCode também suporta o LLDB perfeitamente. O comando `gdb` no macOS (com Xcode) geralmente é um alias para o `lldb`.
  * **macOS (Homebrew):** Se você instalou o GCC via Homebrew e quer o GDB da GNU:
    ```bash
    brew install gdb
    ```

-----

# VSCode e Arduino IDE

## Instalando VSCode

1.  **Acesse o site oficial:** [https://code.visualstudio.com/](https://code.visualstudio.com/)
2.  **Baixe o instalador** para o seu sistema operacional.
3.  **Execute o instalador** e siga as instruções.
      * **Recomendação (Principalmente no Windows):** Durante a instalação, certifique-se de marcar as opções "Adicionar 'Abrir com o Code'..." (para pastas e arquivos) e, o mais importante, **"Adicionar ao PATH"**. Isso permitirá que você abra o VSCode facilmente pelo terminal com o comando `code .`.

## Setando VSCode

Após instalar o VSCode, ele é um editor de texto genérico. Para transformá-lo em um ambiente de desenvolvimento C/C++ poderoso, precisamos instalar as extensões corretas.

### 🔌 Instalando Extensões Essenciais (C/C++)

As extensões fornecem recursos como autocompletar (IntelliSense), depuração, verificação de sintaxe e formatação de código.

1.  Abra o Visual Studio Code.
2.  Clique no ícone de **Extensões** na barra lateral esquerda (ou pressione `Ctrl+Shift+X`).
3.  Na barra de pesquisa, digite `C/C++`.
4.  Procure e instale o **C/C++ Extension Pack** (ID: `ms-vscode.cpptools-extension-pack`).

Este é o pacote oficial da Microsoft e é a melhor escolha, pois ele instala automaticamente um conjunto de ferramentas úteis, incluindo:

  * **C/C++ (ID: `ms-vscode.cpptools`):** Esta é a extensão principal. Ela fornece o IntelliSense (autocompletar inteligente), navegação de código e suporte à depuração.
  * **C/C++ Themes:** Temas de cores otimizados para código C/C++.
  * **CMake Tools:** Suporte para projetos que usam o sistema de build CMake.

### ⚙️ Verificando a Conexão com o Compilador

Com as extensões instaladas, o VSCode agora precisa "enxergar" os compiladores (`gcc` e `g++`) que você instalou anteriormente.

Felizmente, se você seguiu os passos anteriores e **adicionou o `bin` do seu compilador (seja do MSYS2, `build-essential` ou Homebrew) ao PATH do sistema**, a extensão C/C++ da Microsoft geralmente o detectará automaticamente.

Você saberá que funcionou quando abrir um arquivo `.c` ou `.cpp` e o IntelliSense (autocompletar de código) começar a funcionar corretamente.

-----

## ⚡ Instalando a Arduino IDE

A **Arduino IDE** (Ambiente de Desenvolvimento Integrado) é o software oficial da Arduino. É onde você vai escrever seu código em C/C++, compilá-lo e enviá-lo (fazer upload) para a sua placa (como Arduino, ESP32, etc.).

A versão moderna (recomendada) é a 2.0 ou superior, que é mais rápida e tem recursos modernos como autocompletar.

1.  **Acesse o site oficial:**
    Vá para a página de software da Arduino: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

2.  **Baixe o Instalador:**

      * **Windows:** Baixe o **"Windows Win 10 and newer, 64 bits"**. É um instalador (`.exe`) que cuidará de tudo para você, incluindo a instalação de drivers básicos.
      * **macOS:** Baixe o arquivo `.dmg` para o seu processador (Apple Silicon ou Intel).
      * **Linux:** Você pode baixar o `.AppImage` ou, em muitas distribuições, instalar via gerenciador de pacotes (embora o download manual garanta a versão mais recente).

3.  **Instale o Software:**
    Execute o instalador que você baixou. Siga as instructions na tela. Durante a instalação (principalmente no Windows), ele pode perguntar se você deseja instalar "drivers" ou "portas seriais (COM)". **Aceite e instale todos** eles, pois são essenciais para que o computador possa se comunicar com as placas.

-----

## ⚙️ Setando a Arduino IDE

Ao abrir a IDE pela primeira vez, ela está configurada apenas para as placas Arduino básicas (como o Uno). Para programar microcontroladores mais avançados, como o ESP32, você precisa adicionar "suporte" a eles.

### 1\. 🖥️ Instalando Suporte a Novas Placas (Ex: ESP32)

Este é o passo mais importante. Usaremos o **Gerenciador de Placas** (Boards Manager).

1.  **Adicionar a URL da Placa:**

      * Abra a Arduino IDE.
      * Vá em **File \> Preferences** (Arquivo \> Preferências).
      * Encontre o campo chamado **"Additional Boards Manager URLs"** (URLs Adicionais do Gerenciador de Placas).
      * Cole a seguinte URL lá dentro (para o ESP32):
        ```
        [https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json)
        ```
      * **Dica:** Se você já tiver outra URL lá, clique no ícone 🗒️ ao lado da caixa e adicione a nova URL em uma linha separada.
      * Clique em **OK**.

2.  **Instalar a Placa:**

      * Agora, vá para o Gerenciador de Placas clicando no ícone de Placas na barra lateral esquerda (parece uma placa de circuito 📑) ou indo em **Tools \> Board \> Boards Manager...**
      * Na barra de pesquisa, digite **`esp32`**.
      * Você verá **"esp32 by Espressif Systems"**. Clique em **Install** (Instalar).
      * A IDE baixará todas as ferramentas e exemplos para o ESP32.

### 2\. 📚 Instalando Bibliotecas (Libraries)

Bibliotecas (ou "libs") são pacotes de código prontos que facilitam tarefas complexas (ex: controlar um display, conectar ao WiFi).

  * **Método 1: Gerenciador de Bibliotecas (Recomendado)**

    1.  Clique no ícone de Livros 📚 na barra lateral esquerda (Gerenciador de Bibliotecas).
    2.  Na barra de pesquisa, digite o nome da biblioteca que você precisa (ex: **`Adafruit GFX`** ou **`Blynk`**).
    3.  Clique em **Install** (Instalar).

  * **Método 2: Instalar por .zip**

    1.  Se você baixou uma biblioteca de um site (como o GitHub) em um arquivo `.zip`.
    2.  Na IDE, vá em **Sketch \> Include Library \> Add .ZIP Library...**
    3.  Selecione o arquivo `.zip` que você baixou.

### 3\. ✅ Testando a Configuração (O "Blink")

Caso você possua o microcontrolador para testar.

1.  **Conecte sua placa** (Arduino, ESP32, etc.) ao computador com um cabo USB.
2.  **Selecione a Placa:**
      * Vá em **Tools \> Board** e procure sua placa (ex: **"Arduino Uno"** ou **"ESP32 Dev Module"**).
3.  **Selecione a Porta:**
      * Vá em **Tools \> Port**.
      * Você verá uma porta COM (no Windows, ex: `COM3`) ou `tty` (no Linux/Mac). Selecione-a. (Se você não sabe qual é, desconecte a placa, veja quais portas sumiram, e conecte-a novamente).
4.  **Abra o Exemplo:**
      * Vá em **File \> Examples \> 01.Basics \> Blink**.
5.  **Faça o Upload:**
      * Clique no ícone de **seta para a direita (→)** na parte superior para compilar e enviar o código para a placa.
      * Você verá a barra de progresso. Se tudo der certo, o LED "L" na sua placa começará a piscar\!

-----

# 🐧 O Terminal

## O que é o Terminal?

O terminal (ou "linha de comando") é uma interface baseada em texto para interagir com o seu computador.

Pense assim:

  * A **Interface Gráfica (GUI)** é como você usa o computador com um mouse (clicando em ícones, pastas e botões).
  * A **Interface de Linha de Comando (CLI)**, que é o terminal, é como você usa o computador digitando comandos.

É uma ferramenta poderosa, direta e essencial para programadores, pois muitas ferramentas de desenvolvimento (como compiladores, Git e servidores) são feitas para serem executadas por comandos.

No Windows, o terminal mais tradicional é o **Prompt de Comando (CMD)**. Você também tem o **PowerShell** (mais moderno e poderoso) e, em sistemas Linux/macOS, é comum usar o **Bash** ou **Zsh**.

## 🚀 O que ele pode fazer?

Quase tudo que você faz com o mouse, e muito mais\! De forma breve, você pode:

  * **Navegar** entre pastas.
  * **Gerenciar arquivos** (criar, copiar, mover, renomear e deletar).
  * **Executar programas** (como o compilador `gcc` ou `g++` que acabamos de instalar).
  * **Gerenciar processos** do sistema e redes.
  * **Automatizar tarefas** através de *scripts* (arquivos `.bat` no CMD).

-----

### 🚪 Como Abrir o Terminal

A forma de acessar o terminal varia um pouco entre os sistemas:

  * **No Windows:**

    1.  Pressione a **Tecla Windows + R** para abrir a caixa "Executar".
    2.  Digite `cmd` e pressione Enter (para o Prompt de Comando clássico).
    3.  Ou digite `powershell` e pressione Enter (para o terminal mais moderno).

    <!-- end list -->

      * (Você também pode encontrá-los pesquisando no Menu Iniciar).

  * **No macOS:**

    1.  Pressione **Cmd + Espaço** para abrir o Spotlight.
    2.  Digite `Terminal` e pressione Enter.

    <!-- end list -->

      * (Ele também fica na pasta "Utilitários" dentro de "Aplicativos").

  * **No Linux (Ubuntu/Fedora/etc.):**

    1.  O atalho mais comum é **Ctrl + Alt + T**.
    2.  Ou procure por "Terminal" no menu de aplicativos.

-----

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

-----

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


-----

# 🐙 Git e Controle de Versão

## O que é Git?

O **Git** é um **sistema de controle de versão**.

Pense nele como um "Salvar" superpoderoso para seu código. Em vez de criar arquivos como `main_v1.cpp`, `main_v2.cpp` ou `main_final_agora_vai.cpp`, o Git gerencia o histórico para você.

Ele permite que você salve "instantâneos" (chamados **commits**) do seu projeto. Se algo quebrar, você pode facilmente "voltar no tempo" para uma versão que funcionava.

**Por que usar?**

  * **Histórico:** Você tem um registro completo de *quem* mudou *o quê* e *por quê*.
  * **Colaboração:** É a ferramenta que permite que dezenas de pessoas trabalhem no mesmo projeto sem sobrescrever o trabalho umas das outras.
  * **Segurança:** Ao usá-lo com um serviço como **GitHub** ou **GitLab**, você tem um backup do seu código na nuvem.

-----

## Instalando o Git

Antes de usar qualquer comando, você precisa ter o Git instalado no seu computador.

### Em Windows

1.  Baixe o instalador oficial do **Git for Windows** no site:
    [https://git-scm.com/download/win](https://git-scm.com/download/win)
2.  Execute o instalador. Durante a instalação, você pode deixar as opções padrão, elas são seguras e funcionais.
3.  **Importante:** A instalação incluirá o **Git Bash**, um terminal que recomendamos usar, pois ele entende tanto os comandos Git quanto os comandos Linux (como `ls`, `cd`, `rm`).

### Em macOS

A forma mais fácil é instalar as Ferramentas de Linha de Comando do Xcode, que já incluem o Git.

1.  Abra o Terminal (em `Aplicativos/Utilitários`).
2.  Digite o comando:
    ```bash
    xcode-select --install
    ```

<!-- end list -->

  * Como alternativa, se você usa o [Homebrew](https://brew.sh/), você pode simplesmente rodar:
    ```bash
    brew install git
    ```

### Em Linux (Debian/Ubuntu)

Abra seu terminal e use o gerenciador de pacotes:

```bash
sudo apt update
sudo apt install git
```

### Verificando a Instalação

Após instalar, abra um **novo** terminal e digite:

```bash
git --version
```

Se o terminal responder com um número de versão (ex: `git version 2.40.1`), significa que o Git foi instalado com sucesso.

-----

## ⚙️ Os Comandos Essenciais para Iniciar

Vamos ver o fluxo de trabalho mais básico.

### 1\. Configuração Inicial (Faça isso só uma vez)

Antes de tudo, você precisa dizer ao Git quem você é. Isso será usado para assinar todos os "saves" (commits) que você fizer.

Abra seu terminal e digite:

```bash
# Configura seu nome de usuário
git config --global user.name "Seu Nome"

# Configura seu e-mail (o mesmo que você usa no GitHub/GitLab)
git config --global user.email "seu@email.com"
```

### 2\. Iniciando um Repositório (Duas Formas)

Você pode começar um projeto de duas maneiras: criando um novo do zero ou copiando um existente.

#### Opção A: Começar um projeto novo (`git init`)

Se você já tem uma pasta de projeto (ex: `C:\Projetos\MeuApp`) e quer começar a rastreá-la com o Git:

```bash
# Navegue até a pasta do seu projeto
cd C:\Projetos\MeuApp

# Diga ao Git para começar a rastrear esta pasta
git init
```

Isso criará uma subpasta oculta chamada `.git` que guardará todo o histórico.

#### Opção B: Copiar um projeto existente (`git clone`)

Se o projeto já existe (ex: no GitHub), você pode cloná-lo (baixar uma cópia).

```bash
# Vá para a pasta onde você guarda seus projetos
cd C:\Projetos

# Clone o projeto (a URL você pega no site do GitHub/GitLab)
git clone [https://github.com/usuario/nome-do-projeto.git](https://github.com/usuario/nome-do-projeto.git)

# Isso já cria a pasta "nome-do-projeto" para você
cd nome-do-projeto
```

### 3\. O Fluxo de Trabalho Básico (O loop diário)

Este é o ciclo que você fará dezenas de vezes por dia. O Git tem **três "áreas"**:

1.  **Working Directory:** A sua pasta, onde você edita os arquivos.
2.  **Staging Area (Área de Preparação):** Onde você coloca os arquivos que *quer* salvar no próximo commit.
3.  **Repository (Histórico):** Onde os "snapshots" salvos (commits) ficam guardados.

O fluxo é sempre: **Modificar -\> Adicionar (Stage) -\> Commitar (Salvar)**.

#### Passo 1: `git status`

Sempre comece com este comando. Ele é seu melhor amigo e lhe diz o que está acontecendo.

```bash
# Mostra quais arquivos foram modificados, quais estão na Staging Area, etc.
git status
```

  * Arquivos em **vermelho** (`Untracked` ou `Modified`) estão no seu Working Directory.
  * Arquivos em **verde** (`Staged`) estão na Staging Area, prontos para o commit.

#### Passo 2: `git add`

Quando você terminar de editar um arquivo e estiver pronto para salvá-lo no histórico, você o move para a Staging Area.

```bash
# Adiciona um arquivo específico
git add main.cpp

# OU (mais comum)
# Adiciona TODOS os arquivos modificados na pasta atual
git add .
```

> Se você rodar `git status` de novo, verá que os arquivos agora estão em verde.

#### Passo 3: `git commit`

Agora que os arquivos estão preparados, você "tira a foto" e salva o snapshot no histórico.

```bash
# O -m significa "message" (mensagem)
git commit -m "O que eu fiz neste commit (ex: Adicionei a função main)"
```

> **Boas práticas:** Suas mensagens de commit devem ser curtas e claras. Elas explicam *o que* você mudou.

### 4\. Sincronizando com a Nuvem (GitHub/GitLab)

Até agora, seus commits (saves) estão **apenas no seu computador local**. Para colaborar ou fazer backup, você envia (push) seus commits para um servidor remoto (como o GitHub).

#### Passo 1: `git remote` (Só precisa fazer uma vez por projeto)

Se você usou `git init`, você precisa "conectar" seu repositório local a um repositório na nuvem.

```bash
# Crie um repositório vazio no GitHub primeiro
# O GitHub lhe dará esta URL. 'origin' é o apelido padrão para o servidor.
git remote add origin [https://github.com/usuario/nome-do-projeto.git](https://github.com/usuario/nome-do-projeto.git)
```

*(Se você usou `git clone`, isso já foi feito para você.)*

#### Passo 2: `git push`

Isso envia seus commits locais para o servidor remoto (`origin`).

```bash
# A primeira vez que você envia, você precisa usar -u
# 'main' é o nome da branch (ramo) principal. Pode ser 'master' em projetos antigos.
git push -u origin main

# Nas próximas vezes, você pode usar apenas:
git push
```

-----

### 📝 Tabela Rápida: Resumo dos Comandos

| Comando | O que faz (em poucas palavras) |
| :--- | :--- |
| `git config` | Configura seu nome/email (só uma vez). |
| `git init` | Inicia um repositório novo na pasta atual. |
| `git clone [url]` | Baixa/copia um repositório da internet. |
| `git status` | Mostra o estado dos seus arquivos (o mais usado). |
| `git add [arquivo]` | Prepara um arquivo para o "save" (commit). |
| `git commit -m "msg"` | Salva o "snapshot" (o save) no histórico local. |
| `git push` | Envia seus commits locais para o servidor (GitHub). |
| `git pull` | Baixa as atualizações do servidor (o oposto de `push`). |

```
```