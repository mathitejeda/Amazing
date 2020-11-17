#include <iostream>
#include "negocioPaquete.h"
#include "datosPaquete.h"

bool negocioPaquete::nuevoPaquete(paquete reg)
{
	reg.setID(dP.cantRegistros() + 1);
	reg.setEstado(true);

	return dP.guardarPaquete(reg);
}

bool negocioPaquete::modificarPaquete(paquete mod, int pos)
{
	return dP.modificarPaquete(mod, pos);
}

bool negocioPaquete::leerPaquete(paquete& leer, int pos)
{
	return dP.leerPaquete(leer,pos);
}

int negocioPaquete::buscarPaquete(int id)
{
	int i = 0;
	paquete buscar;
	while (dP.leerPaquete(buscar, i)) {
		if (buscar.getID() == id && buscar.getEstado() == true) {
			return i;
		}
		i++;
	}
	return -1;
}
