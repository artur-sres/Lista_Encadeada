# Lista Simplesmente Encadeada em C  

Este projeto implementa uma **lista simplesmente encadeada**, permitindo realizar operações básicas como adicionar, remover, editar e exibir elementos. O código foi desenvolvido para consolidar conceitos de Estruturas de Dados, com foco no uso de ponteiros e gerenciamento dinâmico de memória em C.  

## Funcionalidades  

- **Adicionar elementos**:  
  - No início da lista  
  - No final da lista  
  - Em uma posição específica  

- **Remover elementos**:  
  - Do início da lista  
  - De uma posição específica  

- **Editar elementos**:  
  - Modificar o valor armazenado em uma posição específica  

- **Imprimir elementos**:  
  - Exibir todos os valores da lista com suas respectivas posições  

## Estrutura do Código  

- **Estrutura de Nó (NO):**  
  Cada nó contém:  
  - Um valor inteiro (`valor`)  
  - Sua posição na lista (`posicao`)  
  - Um ponteiro para o próximo nó (`prox`)  

- **Funções Implementadas:**  
  - `void add(int valor, int posicao);`  
    Adiciona um elemento à lista em uma posição válida.  
  - `void remover(int posicao);`  
    Remove um elemento de uma posição específica.  
  - `void editar(int posicao, int valor);`  
    Atualiza o valor de um elemento em uma posição específica.  
  - `void imprimir();`  
    Exibe todos os elementos da lista.  
