#include "Motor.h"

Motor::Motor(){
    electrico = "";
    configuracion ="";
}
Motor::Motor(string elect,string config){
    electrico = elect;
    configuracion = config;
}

string Motor::getElectrico(){
    return electrico;
}
void Motor::setElectrico(string elect){
    electrico = elect;
}

string Motor::getConfiguracion(){
    return configuracion;
}
void Motor::setConfiguracion(string config){
    configuracion = config;
}

string Motor::toString(){
    return "Motor: /nEs Electrico: "+electrico+" Configuracion: "+configuracion;
}