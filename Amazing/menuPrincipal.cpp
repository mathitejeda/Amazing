#include <iostream>
#include "menuPrincipal.h"
#include "vistaTransporte.h"
#include "vistaConductor.h"
#include "vistaPaquete.h"
using namespace std;

void menuPrincipal::menuVisual()
{
	system("cls");
	cout << "1 menu paquete   " << endl;
	cout << "2- menu transportes " << endl;
	cout << "3- menu conductor" << endl;
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
	case 0:
		isRunning = false;
		break;
	default:
		cout << "nothing to see here yet";
		break;
	}
}
