#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
}No;

typedef struct Lista{
    int tam;
    No *primeiro;
}Lista;

void inserir_final(int valor, Lista *lista){
    No *novo = malloc(sizeof(No));
    No *novo = malloc(sizeof(No));

    novo->valor = valor;
    novo->proximo = NULL;

    if(lista->primeiro == NULL){
        lista->primeiro= novo;
    }
    else{
        aux = lista;
        while(aux->proximo){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }


    lista->tam++;
}

void imprimir(Lista *lista) {
    No *inicio = lista->primeiro;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}

int main()
{
    Lista lista;
    lista.primeiro = NULL;
    lista.tam = 0;
    int cont = 0;
    int valor;
    while(cont < 5){
        printf("Digite um número: ");
        scanf("%d", &valor);
        inserir_final(valor, &lista);
        imprimir(&lista);
        cont++;
    }
    return 0;
}
