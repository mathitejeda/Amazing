#include <iostream>
#include <iomanip>
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
		cout << "Ingrese una opción: ";
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
			cout << "Ingrese el id del transporte que desea modificar.";
			cin >> var;
			cin.ignore();
			modificarTransporte(var);
			anykey();
			break;
		case 3:
			cls();
			cout << "Ingrese el id del transporte a eliminar: ";
			cin >> var;
			cin.ignore();
			bajaTransporte(var);
			anykey();
			break;
		case 4:
			cls();
			listarTransportes();
			anykey();
			break;
		case 0:
			return;
			break;
		default:
			cout << "Opcion invalida";
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
	cout << "Ingrese el tipo de vehiculo: " << endl;
	cout << "1: Moto" << endl << "2: menor a 3500" << endl << "3: mayor a 3500" << endl;;
	cin >> var;
	nuevo.setTipoVehiculo(var);
	if (negocioT.nuevoTransporte(nuevo)) {
		cout << "Guardado con exito!";
	}
	else cout << "Error al guardar";
}

void vistaTransporte::modificarTransporte(int id)
{
	transporte modificar;
	int pos;
	char select;
	pos = negocioT.bucarTransporte(id);
	if (pos >= 0) {
		cls();
		if (negocioT.leerTransporte(modificar, pos)) {
			this->mostrarTransporte(modificar);
			cout << endl << "Desea cambiar el estado de circulación? [s/n]: ";
			cin >> select;
			switch (select)
			{
			case 's': case 'S':
				if (modificar.getCirculacion()) modificar.setCirculacion(false);
				else modificar.setCirculacion(true);
				if (negocioT.modificarTransporte(modificar, pos)) {
					cout << "Modificacion guardada con exito!";
				}
				else cout << "No se pudo guardar la modificacion.";
				break;
			case 'n': case 'N':
				cout << "No se modificara el vehiculo";
				break;
			default:
				cout << "Opcion incorrecta!";
				break;
			}
		}
		else {
			cout << "No se pudo leer el transporte";
			return;
		}
	}
	else {
		cout << "No se encontro el transporte";
		return;
	}
}

void vistaTransporte::bajaTransporte(int id)
{
	transporte eliminar;
	int pos;
	char select;
	pos = negocioT.bucarTransporte(id);
	if (pos >= 0) {
		cls();
		if (negocioT.leerTransporte(eliminar, pos)) {
			mostrarTransporte(eliminar);
			cout << "Confirme que desea eliminar el transporte [s/n]: ";
			cin >> select;
			switch (select)
			{
			case 's': case 'S':
				eliminar.setEstado(false);
				if (negocioT.modificarTransporte(eliminar, pos)) cout << "Vehiculo eliminado!";
				else cout << "El vehiculo no pudo ser eliminado.";
				break;
			case 'n': case 'N':
				cout << "No se eliminara el vehiculo.";
				break;
			default:
				cout << "Opcion incorrecta";
				break;
			}
		}
		else cout << "No se pudo leer el transporte";
	}
	else cout << "No se pudo encontrar al transporte";

}

void vistaTransporte::listarTransportes()
{
	transporte listado;
	int i = 0;
	cout << left << setfill(' ') << setw(12) << "ID vehiculo";
	cout << left << setfill(' ') << setw(25) << "Modelo";
	cout << left << setfill(' ') << setw(12) << "Patente";
	cout << left << setfill(' ') << setw(25) << "Estado circulacion";
	cout << endl;
	while (negocioT.leerTransporte(listado, i++)) {
		if (listado.getEstado()) {
			mostrarTransporte(listado, true);
		}
	}
}

void vistaTransporte::mostrarTransporte(transporte mostrar,bool masivo) {
	if (!masivo) {
		cout << left << setfill(' ') << setw(12) << "ID vehiculo";
		cout << left << setfill(' ') << setw(25) << "Modelo";
		cout << left << setfill(' ') << setw(12) << "Patente";
		cout << left << setfill(' ') << setw(25) << "Estado circulacion";
		cout << endl;
	}
	cout << left << setfill(' ') << setw(12) << mostrar.getID();
	cout << left << setfill(' ') << setw(25) << mostrar.getModelo();
	cout << left << setfill(' ') << setw(12) << mostrar.getPatente();
	cout << left << setfill(' ') << setw(25);
	if (mostrar.getCirculacion()) cout << " circulando";
	else cout << "No circulando";
	cout << endl;

}


