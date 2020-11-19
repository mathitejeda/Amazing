#pragma once
#include "negocioConductor.h"
class vistaConductor
{
private:
	negocioConductor negocioC;
	int opc, var;
public:
	void menuConductor();
	void nuevoConductor();
	void asignarVehiculo(int idConductor);
	void bajaConductor(int id);
	void listarConductores();
	void mostrarConductor(conductor mostrar,bool masivo = false);
};

