#ifndef AGENDA_H
#define AGENDA_H
#include <string>
#include <vector>

using namespace std;

class AgendaClasse{
    public:
        void setNames(string nome);
        vector <string> getNames();

    private:
        vector <string> listaNomes;
};

#endif