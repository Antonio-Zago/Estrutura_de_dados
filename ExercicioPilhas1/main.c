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

    Pilha pilha2;
    pilha2.topo = NULL;

    Pilha pilha3;
    pilha3.topo = NULL;

    int cont = 0;
    int valor;

    while(cont<4){
        printf("Digite um número: ");
        scanf("%i", &valor);
        adicionaElemento(&pilha1, valor);
        mostraPilha(&pilha1);

        printf("Digite um número2: ");
        scanf("%i", &valor);
        adicionaElemento(&pilha2, valor);
        mostraPilha(&pilha2);

        if(cont<2){
            printf("Digite um número3: ");
            scanf("%i", &valor);
            adicionaElemento(&pilha3, valor);
            mostraPilha(&pilha3);
        }



        cont++;
    }

    contaElementos(&pilha1);


    exibePilha(&pilha1, &pilha2, &pilha3);

    return 0;



}

void exibePilha(Pilha *pilha1,Pilha *pilha2,Pilha *pilha3){

    //Cria duas pilhas auxiliares, A1 e A2, inicialmente vazias;
    Pilha pilhaResultado1;
    pilhaResultado1.topo = NULL;

    Pilha pilhaResultado2;
    pilhaResultado2.topo = NULL;


    int contPilha1 = contaElementos(pilha1);
    int contPilha2 = contaElementos(pilha2);
    int contMaior = (contPilha1>contPilha2) ? contPilha1 :contPilha2;
    int cont = 0;

    //Remove um elemento de P1 e o insere em A1. Em seguida, remove um elemento de P2 e o insere em A1. Repete esses dois procedimentos até que P1 e P2 fiquem, ambas, vazias;
    while(contMaior>0){
        if(pilha1->topo){
            adicionaElemento(&pilhaResultado1, pilha1->topo->valor);
            printf("\n\n");
            mostraPilha(&pilhaResultado1);
            removeTopo(pilha1);
        }
        if(pilha2->topo){
            adicionaElemento(&pilhaResultado1, pilha2->topo->valor);
            printf("\n\n");
            mostraPilha(&pilhaResultado1);
            removeTopo(pilha2);
        }



        contMaior--;
    }

    //Remove um elemento de P3 e o insere em A1. Repete esse procedimento até que P3 fique vazia;
    while(pilha3->topo){
            adicionaElemento(&pilhaResultado1, pilha3->topo->valor);
            printf("\n\n");
            mostraPilha(&pilhaResultado1);
            removeTopo(pilha3);
    }

    //Remove um elemento de A1 e o insere em A2. Repete esse procedimento até que A1 fique vazia;
    while(pilhaResultado1.topo){
            adicionaElemento(&pilhaResultado2, pilhaResultado1.topo->valor);
            printf("\n\n");
            mostraPilha(&pilhaResultado2);
            removeTopo(&pilhaResultado1);
    }

    printf("\n\n");
    //Remove um elemento de A2 e o exibe no console. Repete esse procedimento 4 vezes.
    while(cont<4){
        mostraTopo(&pilhaResultado2);
        removeTopo(&pilhaResultado2);
        cont++;
    }




}

void mostraTopo(Pilha *pilha){
    printf("%d \n",  pilha->topo->valor);
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

void adicionaElemento(Pilha *pilha, int valor){
    No *novo = malloc(sizeof(No));

    novo->valor = valor;
    if(pilha->topo == NULL){
        novo->no = NULL;
        pilha->topo = novo;
    }
    else{
        novo->no = pilha->topo;
        pilha->topo = novo;
    }
}






int contaElementos(Pilha *pilha){
    No *pilhaAux = malloc(sizeof(No));

    int cont = 0;
    pilhaAux = pilha->topo;
    while(pilhaAux){
        pilhaAux = pilhaAux->no;
        cont++;
    }
    return cont;
}




