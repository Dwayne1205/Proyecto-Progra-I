/*
*Proyecto programacion 1 
*Blackjack
*Dwayne
*Jonatan
*Alcides 4-0267-0686
*v1.3
*/
#include<iostream>
#include "Juego.h"
#include "Jugador.h"
#include "JugadorGenerico.h"
int main() {

	int canJugadores;
	Juego* n = new Juego();
	
	n->getBaraja()->tomarCarta();

	std::cout << "Ingrese la cantidad de jugadores: " << '\n';
	std::cin >> canJugadores;
	for (int i = 0; i < canJugadores; i++) {
		std::string a;
		std::cout << "Ingrese el nickname:" << '\n';
		std::cin >> a;
		JugadorGenerico* jG= new Jugador(a);
		n->Jugadores(jG);
	}

	return 0;
}

