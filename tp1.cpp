#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <algorithm>

enum TTT { V, X, Y };

/* dice que no puede deducir el tipo del item con auto,
 * por ahora no se como solucionarlo */
struct Fila {
	TTT item1;
	TTT item2;
	TTT item3;

	void show() {
		std::cout << item1 << " " << item2 << " " << item3 << std::endl;
	}
};


struct Matriz {
	Fila fila1;
	Fila fila2;
	Fila fila3;

	void show() {
		fila1.show();
		fila2.show();
		fila3.show();
	}
};


Fila fila(int n, Matriz matriz) {
	switch (n) {
	case 1: return matriz.fila1;
	case 2: return matriz.fila2;
	case 3: return matriz.fila3;
	}
};


Fila putrow(TTT value, int itemindex, Fila fila) {
	switch (itemindex) {
	case 1: return Fila{ value, fila.item2, fila.item3 };
	case 2: return Fila{ fila.item1, value, fila.item3 };
	case 3: return Fila{ fila.item1, fila.item2, value };
	default: return fila;
	}
};


Matriz putval(TTT value, int rowindex, int itemindex, Matriz matriz) {
	switch (rowindex) {
	case 1: return Matriz{ putrow(value, itemindex, matriz.fila1), matriz.fila2, matriz.fila3 };
	case 2: return Matriz{ matriz.fila1, putrow(value, itemindex, matriz.fila2), matriz.fila3 };
	case 3: return Matriz{ matriz.fila1, matriz.fila2, putrow(value, itemindex, matriz.fila3) };
	default: return matriz;
	}
};


auto getvalrow(int itemindex, Fila fila) {
	switch (itemindex) {
	case 1: return fila.item1;
	case 2: return fila.item2;
	case 3: return fila.item3;
	}
};


auto getval(int itemindex, int rowindex, Matriz matriz) {
	switch (rowindex) {
	case 1:  getvalrow(itemindex, matriz.fila1);
	case 2:  getvalrow(itemindex, matriz.fila2);
	case 3:  getvalrow(itemindex, matriz.fila3);
	}
};


/* type Posic = (Int,Int) */
std::vector<std::pair<int, int>> posic;


Matriz tablero = Matriz{ Fila{V,V,V},Fila{V,V,V},Fila{V,V,V} };

void allpos() {
	std::vector<std::pair<int, int>> allposs;
	for (int i = 1; i < 10; i++) {
		auto p = std::make_pair(i, i);
		allposs.push_back(p);
	};

	for (std::vector < std::pair<int, int>>::const_iterator it = allposs.begin(); it != allposs.end(); it++) {
		std::cout << it->first;
		std::cout << it->second;
	}
};


int main() {

	std::string m;

    std::cout << "tablero generado:" << std::endl;
	tablero.show();

	[]() {
		std::cout << "Ta-Te-Ti Funcional" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "X maquina Y persona" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "empieza (S/N)?" << std::endl;
	}
	();

	std::cin >> m;
	if (m == "S") {
		std::cout << "Juege" << std::endl;
	}
	else {
		std::cout << "Empiezo" << std::endl;
	}


	system("PAUSE");
	return 0;
}
