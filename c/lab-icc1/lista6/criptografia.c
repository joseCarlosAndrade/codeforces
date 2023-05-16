#include<stdio.h>


int main(void)
{
    // char palavra[20];

    // while (scanf("%16s", palavra) != EOF)
    // {
    //     printf("%s", palavra);
    // }
    char a;
    int n_linhas = 1, n_caracteres_atual = 0, cypher;
    char last;

    while (1)
    {
        last = a;
        a = getchar();
        // printf("final: %d", a);
        if (a == -1 ){break;};
        
        // if (last == 10 || last == 13) 
        {if (a == 10 && last == 13) { n_caracteres_atual =0; n_linhas++;  continue;};
        
        }
        n_caracteres_atual++;

        cypher = a + n_caracteres_atual;
        cypher *= n_linhas;
        if (a >= 65 && a <= 90)
        {
            printf("%c", (cypher%26) + 65);
            continue;
        }
        else if (a >= 97 && a <= 122)
        {
            printf("%c", (cypher%26) + 97);
            continue;
        }

        printf("%c", a);
        // if ((a >= 65 && a <= 90 ) || (a >= 97 && a <= 122))
        // {

        // }
    }
   


}