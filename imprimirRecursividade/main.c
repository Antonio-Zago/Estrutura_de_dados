#include <stdio.h>
#include <stdlib.h>

int main()
{
    imprimir(5);
    return 0;
}

void imprimir(int valor){
    if(valor == 0){
        return;
    }
    printf("%d \n", valor);
    valor--;
    imprimir(valor);
}
