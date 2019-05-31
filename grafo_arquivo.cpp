#include "grafo_arquivo.h"
#include <iostream>
#include <utility>
using namespace std;


Aresta::Aresta(string vertice1_, string vertice2_, int peso_){
    vertice1 = vertice1_;
    vertice2 = vertice2_;
    peso = peso_;
}

void Aresta::imprimeAresta() {
    cout << vertice1 << "-" << peso << ">" << vertice2 << endl;
}

void Grafo::insereAresta(Aresta &aresta){
    bool contemV1 = false;
    bool contemV2 = false;

    arestas.push_back(aresta);

    for (Aresta &arestaTemp : arestasRepetidas)
    {
        if (arestaTemp.vertice1 == aresta.vertice1 && arestaTemp.vertice2 == aresta.vertice2)
        {
            arestaTemp.peso += aresta.peso;
            return;
            
        }
        if(arestaTemp.vertice1 == aresta.vertice1 || arestaTemp.vertice2 == aresta.vertice1){
            contemV1 = true;
        }
        if(arestaTemp.vertice1 == aresta.vertice2 || arestaTemp.vertice2 == aresta.vertice2){
            contemV2 = true;
        }
        
    }

    if (!contemV1)
    {
        pair <string, unsigned> vertice;
        vertice.first = aresta.vertice1;
        vertice.second = 1;
        vertices.push_back(vertice);
    }
    if (!contemV2)
    {
        pair <string, unsigned> vertice;
        vertice.first = aresta.vertice2;
        vertice.second = 1;
        vertices.push_back(vertice);
    }

    arestasRepetidas.push_back(aresta);
}

void Grafo::insereVertice(string nomeVertice) {
    for(pair <string, unsigned> &vertice : vertices){
        if(nomeVertice == vertice.first){
            vertice.second++;
            return;
        }
    }
}

unsigned Grafo::numArestas(){
    return arestasRepetidas.size();
};

void Grafo::listaArestasRepetidas() {
    cout <<  "Arestas Repetidas: " << endl;
    for (Aresta &aresta : arestasRepetidas) {
        cout << aresta.vertice1 << "-" << aresta.peso << ">" << aresta.vertice2 << endl;
    }
    cout << endl;
}

void Grafo::listaArestas() {
    cout <<  "Arestas: " << endl;
    for (Aresta &aresta : arestas) {
        cout << aresta.vertice1 << "-" << aresta.peso << ">" << aresta.vertice2 << endl;
    }
    cout << endl;
}

void Grafo::listaVertices() {
    cout << "Vertices: " << endl;
    for (pair <string, unsigned> &vertice : vertices) {
        cout << vertice.first << "(" << vertice.second << ")" << endl;
    }
    cout << endl;
}

string Grafo::maiorFrequencia() {
    unsigned frequencia = 0;
    string maior;
    for(pair <string, unsigned > &vertice : vertices){
        if(vertice.second > frequencia){
            maior = vertice.first;
            frequencia = vertice.second;
        }
    }
    return maior;
}

Aresta *Grafo::maiorFrequenciaDupla() {
    unsigned frequencia = 0;
    Aresta *maior = nullptr;
    for(Aresta &aresta : arestasRepetidas){
        if(aresta.peso > frequencia){
            maior = &aresta;
            frequencia = aresta.peso;
        }
    }
    return maior;
}

string Grafo::maiorFrequenciaTripla() {

    vector <pair<string[3], unsigned>> triplas; //lista de pares de triplas de nomes com a frequencia

    unsigned size = arestas.size();
    for(unsigned i = 0; i < size; ++i){
        bool achou = false;
        if(i + 1 < size){
            string vertice1 = arestas.at(i).vertice1;
            string vertice2 = arestas.at(i).vertice2;
            string vertice3 = arestas.at(i + 1).vertice2;
            for(pair<string[3], unsigned> &tripla : triplas){
                if(tripla.first[0] == vertice1 && tripla.first[1] == vertice2 && tripla.first[2] == vertice3){
                    tripla.second++;
                    achou = true;
                }
            }
            if (!achou){
                pair<string[3],unsigned > tripla;
                tripla.first[0] = vertice1;
                tripla.first[1] = vertice2;
                tripla.first[2] = vertice3;
                tripla.second = 1;
                triplas.push_back(tripla);
            }
        }
    }

    unsigned frequencia = 0;
    string maiorTripla;

    for(pair<string[3], unsigned> &tripla : triplas){
        if(tripla.second > frequencia){
            frequencia = tripla.second;
            maiorTripla = tripla.first[0] + "->" + tripla.first[1]+ "->" + tripla.first[2] + "(" + to_string(tripla.second) + ")";
        }
    }

    return maiorTripla;
}
