#include "Carta.h"

Carta::Carta(int n, int p, bool bA) : num(n), palo(p), bocaAbajo(bA) {}
Carta::Carta() : num(0), palo(0), bocaAbajo(false) {}
Carta::~Carta() {}
void Carta::setNum(int n) { num = n; }
void Carta::setPalo(int p) { palo = p; }
void Carta::setBocaAbajo(bool bA) { bocaAbajo = bA; }
void Carta::voltear() { bocaAbajo = !bocaAbajo; }
int Carta::getNum() { if (num < 11) { return num; } else return 10; }

std::string Carta::toString() {//Método toString
	std::stringstream s;
	switch (num)
	{
	case 1: s << "A de ";
		break;
	case 2: s << "2 de ";
		break;
	case 3: s << "3 de ";
		break;
	case 4: s << "4 de ";
		break;
	case 5: s << "5 de ";
		break;
	case 6: s << "6 de ";
		break;
	case 7: s << "7 de ";
		break;
	case 8: s << "8 de ";
		break;
	case 9: s << "9 de ";
		break;
	case 10: s << "10 de ";
		break;
	case 11: s << "J de ";
		break;
	case 12:s << "Q de ";
		break;
	case 13: s << "K de ";
		break;
	default: s << "Error en num(Carta.h)" << '\n';
		break;
	}
	switch (palo)
	{
	case 0: s << "Diamantes" << '\n';
		break;
	case 1: s << "Treboles" << '\n';
		break;
	case 2: s << "Espadas" << '\n';
		break;
	case 3: s << "Corazones" << '\n';
		break;

	default: s << "Error en Carta" << '\n';//Si ocurre un error retorna un mensaje con la ubicación del error
		break;
	}
	return s.str();
}