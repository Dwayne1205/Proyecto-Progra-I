#include "JugadorGenerico.h"
#include <iostream>

JugadorGenerico::JugadorGenerico(const std::string& nombre) : nickname(nombre), mano(new Mano()) {}
JugadorGenerico::~JugadorGenerico() {
    delete mano;
}
bool JugadorGenerico::sePaso() {
    return mano->getPuntos() > 21;
}
std::string JugadorGenerico::getNickname() {
	return nickname;
}
void JugadorGenerico::setNickname(std::string nombre) {
	nickname = nombre;
}
Mano* JugadorGenerico::getMano() {
	return mano;
}
void JugadorGenerico::setMano(Mano* dato_mano) {
	mano = dato_mano;
}
Carta* JugadorGenerico::getCarta(int n) {
	return mano->getCartas()[n];
}
int JugadorGenerico::numeroCartas() { return mano->getNumCartas(); }

void JugadorGenerico::agregarCarta(Carta* carta) { mano->agregarCarta(carta); }