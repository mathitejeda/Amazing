#pragma once
#include "persona.h"

class cliente:public persona
{
public:
	cliente();
	~cliente();

	void setTelefono(int telefono);
	void setDomicilio(char domicilio[50]);

	int getTelefono() { return telefono; }
	const char* getDomicilio() { return domicilio; }

private:
	int telefono;
	char domicilio[50];
};

cliente::cliente()
{
}

cliente::~cliente()
{
}

