#pragma once
#include "fecha.h"

class transporte
{
public:

	void setID(int ID);
	void setModeloVehiculo(const char* modelo);
	void setTipoVehiculo(int tipo);
	void setPatente(const char* patente);


	int getID() { return ID; }
	int getTipo() { return tipoVehiculo; }
	const char* getPatente() { return patente; }
	const char* getModelo() { return modelo; }
	void getVencimiento() { return vencimientoVTV.mostrarFecha(); }
	bool getSeguro() { return seguro; }
	bool getCirculacion() { return circulacion; }

	

private:
	int tipoVehiculo, ID;
	char patente[10], modelo[50];
	bool seguro, circulacion;
	fecha vencimientoVTV;
};

enum tipoVehiculo
{
	moto = 1,
	ligero = 2,
	pesado = 3
};


