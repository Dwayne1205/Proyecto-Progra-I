#ifndef CARTA_H
#define CARTA_H
#include <sstream>

class Carta {
	//Atributos de Carta.h
private:

	int num;
	int palo;
	bool bocaAbajo;

public:

	Carta(int, int, bool);//Costructor con parametros
	Carta();
	~Carta();
	void setNum(int);
	void setPalo(int);
	int getPalo();
	bool getBocaAbajo();
	void setBocaAbajo(bool);
	int getNum();
	void voltear();
	std::string toString();
	int valorCarta();
};


#endif
