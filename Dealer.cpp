#include "Dealer.h"

Dealer::Dealer() :JugadorGenerico("Dealer"){}
Dealer::~Dealer(){
	delete mano;
}
Carta* Dealer::pedirCarta(Mazo* mazo) {
	if (mano->getPuntos()<=16) mano->agregarCarta(mazo);
	return mano->ultimaCarta();
}
void Dealer::volteaSegunda() {
	mano->voltearCarta(1);
}