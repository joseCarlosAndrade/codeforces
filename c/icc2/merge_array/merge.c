#include<stdio.h>
#include<stdlib.h>

#define N1 7
#define N2 5 

void merge(int v1[], int n1, int v2[], int n2, int v3[]);

int main(int argc, char ** argv)
{
	int v1[N1] = {1, 2, 3, 4, 5, 6 ,6};
	int v2[N2] = { 10, 11, 12, 12, 13};

	int v3[N1+N2];

	merge(v1, N1, v2, N2, v3);

	for (int i = 0; i < N1+N2; i++)
	{
		printf("%d ", v3[i]);
	}
}

void merge(int v1[], int n1, int v2[], int n2, int v3[])
{
	if (n1 == n2) if (n1 == 0) return;
	
	int temp;
	if (n1 >0 && n2> 0) {
		if (v1[n1-1] >= v2[n2-1]) { // se o ultimo elemento alterado mais p esquerda de v1 for maior igual que o de v2
	 		temp = v1[n1-1];
			n1--;
		}
		else {
			temp = v2[n2-1];
			n2--;
		}

	}
	else if (n1 <= 0) {
		temp = v2[n2-1];
		n2--;
	}
	else {
		temp = v1[n1-1];
		n1--;
	}
	
	v3[n1+n2] = temp;
	merge(v1, n1, v2, n2, v3);
}
	
