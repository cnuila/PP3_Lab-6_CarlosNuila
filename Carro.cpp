#include "Carro.h"
#include "Chasis.h"
#include "Motor.h"
#include "Pintura.h"
using namespace std;

Carro::Carro(){
    modelo = "";
    numModelo = 0;
}

Carro::Carro(string mod,string numMod,Chasis cha,Motor mot,Pintura pint){
    modelo = mod;
    numModelo = numModelo;
    chasis = cha;
    motor = mot;
    pintura = pint;
}

string Carro::getModelo(){
    return modelo;
}
void Carro::setModelo(string mod){
    modelo = mod;
}

int Carro::getNumModelo(){
    return numModelo;
}
void Carro::setNumModelo(int numMod){
    numModelo = numMod;
}

Chasis Carro::getChasis(){
    return chasis;
}
void Carro::setChasis(Chasis cha){
    chasis = cha;
}

Motor Carro::getMotor(){
    return motor;
}
void Carro::setMotor(Motor mot){
    motor = mot;
}

Pintura Carro::getPintura(){
    return pintura;
}
void Carro::setPintura(Pintura pint){
    pintura = pint;
}

string Carro::toString(){
    string numModel = "";
    numModel = to_string(numModelo);
    return "Modelo: "+modelo+numModel+chasis.toString()+motor.toString()+pintura.toString();
}
