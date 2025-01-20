#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vii;

class Graph {
public:
    vii p;     // Vetor de pais
    vii Size;  // Vetor de tamanhos
    int maior;

    // Construtor para inicializar o grafo com 'n' nós
    Graph(int n) {
        p.resize(n);
        Size.assign(n, 1);
        maior = 1;
        for (int i = 0; i < n; ++i) {
            p[i] = i; // Inicialmente, cada nó é seu próprio pai
        }
    }

    // Método para encontrar o representante do conjunto de um elemento
    int find(int i) {
        if (p[i] == i)
            return i;
        return p[i] = find(p[i]); // Compressão de caminho
    }

    // Método para verificar se dois elementos estão no mesmo conjunto
    bool sameSet(int i, int j) {
        return find(i) == find(j);
    }

    // Método para unir dois conjuntos
    bool Union(int i, int j) {
        int x = find(i);
        int y = find(j);

        if (x == y)
            return false; // Já estão no mesmo conjunto

        if (Size[x] > Size[y]) {
            p[y] = x;
            Size[x] += Size[y];
            if (Size[x] > maior)
                maior = Size[x];
        } else {
            p[x] = y;
            Size[y] += Size[x];
            if (Size[y] > maior)
                maior = Size[y];
        }

        return true;
    }
};



int main() {


    int n, it;
    cin >> n >> it;
    Graph g(n); // Grafo com 5 nós (0 a 4)
    int conj = n;

    for (int i = 0; i < it; i++){
        int v1, v2;
        cin >> v1 >> v2;
        if (g.Union(v1-1, v2-1))
            conj--;

        cout << conj << " " << g.maior << endl;
    }

    return 0;
}

