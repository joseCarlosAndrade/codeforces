#include<bits/stdc++.h>
#include<iostream>

using namespace std;


// implementacao do quicksort pelo site geeksforgeeks!!!
int partition(vector<pair<int, int>> &vec, int low, int high) {

    int pivot = vec[high].first;

    
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        
        if (vec[j].first <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

 
    swap(vec[i + 1], vec[high]);

    
    return (i + 1);
}

// implementacao do quicksort pelo site geeksforgeeks!!!
void quickSort(vector<pair<int, int>> &vec, int low, int high) {

    if (low < high) {

       
        int p = partition(vec, low, high);

        quickSort(vec, low, p - 1);
        quickSort(vec, p + 1, high);
    }
}



int main(int argc, char ** argv) {
    int n;
    cin >> n;

    
    vector<pair<int,int>> vetor;

    for (int i = 0; i < n; i++) {
        int duration, limit;
        cin >> duration >> limit;

        // limit_map[i] = {duration, limit};
        vetor.push_back({duration, limit});
    }

    quickSort(vetor, 0, n-1);

    long int custo = 0;
    long int tempo = 0;

    for ( auto tarefa : vetor) {
        tempo += tarefa.first;
        custo += tarefa.second - tempo; 
    }
   
    cout << custo;
}



/*
n tarefas

duracao + d (tempo limite para ser executada)
custo de cada tarefa: d-x => x é o momento em que a tarefa termina

obter custo maximo

2 8 (termina em 2, 8-2 = 6)
3 10 (termina em 5, 10-5 = 5)
4 2 (termina em 9, 2-9 = -7) --     4 15 , 15-9 = 6
4 15 (termina em 13, 15-13 = 2) --  4 2  , 2-13 = -11

custo total = 6
 */