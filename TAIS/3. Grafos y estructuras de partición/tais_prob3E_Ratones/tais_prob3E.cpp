// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>

#include "GrafoDirigidoValorado.h"
#include "Laberinto.h"

bool resuelveCaso() {

	int N;
	std::cin >> N;

	if (!std::cin) return false;

	int S, T, P;
	std::cin >> S >> T >> P;

	GrafoDirigidoValorado<int> grafo(N);

	int v, w, valor;

	for (int i = 0; i < P; ++i) {

		std::cin >> v >> w >> valor;
		grafo.ponArista({ v - 1, w - 1, valor });
	}

	Laberinto laberinto(grafo.inverso(), S - 1);

	std::cout << laberinto.getRatones(T) << std::endl;

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