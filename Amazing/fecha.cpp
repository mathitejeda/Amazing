#include <iostream>
#include <ctime>
#include <string>
#include "fecha.h"

using namespace std;

fecha::fecha(int d, int m, int a)
{
    if (d != 0 || m != 0 || a != 0)
    {
        if (verificarFecha(d, m, a)) {
            dia = d;
            mes = m;
            anio = a;
        }
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
        cout<< "El numero no corresponde a ningun dia.";
        return sDia;
        break;
    }
    return sDia;
}

bool fecha::verificarFecha(int dia, int mes, int anio)
{
    if (mes >= 1 && mes <= 12) {
        switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (dia >= 1 && dia <= 31) return true;
            else return false;
            break;
        case 2:
            if (anio % 4 == 0 && anio % 100 != 0) {
                if (dia >= 1 && dia <= 27) return true;
                else return false;
            }
            else if (dia >= 1 && dia <= 29) return true;
            else return false;
            break;
        case 4: case 6: case 9: case 11:
            if (dia >= 1 && dia <= 30) return true;
            else return false;
            break;
        }
    }
    return false;
}
