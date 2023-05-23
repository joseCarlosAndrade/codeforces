#include<stdio.h>

int main(void)
{
    int N,numero, a ,b, soma = 0;
    int vetor[1000];

    scanf("%d", &N);
    vetor[N] = -1;

    for (int i = 0; i < N; i++) {
        scanf("%d", &numero);
        vetor[i] = numero;

    }

    scanf("%d %d", &a, &b);

    for (int i = a ; i <=b; i++)
    {
        soma += vetor[i];
    }
    printf("%d\n", soma);
}