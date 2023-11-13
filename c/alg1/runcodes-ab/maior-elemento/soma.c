#include"ab.h"

int _soma(NO * no, int *soma) {

    // if ( item_get_chave(no->item) > maior) soma = item_get_chave(no->item);
    *soma += item_get_chave(no->item);
        
    // descer esquerda
    if(no->esq != NULL) {
        _soma(no->esq, soma);


        }
        
    // descer direita
    if(no->dir != NULL){
        _soma(no->dir, soma);

    }


    return 0;

    

}

int soma(AB*T) {
    int soma = 0;
    _soma(T->raiz, &soma);
    return soma;
}