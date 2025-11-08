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

Claro, aqui está a continuação do guia com as seções sobre a IDE do Arduino.

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
    Execute o instalador que você baixou. Siga as instruções na tela. Durante a instalação (principalmente no Windows), ele pode perguntar se você deseja instalar "drivers" ou "portas seriais (COM)". **Aceite e instale todos** eles, pois são essenciais para que o computador possa se comunicar com as placas.

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
        https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
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


