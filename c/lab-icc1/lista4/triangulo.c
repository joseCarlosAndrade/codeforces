#include<stdio.h>

int main(void)
{
    int a, b, c, soma;

    scanf("%d %d %d", &a, &b, &c);

    // variavel para armazenar a soma de todos os lados para facilitar as contas posteriormente
    soma = a + b + c;
    if ( (soma - a <= a) || (soma -b <= b) || (soma-c <= c))
    {
        printf("INVALIDO\n");
        return 0;
    }

    if ((a ==b) || (b == c) || (a == c))
    {
        // a unica situaçao em que 3*a == soma é quando é equilatero
        if (!(soma - 3*a)){
            printf("EQUILATERO\n");
            return 0;
        }
        else{
            printf("ISOSCELES\n");
            return 0;

        }

    } 
    // caso nenhum lado seja igual a outro
    else{
        printf("ESCALENO\n");
    }
    
}