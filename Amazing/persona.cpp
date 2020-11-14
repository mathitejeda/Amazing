#include <iostream>
#include "persona.h"
#include <string.h>

void persona::setNombre(char nombre[50]) {
	strcpy(this->nombre, nombre);
}

void persona::setApellido(char apellido[50])
{
	strcpy(this->apellido,apellido);
}

void persona::setDNI(char DNI[12])
{
	strcpy(this->DNI, DNI);
}

