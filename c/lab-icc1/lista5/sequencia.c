#include <stdio.h>

int main(void)
{
    int n, sinal =0;
    scanf("%d", &n);
    double resultado = 0;

    for (int i = 1; i<= n; i++)
    {   
        resultado += (double)1/(i) * (1 - 2*(sinal%2)); 
        // printf("a: %d\n", 1/(i) * (1 - 2*(sinal%2)));
        sinal++;
    }
    printf("%.4lf\n", resultado);
}
