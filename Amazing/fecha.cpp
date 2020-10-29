#include <iostream>
#include <ctime>
#include <string>
#include "fecha.h"
#include "Funciones.h"

using namespace std;

fecha::fecha(int d, int m, int a)
{
    if (d != 0 || m != 0 || a != 0)
    {
        dia = d;
        mes = m;
        anio = a;
    }
    else
    {
        time_t tiempo;
        struct tm* tmPtr;
        tiempo = time(NULL);
        tmPtr = localtime(&tiempo);
        anio = tmPtr->tm_year + 1900;
        mes = tmPtr->tm_mon + 1;
        dia = tmPtr->tm_mday;
    }
}

void fecha::mostrarFecha()
{
    cout << dia << "/" << mes << "/" << anio;
}

const char* fecha::mostrarDiaTexto(int dia)
{
    const char* sDia;
    switch (dia)
    {
    case 1:
        sDia = "Lunes";
        break;
    case 2:
        sDia = "Martes";
        break;
    case 3:
        sDia = "Miercoles";
        break;
    case 4:
        sDia = "Jueves";
        break;
    case 5:
        sDia = "Viernes";
        break;
    case 6:
        sDia = "Sabado";
        break;
    case 0:
        sDia = "Domingo";
        break;
    default:
        sDia = "";
        error("El numero no corresponde a ningun dia.");
        return sDia;
        break;
    }
    return sDia;
}