#ifndef ARVORE_BINARIA_H
	#define ARVORE_BINARIA_H
    
    #include "item.h"

    typedef struct no_ NO;

    struct no_{
        ITEM  *item;
        NO *esq;
        NO *dir;
    };

    struct ab_{
        NO *raiz;
        int profundidade;
    };

    
    #define FILHO_ESQ 0
    #define FILHO_DIR 1

    typedef struct ab_ AB;

    AB *ab_criar(void); 
    bool ab_inserir(AB *T, ITEM *item, int lado, int chave);
    bool ab_remover(AB *T, int chave);
    void ab_apagar_arvore(AB **T);
    // int maior(AB *T);
    int soma(AB*T);
    
#endif
