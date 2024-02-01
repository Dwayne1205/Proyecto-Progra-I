#include "Nodo.h"

Nodo::Nodo(JugadorGenerico* jugador_dato): sig(nullptr), jugador(jugador_dato){}

Nodo::~Nodo() {
	delete jugador;
}

Nodo* Nodo::getSig() { return sig; }
void Nodo::setSig(Nodo* nodo) { sig = nodo; }
JugadorGenerico* Nodo::getJugador() { return jugador; }
void Nodo::setJugador(JugadorGenerico* jugador_dato) { jugador = jugador_dato; }