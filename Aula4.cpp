#include <iostream>
#include <string>
#include "agenda_array.h"
#include "agenda_classe.h"
#include "agenda_classe_vector.h"

using namespace std;

void test1(){
    string nome;

    Agenda agenda;
    int nomes = 0;
    cout << "Digite 3 nomes: " << endl;
    while (nomes < 3){
        getline(cin, nome);
        agenda.addName(nome);
        nomes++;
    }
    cout << "Lista de nomes: " << endl;
    cout << agenda.getNames()[0] << endl;
    cout << agenda.getNames()[1] << endl;
    cout << agenda.getNames()[2] << endl;

}

void test2(){
    string nome;
    string profissao;
    int idade;

    AgendaClasse agenda;
    int cadastros = 0;
    cout << "Digite nome, profissao e idade: " << endl;
    while (cadastros < 3){
        Cadastro cad;
        cin >> nome;
        cad.setNome(nome);
        cin >> profissao;
        cad.setProfissao(profissao);
        cin >> idade;
        cad.setIdade(idade);
        agenda.insertCad(cad);
        cadastros++;
    }
    agenda.showNames();

}
int main(){
    test2();
    return 0;
}