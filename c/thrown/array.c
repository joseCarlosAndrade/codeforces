#include<stdio.h>

int return_size(int *array);
int return_size_last(int *array);


int main(void)
{
    int a[10] = {1,1,1,1,1,1,1,1,1,1};
    int array[10] = {1,1,1,1,1,0,0,0,0,0};

    // acessando arrays com index invertido
    // for (int i = 0; i < 100; i++){
    //     printf("%c\n", i[a]);

    // }

    // pega o tamanho do array
    printf("%ld", sizeof(a));
    printf("\n Size of array a: %d\n", return_size_last(a));

    int array_size = sizeof(array);
    int element_size;

    if (array_size ==0) 
    return 0;

    element_size = sizeof(array[0]);
    printf("\n%d %d", array_size,element_size);
    printf("\n%d", array_size/element_size);
}

int return_size(int *array )
{
    int array_size = sizeof(array);
    int element_size;

    if (array_size ==0) 
    return 0;

    element_size = sizeof(array[0]);
    printf("\n%d %d", array_size,element_size);


    return array_size / element_size;
}

int return_size_last(int *array) // nao vale -> nesse escopo é apenas um ponteiro, entao sizeof() retorna tamanho do ponteiro
{
    // int count = 0;
    int i=0;
    while (1){
        if (array[i] == '\0') break;
         
         i ++;

        if (i >1000) {
            printf("Exiting, exceeded limit.");
            break;
        }
    }
    return i;
}