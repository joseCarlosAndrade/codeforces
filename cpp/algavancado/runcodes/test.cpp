#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double calculate_distance(pair<int, int> p1, pair<int, int> p2);

int main(int argc, char ** argv) {
    int x1 = 10, x2 = 15, y1 = 45, y2 = 90;

    int r = x1^2;

    std::cout << r << std::endl;
    // 001010
    // 000010
    // 001000 resultado do xor

    std::cout << calculate_distance({10, 0}, {15, 0}) << endl << calculate_distance({10, 0}, {15,10}) << endl;
}


double calculate_distance(pair<int, int> p1, pair<int, int> p2) {
    // d² = (y2-y1)² + (x2-x1)²
    return sqrt( pow((p2.second - p1.second), 2) + pow((p2.first - p1.first), 2) );
}
