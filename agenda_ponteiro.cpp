#include "agenda_ponteiro.h"
#include <string>
#include <iostream>
#include <stdlib.h>

void AgendaClasse::insertCad(Cadastro *cad){
    cadastros.push_back(cad);
}


void AgendaClasse::listaContatos() {
    for (unsigned i = 0; i <  cadastros.size(); ++i) {
        cout << "Nome: " << cadastros.at(i)->getNome() << endl;
        cout << "Profissao: " << cadastros.at(i)->getProfissao() << endl;
        cout << "Idade: " << cadastros.at(i)->getIdade() << endl;
    }
}

bool AgendaClasse::removeCad(string nome){
    for (unsigned i = 0; i <  cadastros.size(); ++i) {
        if (cadastros.at(i)->getNome() == nome){
            cadastros.erase(cadastros.begin() + i);
            return true;
        }
    } 
    return false;
}
void AgendaClasse::alteraNomeCad(string nomeAntigo, string nomeNovo){
    for (unsigned i = 0; i <  cadastros.size(); ++i) {
        if (cadastros.at(i)->getNome() == nomeAntigo){
            cadastros.at(i)->setNome(nomeNovo);
        }
    } 
}
void AgendaClasse::alteraProfissaoCad(string nome, string profissao){
    for (unsigned i = 0; i <  cadastros.size(); ++i) {
        if (cadastros.at(i)->getNome() == nome){
            cadastros.at(i)->setProfissao(profissao);
        }
    } 
}
void AgendaClasse::alteraIdadeCad(string nome, int idade){
    for (unsigned i = 0; i <  cadastros.size(); ++i) {
        if (cadastros.at(i)->getNome() == nome){
            cadastros.at(i)->setIdade(idade);
        }
    } 
}

AgendaClasse::~AgendaClasse(){
    for (unsigned i = 0; i < cadastros.size(); ++i)
    {
        free(cadastros.at(i));
    }
}


void Cadastro::setNome(string nome_) {
    if (nome_.length() > 10){
        nome_ = nome_.substr(0, 10);
        cout << "O nome era muito grande, foi utilizado: " << nome_ << endl;
    }
    nome = nome_;
}

void Cadastro::setProfissao(string profissao_) {
    profissao = profissao_;
}

void Cadastro::setIdade(int idade_) {
    idade = idade_;
}

string Cadastro::getNome() {
    return nome;
}

string Cadastro::getProfissao() {
    return profissao;
}

int Cadastro::getIdade() {
    return idade;
}
