#ifndef JUGADOR_H
#define JUGADOR_H
#include "JugadorGenerico.h"
class Jugador:public JugadorGenerico{
public:
	Carta* pedirCarta(Mazo* mazo)override;
};
#endif