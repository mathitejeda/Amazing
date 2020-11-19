#include <iostream>
#include <wchar.h>
#include <clocale>
#include <stdio.h>

#include "menuPrincipal.h"
using namespace std;

int main(){
	menuPrincipal menu;
	setlocale(LC_ALL, "");
	while (menu.running()) {
		menu.menuVisual();
	}
	return 0;
}