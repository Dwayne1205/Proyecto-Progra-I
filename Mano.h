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
    void agregarCarta(Mazo* mazo);
    void limpiar();
    int getPuntos();
};

#endif
