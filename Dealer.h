#ifndef DEALER_H
#define DEALER_H
#include "JugadorGenerico.h"
class Dealer : public JugadorGenerico{
public:
	Dealer();		
	~Dealer();
	void volteaSegunda();
	Carta* pedirCarta(Mazo* mazo)override;
};
#endif 