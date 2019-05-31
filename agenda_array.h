#ifndef AGENDA_ARRAY_H
#define AGENDA_ARRAY_H
#include <string>

using namespace std;

class Agenda{
    public:
        void addName(string nome);
        string* getNames();

    private:
    	const static int maxNomes = 20;
        string listaNomes[maxNomes];
        static int nNome;
};

#endif