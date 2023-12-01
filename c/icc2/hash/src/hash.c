#include"include/hash.h"
#include<stdlib.h>
#include<assert.h>

hash_t* hash_criar() {
    hash_t * h = NULL;
    h = (hash_t*)calloc(1, sizeof(hash_t));
    assert(h != NULL);

    h->B = MAX_SIZE;
    h->n_elem = 0;
    h->H = (hash_t**)calloc(MAX_SIZE, sizeof(item_t*));
    assert (h->H != NULL);

    for (int i =0; i < MAX_SIZE; i++) {
        item_t*it = (item_t*)calloc(1, sizeof(item_t));
        assert(it!=NULL);
        it->next = NULL;
        it->valor = -1;

        h->H[i] = it;
    }
    return h;
}

int hash_posicao_ocupada(hash_t*h, int index) {
    if (h->H[index]->next != NULL) return 1;
    return 0;
}

int hash_inserir(hash_t*h, elem x) {
    if (hash_buscar(h, x)) return 0; // elemento ja se encontra no arranjo

    // using rehash
    // for (int i =0; i < h->B; i++) {
    //     int index = (x + i) % h->B;
    //     if (hash_posicao_ocupada(h, index)) continue; // se a posicao ja esta ocupada, pular

    //     item_t*it = (item_t*)calloc(1,sizeof(item_t));
    //     assert(it != NULL);
    //     it->next = NULL;
    //     it->valor =x ;

    //     h->H[index]->next = it;
    //     break;
    // }
    // using open hash (linked list as each element)
    int index = x % h->B;
    item_t*no = h->H[index];
    for (;;) {
        if (no->next == NULL) {
            item_t*it = (item_t*)calloc(1,sizeof(item_t));
            assert(it != NULL);
            it->next = NULL;
            it->valor =x ;

            h->H[index]->next = it;
            break;
        }
        no = no->next;
    }


}

int hash_buscar(hash_t*h, elem x) {

}

int hash_remover(hash_t*h, elem x) {

}