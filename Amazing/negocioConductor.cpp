#include <iostream>
#include "negocioConductor.h"
#include "datoConductor.h"

bool negocioConductor::nuevoConductor(conductor reg){
    datoConductor dc;    
    reg.setLegajo(dc.cantidadRegistros()+1);
    reg.setEstado(true);
    reg.setVehiculo(-1);
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

int negocioConductor::buscarConductor(int dato,int criterio)
{
    int i = 0;
    conductor buscar;
    switch (criterio)
    {
    case 1:
        while (dc.leerConductor(i, buscar)) {
            if (buscar.getLegajo() == dato) {
                if (buscar.getEstado() == true) return i;
            }
            i++;
        }
        break;

    case 2:
        while (dc.leerConductor(i, buscar)) {
            if (buscar.getVehiculo() == dato) {
                if (buscar.getEstado() == true) return i;
            }
            i++;
        }
        break;
    default:
        return -1;
        break;
    }
    return -1;
}

