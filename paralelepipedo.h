#ifndef PARALELEPIPEDO_H
#define PARALELEPIPEDO_H

class Paralelepipedo{
    

    public:
        Paralelepipedo(double x, double y, double z);
        void setVolume(double x, double y, double z);
        double getVolume();


    private:

        double x;
        double y;
        double z;
        double volume;
};

#endif