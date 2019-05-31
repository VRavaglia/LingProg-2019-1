#ifndef AGENDA_OVERLOAD_H
#define AGENDA_OVERLOAD_H
#include <vector>
#include <string>
#include <iostream>

class ContatoOverload{
public:
	ContatoOverload(std::string nome, int telefone);
	std::string getNome();
    int getTelefone();

private:
	std::string nome;
	int telefone;

};


class AgendaOverload{
    friend std::ostream &operator<<(std::ostream &out, AgendaOverload &agenda);
public:
    AgendaOverload();
	AgendaOverload(AgendaOverload &);
	~AgendaOverload();
	void removeContato(std::string nome);
	void adicionaContato(ContatoOverload &contato);
	AgendaOverload &operator+(AgendaOverload &agenda);
	AgendaOverload &operator-(AgendaOverload &agenda);
	

private:
	std::vector <ContatoOverload *> contatos;

};

#endif