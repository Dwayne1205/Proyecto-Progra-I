#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
class Lista{
private:
	Nodo* inicio;
public:
	Lista();
	~Lista();
	Nodo* getInicio();
	void insertar(Nodo*);
	void insertarInicio(Nodo*);
	void borrar(Nodo*);
	bool listsaVacia();
};

#endif