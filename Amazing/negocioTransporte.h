#pragma once
#include "transporte.h"

class negocioTransporte
{
private:

public:
	int getCant();
	bool nuevoTransporte(transporte reg);
	bool modificarTransporte(transporte mod,int);
	transporte leerTransporte(int pos);
	void ordenarTransportes(transporte *vec);
	int bucarTransporte(int ID);

};

