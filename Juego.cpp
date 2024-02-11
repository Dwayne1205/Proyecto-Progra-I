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

void Juego::DealerSet() {
	JugadorGenerico* d = new Dealer;
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

//Encuentra a un jugador por su nombre
Nodo* Juego::encontrarJugador(const std::string& nombreJugador) {
	Nodo* nodoAux = listaJugadores->getInicio();//Se obtiene el primer nodo
	while (nodoAux != nullptr) {
		//Verifica si coinciden los nombres
		if (nodoAux->getJugador()->getNickname() == nombreJugador) {
			return nodoAux;//Y se retorna el nodo que tiene al jugador
		}
		nodoAux = nodoAux->getSig();
	}
	return nullptr; // Si no se encuentra el jugador
}
