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
    virtual std::string print();

private:
	std::string nome;
	int telefone;

};

class Colega: public ContatoOverload{
public:
    Colega(std::string nome, int telefone, int classe, int turma);
    std::string print() override;
    int getClasse();
    int getTurma();
private:
    int classe;
    int turma;
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