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