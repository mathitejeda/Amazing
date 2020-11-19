#pragma once
#include "transporte.h"

class negocioTransporte
{
private:

public:
	int getCant();
	bool nuevoTransporte(transporte reg);
	bool modificarTransporte(transporte mod,int);
	bool leerTransporte(transporte& leer, int pos);
	void ordenarTransportes(transporte *vec);
	int bucarTransporte(int ID);

};

