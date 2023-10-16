#include"include/lista.h"
#include<assert.h>

void ordenar_lista(LISTA* lista);

int main(void) {
	int n;
	LISTA * lista = lista_criar();
	scanf("%d", &n);

	for ( int i = 0 ; i < n ; i++ ) {
		int num;
		scanf("%d" , &num);
		lista_inserir( lista, item_criar(num) );
		
		
	}

	//lista_imprimir(lista);

	ordenar_lista(lista);
	
	lista_imprimir(lista);
	printf("\n");
	lista_apagar(&lista);
}

void ordenar_lista(LISTA* lista) {
	assert(lista !=NULL);

	int q = lista->fim + 1;
	for (int i = 0 ; i < q-1 ; i ++) {
		for ( int j = 0; j < q-i-1 ; j++) {
			if (  item_get_chave(lista->lista[j]) > item_get_chave(lista->lista[j+1]) ) {
				ITEM * aux = lista->lista[j];
				lista->lista[j] = lista->lista[j+1];
				lista->lista[j+1] = aux;
			}	
		}	
	} 
}
