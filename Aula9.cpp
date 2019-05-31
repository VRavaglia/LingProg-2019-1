#include <iostream>
#include <string>
#include "agenda_overload.h"

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


int main(){
    ex1();
    return 0;
}