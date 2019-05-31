#ifndef JOGO_H
#define JOGO_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Personagem{
public:
	Personagem(string nome, unsigned forca, unsigned inteligencia);
	string nome;
	unsigned inteligencia;
	unsigned	forca;
};

class Jogo{
friend ostream &operator<<(ostream &out, Personagem *personagem);
friend Personagem *calculaEstatistica(Jogo &jogo, int (*comparacao)(Personagem &, Personagem &));
public:
	explicit Jogo(unsigned max);
	Jogo& operator()(Personagem &personagem);
	Personagem *operator[](const char* nome);
	Personagem *operator[](unsigned i);
	unsigned getNumeroPersonagens();

private:
	vector <Personagem> personagens;
	unsigned max;
};


int maisForte(Personagem &personagem1,Personagem &personagem2);
int maisInteligente(Personagem &personagem1,Personagem &personagem2);

#endif
