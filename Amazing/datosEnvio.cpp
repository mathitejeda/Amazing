#include <iostream>
#include "datosEnvio.h"

int datosEnvio::cantidadRegistros()
{
    int tamanio, bytes;
    p = fopen(PATH_ENVIO, "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    tamanio = bytes / sizeof(reg);
    fclose(p);
    return tamanio;
}

bool datosEnvio::guardarEnvio(envio reg)
{
    bool exito = false;
    p = fopen(PATH_ENVIO, "ab");
    if (p == NULL) return false;
    exito = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
	return exito;
}

bool datosEnvio::leerEnvio(envio& leer, int pos)
{
    if (pos >= 0) {
        bool exito = false;
        p = fopen(PATH_ENVIO, "rb");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(leer), SEEK_SET);
        exito = fread(&leer, sizeof(leer), 1, p);
        fclose(p);
        return exito;
    }
	return false;
}

bool datosEnvio::modificarEnvio(envio mod, int pos)
{
    if (pos >= 0) {
        bool exito = false;
        p = fopen(PATH_ENVIO, "rb+");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(mod), SEEK_SET);
        exito = fwrite(&mod, sizeof(mod), 1, p);
        fclose(p);
        return exito;
    }
	return false;
}
