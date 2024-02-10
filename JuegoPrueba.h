#ifndef JUEGOPRUEBA_H
#define JUEGOPRUEBA_H

#include "Mazo.h"
#include "JugadorGenerico.h"
#include "Lista.h"
#include"Nodo.h"

class JuegoP {

public:

	JuegoP();
	~JuegoP();
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
