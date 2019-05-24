#ifndef CARRO_H
#define CARRO_H
#include <string>
#include "Chasis.h"
#include "Motor.h"
#include "Pintura.h"
using std::string;

class Carro{

    private:
        string modelo;
        int numModelo;
        Chasis chasis;
        Motor motor;
        Pintura pintura;

    public:
        Carro();
        Carro(string,string,Chasis,Motor,Pintura);

        string getModelo();
        void setModelo(string);

        int getNumModelo();
        void setNumModelo(int);

        Chasis getChasis();
        void setChasis(Chasis);

        Motor getMotor();
        void setMotor(Motor);

        Pintura getPintura();
        void setPintura(Pintura);

        string toString();
};

#endif
