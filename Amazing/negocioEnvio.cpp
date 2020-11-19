#include <iostream>
#include "negocioEnvio.h"
#include "datosEnvio.h"

bool negocioEnvio::nuevoEnvio(envio reg)
{
    return dE.guardarEnvio(reg);
}

bool negocioEnvio::modificarEnvio(envio mod, int pos)
{
    return dE.modificarEnvio(mod,pos);
}

bool negocioEnvio::leerEnvio(envio& leer, int pos)
{
    return dE.leerEnvio(leer,pos);
}

int negocioEnvio::buscarEnvio(int id)
{
	int i = 0;
	envio buscar;
	while (dE.leerEnvio(buscar,i)) {
		if (buscar.getID() == id) {
			return i;
		}
		i++;
	}
	return -1;
}

int negocioEnvio::generarID()
{
	int ID = dE.cantidadRegistros() + 1;
	return ID;
}
