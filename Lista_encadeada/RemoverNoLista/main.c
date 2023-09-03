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

int main()
{
    No *lista = NULL;
    int cont = 0;
    int valor;
    while(cont < 2){
        printf("Digite um número: ");
        scanf("%d", &valor);
        adicionarLista(&lista, valor);
        imprimir(lista);
        cont++;
    }
     printf("Digite um número para remover: ");
     scanf("%d", &valor);
     remover(&lista, valor);
     imprimir(lista);
    return 0;
}

void remover(No **lista, int valor){
    No *aux = malloc(sizeof(No));
    No *auxAnterior = malloc(sizeof(No));


    if((*lista)->valor == valor){
        *lista = (*lista)->no;
    }
    else{
        aux = *lista;
        while(aux){
            if(aux->valor == valor){
                auxAnterior->no = aux->no;
                break;
            }
            else{
                auxAnterior = aux;
            }
            aux = aux->no;
        }
    }

}

void adicionarLista(No **lista, int valor){
    No *novo = malloc(sizeof(No));
    if(*lista==NULL){
        novo->valor = valor;
        novo->no = NULL;
        *lista = novo;
    }
    else{
        novo->valor = valor;
        novo->no = *lista;
        *lista = novo;
    }


}
