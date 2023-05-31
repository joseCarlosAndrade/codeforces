#include<stdio.h>

void preencher_vetor(int vetor[], int N);
int encontrar_desaparecido(int vetor[], int N);


int main(void)
{
    int vetor[1000000], N, numero_desaparecido;

    scanf("%d", &N);
    preencher_vetor(vetor, N);

    numero_desaparecido = encontrar_desaparecido(vetor, N);
    printf("Numero desaparecido: %d\n", numero_desaparecido);
}


void preencher_vetor(int vetor[], int N)
{
    for (int i = 0; i< N-1; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

int encontrar_desaparecido(int vetor[], int N)
{
    long soma = 0;

    for (int i = 0; i < N; i++)
    {
        soma += i+1;
        if (i == N-1) continue;
        soma -= vetor[i];
    }

    return soma;
}
