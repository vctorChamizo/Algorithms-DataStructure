// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "GrafoDirigidoValorado.h"
#include "Enlaces.h"


bool resuelveCaso() {

	//Inicializamos grafo Dirigido Valorado

	int V; //Pagina que queremos visitar 1 < V <= 10000
	std::cin >> V;

	if (V == 0) return false;

	std::vector<int> vectorTiempoCarga(V);
		
	for (int & v : vectorTiempoCarga) std::cin >> v;

	int E; //Numero de enlaces
	std::cin >> E;

	GrafoDirigidoValorado<int> grafo(V);

	int v, w, valor; //Caracteristicas de enlaces

	for (int i = 0; i < E; ++i) {

		std::cin >> v >> w >> valor;
		grafo.ponArista({ v - 1, w - 1, valor });
	}

	Enlaces enlaces(grafo, vectorTiempoCarga);

	if (enlaces.hayCamino()) std::cout << enlaces.getTiempoMinimo(V);
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