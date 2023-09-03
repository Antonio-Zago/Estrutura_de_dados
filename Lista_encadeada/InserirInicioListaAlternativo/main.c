#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio, *fim;
    int tam;
} Lista;

// inserção no início da lista
void inserirInicio(Lista *lista, int valor) {
    No *novo = malloc(sizeof(No)); // cria um novo nó
    novo->valor = valor;// (*novo).valor = valor

    if(lista->inicio == NULL) { // a lista está vazia
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    } else { // a lista não está vazia
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    lista->tam++;
}

// imprimir a lista
void imprimir(Lista *lista) {
    No *inicio = lista->inicio;
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
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tam = 0;

    int cont = 0;
    int valor;
    while(cont < 5){

        printf("Digite um valor: ");
        scanf("%d", &valor);
        inserirInicio(&lista, valor);
        imprimir(&lista);
        cont++;
    }
    return 0;
}
