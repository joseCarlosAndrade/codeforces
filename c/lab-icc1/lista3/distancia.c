#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
    float x1 , y1, x2, y2, euclid, manhat;
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);

    euclid = sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) );
    manhat = fabs(x1-x2) + fabs(y1-y2);

    printf("Distancia euclidiana: %.3f\n", euclid);
    printf("Distancia Manhattan: %.3f\n", manhat);
}