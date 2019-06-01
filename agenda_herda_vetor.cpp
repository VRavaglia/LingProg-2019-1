
#include "agenda_herda_vetor.h"


AgendaHerdaVetor &AgendaHerdaVetor::operator+(AgendaHerdaVetor &agenda) {
    for(int i = 0; i < agenda.size(); i++){
        this->push_back(new ContatoOverload(*agenda.at(i)));
    }

    return *this;
}

AgendaHerdaVetor &AgendaHerdaVetor::operator-(AgendaHerdaVetor &agenda) {
    int max = size();
    int i = 0;
    vector<string> nomesRepetidos;
    while(i < max){
        bool achou = false;
        for(int j = 0; j < agenda.size(); j++){
            if(this->at(i)->getNome() == agenda.at(j)->getNome()){
                achou = true;
            }
        }
        if(achou){
            nomesRepetidos.push_back(this->at(i)->getNome());
            delete this->at(i);
            this->erase(this->begin() + i);
            i--;
            max--;
        }
        i++;
    }
    for (int k = 0; k < agenda.size(); ++k) {
        bool achou = false;
        for (int j = 0; j < nomesRepetidos.size(); ++j) {
            if(agenda.at(k)->getNome() == nomesRepetidos.at(j)){
                achou = true;
            }
        }
        if(!achou){
            this->push_back(new ContatoOverload(*agenda.at(k)));
        }
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, AgendaHerdaVetor &agenda){
    for(auto contato : agenda){
        out << contato->print() << endl;
    }
    return out;
}

