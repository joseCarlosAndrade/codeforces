#include<../include/skiplist.h>

#include<stdio.h>
#include<stdlib.h>

struct _no {
	item_t item;
	int level;

	_no_t * next;
	_no_t * down;

};

struct _skiplist {
	_no_t * upleft;
	int level;
	int max_level;
};


skiplist_t * sl_criar() {
	skiplist_t * sl = NULL;
	sl = (skiplist_t*) calloc(1, sizeof(skiplist_t));
	
	assert(sl!=NULL);
	sl->max_level = 2;

	return sl;
}


void sl_inserir( skiplist_t * sl, item_t * it ) {
	assert(skiplist_t !=NULL && it!=NULL);
	//TODO verificar se elemenot ja exite (implementar busca)
	
	// cria um no sentinela
	_no_t sentinela = sl->upleft;
	_no_t updates[sl->max_level];

	int node_level = generate_level() ; //TODO

	while (sentinela->level != 0) {
		while( item_get_valor(sentinela->next->item) < item_get_value(it)) {
			sentinela = sentinela->next;
		}
		updates[sentinela->level] = sentinela;
		sentinela = sentinela->down;
	}

	// procurando na linha local
	while(sentinela->next < item_get_valor(it)) {
		sentinela = sentinela->next;
	}
	
	updates[sentinela->level] = sentinela;


	int curr_level = 0;

	while ( curr_level <= sl->level && curr_level <= node_level) {
		_no_t new_node = _no_criar(item_get_valor(it), curr_level, NULL, NULL);
		// caso seja ultima linha
		if (curr_level == 0) {
			new_node->next = updates[curr_level]->next;
			new_node->down = NULL;
		}
		else {

			new_node->next = updates[curr_level]->next;
			new_node->down = updates[curr_level-1]->next;;
		}

		updates[curr_level]->next = new_node;
		curr_level ++;
	}

	for (int i = sl->level +1; i<= node_level; i++) {
		_no_t * new_node= _no_criar(item_get_valor(it), i, NULL, updates[i-1]->next);
		_no_t * new_upleft(-1, i, new_node, sl->upleft);
		sl->upleft = new_upleft;
		updates[i] = new_upleft;
	}

	sl->level = node_level;
	
}

no_t * _no_criar(int valor, int level, _no_t * next, _no_t * down) {
	_no_t * newnode = NULL;
	newnode = (_no_t*)calloc(1,sizeof(_no_t));
	assert(newnode !=NULL);
	
	item_t * it = NULL;
	it = (item_t*)calloc(1,sizeof(item_t));
	assert(it!=NULL);
	
	newnode->item = it;
	newnode->level = level;
	newnode->next = next;
	newnode->down = down;

	return newnode;
}
