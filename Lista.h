#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Jugador.h"
#include "Dealer.h"
#include <fstream>
#include <sstream>

class Lista{
private:
	Nodo* inicio;
public:
	Lista();
	~Lista();
	Nodo* getInicio();
	void insertar(Nodo*);
	void insertarInicio(Nodo*);
	void insertarFinal(Nodo*);
	void borrar(Nodo*);
	bool listsaVacia();
	int cantidadNodos();
	void guardarLista();
	void cargarLista();
};

#endif