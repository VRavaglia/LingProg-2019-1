#include <iostream>
#include <string>
#include "nome.h"
#include "nome_ponteiro.h"
#include "Relogio.h"
#include "RelogioP.h"


using namespace std;

void ex1(){
    MeuNome nome1("Raposo");
    const MeuNome nome2("Raposo");
    cout << "Nome 1: " << nome1.getNome() << "| Nome2: " << nome2.getNome() << endl;
}

void ex2(){
    MeuNomeP nome1("Raposo");
    const MeuNomeP nome2("Raposo");
    cout << "Nome 1: " << nome1.getNome() << "| Nome2: " << nome2.getNome() << endl;
}

void ex3(){
    Relogio relogio(20, 20, 20);
    cout << "|" << relogio.getHora() << "|" << relogio.getMin() << "|" << relogio.getSeg() << "|" << endl;
    relogio.resetHora();
    cout << "|" << relogio.getHora() << "|" << relogio.getMin() << "|" << relogio.getSeg() << "|" << endl;
    relogio.setHora(20).setMin(20).setSeg(20);
    cout << "|" << relogio.getHora() << "|" << relogio.getMin() << "|" << relogio.getSeg() << "|" << endl;
}

void ex4(){
    RelogioP relogio;
    cout << "|" << relogio.getHora() << "|" << relogio.getMin() << "|" << relogio.getSeg() << "|" << endl;
}



int main(){
    ex4();
    return 0;
}