#ifndef TATETI_FUNCIONAL_H
#define TATETI_FUNCIONAL_H

/**
 * TODO: Implement all functions as generic templates
 */

#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <functional>

/**
 * Enum que define los tipos de datos que contendra el tablero.
 * V = Vacio
 * X = Jugador 1
 * Y = Jugador 2
 */
enum TTT {V, X, Y};

/**
 * Estructura que contiene los objetos en una fila.
 */
struct Fila {
	TTT item1;
	TTT item2;
	TTT item3;
	
	/**
	 * Retorna un string con todos los objetos de la fila.
	 */
	auto show() {
		return std::to_string((int)item1) + " " + std::to_string((int)item2) + " " + std::to_string((int)item3);
	}

    friend bool operator==(const Fila &filaA, const Fila &filaB) {
        return filaA.item1 == filaB.item1 && filaA.item2 == filaB.item2 && filaA.item3 == filaB.item3;
    }

    friend bool operator!=(const Fila &filaA, const Fila &filaB) {
        return !(filaA == filaB);
    }
};

/**
 * Estructura que contiene las filas de una matriz.
 */
struct Matriz {
	Fila fila1;
	Fila fila2;
	Fila fila3;

	/**
	 * Retorna un string con todos las filas de la matriz.
	 */
	auto show() {
		return fila1.show() + "\n" + fila2.show() + "\n" + fila3.show() + "\n";
	}

    friend bool operator==(const Matriz &matrizA, const Matriz &matrizB) {
        return matrizA.fila1 == matrizB.fila1 && matrizA.fila2 == matrizB.fila2 && matrizA.fila3 == matrizB.fila3;
    }

    friend bool operator!=(const Matriz &matrizA, const Matriz &matrizB) {
        return !(matrizA == matrizB);
    }

    // friend bool operator==(const Matriz &matrizA, const Matriz &matrizB) {

    // }
};

Fila fila(int rowindex, Matriz matriz);
std::string resultado(Matriz matriz);
Matriz newState(Matriz matriz, TTT valor);

// /**
//  * Enum que define los tipos de datos que contendra el tablero.
//  * V = Vacio
//  * X = Jugador 1
//  * Y = Jugador 2
//  */
// enum TTT {V, X, Y};

// /**
//  * Estructura que contiene los objetos en una fila.
//  */
// template<typename T>
// struct Fila {
// 	T item1;
// 	T item2;
// 	T item3;
	
// 	/**
// 	 * Retorna un string con todos los objetos de la fila.
// 	 */
// 	auto show() {
// 		return std::to_string((int)item1) + " " + std::to_string((int)item2) + " " + std::to_string((int)item3);
// 	}

//     friend bool operator==(const Fila &filaA, const Fila &filaB) {
//         return filaA.item1 == filaB.item1 && filaA.item2 == filaB.item2 && filaA.item3 == filaB.item3;
//     }

//     friend bool operator!=(const Fila &filaA, const Fila &filaB) {
//         return !(filaA == filaB);
//     }
// };

// /**
//  * Estructura que contiene las filas de una matriz.
//  */
// template<typename T>
// struct Matriz {
// 	Fila<T> fila1;
// 	Fila<T> fila2;
// 	Fila<T> fila3;

// 	/**
// 	 * Retorna un string con todos las filas de la matriz.
// 	 */
// 	auto show() {
// 		return fila1.show() + "\n" + fila2.show() + "\n" + fila3.show() + "\n";
// 	}

//     friend bool operator==(const Matriz &matrizA, const Matriz &matrizB) {
//         return matrizA.fila1 == matrizB.fila1 && matrizA.fila2 == matrizB.fila2 && matrizA.fila3 == matrizB.fila3;
//     }

//     friend bool operator!=(const Matriz &matrizA, const Matriz &matrizB) {
//         return !(matrizA == matrizB);
//     }
// };

// /**
//  * Funcion que devuelve una fila de la matriz dada.
//  * @param rowindex indice de la fila.
//  * @param matriz de donde se extraera la fila.
//  * @return La fila deseada.
//  */
// template<typename T>
// Fila<T> fila(int rowindex, Matriz<T> matriz);

#endif