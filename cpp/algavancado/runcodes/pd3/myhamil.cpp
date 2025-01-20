#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> distancia;
vector<vector<int>> MEMO;
int s; // cidade inicial
int n; // numero de cidades

int solve(int mask, int pos) {
    if (mask == (1 << n) -1) return distancia[pos][s]; // visitou todas as casas

    if (MEMO[mask][pos] != -1) return MEMO[mask][pos]; // ja calculou esta etapa

    int dist = INT_MAX;

    for (int c = 0; c < n; c++) {
        // para tdas as cidades
        if ((mask & (1 << c)) == 0) { // ex: mask: 00101, c: 00100; & = 1, ja visitou
            int ndist = distancia[pos][c] + solve(mask | (1 << c), c);
            dist = min(ndist, dist);
        }
    }

    return MEMO[mask][pos] = dist;
} 

int main(int argc, char ** argv) {

    cin >> n;
    cin >> s;
    distancia.resize(n, vector<int>(n)); // redimensionando distancias
    MEMO.resize(1 << n, vector<int>(n, -1)); // redimensinoando e setando memo como  -1

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            cin >> distancia[i][j];
        }
    }   

    cout << solve (1 << s, s);

}

