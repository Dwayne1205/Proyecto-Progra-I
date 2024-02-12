#include "Jugador.h"
Jugador::Jugador(std::string nickname) : JugadorGenerico(nickname) {}
Jugador::~Jugador() {
    delete mano;
}
Carta* Jugador::pedirCarta(Mazo* mazo){
    Carta* nuevaCarta = nullptr;

    if (!sePaso()) {
        nuevaCarta = mazo->tomarCarta();
        mano->agregarCartaM(mazo);
        std::cout << nickname << " tom� una carta: "<< std::endl;
    }
    else {
        std::cout << nickname << " no puede recibir m�s cartas porque se pas� de 21" << std::endl;
    }
    return nuevaCarta;
}