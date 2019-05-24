#ifndef CHASIS_H
#define CHASIS_H
#include <string>
using std::string;

class Chasis{

    private:
        string tipoRueda;
        string transmision;

    public:
        Chasis();
        Chasis(string,string);

        string getTipoRueda();
        void setTipoRueda(string);

        string getTransmision();
        void setTransmision(string);

        string toString();
};

#endif