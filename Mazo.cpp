#include "Mazo.h"
Mazo::Mazo() :can(52), tam(52), cartas(new Carta* [52]) {
	for (int i = 0; i < tam; i++) {
		cartas[i] = nullptr;
	}
}
Mazo::~Mazo() {
	for (int i = 0; i < can; i++) {//se limpian las 52 casillas del arreglo.
		if (cartas[i] != nullptr) delete cartas[i];
	}
	delete[] cartas;
	cartas = nullptr;
}
void Mazo::inicializar() {
	for (int i = 0; i < 4; i++) {
		for (int j = i * 13; j < (i + 1) * 13; j++) {
			if (cartas[j] == nullptr)cartas[j] = new Carta((j % 13) + 1, i, false);
			else {
				cartas[i]->setNum((j % 13) + 1);
				cartas[i]->setPalo(i);
				cartas[i]->setBocaAbajo(false);
			}
		}
	}
}
void Mazo::barajear() {//Método encargado de barajear las cartas del mazo
	for (int i = 0; i < can; i++) {
		//RNG
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> distribution1(0, can-1);
		int random1 = distribution1(gen);
		//Intercambio de cartas
		Carta* aux = cartas[i];
		cartas[i] = cartas[random1];
		cartas[random1] = aux;
	}
}
Carta* Mazo::tomarCarta() {
	//RNG
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution1(0, can-1);
	int randomX = distribution1(gen);

	Carta* aux = cartas[randomX];
	sacarDelMazo(randomX);
	return aux;
}
void Mazo::sacarDelMazo(int n) {//Método encargado de eliminar del arreglo de cartas, la carta que sale del mazo
	Carta* aux = cartas[n];
	cartas[n] = nullptr;
	for (int i = n; i < can; i++) {//Acomoda todos los elementos en el arreglo que estén a la derecha de la carta eliminada
		//se mueven hacia la izquierda
		cartas[i] = cartas[i + 1];
	}
	cartas[--can]=aux;
}