#ifndef JUGADOR_H
#define JUGADOR_H
#include "JugadorGenerico.h"
class Jugador:public JugadorGenerico{
public:
	Jugador(std::string nick);
	~Jugador();
	Carta* pedirCarta(Mazo* mazo)override;
};
#endif