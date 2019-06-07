#ifndef LISTARESTRITAVETOR_H
#define LISTARESTRITAVETOR_H

#include <vector>

template <class T>
class listaRestritaVetor: public std::vector<T> {
    bool push_front(T);
    bool pop_back(T &);
    bool pop_front(T &);
};


template<class T>
bool listaRestritaVetor<T>::push_front(T t) {
    return this->insert(this->begin(), t);
}

template<class T>
bool listaRestritaVetor<T>::pop_back(T &t) {
    t = this->at(this->size());
    this->erase(this->begin() + this->size());
    return true;
}

template<class T>
bool listaRestritaVetor<T>::pop_front(T &t) {
    t = this->at(0);
    for(unsigned i = 0; i < this->size(); i++){
        this->at(i) = this->at(i + 1);
    }
    this->erase(this->begin() + this->size());
    return true;
}


#endif
