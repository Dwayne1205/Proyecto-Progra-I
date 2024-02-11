#ifndef MANO_H
#define MANO_H

#include "Mazo.h"

class Mano {
private:
    static const int maxCartas;  //Declara la variable
    Carta** cartas;
    int numCartas;

public:
    Mano();
    ~Mano();
    std::string toString();
    void agregarCartaM(Mazo*);
    void agregarCarta(Carta*);
    void limpiar();
    int getPuntos();
    Carta** getCartas();
    int getNumCartas();
    void voltearCarta(int); 
    Carta* ultimaCarta();
};
#endif
