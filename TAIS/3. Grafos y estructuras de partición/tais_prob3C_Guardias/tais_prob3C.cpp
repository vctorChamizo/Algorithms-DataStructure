// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Grafo.h"
#include "guardians.h"

bool resuelveCaso() {

	int V;
	std::cin >> V;

	if (!std::cin) return false;

	int E;
	std::cin >> E;

	Grafo G(V);
	int e1, e2;

	for (int i = 0; i < E; ++i) {

		std::cin >> e1 >> e2;

		G.ponArista(e1 - 1, e2 - 1);
	}

	guardians guards(G);

	if (guards.is_possible()) std::cout << guards.min_guardians();
	else std::cout << "IMPOSIBLE";

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