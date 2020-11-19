#include <iostream>
#include "datosTransporte.h"

int datosTransporte::cantidadRegistros()
{
    int tamanio, bytes;
    p = fopen(PATH_TRANSPORTE, "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    tamanio = bytes / sizeof(reg);
    fclose(p);
    return tamanio;
}

bool datosTransporte::guardarTransporte(transporte reg)
{
    p = fopen(PATH_TRANSPORTE, "ab");
    if (p == NULL) return false;
    exito = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return exito;
}

bool datosTransporte::leerTransporte(transporte&leer,int pos)
{
    if (pos >= 0) {
        p = fopen(PATH_TRANSPORTE, "rb");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(leer), SEEK_SET);
        exito = fread(&leer, sizeof(leer), 1, p);
        fclose(p);
        return exito;
    }
    return false;
}

bool datosTransporte::modificarTransporte(transporte mod, int pos)
{
    if (pos >= 0) {
        p = fopen(PATH_TRANSPORTE, "rb+");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(mod), SEEK_SET);
        exito = fwrite(&mod, sizeof(mod), 1, p);
        fclose(p);
        return exito;
    }
    else return false;
}

int datosTransporte::buscarRegistro(int id)
{
    p = fopen(PATH_TRANSPORTE, "rb");
    if (p == NULL) return -1;
    int pos = 0;
    while (fread(&reg, sizeof(reg), 1, p)) {
        if (reg.getID() == id && reg.getEstado()) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    return -2;
}


