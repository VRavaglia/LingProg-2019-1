#include "carrinho.h"
#include <string>
#include <vector>
#include <iostream>


using namespace std;


Produto::Produto(string tipo, string marca, float preco){
	this->tipo = tipo;
	this->marca = marca;
	this->preco = preco;
}

string Produto::getTipo(){
	return tipo;
}
string Produto::getMarca(){
	return marca;
}
float Produto::getPreco(){
	return preco;
}

Carrinho::Carrinho(unsigned max){
	this->max = max;
	produtos.reserve(max);
}

Carrinho & Carrinho::operator+(Produto &produto){
	if(produtos.size() < max){
		produtos.push_back(&(produto));
	}
	return *this;
}
Carrinho & Carrinho::operator-(Produto &produto){
	size_t n = -1;
	for(size_t i = 0; i< produtos.size(); i++){
		if(produtos.at(i) == &produto){
			break;
		}
	}
	if(n >= 0){
		produtos.erase (produtos.begin()+n);
	}
	return *this;
}

Carrinho::Carrinho(const Carrinho &carrinho){
    this->max = carrinho.max;
	produtos.reserve(carrinho.produtos.size());
	for(size_t i = 0; i< carrinho.produtos.size(); i++){
		produtos.push_back(new Produto(carrinho.produtos.at(i)->getTipo(), carrinho.produtos.at(i)->getMarca(), carrinho.produtos.at(i)->getPreco()));
	}
}

Carrinho::~Carrinho(){
	for(size_t i = 0; i< produtos.size(); i++){
		delete produtos.at(i);
	}
}

ostream & operator<<(ostream &out, Carrinho &carrinho){
	for(size_t i = 0; i< carrinho.produtos.size(); i++){
		out << "|Tipo : " << carrinho.produtos.at(i)->getTipo() << " | Marca: " << carrinho.produtos.at(i)->getMarca() << " | Preco: " << carrinho.produtos.at(i)->getPreco() << " |" << endl;
	}
	return  out;
}