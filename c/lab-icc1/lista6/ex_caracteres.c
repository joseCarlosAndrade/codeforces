#include<stdio.h>

int main(void)
{
    int palavras = 1, caracteres = 0, linhas = 1;
    
    fflush(stdin);
    char a;
    char last_char, last_last;

    while (1){
        last_last = last_char;
        last_char = a;
        a = getchar();
        if (a == -1) break;
        // char a ;
        // scanf("%c", &a);    
        // if (a == 10last_char != 10 && last_char != 13) palavras++; 
        if (a == 10 && last_char == 13) {
            caracteres--;
            if (last_last != 10 && last_last != 13) {palavras++; linhas++; continue;}
             
            linhas++; 
            continue;}
        else if (a == ' ') {palavras++; continue;}
        // else if (feof(stdin)) break;
            caracteres++;
            // printf("\nchar n %d: %c, int: %d", caracteres, a, a);
    
    }

    printf("Caracteres: %d\nPalavras: %d\nLinhas: %d\n", caracteres, palavras, linhas);


}