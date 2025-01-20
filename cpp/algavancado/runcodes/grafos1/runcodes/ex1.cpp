#include<iostream>
#include<bits/stdc++.h>

#define FONTE 10
#define SUMIDOURO 11

using namespace std;

vector<vector<int>> lista_adjacencia;
vector<vector<int>> capacidade_residual;

// retorna um novo fluxo maximo do grafo das capacidades residuais (cainmho aumentante)
int bfs(int s, int t, vector<int>& parent) {
    // preenchendo vetor de nso pares com -1
    fill(parent.begin(), parent.end(), -1);

    parent[s] = -2; // origem!!!

    queue<pair<int, int>> fila; // fila para bfs

    fila.push({s, INT_MAX}); 

    while (!fila.empty()) {
        int no_atual = fila.front().first;
        int fluxo = fila.front().second;
        fila.pop();

        // para cada no adjacente:
        for ( int proximo_no : lista_adjacencia[no_atual]) {
            if (parent[proximo_no] == -1 && capacidade_residual[no_atual][proximo_no] > 0) {
                parent[proximo_no] = no_atual;

                int capacidade_novo = min(capacidade_residual[no_atual][proximo_no], fluxo);
                if (proximo_no == t) {
                    return capacidade_novo;
                }
                fila.push({proximo_no, capacidade_novo});
            }
        }
    }

    return 0;
}

int ek(int s, int t) {
    int fluxo_maximo = 0;
    vector<int> parent(lista_adjacencia.size());

    int novo_fluxo = 0;
    while ((novo_fluxo = bfs(s, t, parent)) != 0) {
        fluxo_maximo += novo_fluxo;

        int no_atual = t;
        while (no_atual != s) {
            int no_anterior = parent[no_atual];
            capacidade_residual[no_anterior][no_atual] -= novo_fluxo;
            capacidade_residual[no_atual][no_anterior] += novo_fluxo;
            no_atual = no_anterior;
        }
    }

    return fluxo_maximo;
}

void adicionar_nos(int u, int v, int c) {
    lista_adjacencia[u].push_back(v);
    lista_adjacencia[v].push_back(u);

    capacidade_residual[u][v] = c;
    capacidade_residual[v][u] = 0;
}


void processar_input() {
    // ler um caracter por ves e processar cada um
    char c;
    bool next_line = false;
    int n_processos = 0;
    while (cin.get(c)) {
        
        if (c >= 'A' && c <= 'Z') {
            next_line = false;
            char n;
            cin.get(n);

            // cout << "LETRA: " << c << " processar " << n << " vezes" << endl;

            int n_int = n - '0';

            n_processos += n_int;

            // 0 a 9 sao os processadores
            // 10 é a fonte
            // 11 é o sumidouro
            // 12 é A
            // 13 é B etc

            int no = c - 'A' + 12;

            adicionar_nos(FONTE, no, n_int);

            char next;

            while (true) {
                cin.get(next);

                if (next == ' ') {
                    continue;
                }

                if (next == ';') {
                    break;
                }

                // cout << "PROCESSADOR: " << next << endl;

                if (next >= '0' && next <= '9') {
                    // transformar o caracter em inteiro
                    int proc = next - '0';
                    adicionar_nos(no, proc, 1);
                }
            }

        } else if (c == '\n') {
            if (next_line) {
                next_line = false;
                
                // ligando todos os processos ao no sumidouro
                for (int i = 0; i < 10; i++) {
                    adicionar_nos(i, SUMIDOURO, 1);
                }

                int max_fluxo = ek(FONTE, SUMIDOURO);
                // cout << "fluxo maximo: " << max_fluxo << "numero de processos " << n_processos << endl;
                if (max_fluxo >= n_processos) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }

                // resetar no e capacidade residual
                lista_adjacencia.clear();
                capacidade_residual.clear();

                lista_adjacencia.resize(38);
                capacidade_residual.resize(38, vector<int>(38, 0));

                n_processos = 0;
                
            } else {
                next_line = true;
            }
          
    
        }
    }
    // ligando todos os processos ao no sumidouro
    for (int i = 0; i < 10; i++) {
        adicionar_nos(i, SUMIDOURO, 1);
    }

    int max_fluxo = ek(FONTE, SUMIDOURO);
    // cout << "fluxo maximo: " << max_fluxo << "numero de processos " << n_processos << endl;
    if (max_fluxo >= n_processos) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    // resetar no e capacidade residual
    lista_adjacencia.clear();
    capacidade_residual.clear();

    lista_adjacencia.resize(38);
    capacidade_residual.resize(38, vector<int>(38, 0));

    n_processos = 0;
}

int main() {
    // int n = 6;
    lista_adjacencia.resize(38);
    capacidade_residual.resize(38, vector<int>(38, 0));

    // adicionar_nos(0, 1, 16);
    // adicionar_nos(0, 2, 13);
    // adicionar_nos(1, 2, 10);
    // adicionar_nos(1, 3, 12);
    // adicionar_nos(2, 1, 4);
    // adicionar_nos(2, 4, 14);
    // adicionar_nos(3, 2, 9);
    // adicionar_nos(3, 5, 20);
    // adicionar_nos(4, 3, 7);
    // adicionar_nos(4, 5, 4);

    // cout << "Fluxo maximo: " << ek(0, 5) << endl;
    processar_input();

    return 0;
}