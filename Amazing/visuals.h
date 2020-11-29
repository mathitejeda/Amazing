#pragma once
class visuals
{
private:
	static visuals* _instanciaVisuals;
public:
	static visuals* instanciaVisuals(int texto = blanco, int fondo = negro);
	void error(const char* mensaje);
	void exito(const char* mensaje);
	enum colores {
		negro,
		azul,
		verde,
		cian,
		rojo,
		magenta,
		marron,
		grisClaro,
		gris,
		azulClaro,
		verdeClaro,
		cianClaro,
		rojoClaro,
		magentaClaro,
		amarillo,
		blanco
	};
protected:
	visuals(int texto, int fondo);
};

