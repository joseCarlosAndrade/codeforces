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

void solve(int labirinto[], int M, int N, int x, int y, int count) {
    if (x == M-1 &&  y == N-1) {
        // solutions++;
        solutions.push_back(count);
        return ;
    }

    for (int i = 0; i < 4; i++) {
        int nx = moves[i][0] + x;
        int ny = moves[i][1] + y;

        // verificar nx e ny
        if (is_valid(nx, ny, M, N, labirinto)) {
            labirinto[nx + ny*M] = 1;
            solve(labirinto, M, N, nx, ny, count+1);
            labirinto[nx + ny*M] = 0;
        }
    }
}   

int main(int argc, char **argv) {
    int M, N;

    cin >> M >> N;

    int labirinto[M * N +1]; 

    memset(labirinto, 0, sizeof(labirinto));
    labirinto[0] = 1;

    int x, y;

    while (cin >> x >> y ) {

        labirinto[x + y*M] = -1;
    }

    solve(labirinto, M, N, 0, 0, 0);

    sort(solutions.begin(), solutions.end());

    cout << solutions.size() << " " << solutions[0];
    


    return 0;
}