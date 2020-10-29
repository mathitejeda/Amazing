#pragma once
#include "persona.h"

class conductor:public persona
{
public:
	conductor();
	~conductor();
	
	void setLegajo(int legajo);

	int getLegajo() { return legajo; }
private:
	int legajo;
};

conductor::conductor()
{
}

conductor::~conductor()
{
}
