#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define P (1000000007)

// exponenciaçao modular
long long calc(long long base, long long exp, long long mod)  {
    long long result = 1;

    while (exp > 0) {
        if (exp %2 == 1) {
            result = (result * base) % mod;
        }
        base = (base *base)% mod;

        exp = exp /2;
    }
    return result;
}

int main(int argc, char **argv) {
    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i++) {
        long long a, b, c;

        cin >> a >> b >> c;
        long long bc = calc(b,c, P-1);
        long long abc = calc(a, bc, P);

        cout << abc << endl;
    }
}