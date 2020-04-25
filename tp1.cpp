#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Fila {
	char a, a, a;
};

struct Matriz {
	Fila fila1;
	Fila fila2;
	Fila fila3;
};

void showMat(Matriz matriz) {
	int n = 1;
	if (n < 3) {
		fila(n,matriz);
		n++;
	}	
};

Matriz mtest = Matriz{ Fila{1,2,3},Fila{4,5,6},Fila{7,8,9} };


Fila fila(int n, Matriz matriz) {
	switch (n) {
	case 1: return matriz.fila1;
	case 2: return matriz.fila2;
	case 3: return matriz.fila3;
	}
}

void putFila(char u, int n, Fila fila) {
		switch (n) {
		case 1:  u = fila.a1;
		case 2:  u = fila.a2;
		case 3:  u = fila.a3;
		}
};

void putVal(char u,int n,int m, Matriz matriz) {
	switch (n) {
	case 1:  putFila(u, m, matriz.fila1);
	case 2:  putFila(u, m, matriz.fila2);
	case 3:	 putFila(u, m, matriz.fila3);
	}
};

char getvalFila(int n, Fila fila){
	switch (n) {
	case 1:  return fila.a1;
	case 2:  return fila.a2;
	case 3:  return fila.a3;
	}
}


char getVal(int n, int m, Matriz matriz) {
	switch (n) {
	case 1:  getvalFila (m, matriz.fila1);
	case 2:  getvalFila (m, matriz.fila2);
	case 3:  getvalFila (m, matriz.fila3);
	}
}
/* varias funciones matriz */

enum TTT { V, X, Y };

/* type Posic = (Int,Int) */

Matriz tablero = Matriz{ Fila{V,V,V},Fila{V,V,V},Fila{V,V,V} };


int main() {

	std::string m;
	int f;
	int c;

	Fila filaA = { (int)1, (int)2, (int)3 };

	[]() {
		std::cout << "Ta-Te-Ti Funcional" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "X maquina Y persona" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "empieza (S/N)?" << std::endl;
	};

		std::cin >> m;
		if (m == "S") {
			std::cout << "Juege" << std::endl;
		}
		else {
			std::cout << "Empiezo" << std::endl;
		}


	std::cin >> f;
	std::cin >> c;

	system("PAUSE");
	return 0;
}
