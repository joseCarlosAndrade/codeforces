#include"../include/avl.h"
#include"../include/item.h"
#include"stdlib.h"

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

int inserir_rec(NO**raiz, elem chave, int *flag) {
    if (*raiz != NULL) {
        if(get_valor((*raiz)->info) > chave) {
            inserir_rec((*raiz)->esq, chave, flag);

            if (*flag == 1) { // nao foi feita nenhuma rotacao ainda, conferir fator de balanceamento
                switch ((*raiz)->FB)
                {
                case -1:
                    (*raiz)->FB = 0;
                    *flag = 0;
                    break;
                
                case 0:
                    (*raiz)->FB = 1;
                    *flag = 1;

                    break;
                
                case 1:
                    if ((*raiz)->esq->FB > 0) { // sinais iguais do fb pai e filho
                        *raiz = rotacao_DD(*raiz); // rotacionando para a direita
                        (*raiz)->FB = 0;
                        (*raiz)->dir->FB = 0;

                    } else {
                        // sinais diferentes, rotacao dupla
                    }
                    break;
                }
            }

        }
        else if (get_valor((*raiz)->info) < chave) {
            inserir_rec((*raiz)->dir, chave, flag);

            if (*flag == 1) { // nao foi feita nenhuma rotacao ainda, conferir fator de balanceamento

            }
        }
        else {
            printf("Elemento ja existente!\n");
            return 0;
        }
    }
    else {
        *raiz = (NO*)calloc(1, sizeof(NO));
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->FB = 0;
        (*raiz)->info = criar_item(chave);
        *flag = 1;
        return *raiz;
    }
}

int inserir(AVL * A, elem chave) {
    int flag;
    return inserir_rec(&(A->raiz), chave, &flag);
}