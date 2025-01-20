#include<iostream>
#include<bits/stdc++.h>

using namespace std;



int moves[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
// int solutions = 0;
vector<int> solutions;

bool is_valid(int x, int y, int M, int N, int labirinto[]) {
    if ( x >= 0 && x < M && y >= 0 && y <N) {
        // dentro do labirinto. verificando se posicao ja esta ocupada
        if (labirinto[x + y*M] == 0) return true;
    }

    return false;
}

int main () {
    int M = 5, N = 5;

    int labirinto[M*N+1];

    memset(labirinto, 0, sizeof(labirinto));

    labirinto
}

/*
{0 - 0 0 0,
 0 - 0 - 0,
 0 - 0 - 0,
 0 - 0 - 0,
 0 0 0 - 0}
*/
/*
1 0
1 1
1 2
1 3
3 1
3 2
3 3
3 4
*/