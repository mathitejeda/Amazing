#include <iostream>
#include "vistaTransporte.h"
#include "transporte.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

void vistaTransporte::menuTransporte()
{
	while (true) {
		cls();
		cout << "MENÚ TRANSPORTE" << endl;
		cout << "1- Ingresar nuevo vehiculo" << endl;
		cout << "2- Modificar vehiculo" << endl;
		cout << "3_ Eliminar vehiculo" << endl;
		cout << "4_ Listar vehiculos" << endl;
		cout << "0- Volver al menú principal" << endl;
		cout << "Ingrese una opción";
		cin >> opc;
		cin.ignore();
		switch (opc)
		{
		case 1:
			cls();
			nuevoTransporte();
			anykey();
			break;
		case 2:
			cls();
			mostrarTransporte(0);
			anykey();
			break;
		case 3:
			break;
		case 4:
			break;
		case 0:
			break;
		default:
			break;
		}
	}
}

void vistaTransporte::nuevoTransporte()
{
	transporte nuevo;
	char patente[10], modelo[50];
	cout << "Ingrese el modelo de vehiculo: ";
	cin.getline(modelo, 50);
	nuevo.setModeloVehiculo(modelo);
	cout << "Ingrese la pantente del vehiculo: ";
	cin.getline(patente, 10);
	nuevo.setPatente(patente);
	cout << "Ingrese el tipo de vehiculo: ";
	cout << "1: Moto" << endl << "2: menor a 3500" << endl << "3: mayor a 3500" << endl;;
	cin >> var;
	nuevo.setTipoVehiculo(var);
	if (negocioT.nuevoTransporte(nuevo)) {
		cout << "Guardado con exito!";
	}
	else cout << "Error al guardar";
}

void vistaTransporte::modificarTransporte()
{

}

void vistaTransporte::bajaTransporte()
{
}

void vistaTransporte::listarTransportes()
{

}

void vistaTransporte::mostrarTransporte(int id) {
	transporte mostrar;
	if (negocioT.leerTransporte(id, mostrar)) {
		cout << mostrar.getID() << endl;
		cout << mostrar.getModelo() << endl;
		cout << mostrar.getTipo();
	}
	else cout << "error en lectura";
}

