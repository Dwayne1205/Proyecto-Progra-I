#ifndef MAZO_H
#define MAZO_H
#include "Carta.h"
#include<random>//Biblioteca para generar numeros aleatorios.
#include<iostream>
#include <fstream>

class Mazo {
private:
	Carta** cartas;
	int can;
	int tam;

public:
	Mazo();
	~Mazo();
	void inicializar();
	void barajear();
	Carta* tomarCarta();
	void sacarDelMazo(int n);
	void guardarMazo();
	void cargarMazo();
};
#endif