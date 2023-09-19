#include"fila.h"
#include<stdio.h>

void cartas(int n) {
    // criando as filas
    FILA * fila = fila_criar(); // principal
    FILA * fila_descartada = fila_criar(); // fila de cartas descartadas

    // inserindo os elementos na fila
    for (int i = 0 ; i < n; i ++) {
        fila_inserir(fila, item_criar(i+1));
    }

    while(fila_tamanho(fila) > 1) {
         // removendo inicio
        ITEM * at = fila_remover(fila);

        // inserindo na fila de cartas descartadas
        fila_inserir(fila_descartada, at);


        // retirando mais um item do comeco para colocar no fim
        ITEM * item_final = fila_remover(fila);

        // inserindo o no final da fila
        fila_inserir(fila, item_final);

    }

    // printando filas:
    printf("Discarded cards:");
    while(!fila_vazia(fila_descartada)) {
        ITEM * it =  fila_remover(fila_descartada);
        printf(" %d", item_get_chave(it));
        if (fila_tamanho(fila_descartada) >=1) printf(",");
    }   

    // if (!fila_vazia);
    // fila_imprimir(fila_descartada);
    printf("\nRemaining card: %d\n", item_get_chave( fila_frente(fila) ));
    // if (!fila_vazia);
    // fila_imprimir(fila);
    
    fila_apagar(&fila);
    fila_apagar(&fila_descartada);
}