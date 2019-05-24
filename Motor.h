#ifndef MOTOR_H
#define MOTOR_H
#include <string>
using std::string;

class Motor{

    private:
        string electrico;
        string configuracion;

    public:
        Motor();
        Motor(string,string);

        string getElectrico();
        void setElectrico(string);

        string getConfiguracion();
        void setConfiguracion(string);

        string toString();
};

#endif