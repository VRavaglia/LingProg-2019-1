#include "agenda_array.h"
#include <string>
#include <iostream>

int Agenda::nNome = 0;

void Agenda::addName(string nome){
    if (nome.length() > 10){
        nome = nome.substr(0, 10);
        cout << "O nome era muito grande, foi utilizado: " << nome << endl;
    }
    listaNomes[nNome] = nome;
    nNome++;
}

string * Agenda::getNames(){
    return listaNomes;
}