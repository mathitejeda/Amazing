#pragma once
class menuPrincipal
{
private:
	bool isRunning = true;
	int opc;
public:
	bool running() { return isRunning; }
	void menuVisual();
	void menuOpciones();
};

