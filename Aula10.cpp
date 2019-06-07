#include <iostream>
#include <string>
#include "listaRestritaVetor.h"
#include "listaRestritaEncadeada.h"
#include "ListaRestrita.h"
#include "arvore.h"
#include <iostream>

using namespace std;

void ex1(){
    int retorno;
    ListaRestrita <int> lista(5);
    cout << "Lista vazia: " << endl;
    lista.print();
    cout << "Lista com push front: " << endl;
    lista.push_front(1);
    lista.print();
    cout << "Lista com push front: " << endl;
    lista.push_front(2);
    lista.print();
    cout << "Lista com push back: " << endl;
    lista.push_back(3);
    lista.print();
    cout << "Lista com push back: " << endl;
    lista.push_back(4);
    lista.print();
    cout << "Lista com pop front: " << endl;
    lista.pop_front(retorno);
    lista.print();
    cout << "Lista com pop back: " << endl;
    lista.pop_back(retorno);
    lista.print();
}

void ex3(){
    int retorno;
    listaRestritaEncadeada <int> lista;
    cout << "Lista vazia: " << endl;
    lista.print();
    cout << "Lista com push front: " << endl;
    lista.push_front(1);
    lista.print();
    cout << "Lista com push front: " << endl;
    lista.push_front(2);
    lista.print();
    cout << "Lista com push back: " << endl;
    lista.push_back(3);
    lista.print();
    cout << "Lista com push back: " << endl;
    lista.push_back(4);
    lista.print();
    cout << "Lista com pop front: " << endl;
    lista.pop_front(retorno);
    lista.print();
    cout << "Lista com pop back: " << endl;
    lista.pop_back(retorno);
    lista.print();
}

void ex4(){
    arvore<int> av;
    cout << "Arvore vazia: " << endl;
    av.print(av.raiz);
    cout << "Arvore com 1 a 5" << endl;
    av.insere(1);
    av.insere(2);
    av.insere(3);
    av.insere(4);
    av.insere(5);
    av.print(av.raiz);

}

int main(){
    ex4();
    return 0;
}