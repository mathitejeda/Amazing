#pragma once

class persona
{
public:
	void setNombre(char nombre[50]);
	void setApellido(char apellido[50]);
	void setDNI(char DNI[12]);

	const char* getNombre() { return nombre; }
	const char* getApellido() { return apellido; }
	const char* getDNI() { return DNI; }
	
private:
	char nombre[50], apellido[50], DNI[12];
};

