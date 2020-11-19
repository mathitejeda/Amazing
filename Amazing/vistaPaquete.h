#pragma once
#include "negocioPaquete.h"
class vistaPaquete
{
private:
	negocioPaquete negocioP;
	int opc, var;
public:
	void menuPaquete();
	void ingresarPaquete();
	void estadoEnvio(int);
	void listarPaquetes(bool criterio);
	void mostrarPaquete(paquete);
};

