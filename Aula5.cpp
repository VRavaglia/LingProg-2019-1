#include <iostream>
#include <fstream>
#include <string>
#include "agenda_ponteiro.h"
#include "grafo_arquivo.h"
#include <utility>

using namespace std;

void ex1(){
    string nome;
    string profissao;
    int idade;

    AgendaClasse agenda;
    int cadastros = 0;
    cout << "Digite nome, profissao e idade: " << endl;
    while (cadastros < 3){
        Cadastro *cad = new Cadastro;
        cin >> nome;
        cad->setNome(nome);
        cin >> profissao;
        cad->setProfissao(profissao);
        cin >> idade;
        cad->setIdade(idade);
        agenda.insertCad(cad);
        cadastros++;
    }
    cout << "Original: " << endl;
    agenda.listaContatos();
    agenda.removeCad("felipe");
    cout << "Sem felipe: " << endl;
    agenda.listaContatos();
    agenda.alteraIdadeCad("mateus", 13);
    cout << "Mateus 13 anos: " << endl;
    agenda.listaContatos();
}

void ex2(){
    ifstream arquivo ("texto.txt");
    string linha;
    Grafo grafo;
    if (arquivo.is_open())
    {
        bool primeira = true;
        string primeiraP;
        string segundaP;
        while (getline (arquivo,linha))
        {
            size_t pos = 0;
            while ((pos = linha.find(' ')) != string::npos) {
                string palavra = linha.substr(0, pos);
                linha.erase(0, pos + 1);

                grafo.insereVertice(palavra);

                if(!primeira){
                    primeiraP = segundaP;
                    segundaP = palavra;
                    Aresta aresta(primeiraP, segundaP, 1);
                    cout << "Inserindo: ";
                    aresta.imprimeAresta();
                    grafo.insereAresta(aresta);

                }
                else
                {
                    segundaP = palavra;
                    primeira = false;
                }
            }
        }
        primeiraP = segundaP;
        segundaP = linha;
        Aresta aresta(primeiraP, segundaP, 1);
        cout << "Inserindo: ";
        aresta.imprimeAresta();
        grafo.insereAresta(aresta);
        arquivo.close();
    }
    else{
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }

    cout << endl;
    grafo.listaArestas();
    grafo.listaArestasRepetidas();
    grafo.listaVertices();
    cout << "Palavra que mais aparece: \"" << grafo.maiorFrequencia() << "\"" << endl;
    Aresta *aresta = grafo.maiorFrequenciaDupla();
    if (aresta){
        cout << "Dupla que mais aparece: ";
        aresta->imprimeAresta();
    }
    else{
        cout << "Nenhuma dupla"<< endl;
    }
    string tripla = grafo.maiorFrequenciaTripla();
    if (!tripla.empty()){
        cout << tripla << endl;
    }
    else{
        cout << "Nenhuma tripla"<< endl;
    }
}

int main(){
    ex2();
    return 0;
}