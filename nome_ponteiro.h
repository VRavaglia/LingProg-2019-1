#ifndef NOME_P_H
#define NOME_P_H
#include <string>

using namespace std;

class MeuNomeP{
public:
    MeuNomeP(string nome);
    ~MeuNomeP();
    string getNome() const;
    string getNome();
    void setNome(string nome);
private:
    char *nome;
};



#endif