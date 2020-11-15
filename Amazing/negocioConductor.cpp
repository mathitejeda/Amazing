#include <iostream>
#include "negocioConductor.h"
#include "datoConductor.h"

bool negocioConductor::nuevoConductor(conductor reg){
    datoConductor dc;    
    reg.setLegajo(dc.cantidadRegistros()+1);
    return dc.guardarConductor(reg);
}

bool negocioConductor::modificarConductor(conductor mod, int pos){
    datoConductor dc;
    return dc.modificarConductor(mod,pos);
}

bool negocioConductor::leerConductor(conductor &leer, int pos)
{
    if (dc.leerConductor(pos, leer)) {
        return true;
    }
    return false;
}

int negocioConductor::buscarConductor(int legajo)
{
    int i = 0;
    conductor buscar;
    while (dc.leerConductor(i,buscar)) {
        if (buscar.getLegajo() == legajo) {
            return i;
        }
        i++;
    }
    return -1;
}

