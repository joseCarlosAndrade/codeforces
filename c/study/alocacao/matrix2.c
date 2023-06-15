#include<stdio.h>
#include<stdlib.h>

/*
Ver desenhos da memoria stack e heap no caderno
*/

void alocaMatrix2(int ***matrix, int rows, int cols)
{
    *matrix = (int **)malloc(sizeof(int*)*rows);
    for (int i = 0; i < rows; i++)
    {
        // ou (*matrix)[i]
        *(matrix+i) = (int *) malloc(sizeof(int)*cols);
    }

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

    alocaMatriz1(&matrix, 5, 10);

    printf("%d\n", matrix[1][2]);

    desalocarMatriz1(matrix, 5);
    return 0;
}