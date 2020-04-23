#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void inicio();
void pintar();

std::vector<std::string> fila1;
std::vector<std::string> fila2;
std::vector<std::string> fila3;
void jugar(std::vector<std::string>, std::vector<std::string>, std::vector<std::string>);
void imprimir(std::vector<std::string>, std::vector<std::string>, std::vector<std::string>);


int main() {

	string m;
	int f;
	int c;

	inicio();

	cin >> m;
	if (m == "S") {
		cout << "Empezara usted" << endl;
		pintar();
	}else{
		cout << "Empezara la maquina" << endl;
		pintar();
	}

	jugar(fila1,fila2,fila3);

	cin >> f;
	cin >> c;	

	system("PAUSE");
	return 0;
}


void imprimir(std::vector<std::string> fila1, std::vector<std::string> fila2, std::vector<std::string> fila3) {

	for (auto it = std::begin(fila1); it != std::end(fila1); it++) {
		std::cout << *it;
	}
	std::cout << " " << std::endl;
	for (auto it = std::begin(fila2); it != std::end(fila2); it++) {
		std::cout << *it;
	}
	std::cout << " " << std::endl;
	for (auto it = std::begin(fila3); it != std::end(fila3); it++) {
		std::cout << *it;
	}
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;

	//for_each{
		//begin(fila1), end(fila1), [](string n) { cout << n;}
	//};
	//cout << " " << endl;
	
}

void jugar(std::vector<std::string> fila1, std::vector<std::string> fila2, std::vector<std::string> fila3) {

	for (int i = 0; i < 3; i++) {
		fila1.push_back("H");
		fila2.push_back("H");
		fila3.push_back("H");
	}
	imprimir(fila1, fila2, fila3);
}

void pintar() {
	[]() {
		std::cout <<"Introduce fila (A,B,C) y columna (1,2,3) hasta terminar por ejemplo (A #ENTER 1 #ENTER)"  << std::endl;
		std::cout <<"Este es un ejemplo del tablero" << std::endl;
		std::cout <<"--123" << std::endl;
		std::cout <<"A-HHH" << std::endl;
		std::cout <<"B-HHH" << std::endl;
		std::cout <<"C-HHH" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "ESTE ES EL TABLERO!" << std::endl;
		std::cout << " " << std::endl;
	}
	();
}

void inicio() {
	[]() {
		std::cout << "Tateti funcional" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "Sera X la maquina, sera O persona" << std::endl;
		std::cout << "Empieza usted? Teclee S/N" << std::endl;
	}
	();
}