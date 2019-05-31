#include <iostream>
#include <string>
#include "carrinho.h"
#include "jogo.h"

using namespace std;

void ex1(){
    Produto calca("calca", "13", 200);
    Produto oculos("oculos", "ray ban", 1222);
    Produto polo("polo", "polo", 3000);
    Carrinho outfitSchreiber(5);
    outfitSchreiber = outfitSchreiber + calca;
    outfitSchreiber = outfitSchreiber + oculos;
    outfitSchreiber = outfitSchreiber + polo;
    cout << outfitSchreiber << endl;
    outfitSchreiber = outfitSchreiber - calca;
    cout << outfitSchreiber << endl;
    Carrinho outfitGilbert = outfitSchreiber;
    cout << outfitGilbert << endl;
}

void ex2(){
	Jogo jogo(4);
	
	Personagem hulk("Hulk", 90, 20);
	Personagem homemDeFerro("Homem de Ferro", 60, 90);
	Personagem capitao("Capitao America", 50, 70);
	Personagem thor("Thor", 80, 60);

	jogo(hulk)(homemDeFerro)(capitao)(thor);

	if (jogo["Hulk"]){
		cout << jogo["Hulk"] << endl;
	}
	else{
		cout << "Personagem nao encontrado!" << endl;
	}

	if (jogo["Homem Formiga"]){
		cout << jogo["Homem Formiga"] << endl;
	}
	else{
		cout << "Personagem nao encontrado!" << endl;
	}
    cout << endl;
	cout << "Todos: " << endl;
	for (unsigned i = 0; i < jogo.getNumeroPersonagens(); i++){
		cout << jogo [i] << endl;
	}


	cout << "*** Mais Forte:\n"
		  << calculaEstatistica(jogo, maisForte) << endl;
	cout << "*** Mais Inteligente:\n"
		  << calculaEstatistica(jogo, maisInteligente) << endl;
}

int main(){
    ex2();
    return 0;
}
