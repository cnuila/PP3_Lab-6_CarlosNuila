#include "Pintura.h"

Pintura::Pintura(){
    color = "";
    acabado ="";
}
Pintura::Pintura(string color,string acabado){
    this->color = color;
    this->acabado = acabado;
}

string Pintura::getColor(){
    return color;
}
void Pintura::setColor(string color){
    this->color = color;
}

string Pintura::getAcabado(){
    return acabado;
}
void Pintura::setAcabado(string acabado){
    this->acabado = acabado;
}

string Pintura::toString(){
    return "Pintura: /nColor: "+color+" Acabado: "+acabado;
}