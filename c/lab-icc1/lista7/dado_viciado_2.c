#include <stdio.h>
#define MAX_NUM 500

int main (void)
{
    int lados[MAX_NUM] ,face;
    int flag, frequencia[6], final_array[7], contador =0;

    for (int i =0; i< MAX_NUM; i++)
    {
        lados[i] = -1;
        if (i < 6) frequencia[i] = 0;
        if (i < 7) final_array[i] = -1;

    }


    flag = scanf("%d", &face);


    while (flag != EOF)
    {
        lados[contador] = face;

        flag = scanf("%d", &face);
        contador++;
    }

    // checar frequencia de cada numero
    for (int dado_lado = 1; dado_lado < 7; dado_lado ++)
    {
        contador = 0;
        while(1)
        {
            face = lados[contador];
            if (face == -1) break;

            if (face == dado_lado) frequencia[dado_lado-1]++;
            contador++;

        }
    }

    // montar a lista de frequencia e lados

    while (1){
        int maior_freq = 0, index = 0;

        for(int i = 0; i < 6; i++)
        {
            if (frequencia[i] > maior_freq) {
                maior_freq = frequencia[i]; 
                index = i;
                }
        }
        if (maior_freq == 0) break;

        frequencia[index] = -1;
        if( final_array[0] <= maior_freq){
            

            final_array[0] = maior_freq;

            for (int i=1 ; i< 7; i++)
            {
                if (final_array[i] == -1)
                {
                final_array[i] = index+1;
                break;
                }
            }

        }
    }

    for (int i = 1; i < 7; i++)
    {
        if (final_array[i] != -1) printf("%d\n", final_array[i]);
    }
    printf("%d\n", final_array[0]);
    // for (int i = 0; i < 6; i++) printf("%d ", frequencia[i]);
}