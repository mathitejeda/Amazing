#pragma once
#include "envio.h"
#include "datosEnvio.h"

class negocioEnvio
{
private:
	datosEnvio dE;
public:
	bool nuevoEnvio(envio reg);
	bool modificarEnvio(envio mod, int pos);
	bool leerEnvio(envio& leer, int pos);
	int buscarEnvio(int id);
	int generarID();
};

