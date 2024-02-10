#include "GestorJuego.h"

GestorJuego::GestorJuego() {}
GestorJuego::GestorJuego(Juego* j):juego{j}{}

void GestorJuego::empezarPartida() {

	juego->getBaraja()->inicializar();
	juego->getBaraja()->barajear();

}
GestorJuego::~GestorJuego() {}

void GestorJuego::Ronda(Nodo* x) {//Para pedir carta...

	Nodo* nodoAux = juego->getListaJugadores()->getInicio();
	while (nodoAux != nullptr) {
		if (nodoAux == x) {
			nodoAux->getJugador()->pedirCarta();	
		}
		nodoAux = nodoAux->getSig();
	}
}

Nodo* GestorJuego::encontrarJugador(const std::string& nombreJugador) {
    Nodo* nodoAux = juego->getListaJugadores()->getInicio();
    while (nodoAux != nullptr) {
        if (nodoAux->getJugador()->getNombre() == nombreJugador) {
            return nodoAux;
        }
        nodoAux = nodoAux->getSig();
    }
    return nullptr; // Si no se encuentra el jugador
}


void GestorJuego::mostrarMenu() {
   if(juego){
        int opcion;
        bool pide;
        
        do {
            std::cout << "----- Menú -----" << std::endl;
            std::cout << "1. Empezar partida" << std::endl;
            std::cout << "2. Realizar ronda" << std::endl;
            std::cout << "3. Salir" << std::endl;
            std::cout << "Ingrese su opción: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                
                empezarPartida(juego);
                int canJ;

                std::cout << "Ingrese la cantidad de jugadores: " << '\n';
                std::cin >> canJ;
                canJugadores = canJ;
                for (int i = 0; i < canJ; i++) {
                    std::string a;
                    std::cout << "Ingrese el nickname del jugador " << i + 1 << ": " << '\n';
                    std::cin >> a;
                    JugadorGenerico* jG = new Jugador(a);
                    juego->Jugadores(jG);
                }
                juego->Dealer();

                std::cout << "El dealer reparte...." << '\n';
                repartir();

                break;
            case 2:
                //Para ver si se ha comenzado la partida
                if (juego->getListaJugadores()->getInicio() != nullptr) {
                    // selecciona el jugador actual para la ronda
                    Nodo* nodoAux = juego->getListaJugadores()->getInicio();
                    while (nodoAux != nullptr) {
                        std::cout << "Pedir Carta:" << '\n';
                        std::cout << " 0:No" << '\n';
                        std::cout << " 1:Si" << '\n';
                        std::cin >> pide;
                        nodoAux->getJugador()->pedirCarta();
                    
                    }
                    else {
                        std::cout << "El jugador no se encontró." << std::endl;
                    }
                }
                else {
                    std::cout << "Debe empezar la partida primero." << std::endl;
                }
                break;
            case 3:
                std::cout << "Saliendo del juego..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Por favor, ingrese una opción válida." << std::endl;
                break;
            }
        } while (opcion != 3);
    }
}

void GestorJuego::repartir() {
		
		Nodo* nodoAux = juego->getListaJugadores()->getInicio();
		while (nodoAux != nullptr) {
				nodoAux->getJugador()->pedirCarta(juego->getBaraja());
				nodoAux->getJugador()->pedirCarta(juego->getBaraja());
			
				nodoAux = nodoAux->getSig();
		}
		if (nodoAux == nullptr) {
            nodoAux->getJugador()->getMano()->voltearCarta(1);
		}
	}
}

		
	

