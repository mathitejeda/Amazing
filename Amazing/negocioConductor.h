#pragma once
#include "conductor.h"
#include "datoConductor.h"

class negocioConductor
{
private:
    datoConductor dc;
public:
    bool nuevoConductor(conductor reg);
    bool modificarConductor(conductor mod, int pos);
    bool leerConductor(conductor &leer, int pos);
    int buscarConductor(int legajo);
};
