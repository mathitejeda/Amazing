#pragma once
#include "transporte.h"
class datosTransporte
{
private:
	FILE* p;
	transporte reg;
	const char* PATH_TRANSPORTE = "../datos/transporte.dat";
	bool exito = false;

public:
	int cantidadRegistros();
	bool guardarTransporte(transporte);
	bool leerTransporte(transporte& leer, int);
	bool modificarTransporte(transporte, int);
	int buscarRegistro(int);
};

