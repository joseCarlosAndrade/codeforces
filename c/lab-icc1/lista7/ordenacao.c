#include<stdio.h>

int main(void)
{   
    int N,numero;
    int vetor[1000];

    scanf("%d", &N);
    vetor[N] = -1;

    for (int i = 0; i < N; i++) {
        scanf("%d", &numero);
        vetor[i] = numero;

    }

    for (int i = 0; i < N; i ++)
    {
        for (int j = 1; j < N; j++)
        {
            if (vetor[j] < vetor[j-1])        
            {
                int temp = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = temp;
            }
        }
    }

    for (int i = 0; i <N; i++)
    {
        printf("%d ", vetor[i]);

    }   
    printf("\n");
}