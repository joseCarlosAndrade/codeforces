#include<stdio.h>

int main(void)
{
    int i, j;
    for (i=0, j=100; i+j >= 0; i++, j-= 2 )
    {
        printf("%d %d\n", i, j);
    }
}