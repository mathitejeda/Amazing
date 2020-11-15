#pragma once
#include "persona.h"

class conductor:public persona
{
public:
	void setLegajo(int legajo);
	void setVehiculo(int id);

	int getLegajo() { return legajo; }
	int getVehiculo() { return idVehiculo; }
private:
	int legajo;
	int idVehiculo;
};