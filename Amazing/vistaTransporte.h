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
	void modificarTransporte(int);
	void bajaTransporte(int id);
	void listarTransportes();
	void mostrarTransporte(transporte mostrar,bool masivo = false);
};

