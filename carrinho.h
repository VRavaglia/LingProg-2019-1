#ifndef CARRINHO_H
#define CARRINHO_H

#include <string>
#include <vector>
#include <iostream>


class Produto{
public:
	Produto(std::string tipo, std::string marca, float preco);
	std::string getTipo();
	std::string getMarca();
	float getPreco();
private:
	std::string tipo;
	std::string marca;
	float preco;
};

class Carrinho{
friend std::ostream & operator<<(std::ostream &out, Carrinho &carrinho);

public:
	explicit Carrinho(unsigned max);
	Carrinho(const Carrinho &);
	~Carrinho();
	Carrinho & operator+(Produto &produto);
	Carrinho & operator-(Produto &produto);
private:
	unsigned max;
	std::vector<Produto *> produtos;
};


#endif