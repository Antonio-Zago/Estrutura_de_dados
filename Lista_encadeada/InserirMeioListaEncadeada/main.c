#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>



typedef struct No{
    int valor;
    struct No *no;
}No;

typedef struct Lista{
    int tam;
    No *inicio;
}Lista;


void imprimir(Lista *lista){
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->no;
    }
    printf("\n\n");
};

void inserir_meio(int valor, int posicao, Lista *lista){
    No *novo = malloc(sizeof(No));
    No *aux = malloc(sizeof(No));
    int cont = 0;
    bool achouPosicao = false;


    if(lista->inicio == NULL){
        printf("Lista vazia");
    }
    else{
       aux = lista;
       while(aux->no){
           if(cont == posicao){
                novo->valor = valor;
                novo->no = aux->no;
                aux->no = novo;
                achouPosicao = true;
           }
           aux = aux->no;
           cont++;
       }
       if(!achouPosicao){
            printf("Posicao digitada maior que a lista");
       }
    }
};

void inserirInicio(Lista *lista, int valor) {
    No *novo = malloc(sizeof(No)); // cria um novo nó
    novo->valor = valor;// (*novo).valor = valor

    if(lista->inicio == NULL) { // a lista está vazia
        novo->no = NULL;
        lista->inicio = novo;
    } else { // a lista não está vazia
        novo->no = lista->inicio;
        lista->inicio = novo;
    }
    lista->tam++;
}


int main()
{
    Lista lista;
    lista.inicio = NULL;
    lista.tam = 0;
    int cont = 0;
    int valor;
    int posicao;
    inserirInicio(&lista,1);
    inserirInicio(&lista,2);
    inserirInicio(&lista,3);
    while(cont < 5){
        printf("Digite um número: ");
        scanf("%d", &valor);
        printf("Digite uma posicao: ");
        scanf("%d", &posicao);
        inserir_meio(valor,posicao, &lista);

        imprimir(&lista);
        cont++;
    }
    return 0;
}
