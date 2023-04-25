#include <stdio.h>

int main(void)
{
    char caractere;
    scanf("%c", &caractere);

    if ((caractere >= 65 && caractere <= 90 ) || (caractere >= 97 && caractere <= 122))
    {
        switch (caractere)
        {
        case 65:
            // printf("Eh vogal\n");
            // break;
        case 69:
            // printf("Eh vogal\n");
            // break;
        case 73:
            // printf("Eh vogal\n");
            // break;        
        case 79:
            // printf("Eh vogal\n");
            // break;        
        case 85:
        case 97:
        case 101:
        case 105:
        case 111:
        case 117:
            printf("Eh uma vogal\n");
            break;        

        default:
            printf("Eh uma consoante\n");
        }
        return 0;
    }
    printf("Nao eh uma letra do alfabeto\n");
    return 0;
}