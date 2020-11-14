#pragma once
class datosPaquete
{
private:
	FILE* p;
	paquete reg;
	int tamanio = sizeof(this->reg);
	bool exito = false;
	const char* PATH_PAQUETE = "../datos/paquete.dat";
public:
	bool guardarPaquete(paquete);
	bool leerPaquete(int,paquete&);
	bool modificarPaquete(paquete, int);
	int cantRegistros();
};

