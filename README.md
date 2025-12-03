# 🚀 Guia de Ferramentas de Aviônica

Bem-vindo ao guia de configuração de ferramentas! Clique nos links abaixo para ir para cada seção.

Obs: Cada arquivo markdown possui um pdf correspondente que pode ser baixado o diretório [Markdown/pdfs/](/Markdown/pdfs/).  

## 📖 Sumário

* [**1. Instalando Compiladores**](./Markdown/COMPILADORES.md)
  * [Em Linux](./Markdown/COMPILADORES.md#em-linux)
  * [Em Windows](./Markdown/COMPILADORES.md#💻-em-windows)
  * [Em macOS](./Markdown/COMPILADORES.md#em-macos)
  * [Verificando a Instalação](./Markdown/COMPILADORES.md#verificando-a-instalação)
  * [Opcional: GDB (Debugger)](./Markdown/COMPILADORES.md#opcional-verificandoinstalando-o-gdb-debugger)

* [**2. VSCode e Arduino IDE**](./Markdown/IDE.md)
  * [Instalando VSCode](./Markdown/IDE.md#instalando-vscode)
  * [Setando VSCode](./Markdown/IDE.md#setando-vscode)
  * [Instalando a Arduino Markdown/IDE](./Markdown/IDE.md#⚡-instalando-a-arduino-ide)
  * [Setando a Arduino Markdown/IDE](./Markdown/IDE.md#⚙️-setando-a-arduino-ide)

* [**3. O Terminal**](./Markdown/TERMINAL.md)
  * [O que é o Terminal?](./Markdown/TERMINAL.md#o-que-é-o-terminal)
  * [O que ele pode fazer?](./Markdown/TERMINAL.md#🚀-o-que-ele-pode-fazer)
  * [Como Abrir o Terminal](./Markdown/TERMINAL.md#🚪-como-abrir-o-terminal)
  * [Comandos Essenciais](./Markdown/TERMINAL.md#⌨️-comandos-essenciais-foco-no-cmd)
  * [Dica: Autocompletar](./Markdown/TERMINAL.md#⭐-dica-rápida-autocompletar)
  * [Exemplos Práticos (CMD)](./Markdown/TERMINAL.md#💻-exemplos-práticos-no-windows-cmd)

* [**4. Git e Controle de Versão**](./Markdown/GIT.md)
  * [O que é Git?](./Markdown/GIT.md#o-que-é-git)
  * [Instalando o Git](./Markdown/GIT.md#instalando-o-git)
  * [Comandos Essenciais (Pessoal)](./Markdown/GIT.md#⚙️-os-comandos-essenciais-para-iniciar)
  * [Fluxo de Trabalho em Equipe](./Markdown/GIT.md#5-o-fluxo-de-trabalho-em-equipe-o-essencial)
  * [Tabela Rápida de Comandos](./Markdown/GIT.md#📝-tabela-rápida-resumo-dos-comandos)

* [**Aula 1 (Extras): Compilação e C++ Avançado**](./Conteúdo/Aula%201/Aula%201%20(Extras).md)
  * [Compilação Manual (O que acontece?)](./Conteúdo/Aula%201/Aula%201%20(Extras).md#1-⚙️-compilação-manual-o-por-trás-dos-panos)
  * [Tópicos Extras (Namespaces, Enums, Lambda)](./Conteúdo/Aula%201/Aula%201%20(Extras).md#2-📦-tópicos-extras-de-c-básico)
  * [Conversão de Tipos (Casting)](./Conteúdo/Aula%201/Aula%201%20(Extras).md#3-conversão-de-tipos-casting)
  * [⏱️ `delay()` vs. `millis()`](./Conteúdo/Aula%201/Aula%201%20(Extras).md#4-⏱️-delay-vs-millis)
  * [📊 Diagramas de Referência](./Conteúdo/Aula%201/Aula%201%20(Extras).md#5-diagramas-e-referências)

* [**Aula 2 (Extras): Memória e Ponteiros Avançados**](./Conteúdo/Aula%202/Aula%202%20(Extras).md)
  * [🗺️ Mapa de Memória e Stack Overflow](./Conteúdo/Aula%202/Aula%202%20(Extras).md#1-🗺️-o-mapa-de-memória-detalhado)
  * [📌 Ponteiros (Aritmética e Arrays)](./Conteúdo/Aula%202/Aula%202%20(Extras).md#2-📌-ponteiros-o-mergulho-profundo)
  * [💥 O Heap (malloc, free, new)](./Conteúdo/Aula%202/Aula%202%20(Extras).md#3-💥-alocação-dinâmica-o-heap)
  * [🔄 Fragmentação e `realloc`](./Conteúdo/Aula%202/Aula%202%20(Extras).md#4-🔄-malloc-e-realloc-o-jeito-c-de-gerenciar-o-heap)
  * [⚔️ `String` vs. `char[]`](./Conteúdo/Aula%202/Aula%202%20(Extras).md#5-⚔️-o-duelo-string-vs-char-vs-char)
  * [🔄 Recursividade vs. Loops](./Conteúdo/Aula%202/Aula%202%20(Extras).md#6-recursividade-vs-loops-iteração)
  * [📊 Diagramas (Memory, Heap-Stack, Ponteiros)](./Conteúdo/Aula%202/Aula%202%20(Extras).md#7-diagramas-e-referências)

* [**Aula 3 (Extras): Estruturas de Dados & OOP Avançado**](./Conteúdo/Aula%203/Aula%203%20(Extras).md)
  * [🏗️ Estruturas de Dados (Listas, Pilhas, Filas)](./Conteúdo/Aula%203/Aula%203%20(Extras).md#1-🏗️-estruturas-de-dados-além-do-array)
  * [👉 Ponteiros de Função (Callbacks)](./Conteúdo/Aula%203/Aula%203%20(Extras).md#2-👉-ponteiros-de-função-callbacks)
  * [🏛️ OOP Avançado (Polimorfismo e Herança)](./Conteúdo/Aula%203/Aula%203%20(Extras).md#3-🏛️-oop-avançado-o-poder-da-arquitetura)
  * [📊 Diagramas e Referências](./Conteúdo/Aula%203/Aula%203%20(Extras).md#4-diagramas-e-referências)

---