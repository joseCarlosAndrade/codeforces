#include <stdio.h>
#include<stdlib.h>

int ctbits(int v){
    int ans=0;
    for(int i=1;i<=v;i*=2){
        if(i&v){
            ans++;
        }
    }
    //printf("%d %d\n", v, ans);
    return ans;
}

void bubble_sort(int n, int v[n]) {

   // bubble sort 
    while(1){
        int swapped=0;
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]){
                int aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                swapped=1;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main ()
{
    int n;
    int tam[100];
    int buckets[100][1010];
    int v[1010];
    
    scanf("%d", &n);
    
    for(int i=0;i<11;i++){
        tam[i]=0;
    }
    
    for(int i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
   
    

    // separando em buckets
    for(int i=0;i<n;i++){
        int bits=ctbits(v[i]);
        buckets[bits][tam[bits]]=v[i];
        tam[bits]++;
    }

    // ordenando cada bucket
    for(int i=1;i<11;i++){
        if(tam[i]){
	    
		bubble_sort(tam[i], buckets[i] );
        }
    }
    
    // printando cada bucket ordenado
    for(int i=1;i<11;i++){
        if(tam[i]){
            for(int j=0;j<tam[i];j++){
                printf("%d ", buckets[i][j]);
            }printf("\n");
        }
    }
    
    // concatenando vetor final
    /* 
     *
     *
     * */

    for(int j = 0; j < n ; j++) {
       int max; 
	   // escolhendo um valor maximo inicial para evitar acessar index -1 
	for(int o = 0; o<11; o++) {
		if(tam[o]) {
			max = buckets[o][tam[o]-1];
			break;
		}
	}

	int max_o;
	for (int o = 0; o <11; o++) {
		if (tam[o] && buckets[o][tam[o]-1] >= max) {

			max = buckets[o][tam[o]-1];
			max_o = o;
			//printf("m %d; ", max);
		
		}
    	} 
	tam[max_o]--;
	v[n-1-j] = max;

    }

    // printando vetor final
    for(int i=0;i<n;i++){
        printf("%d ", v[i]);
    }printf("\n");

  return 0;
}
