#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

template <class T>
class ramo{
public:
    ramo(T t);
    ~ramo();
    ramo *direita;
    ramo *esquerda;
    T valor;
};

template<class T>
ramo<T>::ramo(T t) {
    valor = t;
    esquerda = nullptr;
    direita = nullptr;
}

template<class T>
ramo<T>::~ramo() {
    std::cout << "Vlw, flw..." << std::endl;
    delete esquerda;
    delete direita;
}

template <class T>
class arvore {
public:
    arvore();
    ~arvore();
    void insere(T t);
    void print(ramo<T> *r);
    ramo<T> *raiz;

private:
    void caminha(ramo<T> *r, T t);
    void destroi(ramo<T> *r);

};


template<class T>
arvore<T>::arvore() {
    raiz = nullptr;
}

template<class T>
arvore<T>::~arvore() {
    delete raiz;
}

template<class T>
void arvore<T>::insere(T t) {
    if(!raiz){
        raiz = new ramo<T>(t);
        return;
    }
    caminha(raiz, t);
}

template<class T>
void arvore<T>::caminha(ramo<T> *r, T t) {
    if(r->valor < t){
        if (!r->esquerda){
            ramo<T> *esquerda = new ramo<T>(t);
            r->esquerda = esquerda;
            return;
        }
        caminha(r->esquerda, t);
        return;
    }
    if(!r->direita){
        ramo<T> *direita = new ramo<T>(t);
        r->esquerda = direita;
        return;
    }
    caminha(r->direita, t);
}

template<class T>
void arvore<T>::print(ramo<T> *r) {
    if(r){
        std::cout << r->valor << std::endl;
        if (r->esquerda){
            print(r->esquerda);
        }
        if (r->direita){
            print(r->direita);
        }
    }
}


template<class T>
void arvore<T>::destroi(ramo<T> *r) {
    if (r->esquerda){
        print(r->esquerda);
    }
    if (r->direita){
        print(r->direita);
    }
}

#endif
