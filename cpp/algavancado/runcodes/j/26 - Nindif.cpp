#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int MAX_X = 10000; // maximum number of sticks in a pile


vector<int> compute_grundy(const vector<int>& moves, int max_sticks) {
    vector<int> grundy(max_sticks + 1, 0);

    for (int i = 0; i <= max_sticks; ++i) {
        unordered_set<int> reachable_states;
        for (int move : moves) {
            if (i >= move) {
                reachable_states.insert(grundy[i - move]);
            }
        }
        // calculate the Minimum Excludant (MEX)
        int g = 0;
        while (reachable_states.count(g)) {
            ++g;
        }
        grundy[i] = g;
    }
    return grundy;
}

// determine the state of the game for a given pile configuration
char evaluate_state(const vector<int>& grundy, const vector<int>& piles) {
    int xor_sum = 0;
    for (int sticks : piles) {
        xor_sum ^= grundy[sticks];
    }
    return (xor_sum == 0) ? 'L' : 'W';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c; //eread number of allowed moves
    vector<int> moves(c);
    for (int i = 0; i < c; ++i) {
        cin >> moves[i]; // Read the allowed moves
    }

    // pecompute Grundy numbers up to MAX_X
    vector<int> grundy = compute_grundy(moves, MAX_X);

    int m;
    cin >> m; //
    vector<char> results;

    for (int i = 0; i < m; ++i) {
        int p;
        cin >> p; 
        vector<int> piles(p);
        for (int j = 0; j < p; ++j) {
            cin >> piles[j]; //
        }
        results.push_back(evaluate_state(grundy, piles));
    }

    
    for (char result : results) {
        cout << result;
    }
    cout << endl; // end with a newline

    return 0;
}
