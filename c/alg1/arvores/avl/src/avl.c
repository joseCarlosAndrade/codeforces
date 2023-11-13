#include"../include/avl.h"

NO * rotacao_EE(NO * desb) {
    NO * aux;
    aux = desb->dir;
    desb->dir = aux->esq;
    aux->esq = desb;

    return aux;
}

NO * rotacao_DD(NO * desb) {
    NO * aux;
    aux = desb->esq;
    desb->esq = aux->dir;
    aux->dir = desb;

    return aux;
}

NO * rotacao_ED(NO * desb) {
    desb->esq = rotacao_EE(desb->esq);
    return rotacao_DD(desb);
}

NO * rotacao_DE(NO * desb) {
    desb->dir = rotacao_DD(desb->dir);
    return rotacao_EE(desb);
}