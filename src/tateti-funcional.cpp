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
#include "tateti-funcional.hpp"

/* TEMPLATE VARIANT */
#if TEMPLATE_VARIANT == 1

/**
 * Funcion que devuelve una fila de la matriz dada.
 * @param rowindex indice de la fila.
 * @param matriz de donde se extraera la fila.
 * @return La fila deseada.
 */
template<typename T>
Fila<T> fila(int rowindex, Matriz<T> matriz) {
	switch(rowindex) {
	case 1: return matriz.fila1;
	case 2: return matriz.fila2;
	case 3: return matriz.fila3;
	default: return Fila<T>{V, V, V};
	}
}

#endif

#if TEMPLATE_VARIANT == 0

/**
 * Funcion que devuelve una fila de la matriz dada.
 * @param rowindex indice de la fila.
 * @param matriz de donde se extraera la fila.
 * @return La fila deseada.
 */
Fila fila(const int &rowindex, const Matriz &matriz) {
	switch(rowindex) {
	case 1: return matriz.fila1;
	case 2: return matriz.fila2;
	case 3: return matriz.fila3;
	default: return Fila{V, V, V};
	}
}

/**
 * Funcion que devuelve una fila con un item modificado.
 * @param value valor del nuevo item.
 * @param colindex indice de la columna.
 * @param fila la fila que se modificara.
 * @return La fila modificada.
 */
Fila putrow(const TTT &value, const int &colindex, const Fila &fila) {
	switch (colindex) {
	case 1: return Fila {value, fila.item2, fila.item3};
	case 2: return Fila {fila.item1, value, fila.item3};
	case 3: return Fila {fila.item1, fila.item2, value};
	default : return fila;
	}
}

/**
 * Funcion que devuelve una matriz con un item modificado.
 * @param value valor del nuevo item.
 * @param rowindex indice de la fila.
 * @param colindex indice de la columna.
 * @param matriz la matriz que se modificara.
 * @return La matriz modificada.
 */
Matriz putval(const TTT &value, const int &rowindex, const int &colindex, const Matriz &matriz) {
	switch (rowindex) {
	case 1: return Matriz {putrow(value, colindex, matriz.fila1), matriz.fila2, matriz.fila3};
	case 2: return Matriz {matriz.fila1, putrow(value, colindex, matriz.fila2), matriz.fila3};
	case 3: return Matriz {matriz.fila1, matriz.fila2, putrow(value, colindex, matriz.fila3)};
	default: return matriz;
	}
}

/**
 * Funcion que devuelve un item de una fila.
 * @param colindex indice de la columna.
 * @param fila la fila que contiene el item.
 * @return El item deseado.
 */
TTT getvalrow(const int &colindex,const  Fila &fila){
	switch (colindex) {
	case 1: return fila.item1;
	case 2: return fila.item2;
	case 3: return fila.item3;
	default: return TTT::V;
	}
}

/**
 * Funcion que devuelve un item de una fila de una matriz.
 * @param colindex indice de la columna.
 * @param rowindex indice de la fila.
 * @param matriz la matriz que contiene el item.
 * @return El item deseado.
 */
TTT getval(const int &rowindex, const int &colindex, const Matriz &matriz) {
	switch (rowindex) {
	case 1: return getvalrow(colindex, matriz.fila1);
	case 2: return getvalrow(colindex, matriz.fila2);
	case 3: return getvalrow(colindex, matriz.fila3);
	default: return TTT::V;
	}
}

/**
 * Objeto que contiene una posicion definido por dos integer
 */
typedef std::pair<int, int> Posic;

/**
 * Funcion que devuelve un vector con todos las posibles posiciones del tablero.
 * @return vector con todos las posibles posiciones del tablero.
 */
std::vector<Posic> allpos() {
	std::vector<Posic> allposs;
	for (int i = 1; i <= 3; i++) {
		for (size_t j = 1; j <= 3; j++) {
			allposs.push_back(std::make_pair(i, j));
		}
	}
	return allposs;
}

/**
 * Funcion que devuelve un item de una posicion de una matriz.
 * @param posicion la posicion del item.
 * @param matriz la matriz que contiene el item.
 * @return El item deseado.
 */
TTT getposval(const Posic &posicion, const Matriz &matriz) {
	return getval(posicion.first, posicion.second, matriz);
}

/**
 * Funcion que devuelve todos los items de una fila de una matriz.
 * @param rowindex indice de la fila.
 * @param matriz la matriz que contiene el fila.
 * @return Un vector con los items de una fila.
 */
std::vector<TTT> getRowVals(const int &rowindex, const Matriz &matriz) {
	return std::vector<TTT> {getval(rowindex, 1, matriz), getval(rowindex, 2, matriz), getval(rowindex, 3, matriz)};
}

/**
 * Funcion que devuelve todos los items de una columna de una matriz.
 * @param colindex indice de la columna.
 * @param matriz la matriz que contiene el columna.
 * @return Un vector con los items de una columna.
 */
std::vector<TTT> getColVals(const int &colindex, const Matriz &matriz) {
	return std::vector<TTT> {getval(1, colindex, matriz), getval(2, colindex, matriz), getval(3, colindex, matriz)};
}

/**
 * Funcion que devuelve todos los items de la diagonal principal de una matriz.
 * @param matriz la matriz que contiene la diagonal principal.
 * @return Un vector con los items de la diagonal principal.
 */
std::vector<TTT> getDiagPpal(const Matriz &matriz) {
	return std::vector<TTT> {getval(1, 1, matriz), getval(2, 2, matriz), getval(3, 3, matriz)};
}

/**
 * Funcion que devuelve todos los items de la diagonal secundaria de una matriz.
 * @param matriz la matriz que contiene la diagonal secundaria.
 * @return Un vector con los items de la diagonal secundaria.
 */
std::vector<TTT> getDiagSec(const Matriz &matriz) {
	return std::vector<TTT> {getval(1, 3, matriz), getval(2, 2, matriz), getval(3, 1, matriz)};
}

/* OVERLOAD THE + OPERATOR FOR VECTORS */
template<typename T>
std::vector<T> operator+(std::vector<T> vec1, const std::vector<T>&& vec2)
{
    std::move(vec2.begin(), vec2.end(), std::back_inserter(vec1));
    return vec1;
}

/**
 * Funcion que devuelve todos los items de las diagonales que intersectan con una posicion de una matriz.
 * 
 * Utilizando insert(...) la mejor forma que se encontro para concatenar 2 vectores.
 * Edit: Se encontro una forma de sobrecarcar el operador '+' para concatenar vectores.
 * 
 * @param posicion la posicion.
 * @param matriz la matriz que contiene la diagonal secundaria.
 * @return Un vector con todos los items de las diagonales que intersectan a la posicion.
 */
std::vector<TTT> mydiags(const Posic &posicion, const Matriz &matriz) {
	if ((posicion.first == 2) && (posicion.second == 2)) {
		return getDiagPpal(matriz) + getDiagSec(matriz);
	}
	if ((posicion.first == 1) && (posicion.second == 1)) return getDiagPpal(matriz);
	if ((posicion.first == 3) && (posicion.second == 3)) return getDiagPpal(matriz);
	if ((posicion.first == 1) && (posicion.second == 3)) return getDiagSec(matriz);
	if ((posicion.first == 3) && (posicion.second == 1)) return getDiagSec(matriz);
	return std::vector<TTT> {};
}

/**
 * Funcion que devuelve el valor de un item para un jugador.
 * @param mivalor el valor del jugador.
 * @param valor el valor de un item.
 * @return Un numero que representa el valor de un item para un jugador.
 */
int playvalue(const TTT &mivalor, const TTT &valor) {
	if (mivalor == valor) return 2;
	if (valor == TTT::V) return 1;
	else return 0;
}

/**
 * Funcion que devuelve los valores de una coleccion de items para un jugador.
 * 
 * Dato interesante: utilizando la libreria <ranges> en C++20 (gcc v10.x)
 * se puede utilizar std::views::transform para evitar la creacion del 
 * objeto vector antes de hacer return.
 * 
 * @param mivalor el valor del jugador.
 * @param valores los valores de una coleccion de items.
 * @return Numeros que representan los valores de una coleccion de items para un jugador.
 */
std::vector<int> valorize(const TTT &mivalor, const std::vector<TTT> &valores) {
	std::vector<int> valnums;
	std::transform(valores.begin(), valores.end(), std::back_inserter(valnums), 
		std::bind(&playvalue, mivalor, std::placeholders::_1));
    return valnums;
}

/**
 * Funcion que devuelve el valor de una posicion en una matriz para un jugador.
 * @param mivalor el valor del jugador.
 * @param posicion la posicion.
 * @param matriz la matriz.
 * @return Un numero que representa el valor de una posicion en una matriz para un jugador.
 */
int valpos(const TTT &mivalor, const Posic &posicion, const Matriz &matriz) {
	std::vector<int> myvalues = valorize(mivalor, 
										 getColVals(posicion.second, matriz) + 
										 getRowVals(posicion.first, matriz) + 
										 mydiags(posicion, matriz));
	return std::accumulate(myvalues.begin(), myvalues.end(), 0);
}

/**
 * Funcion que devuelve los valores de todas las posiciones en una matriz para un jugador.
 * @param mivalor el valor del jugador.
 * @param matriz la matriz.
 * @return Una coleccion con todas las posiciones de una matriz y sus valores numericos asiciados para un jugador.
 */
std::vector<std::pair<Posic, int>> allposValues(const TTT  &mivalor, const Matriz &matriz) {
    std::vector<std::pair<Posic, int>> allposvalues;
    std::vector<Posic> allposvector = allpos();
    std::transform(begin(allposvector), end(allposvector), back_inserter(allposvalues), 
		[mivalor, matriz] (Posic pos) {return make_pair(pos, valpos(mivalor, pos, matriz));});
    return allposvalues;
}

/**
 * Funcion que devuelve todos los trios de posiciones en una matriz que un jugador puede utilizar para ganar.
 * @param matriz la matriz.
 * @return Una coleccion con todos los trios de posiciones y sus valores.
 */
std::vector<std::vector<TTT>> allTrios(const Matriz &matriz) {
    std::vector<int> n = {1, 2, 3};
	std::vector<std::vector<TTT>> trios;
	trios.push_back(getDiagPpal(matriz));
	trios.push_back(getDiagSec(matriz));
    std::transform(begin(n), end(n), back_inserter(trios), 
		std::bind(&getColVals, std::placeholders::_1, matriz));
    std::transform(begin(n), end(n), back_inserter(trios), 
		std::bind(&getRowVals, std::placeholders::_1, matriz));
    return trios;
}

/**
 * Funcion que devuelve todas las posiciones vacias de una matriz y sus valores numericos asiciados para un jugador.
 * @param mivalor el valor del jugador.
 * @param matriz la matriz.
 * @return Una coleccion con todas las posiciones vacias de una matriz y sus valores numericos asiciados para un jugador.
 */
std::vector<std::pair<Posic, int>> availmoves(const TTT &mivalor, const Matriz &matriz) {
    std::vector<std::pair<Posic, int>> posvalues = allposValues(mivalor, matriz);
	posvalues.erase(std::remove_if(posvalues.begin(), posvalues.end(), 
		[matriz] (std::pair<Posic, int> posval) {return getposval(posval.first, matriz) != TTT::V;
		}), posvalues.end());
    return posvalues;
}

/**
 * Funcion que calcula la mejor posicion en la que un jugador puede jugar.
 * @param mivalor el valor del jugador.
 * @param matriz la matriz.
 * @return la mejor posicion en la que un jugador puede jugar.
 */
Posic bestmove(const TTT &mivalor, const Matriz &matriz) {
	std::vector<std::pair<Posic, int>> posvalues = availmoves(mivalor, matriz);
	return std::accumulate(posvalues.begin(), posvalues.end(), posvalues[0], 
		[] (std::pair<Posic, int> posvalbest, std::pair<Posic, int> posvalnew) {
			return (posvalbest.second >= posvalnew.second) ? posvalbest : posvalnew;}).first;
};

/**
 * Funcion que realiza una jugada para jugador en una posicion de una matriz.
 * @param mivalor el valor del jugador.
 * @param posicion la posicion del jugador.
 * @param matriz la matriz.
 * @return La matriz con la nueva jugada realizada.
 */
Matriz play(const TTT &mivalor, const Posic &posicion, const Matriz &matriz) {
	return putval(mivalor, posicion.first, posicion.second, matriz);
}

/**
 * Funcion que realiza la mejor jugada para el jugador en una posicion de una matriz.
 * @param mivalor el valor del jugador.
 * @param matriz la matriz.
 * @return La matriz con la nueva mejor jugada realizada.
 */
Matriz playbest(const TTT &mivalor, const Matriz &matriz) {
	return play(mivalor, bestmove(mivalor, matriz), matriz);
}

/**
 * Funcion que verifica si un jugador gano en una matriz.
 * @param valor el valor del jugador.
 * @param matriz la matriz.
 * @return Verdadero si el jugador gano, falso en caso contrario.
 */
bool gano(const TTT &valor, const Matriz &matriz) {
    std::vector<std::vector<TTT>> trios = allTrios(matriz);
	return std::any_of(trios.begin(), trios.end(), 
		[valor] (std::vector<TTT> trio) {return std::all_of(trio.begin(), trio.end(), 
				[valor] (TTT valortrio) {return valor == valortrio;}); });
}

/**
 * Funcion que verifica si hay un empate en una matriz.
 * @param matriz la matriz.
 * @return Verdadero si hay un empate, falso en caso contrario.
 */
bool empate(const Matriz &matriz) {
	return !gano(TTT::X, matriz) && !gano(TTT::Y, matriz);
}

/**
 * Funcion que verifica si no quedan lugares vacios en una matriz.
 * @param matriz la matriz.
 * @return Verdadero si no quedan lugares vacios, falso en caso contrario.
 */
bool nofreePlace(const Matriz &matriz) {
    std::vector<Posic> allposvector = allpos();
	return std::all_of(allposvector.begin(), allposvector.end(), 
		[matriz] (Posic pos) {return TTT::V != getposval(pos, matriz);});
}

/**
 * Funcion que verifica si no hay mas jugadas posibles en una matriz.
 * @return Verdadero si no hay mas jugadas posibles, falso en caso contrario.
 */
bool finished(const Matriz &matriz) {
    return gano(TTT::X ,matriz) || gano (TTT::Y, matriz) || nofreePlace(matriz);
}

/**
 * Funcion que devuelve quien gano en una matriz
 * @return String con el resultado de la matriz
 */
std::string resultado(const Matriz &matriz) {
    if (gano(X, matriz)) {return "Gano X";}
    else if (gano(Y, matriz)) {return "Gano Y";}
	else {return "Empate";}
}


/**
 * Funcion que permite al usuario ingresar una posicion, esta es validada.
 * @return La posicion valida.
 */
Posic readPos() {
    std::set<int> posicion = {1, 2, 3};
    int f, c;
    std::cout << "fila:" << std::endl;
    std::cin >> f;
    std::cout << "columna:" << std::endl;
    std::cin >> c;
	if (!(posicion.count(f) && posicion.count(c))) {
		std::cout << "valores invalidos" << std::endl;
		readPos();
	}
	return Posic(f, c);
}

/**
 * Funcion que realiza una jugada en la posicion ingresada por el usuario.
 * @param matriz la matriz.
 * @return Matriz con el nuevo estado del juego.
 */
Matriz newStatePlayer(const Matriz &matriz) {
   return (play(Y, readPos(), matriz));
}

/**
 * Funcion que realiza una jugada para un jugador en una matriz y avanza al proximo estado.
 * @param matriz la matriz.
 * @param valor el valor del jugador. Maquina = X, usuario = Y.
 * @return Matriz con el nuevo estado del juego.
 */
Matriz newState(Matriz matriz, const TTT &valor) {
    if (valor == Y) {matriz = newStatePlayer(matriz);} else {matriz = playbest(TTT::X, matriz);}
    if (valor == Y) {std::cout << "player" << std::endl;} else {std::cout << "maquina" << std::endl;}
    std::cout << matriz.show();
    if (!finished(matriz)) {
		return newState(matriz, (valor == TTT::Y)? TTT::X : TTT::Y);
	}
	return matriz;
}

#endif

// int main() {
// 	char m;

// 	std::cout << "tablero generado:" << std::endl;
// 	std::cout << tablero.show();

// 	std::cout << "Ta-Te-Ti Funcional" << std::endl;
// 	std::cout << " " << std::endl;
// 	std::cout << "X maquina Y persona" << std::endl;
// 	std::cout << " " << std::endl;
//     std::cout << "empieza (S/N)?" << std::endl;
// 	std::cin >> m;
// 	tablero = newState(tablero, (m == 'S' || m == 's')? TTT::Y : TTT::X);

//     std::cout << resultado(tablero) << std::endl;
// 	return 0;
// }
