#include"fila.h"
#include<stdio.h>

int main() {
    fila_t*fila = criar();

    inserir(fila, 4, 5);
    inserir(fila, 7, 1);
    inserir(fila, 2, 3);
    inserir(fila, 8, 9);

    while(!isEmpty(fila)) {
        elem x;
        remover(fila, &x);
        printf("%d ", x);
    }

    finalizar(fila);
       
}