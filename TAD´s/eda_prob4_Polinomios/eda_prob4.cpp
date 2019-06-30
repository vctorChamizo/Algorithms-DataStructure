// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Polinomio.h"

bool resuelveCaso() {

	int C, E;
	std::cin >> C >> E;

	if (!std::cin) return false;

	Polinomio P;
	
	while (C != 0 || E != 0) {

		P.insert(C, E);
		std::cin >> C >> E;
	}

	int N, valor;
	std::cin >> N >> valor;

	std::cout << P.evaluate(valor);

	for (int i = 1; i < N; ++i) {

		std::cin >> valor;
		std::cout << ' ' << P.evaluate(valor);
	}

	std::cout << std::endl;

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}