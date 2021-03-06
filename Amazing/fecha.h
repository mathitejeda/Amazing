#pragma once

class fecha
{
public:
	fecha(int d = 0, int m = 0, int a = 0);
	// getters
	int getDia() { return dia; }
	int getMes() { return mes; }
	int getAnio() { return anio; }
	// setters
	void setDia(int d) { dia = d; }
	void setMes(int m) { mes = m; }
	void setAnio(int a) { anio = a; }
	// funciones
	void mostrarFecha();
	const char* mostrarDiaTexto(int dia);
	bool verificarFecha(int dia, int mes, int anio);

private:
	int dia;
	int mes;
	int anio;
	bool biciesto = false;
};

