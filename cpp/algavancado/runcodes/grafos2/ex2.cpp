#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

// uisando referencia de vetores e pilhas para nao usar global
// dfs1: faz a primeira dfs para preencher a pilha
void dfs1(int node, vector<int> adj[], vector<bool>& visited, stack<int>& order) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            
            dfs1(neighbor, adj, visited, order);
        }
    }
    order.push(node);
}

// dfs2: faz a segunda dfs para verificar se o grafo é fortemente conexo
// relaiza a dfs no grafo transposto
void dfs2(int node, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {

            dfs2(neighbor, adj, visited);
        }
    }
}

// isStronglyConnected: verifica se o grafo é fortemente conexo
bool isStronglyConnected(int N, vector<int> adj[], vector<int> adjT[]) {
    vector<bool> visited(N + 1, false);
    stack<int> order;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, order);
        }
    }

    fill(visited.begin(), visited.end(), false);

    int components = 0;
    while (!order.empty()) {
        int node = order.top();
        order.pop();

        if (!visited[node]) {
            components++;

            dfs2(node, adjT, visited);
        }
    }

    return (components == 1);
}

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;

        // condicao de parada
        if (N == 0 && M == 0) break;

        vector<int> adj[N + 1], adjT[N + 1];

        // leitura do grafo
        for (int i = 0; i < M; i++) {
            int u, v, r;
            cin >> u >> v >> r;
            adj[u].push_back(v);
            adjT[v].push_back(u);

            if (r == 2) { // reciprocidade!
                adj[v].push_back(u);
                adjT[u].push_back(v);
            }
        }

        if (isStronglyConnected(N, adj, adjT)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
