#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// default variables
bitset<1000005> isPrime;
vector<int> primes;

void isPrimes(int N) {
  isPrime.set();

  isPrime[0] = isPrime[1] = 0;
  for (ll i = 2; i <= N; i++) {
    if (isPrime[i] == 1) {

      for (ll j = i*i; j <= N; j += i) {
        isPrime[i] = 0;
        
        }

      primes.push_back(i);
    }
  }

}

int solve(int k) {
  map<int, int> fatMap;

  // sqrt to reduce complexity!
  for (int i = 0, fp = primes[i]; fp*fp <= k; i++, fp = primes[i]){
    while (k % fp == 0) {
      k /= fp;
      
      fatMap[fp]++;
    }
  }


  if (k != 1) fatMap[k] = 1;
  int c = 1;
  for (pair<int, int> it : fatMap) {

    c *= (it.second + 1);
  }

  return c;
}

int main() {
  int n;
  cin >> n;

  isPrimes(1000000);

  // default ingestion
  for (int i = 0; i < n; i++) {
    int tmp;

    cin >> tmp;
    cout << solve(tmp) << endl;
  }

  return 0;
}