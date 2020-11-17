#pragma once
#include "paquete.h"
#include "datosPaquete.h"
class negocioPaquete
{
private:
	datosPaquete dP;
public:
	bool nuevoPaquete(paquete reg);
	bool modificarPaquete(paquete mod, int pos);
	bool leerPaquete(paquete& leer, int pos);
	int buscarPaquete(int id);

};

