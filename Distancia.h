#ifndef DISTANCIA_H
#define DISTANCIA_H

class Ponto{
public:
    Ponto();
    double getX();
    double getY();
    double getZ();
    void setX(double x);
    void setY(double y);
    void setZ(double z);

private:
    double x, y, z;
};

class Distancia {
    public:
        Distancia();

    void setPontoA(double x, double y, double z);
        Ponto getPontoA();
        void setPontoB(double x, double y, double z);
        Ponto getPontoB();
        double getDistancia();

    private:
        Ponto a, b;
        double distancia;
        double calculaDistancia(Ponto a, Ponto b);
};




#endif
