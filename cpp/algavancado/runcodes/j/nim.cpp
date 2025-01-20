#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    long long balance = 20;

    while (t--) {
        int n;
        cin >> n;

        int xor_sum = 0;
        for (int i = 0; i < n; ++i) {
            int sticks;
            cin >> sticks;
            xor_sum ^= sticks;
        }

        if (xor_sum != 0) {
            balance += 20;
        } else {
            balance -= 20;
        }
    }

    cout << balance << endl;
    return 0;
}
