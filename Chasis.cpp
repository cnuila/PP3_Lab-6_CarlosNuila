#include "Chasis.h"

Chasis::Chasis(){
    tipoRueda = "";
    transmision = "";
}

Chasis::Chasis(string tipoR,string trans){
    tipoRueda = tipoR;
    transmision = trans;
}

string Chasis::getTipoRueda(){
    return tipoRueda;
}
void Chasis::setTipoRueda(string tipoR){
    tipoRueda = tipoR;
}

string Chasis::getTransmision(){
    return transmision;
}
void Chasis::setTransmision(string trans){
    transmision = trans;
}

string Chasis::toString(){
    return " Chasis: /nTipo de Rueda: "+tipoRueda+" Transmision: "+transmision;
}