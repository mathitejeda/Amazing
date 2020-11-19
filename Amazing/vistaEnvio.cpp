#include <iostream>
#include "negocioConductor.h"
#include "negocioTransporte.h"
#include "negocioPaquete.h"
#include "vistaPaquete.h"
#include "envio.h"
#include "vistaEnvio.h"
#include "envio.h"
#include "rlutil.h"

using namespace rlutil;
using namespace std;


void vistaEnvio::menuEnvio()
{
	while (true)
	{
		cls();
		cout << "MENÚ ENVÍO" << endl;
		cout << "1- Cargar envio."<<endl;
		cout << "2- Cierre envio"<<endl;
		cout << "0- Volver al menu principal" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cls();
			cargarEnvio();
			anykey();
			break;
		case 2:
			cls();
			cout << "Ingrese el id del envio a cerrar: ";
			cin >> var;
			cierreEnvio(var);
			anykey();
			break;
		case 0:
			return;
			break;
		default:
			cls();
			cout << "Opcion incorrecta!";
			anykey();
			break;
		}
	}
}

void vistaEnvio::cargarEnvio()
{
	conductor chofer;
	transporte vehiculo;
	envio reg;
	int posVehiculo, posChofer;
	cout << "Ingrese el id del vehiculo que realizara el envio: ";
	cin >> var;
	cin.ignore();
	posVehiculo = negocioT.bucarTransporte(var);
	if (posVehiculo >= 0) {
		if (negocioT.leerTransporte(vehiculo, posVehiculo)) {
			posChofer = negocioC.buscarConductor(vehiculo.getID(), 2);
			if (posChofer >= 0) {
				if (negocioC.leerConductor(chofer, posChofer)) {
					reg.setIDVehiculo(vehiculo.getID());
					reg.setLegajoChofer(chofer.getLegajo());
				}
				else {
					cout << "Error de lectura";
					return;
				}
			}
			else {
				cout << "No se encuentra ningun chofer asignado al vechiculo";
				return;
			}
		}
		else
		{
			cout << "No se pudo leer el transporte";
			return;
		}
	}
	else{
		cout << "No se encontro el transporte";
	return;
}

	reg.setID(negocioE.generarID());

	paquete paquete;
	int i = 0;
	while (var != 0)
	{
		cout <<endl<< "Ingrese el id del paquete a enviar (0 para finalizar): ";
		cin >> var;
		cin.ignore();
		int posPaquete = negocioP.buscarPaquete(var);
		if (posPaquete >= 0) {
			if (paquete.getEnvio() < 0) {
				if (negocioP.leerPaquete(paquete, posPaquete)) {
					paquete.setEnvio(reg.getID());
					paquete.setEstadoEnvio(paquete.despachado);
					if (negocioP.modificarPaquete(paquete, posPaquete)) {
						cout << "Paquete asignado con exito!";
						i++;
						if (vehiculo.getTipo() == 1 && i == 10) {
							cout << "Se ha asignado el maximo de paquetes";
							var = 0;
						}
						else if (vehiculo.getTipo() == 2 && i == 50) {
							cout << "Se ha asignado el maximo de paquetes";
							var = 0;
						}
						else if (vehiculo.getTipo() == 3 && i == 200) {
							cout << "Se ha asignado el maximo de paquetes";
							var = 0;
						}
					}
					else cout << "No se pudo asignar";
				}
				else cout << "No se pudo leer el paquete";
			}
			else cout << "El paquete ya tiene un envio asignado";
		}
		else cout << "No se encontro el paquete";
	}
	if (negocioE.nuevoEnvio(reg)) {
		cout << "Envio guardado con exito!";
	}
	else cout << "No se pudo guardar el envio";
}

void vistaEnvio::cierreEnvio(int idEnvio)
{
	envio cierre;
	paquete ref;
	vistaPaquete vistaPaquete;
	char sel;
	int posEnvio = negocioE.buscarEnvio(idEnvio);
	if (posEnvio >= 0) {
		int i = 0;
		while (negocioP.leerPaquete(ref, i)) {
			if (ref.getEnvio() == idEnvio){
				cls();
				vistaPaquete.mostrarPaquete(ref);
				cout << endl;
				cout << "El paquete fue entregado? [s/n]: ";
				cin >> sel;
				cin.ignore();
				switch (sel)
				{
				case 's': case 'S':
					ref.setEstado(true);
					ref.setEstadoEnvio(ref.entregado);
					if (negocioP.modificarPaquete(ref, i)) cout << "Se cambio el estado a 'entregado'";
					else cout << "No se pudo cambiar el estado, intente cambiarlo manualmente";
					break;
				case 'n': case 'N':
				{
					int intentos = ref.getIntentos() + 1;
					if (intentos < 3) {
						ref.setIntentos(intentos);
						cout << endl << "Aun quedan " << 3 - intentos << " intentos";
						ref.setEstadoEnvio(ref.enLocal);
					}
					else {
						cout << "El paquete ha llegado al maximo de intentos, el estado pasara a devuelto al remitente";
						ref.setEstadoEnvio(ref.devuelto);
						ref.setEstado(false);
					}
					break;
				}
				default:
					cout << "Opcion incorrecta!";
					break;
				}
				if (negocioP.modificarPaquete(ref, i)) { cout << "se han guardado los cambios"; }
				else cout << "No se pudieron guardar los cambios";
				cout << "Presione cualquier tecla para continuar... ";
				anykey();
			}
			i++;
		}
	}
	else if (posEnvio <= 0) cout << "No se encontro el envío";
}
