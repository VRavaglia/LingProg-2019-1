#ifndef LINGPROG_PILHA_H
#define LINGPROG_PILHA_H

#include <vector>

class Pilha: std::vector<int> {
public:
    Pilha(unsigned max);
    bool push(int n);
    bool pop(int &n);

private:
    unsigned max;
};


#endif //LINGPROG_PILHA_H
