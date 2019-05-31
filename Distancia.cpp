
#include "Distancia.h"
#include <math.h>

Distancia::Distancia() {
    distancia = 0;
}

void Distancia::setPontoA(double x, double y, double z) {
    a.setX(x);
    a.setY(y);
    a.setZ(z);
}

Ponto Distancia::getPontoA() {
    return a;
}

void Distancia::setPontoB(double x, double y, double z) {
    b.setX(x);
    b.setY(y);
    b.setZ(z);
}

Ponto Distancia::getPontoB() {
    return b;
}

double Distancia::getDistancia() {
    distancia = calculaDistancia(a, b);
    return distancia;
}

double Distancia::calculaDistancia(Ponto a, Ponto b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2) + pow(a.getZ() - b.getZ(), 2));
}

Ponto::Ponto() {
    setX(0);
    setY(0);
    setZ(0);
}

double Ponto::getX() {
    return x;
}

double Ponto::getY() {
    return y;
}

double Ponto::getZ() {
    return z;
}

void Ponto::setX(double x_) {
    x = x_;
}

void Ponto::setY(double y_) {
    y = y_;
}

void Ponto::setZ(double z_) {
    z = z_;
}
