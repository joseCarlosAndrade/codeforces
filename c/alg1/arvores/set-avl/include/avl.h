
/* Estrutura de dados escolhida para a construção do SET. A arvore AVL foi escolhida pois 
possui uma grande eficiência na inserção e busca, operações mais realizadas para construir a 
estrutura de dados de um conjunto. 
Ou seja, independente do estado da arvore AVL, as operações de busca, inserção e remoção 
serão sempre O(logn).*/

#ifndef AVL_H
#define AVL_H

#include"item.h"

// typedef int elem;
typedef struct no NO;
struct no {
    item_t* info;
    NO * esq, * dir;
    int FB; // fator de balanceamento;
    int altura; //altura do nó
};

typedef struct avl {
    NO *raiz;

} AVL;

// funcoes para avl padroes
AVL *cria();
int esta_vazia(AVL *A);
void finalizar(AVL *A);
void imprimir(AVL *A);
int altura(AVL *A);
int busca(AVL *A, elem chave);
int inserir(AVL *A, elem chave);
int remover(AVL *A, elem chave);


#endif