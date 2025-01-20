#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

vector<ll> valor_fortuna;
vb visitado;

stack<int> pilha_ordem;
vector<vector<int>> grafo_original, grafo_transposto;
vi componentes_grafo[1000000];
vi componentes;
vector<ll> soma_componentes;

ll dp[1000000];

// dfs para a primeira busca no grafo original
void dfs_primeira(int vertice){

    visitado[vertice] = true;
    for (int vizinho : grafo_original[vertice]) {
        if (!visitado[vizinho])

            dfs_primeira(vizinho);
    }
    pilha_ordem.push(vertice);
    
}

// dfs para a segunda busca no grafo transposto
void dfs_segunda(int vertice, int index_componente){
    componentes[vertice] = index_componente;
    soma_componentes[index_componente] += valor_fortuna[vertice];
    for (int vizinho : grafo_transposto[vertice]) {
        if (componentes[vizinho] == -1)
            dfs_segunda(vizinho, index_componente);
    }
}

// dfs para calcular o valor máximo de fortuna em um componente
ll dfs_calcular_fortuna(int componente){
    if (dp[componente] != -1) return dp[componente];
    ll soma_maxima = 0;

    for (int vizinho_componente : componentes_grafo[componente]) {
        soma_maxima = max(soma_maxima, dfs_calcular_fortuna(vizinho_componente));

    }
    return dp[componente] = soma_maxima + soma_componentes[componente];

}

int main(){

    int n, m;
    cin >> n >> m;

    grafo_original.assign(n, vector<int>());
    grafo_transposto.assign(n, vector<int>());

    visitado.assign(n, false);
    valor_fortuna.resize(n);

    componentes.assign(n, -1);
    soma_componentes.assign(n, 0);
    
    fill(dp, dp + n + 1, -1);

    // le as fortunas
    for (int i = 0; i < n; i++){
        int valor;
        cin >> valor;
        valor_fortuna[i] = valor;
    }

    // le as arestas
    for (int i = 0; i < m; i++){
        int v1, v2;

        cin >> v1 >> v2;

        grafo_original[v1-1].push_back(v2-1);
        grafo_transposto[v2-1].push_back(v1-1);
    }

    // kosaraju: primeira dfs no grafo original
    for (int i = 0; i < n; i++){
        if (!visitado[i])
            dfs_primeira(i);

    }

    // kosaraju: segunda dfs no grafo transposto
    int index_componente_conexo = 0;
    while(!pilha_ordem.empty()) {
        int v = pilha_ordem.top();

        pilha_ordem.pop();

        if (componentes[v] == -1){
            dfs_segunda(v, index_componente_conexo);
            index_componente_conexo++;
        }

    }

    // gera o dag a partir dos componentes fortemente conexos
    for (int i = 0; i < n; i++){
        for (int vizinho : grafo_original[i]) {

            if (componentes[i] != componentes[vizinho]) {
                componentes_grafo[componentes[i]].push_back(componentes[vizinho]);
            }

        }
    }

    // calcula a fortuna máxima que pode ser obtida
    ll fortuna_maxima = 0;
    for (int i = 0; i < index_componente_conexo; i++){

        ll fortuna_componente = dfs_calcular_fortuna(i);

        fortuna_maxima = max(fortuna_maxima, fortuna_componente);
    }

    cout << fortuna_maxima << endl;

    return 0;
}
