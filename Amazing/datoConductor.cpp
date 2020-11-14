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

bool datoConductor::leerConductor(int pos)
{
    if (pos >= 0)
    {
        p = fopen(PATH_CONDUCTOR, "rb");
        if (p == NULL)
            return false;
        fseek(p, pos * sizeof(reg), SEEK_SET);
        exito = fread(&reg, sizeof(reg), 1, p);
        return exito;
    }
    else
        return false;
}

int datoConductor::cantidadRegistros()
{
    int tamanio, byte;
    p = fopen(PATH_CONDUCTOR, "rb");
    if (p == NULL)
        return false;
    fseek(p, sizeof(reg), SEEK_END);
    byte = ftell(p);
    fclose(p);
    return tamanio = byte / sizeof(reg);
}

bool datoConductor::modificarConductor(conductor mod, int pos)
{
    bool exito;
    if (pos >= 0)
    {
        p = fopen(PATH_CONDUCTOR, "rb+");
        if (p == NULL)
            return false;
        if (leerConductor(pos))
        {
            exito = fwrite(&mod, sizeof(reg), 1, p);
        }
        else
            exito = false;
        fclose(p);
        return exito;
    }
    else
        return false;
}
