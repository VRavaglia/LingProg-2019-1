#include "pilha.h"
#include <vector>

Pilha::Pilha(unsigned max) {
    this->max = max;
}

bool Pilha::push(int n) {
    if (size() == max){
        return false;
    }
    push_back(n);
    return true;
}

bool Pilha::pop(int &n) {
    if (empty()){
        return false;
    }

    n = back();
    pop_back();

    return true;
}
