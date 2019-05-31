#include "nome_ponteiro.h"
#include <string>
#include <stdlib.h> 
#include <stdio.h>
#include <cstring>

MeuNomeP::MeuNomeP(string nome){
    setNome(nome);
}

MeuNomeP::~MeuNomeP(){
    free(nome);
}
string MeuNomeP::getNome() const{
    return nome;
}
string MeuNomeP::getNome(){
    return nome;
}
void MeuNomeP::setNome(string nome){
    this->nome = (char *) malloc(sizeof(char)*nome.length());
    std::strcpy(this->nome, nome.c_str());
}

