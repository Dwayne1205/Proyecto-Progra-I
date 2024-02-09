#ifndef GESTOR_JUEGO_H
#define GESTOR_JUEGO_H
#include "Juego.h"
class GestorJuego {

public:

	GestorJuego(int,Juego*);
	GestorJuego();
	~GestorJuego();
	void empezarPartida();
	void Ronda(Nodo*);
	void dibujarMenu();
	void dibujarOpsRonda();

private:
	int canJugadores;
	Juego* juego;
};



#endif
