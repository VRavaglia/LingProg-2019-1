#ifndef NOME_H
#define NOME_H
#include <string>

using namespace std;

class MeuNome{
public:
    MeuNome(string nome);
    string getNome() const;
    string getNome();
    void setNome(string nome);
private:
    string nome;
};



#endif