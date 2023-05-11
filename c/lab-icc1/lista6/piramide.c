#include <stdio.h>

int main(void)

{
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        // printf("")
        // for (int espaco = n; espaco > 0; espaco--)
        // {
        //     printf(" ");
        // }
        for( int espaco = 0; espaco < n-i; espaco ++)
            {
                printf(" ");
            }

        for (int aste = 0; aste < 2*i ; aste += 1)
        {
            
            printf("*");
        }
        printf("\n");
    }
}