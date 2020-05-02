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
#include <ostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

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
};

/**
 * Funcion que devuelve una fila de la matriz dada.
 * @param rowindex indice de la fila.
 * @param matriz de donde se extraera la fila.
 * @return La fila deseada.
 */
Fila fila(int rowindex, Matriz matriz) {
	switch(rowindex) {
	case 1: return matriz.fila1;
	case 2: return matriz.fila2;
	case 3: return matriz.fila3;
	}
}

/**
 * Funcion que devuelve una fila con un item modificado.
 * @param value valor del nuevo item.
 * @param colindex indice de la columna.
 * @param fila la fila que se modificara.
 * @return La fila modificada.
 */
Fila putrow(TTT value, int colindex, Fila fila) {
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
Matriz putval(TTT value, int rowindex, int colindex, Matriz matriz) {
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
TTT getvalrow(int colindex, Fila fila){
	switch (colindex) {
	case 1: return fila.item1;
	case 2: return fila.item2;
	case 3: return fila.item3;
	}
}

/**
 * Funcion que devuelve un item de una fila de una matriz.
 * @param colindex indice de la columna.
 * @param rowindex indice de la fila.
 * @param matriz la matriz que contiene el item.
 * @return El item deseado.
 */
TTT getval(int colindex, int rowindex, Matriz matriz) {
	switch (rowindex) {
	case 1:  getvalrow (colindex, matriz.fila1);
	case 2:  getvalrow (colindex, matriz.fila2);
	case 3:  getvalrow (colindex, matriz.fila3);
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
	// for (std::vector<Posic>::iterator it = allposs.begin(); it != allposs.end(); ++it) {
	// 	auto p = std::make_pair(i, i);
	// 	allposs.push_back(p);

	for (int i = 1; i < 10; i++) {
		auto p = std::make_pair(i, i);
		allposs.push_back(p);
	};
	return allposs;
}

/**
 * El tablero base del juego, una matriz con todos los items con el valor V (vacio)
 */
Matriz tablero = Matriz {Fila{V, V, V}, Fila{V, V, V}, Fila{V, V, V}};

/**
 * Funcion que devuelve un item de una posicion de una matriz.
 * @param posicion la posicion del item.
 * @param matriz la matriz que contiene el item.
 * @return El item deseado.
 */
TTT getposval(Posic posicion, Matriz matriz) {
	getval(posicion.first, posicion.second, matriz);
}

/**
 * Funcion que devuelve todos los items de una fila de una matriz.
 * @param rowindex indice de la fila.
 * @param matriz la matriz que contiene el fila.
 * @return Un vector con los items de una fila.
 */
std::vector<TTT> getRowVals(int rowindex, Matriz matriz) {
	return std::vector<TTT> {getval(rowindex, 1, matriz), getval(rowindex, 2, matriz), getval(rowindex, 3, matriz)};
}

/**
 * Funcion que devuelve todos los items de una columna de una matriz.
 * @param colindex indice de la columna.
 * @param matriz la matriz que contiene el columna.
 * @return Un vector con los items de una columna.
 */
std::vector<TTT> getColVals(int colindex, Matriz matriz) {
	return std::vector<TTT> {getval(1, colindex, matriz), getval(2, colindex, matriz), getval(3, colindex, matriz)};
}

/**
 * Funcion que devuelve todos los items de la diagonal principal de una matriz.
 * @param matriz la matriz que contiene la diagonal principal.
 * @return Un vector con los items de la diagonal principal.
 */
std::vector<TTT> getDiagPpal(Matriz matriz) {
	return std::vector<TTT> {getval(1, 1, matriz), getval(2, 2, matriz), getval(3, 3, matriz)};
}

/**
 * Funcion que devuelve todos los items de la diagonal secundaria de una matriz.
 * @param matriz la matriz que contiene la diagonal secundaria.
 * @return Un vector con los items de la diagonal secundaria.
 */
std::vector<TTT> getDiagSec(Matriz matriz) {
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
std::vector<TTT> mydiags(Posic posicion, Matriz matriz) {
	/* en el primer caso hay que unir diagppal y diagsec*/
	if ((posicion.first == 2) && (posicion.second == 2)) {
		// std::vector<TTT> diagppal = getDiagPpal(matriz);
    	// std::vector<TTT> diagsec =  getDiagSec(matriz);
		// diagppal.insert(diagppal.end(), diagsec.begin(), diagsec.end());
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
int playvalue(TTT mivalor, TTT valor) {
	if (mivalor == valor) return 2;
	if (valor == V) return 1;
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
std::vector<int> valorize(TTT mivalor, std::vector<TTT> valores) {
	std::vector<int> valnums;
	std::transform(valnums.begin(), valnums.end(), valnums.begin(),
		[mivalor, valores](std::vector<TTT> valnums) {return  (valnums.push_back = (playvalue(mivalor,valores.back))); });

	/*auto valnums_bind = std::bind(&playvalue, mivalor, std::placeholders::_1);
	std::transform(valores.begin(), valores.end(), std::back_inserter(valnums), valnums_bind);*/
	return valnums;
}

/**
 * Funcion que devuelve el valor de una posicion en una matriz para un jugador.
 * @param mivalor el valor del jugador.
 * @param posicion la posicion.
 * @param matriz la matriz.
 * @return Un numero que representa el valor de una posicion en una matriz para un jugador.
 */
int valpos(TTT mivalor, Posic posicion, Matriz matriz) {
	std::vector<int> myvalues = valorize(mivalor, 
										 getColVals(posicion.second, matriz) + 
										 getRowVals(posicion.first, matriz) + 
										 mydiags(posicion, matriz));
	return std::accumulate(myvalues.begin(), myvalues.end(), 0);
}

// TO BE CONTINUED...

/**
 * Funcion que devuelve todos los valores de las posiciones de un jugador
 * @param mivalor el valor del jugador.
 * @param matriz la matriz.
 * @return un vector que representa lugar a lugar el valor de una posicion en una matriz para un jugador.
 */

typedef std::vector<Posic, int> posvalue;
std::vector<posvalue> allposValues(TTT  mivalor, Matriz tablero) {
    std::vector<posvalue> allposvalues;
    std::vector<Posic>allposs = allpos();
    auto allpos_bind = std::bind(&valpos, mivalor, tablero, std::placeholders::_1);
    std::transform(begin(allposs), end(allposs), back_inserter(allposvalues), allpos_bind);
    return allposvalues;
};

typedef std::vector<TTT> vecTTT;
std::vector<vecTTT> alltrios(Matriz tablero) {
    std::vector <TTT> col;
    std::vector <TTT> fil;
    std::vector <TTT> colfil;
    std::vector<int> n = { 1, 2, 3 };
    auto col_bind = std::bind(&getColVals, tablero, std::placeholders::_1);
    std::transform(begin(n), end(n), back_inserter(col), col_bind);
    auto fil_bind = std::bind(&getRowVals, tablero, std::placeholders::_1);
    std::transform(begin(n), end(n), back_inserter(fil), fil_bind);

 //SUMADO DE MAPAS?
    
    
    std::vector<vecTTT> trios = { (getDiagPpal(tablero)) ,  (getDiagSec(tablero) /*, colfil*/)};
  
    return trios;

};


/**
 * Funcion que devuelve todas las posiciones vacias
 * @param mivalor el valor del jugador
 * @param matriz la matriz.
 * @return un vector que representa la posicion y su valor.
 */
std::vector<posvalue> availmoves(TTT mivalor, Matriz tablero,Posic pos) {
    std::vector<posvalue>posiciones = allposValues(mivalor, tablero);
    std::vector<TTT> vacio = { V };
    std::vector<posvalue>availmoves;
    std::copy_if(posiciones.begin(), posiciones.end(), std::back_inserter(availmoves),
        [&vacio](const Fila& item)
        {   /* return std::find(vacio.begin(), vacio.end(), item) == vacio.end();*/});

    return availmoves;
 
}



/*template<typename T, typename Predicate>
std::vector<posvalue> availmoves(Predicate pred, TTT mivalor, Matriz tablero)
{
	auto results = std::vector<posvalue>{getposval((allposValues(mivalor, tablero)).push_back, tablero)};
	std::copy_if(begin(input), end(input), back_inserter(results), pred);
	return results;
}*/

Matriz play(TTT yo, Posic poss, Matriz tablero){
	return putval(yo, poss.first, poss.second,tablero);
};

Posic bestmove(TTT yo, Matriz tablero){
	//implementar
};

Matriz playbest(TTT yo, Matriz tablero) {
	return play(yo, bestmove(yo, tablero), tablero);
};

int main() {
	std::string m;

    std::cout << "tablero generado:" << std::endl;
	std::cout << tablero.show();

	std::cout << "Ta-Te-Ti Funcional" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "X maquina Y persona" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "empieza (S/N)?" << std::endl;

	std::cin >> m;
	if (m == "S") {
		std::cout << "Juege" << std::endl;
	} else {
		std::cout << "Empiezo" << std::endl;
	}

	system("PAUSE");
	return 0;
}
