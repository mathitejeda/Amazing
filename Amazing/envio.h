#pragma once
#include "fecha.h"
#include "cliente.h"
class envio
{
public:
	envio();
	~envio();

	void setEstadoEnvio(int envio);
	int getEstadoEnvio() { return estadoEnvio; }
	void getFecha() { return fechaEnvio.mostrarFecha(); }

private:
	int idpaquete;
	int estadoEnvio, intentos;
	int IDVehiculo, legajoChofer;
	fecha fechaEnvio;
	cliente remitente, destinatario;
};

enum estadoEnvio
{
	enLocal = 1,
	despachado = 2,
	devuelto = 3
};

envio::envio()
{
}

envio::~envio()
{
}

