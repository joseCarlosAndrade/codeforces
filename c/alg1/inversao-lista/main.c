#include<stdio.h>
#include<stdlib.h>

#include"include/lista.h"

int main(void) {
	LISTA* lista = lista_criar();

	int n ;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++) {
		int valor;
		scanf("%d", &valor);
		lista_inserir(lista, item_criar(valor));
	}

	lista_inverter(&lista);
	lista_imprimir(lista);
	printf("\n");

	lista_apagar(&lista);
}
