#include"../include/avl.h"
#include"../include/item.h"

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

void atualizar_altura(NO *no){
    if (no == NULL)
        return;
    int esq = 0;
    int dir = 0;

    if (no->esq != NULL)
        esq = no->esq->altura;
    if (no->dir != NULL)
        dir = no->dir->altura;

    if (esq >= dir){
        no->altura = 1 + esq;
    }
    else{
        no->altura = 1 + dir;
    }
}

NO * rotacao_EE(NO * desb) {
    NO * aux;
    aux = desb->dir;
    desb->dir = aux->esq;
    aux->esq = desb;
    atualizar_altura(desb);
    atualizar_altura(aux);
    return aux;
}

NO * rotacao_DD(NO * desb) {
    NO * aux;
    aux = desb->esq;
    desb->esq = aux->dir;
    aux->dir = desb;
    atualizar_altura(desb);
    atualizar_altura(aux);
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

int atualizar_fb(NO *no){
    int e = 0;
    int d = 0;

    if (no->dir != NULL)
        d = no->dir->altura;

    if (no->esq != NULL)
        e = no->esq->altura;

    return e - d;
}

AVL *cria() {
    AVL * a = (AVL*)calloc(1, sizeof(AVL));
    assert(a!=NULL);
    a->raiz=NULL;

    return a;
}

int esta_vazia(AVL *a) {
    assert(a!=NULL);
    return a->raiz == NULL; // verdadeiro se arvore estiver vazia
}

void finaliza(NO *raiz) {

    if (raiz !=NULL) {
        finaliza(raiz->esq);
        finaliza(raiz->dir);
        apagar_item(&(raiz->info));
        free(raiz);
    }
}

void finalizar(AVL*a) {
    assert( a!=NULL);

    finaliza(a->raiz);
    free(a);
}

void imprime(NO *raiz) { // funcoes de impressao do professor
    if(raiz != NULL) {
            printf("%d(", get_valor(raiz->info));
            imprime(raiz->esq);
            printf(",");
            imprime(raiz->dir);
            printf(")");
    } else {
            printf("_");
    }
}

void imprimir(AVL *A) {
    imprime(A->raiz);
    printf("\n");
}

int altura(AVL *A) {
    return A->raiz->altura;
}

int busca_recursiva(NO *no, elem chave) {
    if (no == NULL) return 0;

    if (get_valor(no->info) == chave) return 1;

    if (get_valor(no->info) > chave) return busca_recursiva(no->esq, chave);

    return busca_recursiva(no->dir, chave);
}

int busca(AVL *A, elem chave) {
    return busca_recursiva(A->raiz, chave);
}

NO* inserir_rec(NO*raiz, elem chave, int *flag) {
    if (raiz != NULL) {
        if(get_valor((raiz)->info) > chave) {
            raiz->esq = inserir_rec(raiz->esq, chave, flag);

            if(*flag == 1) {
                switch(raiz->   FB) {
                    case -1:
                        raiz->FB = 0;
                        *flag = 0;
                        break;
                    case 0:
                        raiz->FB = 1;
                        *flag = 1;
                        break;
                    case 1:
                        if(raiz->esq->FB > 0) { //sinais iguais
                            raiz = rotacao_DD(raiz);
                            raiz->FB = 0;
                            raiz->dir->FB = 0;
                        } else {
                            raiz = rotacao_ED(raiz);
                            if(raiz->FB == 0) {
                                raiz->esq->FB = 0;
                                raiz->dir->FB = 0;
                            } else if(raiz->FB == -1) {
                                raiz->esq->FB = 1;
                                raiz->dir->FB = 0;
                                raiz->FB = 0;
                            } else { //raiz->fb == 1
                                raiz->esq->FB = 0;
                                raiz->dir->FB = -1;
                                raiz->FB = 0;
                            }
                        }
                        *flag = 0;
                }
            }

        }
        else if (get_valor((raiz)->info) < chave) {
            raiz->dir = inserir_rec((raiz)->dir, chave, flag);

            if(*flag == 1) {
                switch(raiz->FB) {
                    case 1:
                        raiz->FB = 0;
                        *flag = 0;
                        break;
                    case 0:
                        raiz->FB = -1;
                        *flag = 1;
                        break;
                    case -1:
                        if(raiz->dir->FB < 0) { //sinais iguais
                            raiz = rotacao_EE(raiz);
                            raiz->FB = 0;
                            raiz->esq->FB = 0;
                        } else {
                            raiz = rotacao_DE(raiz);
                            if(raiz->FB == 0) {
                                raiz->esq->FB = 0;
                                raiz->dir->FB = 0;
                            } else if(raiz->FB == -1) {
                                raiz->esq->FB = 1;
                                raiz->dir->FB = 0;
                                raiz->FB = 0;
                            } else { //raiz->fb == 1
                                raiz->esq->FB = 0;
                                raiz->dir->FB = -1;
                                raiz->FB = 0;
                            }
                        }
                        *flag = 0;
                }
                        
        }
        }else {
            return 0;
        }
    }
    else {
        raiz = (NO*)calloc(1, sizeof(NO));
        (raiz)->esq = NULL;
        (raiz)->dir = NULL;
        (raiz)->FB = 0;
        (raiz)->altura = 0;
        (raiz)->info = criar_item(chave);
        *flag = 1;
    
    }
    atualizar_altura(raiz);
    return raiz;
    
}

int inserir(AVL * A, elem chave) {
    assert(A!=NULL);
    if (busca(A, chave)) return 0; // chave ja esta inserida
    int flag = 1;   
    A->raiz = inserir_rec(A->raiz, chave, &flag);
    atualizar_altura(A->raiz);
    return 1;

}
 
NO *balancear(NO *no){
    no->FB = atualizar_fb(no);

    if (no->esq != NULL){
    no->esq->FB = atualizar_fb(no->esq);        
    }
    
    if (no->dir != NULL){
    no->dir->FB = atualizar_fb(no->dir);        
    }

    if (no == NULL)
        return NULL;
    switch (no->FB)
    {
    case -2:
        if (no->dir->FB == -1)
            return rotacao_EE(no);
        return rotacao_DE(no);

    case 2:
        if (no->esq->FB == 1)
            return rotacao_DD(no);
        return rotacao_ED(no);
    }
    return no;
}

NO *caso_doisfilhos(NO *no, elem *menor){
    if (no == NULL)
        return NULL;

    if (no->esq == NULL)
    {
        NO *dir = no->dir;
        *menor = get_valor(no->info);
        free(no);
        no = NULL;
        return dir;
    }

    no->esq = caso_doisfilhos(no->esq, menor);
    atualizar_altura(no);
    return no;
}

NO *remover_recursiva(NO *no, elem chave, int *busca){
    if(no == NULL){
        *busca = 1;
        return NULL;
    }

    if(get_valor(no->info) == chave){
        //caso nao tenha filhos ou so tenha um fiho na esquerda
        if (no->dir == NULL)
        {
            NO *no_e = no->esq;
            free(no);
            // no == NULL;
            return no_e;
        }

        //caso so tenha um filho na direita
        if (no->esq == NULL)
        {
            NO *no_d = no->dir;
            free(no);
            // no == NULL;
            return no_d;
        }

        //caso tenha dois filhos

        elem menor;
        no->dir = caso_doisfilhos(no->dir, &menor);
        set_valor(no->info, menor);
        atualizar_altura(no);
        return balancear(no);
    }

    if(get_valor(no->info) < chave){
        no->dir = remover_recursiva(no->dir, chave, busca);
    }
    else{
        no->esq = remover_recursiva(no->esq, chave, busca);
    }
    atualizar_altura(no);
    return balancear(no);
}

int remover(AVL *A, elem chave) {

    assert(A!=NULL);

    int busca = 0;

    NO * aux;
    aux = remover_recursiva(A->raiz, chave, &busca);

    if(busca != 1){
    A->raiz = aux;
    atualizar_altura(A->raiz);
    return 1;
    }
    else{
        return 0;
    }
}