#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int MOVES[3][2] = {{1, 0}, {0, 1}, {1, 1}}; // movimentos possiveis
long long MEMO[1005][1005];

vector<char> tabuleiro;
int N;

long long return_mod(long long a, long long b, long long c ) {
    long long t = (a+b) %1000000007;
    return (t + c)%1000000007;
}

long solve(int i, int j) {
    if (i < 0 || j  < 0) return 0;
    
    if (tabuleiro[i*N + j] == '*') return MEMO[i][j] = 0; // caminhos invalidos

    if (i == 0 && j == 0) return MEMO[i][j] = 1; // chegou no começo

    if (MEMO[i][j] != -1) return MEMO[i][j]; // ja calculou

    
    return (MEMO[i][j] = return_mod(solve (i-1, j) , solve(i, j -1) , solve(i-1, j-1)));
}

int main(int argc, char ** argv) {

    cin >> N;

    memset(MEMO, -1, sizeof(MEMO));

    for (int i = 0 ; i < N*N ; i ++) {
        char c;
        cin >> c;
        tabuleiro.push_back(c);
    }

    cout << solve(N-1, N-1);
}
