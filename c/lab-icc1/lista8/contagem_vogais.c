#include<stdio.h>

int main(void)
{
    char palavra[100];
    int i = 0, vogais =0 ;

    scanf("%s100", palavra);

    while (palavra[i] != 0)
    {
        // char a = palavra[i];

        switch (palavra[i])
        {
        case 65:
        case 69:
        case 73:
        case 79:
        case 85:
        case 97:
        case 101:
        case 105:
        case 111:
        case 117:
            vogais++;
            break;
        default:
            break;
        }

        i++;
    }

    if (!vogais) printf("A palavra \"%s\" nao contem vogais.\n", palavra);
    else 
    {
        if (vogais>1)
        printf("A palavra \"%s\" contem %d vogais.\n", palavra, vogais);

        else
            printf("A palavra \"%s\" contem %d vogal.\n", palavra, vogais);

    }

}