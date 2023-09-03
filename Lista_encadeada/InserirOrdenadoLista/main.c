#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct No{
    int valor;
    struct No *no;
}No;

void imprimir(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d ", no->valor );
        no = no->no;
    }
    printf("\n\n");
}

void inserir_ordenado(No **lista, int valor){
    No *novo = malloc(sizeof(No));
    No *aux = malloc(sizeof(No));
    No *auxAnterior = malloc(sizeof(No));
    bool achouPosicao = false;

    novo->valor = valor;
    if(*lista == NULL){

        novo->no = NULL;
        *lista = novo;
    }
    else if(valor < (*lista)->valor){
        novo->no = *lista;
        *lista = novo;
    }
    else{
        aux = *lista;
        while(aux->no){
            if(aux->valor > valor){
                novo->no = aux;
                auxAnterior->no = novo;
                aux=aux->no;
                achouPosicao = true;
                break;
            }
            else{
                auxAnterior = aux;
                aux=aux->no;
            }
        }
        if(!achouPosicao){
            if(aux->valor > valor){
                novo->no = aux;
                auxAnterior->no = novo;
            }
            else{
                novo->no = NULL;
                aux->no = novo;
            }
        }
    }


};

int main()
{
    No *lista = NULL;
    int cont = 0;
    int valor;
    while(cont < 5){
        printf("Digite um número: ");
        scanf("%d", &valor);
        inserir_ordenado(&lista, valor);
        imprimir(lista);
        cont++;
    }
    return 0;
}
