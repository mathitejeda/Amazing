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

transporte datosTransporte::leerTransporte(int pos)
{
    if (pos >= 0) {
        p = fopen(PATH_TRANSPORTE, "rb");
        if (p == NULL) {
            std::cout << "error en lectura";
            return reg;
        }
        fseek(p, pos * sizeof(reg), SEEK_SET);
        exito = fread(&reg, sizeof(reg), 1, p);
        fclose(p);
        return reg;
    }
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

void datosTransporte::cargarVector(transporte *vec) {
    int cant = cantidadRegistros();
    vec = (transporte*)malloc(cant * sizeof(transporte));
    if (vec == NULL) {
        return;
    }
    p = fopen(PATH_TRANSPORTE, "rb");
    if (p == NULL) {
        free(vec);
        return;
    }
    fread(&vec[0], sizeof(transporte), cant, p);
    fclose(p);
}
