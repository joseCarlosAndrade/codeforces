#include <stdio.h>

void redimensionar(float fator);

int main(void)
{
    int N;
    float fator;

    scanf("%d %f", &N, &fator);

    for (int i = 0 ; i < N ; i++)
    {
        redimensionar(fator);
    }
    // printf("\n");
}

void redimensionar(float fator)
{
    float x, y;

    scanf("%f %f", &x, &y);
    printf("%.2f %.2f\n", x*fator, y*fator);

}

