#ifndef JUEGO_H
#define JUEGO_H

#include "Mazo.h"
#include "JugadorGenerico.h"
#include "Lista.h"
#include"Nodo.h"

class Juego {

public:

	Juego();
	~Juego();
	void Jugadores(JugadorGenerico*);
	void SacarJugador(Nodo*);
	void Dealer();
	Mazo* getBaraja();
	Lista* getListaJugadores();

private:

	Mazo* Baraja;

	Lista* listaJugadores;

};
#endif
