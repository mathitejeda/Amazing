#include <iostream>
#include <iomanip>
#include "rlutil.h"
#include "conductor.h"
#include "vistaConductor.h"
#include "negocioTransporte.h"
#include "transporte.h"
#include "vistaTransporte.h"
#include "verificador.h"
#include "visuals.h"
using namespace rlutil;
using namespace std;

void vistaConductor::menuConductor()
{
	while (true) {
		cls();
		cout << "MENÚ CONDUCTOR" << endl;
		cout << "1- Alta conductor" << endl;
		cout << "2- Asignar vehiculo" << endl;
		cout << "3_ Baja conductor" << endl;
		cout << "4_ Listar conductores" << endl;
		cout << "0- Volver al menú principal" << endl;
		cout << "Ingrese una opción: ";
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
		case 3:
			cls();
			cout << "Ingrese el legajo del conductor: ";
			cin >> var;
			cin.ignore();
			bajaConductor(var);
			anykey();
			break;
		case 4:
			cls();
			listarConductores();
			anykey();
			break;
		case 0:
			return;
			break;
		default:
			cls();
			visuals::instanciaVisuals()->error("Opcion incorrecta");
			break;
		}
	}
}

void vistaConductor::nuevoConductor()
{
	conductor nuevo;
	verificador verif;
	char nombres[50], DNI[12];
	cout << "Ingrese el nombre del conductor: ";
	cin.getline(nombres, 50);
	if (!verif.verificarNombre(nombres))
	{
		cout << "Nombre invalido.";
		return nuevoConductor();
	}
	nuevo.setNombre(nombres);
	cout << "Ingrese el apellido del conductor: ";
	cin.getline(nombres, 50);
	if (!verif.verificarNombre(nombres)) {
		cout << "Apellido invalido.";
		return nuevoConductor();
	}
	nuevo.setApellido(nombres);
	cout << "Ingrese el DNI del conductor: ";
	cin.getline(DNI, 12);
	if (!verif.verificarDNI(DNI)) {
		cout << "DNI invalido.";
		return nuevoConductor();
	}
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
	pos = negocioC.buscarConductor(idConductor,1);
	if (pos >= 0) {
		if (negocioC.leerConductor(modificar, pos));
		mostrarConductor(modificar);
		//apartado vehiculo
		cout <<endl<< "Ingrese el id del vehiculo que desea asignar: ";
		cin >> idVehiculo;
		cin.ignore();
		transporte asignar;
		negocioTransporte negocioT;
		posT = negocioT.bucarTransporte(idVehiculo);
		if ( posT >= 0) {
			vistaTransporte mostrarT;
			if (negocioT.leerTransporte(asignar, posT)) {
				mostrarT.mostrarTransporte(asignar);
			}
			else {
				visuals::instanciaVisuals()->error("No se pudo leer el vehiculo");
				return;
			}
		}
		else {
			visuals::instanciaVisuals()->error("No se encontro el vehiculo");
			return;
		}
		cout << "Confirme vehiculo[s/n]: ";
		cin >> selec;
		//
		switch (selec)
		{
		case 's': case 'S':
		modificar.setVehiculo(var);
		if (negocioC.modificarConductor(modificar, pos)) {
			visuals::instanciaVisuals()->exito("Asignado con exito!");
		}
		else visuals::instanciaVisuals()->error("No se pudo asignar");
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
	conductor eliminar;
	int pos;
	char sel;
	pos = negocioC.buscarConductor(id,1);
	if (pos >= 0) {
		cls();
		if (negocioC.leerConductor(eliminar, pos)) {
			mostrarConductor(eliminar);
			cout << "Confirme que desea eliminar conductor [s/n]: ";
			cin >> sel;
			switch (sel)
			{
			case 's': case 'S':
				eliminar.setEstado(false);
				if (negocioC.modificarConductor(eliminar, pos)) cout << "Conductor eliminado con exito!";
				else cout << "No se pudo eliminar.";
				break;
			case 'n': case 'N':
				cout << "No se eliminara al conductor.";
				break;
			default:
				cout << "Opcion incorrecta!";
				break;
			}
		}
	}
	else cout << "No se pudo encontrar al conductor";
}

void vistaConductor::listarConductores()
{
	conductor listado;
	int i = 0;
	cout << left << setfill(' ') << setw(7) << "Legajo";
	cout << left << setfill(' ') << setw(25) << "Nombre(s)";
	cout << left << setfill(' ') << setw(25) << "Apellido(s)";
	cout << left << setfill(' ') << setw(15) << "DNI";
	cout << left << setfill(' ') << setw(15) << "ID Vehiculo";
	while (negocioC.leerConductor(listado, i++)) {
		if (listado.getEstado()) {
			cout << endl;
			mostrarConductor(listado, true);
		}
	}
}

void vistaConductor::mostrarConductor(conductor mostrar, bool masivo)
{
	if (!masivo) {
		cout << left << setfill(' ') << setw(7) << "Legajo";
		cout << left << setfill(' ') << setw(25) << "Nombre(s)";
		cout << left << setfill(' ') << setw(25) << "Apellido(s)";
		cout << left << setfill(' ') << setw(15) << "DNI";
		cout << left << setfill(' ') << setw(15) << "ID Vehiculo";
		cout << endl;
	}
	cout << left << setfill(' ') << setw(7) << mostrar.getLegajo();
	cout << left << setfill(' ') << setw(25) << mostrar.getNombre();
	cout << left << setfill(' ') << setw(25) << mostrar.getApellido();
	cout << left << setfill(' ') << setw(15) << mostrar.getDNI();
	cout << left << setfill(' ') << setw(15);
	if (mostrar.getVehiculo() >= 0) cout << mostrar.getVehiculo();
	else cout << "N/A";
	cout << endl;
}
