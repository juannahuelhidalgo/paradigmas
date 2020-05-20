/**
 * @file tateti-funcional.cpp
 * @brief Programa bajo paradigma funcional que juega al TaTeTi
 *
 * PARADIGMAS DE PROGRAMACION\n
 * Proyecto de Programación Funcional\n
 * Trabajo práctico N°1\n
 * Abril de 2020
 *
 * @author name1, name2
 * @date Abril de 2020
 * @see link a git
 */
#include <iostream>
#include "tateti-funcional.hpp"

int main() {
	char m;

    /**
     * El tablero base del juego, una matriz con todos los items con el valor V (vacio)
     */
    Matriz tablero = Matriz {Fila{V, V, V}, Fila{V, V, V}, Fila{V, V, V}};

	std::cout << "Ta-Te-Ti Funcional" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "X maquina Y persona" << std::endl;
	std::cout << " " << std::endl;
    std::cout << "empieza (S/N)?" << std::endl;
	std::cin >> m;
	tablero = newState(tablero, (m == 'S' || m == 's')? TTT::Y : TTT::X);

    std::cout << resultado(tablero) << std::endl;
	return 0;
}