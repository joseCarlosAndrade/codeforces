#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> possiveis_passos;

// estrategia: mantenho um vetor p_minimos que armazena os passo minimos necessarios para chegar na faixa i;
// a cada pulo, pega a quantidade de metros possiveis naquela faixa e itera sobre sua posicao + metros possiveis, incrementando a quantidade de passos
// para chegar naquelas posiçoes a frente, caso estas ainda nao tenham sido visitadas, garantindo que sempre seja a menor das opçoes
int passos_minimos(int N) {
    vector<int> p_minimos(N, -1);

    p_minimos[0] = 0;
    
    int passos_total = 0; 

    for (int i = 0; i < N; i++) {
        int current_passos = p_minimos[i];
        
        for(int j = i + possiveis_passos[i]; j > i; j--) {
            if (j > N-1) continue;
            if (p_minimos[j] == -1) p_minimos[j] = current_passos+1;
        }

        if (i < N-1 && p_minimos[i+1] == -1) return -1; // parar se perceber que nao é possivel
    }

    // for (auto a : p_minimos) {
    //     cout << a << " ";
    // }

    return p_minimos[N-1] ;
}

int main() {
    int N;
    cin >> N;

    
    for (int i = 0; i < N; i ++) {
        int p;
        cin >> p;
        possiveis_passos.push_back(p);
    }

    int p_min = passos_minimos(N);
    if (p_min > 0) cout << p_min << endl;
    else cout << "Salto impossivel";
}