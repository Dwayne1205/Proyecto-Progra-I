#ifndef NODO_H
#define NODO_H
#include "JugadorGenerico.h"
class Nodo{
private:
	Nodo* sig;
	JugadorGenerico* jugador;
public:
	Nodo(JugadorGenerico*);
	Nodo* getSig();
	void setSig(Nodo*);
	JugadorGenerico* getJugador();
	void setJugador(JugadorGenerico*);
	~Nodo();
};
#endif
