#include <iostream>
#include "negocioTransporte.h"
#include "datosTransporte.h"

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

bool negocioTransporte::leerTransporte(int pos, transporte& leer) {
    datosTransporte dt;
    return dt.leerTransporte(pos, leer);
}
