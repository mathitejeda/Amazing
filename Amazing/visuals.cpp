#include <iostream>
#include <iomanip>
#include "rlutil.h"
#include "visuals.h"

using namespace rlutil;
using namespace std;

visuals::visuals(int texto, int fondo){
    setBackgroundColor(fondo);
    setColor(texto);
    saveDefaultColor();
}
visuals* visuals::_instanciaVisuals = 0;
visuals* visuals::instanciaVisuals(int texto, int fondo)
{
    if (_instanciaVisuals == 0) {
        _instanciaVisuals = new visuals(texto,fondo);
    }
    return _instanciaVisuals;
}

void visuals::error(const char* mensaje){
setColor(RED);
cout << ">"<<mensaje;
anykey();
    resetColor();
}

void visuals::exito(const char* mensaje){
    setColor(GREEN);
    cout << ">" << mensaje;
    anykey();
    resetColor();
}