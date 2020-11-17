#pragma once
#include "persona.h"

class conductor:public persona
{
public:
	void setLegajo(int legajo);
	void setVehiculo(int id);
	void setEstado(bool estado);

	int getLegajo() { return legajo; }
	int getVehiculo() { return idVehiculo; }
	bool getEstado() { return estado; }
private:
	int legajo;
	int idVehiculo;
	bool estado;
};