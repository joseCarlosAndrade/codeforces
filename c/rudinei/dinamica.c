#include <stdio.h>
#include <stdlib.h>

/*
-> Código para alocar dinâmicamente um vetor double - Aula Rudinei 15/06
-> Objetivo do código é fazer o ponteiro vet na stack apontar para o vetor
alocado na heap
-> Desenhe para entender quando passar *p ou p para ponteiros
*/

// protótipos:
double *aloca(int x);
double *entrada(int *t);
void imprime(double *vet, int tam);

// função alocar vetor na heap
double *aloca(int x) { // Recebe o valor do tamanho

  double *p;

  // Se o malloc não achar um espaço disponível para alocar
  if ((p = (double *)malloc(sizeof(double) * x)) == NULL) {

    /* malloc e calloc devolve um ponteiro void pq ele não sabe o que vc vai
     colocar lá dentro do espaço que vc pediu pra ele alocar */
    printf("Sem memória disponível");
    exit(1); // Sai do programa retornando 1 (mostra que deu erro pro SO)
  }

  return (p); // Váriáveis p vai sumir, mas o vetor na heap fica
}

// função receber as entradas
double *entrada(int *t) {

  /* passa t por referência pois o valor que consegui pegar no scanf quero
     colocar ele em tam pra usar na função imprimir */
  printf("Digite o tamanho do vetor: ");
  scanf("%d", t); // Armazenei o tamanho em t

  double *v;

  // v vai receber o endereço que o ponteiro p guarda
  v = aloca(*t); // Quero pegar o valor do tamanho

  // preencher o vetor
  printf("Digite os elementos do vetor: ");
  for (int i = 0; i < *t; i++) {
    // v[i] pode ser usado pra ponteiro, pois é v+i (aritimética de ponteiro)
    scanf("%lf", &v[i]);
  }
  return (v); // retornei o endereço do vetor preenchido
  // perco o v
}

// função imprimir o vetor
void imprime(double *vet, int tam) {

  // passei o conteúdo de vet, não o endereço, mas posso mudar o vetor no heap
  printf("Valores do vetor:\n");
  for (int i = 0; i < tam; i++) {
    printf("%2.lf", vet[i]);
  }
}

int main(void) {

  double *vet; // Vai apontar para o vetor na heap
  int tam;

  // vet vai receber o enderço do vetor preenchido que está na heap
  vet = entrada(&tam);

  imprime(vet, tam);

  free(vet); // para não dar desperdiço de memória (leak)
  // espaço que antes estava o vetor agora está disponível

  // para o ponteiro para de apontar para algo que não sei oq o SI vai colocar
  vet = NULL;

  return 0;
}