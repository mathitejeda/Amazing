#include <iostream>
#include "menuPrincipal.h"
#include "vistaTransporte.h"
#include "vistaConductor.h"
#include "vistaPaquete.h"
#include "vistaEnvio.h"
using namespace std;

void menuPrincipal::menuVisual()
{
	system("cls");
	cout << "MEN� PRINCIPAL" << endl;
	cout << "1- Men� paquete   " << endl;
	cout << "2- Men� transportes " << endl;
	cout << "3- Men� conductor" << endl;
	cout << "4- Men� env�o" << endl;
	cout << "0- Salir" << endl;
	cout << "seleccione una opcion: ";
	cin >> opc;
	menuOpciones();
}

void menuPrincipal::menuOpciones()
{
	switch (opc)
	{
	case 1:
	{
		vistaPaquete paquete;
		paquete.menuPaquete();
		break;
	}
	case 2:
	{
		vistaTransporte transporte;
		transporte.menuTransporte();
		break;
	}
	case 3:
	{
		vistaConductor conductor;
		conductor.menuConductor();
		break;
	}
	case 4:
	{
		vistaEnvio envio;
		envio.menuEnvio();
		break;
	}
	case 0:
		isRunning = false;
		break;
	default:
		cout << "nothing to see here yet";
		break;
	}
}
