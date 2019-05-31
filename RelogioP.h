#ifndef RELOGIO_P_H
#define RELOGIO_P_H

#include <time.h>
#include <stdlib.h>
#include <string>

class PonteiroDeRelogio{
public:
    PonteiroDeRelogio(std::string tipo);
    void resetHora();
    int getValor() const;

private:
    std::string tipo;
    time_t hora;
    struct tm *infoHora;
};

class RelogioP
{
public:
	RelogioP();
    int getSeg() const;
    int getMin() const;
    int getHora() const;

private:

	PonteiroDeRelogio seg;
    PonteiroDeRelogio min;
    PonteiroDeRelogio hr;
};



#endif