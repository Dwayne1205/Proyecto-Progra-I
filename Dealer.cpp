#include "Dealer.h"

Dealer::Dealer() :JugadorGenerico("Dealer"){}
Carta* Dealer::pedirCarta(Mazo* mazo) {
	Carta* aux;
	while(mano->getPuntos()<=16) mano->agregarCarta(mazo);
}