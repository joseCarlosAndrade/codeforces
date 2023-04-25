#include<stdio.h>
#include<math.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    float resultado1, resultado2, delta = pow(b, 2) - 4 *a *c;

    if (delta < 0)
    {
        printf("NAO EXISTE RAIZ REAL\n");
        return 0;
    }
    else if (delta == 0)
    {   
        resultado1 = -b / (2 * a );
        printf("%.3f\n", resultado1);
    }
    else
    {
        resultado1 = (-b - sqrt(delta)) / ( 2 * a);
        resultado2 = (-b + sqrt(delta)) / ( 2 * a);

        if (resultado1 <resultado2)
            printf("%.3f %.3f\n", resultado1, resultado2);
        else
            printf("%.3f %.3f\n", resultado2, resultado1);

    }
}