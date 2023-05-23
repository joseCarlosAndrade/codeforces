#include <stdio.h>

int main(void)
{
    int N, numero;
    int divisores_menor = 0, divisores=0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &numero);

        if (numero == 1) {
            printf("SIM\n");
            continue;
        }

        divisores = 0;

        // descobrir quantidade de divisores de numero
        for (int n = 1; n <= numero; n++)
        {
            if (numero%n == 0) 
        {
                divisores++;
            }
        }

        
        // loop de 1 a N-1 -> descobrir quantidade de divisores de cada um e comparar com resultado anterior
        // if divisores_menor >= divisores -> NAO 
        
        for (int k = 1; k < numero; k++)
        {
            divisores_menor = 0;
            for ( int d = 1; d <= k; d++)
            {
                if (k%d ==0) divisores_menor++;
            }
            if (divisores_menor >= divisores)
            {
                printf("NAO\n");
                break;
            }
            else if (k == numero-1){
                printf("SIM\n");
            }
        }
    }
}