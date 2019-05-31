#include "nome.h"
#include <string>

MeuNome::MeuNome(string nome){
    setNome(nome);
}
string MeuNome::getNome() const{
    return nome;
}
string MeuNome::getNome(){
    return nome;
}
void MeuNome::setNome(string nome){
    this->nome = nome;
}

