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
// Acá se obtiene una representación de la mano en forma de cadena de caracteres
std::string Mano::toString() {
    std::string manoString;
    for (int i = 0; i < numCartas; ++i) {
        Carta* carta = cartas[i];
        // Agrega el número y palo de cada carta a la cadena de caracteres
        manoString += std::to_string(carta->getNum());
        manoString += carta->getPalo();
        if (i < numCartas - 1) {
            manoString += " ";
        }
    }
    return manoString; // Retorna la cadena que representa la mano
}

void Mano::agregarCartaM(Mazo* mazo) {
    if (numCartas < maxCartas) {
        Carta* nuevaCarta = mazo->tomarCarta();
        cartas[numCartas++] = nuevaCarta;
    }
    else {
        std::cout << "La mano está llena" << std::endl;
    }
}
void Mano::agregarCarta(Carta* carta) {//agrega una carta que recibe como parámetro
    if (numCartas < maxCartas) {
		cartas[numCartas++] = carta;
	}
    else {
		std::cout << "La mano está llena" << std::endl;
	}
}

void Mano::limpiar() {
    for (int i = 0; i < numCartas; ++i) {
        delete cartas[i];
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

int Mano::getNumCartas() { return numCartas; }

void Mano::voltearCarta(int n) {
    cartas[n]->voltear();
}

Carta* Mano::ultimaCarta() {
    return cartas[numCartas - 1];
}