#pragma once
#include "fecha.h"

class transporte
{
public:
	transporte();
	~transporte();

	void setID(int ID);
	void setTipoVehiculo(int tipo);
	void setPatente(char patente[7]);

	int getID() { return ID; }
	int getTipo() { return tipoVehiculo; }
	const char* getPatente() { return patente; }
	void getVencimiento() { return vencimientoVTV.mostrarFecha(); }
	bool getSeguro() { return seguro; }
	bool getCirculacion() { return circulacion; }

	

private:
	int tipoVehiculo, ID;
	char patente[7];
	bool seguro, circulacion;
	fecha vencimientoVTV;
};

enum tipoVehiculo
{
	moto = 1,
	ligero = 2,
	pesado = 3
};

transporte::transporte()
{
}

transporte::~transporte()
{
}


