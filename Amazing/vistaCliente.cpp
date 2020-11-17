#include <iostream>
#include "rlutil.h"
#include "vistaCliente.h"

using namespace std;
using namespace rlutil;

void vistaCliente::cargarCliente(cliente &cargar)
{
	char dni[12];
	char nombres[50];
	int telefono;
	cout << "Ingrese nombre[s]: ";
	cin.getline(nombres, 50);
	cargar.setNombre(nombres);
	cout << "Ingrese apellido[s]: ";
	cin.getline(nombres, 50);
	cargar.setApellido(nombres);
	cout << "Ingrese el DNI: ";
	cin.getline(dni, 12);
	cargar.setDNI(dni);
	cout << "Ingrese el numero de telefono: ";
	cin >> telefono;
	cargar.setTelefono(telefono);
}

void vistaCliente::mostrarCliente(cliente mostrar)
{
}
