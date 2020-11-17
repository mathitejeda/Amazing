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
			cout << "sike, esta opcion no hace nada hasta que sepa como usarla";
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
		modificar = negocioT.leerTransporte(pos);
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
}

void vistaTransporte::bajaTransporte(int id)
{
	transporte eliminar;
	int pos;
	char select;
	pos = negocioT.bucarTransporte(id);
	if (pos >= 0) {
		cls();
		eliminar = negocioT.leerTransporte(pos);
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
	cout << "No se pudo encontrar al transporte";

}

void vistaTransporte::listarTransportes()
{
	transporte* vec = {0};
	negocioT.ordenarTransportes(vec);
	for (int i = 0; i <= negocioT.getCant();i++) {
		
		cout << ".................................." << endl;

	}
}

void vistaTransporte::mostrarTransporte(transporte mostrar) {
	cout << "Vehiculo nro " << mostrar.getID() << endl;
	cout << "* Modelo: " << mostrar.getModelo() << endl;
	cout << "* Patente: " << mostrar.getPatente() << endl;
	cout << "*Estado de circulacion: ";
	if (mostrar.getCirculacion()) cout << "Circulando"<<endl;
	else cout << "No circulando" << endl;

}


