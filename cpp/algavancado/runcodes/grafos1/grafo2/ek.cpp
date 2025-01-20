#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define V 100


using namespace std;

/*
int grafo[V][V] = {{0,16,13,0,0,0},
				   {0,0,10,12,0,0},
				   {0,4,0,0,14,0},
				   {0,0,9,0,0,20},
				   {0,0,0,7,0,4},
				   {0,0,0,0,0,0}};


*/
int grafo[V][V] = {{0,10,0,4,0,0},
				   {0,0,13,0,4,0},
				   {0,0,0,0,0,10},
				   {0,0,4,0,0,0},
				   {0,0,0,0,0,4},
				   {0,0,0,0,0,0}};

/*
int grafo[V][V] = {{0,3,2,0},
				   {0,0,5,2},
				   {0,0,0,3},
				   {0,0,0,0}};

*/

int rgrafo[V][V];
int pai[V];


void printGrafo(int g[V][V], int tam){
		printf("\n");

	for (int i = 0; i < tam; ++i){
		for (int j = 0; j < tam; ++j)
			printf("%3d", g[i][j]);
		printf("\n");
	}
}


void printVet(int *v, int tam, string tit){
	cout << tit << ": ";
	for (int i = 0; i < tam; ++i)
		printf("%d  ", v[i]);
	printf("\n");
}

bool caminho(int s, int t){
	queue<int> q;
	q.push(s);
	pai[s] = -1;

	int visitado[V];
	memset(visitado, 0, sizeof visitado);
	visitado[s] = 1;

	while (!q.empty()){
		int u = q.front(); q.pop();
		
		// para todo v adj a u
		for (int v = 0; v < V; ++v){
			// so entra na fila se tiver residuo e NAO visitado..
			if (rgrafo[u][v]>0 && visitado[v] == 0) {
				q.push(v);
				pai[v] = u;
				visitado[v] = 1;
			}
		}
	}
	printVet(pai,t+1, "Pai");
	printVet(visitado,t+1, "Vis");

	// verifica se tem caminho de s para t
	return (visitado[t] == 1);
}


int ek(){
	int u,v;

	// copia grafo original no grafo residual...
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			rgrafo[i][j] = grafo[i][j];

	int s = 0;
	int t = 5;
	//int t = 3;

	int maxFlow = 0;

	printGrafo(rgrafo,6);
	while (caminho(s,t)){
		int gargalo = 100000;
		// calcular o gargalo....
		for (int v = t; v!=s; v = pai[v]){
			u = pai[v];
			gargalo = min(gargalo, rgrafo[u][v]);
		}
		printf("Gargalo: %d\n", gargalo);

		// Atualiza o forward e backward edges...
		for (int v = t; v!=s; v = pai[v]){
			u = pai[v];
			rgrafo[u][v] -= gargalo;
			rgrafo[v][u] += gargalo;
		}
		maxFlow += gargalo;
		printGrafo(rgrafo,6);
	}

	return maxFlow;

}


int main(int argc, char const *argv[])
{
	printf("O Flxuo maximo no grafo eh %d\n", ek());
	return 0;
}
