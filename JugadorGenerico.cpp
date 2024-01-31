#include "JugadorGenerico.h"
#include <iostream>

JugadorGenerico::JugadorGenerico(const std::string& nombre) : nickname(nombre), mano(new Mano()) {}
JugadorGenerico::~JugadorGenerico() {
    delete mano;
}
bool JugadorGenerico::sePaso() {
    return mano->getPuntos() > 21;
}
