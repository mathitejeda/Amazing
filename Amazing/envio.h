#pragma once
#include "fecha.h"
#include "cliente.h"
class envio
{
public:
	void setID(int id);
	void setIDVehiculo(int id);
	void setLegajoChofer(int legajo);

	int getID() { return IDEnvio; }
	int getIDVehiculo() { return IDVehiculo; }
	void getFecha() { return fechaEnvio.mostrarFecha(); }

private:
	int IDEnvio;
	int IDVehiculo, legajoChofer;
	fecha fechaEnvio;
};
