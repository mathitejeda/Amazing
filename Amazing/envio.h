#pragma once
#include "fecha.h"
#include "cliente.h"
class envio
{
public:
	envio();
	~envio();

	void setEstadoEntrega(bool estado);
	void setEstadoEnvio(int envio);

	bool getEstadoEntrega() { return estadoEntrega; }
	int getEstadoEnvio() { return estadoEnvio; }
	void getFecha() { return fechaEnvio.mostrarFecha(); }

private:
	char dniRemitente[12], dniDestinatario[12];
	bool estadoEntrega;
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

