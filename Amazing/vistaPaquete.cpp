#include <iostream>
#include <iomanip>
#include "paquete.h"
#include "vistaPaquete.h"
#include "negocioPaquete.h"
#include "rlutil.h"


using namespace std;
using namespace rlutil;

void vistaPaquete::menuPaquete()
{
	while (true) {
		cls();
		cout << "MENÚ PAQUETE" << endl;
		cout << "1- Ingresar paquete" << endl;
		cout << "2- Cambiar estado de envio de paquete" << endl;
		cout << "3- listar paquetes" << endl;
		cout << "0- volver al menú principal" << endl;
		cout << "Seleccione una opción: ";
		cin >> opc;
		cin.ignore();
		switch (opc)
		{
		case 1:
			cls();
			ingresarPaquete();
			anykey();
			break;
		case 2:
			cls();
			cout << "Ingrese el id del paquete: ";
			cin >> var;
			cin.ignore();
			estadoEnvio(var);
			anykey();
			break;
		case 3:
			cls();
			listarPaquetes();
			anykey();
			break;
		case 0:
			return;
			break;
		default:
			cls();
			cout << "opción incorrecta";
			Sleep(3000);
			break;
		}
	}
}

void vistaPaquete::ingresarPaquete()
{
	paquete ingreso;
	float peso;
	cout << "Ingrese los datos del remitente: ";
	ingreso.cargarRemitente();
	cin.ignore();
	cls();
	cout << "Ingrese los datos del destinatario: ";
	ingreso.cargarDestinatario();
	cin.ignore();
	cls();
	cout << "Ingrese el peso del paquete: ";
	cin >> peso;
	ingreso.setPeso(peso);
	if (negocioP.nuevoPaquete(ingreso)) cout << "paquete ingresado con exito";
	else cout << "No se pudo realizar el ingreso";
}

void vistaPaquete::estadoEnvio(int id)
{
	int pos = negocioP.buscarPaquete(id);
	char sel;
	paquete modEstado;
	if (negocioP.leerPaquete(modEstado, pos)) {
		cls();
		mostrarPaquete(modEstado);
		if (!modEstado.getEstado()) {
			if (modEstado.getEnvio() >= 0) {
				cout << "Desea cambiar el estado a enviado?";
				cin >> sel;
				switch (sel)
				{
				case 's': case 'S':
					modEstado.setEstado(true);
					if (negocioP.modificarPaquete(modEstado, pos)) cout << "Paquete modificado con exito!";
					else cout << "No se pudo modificar el paquete";
					break;
				case 'n': case 'N':
					cout << "No se modificara el paquete.";
					break;
				default:
					break;
				}
			}
			else cout << "No se puede modificar si no se le asigno un envio previamente";
		}
		else cout << "No se puede modificar porque ya ha entregado";
	}
	
}

void vistaPaquete::listarPaquetes()
{
}

void vistaPaquete::mostrarPaquete(paquete mostrar)
{
	cout << "#ID de paquete: " << mostrar.getID() << endl;
	cout << "* Datos Remitente: " << endl;
	cout << left << setfill(' ') << setw(20) << mostrar.getRemitente().getNombre() << "|";
	cout << left << setfill(' ') << setw(20) << mostrar.getRemitente().getApellido() << "|";
	cout << left << setfill(' ') << setw(20) << mostrar.getRemitente().getDomicilio() << "|";
	cout << left << setfill(' ') << setw(15) << mostrar.getRemitente().getDNI() << "|";
	cout << left << setfill(' ') << setw(15) << mostrar.getRemitente().getTelefono() << "|";
	cout << endl << "* Datos destinatario: " << endl;
	cout << left << setfill(' ') << setw(20) << mostrar.getDestinatario().getNombre() << "|";
	cout << left << setfill(' ') << setw(20) << mostrar.getDestinatario().getApellido() << "|";
	cout << left << setfill(' ') << setw(20) << mostrar.getDestinatario().getDomicilio() << "|";
	cout << left << setfill(' ') << setw(15) << mostrar.getDestinatario().getDNI() << "|";
	cout << left << setfill(' ') << setw(15) << mostrar.getDestinatario().getTelefono() << "|";
	cout << endl << "* Peso del paquete: " << mostrar.getPeso() << "gramos. ";
	cout << "* Envio nro: ";
	if (mostrar.getEnvio() < 0) cout << "N/A"<<endl;
	else cout << mostrar.getEnvio()<<endl;
	cout << "* Estado de envio: ";
	if (mostrar.getEstado()) cout << "Entregado"<<endl;
	else cout << "No entregado"<<endl;
}


