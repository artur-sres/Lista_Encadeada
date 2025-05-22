//Lista encadeada
#include<stdio.h>
#include<stdlib.h>

//Criacao do tipo de variavel NO
typedef struct NO{
    int valor;
    struct NO* prox;
    struct NO* ant;
}NO;

//Criacao da variavel de inicio, final e tamanho
NO* inicio=NULL;
NO* final=NULL;
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
            final = novo;
        
        }else if(posicao==0){
            //lista nao vazia e eu quero adicionar no inicio
            novo->prox=inicio;
            novo->prox->ant=novo;
            inicio=novo;

        }else if(posicao==tamanho){
            //lista nao vazia e eu quero adicionar no final
            novo->ant=final;
            final->prox=novo;
            final=novo;
        
        }else{
            //lista nao vazia e eu quero adicionar em outra posicao
            if(posicao<(tamanho/2)){
                NO* aux = inicio;
                for(int i=0; i<posicao-1; i++){
                    aux=aux->prox;
                }
                novo->prox=aux->prox;
                novo->ant=aux;
                novo->prox->ant=novo;
                aux->prox=novo;

            }else{
                NO* aux = final;
                for(int i=tamanho-1; i>posicao-1; i--){
                    aux=aux->ant;
                }
                novo->prox=aux->prox;
                novo->ant=aux;
                novo->prox->ant=novo;
                aux->prox=novo;
            }
        }
    tamanho++;
    }else{
        printf("Insercao incorreta. Posicao invalida!\n");
    }
}

//Funcao para remover
void remover(int posicao){
    if(posicao>=0&&posicao<tamanho){
        NO* lixo;
        
        //Casos de remocao:
        if(posicao==0){
            //remover do inicio
            lixo=inicio;
            inicio=lixo->prox;
            if(inicio!=NULL){
                inicio->ant=NULL;
            }else{
                final=NULL;
            }

        }else{
            if(posicao<(tamanho/2)){
                lixo = inicio;
                for(int i=0; i<posicao; i++){
                    lixo=lixo->prox;
                }
                lixo->ant->prox=lixo->prox;
                if(lixo->prox!=NULL){
                lixo->prox->ant=lixo->ant;
                }else{
                    final=lixo->ant;
                }

            }else{
                lixo = final;
                for(int i=tamanho-1; i>posicao; i--){
                    lixo=lixo->ant;
                }     
                lixo->ant->prox=lixo->prox;
                if(lixo->prox!=NULL){
                    lixo->prox->ant=lixo->ant;
                }else{
                    final=lixo->ant;
                }
            }
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
        if(posicao<(tamanho/2)){
            NO* aux = inicio;
            for(int i=0; i<posicao; i++){
                aux=aux->prox;
            }
            aux->valor=valor;
        }else{
            NO* aux = final;
            for(int i=tamanho-1; i>posicao; i--){
                aux=aux->ant;
            }
            aux->valor=valor;
        }
    }else{
        printf("Edicao incorreta. Posicao invalida!\n");
    }
}

//Funcao para imprimir
void imprimir(char *ordem){
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