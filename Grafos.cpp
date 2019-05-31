#include "Grafos.h"

vector <size_t> Grafos::numArestas(vector<vector<size_t>> &matriz) {
    size_t linhas = matriz.size();
    vector <size_t> arestas;
    arestas.reserve(linhas);
    for (size_t i = 0; i < linhas; ++i) {
        int ligacoes = 0;
        size_t colunas = matriz[i].size();
        for (size_t j = 0; j < colunas; ++j) {
            if (matriz[i][j]){
                ligacoes++;
            }
        }
        arestas.push_back(ligacoes);
    }
    return arestas;
}

vector<vector<int>> Grafos::matrizToSparse(vector<vector<int>> &matriz) {
    vector <vector<int>> sparse;
    size_t linhas = matriz.size();
    sparse.reserve(linhas);

    for (size_t i = 0; i < linhas; ++i) {
        size_t colunas = matriz[i].size();
        for (size_t j = 0; j < colunas; ++j) {
            if (matriz[i][j]){
                sparse[i].push_back(j);
            }
        }
    }

    return sparse;
}

vector<vector<int>> Grafos::sparseToMatrix(vector<vector<int>> &sparse) {
    vector <vector<int>> matrix;
    size_t linhas = sparse.size();
    matrix.reserve(linhas);
    for (size_t k = 0; k < linhas; ++k) {
        matrix[k].reserve(linhas);
    }

    for (size_t i = 0; i < linhas; ++i) {
        for (size_t j = 0; j < linhas; ++j) {
            size_t colunas = sparse[i].size();
            matrix[i][j] = 0;
            for (size_t k = 0; k < colunas; ++k) {
                if (sparse[i][k] == j){
                    matrix[i][j] = 1;
                }
            }

        }
    }

    return matrix;
}
