#include "transporte.h"
#include <iostream>

using namespace std;

inline void transporte::setID(int ID)
{
	this->ID = ID;
}

inline void transporte::setTipoVehiculo(int tipo)
{
	this->tipoVehiculo = tipo;
}

inline void transporte::setPatente(char patente[7])
{
	strcpy(this->patente, patente);
}


