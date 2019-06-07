#ifndef LISTARESTRITAENCADEADA_H
#define LISTARESTRITAENCADEADA_H

#include <iostream>

template <class T>
class no{
public:
    no(T t);
    no *proximo;
    no *anterior;
    T valor;
};

template<class T>
no<T>::no(T t) {
    valor = t;
    anterior = nullptr;
    proximo = nullptr;
}

template <class T>
class listaRestritaEncadeada {
public:
    listaRestritaEncadeada();
    ~listaRestritaEncadeada();
    void push_back(T t);
    void push_front(T t);
    bool pop_back(T &t);
    bool pop_front(T &t);
    void print();

private:
    void init(T t);
    no<T> *primeiro;
    no<T> *ultimo;
};


template<class T>
listaRestritaEncadeada<T>::listaRestritaEncadeada() {
    primeiro = nullptr;
    ultimo = nullptr;
}

template<class T>
listaRestritaEncadeada<T>::~listaRestritaEncadeada() {
    no<T> *atual = primeiro;
    while (atual){
        no<T> *anterior = atual;
        atual = atual->proximo;
        delete anterior;
    }
}

template<class T>
void listaRestritaEncadeada<T>::init(T t) {
    primeiro  = new no<T>(t);
    ultimo = primeiro;
}

template<class T>
void listaRestritaEncadeada<T>::push_back(T t) {
    if(!primeiro){
        init(t);
        return;
    }
    no<T> *proximo = new no<T>(t);
    ultimo->proximo = proximo;
    proximo->anterior = ultimo;
    ultimo = proximo;
}

template<class T>
void listaRestritaEncadeada<T>::push_front(T t) {
    if(!primeiro){
        init(t);
        return;
    }
    no<T> *anterior = new no<T>(t);
    primeiro->anterior = anterior;
    anterior->proximo = primeiro;
    primeiro = anterior;
}

template<class T>
bool listaRestritaEncadeada<T>::pop_back(T &t) {
    if(!primeiro){
        return false;
    }
    no<T> *atual = ultimo;
    ultimo = ultimo->anterior;
    ultimo->proximo = nullptr;
    delete atual;
}

template<class T>
bool listaRestritaEncadeada<T>::pop_front(T &t) {
    if(!primeiro){
        return false;
    }

    no<T> *atual = primeiro;
    primeiro = primeiro->proximo;
    primeiro->anterior = nullptr;
    delete atual;
}

template<class T>
void listaRestritaEncadeada<T>::print() {
    no<T> *atual = primeiro;
    while (atual){
        std::cout << atual->valor << std::endl;
        atual = atual->proximo;
    }
}

#endif
