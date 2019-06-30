// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACION:

		Para resolver este problema se ha usado el algorirmo de Dijkstra (camino minimo) que nos permite
		calcular el coste desde el la pagina de incio (1) hasta la pagina de destino (V). Cuando se encuentra el 
		cammino minimo hasta el vertice en cuestion hay que almacenar tambien el tiempo de carga dado.


	COSTE TOTAL:

		O(V + E) -> siendo V el numero de vertices del grfao y E el numero de aristas.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

#include "GrafoDirigidoValorado.h"
#include "network.h"

bool resuelveCaso() {

	int V;
	std::cin >> V;

	if (V == 0) return false;

	std::vector<int> v_charge(V);

	for (auto & v_c : v_charge) std::cin >> v_c;

	int E;
	std::cin >> E;

	GrafoDirigidoValorado<int> G(V);
	int e1, e2, v;

	for (int i = 0; i < E; ++i) {

		std::cin >> e1 >> e2 >> v;

		G.ponArista({ e1 - 1, e2 - 1, v });
	}

	network net(G, v_charge);

	if (net.is_possible()) std::cout << net.min_path(V - 1);
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