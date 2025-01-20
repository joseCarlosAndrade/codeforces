#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VecInt;
typedef vector<vector<int>> MatrixInt;

bitset<100005> isPrime; // mark prime numbers
VecInt primeNumbers; // storing

// matrices definitions
int rows, cols;
MatrixInt inputMatrix; 
MatrixInt differenceMatrix;



void generatePrimes(ll limit) {
    isPrime.set(); // all to 1

    //  0 and 1 as non-prime
    isPrime[0] =0;
    isPrime[1] = 0;

    // Sieve 
    for (ll i = 2; i <= limit; i++) {
        if (isPrime[i] == 1) { // If i is still considered prime

            for (ll j = i * i; j <= limit; j += i) {
                isPrime[j] =0; //multiple of i 
            }
            primeNumbers.push_back(i); // 
        }
    }

}

// solving :)
int solve() {
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!isPrime[inputMatrix[i][j]]) { //current number is not prime
    
                for (int k = 0; k < primeNumbers.size(); k++) {
                    if (primeNumbers[k] > inputMatrix[i][j]) {
                        differenceMatrix[i][j] = primeNumbers[k] - inputMatrix[i][j];
                        inputMatrix[i][j] = primeNumbers[k];
                        break;
                    }
                }
            }
        }
    }

    int minimumSum = INT_MAX; 

    // for rosw
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += differenceMatrix[i][j];
        }
        minimumSum = min(minimumSum, rowSum);
    }

    // fopr columns
    for (int i = 0; i < cols; i++) {
        int colSum = 0;
        for (int j = 0; j < rows; j++) {
            colSum += differenceMatrix[j][i];
        }
        minimumSum = min(minimumSum, colSum);
    }

    return minimumSum; 
}

int main() {

    generatePrimes(100000); //generating primes up to 100000

    //filling matrixx
    cin >> rows >> cols;

    inputMatrix.resize(rows, VecInt(cols));
    differenceMatrix.resize(rows, VecInt(cols));

    // Read the matrix values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> inputMatrix[i][j];

        }
    }
    cout << solve() << endl;
    return 0;
}