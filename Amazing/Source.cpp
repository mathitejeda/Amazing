#include <iostream>
#include "menuPrincipal.h"
using namespace std;

int main(){
	menuPrincipal menu;
	while (menu.running()) {
		menu.menuVisual();
	}
	return 0;
}