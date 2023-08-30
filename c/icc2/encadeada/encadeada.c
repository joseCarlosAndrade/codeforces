#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct _celula {
	int v;
	struct _celula * proximo;
};

typedef struct _celula celula_t;

celula_t * criar_lista_encadeada(int v);
void adicionar_elemento_lista(celula_t* head, int v);
void printar_lista(celula_t*head);
void modifica(celula_t*head, int n);

celula_t * locate(celula_t* head, int target);

int main(int argc, char ** argv) {
	
	celula_t* head = criar_lista_encadeada(0);

	adicionar_elemento_lista(head, 1);
	adicionar_elemento_lista(head, 3);
	
	printar_lista(head);

	printf("\n");
	printf("%p\n", head);
	printf("%p %p %p\n", locate(head, 0), locate(head,1), locate(head,2)); 
	modifica(head, 2);
	printar_lista(head);
}

celula_t * criar_lista_encadeada(int v) {
	celula_t * lista = (celula_t *) calloc ( 1, sizeof(celula_t));
	assert(lista != NULL);

	lista->v = v;
	lista->proximo = NULL;
	return lista;
}

void adicionar_elemento_lista(celula_t* head, int v) {
	if (head->proximo == NULL) {
		celula_t * proximo = (celula_t*)calloc(1,sizeof(celula_t));
		assert(proximo != NULL);
		proximo->v = v;

		head->proximo = proximo;
		
	}
	else adicionar_elemento_lista(head->proximo, v);
}

void printar_lista(celula_t*head) {
	if (head->proximo == NULL) {
		printf("%d ", head->v);
		return;
	}

	printf("%d ", head->v);
	printar_lista(head->proximo);

}

celula_t * locate(celula_t* head, int target) {
	for (celula_t * p = head; p!= NULL; p = p->proximo) {
		if (p->v == target) return p;
	}
	return NULL;
}

void modifica(celula_t*head, int n){

     for (celula_t* p = head; p != NULL; p = p->proximo){
         if((p->v <= n) && (p->proximo->v >= n)){
                      
              celula_t* novo = (celula_t*) malloc(sizeof(celula_t));
              if(novo == NULL){exit(1);}
              novo->proximo = p->proximo;
              p->proximo = novo;
              novo->v = n;
              break;                          
         }
     }

}
