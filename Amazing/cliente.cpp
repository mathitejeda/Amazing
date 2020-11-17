#include <iostream>
#include <string.h>
#include "cliente.h"
void cliente::setTelefono(int telefono) {
	this->telefono = telefono;
}

void cliente::setDomicilio(char domicilio[50])
{
	strcpy(this->domicilio, domicilio);
}
 