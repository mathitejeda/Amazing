#include <iostream>
#include "rlutil.h"
#include "conductor.h"
#include "vistaConductor.h"
#include "negocioTransporte.h"
#include "transporte.h"
#include "vistaTransporte.h"
using namespace rlutil;
using namespace std;

void vistaConductor::menuConductor()
{
	while (true) {
		cls();
		cout << "MEN� CONDUCTOR" << endl;
		cout << "1- Alta conductor" << endl;
		cout << "2- Asignar vehiculo" << endl;
		cout << "3_ Baja conductor" << endl;
		cout << "4_ Listar conductores" << endl;
		cout << "0- Volver al men� principal" << endl;
		cout << "Ingrese una opci�n";
		cin >> opc;
		cin.ignore();
		switch (opc)
		{
		case 1:
			cls();
			nuevoConductor();
			anykey();
			break;
		case 2:
			cls();
			cout << "Ingrese el legajo del conductor: ";
			cin >> var;
			cin.ignore();
			asignarVehiculo(var);
			anykey();
			break;
		case 0:
			return;
			break;
		default:
			cls();
			cout << "opcion incorrecta!";
			anykey();
			break;
		}
	}
}

void vistaConductor::nuevoConductor()
{
	conductor nuevo;
	char nombres[50], DNI[12];
	cout << "Ingrese el nombre del conductor: ";
	cin.getline(nombres, 50);
	nuevo.setNombre(nombres);
	cout << "Ingrese el apellido del conductor: ";
	cin.getline(nombres, 50);
	nuevo.setApellido(nombres);
	cout << "Ingrese el DNI del conductor: ";
	cin.getline(DNI, 12);
	nuevo.setDNI(DNI);
	
	if (negocioC.nuevoConductor(nuevo)) {
		cout << "Conductor guardado con exito!";
	}
	else cout << "No se pudo guardar.";

}

void vistaConductor::asignarVehiculo(int idConductor)
{
	conductor modificar;
	int pos, posT,idVehiculo;
	char selec;
	pos = negocioC.buscarConductor(idConductor);
	if (pos >= 0) {
		if (negocioC.leerConductor(modificar, pos));
		mostrarConductor(modificar);
		//apartado vehiculo
		cout <<endl<< "Ingrese el id del vehiculo que desea asignar: ";
		cin >> idVehiculo;
		cout << idVehiculo;
		cin.ignore();
		transporte asignar;
		negocioTransporte negocioT;
		posT = negocioT.bucarTransporte(idVehiculo);
		if ( pos >= 0) {
			vistaTransporte mostrarT;
			asignar = negocioT.leerTransporte(idVehiculo);
			mostrarT.mostrarTransporte(asignar);
		}
		else {
			cout <<"No existe el vehiculo";
			return;
		}
		cout << "Confirme vehiculo[s/n]: ";
		cin >> selec;
		//
		switch (selec)
		{
		case 's': case 'S':
		modificar.setVehiculo(var);
		if (negocioC.modificarConductor(modificar,pos)) {
			cout << "Asignado con exito!";
		}
		else cout << "No se pudo asignar";
		break;
		case 'n': case 'N':
			cout << "No se asignara el vehiculo";
			break;
		default:
			break;
		}
		
	}
}

void vistaConductor::bajaConductor(int id)
{
}

void vistaConductor::listarConductores()
{
}

void vistaConductor::mostrarConductor(conductor mostrar)
{
	cout << "Legajo nro: " << mostrar.getLegajo() << endl;
	cout << "Nombre(s): " << mostrar.getNombre() << endl;
	cout << "Apellido(s): " << mostrar.getApellido() << endl;
	cout << "DNI: " << mostrar.getDNI() << endl;
}
