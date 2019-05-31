#include "RelogioP.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

RelogioP::RelogioP() : seg("seg"), min("min"), hr("hr"){
    seg.resetHora();
    min.resetHora();
    hr.resetHora();
}

int RelogioP::getSeg() const {
    return seg.getValor();
}

int RelogioP::getMin() const {
    return min.getValor();
}

int RelogioP::getHora() const {
    return hr.getValor();
}

PonteiroDeRelogio::PonteiroDeRelogio(std::string tipo) {
    this->tipo = tipo;
    infoHora = (tm *) malloc(sizeof(tm));
}

void PonteiroDeRelogio::resetHora(){
	time(&hora);
	struct tm *tempInfohora = localtime(&hora);
	infoHora->tm_sec = tempInfohora->tm_sec;
	infoHora->tm_min = tempInfohora->tm_min;
	infoHora->tm_hour = tempInfohora->tm_hour;
}

int PonteiroDeRelogio::getValor() const {
    if (tipo == "seg"){
        return infoHora->tm_sec;
    }
    if (tipo == "min"){
        return infoHora->tm_min;
    }
    if (tipo == "hr"){
        return infoHora->tm_hour;
    }
    cout << "Formato de hora, minuto ou segundo nao entendido." << endl;
    return 0;
}
