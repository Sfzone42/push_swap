    ██████  ██    ██ ███████ ██   ██         ███████ ██     ██  █████  ██████  
    ██   ██ ██    ██ ██      ██   ██         ██      ██     ██ ██   ██ ██   ██ 
    ██████  ██    ██ ███████ ███████         ███████ ██  █  ██ ███████ ██████  
    ██      ██    ██      ██ ██   ██              ██ ██ ███ ██ ██   ██ ██      
    ██       ██████  ███████ ██   ██ ███████ ███████  ███ ███  ██   ██ ██      
                                                                        

# push_swap

**push_swap** é um projeto desenvolvido como parte do currículo da 42. O objetivo é implementar um algoritmo eficiente para ordenar uma lista de números utilizando duas pilhas e um conjunto limitado de operações. O projeto consiste em dois programas: um que gera uma lista de instruções para ordenar os números (`push_swap`) e outro que verifica se as instruções geradas são corretas (`checker`).

## 📋 Índice

- [Visão Geral](#visão-geral)
- [Instalação](#instalação)
- [Uso](#uso)
- [Regras](#regras)
- [Operações Disponíveis](#operações-disponíveis)
- [Algoritmos de Ordenação](#algoritmos-de-ordenação)
- [Exemplos](#exemplos)
- [Licença](#licença)
- [Contato](#contato)

## 🌟 Visão Geral

O projeto **push_swap** desafia você a ordenar uma pilha de números usando o menor número possível de operações. Para isso, você deve implementar um algoritmo que utiliza duas pilhas (A e B) e uma série de operações para mover e ordenar os elementos. O objetivo final é que todos os elementos estejam ordenados na pilha A.

## 🚀 Instalação

### Pré-requisitos

- **gcc** (ou outro compilador C)
- **make**

### Passos de Instalação

1. Clone o repositório:
    ```bash
    git clone https://github.com/lhabacuc/push_swap.git
    cd push_swap
    ```

2. Compile os programas:
    ```bash
    make
    ```

Isso criará dois executáveis principais: `push_swap` e `checker`.

## 🎮 Uso

### Para ordenar uma lista de números:

1. Execute o programa `push_swap` com uma lista de números inteiros como argumento:
    ```bash
    ./push_swap 3 2 1 6 5 4
    ```

2. O programa gerará uma lista de instruções que, se aplicadas corretamente, ordenarão os números.

### Para verificar se as instruções são válidas:

1. Use o programa `checker` para verificar a validade da sequência de instruções:
    ```bash
    ./push_swap 3 2 1 6 5 4 | ./checker 3 2 1 6 5 4
    ```

Se a lista estiver ordenada corretamente após aplicar as instruções, o `checker` retornará "OK". Caso contrário, retornará "KO".

## 📏 Regras

- O objetivo é ordenar todos os elementos da pilha A.
- As operações só podem ser aplicadas a pilha A, a pilha B ou a ambas.
- Todas as operações devem ser implementadas de maneira a minimizar o número de movimentos.

## 🔄 Operações Disponíveis

- **sa**: Troca os dois primeiros elementos no topo da pilha A.
- **sb**: Troca os dois primeiros elementos no topo da pilha B.
- **ss**: Realiza `sa` e `sb` simultaneamente.
- **pa**: Move o primeiro elemento do topo da pilha B para o topo da pilha A.
- **pb**: Move o primeiro elemento do topo da pilha A para o topo da pilha B.
- **ra**: Roda todos os elementos da pilha A para cima.
- **rb**: Roda todos os elementos da pilha B para cima.
- **rr**: Realiza `ra` e `rb` simultaneamente.
- **rra**: Roda todos os elementos da pilha A para baixo.
- **rrb**: Roda todos os elementos da pilha B para baixo.
- **rrr**: Realiza `rra` e `rrb` simultaneamente.

## 🔢 Algoritmos de Ordenação

Para resolver o problema, diferentes algoritmos de ordenação podem ser implementados, como:

- **Ordenação por Inserção**
- **Quicksort Adaptado**
- **Radix Sort**

O desafio é escolher o algoritmo mais eficiente em termos de número de operações, especialmente para conjuntos maiores de números.

## 🖼️ Exemplos

### Exemplo 1
```bash
./push_swap 4 67 3 87 23
```
Saída:
```
pb
pb
ra
pb
sa
pa
pa
pa
```

### Exemplo 2
```bash
./push_swap 3 2 1
```
Saída:
```
sa
rra
```


## 📄 Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.

## 📞 Contato

- **GitHub**: [lhabacuc](https://github.com/lhabacuc)
- **Email**: liedsonnhabacuc@gmail.com
