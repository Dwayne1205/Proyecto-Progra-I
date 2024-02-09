#include "Lista.h"

Lista::Lista() :inicio(nullptr) {}
Lista::~Lista() {
	Nodo* aux = inicio;
	while (inicio->getSig() != nullptr) {
		aux = inicio;
		inicio = inicio->getSig();
		delete aux;
	}
	if (inicio != nullptr) delete inicio;
}

Nodo* Lista::getInicio() { return inicio; }

void Lista::insertar(Nodo* nuevo) {
	if (inicio == nullptr) inicio = nuevo;
	else {
		Nodo* aux = inicio;
		while (aux->getSig() != nullptr) {
			aux = aux->getSig();
		}
		aux->setSig(nuevo);
	}
}

void Lista::insertarInicio(Nodo* nuevo) {
	if (inicio == nullptr) inicio = nuevo;
	else {
		nuevo->setSig(inicio);
		inicio = nuevo;
	}
}

void Lista::insertarFinal(Nodo* nuevo) {
	if (inicio == nullptr) inicio = nuevo;
	else {
		Nodo* aux = inicio;
		while (aux->getSig() != nullptr) {
			aux = aux->getSig();
		}
		aux->setSig(nuevo);
	}
}

void Lista::borrar(Nodo* borrar) {
	if (inicio == borrar) {
		inicio = inicio->getSig();
		delete borrar;
	}
	else {
		Nodo* aux = inicio;
		while (aux->getSig() != borrar)aux = aux->getSig();
		aux->setSig(borrar->getSig());
		delete borrar;
	}
}

bool Lista::listsaVacia() { return inicio == nullptr; }

int Lista::cantidadNodos() {
	int n = 0;
	Nodo* aux = inicio;
	while (aux != nullptr) {
		n++;
		aux = aux->getSig();
	}
	return n;
}

void Lista::guardarLista() {//Guarda los jugadores en orden de primero a ultimo.
	std::ofstream archivo;
	archivo.open("Jugadores.txt");
	Nodo* aux = inicio;
	if (!archivo.is_open()) {
		std::cout << "No se pudo abrir el archivo" << std::endl;
		return;
	}

	while(aux!=nullptr) {
		archivo << aux->getJugador()->getNickname() << ";";
		for (int j = 0; j < aux->getJugador()->numeroCartas(); j++){
			archivo << aux->getJugador()->getCarta(j)->valorCarta() << ";";
			archivo << aux->getJugador()->getCarta(j)->getPalo() << ";";
			archivo << aux->getJugador()->getCarta(j)->getBocaAbajo() << ";";
		}
		archivo << '\n';
		aux = aux->getSig();
	}

	archivo.close();
}

void Lista::cargarLista() {
	std::ifstream archivo;
	archivo.open("Jugadores.txt");
	if (!archivo.is_open()) {
		std::cout << "No se pudo abrir el archivo" << std::endl;
		return;
	}
	std::string nombre;
	int valor;
	int palo;
	bool bocaAbajo;
	std::string buffer;

	while (std::getline(archivo, buffer, '\n')) {
		std::istringstream linea(buffer);
		std::getline(linea, nombre, ';');
		JugadorGenerico* jugador;
		if (nombre != "Dealer") { 
			jugador = new Jugador(nombre); 
		}
		else {
			jugador = new Dealer();
		}
		while (linea) {
			std::string str;
			std::getline(linea, str, ';');
			valor = std::stoi(str);
			std::getline(linea, str, ';');
			palo = std::stoi(str);
			std::getline(linea, str, ';');
			bocaAbajo = std::stoi(str);
			Carta* carta = new Carta(valor, palo,bocaAbajo);
			jugador->agregarCarta(carta);
		}
	}
	archivo.close();
}