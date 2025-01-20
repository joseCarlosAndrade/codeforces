#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int n; // Número de cidades
int s; // Cidade de início
vector<vector<int>> dist; // Matriz de distâncias
vector<vector<int>> dp; // Tabela de cache para a programação dinâmica

// Função recursiva para encontrar o custo mínimo
int tsp(int mask, int pos) {
    // Se todas as cidades foram visitadas, retornar à cidade inicial
    if (mask == (1 << n) - 1) {
        return dist[pos][s]; // Custo de voltar à cidade inicial
    }
    
    // Verificar se o valor já foi calculado
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    // Tentar visitar cada cidade não visitada
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // Se a cidade ainda não foi visitada
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    // Armazenar o resultado no cache e retornar
    return dp[mask][pos] = ans;
}

int main() {
    // Ler o número de cidades e a cidade de início
    cin >> n;
    cin >> s;

    // Redimensionar a matriz de distâncias
    dist.resize(n, vector<int>(n));
    
    // Ler a matriz de distâncias
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Inicializar a tabela de cache com -1
    dp.resize(1 << n, vector<int>(n, -1));

    // Iniciar o TSP a partir da cidade inicial
    int result = tsp(1 << s, s);
    
    // Imprimir o custo mínimo
    cout << "Custo mínimo do passeio: " << result << endl;

    return 0;
}
