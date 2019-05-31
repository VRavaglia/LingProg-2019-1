#ifndef AGENDA_PONTEIRO_H
#define AGENDA_PONTEIRO_H
#include <string>
#include <vector>

using namespace std;

class Cadastro
{
public:
    void setNome(string nome);
    void setProfissao(string profissao);
    void setIdade(int idade);
    string getNome();
    string getProfissao();
    int getIdade();


private:
    string nome;
    string profissao;
    int idade;

};


class AgendaClasse{
public:
    ~AgendaClasse();
    void insertCad(Cadastro *cad);
    bool removeCad(string nome);
    void alteraNomeCad(string nomeAntigo, string nomeNovo);
    void alteraProfissaoCad(string nome, string profissao);
    void alteraIdadeCad(string nome, int idade);
    void listaContatos();

private:
    vector<Cadastro*> cadastros;
};



#endif