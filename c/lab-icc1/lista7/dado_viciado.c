#include<stdio.h>

#define MAX_LADOS 100


int main(void)
{
    int face, flag, contador=0;
    int lados[100] = {-1};
    int frequencia[7] = {-1};
    int cont, numero, frequencia_atual, index_maior = 1;

    for (int i =0; i< MAX_LADOS; i++)
    {
        lados[i] = -1;

        if (i >7) continue;
        frequencia[i] = -1;
    }
    frequencia[0] = -1;

    flag = scanf("%d", &face);

    while (flag != EOF)
    {
        lados[contador] = face;

        flag = scanf("%d", &face);
        contador++;
    }
   
    cont = 0;
    while (1) {
        if (lados[cont] == -1) break;
        printf("%d ", lados[cont]);
        cont ++;
    }   
    printf("finish\n");

    for (int face = 1; face <= 6; face++)
    {   
       cont = 0;
       frequencia_atual = 0;

        while(1)
        {
            numero = lados[cont];
            // printf("%d ", numero);
            if (numero == -1) break;

            if (face == numero) frequencia_atual++;

            
            if (frequencia[0] == frequencia_atual)
            {
                // frequencia[0] = frequencia_atual;
                int equal = 0;
                for (int k = 1; k < 7; k++) {
                    if (numero == frequencia[k]) equal = 1;
                    
                }
                // numero encontrado ja esta na lista
                if (equal) ;
                else {
                    for (int k = 1; k < 7; k++) {
                        if (frequencia[k] == -1) frequencia[k] = numero;
                    }
                }
                // if (equal) frequencia[index_maior++] = numero;
            }
            else if (frequencia[0] < frequencia_atual)
            {
                index_maior = 1;
                for (int f = 1; f < 7;f ++) frequencia[f] = -1;
                frequencia[0] = frequencia_atual;
                frequencia[index_maior] = numero;
            }

            cont++;
        }
        
    }


    for (int i = 6; i >= 0; i--)
    {
        if (frequencia[i] == -1) continue;
        printf("%d\n", frequencia[i]);
    }


    // testa cada numero 1 a 6
    // percorre a lista de lados e adiciona o nuimero que aparece mais vezes
}