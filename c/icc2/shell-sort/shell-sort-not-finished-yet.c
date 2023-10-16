#include<stdio.h>
#include<stdlib.h>

#define SIZE 7

void shell_sort(int n, int vec[n]);

int main(void) {
	int vec[SIZE]= {14, 3, 12, 4, 1, 5 ,2};

	for ( int i = 0; i < SIZE; i ++ ){
		printf("%d ", vec[i]);
	}

	shell_sort(SIZE, vec);
	printf("\n");
	
	for ( int i = 0; i < SIZE; i ++ ){
		printf("%d ", vec[i]);
	}
}
// 25 57 48 37 12 92 86 33

void shell_sort(int n, int vec[n]) {
	
	for (int h = 5; h >= 1; h = h-2) {
	
		// 0 1 2 3 4 5 6 7
		//           h
		//             h
		//             	 h
		for (int i = h; i <n; i++) {
			
			int j;
			// 0 1 2 3 4 5 6 7
			//           ij
			// j         i  p/ h=5
			//
			// 0 1 2 3 4 5 6 7
			//             i
			// j     j     j p/ h=3	
			//
			// Enquanto i aumenta linearmente a partir da iteracao de h, j diminui em h a cada iteracao sua para comparacao
			//
			int temp = vec[i];
			for(  j = i; j >= h && vec[j-h] > temp ; j -=h) {
					vec[j] = vec[j-h];

			}
			vec[j] = temp;
		}
	}

}


