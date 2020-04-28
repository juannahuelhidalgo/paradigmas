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

	auto show() {
		return std::to_string((int)item1) + " " + std::to_string((int)item2) + " " + std::to_string((int)item3);
	}
};

struct Matriz {
	Fila fila1;
	Fila fila2;
	Fila fila3;

	auto show() {
		return fila1.show() + "\n" + fila2.show() + "\n" + fila3.show() + "\n";
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

typedef std::pair<int, int> Posic;

Matriz tablero = Matriz{ Fila{V,V,V},Fila{V,V,V},Fila{V,V,V} };

//USO DE BEGIN?
std::vector<Posic> allpos() {
	std::vector<Posic> allposs;
/*	for (std::vector<Posic>::iterator it = allposs.begin(); it != allposs.end(); ++it) {
		auto p = std::make_pair(i, i);
		allposs.push_back(p);
	*/

	for (int i = 1; i < 10; i++) {
		auto p = std::make_pair(i, i);
		allposs.push_back(p);
	};
	return allposs;
};

TTT getposval(Posic poss, Matriz tablero) {
	getval(poss.first, poss.second, tablero);
};

TTT getFilaVals(int rowindex, Matriz tablero) {
	getval(rowindex, 1, tablero);
	getval(rowindex, 2, tablero);
	getval(rowindex, 3, tablero);
};

TTT getColVals(int colindex, Matriz tablero) {
	getval(1, colindex, tablero);
	getval(2, colindex, tablero);
	getval(3, colindex, tablero);
};

TTT getDiagPpal(Matriz tablero) {
	getval(1, 1, tablero);
	getval(2, 2, tablero);
	getval(3, 3, tablero);
};

TTT getDiagSec(Matriz tablero) {
	getval(1, 3, tablero);
	getval(2, 2, tablero);
	getval(3, 1, tablero);
};

//VER porque no deja usar el poss asi, puntero? 
TTT mydiags(Posic poss, Matriz tablero) {
	if (poss.first == 2 && poss.second = 2) { getDiagPpal(tablero) + getDiagSec(tablero); };
	if (poss.first == 1 && poss.second == 1) { getDiagPpal(tablero); };
	if (poss.first == 3 && poss.second == 3) { getDiagPpal(tablero); };
	if (poss.first == 1 && poss.second == 3) { getDiagPpal(tablero); };
	if (poss.first == 3 && poss.second == 1) { getDiagPpal(tablero); };
	if (poss.first == NULL && poss.second == NULL) { getDiagPpal(tablero); };
	
};

int playvalue(TTT yo, TTT t) {
	if (yo == t) { return 2; }
	if (t == V) { return 1; }
	else { return 0; }
};

std::vector<int> valorize(TTT yo, TTT p) {
	std::vector<int> v;
	std::transform(v.begin(), v.end(), v.begin(),
		[yo, p](std::vector<int> v) {return  (v.push_back = playvalue(yo, p)); });
};


//ver ++
template<typename ...Args> auto sum(Args ...args)
{
	return (args + ... + 0);
}
int valpos(TTT yo, Posic poss, Matriz tablero) {
	TTT myvalues = ((getColVals(poss.second, tablero)) ++ (getFilaVals(poss.first, tablero)) ++ (mydiags(poss, tablero)));
		sum(valorize(yo, myvalues));

};

//FALTA QUE VARIABLE DEL POSIC VA EN X AKA VALPOS
std::vector<Posic, int> allposValues(TTT yo, Matriz tablero){
	std::vector<Posic,int> v;
	std::transform(v.begin(), v.end(), v.begin(),
		[yo, p](std::vector<int> v) {return  (v.push_back = (valpos(yo, ,tablero),allpos())); });

};


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
	}
	else {
		std::cout << "Empiezo" << std::endl;
	}

	system("PAUSE");
	return 0;
}
