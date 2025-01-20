#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vii;

class Grafo {
    public:
        vii pais;     // vetor de pais
        vii tamanho;  // vetor de tamanhos dos conjuntos
        int maior_conjunto;

        // construtor para inicializar o grafo com 'n' nós
        Grafo(int n) {
            
            pais.resize(n);
            tamanho.assign(n, 1);

            maior_conjunto = 1;
            
            for (int i = 0; i < n; ++i) {
                pais[i] = i; // inicialmente, cada nó é seu próprio pai
            }
        }

        // encontrar o representante do conjunto de um elemento
        int encontrar(int i) {
            if (pais[i] == i)
                return i;
            return pais[i] = encontrar(pais[i]); // compressão de caminho
        }

        // verificase dois elementos estão no mesmo conjunto
        bool mesmoConjunto(int i, int j) {

            return encontrar(i) == encontrar(j);
        }

        // unir dois conjuntos
        bool unir(int i, int j) {

            int x = encontrar(i);
            int y = encontrar(j);

            if (x == y)
                return false; // já estão no mesmo conjunto

            if (tamanho[x] > tamanho[y]) {

                pais[y] = x;
                tamanho[x] += tamanho[y];
                
                if (tamanho[x] > maior_conjunto)

                    maior_conjunto = tamanho[x];
            } else {
                pais[x] = y;

                tamanho[y] += tamanho[x];

                if (tamanho[y] > maior_conjunto)
                    maior_conjunto = tamanho[y];
            }

            return true;
        }
};

int main() {
    int n, it;
    cin >> n >> it;

    Grafo g(n); // grafo com n nós
    int conjuntos = n; // inicializa o número de conjuntos como 'n'

    for (int i = 0; i < it; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        if (g.unir(v1 - 1, v2 - 1))

            conjuntos--; // decrementa o número de conjuntos

        cout << conjuntos << " " << g.maior_conjunto << endl; // imprime o número de conjuntos e o tamanho do maior
    }

    return 0;
}
