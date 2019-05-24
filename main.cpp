#include "Carro.h"
#include "Motor.h"
#include "Chasis.h"
#include "Pintura.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

    char respuesta = 'S';
    while (respuesta == 'S' || respuesta == 's'){
    int opcion = 0;
    while(opcion <= 0 || opcion > 6){
        cout << "Menu" <<endl
        << "1)Agregar Linea de Produccion" <<endl
        << "2)Ver Matriz de Produccion" <<endl
        << "3)Ver linea de Produccion" <<endl
        << "4)Ver listado de Carros" <<endl
        << "5)Avanzar ciclo de linea de produccion" <<endl
        << "6)Salir"
        << "Ingrese su opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            {
                ;

                break;
            }
    }
    cout << "¿Desea volver a hacerlo[s/n]?: ";
    cin >>  respuesta;
    }
    return 0;
}
