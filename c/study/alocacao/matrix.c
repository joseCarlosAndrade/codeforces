#include<stdio.h>
#include<stdlib.h>

/*
Alocando matriz de forma dinamica com numero de linhas e colunas como parametros*/
int  **alocaMatriz1(int nrows, int ncols)
{
    // aloca um ponteiro -> vetor de linhas em que cada elemento aloca um ponteiro de colunas
    int **matrix = (int **) malloc(sizeof(int *) * nrows);

    for (int i = 0; i < nrows; i++)
    {
        matrix[i] = (int *) malloc(sizeof(int) * ncols);
    }

    return matrix;
}

void desalocarMatriz1(int ** matrix, int nrows)
{
    for (int i = 0; i < nrows; i++)
    {
        free(matrix[i]);
    }

    free(matrix);
}

int main(int argc, char *argv[])
{
    int ** matrix;

    matrix = alocaMatriz1(5, 10);

    printf("%d\n", matrix[1][2]);

    desalocarMatriz1(matrix, 5);
    return 0;
}