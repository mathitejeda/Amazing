#include <iostream>
#include "menuPrincipal.h"
#include "vistaTransporte.h"

using namespace std;

void menuPrincipal::menuVisual()
{
	cout << "1 menu choferes" << endl;
	cout << "seleccione una opcion: ";
	cin >> opc;
	menuOpciones();
}

void menuPrincipal::menuOpciones()
{
	switch (opc)
	{
	case 1:
		vistaTransporte transporte;
		transporte.menuTransporte();
		break;
	case 0:
		isRunning = false;
		break;
	default:
		cout << "nothing to see here yet";
		break;
	}
}
