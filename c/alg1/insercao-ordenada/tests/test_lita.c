#include"../include/lista.h"


int main(void) {
	LISTA *lista = lista_criar();

	lista_inserir(lista, item_criar(10));
	lista_inserir(lista, item_criar(11));
	lista_inserir(lista, item_criar(9));
	lista_inserir(lista, item_criar(3));

	lista_remover(lista, 11);

	ITEM *it = lista_busca(lista, 3);

	printf("Buscando item de chave 3: ");
	item_imprimir(it);

	printf("\nPrintando lista: ");
	lista_imprimir(lista);
	
}
