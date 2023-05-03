#include<stdio.h>

int main(void)
{
    double angulo, seno, nom;
    double denom;
    int sinal =1;

    scanf("%lf", &seno);
    nom = seno  ;
    angulo = nom;
    for (int i = 3; i < 150*2; i += 2)
    {
        
        denom = i;

        for (int j = 1; j<=2; j++)
        {
            nom *= seno;
        }
        for (int o = 1; o < i; o++)
        {
            // nom *= seno;
            denom = denom*(i-o);
        }
        if (sinal%2){
            angulo = angulo - (nom / denom);
            // printf("operaçao sub %.6f %lf %lf\n", angulo, nom, denom);
        }
        else{
            angulo = angulo + (nom / denom);
            // printf("operaçao add %.6f %lf %lf\n", angulo, nom, denom); 
        }

        // printf("nom %lf, denom: %lf\n", nom, denom);
        sinal++;
    }
    printf("%.6f\n", angulo);
}