#include "agenda_classe_vector.h"
#include <string>
#include <iostream>

void AgendaClasseVector::insertCad(CadastroVector cad){
    string nome = cad.getName();
    if (nome.length() > 10){
        cad.setNome(nome.substr(0, 10));
        cout << "O nome era muito grande, foi utilizado: " << cad.getName() << endl;
    }
    listaNomes.push_back(cad);
}


void AgendaClasseVector::showNames() {
    for (int i = 0; i <  nNome; ++i) {
        cout << "Nome: " << listaNomes[i].getName() << endl;
        cout << "Profissao: " << listaNomes[i].getProfissao() << endl;
        cout << "Idade: " << listaNomes[i].getIdade() << endl;
    }
}


void CadastroVector::setNome(string nome_) {
    nome = nome_;
}

void CadastroVector::setProfissao(string profissao_) {
    profissao = profissao_;
}

void CadastroVector::setIdade(int idade_) {
    idade = idade_;
}

string CadastroVector::getName() {
    return nome;
}

string CadastroVector::getProfissao() {
    return profissao;
}

int CadastroVector::getIdade() {
    return idade;
}
