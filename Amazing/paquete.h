#pragma once
#include "cliente.h"
class paquete
{
public:
	void setID(int id);
	void setEnvio(int id);
	void setEstado(bool estado);
	void setPeso(float peso);
	void cargarRemitente();
	void cargarDestinatario();
	void setIntentos(int intentos);
	void setEstadoEnvio(int estado);

	cliente getRemitente() { return remitente; }
	cliente getDestinatario() { return destinatario; }
	int getID() { return id; }
	int getEnvio() { return idEnvio; }
	int getEstadoEnvio() { return estadoEnvio; }
	int getIntentos() { return intentos; }
	bool getEstado() { return estadoEntrega; }
	float getPeso() { return peso; }

	enum estadoEnvio
	{
		enLocal = 1,
		despachado = 2,
		devuelto = 3,
		entregado = 4
	};
private:
	int id, idEnvio,intentos;
	cliente remitente, destinatario;
	bool estadoEntrega;
	float peso;
	int estadoEnvio;
};
