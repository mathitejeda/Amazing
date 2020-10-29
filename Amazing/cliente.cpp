#include "cliente.h"
#include <iostream>
void cliente::setTelefono(int telefono) {
	this->telefono = telefono;
}

void cliente::setDomicilio(char domicilio[50])
{
	strcpy(this->domicilio, domicilio);
}
