#include <iostream>
#include "rlutil.h"
#include "vistaCliente.h"
#include "verificador.h"

using namespace std;
using namespace rlutil;

void vistaCliente::cargarCliente(cliente &cargar)
{
	verificador verif;
	char dni[12];
	char nombres[50];
	int telefono;
	cout <<endl<< "Ingrese nombre[s]: ";
	cin.getline(nombres, 50);
	if(!verif.verificarNombre(nombres)){
	  cout << "El nombre ingresado es invalido";
	  return cargarCliente(cargar);
	}
	cargar.setNombre(nombres);
	cout << "Ingrese apellido[s]: ";
	cin.getline(nombres, 50);
	if(!verif.verificarNombre(nombres)){
	  cout << "El apellido ingresado es invalido";
	  return cargarCliente(cargar);
	}
	cargar.setApellido(nombres);
	cout << "Ingrese el domicilio: ";
	cin.getline(nombres, 50);
	cargar.setDomicilio(nombres);
	cout << "Ingrese el DNI: ";
	cin.getline(dni, 12);
	if(!verif.verificarDNI(dni)){
	  cout << "El dni ingresado es invalido";
	  return cargarCliente(cargar);
	}
	cargar.setDNI(dni);
	cout << "Ingrese el numero de telefono: ";
	cin >> telefono;
	cin.ignore();
	cargar.setTelefono(telefono);
}

void vistaCliente::mostrarCliente(cliente mostrar)
{
}
