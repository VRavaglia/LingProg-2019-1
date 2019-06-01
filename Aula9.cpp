#include <iostream>
#include <string>
#include "agenda_overload.h"
#include "agenda_herda_vetor.h"

using namespace std;

void ex1(){
    AgendaOverload agenda1;
    agenda1.adicionaContato(*(new ContatoOverload("C", 666)));
    agenda1.adicionaContato(*(new ContatoOverload("B", 666)));
    agenda1.adicionaContato(*(new ContatoOverload("A", 666)));

    AgendaOverload agenda2;
    agenda2.adicionaContato(*(new ContatoOverload("D", 666)));
    agenda2.adicionaContato(*(new ContatoOverload("E", 666)));
    agenda2.adicionaContato(*(new ContatoOverload("A", 666)));

    cout << "Antes Sub" << endl;
    cout << "Agenda 1" << endl;
    cout << agenda1;
    cout << "Agenda 2" << endl;
    cout << agenda2;

    agenda1 - agenda2;

    cout << "Depois Sub" << endl;
    cout << "Agenda 1" << endl;
    cout << agenda1;
    cout << "Agenda 2" << endl;
    cout << agenda2;

    agenda1 + agenda2;
    cout << "Depois Soma" << endl;
    cout << "Agenda 1" << endl;
    cout << agenda1;
    cout << "Agenda 2" << endl;
    cout << agenda2;

    AgendaOverload agenda3(agenda2);

    cout << "Copia Agenda2" << endl;
    cout << agenda3 << endl;

}

void ex2e3(){
    AgendaOverload agenda1;
    Colega colega2("Colega2", 666, 10, 10);
    ContatoOverload contato1("contato1", 666);
    agenda1.adicionaContato(colega2);
    agenda1.adicionaContato(colega2);
    agenda1.adicionaContato(contato1);

    ContatoOverload *contatoP = &colega2;
    cout << agenda1 << endl;
}

void ex3(){
    AgendaHerdaVetor agenda1;
    agenda1.push_back(new ContatoOverload("C", 666));
    agenda1.push_back(new ContatoOverload("B", 666));
    agenda1.push_back(new ContatoOverload("A", 666));

    AgendaHerdaVetor agenda2;
    agenda2.push_back(new ContatoOverload("D", 666));
    agenda2.push_back(new ContatoOverload("E", 666));
    agenda2.push_back(new ContatoOverload("A", 66));

    cout << "Antes Sub" << endl;
    cout << "Agenda 1" << endl;
    cout << agenda1;
    cout << "Agenda 2" << endl;
    cout << agenda2;

    agenda1 - agenda2;

    cout << "Depois Sub" << endl;
    cout << "Agenda 1" << endl;
    cout << agenda1;
    cout << "Agenda 2" << endl;
    cout << agenda2;

    agenda1 + agenda2;
    cout << "Depois Soma" << endl;
    cout << "Agenda 1" << endl;
    cout << agenda1;
    cout << "Agenda 2" << endl;
    cout << agenda2;

}


int main(){
    //ex1();
    //ex2e3();
    ex3();
    return 0;
}