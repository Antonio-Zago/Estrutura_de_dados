#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *no;
}No;

typedef struct Pilha{
    No *topo;
}Pilha;

void imprimir(Pilha *pilha){
    No *topo = pilha->topo;
    while(topo != NULL) {
        printf("%d ", topo->valor);
        topo = topo->no;
    }
    printf("\n\n");
}

int main()
{
    int cont = 0;
    int valor;
    Pilha pilha;
    pilha.topo = NULL;
    while(cont < 5){
        printf("Digite um número: ");
        scanf("%d", &valor);
        inserir(valor, &pilha);

        imprimir(&pilha);
        cont++;
    }
    return 0;
}

void inserir(int valor,Pilha *pilha){
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->no = pilha->topo;
    pilha->topo = novo;

}
