#include "Carro.h"
#include "Motor.h"
#include "Chasis.h"
#include "Pintura.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void freeMatrix(char **&matrix, int size);
void printMatrix(char **matrix, int size);

int main()
{
    char **matrix = NULL;
    int size = 5;
    matrix = new char *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new char[4];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j] = ' ';
        }
    }
    vector<Carro *> prototipos;
    vector<Carro *> carrosFinalizados;
    vector<Carro *> carrosLineaproduccion;
    int opcion = 0;
    bool sigue = true;
    while (sigue)
    {
        cout << "Menu" << endl
             << "1)Agregar Linea de Produccion" << endl
             << "2)Ver Matriz de Produccion" << endl
             << "3)Ver linea de Produccion" << endl
             << "4)Ver listado de Carros" << endl
             << "5)Avanzar ciclo de linea de produccion" << endl
             << "6)Salir" << endl
             << "Ingrese su opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            string modelo;
            cout << "Ingrese el nombre del modelo: ";
            cin >> modelo;

            //creacion de chasis

            string tipoRuedas;
            cout << "Ingrese el tipo de Ruedas: ";
            cin >> tipoRuedas;

            string transmision;
            int temp = -1;
            while (temp < 0 || temp > 1)
            {
                cout << "Tiene transmision automatica[0] o no[1]: ";
                cin >> temp;
            }
            if (temp == 0)
            {
                transmision = "Automatica";
            }
            else
            {
                transmision = "Mecanico";
            }

            Chasis *chasis = new Chasis(tipoRuedas, transmision);

            //creacion de motor
            string electrico = "";
            int temp2 = -1;
            while (temp2 < 0 || temp2 > 1)
            {
                cout << "Es electrico[0] o no[1]: ";
                cin >> temp2;
            }
            if (temp2 == 0)
            {
                electrico = "Si";
            }
            else
            {
                electrico = "No";
            }

            string configuracion;
            cout << "Ingrese la configuracion: ";
            cin >> configuracion;

            Motor *motor = new Motor(electrico, configuracion);

            //creacion pintura
            string color;
            cout << "Ingrese el color: ";
            cin >> color;

            string acabado;
            cout << "Ingrese el acabado: ";
            cin >> acabado;
            int numModelo = 0;
            Pintura *pintura = new Pintura(color, acabado);
            if (prototipos.size() <= 5)
            {
                prototipos.push_back(new Carro(modelo, numModelo, chasis, motor, pintura));
                matrix[prototipos.size() - 1][0] = 'P';
            }
            else
            {
                cout << "Solo se pueden crear 5 prototipos";
            }
            break;
        }
        case 2:
        {
            printMatrix(matrix, size);
            break;
        }
        case 3:
        {
            if (!carrosLineaproduccion.empty())
            {
                for (int i = 0; i < carrosLineaproduccion.size(); i++)
                {
                    cout << "i = " << i <<endl;
                    cout << i + 1 << ")" << carrosLineaproduccion[i]->toString() << endl;
                }
            }
            else
            {
                cout << "No hay carros en la linea de produccion" << endl;
            }
            break;
        }
        case 4:
        {
            if (!carrosFinalizados.empty())
            {
                for (int i = 0; i < carrosFinalizados.size(); i++)
                {
                    cout << i + 1 << ")" << carrosFinalizados[i]->toString() << endl;
                }
            }
            else
            {
                cout << "No hay carros finalizados" << endl;
            }
            break;
        }
        case 5:
        {
            for (int i = 0; i < prototipos.size(); i++)
            {
                if (matrix[i][0] == 'P')
                {
                    carrosLineaproduccion.push_back(new Carro());
                    carrosLineaproduccion[carrosLineaproduccion.size() - 1]->setModelo(prototipos[i]->getModelo());
                    int numModelo = -1;
                    for (int j = 0; j < carrosLineaproduccion.size(); j++)
                    {
                        if (!carrosLineaproduccion.empty())
                        {
                            if (carrosLineaproduccion[j]->getModelo() == prototipos[i]->getModelo())
                            {
                                if (numModelo < carrosLineaproduccion[j]->getNumModelo())
                                {
                                    numModelo = carrosLineaproduccion[j]->getNumModelo()+1;
                                }
                            }
                        }
                    }
                    
                    carrosLineaproduccion[carrosLineaproduccion.size() - 1]->setNumModelo(numModelo);
                    for (int j = 4; j > 1; j--)
                    {
                        if (matrix[i][j - 1] != ' ')
                        {
                            matrix[i][j] = 'C';
                            cout << matrix[i][j] << " DSaadsdadsa";
                            break;
                        }
                    }
                    for (int j = 0; j < carrosLineaproduccion.size(); j++)
                    {
                        if (carrosLineaproduccion[j]->getChasis() == NULL)
                        {
                            carrosLineaproduccion[j]->setChasis(prototipos[i]->getChasis());
                        }
                        else
                        {
                            if (carrosLineaproduccion[j]->getMotor() == NULL)
                            {
                                carrosLineaproduccion[j]->setMotor(prototipos[i]->getMotor());
                            }
                            else
                            {
                                if (carrosLineaproduccion[j]->getPintura() == NULL)
                                {
                                    carrosLineaproduccion[j]->setPintura(prototipos[i]->getPintura());
                                }
                                else
                                {
                                    carrosFinalizados.push_back(carrosLineaproduccion[j]);
                                    carrosLineaproduccion.erase(carrosLineaproduccion.begin() + j - 1);
                                }
                            }
                        }
                    }
                }
            }
            break;
        }
        case 6:
        {
            sigue = false;
        }
        }
    }
    for (int i = 0; i < carrosFinalizados.size(); i++)
    {
        if (!carrosFinalizados.empty())
        {
            delete carrosFinalizados[i];
        }
    }
    for (int i = 0; i < prototipos.size(); i++)
    {
        if (!prototipos.empty())
        {
            delete prototipos[i];
        }
    }
    for (int i = 0; i < carrosLineaproduccion.size(); i++)
    {
        if (!carrosLineaproduccion.empty())
        {
            delete carrosLineaproduccion[i];
        }
    }
    freeMatrix(matrix, size);
    return 0;
}

void printMatrix(char **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "[" << matrix[i][j] << "]";
        }
        cout << endl;
    }
}

void freeMatrix(char **&matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (matrix[i] != NULL)
        {
            delete[] matrix[i];
            matrix[i] = NULL;
        }
    }
    if (matrix != NULL)
    {
        delete[] matrix;
        matrix = NULL;
    }
}
