#include <iostream>

using namespace std;

int getBits(int *collection, __int128_t bitmask) {
  int v = 0;
  for (int i = 0; collection[i] != -1; i++) {
    if (bitmask & (1 << collection[i])) {
      v++;
    }
  }

  return v;
}

int solve(int **collections, __int128_t *bitmasks) {}

int main() {
  int n, m;
  cin >> n >> m;

  int **collections = new int *[n + 1];
  collections[n] = nullptr;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    collections[i] = new int[n];
    for (int j = 0; j < k; ++j) {
      cin >> collections[i][j];
    }
    collections[i][k] = -1;
  }
  
  __int128_t *bitmasks = new __int128_t[n + 1];
  bitmasks[n] = -1;

  for (int i = 0; i < n; i++) {
    const auto &collection = collections[i];
    for (int j = 0; collection[j] != -1; j++) {
      bitmasks[i] |= (1 << collection[j]);
    }
  }

  cout << solve(collections, bitmasks) << endl;
}
