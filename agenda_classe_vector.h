#ifndef AGENDA_CLASSE_VECTOR_H
#define AGENDA_CLASSE_VECTOR_H
#include <string>
#include <vector>

using namespace std;

class CadastroVector
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


class AgendaClasseVector{
public:
    void insertCad(CadastroVector cad);
    void showNames();

private:
    vector <CadastroVector> listaNomes;
};



#endif