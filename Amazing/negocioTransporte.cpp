#include <iostream>
#include "negocioTransporte.h"
#include "datosTransporte.h"

int negocioTransporte::getCant()
{
    datosTransporte dt;
    return dt.cantidadRegistros();
}

bool negocioTransporte::nuevoTransporte(transporte reg)
{
    datosTransporte dt;
    reg.setID(dt.cantidadRegistros() + 1);
    return dt.guardarTransporte(reg);
}

bool negocioTransporte::modificarTransporte(transporte mod, int pos)
{
    datosTransporte dt;
    return dt.modificarTransporte(mod, pos);
}


bool negocioTransporte::leerTransporte(transporte &leer,int pos) {
    datosTransporte dt;
    return dt.leerTransporte(leer,pos);
}

int negocioTransporte::bucarTransporte(int ID)
{
    datosTransporte dt;
    return dt.buscarRegistro(ID);
}
