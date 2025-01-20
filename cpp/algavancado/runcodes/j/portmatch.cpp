#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s, p;
    
    // read input strings
    getline(cin, s);
    getline(cin, p);


    int n = s.size(), m = p.size();
    vector<int> idxs;

    // precompute prefix function for the pattern
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];

        }
        if (p[i] == p[j]) {
            ++j;
        }
        pi[i] = j;
    }

    // kmp search for the pattern in the string
    for (int i = 0, j = 0; i < n; ++i) {

        while (j > 0 && s[i] != p[j]) {

            j = pi[j - 1];
        }
        if (s[i] == p[j]) {

            ++j;
        }
        if (j == m) {
            idxs.push_back(i - m + 1);
            j = pi[j - 1];

        }
    }

    int q = idxs.size();
    // output results based on occurrences
    if (q >= 100) {

        cout << q << "\n";
    } else {
        cout << q << "\n";
        for (int i : idxs) {
            cout << i << "\n";
        }
    }

    return 0;
}
