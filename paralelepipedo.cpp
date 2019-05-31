#include "paralelepipedo.h"

Paralelepipedo::Paralelepipedo(double a, double b, double c){
    x = a;
    y = b;
    z = c;
    setVolume(x,y,z);
}

void Paralelepipedo::setVolume(double a, double b, double c){
    x = a;
    y = b;
    z = c;
    volume = a*b*c;
}

double Paralelepipedo::getVolume(){
    return volume;
}