#include "GestorJuego.h"

GestorJuego::GestorJuego() {}
GestorJuego::GestorJuego(int cJ):canJugadores{cJ}{}

void GestorJuego::empezarPartida(Juego* j) {

	j->getBaraja()->inicializar();
	j->getBaraja()->barajear();

}
GestorJuego::~GestorJuego() {}

void GestorJuego::Ronda(Juego* j, Nodo* x) {//Para pedir carta...

	Nodo* nodoAux = j->getListaJugadores()->getInicio();
	while (nodoAux != nullptr) {
		if (nodoAux == x) {
			nodoAux->getJugador()->pedirCarta();	
		}
		nodoAux = nodoAux->getSig();
	}
}

