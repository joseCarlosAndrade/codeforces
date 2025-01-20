#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// utilitario que calcula a distancia entre dois pontos
double calculate_distance(pair<int, int> p1, pair<int, int> p2) {
    // d² = (y2-y1)² + (x2-x1)²
    return sqrt( pow((p2.second - p1.second), 2) + pow((p2.first - p1.first), 2) );
}


// finding minimal distance
double find_min_distance_loop(const vector<pair<int, int>> &vetor, int init, int end) {
    double min_distance = INFINITY;
    
    // 0 1 2 3 4 5

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

vector<pair<int, int>> find_intersection_points(const vector<pair<int, int >> &pontos, int half_index, double threshold, int init, int end) {


    double min_x = pontos[half_index].first - threshold;
    double max_x = pontos[half_index].first + threshold;
    
    vector<pair<int, int>> new_points;



    for ( int i = init ; i <= end; i++) {
        if( abs(pontos[i].first - pontos[half_index].first) < threshold) {
            new_points.push_back(pontos[i]);
        }
    }

    return new_points;
}


// comparison function tu use in std::sort
bool sort_by_x_comparison(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

// comparison  function to use ni std::sotr by y
bool sort_by_y_comparison(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


// recebe os pontos ja ordenados em x - passando por const reference para nao ter que copiar os valores de vector constantemente
double find_minimal_distance(const vector<pair<int, int>> &pontos, int init, int end) {

    int size = end-init +1;

    // caso base
    if (size <= 3) {
        // double min;
        return find_min_distance_loop(pontos, init, end);
    }
    //       0 1 2 3 '4' 5 6
    // 0 1 2 3 4 5 6 '7' 8 9 10
    //     2 3             9

    // size = 9 - 3 + 1 = 7
    // half = (9 + 3+1) /2 = 6.5

    int half = ceil((init + end + 1) / 2 ); // arredondando para cima

    double min_distance_left = find_minimal_distance(pontos, init, half-1);
    double min_distance_right = find_minimal_distance(pontos, half, end);

    double min_both = min_distance_left < min_distance_right ? min_distance_left : min_distance_right;

    // encontrando pontos que estao na intersecção  
    vector<pair<int, int >> half_points = find_intersection_points(pontos, half-1, min_both, init, end);

    // ordenando pelo eixo y
    sort(half_points.begin(), half_points.end(), sort_by_y_comparison);

    double min_distance_half = INFINITY;

    if (half_points.size() > 0) {

    
        for (int i = 0; i < half_points.size()-1; i++) {
            for (int j = i+1; j < half_points.size() && j-i<=7; j++) {
                double dist = calculate_distance(half_points[i], half_points[j]);

                if (dist < min_distance_half) {
                    min_distance_half = dist;
                }
            }
        }   
    }

    double min_final_distance = min_distance_half < min_both ? min_distance_half : min_both;

    return min_final_distance;
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

    double minimal_distance = find_minimal_distance(pontos, 0, n-1);

    cout << fixed  << setprecision(2) << minimal_distance;
   
}