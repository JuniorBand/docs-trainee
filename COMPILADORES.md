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
---

## Opcional: Verificando/Instalando o GDB (Debugger)

O **GDB (GNU Debugger)** é uma ferramenta essencial para depurar seu código (encontrar e corrigir erros).

> [!NOTE]
Na maioria dos casos, os pacotes que instalam o `gcc`/`g++` (como `build-essential` ou o toolchain do MSYS2) **já incluem o GDB**.

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
---
