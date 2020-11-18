#pragma once
#include "envio.h"
class datosEnvio
{
private:
	FILE* p;
	envio reg;
	const char* PATH_ENVIO = "../datos/envio.dat";
public:
	int cantidadRegistros();
	bool guardarEnvio(envio reg);
	bool leerEnvio(envio& leer, int pos);
	bool modificarEnvio(envio mod, int pos);

};

