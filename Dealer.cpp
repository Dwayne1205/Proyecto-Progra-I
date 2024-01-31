#include "Dealer.h"

Dealer::Dealer() :JugadorGenerico("Dealer"){}
Dealer::~Dealer(){
	delete mano;
}
Carta* Dealer::pedirCarta(Mazo* mazo) {
	while(mano->getPuntos()<=16) mano->agregarCarta(mazo);
}
void Dealer::volteaSegunda() {//
	
}