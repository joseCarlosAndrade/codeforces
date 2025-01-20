#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool verificar_chute(const vector<int>& paginas, int n, int m, int chute) {
    
    int acumulador = 0;
    int estudante  = 1;

    for ( int i = 0; i < n; i++)
    {
        if (paginas[i] > chute) return false;

        if (acumulador + paginas[i] > chute) {
            // voltando acumulador para proxiumo estudante
            acumulador = paginas[i];
            estudante++;

            if (estudante > m) return false; // condicao de parada (ultimo estudante)
        }
        else {
        // acumulando

        acumulador += paginas[i];
    }
    } 
    // chegou aqui, eh pq coube
    return true;
    
}


int encontrar_max_paginas(const vector<int> & paginas, int n, int m) {
    int min = paginas[n-1]; // minimo vai ser o livro com maior qnt de paginas
    int max = accumulate(paginas.begin(), paginas.end(), 0); // maximo eh a soma de todas as paginas

    int result;

    while (min <= max) {
        int mid = min + (max - min) / 2;

        if (verificar_chute(paginas, n, m, mid)) {
            result = mid;
            max = mid -1;
        } else {
            min = mid + 1;
        }
    }

    return result;
}

int main(int argc, char ** argv) {
    int n, m;
    vector<int> paginas;

    cin >> n >> m;

    for (int i =0; i < n; i++) {
        int pag;
        cin >> pag;

        paginas.push_back(pag);
    }

    sort(paginas.begin(), paginas.end());

    cout << encontrar_max_paginas(paginas, n, m);
    
}