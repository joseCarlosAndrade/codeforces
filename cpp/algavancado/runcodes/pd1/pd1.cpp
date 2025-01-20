// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;

// vector<long int> custo_ternos;
// int custo_total = 0;
// long int N;

// long int solve (long int i, long int custo) {
//     if (i < 0) return 0;

//     if (i ==0) return custo_ternos[0]; // sempre vai pegar o primeiro terno
    
//     long int novo_custo = abs(custo_ternos[i] - custo ); // somando custos

//     if  (i == 1) return (abs(solve(0, custo)-custo));

//     return min( solve(i-1, custo_ternos[i]) + novo_custo, solve (i-2, custo_ternos[i]) + novo_custo );
// }

// // long int solve2(int i) {
// //     if (i == 0) return INFINITY;
// //     if (i == 1) return abs(custo_ternos[1] - custo_ternos[0]);


// //     return min(solve2(i-1), solve2(i-2));
// // }

// long int solve3(int i , int last_index) {
//     if (i >= N) return 0;

//     return min(solve3(i+1, i) + abs(custo_ternos[last_index]-i), solve3(i+2, i) + abs(custo_ternos[last_index]-i));
// }

// long int solveRec() {
//     return min(solve3(1, 0), solve3(2, 0));
// }

// long int custo(int i, int j) {
//     return abs(custo_ternos[i] - custo_ternos[j]);
// }

// // long int solve4(int i) {
// //     if (i==0) return min(custo(0, 1), custo(0, 2));
// //     if (i == N-2) return custo(i, i+1); // condicao de parada
    

// //     return ()

// // }

// long int solve4(int i, int last_i) {
//     if (i == N-2)   return custo(N-1, N-2);

//     if (i == N-3) return min(custo(N-1), )
    
//     return (
//         min (
//             solve4(i+1, i), 
//             solve4(i+2, i) 
//             )
//         );
// }

// int main(int argc, char ** argv) {
//     cin >> N;

//     for (int i = 0; i < N; i++) {
//         long int custo;
//         cin >> custo;

//         custo_ternos.push_back(custo);
//     }

//     long int custo_minimo = solveRec();
//     cout << custo_minimo;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long int menorCustoTernos(const vector<long int>& d) {
    int n = d.size();
    
    // Vetor dp para armazenar o menor custo até cada terno
    vector<long int> dp(n, 0);
    
    // Condição inicial: custo para começar com o primeiro terno é zero
    dp[0] = 0; // dp[0] representa o terno 1
    
    // Para o segundo terno, o custo é simplesmente a diferença do primeiro para o segundo
    if (n > 1) {
        dp[1] = abs(d[1] - d[0]);
    }
    
    // Preencher o dp para todos os ternos
    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i-1] + abs(d[i] - d[i-1]), dp[i-2] + abs(d[i] - d[i-2]));
    }
    
    // O resultado final é o custo para chegar ao último terno
    return dp[n-1];
}

int main() {
    int n;
    // cout << "Digite o número de ternos: ";
    cin >> n;
    
    vector<long int> d(n);
    // cout << "Digite os custos de manutenção dos ternos: ";
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    
    long int resultado = menorCustoTernos(d);
    cout << "O menor custo total possível é: " << resultado << endl;
    
    return 0;
}
