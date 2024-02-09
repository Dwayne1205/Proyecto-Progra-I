#include "GestorJuego.h"

GestorJuego::GestorJuego() {}
GestorJuego::GestorJuego(int cJ, Juego* j):canJugadores{cJ}, juego{j}{}

void GestorJuego::empezarPartida() {

	juego->getBaraja()->inicializar();
	juego->getBaraja()->barajear();

}
GestorJuego::~GestorJuego() {}

void GestorJuego::Ronda(Nodo* x) {//Para pedir carta...

	Nodo* nodoAux = juego->getListaJugadores()->getInicio();
	while (nodoAux != nullptr) {
		if (nodoAux == x) {
			nodoAux->getJugador()->pedirCarta();	
		}
		nodoAux = nodoAux->getSig();
	}
}

