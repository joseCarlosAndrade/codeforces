#include<iostream>
#include<bits/stdc++.h>


int main(int argc, char ** argv) {

    std::map<int , std::multiset<int>> timeline;

    std::map<int, int> id_time; // mapa que fica ordenado de acordo com o T passado como chave
    std::map<int, int> id_timeline;
    
    int n ;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::string query;
        int id;
        int T;
        std::cin >> query >> id >> T;

        id_time.insert({id, T});
        id_timeline.insert({id, T});
    }


    int K;
    std::cin >> K ;

    

    for (;;) {
        if (K-- == 0) return 1;  

        int mintime = 9999;
        int minid = 0;
        for ( auto p : id_timeline) { // acessa ids por ordem crescente
            if (p.second < mintime) {
                mintime = p.second;
                minid = p.first;
            } else if (p.second = mintime) { // tempos iguais, pegar o menor id
                if (p.first < minid) {
                    minid = p.first;
                    mintime = p.second;
                }
            }
        }

        // aqui tenho o menor tempo e o menor id encontrado.
        std::cout << minid << std::endl;
        
        id_timeline[minid] += id_time[minid];
    }
}
