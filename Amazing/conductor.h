#pragma once
#include "persona.h"

class conductor:public persona
{
public:
	void setLegajo(int legajo);

	int getLegajo() { return legajo; }
private:
	int legajo;
};