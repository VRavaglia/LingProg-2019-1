#include <vector>
#include <string>
#include "agenda_overload.h"

using namespace std;

ContatoOverload::ContatoOverload(string nome, int telefone){
	this->nome = nome;
	this->telefone = telefone;
}

std::string ContatoOverload::getNome() {
    return nome;
}

int ContatoOverload::getTelefone() {
    return telefone;
}

std::string ContatoOverload::print() {
    return "Nome: " + nome + " Telefone: " + to_string(telefone);
}

AgendaOverload::AgendaOverload(AgendaOverload &agenda){
	for(int i = 0; i < agenda.contatos.size(); i++){
		contatos.push_back(new ContatoOverload(*agenda.contatos.at(i)));
	}
}

AgendaOverload::AgendaOverload() = default;

AgendaOverload::~AgendaOverload(){
	for (int i = 0; i < contatos.size(); i++){
		delete contatos.at(i);
	}
}

void AgendaOverload::removeContato(string nome){
	for(int i = 0 ; i < contatos.size(); i++){
		if(contatos.at(i)->getNome() == nome){
			delete contatos.at(i);
			contatos.erase(contatos.begin() + i);
			break;
		}
	}
}

void AgendaOverload::adicionaContato(ContatoOverload &contato){
	contatos.push_back(&contato);
}

AgendaOverload &AgendaOverload::operator+(AgendaOverload &agenda){
	for(int i = 0; i < agenda.contatos.size(); i++){
		this->contatos.push_back(new ContatoOverload(*agenda.contatos.at(i)));
	}

    return *this;
}

AgendaOverload &AgendaOverload::operator-(AgendaOverload &agenda){
    int max = contatos.size();
    int i = 0;
    vector<string> nomesRepetidos;
	while(i < max){
		bool achou = false;
		for(int j = 0; j < agenda.contatos.size(); j++){
			if(contatos.at(i)->getNome() == agenda.contatos.at(j)->getNome()){
                achou = true;
			}
		}
		if(achou){
		    nomesRepetidos.push_back(contatos.at(i)->getNome());
		    delete contatos.at(i);
		    contatos.erase(contatos.begin() + i);
		    i--;
		    max--;
		}
		i++;
	}
    for (int k = 0; k < agenda.contatos.size(); ++k) {
        bool achou = false;
        for (int j = 0; j < nomesRepetidos.size(); ++j) {
            if(agenda.contatos.at(k)->getNome() == nomesRepetidos.at(j)){
                achou = true;
            }
        }
        if(!achou){
            contatos.push_back(new ContatoOverload(*agenda.contatos.at(k)));
        }
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, AgendaOverload &agenda) {
    for(auto contato : agenda.contatos){
        out << contato->print() << endl;
    }
    return out;
}

Colega::Colega(std::string nome, int telefone, int classe, int turma): ContatoOverload(nome, telefone) {
    this->classe = classe;
    this->turma = turma;
}

int Colega::getClasse() {
    return classe;
}

int Colega::getTurma() {
    return turma;
}

std::string Colega::print() {
    return "Nome: " + getNome() + " Telefone: " + to_string(getTelefone()) + " Classe:" + to_string(classe) + " Turma: " + to_string(turma);
}
