// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "GrafoValorado.h"
#include "CostePuentes.h"


bool resuelveCaso() {

	//Inicializamos grafo Valorado

	int V; //Numero de islas

	std::cin >> V;

	if (!std::cin) return false;

	GrafoValorado<int> grafo(V);

	int E; //Numero de puentes que se pueden construir

	std::cin >> E;

	int v, w, valor; //Islas que unen los puentes y coste de dicho puente

	for (auto i = 0; i < E; ++i) {

		std::cin >> v >> w >> valor;
		
		grafo.ponArista({ v - 1, w - 1, valor });
	}

	CostePuentes cPuentes(grafo);

	if (cPuentes.hayPuentes()) std::cout << cPuentes.getCosteMinimo();
	else std::cout << "No hay puentes suficentes";

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