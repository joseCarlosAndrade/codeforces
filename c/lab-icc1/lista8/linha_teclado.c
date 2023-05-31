#include <stdio.h>

int esta_na_linha(char * palavra, char * linha);

int main(void)
{
    char *linha_1 = "qwertyuiop";
    char *linha_2 = "asdfghjkl";
    char *linha_3 = "zxcvbnm";
    char string[1000];

    int flag;

    while (1)
    {
    flag = scanf("%1000s", string);
    if (flag == -1) break;

    if (esta_na_linha(string, linha_1) || esta_na_linha(string, linha_2) || esta_na_linha(string, linha_3)) printf("%s\n", string);

    
    }
    

}

int esta_na_linha(char * palavra, char * linha)
{
    int i = 0, j = 0;
    char linha_char = *(linha); // quando char == 0 -> fim da string
    char palavra_char = *(palavra);
    if (palavra_char < 97 && palavra_char != 0) palavra_char += 32;

    // printf("%d ", linha_char);
    while (palavra_char != 0)
    {   
        int contem = 0;
        j = 0;

        while (linha_char != 0)
        {
            

            if (palavra_char == linha_char){
                contem = 1;
                // printf("%c %c %d, compare: %d \n", linha_char, palavra_char, contem, linha_char == palavra_char);

                linha_char = *(linha);
                break;
            }
            // printf("%c %c %d, compare: %d \n", linha_char, palavra_char, contem, linha_char == palavra_char);

            linha_char = *(linha + ++j);
        }

        if (contem == 0) return 0;
        // printf("%c ", linha_char);
        palavra_char = *(palavra + ++i);
        if (palavra_char < 97 && palavra_char != 0) palavra_char += 32;

    }



    return 1;
}