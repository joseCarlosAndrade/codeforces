#include<stdio.h>

int main(void)
{
    double x, nom, denom;
    scanf("%lf", &x);

    double soma = x;
    nom = x;

    int sinal=1;

    for (int i = 3; i < 2*20; i+=2)
    {
        denom = i;
        nom = x;
        for (int j = 2; j < i; j++){
            nom *= x;
        }

        for (int o = 1; o < i; o++)
        {
            // nom *= seno;
            denom = denom*(i-o);
        }
        soma += ( nom / denom ) * (1 - 2*(sinal%2));

        // printf("%lf %lf %lf %d\n", nom, denom, soma, 1 - 2*(sinal%2));

        // * (1 - 2*(sinal%2));
        sinal++;
    }
    printf("resultado: %lf\n", soma);
}