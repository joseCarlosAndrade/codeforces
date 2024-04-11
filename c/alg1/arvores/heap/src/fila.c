#include"fila.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct no {
    elem info;
    int prio;
};

struct fila {
    int n;
    no_t *heap[MAX]; // ponteiro para a fila de MAX elementos
};

void sobe(fila_t *f, int i) {
    int j;
    no_t *temp;

    j= (int)((i-1)/2);

    // se i tem pai e que seja menor que i
    if (j>=0 && f->heap[i]->prio > f->heap[j]->prio) {
        // trocar ambos
        temp = f->heap[i];
        f->heap[i] = f->heap[j];
        f->heap[j] = temp;

        // continua subindo o elemento
        sobe(f, j);

    }

}

void desce(fila_t *f, int i) {
    int j;
    no_t *temp;

    j = 2*i +1;

    if (j < f->n) { // se i tem filhos
        if (j < f->n-1) { // se i tem filho a direita
            if(f->heap[j]->prio < f->heap[j+1]->prio) j++; // peha o maior filho...

        }
        // ... e compara com o pai
        if(f->heap[j]->prio> f->heap[i]->prio) {
            // troca ambos
            temp = f->heap[i];
            f->heap[i] = f->heap[j];
            f->heap[j] = temp;

            desce(f, j); // comtinua descendo

        }

    }
}

fila_t * criar() {
    fila_t * fila = (fila_t*)calloc(1, sizeof(fila_t));
    assert (fila != NULL);

    fila->n = 0;
    return fila;
}

int inserir(fila_t *f, elem chave, int prior) {
    assert(f !=NULL);
    if(isFull(f)) return 0;

    // inserir no final do vetor
    no_t*no = (no_t*)calloc(1, sizeof(no_t));
    assert(no!=NULL);
    no->info = chave;
    no->prio = prior;
    f->heap[f->n] = no;
    sobe(f, f->n); // subindo elemento adicionado
    f->n++;

    return 1;ASA
}

int remover(fila_t *f, elem *chave) {
    assert(f !=NULL);
    if(isEmpty(f)) return 0;

    *chave = f->heap[0]->info;
    free(f->heap[0]);

    f->heap[0] = f->heap[f->n-1]; // raiz desalocada agora recebe o ultimo elemento folha n-1
    f->n--; // precisa ser atualizado antes de descer
    desce(f, 0);
    return 1;
}

int isEmpty(fila_t *f) {
    assert(f!=NULL);
    return f->n == 0;
}

int isFull(fila_t *f) {
    assert(f  !=NULL);
    return f->n == MAX;
}

void finalizar( fila_t *f) {
    assert(f != NULL);

    for(int i = 0; i < f->n; i++) {
        free(f->heap[i]);
    }
    free(f);
}
