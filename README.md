# UFG - Disciplinas de Programação

Este repositório reúne os códigos, exercícios e implementações desenvolvidos durante a graduação na **Universidade Federal de Goiás (UFG)**. O foco principal deste acervo são as disciplinas de base da Ciência da Computação, desenvolvidas em **C**.

## 📂 Estrutura do Repositório

O repositório está dividido em dois diretórios principais, cada um correspondendo a uma matéria específica:

### 1. IP (Introdução à Programação)
Aqui estão consolidados os fundamentos da lógica de programação e da sintaxe da linguagem C. Os códigos evoluem de conceitos básicos até manipulação de estruturas multidimensionais.

* **Fundamentos:** Entrada/Saída e operações aritméticas (`A*.c`).
* **Controle de Fluxo:** Estruturas condicionais (`if/else`, `switch`) (`B*.c`).
* **Repetição:** Laços (`for`, `while`) e acumuladores (`C*.c`).
* **Modularização:** Criação e uso de funções (`D*.c`).
* **Vetores (Arrays):** Manipulação de dados lineares e ordenação simples (`E*.c`).
* **Matrizes:** Operações em arrays multidimensionais, como multiplicação de matrizes e transposição (`F*.c`).

### 2. AED1 (Algoritmos e Estruturas de Dados 1)
Esta pasta contém implementações mais avançadas, focadas em eficiência algorítmica, gerenciamento de memória e estruturas de dados clássicas. Os códigos estão organizados por origem (ex: *Boca*, *Turring*).

* **Alocação Dinâmica:** Uso de `malloc`, `free` e ponteiros.
* **Estruturas de Dados Lineares:**
    * Listas Encadeadas e Duplamente Encadeadas.
    * Pilhas (Stacks) e Filas (Queues).
* **Algoritmos de Ordenação e Busca:**
    * Binary Search.
    * Métodos de ordenação (ex: Bitonic Sort, Bubble Sort).
* **Recursividade:** Soluções para problemas complexos como o **N-Queens** e labirintos.
* **Matemática e Otimização:** Manipulação de matrizes esparsas, tabelas hash e aritmética de ponteiros.

## 🚀 Como Executar

Como os arquivos são escritos em C, você precisará de um compilador como o `gcc`.

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/seu-usuario/UFG.git](https://github.com/seu-usuario/UFG.git)
   cd UFG
````

2.  **Para compilar um arquivo específico:**

    ```bash
    gcc Materias/IP/nome_do_arquivo.c -o saida
    # Ou, se usar a biblioteca math.h:
    gcc Materias/AED1/Boca/nome_do_arquivo.c -o saida -lm
    ```

3.  **Para executar:**

    ```bash
    ./saida
    ```

## 🛠️ Tecnologias Utilizadas

  * **Linguagem:** C 
  * **Compilador:** GCC
  * **Ferramentas:** VS Code
