#include <iostream>
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
}

void vistaPaquete::listarPaquetes()
{
}
