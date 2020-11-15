#pragma once
#include "conductor.h"
class datoConductor
{
private:
    conductor reg;
    FILE * p;
    const char* PATH_CONDUCTOR = "../datos/conductor.dat";
    bool exito = false;
public:
    int cantidadRegistros();
    bool guardarConductor(conductor reg);
    bool leerConductor(int pos, conductor &leer);
    bool modificarConductor(conductor mod, int pos);
    int buscarRegistro(int ID);
};