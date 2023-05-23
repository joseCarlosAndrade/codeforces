#include <stdio.h>
#include <math.h>

// caso math.h nao defina M_PI (meu caso para minha arquitetura) definir por mim mesmo
#ifndef  M_PI
#define  M_PI  3.1415926535897932384626433
#endif

int main(void)
{   
    int N;
    float numero, vetor[1000], resultado = 0;

    scanf("%d", &N);

    vetor[N] = -1;

    for (int i = 0; i < N; i++) {
        scanf("%f", &numero);
        vetor[i] = numero;

    }


    for (int i = 0; i < N; i++)
    {   
        resultado = 0;
        for (int j = 0; j < N; j++)
        {
            resultado += (float) vetor[j]*cos((M_PI / N) *(j + 0.5) * (i) );
        }
        printf("%.4f\n", resultado);
    }

}