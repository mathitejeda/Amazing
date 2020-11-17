#include <iostream>
#include "datoConductor.h"

bool datoConductor::guardarConductor(conductor reg)
{
    p = fopen(PATH_CONDUCTOR, "ab");
    if (p == NULL)
        return false;
    exito = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return exito;
}

bool datoConductor::leerConductor(int pos, conductor & leer)
{
    if (pos >= 0)
    {
        p = fopen(PATH_CONDUCTOR, "rb");
        if (p == NULL)
            return false;
        fseek(p, pos * sizeof(leer), SEEK_SET);
        exito = fread(&leer, sizeof(leer), 1, p);
        fclose(p);
        return exito;
    }
    else
        return false;
}

int datoConductor::cantidadRegistros()
{
    int cant, bytes;
    p = fopen(PATH_CONDUCTOR, "rb");
    if (p == NULL)
        return 0;
    fseek(p, 0 , SEEK_END);
    bytes = ftell(p);
    cant = bytes / sizeof(reg);
    fclose(p);
    return cant;
}

bool datoConductor::modificarConductor(conductor mod, int pos)
{
    bool exito;
    if (pos >= 0) {
        p = fopen(PATH_CONDUCTOR, "rb+");
        if (p == NULL)return false;
        fseek(p, pos * sizeof(mod), SEEK_SET);
        exito = fwrite(&mod, sizeof(mod), 1, p);
        fclose(p);
        return exito;
    }
    else return false;
}
