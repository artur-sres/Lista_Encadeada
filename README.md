# Lista Simplesmente Encadeada em C  

Este projeto implementa uma **lista simplesmente encadeada**, permitindo realizar operações básicas como adicionar, remover, editar e exibir elementos. O código foi desenvolvido para consolidar conceitos de Estruturas de Dados, com foco no uso de ponteiros e gerenciamento dinâmico de memória em C.  

**Funções Implementadas:**  
  - `void add(int valor, int posicao);`  
    Adiciona um elemento à lista em uma posição válida.  
  - `void remover(int posicao);`  
    Remove um elemento de uma posição específica.  
  - `void editar(int posicao, int valor);`  
    Atualiza o valor de um elemento em uma posição específica.  
  - `void imprimir();`  
    Exibe todos os elementos da lista.

2 commit:
retirei a função locale pois ela não era útil para o objetivo, que era só entender a lógica...
otimizei algumas operaçoes(tamanho++, tamanho--) que poderiam ser resumidas.
e cobri mais alguns possiveis casos que poderiam vir a acontecer...
o proximo passo é tornala duplamente encadeada.

3 commit:
duplo encadeamento implementado por meio da adição de um ponteiro "final" apontando para o ultimo no da lista.
as demais funçoes tambem foram aprimoradas para poderem usufruir do duplo encadeamento e aumentar o desemprenho geral do codigo.
