#include<bits/stdc++.h>

using std::cin;
using std::cout;

int main() {
    int t;
    cin >> t;
    

    for(int j = 0; j < t; j++) {

        std::vector<int> arr;
        long int tam = 3;

        arr.push_back(2);
        arr.push_back(1);
        long int n;

        cin >> n;

        if (n == 1) {
            cout << "2\n";
            continue; 
        }
        

        for (int i = 3; i < n+1; i++) {
            
            int id =0 ;
            for(;;) {
                if (arr[id] + arr[id+1] == i) {
                    tam += 2;
                    arr.insert(arr.begin()+ id+1, i);
                    id ++;
                }
                id++;
                if (id >= arr.size()) {
                    break;
                }
            }
        }
        cout << tam << "\n";
    }
}

