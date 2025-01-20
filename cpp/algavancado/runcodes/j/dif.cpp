#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAX_X = 10000;

vector<bool> compute_grundy(const vector<int>& moves, int max_sticks) {
    vector<bool> grundy(max_sticks+ 1, false);

    for (int i = 0; i<= max_sticks; ++ i) {

        unordered_set<int> reachable;
        for (int move : moves) {
            if (i >= move) {
                reachable.insert(grundy[i - move]);
            }
        }
        grundy[i] = reachable.count(false) == 0;
    }
    return grundy;
}

char evaluate_state(const vector<bool>& grundy, const vector<int>& piles) {
    int xor_sum = 0;
    for (int sticks : piles) {
        xor_sum ^= grundy[sticks];
    }

    return (xor_sum == 0) ? 'L' :'W';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >>c;

    vector<int> moves(c);
    for (int i = 0; i < c; ++i) {
        cin >> moves[i];

    }


    vector<bool> grundy = compute_grundy(moves, MAX_X);

    int m;
    cin >>m;
    vector<char> results;

    for (int i = 0; i < m; ++i) {
        int p;
        cin >> p;
        vector<int> piles(p);
        for (int j = 0; j < p; ++j) {
            cin >> piles[j];

        }
        results.push_back(evaluate_state(grundy, piles));
    }

    for (char result : results) {
        cout<< result;
    }

    return 0;
}
