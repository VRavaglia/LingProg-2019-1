#include "jogo.h"
#include <string>
#include <vector>

using namespace std;

Personagem::Personagem(string nome, unsigned forca, unsigned inteligencia){
	this->nome = nome;
	this->forca = forca;
	this->inteligencia = inteligencia;
}

Jogo::Jogo(unsigned max){
	this->max = max;
	personagens.reserve(max);
}

Jogo &Jogo::operator()(Personagem &personagem){
	if(personagens.size() < max){
		personagens.push_back(personagem);
	}
	return *this;
}

unsigned Jogo::getNumeroPersonagens(){
	return personagens.size();
}

Personagem *Jogo::operator[](const char* nome) {
    for (unsigned i = 0; i < getNumeroPersonagens(); ++i) {
        if (personagens.at(i).nome.compare(nome) == 0){
            return &personagens.at(i);
        }
    }
    return nullptr;
}

Personagem *Jogo::operator[](unsigned i) {
    if(i >= 0 && i < getNumeroPersonagens()){
        return &personagens.at(i);
    }
    return nullptr;
}

ostream &operator<<(ostream &out, Personagem *personagem) {
    out << "|Nome: " << personagem->nome << " | Forca: " << personagem->forca << " | Inteligencia: " << personagem->inteligencia << " |";
    return out;
}

Personagem *calculaEstatistica(Jogo &jogo, int (*comparacao)(Personagem &, Personagem &)) {
    unsigned n = 0;
    if(jogo.getNumeroPersonagens() > 0){
        for (unsigned i = 0; i < jogo.getNumeroPersonagens(); ++i) {
            if(comparacao(jogo.personagens.at(i), jogo.personagens.at(n)) == 1){
                n = i;
            }
        }
        return &jogo.personagens.at(n);
    }
    return nullptr;

}

int maisForte(Personagem &personagem1, Personagem &personagem2) {
    if (personagem1.forca > personagem2.forca){
        return 1;
    }
    if (personagem1.forca < personagem2.forca){
        return -1;
    }
    return 0;
}

int maisInteligente(Personagem &personagem1, Personagem &personagem2) {
    if (personagem1.inteligencia > personagem2.inteligencia){
        return 1;
    }
    if (personagem1.inteligencia < personagem2.inteligencia){
        return -1;
    }
    return 0;
}
