#ifndef GRAFOS_H
#define GRAFOS_H

#include <vector>
using namespace std;

class Grafos {
    public:
        vector <size_t> numArestas(vector <vector <size_t>> &matriz);
        vector <vector <int>> matrizToSparse(vector <vector <int>> &matriz);
        vector <vector <int>> sparseToMatrix(vector <vector <int>> &sparse);

};


#endif
