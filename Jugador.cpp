#include "Jugador.h"
Carta* Jugador::pedirCarta(Mazo* mazo){
    Carta* nuevaCarta = nullptr;

    if (!sePaso()) {
        nuevaCarta = mazo->tomarCarta();
        mano->agregarCarta(mazo);
        std::cout << nickname << " tomó una carta: " << nuevaCarta->toString() << std::endl;
    }
    else {
        std::cout << nickname << " no puede recibir más cartas porque se pasó de 21" << std::endl;
    }

    return nuevaCarta;
}