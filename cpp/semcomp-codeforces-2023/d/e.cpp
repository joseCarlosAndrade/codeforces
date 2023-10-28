#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int main() {
	long long int n, max =0, min = 0;
	cin >> n;
	
	while(n--) {
		unsigned long long int v;
		cin >> v;

		if (v > max) {
			max = v;
			min = v;
		}
		else if (v < min) {
			min = v;
		}
		
	}
	cout << max-min << "\n";
}
