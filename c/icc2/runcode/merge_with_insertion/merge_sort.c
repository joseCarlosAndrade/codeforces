#include "stdio.h"
#include "stdlib.h"
#define N 8



void insert_sort(int *arr, int come, int fim){
     
     for (int i = come+1; i < fim; i++)
     {
       for (int j = i - 1; j >= 0; j--)
       {
            if (arr[i] < arr[j]){
                int temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
       }
       
     }

     for ( int u =0 ; u <= fim-come; u++) {
	printf("i: %d ", arr[u]);
     }
     printf("\nInsertion ^^ indexes: come: %d, fim: %d\n", come, fim);
}

void merge( int *arr, int c, int m, int f) {
	int i = c; // comeco da subarray da esquerda
	int j = m+1; // comeco da subarray da direita

	int temp_left[m-i+1];
	int temp_right[f-j+1];

	for ( int o = 0; o <= m; o ++) {
		temp_left[o] = arr[o+c]; 
	}
	for ( int u = m+1; u <= f; u ++) {
		temp_right[u-(m+1)] = arr[u]; 
	}

	int index_arr = 0;
	while ( i <= m || j <= f) {
		if ( i <=m && j <= f) {
			// ambos i e j ainda possuem 
			if (temp_left[i] > temp_right[j-(m+1)]) {
					arr[index_arr++] = temp_left[i];
					i++;
				}
			else {
				arr[index_arr++] = temp_right[j-(m+1)]; 
				j++;
			}
		}

		else if (i>m) {
			// i estourou, rodar apenas elementos de j
			arr[index_arr++] = temp_right[j-(m+1)];
			j++;
		}

		else if (j > f) {
			// j estourou, rodar apenas elementos de i
			arr[index_arr++] = temp_left[i];
			i++;
		}

	}
}


void merge_sort(int * arr, int come , int fim, int k){
     if ((fim - come)+1 <= k){
        insert_sort(arr, come,fim);      
        return;
    }

     int meio = (fim+come)/2;
     
     
     merge_sort(arr,come,meio,k);
     merge_sort(arr,meio+1,fim,k);
     merge(arr, come, meio, fim);

}



int main(){

int* arr1 =(int*) malloc(sizeof(int)* N );
    if (arr1 ==NULL){exit(1);}

int arr2[N] = {2,8,7,3,0,9,9,9}; /// array auxiliar para toda vez que testar não precisar escrever

for (int  i = 0; i < N; i++)
{
    arr1[i] = arr2[i];
}

merge_sort(arr1,0, N-1, 5);

for (int i = 0; i < N; i++)
{
    printf("%d ", arr1[i]);
}

free(arr1);


}
