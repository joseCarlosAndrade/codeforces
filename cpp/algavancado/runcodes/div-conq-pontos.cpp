#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// utilitario que calcula a distancia entre dois pontos
double calculate_distance(pair<int, int> p1, pair<int, int> p2) {
    // d² = (y2-y1)² + (x2-x1)²
    return sqrt( pow((p2.second - p1.second), 2) + pow((p2.first - p1.first), 2) );
}


// finding minimal distance
double find_min_distance(vector<pair<int, int>> vetor, int init, int end) {
    double min_distance = INFINITY;

    for (int i = init; i < end; i++ ) {
        for (int j = i+1; j <= end; j++) {
            double distance = calculate_distance(vetor[i], vetor[j]);

            if (distance < min_distance) {
                min_distance = distance;
            }
        }
    }

    return min_distance;
}

vector<pair<int, int>> find_intersection_points(vector<pair<int, int >> pontos, int half_index, double threshold) {
    double min_x = pontos[half_index].first - threshold;
    double max_x = pontos[half_index].first + threshold;
    
    vector<pair<int, int>> new_points;

    // buscando do centro -> esquerda e depois centro -> direita, pois como os pontos ja estao ordenados por x, faz com que deste modo seja mais eficiente
    for (int i = half_index-1; i >= 0; i--) {
        if (pontos[half_index].first - pontos[i].first <= threshold) {
            new_points.push_back(pontos[i]);
        } else {
            break;
        }
    }

    for (int i = half_index+1; i < pontos.size(); i++) {
        if (pontos[i].first - pontos[half_index].first <= threshold) {
            new_points.push_back(pontos[i]);
        } else {
            break;
        }
    }
}


// comparison function tu use in std::sort
bool sort_by_x_comparison(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

// comparison  function to use ni std::sotr by y
bool sort_by_y_comparison(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main(int argc, char ** argv) {
    int n;  

    vector<pair<int, int>> pontos;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y ;
        pontos.push_back({x, y});
    }

    
    // ordenando pontos pela coordenada x
    // sort(pontos.begin(), pontos.end()); // por padrao, isso ja ordena pelo primeiro elemento do pair
    // vou deixar a funcao de comparaçao aqui ainda para caso um dia eu precise.
    // poderiamos usar:
    sort(pontos.begin(), pontos.end(), sort_by_x_comparison);

    // 1 2 3 4 5 6 - 3
    // 0 1 2 | 3 4 5 - 3 is the start of the second half

    // 1 2 3 4 5 6 7 - 3/4
    // 0 1 2 3 | 4 5 6 - 4 is the start of the second half, so 

    int half = ceil(pontos.size() / 2 ); // arredondando para cima

    // pontos[0:half-1] primeira metade
    // pontos[half:] segunda metade de pontos

    // encontrando distancias minimas em cada lado

    double min_distance_left = find_min_distance(pontos, 0, half-1);
    double min_distance_right = find_min_distance(pontos, half, pontos.size()-1);

    double min_both = min_distance_left < min_distance_right ? min_distance_left : min_distance_right; // min entre as duas (both)

    // finding intersecting points ordered by y axis
    vector<pair<int, int >> half_points = find_intersection_points(pontos, half-1, min_both); // passando half-1 pois deve considerar o ponto mais a direita de q

    // order this new vector by y values
    sort(half_points.begin(), half_points.end(), sort_by_y_comparison);

    // comparar a distancia de cada ponto com no maximo seus proximos 15 pontos


    // for (auto a: pontos) {
    //     cout << a.first << " " << a.second << endl;
    // }
}