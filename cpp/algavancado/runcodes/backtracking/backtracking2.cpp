#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> farmacias_adjacentes[25];
int ruas_visitadas[25][25]; // representa as ruas que ja foram visitadas

int caminho_max;

void solve(int no, int caminho) {
    caminho_max = caminho_max > caminho ? caminho_max : caminho; // pegando o maximo entre caminho_max e caminho

    for(int n : farmacias_adjacentes[no]) {
        // para todas as farmacias adjacentes a no:

        if (ruas_visitadas[no][n] == 0) { // caso esta rua nao foi visitada ainda
            ruas_visitadas[no][n] = 1;
            ruas_visitadas[n][no] = 1; // visitando
            solve(n, caminho+1);

            ruas_visitadas[no][n] = 0;
            ruas_visitadas[n][no] = 0; // desvisitando

        }
    }

}

int main(int argc, char **argv) {
    int n, m;

    while(cin >>n) {

        if (!n) return 0;

        cin >> m;

        for (int i = 0; i< m ; i++) {
            int p1, p2;
            cin >> p1 >> p2;

            // adicionando relacoes entre os nos p1 e p2
            farmacias_adjacentes[p1].push_back(p2);
            farmacias_adjacentes[p2].push_back(p1);
        }
        
        caminho_max = 0;

        // começando por cada no
        for (int i = 0; i < n; i ++) {
            // zerando vetor de visitados
            memset(ruas_visitadas, 0, sizeof(ruas_visitadas));
            solve(i, 0);
        }

        cout << caminho_max << endl;

        for (int i = 0; i < 25; i++) {
            farmacias_adjacentes[i].clear();
        }
    }
}