// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Grafo.h"
#include "Bipartito.h"


bool resuelveCaso() {

	int V;

	std::cin >> V;

	if (!std::cin)
		return false;

	int E;

	std::cin >> E;

	Grafo grafo(V);

	int v, w;

	for (int i = 0; i < E; ++i) {

		std::cin >> v >> w;

		grafo.ponArista(v, w);
	}

	Bipartito bp(grafo);

	if (bp.getBipartito()) std::cout << "SI";
	else std::cout << "NO";
	
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