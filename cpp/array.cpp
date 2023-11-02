#include<iostream>
#include<vector>

std::vector<int> juncao_listas(std::vector<int> lista1, std::vector<int> lista2) {
    std::vector<int> lista_final;
    // lista_final.insert()

    for (auto e : lista1) {
        if (!lista_final.size()) lista_final.push_back(e); // primeiro elemento a ser inserido

        else {
            for (int i = 0; i < lista_final.size(); i++) {
                if (e < lista_final[i])  {
                    lista_final.insert(lista_final.begin()+ i, e);
                    break;
                }
            }
            lista_final.push_back(e);

        }
    }

    for (auto e : lista2) {
        if (!lista_final.size()) lista_final.push_back(e); // primeiro elemento a ser inserido

        else {
            for (int i = 0; i < lista_final.size(); i++) {
                if (e < lista_final[i]) {
                    lista_final.insert(lista_final.begin()+ i, e);
                    break;  
                }
            }
            lista_final.push_back(e);
        }
    }
    return lista_final;
}

int main() {
    std::vector<int> lista1;
    lista1.push_back(1);
    lista1.push_back(8);
    lista1.push_back(3);

    std::vector<int> lista2;
    lista2.push_back(4);
    lista2.push_back(2);
    lista2.push_back(9);

    std::vector<int> finals = juncao_listas(lista1, lista2);

    for (auto a: finals) {
        std::cout << a << " ";
    }
}