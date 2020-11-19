#pragma once
#include "negocioEnvio.h"
class vistaEnvio
{
private:
	negocioEnvio negocioE;
	negocioConductor negocioC;
	negocioTransporte negocioT;
	negocioPaquete negocioP;
	int opc, var;
public:
	void menuEnvio();
	void cargarEnvio();
	void cierreEnvio(int idEnvio);
};

