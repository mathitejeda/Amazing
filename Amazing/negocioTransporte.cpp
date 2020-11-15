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


transporte negocioTransporte::leerTransporte(int pos) {
    datosTransporte dt;
    return dt.leerTransporte(pos);
}

void negocioTransporte::ordenarTransportes(transporte *vec)
{
    datosTransporte dt;
    dt.cargarVector(vec);
    int i, j, pos;
    transporte aux;
    for (i = 0;i < dt.cantidadRegistros();i++) {
        pos = i;
        for (j = 0;j < dt.cantidadRegistros() + 1;j++) {
            if (vec[j].getID() > vec[i].getID()) {
                pos = j;
            }
        }
        aux = vec[i];
        vec[i] = vec[pos];
        vec[pos] = aux;
    }


}

int negocioTransporte::bucarTransporte(int ID)
{
    datosTransporte dt;
    return dt.buscarRegistro(ID);
}
