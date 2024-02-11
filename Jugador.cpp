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
        std::cout << nickname << " tomó una carta: " << nuevaCarta->toString() << std::endl;
    }
    else {
        std::cout << nickname << " no puede recibir más cartas porque se pasó de 21" << std::endl;
    }
    return nuevaCarta;
}