#include <iostream>
#include "vistaCliente.h"
#include "paquete.h"

void paquete::setID(int id)
{
	this->id = id;
}

void paquete::setEnvio(int id)
{
	this->idEnvio = id;
}

void paquete::setEstado(bool estado)
{
	this->estadoEntrega = estado;
}

void paquete::setPeso(float peso)
{
	this->peso = peso;
}

void paquete::cargarRemitente()
{
	vistaCliente cargar;
	cargar.cargarCliente(remitente);
}

void paquete::cargarDestinatario()
{
	vistaCliente cargar;
	cargar.cargarCliente(destinatario);
}

void paquete::setIntentos(int intentos)
{
	this->intentos = intentos;
}

void paquete::setEstadoEnvio(int estado)
{
	this->estadoEnvio = estado;
}
