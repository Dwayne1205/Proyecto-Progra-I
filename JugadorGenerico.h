#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H

#include <string>
#include "Mano.h"

class JugadorGenerico {
protected:
    std::string nickname;
    Mano* mano;

public:
    JugadorGenerico(const std::string& nombre);
    virtual ~JugadorGenerico();
    virtual Carta* pedirCarta(Mazo* mazo)=0;
    bool sePaso();
    std::string getNickname();
    void setNickname(std::string);
    Mano* getMano();
    void setMano(Mano*);
    Carta* getCarta(int);
    int numeroCartas();
    void agregarCarta(Carta*);

};
#endif
