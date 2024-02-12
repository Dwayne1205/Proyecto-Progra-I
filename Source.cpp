/*
*Proyecto programacion 1 
* Blackjack
*Dhuaine Ramirez Leon 4-0268-0031
*Jonatan Arauz
*Alcides 4-0267-0686
*v1.3
*/
#include <iostream>
#include "GestorJuego.h"
int main() {
	
	Juego* nj = new Juego();
	GestorJuego* jG = new GestorJuego(nj);
	jG->mostrarMenu();


	return 0;
}