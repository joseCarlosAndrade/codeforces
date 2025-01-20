#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Função para verificar se uma letra é vogal
bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Função para calcular o custo da troca de dois caracteres
int cost_of_swap(char a, char b) {
    if (a == b) return 0;
    if ((is_vowel(a) && is_vowel(b)) || (!is_vowel(a) && !is_vowel(b))) return 1;
    return 3;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    int n = s1.size();
    int m = s2.size();
    
    // Tabela de distâncias e ações
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<string>> actions(n + 1, vector<string>(m + 1, ""));
    
    // Preenchendo a primeira linha e a primeira coluna (remoções e inserções)
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = i * 2;  // Remover todos os caracteres de s1
        actions[i][0] = actions[i-1][0] + "R:" + s1[i-1] + " ";  // Remoção
    }
    
    for (int j = 1; j <= m; ++j) {
        dp[0][j] = j * 2;  // Inserir todos os caracteres de s2
        actions[0][j] = actions[0][j-1] + "I:" + s2[j-1] + " ";  // Inserção
    }
    
    // Preenchendo o resto da tabela
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int remove_cost = dp[i-1][j] + 2;
            int insert_cost = dp[i][j-1] + 2;
            int swap_cost = dp[i-1][j-1] + cost_of_swap(s1[i-1], s2[j-1]);
            
            dp[i][j] = min({remove_cost, insert_cost, swap_cost});
            
            if (dp[i][j] == remove_cost) {
                actions[i][j] = actions[i-1][j] + "R:" + s1[i-1] ;
            } else if (dp[i][j] == insert_cost) {
                actions[i][j] = actions[i][j-1] + "I:" + s2[j-1];
            } else {
                if (s1[i-1] != s2[j-1])
                    actions[i][j] = actions[i-1][j-1] + "T:" + s1[i-1] + "-" + s2[j-1];
                else
                    actions[i][j] = actions[i-1][j-1];  // Não há custo se as letras forem iguais
            }
        }
    }
    
    // Saída
    if (dp[n][m] == 0) {
        cout << 0 << endl;
        cout << "nada a fazer" << endl;
    } else {
        cout << dp[n][m] << endl;
        cout << actions[n][m] << endl;
    }
    
    return 0;
}