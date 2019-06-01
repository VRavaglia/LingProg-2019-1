#ifndef AGENDA_HERDA_VETOR_H
#define AGENDA_HERDA_VETOR_H

#include "agenda_overload.h"

#include <vector>
#include <string>

using namespace std;

class AgendaHerdaVetor: public vector<ContatoOverload*> {
    friend std::ostream &operator<<(std::ostream &out, AgendaHerdaVetor &agenda);
public:
    AgendaHerdaVetor() = default;
    AgendaHerdaVetor &operator+(AgendaHerdaVetor &agenda);
    AgendaHerdaVetor &operator-(AgendaHerdaVetor &agenda);

};


#endif
