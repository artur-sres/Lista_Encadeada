//Lista encadeada
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//Criacao do tipo de variavel NO
typedef struct NO{
    int valor;
    int posicao;
    struct NO* prox;
}NO;

//Criacao da variavel de inicio para acessar o primeiro termo da lista e tamanho da lista
NO* inicio=NULL;
int tamanho=0;

//Funcao para adicionar
void add(int valor, int posicao){ 
    //Verificar se a posicao é válida
    if((posicao>=0)&&(posicao<=tamanho)){
        //Criaçao da variável temporaria "novo" para guardar os parametros da função na memoria com "malloc"
        NO* novo=malloc(sizeof(NO));
        novo->valor=valor;
        novo->posicao=posicao;

        //Casos de insercao:        
        if(inicio==NULL){ 
            //Caso a lista esteja vazia
            inicio = novo;
            tamanho++;
        
        }else if(posicao==0){
            //Caso a lista nao esteja vazia e eu quero add no inicio
            novo->prox=inicio;
            inicio=novo;
            tamanho++;

        }else if(posicao==tamanho){
            //Caso a lista nao esteja vazia e eu quero add no fim
            NO* aux=inicio;
            for(int i=0;i<tamanho-1;i++){
                aux=aux->prox;
            }
            aux->prox=novo;
            tamanho++;
        
        }else{
            //Caso a lista nao esteja vazia e eu quero add em outra posicao
            NO* aux1=inicio;
            for(int i=0;i!=posicao-1;i++){
                aux1=aux1->prox;
            }
            NO* aux2=aux1->prox;
            aux1->prox=novo;
            novo->prox=aux2;
            tamanho++;
        }
    }
}

//Funcao para remover
void remover(int posicao){
    if(posicao>=0&&posicao<tamanho){
        if(posicao==0){
            NO* aux=inicio;
            inicio=aux->prox;
            free(aux);
        }else{
            NO* aux1=inicio;
            for(int i=0;i!=posicao-1;i++){
                aux1=aux1->prox;
            }
            NO* aux2=aux1->prox;
            aux1->prox=aux2->prox;
            free(aux2);
        }
    }else{
        printf("Insercao incorreta. Posicao invalida!\n");
    }
}

//Funcao para editar
void editar(int posicao, int valor){
    if(posicao>=0&&posicao<tamanho){
        NO* aux=inicio;
        for(int i=0;i!=posicao;i++){
            aux=aux->prox;
        }
        aux->valor=valor;
    }else{
        printf("Insercao incorreta. Posicao invalida!\n");
    }
}

//Funcao para imprimir
void imprimir(){
    if(tamanho>0){
    }
    printf("========== Valores do NO ==========\n");
        NO* aux=inicio;
        for(int i=0;i!=tamanho;i++){
            printf("O valor do NO na posicao %i: %i\n", i, aux->valor);
            aux=aux->prox;
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    add(1,0);
    add(2,1);
    add(3,2);
    add(4,3);
    imprimir();
    editar(1,4);
    imprimir();
    return 0;
}