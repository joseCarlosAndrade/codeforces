#include<stdio.h>
#include<stdlib.h>


int main() {
	
	int n, blusas;
	scanf("%d %d", &n, &blusas);

	int **arr = (int**) calloc(n, sizeof(int*));
	
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)calloc(blusas + 1, sizeof(int));
		
		int n_p;
		scanf(" %d", &n_p);
		for (int j =0; j < n_p; j++) {
			int b;
			scanf(" %d", &b);
			arr[i][b-1] = 1;
			arr[i][blusas] = n_p;
		}
	}

	// for (int i = 0 ; i < n ; i++) {
	// 	for (int j = 0; j < blusas+1; j++) {
	// 		printf("%d ", arr[i][j]);
	// 	}
	// 	printf("\n");
	// }

	int qnt = 0;
	for (int j = 0; j < blusas; j++) {
		if ( arr[0][j] == 0) continue; // comeca com 0, nao tem caminho
		int q = 1;

		for (int i = 1; i < n ; i ++) {
			// if ( arr[i][j] == 0) continue;
			q *= (arr[i][blusas]-arr[i][j]);
			q = q%(int)(1e9+7);
			if (q==0) break; //caminho impossivel


		}
		qnt += q;
		qnt = qnt%(int)(1e9+7);
	}

	printf("%d\n", qnt);

}
