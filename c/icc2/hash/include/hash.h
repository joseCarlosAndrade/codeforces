#ifndef HASH_H
#define HASH_H

#define MAX_SIZE 100

typedef int elem;

typedef struct item_ {
    struct item_t* next;
    elem valor;
} item_t;

typedef struct hash_  { 
    item_t **H;
    int B;
    int n_elem;
} hash_t;

hash_t* hash_criar();

int hash_inserir(hash_t*h, elem x);

int hash_buscar(hash_t*h, elem x);

int hash_remover(hash_t*h, elem x);

#endif