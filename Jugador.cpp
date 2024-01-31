#include "Jugador.h"
Jugador::Jugador(std::string nickname) : JugadorGenerico(nickname) {}
Jugador::~Jugador() {
    delete mano;
}
Carta* Jugador::pedirCarta(Mazo* mazo){
    Carta* nuevaCarta = nullptr;

    if (!sePaso()) {
        nuevaCarta = mazo->tomarCarta();
        mano->agregarCarta(mazo);
        std::cout << nickname << " tom� una carta: " << nuevaCarta->toString() << std::endl;
    }
    else {
        std::cout << nickname << " no puede recibir m�s cartas porque se pas� de 21" << std::endl;
    }
    return nuevaCarta;
}