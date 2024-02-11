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
	void DealerSet();
	Nodo* encontrarJugador(const std::string&);
	Mazo* getBaraja();
	Lista* getListaJugadores();
	void cargarPartida();
	void guardarPartida(const std::string& nombreArchivo);

private:

	Mazo* Baraja;

	Lista* listaJugadores;

};
#endif
