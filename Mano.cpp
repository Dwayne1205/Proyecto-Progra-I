#include "Mano.h"
#include <iostream>

const int Mano::maxCartas = 8; // Definir el tamaño máximo de cartas

Mano::Mano() : cartas(new Carta* [maxCartas]), numCartas(0) {
    for (int i = 0; i < maxCartas; i++) {
        cartas[i] = nullptr;
    }
}

Mano::~Mano() {
    limpiar();
    delete[] cartas;
}

void Mano::agregarCarta(Mazo* mazo) {
    if (numCartas < maxCartas) {
        Carta* nuevaCarta = mazo->tomarCarta();
        cartas[numCartas++] = nuevaCarta;
    }
    else {
        std::cout << "La mano está llena" << std::endl;
    }
}

void Mano::limpiar() {
    for (int i = 0; i < numCartas; ++i) {
        cartas[i] = nullptr;
    }
    numCartas = 0;
}

int Mano::getPuntos() {
    int puntos = 0;
    int ases = 0;
    int valor = 0;
    for (int i = 0; i < numCartas; ++i) {
        valor = cartas[i]->getNum();
        if (valor == 1) {
            ases++;
            puntos += 11; // Valor predeterminado para el As
        }
        else {
            puntos += valor;
        }
    }

    while (puntos > 21 && ases > 0) {
        puntos -= 10;
        ases--;
    }

    return puntos;
}

Carta** Mano::getCartas() {
	return cartas;
}

void Mano::voltearCarta(int n) {
    cartas[n]->voltear();
}

Carta* Mano::ultimaCarta() {
	return cartas[numCartas - 1];
}