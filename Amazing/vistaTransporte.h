#pragma once
#include "negocioTransporte.h"
class vistaTransporte
{
private:
	negocioTransporte negocioT;
	int opc;
	int var;
public:
	void menuTransporte();
	void nuevoTransporte();
	void modificarTransporte();
	void bajaTransporte();
	void listarTransportes();
	void mostrarTransporte(int);
};

