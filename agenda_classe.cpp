#include "agenda_classe.h"
#include <string>
#include <iostream>

int AgendaClasse::nNome = 0;

void AgendaClasse::insertCad(Cadastro cad){
    string nome = cad.getName();
    if (nome.length() > 10){
        cad.setNome(nome.substr(0, 10));
        cout << "O nome era muito grande, foi utilizado: " << cad.getName() << endl;
    }
    listaNomes[nNome] = cad;
    nNome++;
}


void AgendaClasse::showNames() {
    for (int i = 0; i <  nNome; ++i) {
        cout << "Nome: " << listaNomes[i].getName() << endl;
        cout << "Profissao: " << listaNomes[i].getProfissao() << endl;
        cout << "Idade: " << listaNomes[i].getIdade() << endl;
    }
}


void Cadastro::setNome(string nome_) {
    nome = nome_;
}

void Cadastro::setProfissao(string profissao_) {
    profissao = profissao_;
}

void Cadastro::setIdade(int idade_) {
    idade = idade_;
}

string Cadastro::getName() {
    return nome;
}

string Cadastro::getProfissao() {
    return profissao;
}

int Cadastro::getIdade() {
    return idade;
}
