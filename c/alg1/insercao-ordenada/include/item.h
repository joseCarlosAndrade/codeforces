#ifndef ITEM_H
	#define ITEM_H
	
	#include <stdbool.h>
	#include <stdlib.h>
	#include <stdio.h>
        struct item_ {
                int valor; // nao sera dado como generico aqui pois no .h esta definido como int ja.
        };


	typedef struct item_ ITEM;

	ITEM *item_criar(int chave);
	bool item_apagar(ITEM **item);
	void item_imprimir(ITEM *item);
	int item_get_chave(ITEM *item);
	bool item_set_chave(ITEM *item, int chave);

#endif
