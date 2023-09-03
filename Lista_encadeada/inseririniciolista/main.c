#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

//Inserindo do inicio
/*
    Parametro é um ponteiro de ponteiro, porque a variavel criada
    na main é um ponteiro e é passada como parametro para
    a função de adicionar no inicio.
    Passando esse ponteiro para a função é possivel após
    ser feita a criação de uma nova estrutura
    mudar dentro da própria função o valor de lista
    atribuindo o valor da nova estrutura criada
*/
void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }else{
        printf("Erro ao alocar memória");
    }
}

void imprimir(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d ", no->valor );
        no = no->proximo;
    }
    printf("\n\n");
}

int main()
{
    No *lista = NULL;
    int cont = 0;
    int valor;
    while(cont < 5){

        printf("Digite um valor: ");
        scanf("%d", &valor);
        inserir_no_inicio(&lista, valor);
        imprimir(lista);
        cont++;
    }
    return 0;
}
