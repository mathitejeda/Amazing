#include <iostream>
#include <string.h>
#include "transporte.h"


using namespace std;

void transporte::setID(int ID)
{
	this->ID = ID;
}

void transporte::setTipoVehiculo(int tipo)
{
	this->tipoVehiculo = tipo;
}

void transporte::setPatente(const char* patente)
{
	strcpy(this->patente, patente);
}

void transporte::setCirculacion(bool circulacion)
{
	this->circulacion = circulacion;
}

void transporte::setEstado(bool estado)
{
	this->estado = estado;
}

void transporte::setModeloVehiculo(const char* modelo) {
	strcpy(this->modelo, modelo);
}


