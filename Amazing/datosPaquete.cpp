#include <iostream>
#include "paquete.h"
#include "datosPaquete.h"

bool datosPaquete::guardarPaquete(paquete reg)
{
	p = fopen(PATH_PAQUETE, "ab");
	if (p == NULL) return false;
	exito = fwrite(&reg, sizeof(reg), 1, p);
	fclose(p);
	return exito;
}

bool datosPaquete::leerPaquete(int pos,paquete &leer)
{
	if (pos >= 0) {
		p = fopen(PATH_PAQUETE, "rb");
		if (p == NULL) return false;
		fseek(p, pos * tamanio, SEEK_SET);
		exito = fread(&leer, tamanio, 1, p);
		fclose(p);
		return exito;
	}
	return false;
}

bool datosPaquete::modificarPaquete(paquete mod, int pos)
{
	if (pos >= 0) {
		p = fopen(PATH_PAQUETE, "rb+");
		if (p == NULL) return false;
		fseek(p, pos * tamanio, SEEK_SET);
		exito = fwrite(&mod, tamanio, 1, p);
		fclose(p);
		return exito;
	}
	return false;
}

int datosPaquete::cantRegistros()
{
	p = fopen(PATH_PAQUETE, "rb");
	if (p == NULL) return 0;
	fseek(p, 0, SEEK_END);
	int bytes = sizeof(p);
	fclose(p);
	return bytes / tamanio;
}
