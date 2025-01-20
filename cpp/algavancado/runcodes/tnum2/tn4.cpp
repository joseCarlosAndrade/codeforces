#include <iostream>
#include <vector>
using namespace std;

int main() {
    int p;
    cin >> p;

    vector<int> results(p, -1);

    for (long long s = 0; s <= (p -1) / 2; ++s) {
        long long sq = (s * s) % p; 
        if (results[sq]  ==-1) { // apenas atualiza se ainda nao tiver uma raiz menor
            results[sq] = s;
        }
    }
    
    for ( int i = 0 ; i < p; ++i) {
        cout << results[i];
        if (i < p - 1 ) cout << " ";
    }
    cout << endl;

    return 0;
}
