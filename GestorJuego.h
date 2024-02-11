#ifndef GESTOR_JUEGO_H
#define GESTOR_JUEGO_H
#include "Juego.h"
class GestorJuego {

public:

	GestorJuego(Juego*);
	GestorJuego();
	~GestorJuego();
	void empezarPartida();
	void mostrarMenu();
	void repartir();
	Nodo* encontrarJugador(const std::string&);

private:
	int canJugadores;
	Juego* juego;
};



#endif
