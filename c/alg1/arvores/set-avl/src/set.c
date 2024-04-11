#include"set.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


struct set {
    AVL *core; // avl que armazena os elementos
    int n; // quantidade de elementos
};

// cria um novo set com 0 elementos
SET *set_criar(void) {
    SET*set = (SET*)calloc(1, sizeof(SET));
    assert(set!=NULL);

    set->core = cria();
    set->n = 0; // seta a variavel que guarda a quantidade de itens dentro da avl

    return set;
}

int set_pertence(SET *A, int elemento) { // retorna 1 (true) se o elemento buscado foi encontrado
    return busca(A->core, elemento); // usa a busca da avl
}

int set_inserir (SET *s, int elemento) {
    assert(s!= NULL);
    // if(set_pertence(s, elemento)) return 0;

    if (inserir(s->core, elemento)) { // verificação se o elemento ja esta inserido feita dentro dessa funcao
        s->n ++; // aumentando quantidade de elementos (se a inserção obteve sucesso)
    }   

    return 0; // falha na inserção: elemento ja existe no conjunto
}

int set_remover(SET *s, int elemento) {
    assert(s!=NULL);
    return remover(s->core, elemento);
}

void set_apagar(SET **s) { // finaliza o set, liberando espaço da arvore ali alocada e do proprio set
    finalizar((*s)->core);
    free(*s);
}

void imprimir_set_rec(NO* no) { // funcao chamada dentro de set_imprimir. Imprime as informações
                                // recursivamente
    if(no==NULL) return;
    else {
        printf("%d ", get_valor(no->info));
    }

    imprimir_set_rec(no->esq);
    imprimir_set_rec(no->dir);
    
}

void set_imprimir(SET *s) { // imprime o conjunto. como um conjunto nao tem ordem, qualquer forma de percorrer a avl é valida
    imprimir_set_rec(s->core->raiz);
    printf("\n");
}


void inserir_checagem(SET*s, NO* no) { // insere recursivamente os elementos filhos de no no
                                       // conjutno s, verificado se ja estao inseridos ou nao
    // set_imprimir(s);
    if(no==NULL) return;
    else {
        // printf("%d ", get_valor(no->info));
        // if (!set_pertence(s, get_valor(no->info))); //
        set_inserir(s, get_valor(no->info)); // verificação se no ja existe ja esta dentr de set_inserir
    }

    inserir_checagem(s,no->esq);
    inserir_checagem(s,no->dir);
    
}

SET *set_uniao(SET *A, SET *B) { // cria um novo set que representa a uniao dos conjuntos A e B
    assert(A!=NULL && B!=NULL);

    SET*n_set = set_criar();

    inserir_checagem(n_set, A->core->raiz);
    inserir_checagem(n_set, B->core->raiz);

    return n_set;
    
}  

void intersec_rec(NO*raiz , SET*B, SET*final) { //cria um novo conjunto que representa a intersecção
                                                // dos elelementos do conjunto B com os noa dilhoa da raiz dada
    if (raiz==NULL) return;
    
    if (set_pertence(B, get_valor(raiz->info))) {
        set_inserir(final, get_valor(raiz->info));
    }

    intersec_rec(raiz->esq, B, final);
    intersec_rec(raiz->dir, B, final);

}


SET *set_interseccao(SET *A, SET *B) {
    assert(A!=NULL && B!=NULL);

    SET*n_set = set_criar();

    intersec_rec(A->core->raiz, B, n_set);

    return n_set;
}       