#include "forca.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>

void Forca::geraPalavra(string nomeArquivo) {
    string linha;
    vector<string> linhas;

    ifstream arquivo (nomeArquivo);
    if (arquivo.is_open())
    {
        while ( getline (arquivo,linha) )
        {
            linhas.push_back(linha);
        }
        arquivo.close();
    }

    unsigned r;
    if(!linhas.empty()){
        r = rand() % (linhas.size()/2);
    }
    else{
        cout << "Erro ao ler o arquivo." << endl;
        return;
    }


    palavra = linhas.at(r);
    dica = linhas.at(r + 1);
    descobertas.clear();
    descobertas.reserve(linhas.size());
    for (unsigned i = 0; i < palavra.size() - 1; ++i) {
        descobertas.push_back(false);
    }
}

Forca::Forca(string nomeArquivo, unsigned tentativas){
    this->nomeArquivo = nomeArquivo;
    this->tentativas = tentativas;
}

void Forca::execute() {
    geraPalavra(nomeArquivo);
    cout << "Dica para a palavra: " << dica << endl;
    cout << "A palavra tem " << (palavra.size() - 1) << " letras." << endl;
    while(true){
        cout << "Digite um caractere, ou 0 para sair:" << endl;
        char resposta;
        cin >> resposta;
        if (resposta == '0'){
            cout << "Saindo..." << endl;
            return;
        }
        if (! teste(resposta)){
            tentativas--;
        }
        if (tentativas == 0){
            cout << "Voce perdeu!" << endl;
            return;
        }
        if (ganhou()){
            cout << "Voce ganhou!" << endl;
        }
        cout << "Palavra: " << palavraFormatada() << endl;
    }
}

bool Forca::teste(char c) {
    bool encontrou = false;

    for (unsigned i = 0; i < palavra.length(); ++i) {
        if(tolower(c) == tolower(palavra.at(i))) {
            encontrou = true;
            descobertas.at(i) = true;
        }
    }

    return encontrou;
}

string Forca::palavraFormatada() {
    string formatada = "(";
    for (unsigned i = 0; i < descobertas.size(); ++i) {
        if (descobertas.at(i)){
            formatada += palavra.at(i);
        } else{
            formatada += "_";
        }
    }
    formatada += ")";

    return formatada;
}


bool Forca::ganhou() {
    for (unsigned i = 0; i < descobertas.size(); ++i) {
        if(!descobertas.at(i)){
            return false;
        }

    }
    return true;
}

ForcaSobrecarga::ForcaSobrecarga(string nomeArquivo, unsigned tentativas) : Forca(nomeArquivo, tentativas) {
    this->nomeArquivo = nomeArquivo;
    this->tentativas = tentativas;
}

bool ForcaSobrecarga::operator<<(char c) {
    return teste(c);
}

void ForcaSobrecarga::geraPalavra(string nomeArquivo) {
    string linha;
    vector<string> linhas;

    ifstream arquivo (nomeArquivo);
    if (arquivo.is_open())
    {
        while ( getline (arquivo,linha) )
        {
            linhas.push_back(linha);
        }
        arquivo.close();
    }

    unsigned r;
    if(!linhas.empty()){
        r = rand() % (linhas.size()/3);
    }
    else{
        cout << "Erro ao ler o arquivo." << endl;
        return;
    }


    palavra = linhas.at(r);
    dica1 = linhas.at(r + 1);
    dica2 = linhas.at(r + 2);
    descobertas.clear();
    descobertas.reserve(linhas.size());
    for (unsigned i = 0; i < palavra.size() - 1; ++i) {
        descobertas.push_back(false);
    }
}

void ForcaSobrecarga::execute() {
    geraPalavra(nomeArquivo);
    cout << "Dica para a palavra: " << dica1 << endl;
    cout << "Dica para a palavra: " << dica2 << endl;
    cout << "A palavra tem " << (palavra.size() - 1) << " letras." << endl;
    while(true){
        cout << "Digite um caractere, ou 0 para sair:" << endl;
        char resposta;
        cin >> resposta;
        if (resposta == '0'){
            cout << "Saindo..." << endl;
            return;
        }
        if (! (*this << resposta)){
            tentativas--;
        }
        if (tentativas == 0){
            cout << "Voce perdeu!" << endl;
            return;
        }
        if (ganhou()){
            cout << "Voce ganhou!" << endl;
        }
        cout << "Palavra: " << palavraFormatada() << endl;
    }
}

