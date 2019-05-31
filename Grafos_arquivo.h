#ifndef GRAFOS_ARQUIVO_H
#define GRAFOS_ARQUIVO_H

#include <vector>
using namespace std;

class Aresta
{
public:
	Aresta(string vertice1, string vertice2, int peso);
	string vertice1;
	string vertice2;
	int peso;
};

class Grafo {
    public:
    	int void insereAresta(Aresta &aresta);
        unsigned numArestas();
    private:
    	vector <Aresta> arestas;
    	vector <string> vertices;

};


#endif
