#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> precos;
vector<int> paginas;

int MEMO[1002][55002];

int solve (int i , int O) { // orcamento disponivel
    if (i == 0 ) return 0;

    if (MEMO[i][O] != -1) return MEMO[i][O];

    if (precos[i] > O) return MEMO[i][O] = solve(i-1, O); // este unico preço ja extrapola o orçamento, ignorar

    return MEMO[i][O] = max( 
                paginas[i] + solve(i-1, O-precos[i]),  // escolher este livro (acrescentar paginas) e tentar o anterior com orçamento descontado
                solve(i-1, O) // ignorar este livro
            );
}

int main(int argc, char ** argv) {
    precos.push_back(0);
    paginas.push_back(0);


    int n, x;

    cin >> n >> x;  

    
    memset(MEMO, -1, sizeof(MEMO));

    for (int i = 0; i < n;  i ++) {
        int prec;
        cin >> prec;
        precos.push_back(prec);
    }

    for (int i = 0; i < n;  i ++) {
        int pag;
        cin >> pag;
        paginas.push_back(pag);

    }

    cout << solve(n, x);

}   