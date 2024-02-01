#include "Lista.h"

Lista::Lista():inicio(nullptr){}
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
	if(inicio == nullptr) inicio = nuevo;
	else{
		Nodo* aux = inicio;
		while(aux->getSig()!=nullptr){
			aux=aux->getSig();
		}
		aux->setSig(nuevo);
	}
}

void Lista::insertarInicio(Nodo* nuevo) {
	if(inicio == nullptr) inicio = nuevo;
	else {
		nuevo->setSig(inicio);
		inicio=nuevo;
	}
}

void Lista::borrar(Nodo* borrar) {
	if (inicio == borrar) {
		inicio=inicio->getSig();
		delete borrar;
	}
	else {
		Nodo* aux = inicio;
		while (aux->getSig() != borrar)aux = aux->getSig();
		aux->setSig(borrar->getSig());
		delete borrar;
	}
}

bool Lista::listsaVacia() { return inicio==nullptr; }