#ifndef GESTORPRUEBA_H
#define GESTORPRUEBA_H
#include "JuegoPrueba.h"
class GestorP {

public:

	GestorP(Juego*);
	GestorP();
	~GestorP();
	void empezarPartida();
	void Ronda(Nodo*);
	void mostrarMenu();
	void repartir();
	Nodo* encontrarJugador(const std::string&);

private:
	int canJugadores;
	Juego* juego;
};



#endif
