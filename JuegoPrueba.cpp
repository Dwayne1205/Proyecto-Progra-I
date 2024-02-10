#include "JuegoPrueba.h"

JuegoP::JuegoP() {
	Baraja = new Mazo;
	listaJugadores = new Lista;
}

JuegoP::~Juego() {
	delete Baraja;
	delete listaJugadores;
}

void JuegoP::Jugadores(JugadorGenerico* jG) {
	Nodo* aux= new Nodo(jG);
	listaJugadores->insertarInicio(aux);
}

void JuegoP::Dealer() {
	Dealer* d = new Dealer;
	Nodo* auxD = new Nodo(d);
	listaJugadores->insertar(auxD);
}

void JuegoP::SacarJugador(Nodo* sacar) {
	listaJugadores->borrar(sacar);
}

Mazo* JuegoP::getBaraja() {
	return Baraja;
}
Lista* JuegoP::getListaJugadores() {
	return listaJugadores;
}
