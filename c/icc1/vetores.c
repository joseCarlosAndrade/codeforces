#include<stdio.h>

int main(void)
{
    const unsigned int x, y;

    scanf("%d %d", &x, &y);

    int vetor_x[x+1];
    int vetor_y[y+1];
    vetor_x[x] = -1;
    vetor_y[y] = -1;

    for (int i=0; i < x; i++)
    {
        scanf("%d", vetor_x[i]);
    }

    for (int j=0; j < x; j++)
    {
        scanf("%d ", vetor_y[j]);
    }

    int i = 0;
    while (1)
    {
        printf("%d %d\n", vetor_x[i], vetor_y[i]);
        i++;
    }
}