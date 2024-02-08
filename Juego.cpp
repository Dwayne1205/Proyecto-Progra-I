#include "Juego.h"

Juego::Juego() {
	Baraja = new Mazo;
	listaJugadores = new Lista;
}

Juego::~Juego() {
	delete Baraja;
	delete listaJugadores;
}

void Juego::Jugadores(JugadorGenerico* jG) {
	Nodo* aux= new Nodo(jG);
	listaJugadores->insertarInicio(aux);
}

void Juego::Dealer() {
	Dealer* d = new Dealer;
	Nodo* auxD = new Nodo(d);
	listaJugadores->insertar(auxD);
}

void Juego::SacarJugador(Nodo* sacar) {
	listaJugadores->borrar(sacar);
}

Mazo* Juego::getBaraja() {
	return Baraja;
}
Lista* Juego::getListaJugadores() {
	return listaJugadores;
}