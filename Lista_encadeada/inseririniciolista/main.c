#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

//Inserindo do inicio
/*
    Parametro � um ponteiro de ponteiro, porque a variavel criada
    na main � um ponteiro e � passada como parametro para
    a fun��o de adicionar no inicio.
    Passando esse ponteiro para a fun��o � possivel ap�s
    ser feita a cria��o de uma nova estrutura
    mudar dentro da pr�pria fun��o o valor de lista
    atribuindo o valor da nova estrutura criada
*/
void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }else{
        printf("Erro ao alocar mem�ria");
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
