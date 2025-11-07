
# Instalando VSCode

1.  **Acesse o site oficial:** [https://code.visualstudio.com/](https://code.visualstudio.com/)
2.  **Baixe o instalador** para o seu sistema operacional.
3.  **Execute o instalador** e siga as instruções.
    * **Recomendação (Principalmente no Windows):** Durante a instalação, certifique-se de marcar as opções "Adicionar 'Abrir com o Code'..." (para pastas e arquivos) e, o mais importante, **"Adicionar ao PATH"**. Isso permitirá que você abra o VSCode facilmente pelo terminal com o comando `code .`.

# Setando VSCode

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