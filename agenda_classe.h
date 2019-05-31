#ifndef AGENDA_CLASSE_H
#define AGENDA_CLASSE_H
#include <string>

using namespace std;

class Cadastro
{
public:
    void setNome(string nome);
    void setProfissao(string profissao);
    void setIdade(int idade);
    string getName();
    string getProfissao();
    int getIdade();


private:
    string nome;
    string profissao;
    int idade;

};


class AgendaClasse{
public:
    void insertCad(Cadastro cad);
    void showNames();

private:
    const static int maxNomes = 20;
    Cadastro listaNomes[maxNomes];
    static int nNome;
};



#endif