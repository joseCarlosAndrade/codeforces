#include <stdio.h>

int main(void)
{
    int x,y, combinado[100];

    for (int i = 0; i < 100; i++)
    {
        combinado[i] = -10000;
    }

    scanf("%d %d", &x, &y);
    int  contador = 0;

    while(x)
    {  
            scanf("%d", &combinado[contador]);
            contador += 2;
            // if (contador <yi-1)
            // contador += 2;
            // else contador++;
            
            x--;
        
    }
    int contador_y = 0;
    if (y) contador_y = 1;
    while(y){

            scanf("%d", &combinado[contador_y]);
            contador_y += 2;

            // if (contador <xi-1)
            // contador += 2;
            // else contador++;
            
            y--;
        
    }

    if (contador_y > contador) contador = contador_y;

    for (int i=0; i < contador; i++) 
    {
        if (combinado[i] == -10000) continue;
        printf("%d ", combinado[i]);
    }

    if(contador>1)  printf("\n");
}