// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>

#include "GrafoValorado.h"
#include "Camiones.h"


bool resuelveCaso() {

	//Inicializamos grafo Valorado

	int V;

	std::cin >> V;

	if (!std::cin)
		return false;

	GrafoValorado<int> grafo(V);

	int E;

	std::cin >> E;

	int v, w, valor;

	for (int i = 0; i < E; ++i) {

		std::cin >> v >> w >> valor;
		grafo.ponArista({ v - 1, w - 1, valor });
	}

	//Leemos datos de las rutas que tomará el camión

	int K, origen, destino, anchura;

	std::cin >> K;

	for (int j = 0; j < K; ++j) {

		std::cin >> origen >> destino >> anchura;

		Camiones camiones(grafo, origen - 1, anchura);

		if (camiones.esRuta(destino - 1)) std::cout << "SI";
		else std::cout << "NO";

		std::cout << std::endl;
	}	

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