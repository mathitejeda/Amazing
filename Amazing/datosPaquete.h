#pragma once

class datosPaquete
{
private:
	paquete reg;
	FILE* p;
	bool exito = false;
	const char* PATH_PAQUETE = "../datos/paquete.dat";
public:
	bool guardarPaquete(paquete);
	bool leerPaquete(paquete& ,int);
	bool modificarPaquete(paquete, int);
	int cantRegistros();
};

