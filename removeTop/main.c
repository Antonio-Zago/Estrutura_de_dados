#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *no;
}No;

typedef struct Pilha{
    No *topo;
}Pilha;

int main()
{
    Pilha pilha1;
    pilha1.topo = NULL;

    removeTopo(&pilha1);
    mostraPilha(&pilha1);

    return 0;
}

void removeTopo(Pilha *pilha){
    if(pilha->topo != NULL){
        if(pilha->topo->no == NULL){
        pilha->topo = NULL;
        }else{
            pilha->topo = pilha->topo->no;
        }
    }

}


void mostraPilha(Pilha *pilha){
    No *no = malloc(sizeof(No));

    no = pilha->topo;

    while(no){
        printf("%d \n",  no->valor);
        no = no->no;
    }
}
