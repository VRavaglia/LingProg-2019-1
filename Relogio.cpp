#include "Relogio.h"
#include <time.h>
#include <stdlib.h>

Relogio::Relogio(){
	resetHora();
}

Relogio::Relogio(int seg, int min, int hora){
	infoHora = (tm *) malloc(sizeof(tm));
	setSeg(seg);
	setMin(min);
	setHora(hora);

}
Relogio::~Relogio(){
	free(infoHora);
}
void Relogio::resetHora(){
	time(&hora);
	struct tm *tempInfohora = localtime(&hora);
	infoHora->tm_sec = tempInfohora->tm_sec;
	infoHora->tm_min = tempInfohora->tm_min;
	infoHora->tm_hour = tempInfohora->tm_hour;
}

int Relogio::getSeg() const{
	return infoHora->tm_sec;
}
int Relogio::getMin() const{
	return infoHora->tm_min;
}
int Relogio::getHora() const{
	return infoHora->tm_hour;
}
Relogio & Relogio::setSeg(int seg){
	infoHora->tm_sec = seg;
	return *this;
}
Relogio & Relogio::setMin(int min){
	infoHora->tm_min = min;
	return *this;
}
Relogio & Relogio::setHora(int hora){
	infoHora->tm_hour = hora;
	return *this;
}