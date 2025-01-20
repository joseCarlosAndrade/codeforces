#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<long int> custo_ternos; // vetor que armazena custo individual de manutencao

long int custo(int i, int j) {
    return abs(custo_ternos[i] - custo_ternos[j]);
}

long int custo_minimo_total(int N) {
    vector<long int> custos_minimos(N, 0); // vetor que armazena o menor custo para chegar ate o terno i

    custos_minimos[0] = 0;
    custos_minimos[1] = custo(0, 1);

    for ( int i = 2; i < N; i++) {
        // custo para chegar no terno i vai ser:
        // o minimo entre chegar do terno i-1 ou i-2
        custos_minimos[i] = min(
            custo(i,i-1) + custos_minimos[i-1],
            custo(i, i-2) + custos_minimos[i-2]);
    }

    return custos_minimos[N-1]; // chegar no terno final
}


int main(int argc, char ** argv) {
    int N;
    cin >> N;

    for (int i = 0 ; i < N; i++) {
        long int a;
        cin >> a;
        custo_ternos.push_back(a);
    }

    cout << custo_minimo_total(N);
}