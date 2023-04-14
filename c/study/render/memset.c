#include<math.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    char a[100][100];
    memset(a, '$', sizeof(char)*100*100);

    for (int j = 0; j < 100; j++)
    {
        for (int i = 0 ; i <100; i++)
        {
            putchar(a[i][j]);
        }
        putchar('\n');
    }
}