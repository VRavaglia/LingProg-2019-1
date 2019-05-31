#include <iostream>
#include "fibonacci-sc.h"
#include <string>
#include "agenda.h"
#include "paralelepipedo.h"
#include "Distancia.h"
using namespace std;

void test1(){
    int n = 0;
    cin >> n;
    cout << "Teu numero: " << fibonacci(n) << endl;
}

void test2(){
    int n = 0;
    cin >> n;
    Fibonacci fib;
    fib.computeFibonacci(n);
    cout << "Teu numero: " << fib.getFib() << endl;
}

void test3(){
    string nome;

    Agenda agenda;
    int nomes = 0;
    cout << "Digite 3 nomes: " << endl;
    while (nomes < 3){
        cin >> nome;
        agenda.setNames(nome);
        nomes = agenda.getNames().size();
    }
    cout << "Lista de nomes: " << endl;
    cout << agenda.getNames()[0] << endl;
    cout << agenda.getNames()[1] << endl;
    cout << agenda.getNames()[2] << endl;

}

void test4(){
    double x, y, z;
    cout << "Insira as dimensoes do paralelepipedo: " << endl;
    cin >> x;
    cin >> y;
    cin >> z;
    Paralelepipedo par(x,y,z);
    cout << "Volume do paralelepipedo: " << par.getVolume() << endl;
}

void test5(){
    double x, y, z;
    Distancia dis;
    cout << "Insira as coordenadas do primeiro ponto: " << endl;
    cin >> x;
    cin >> y;
    cin >> z;
    dis.setPontoA(x,y,z);
    cout << "Insira as coordenadas do segundo ponto: " << endl;
    cin >> x;
    cin >> y;
    cin >> z;
    dis.setPontoB(x,y,z);
    cout << "A distancia entre os pontos eh: " << dis.getDistancia() << endl;
};

int main(){
    test5();
    return 0;
}