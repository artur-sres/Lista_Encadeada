//Lista encadeada
#include<stdio.h>
#include<stdlib.h>

//Criacao do tipo de variavel NO
typedef struct NO{
    int valor;
    struct NO* prox;
}NO;

//Criacao da variavel de inicio, tamanho
NO* inicio=NULL;
int tamanho=0;

//Funcao para adicionar
void add(int valor, int posicao){ 
    if((posicao>=0)&&(posicao<=tamanho)){
        NO* novo=malloc(sizeof(NO));
        novo->valor=valor;
        novo->prox=NULL;

        //Casos de insercao:        
        if(inicio==NULL){ 
            //lista vazia
            inicio = novo;
        
        }else if(posicao==0){
            //lista nao vazia e eu quero adicionar no inicio
            novo->prox=inicio;
            inicio=novo;

        }else if(posicao==tamanho){
            //lista nao vazia e eu quero adicionar no final
            NO* aux=inicio;
            for(int i=0;i<tamanho-1;i++){
                aux=aux->prox;
            }
            aux->prox=novo;
        
        }else{
            //lista nao vazia e eu quero adicionar em outra posicao
            NO* aux1=inicio;
            for(int i=0;i!=posicao-1;i++){
                aux1=aux1->prox;
            }
            NO* aux2=aux1->prox;
            aux1->prox=novo;
            novo->prox=aux2;    
        }
    tamanho++;
    }else{
        printf("Insercao incorreta. Posicao invalida!\n");
    }
}

//Funcao para remover
void remover(int posicao){
    if(posicao>=0&&posicao<tamanho){
        NO* lixo=NULL;
        
        //Casos de remocao:
        if(posicao==0){
            //remover do inicio
            lixo=inicio;
            inicio=lixo->prox;
            
        }else{
            //remover de outra posicao
            NO* aux1=inicio;
            for(int i=0;i<posicao-1;i++){
                aux1=aux1->prox;
            }
            lixo=aux1->prox;
            aux1->prox=lixo->prox;
        }        
        free(lixo);
        tamanho--;
    }else{
        printf("Remocao incorreta. Posicao invalida!\n");
    }
}

//Funcao para editar
void editar(int posicao, int valor){
    if(posicao>=0&&posicao<tamanho){
        NO* aux=inicio;
        for(int i=0;i<posicao;i++){
            aux=aux->prox;
        }
        aux->valor=valor;
    }else{
        printf("Edicao incorreta. Posicao invalida!\n");
    }
}

//Funcao para imprimir
void imprimir(){
    if(tamanho>0){
        printf("========== Valores do NO ==========\n");
        NO* aux=inicio;
        int i=0;
        while(aux!=NULL){
            printf("O valor do NO na posicao %i: %i\n", i, aux->valor);
            aux=aux->prox;
            i++;
        }
    }else{
        printf("Nao foi possivel imprimir, lista vazia!\n");
    }
}

//Funcao principal
int main(){
    return 0;
}
