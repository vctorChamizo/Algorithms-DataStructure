// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Juego.h"


bool resuelveCaso() {

	int N, K, S, E;
	std::cin >> N >> K >> S >> E;

	if (N == 0) return false;

	int ini, fin;

	std::vector<int> tablero(N * N);

	for (int i = 0; i < (N * N); ++i)
		tablero[i] = i;

	for (int j = 0; j < (S + E); ++j) {

		std::cin >> ini >> fin;

		tablero[ini - 1] = fin - 1;
	}

	Juego juego(tablero, K);

	std::cout << juego.caminoMinimo(N * N - 1) << std::endl;

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