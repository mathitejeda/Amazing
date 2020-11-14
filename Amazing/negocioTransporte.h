#pragma once
#include "transporte.h"

class negocioTransporte
{
public:
	bool nuevoTransporte(transporte reg);
	bool modificarTransporte(transporte mod,int);
	bool leerTransporte(int pos, transporte& leer);

};

