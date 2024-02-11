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
	void cargarPartida();
	void guardarPartida();
	void realizarRonda();
private:
	int canJugadores;
	Juego* juego;
};



#endif
