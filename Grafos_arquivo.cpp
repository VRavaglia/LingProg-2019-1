#include "Grafos_arquivo.h"

Aresta::Aresta(string vertice1_, string vertice2_, int peso_){
    vertice1 = vertice1_;
    vertice2 = vertice2_;
    peso = peso_;
}

int Grafo::insereAresta(Aresta &aresta){
    bool contemV1 = false;
    bool contemV2 = false;

    for (unsigned i = 0; i < arestas.size(); ++i)
    {
        Aresta *arestaTemp = &arestas.at(i);
        if ((arestaTemp->vertice1 == aresta.vertice1 and arestaTemp->vertice2 == aresta.vertice2) or (arestaTemp->vertice1 == aresta.vertice2 and arestaTemp->vertice2 == aresta.vertice1))
        {
            arestaTemp->peso += peso;
            return 0;
            
        }
        if(arestaTemp->vertice1 == aresta.vertice1 or arestaTemp->vertice2 == aresta.vertice1){
            contemV1 = true;
        }
        if(arestaTemp->vertice1 == aresta.vertice2 or arestaTemp->vertice2 == aresta.vertice2){
            contemV2 = true;
        }
        
    }

    if (contemV1)
    {
        vertices.push_back(aresta.vertice1);
    }
    if (contemV2)
    {
        vertices.push_back(aresta.vertice2);
    }

    arestas.push_back(aresta);
}

unsigned Grafo::numArestas(){
    return arestas.size();
};