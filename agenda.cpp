#include "agenda.h"
#include <string>
#include <iostream>

void AgendaClasse::setNames(string nome){
    if (nome.length() > 10){
        nome = nome.substr(0, 10);
        cout << "O nome era muito grande, foi utilizado: " << nome << endl;
    }
    listaNomes.push_back(nome);
}

vector <string> AgendaClasse::getNames(){
    return listaNomes;
}