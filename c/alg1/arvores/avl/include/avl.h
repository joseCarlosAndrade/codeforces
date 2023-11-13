#ifndef AVL_H
#define AVL_H

typedef int elem;

typedef struct no {
    elem info;
    struct no * esq, * dir;
    int FB; // fator de balanceamento;
} NO;

typedef struct avl {
    NO *raiz;

} AVL;


NO * rotacao_EE( NO * desb);

NO * rotacao_DD(NO * desb);

NO * rotacao_ED(NO * desb);

NO * rotacao_DE(NO * desb);

#endif