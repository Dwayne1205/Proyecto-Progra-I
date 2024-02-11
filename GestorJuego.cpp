#include "GestorJuego.h"

GestorJuego::GestorJuego() {}
GestorJuego::GestorJuego(Juego* j):juego{j}{}

void GestorJuego::empezarPartida() {
    
	juego->getBaraja()->inicializar();
	juego->getBaraja()->barajear();

    std::cout << "Ingrese la cantidad de jugadores: ";
    std::cin >> canJugadores;
    juego->DealerSet();
    for (int i = 0; i < canJugadores; i++) {
        std::string nickname;
        std::cout << "Ingrese el nickname del jugador " << i + 1 << ": ";
        std::cin >> nickname;
        JugadorGenerico* jG = new Jugador(nickname);
        juego->Jugadores(jG);
    }
}
GestorJuego::~GestorJuego() {}


void GestorJuego::mostrarMenu() {
   if(juego){
        int opcion;
        bool pide;
        do {
            std::cout << "----- BlackJack -----" << std::endl;
            std::cout << "1. Empezar partida" << std::endl;
            std::cout << "2. Realizar ronda" << std::endl;
            std::cout << "3. Salir" << std::endl;
            std::cout << "Ingrese su opción: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                
                empezarPartida();
                system("cls");

                break;
            case 2:
                realizarRonda();
                break;
            case 3:
                cargarPartida();
                std::cout << "Partida cargada" << std::endl;
                break;
            case 4:
                std::cout << "Saliendo del juego" << std::endl;
                exit(0); // Termina el programa
                break;
            default:
                std::cout << "Opción no válida. Por favor, ingrese una opción válida." << std::endl;
                break;
            }
        } while (opcion != 4);
    }
}

void GestorJuego::repartir() {
		
		Nodo* nodoAux = juego->getListaJugadores()->getInicio();
		while (nodoAux != nullptr) {
				nodoAux->getJugador()->pedirCarta(juego->getBaraja());
				nodoAux->getJugador()->pedirCarta(juego->getBaraja());
			
                if (nodoAux != nullptr&& nodoAux->getJugador()->getNickname()=="Dealer") {
            nodoAux->getJugador()->getMano()->voltearCarta(1);
		}
				nodoAux = nodoAux->getSig();
		}
		
	}
void GestorJuego::cargarPartida() {
    juego->cargarPartida();
}

void GestorJuego::realizarRonda() {
    if (juego->getListaJugadores()->getInicio() != nullptr) {
        Nodo* nodoAux = juego->getListaJugadores()->getInicio();
        while (nodoAux != nullptr) {
            char opcion;
            bool opcionValida = false; // Variable para verificar si la opción ingresada es válida
            do {
                std::cout << nodoAux->getJugador()->getNickname() << ":" << std::endl;
                std::cout << "Mano: " << nodoAux->getJugador()->getMano()->toString() << std::endl;
                std::cout << "(D)eme carta - (P)asar - (G)uardar Partida - (S)alir" << std::endl;
                std::cout << "Ingrese su opción: ";
                std::cin >> opcion;

                /*Después de cada acción del jugador, se valida la opción ingresada y se ejecuta la acción correspondiente.
                El bucle continúa hasta que todos los jugadores hayan tomado su decisión en esta ronda*/

                switch (opcion) {
                case 'D':
                case 'd':
                    nodoAux->getJugador()->pedirCarta(juego->getBaraja());
                    opcionValida = true;
                    break;
                case 'P':
                case 'p':
                    nodoAux = nodoAux->getSig();
                    opcionValida = true;
                    break;
                case 'G':
                case 'g':
                    guardarPartida(); // Guardar la partida antes de pasar al siguiente jugador
                    std::cout << "Partida guardada." << std::endl;
                    opcionValida = true;
                    break;
                case 'S':
                case 's':
                    std::cout << "Saliendo del juego" << std::endl;
                    exit(0);
                    break;
                default:
                    std::cout << "Opción no válida. Por favor, ingrese una opción válida." << std::endl;
                    break;
                }
            } while (!opcionValida); // Continuar solicitando una opción válida hasta que se ingrese una
        }
    }
    //Si no hay jugadores en la lista, se muestra un mensaje indicando que se debe iniciar la partida primero
    else {
        std::cout << "Debe empezar la partida primero." << std::endl;
    }
}
//guarda la partida actual en un archivo para que pueda ser cargada después
void GestorJuego::guardarPartida() {
    std::string nombreArchivo = "partida_guardada.txt";
    juego->guardarPartida(nombreArchivo);
}

		
	

