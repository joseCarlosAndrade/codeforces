#include <stdio.h>
#include <math.h>

int main(void)
{
    for (int a = 1 ; a < 10; a++){
        // primeiro digito dos milhares precisa começar em 1 para nao comparar 0xxx
        for (int b = 0; b < 10; b++)
        {
            for (int c = 0; c < 10; c++)
            {
                for (int d = 0; d < 10; d++)
                {
                    // numero = abcd
                    int numero = a*1000 + b*100 + c*10 + d;
                    double soma = a*10 + b + c*10 + d;
                    if (sqrt(numero) == soma){
                        printf("%d\n", numero);
                    }
                }
            }
        }
    }
}