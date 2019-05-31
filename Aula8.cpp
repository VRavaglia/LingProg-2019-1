#include <iostream>
#include <string>
#include "forca.h"
#include "pilha.h"

using namespace std;

void ex1(){
    Forca forca("palavras.txt", 4);
    forca.execute();
}

void ex2(){
    ForcaSobrecarga forca("palavrasMaisDicas.txt", 4);
    forca.execute();
}

void ex3(){
    Pilha pilha(3);
    int i;
    cout << "Tamanho maximo 3" << endl;
    cout << "Desempilha: " << endl;
    cout << pilha.pop(i) << endl;
    cout << "Numero do final: " << i << endl;
    cout << "Empilha 4 vezes" << endl;
    cout << pilha.push(1) << endl;
    cout << pilha.push(2) << endl;
    cout << pilha.push(3) << endl;
    cout << pilha.push(1) << endl;
    cout << "Desempilha: " << endl;
    cout << pilha.pop(i) << endl;
    cout << "Numero do final: " << i << endl;

}

int main(){
    srand (time(nullptr));
    ex3();
    return 0;
}