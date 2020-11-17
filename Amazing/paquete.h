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

	cliente getRemitente() { return remitente; }
	cliente getDestinatario() { return destinatario; }
	int getID() { return id; }
	int getEnvio() { return idEnvio; }
	bool getEstado() { return estadoEntrega; }
	float getPeso() { return peso; }
private:
	int id, idEnvio;
	cliente remitente, destinatario;
	bool estadoEntrega;
	float peso;
};


