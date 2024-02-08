#ifndef GESTOR_JUEGO_H
#define GESTOR_JUEGO_H
#include "Juego.h"
class GestorJuego {

public:

	GestorJuego(int);
	GestorJuego();
	~GestorJuego();
	void empezarPartida(Juego*);
	void Ronda(Juego*,Nodo*);

private:
	int canJugadores;

};



#endif
