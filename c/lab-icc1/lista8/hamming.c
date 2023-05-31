#include <stdio.h>

void decimal_to_binario(int numero, int vetor[]);
int calcular_distancia(int binario_x[10], int binario_y[10]);


int main(void)
{
    int x,y;

    scanf("%d %d", &x, &y);
    int  binario_x[10]= {0,0,0,0,0,0,0,0,0,0};
    int  binario_y[10]= {0,0,0,0,0,0,0,0,0,0};

    decimal_to_binario(x, binario_x);
    decimal_to_binario(y, binario_y);
    // binario_x = decimal_to_binario(x);
    // binario_y = decimal_to_binario(y);

    // int binario_x[10] = decimal_to_binario(x);
    // int binario_y[10] = decimal_to_binario(y);

    int distancia_hamming = calcular_distancia(binario_x, binario_y);
    
    printf("%d\n", distancia_hamming);
}

void decimal_to_binario(int numero, int vetor_binario[]) 
{
    // vetor_binario;
    int i = 0;
    while (1)
    {
        vetor_binario[9-i] = numero % 2;
        // div = decimal / 2;
        // if (div == 0) break;

        
        if (numero == 0) break;
        numero = numero / 2;
        i++;
    }
    for (int j = 0; j < 10; j++)
    {
        // printf("%d ", vetor_binario[j]);
    }
    
}

int calcular_distancia(int binario_x[10], int binario_y[10])
{
    int distancia = 0;
    // int valid = 0;
    for (int i = 0; i < 10; i++)
    {   
        
        if (binario_x[i] != binario_y[i] ) distancia++;
    }

    return distancia;
}