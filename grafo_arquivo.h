#ifndef GRAFOS_ARQUIVO_H
#define GRAFOS_ARQUIVO_H

#include <string>
#include <vector>
#include <utility>
using namespace std;

class Aresta
{
public:
	Aresta(string vertice1, string vertice2, int peso);
	string vertice1;
	string vertice2;
	int peso;
	void imprimeAresta();
};

class Grafo {
public:
    void insereAresta(Aresta &aresta);
    void insereVertice(string nomeVertice);
    unsigned numArestas();
    void listaArestasRepetidas();
    void listaArestas();
    void listaVertices();
    string maiorFrequencia();
    Aresta *maiorFrequenciaDupla();
    string maiorFrequenciaTripla();

private:
    vector <Aresta> arestas;
    vector <Aresta> arestasRepetidas;
    vector <pair<string, unsigned>> vertices;

};


#endif
