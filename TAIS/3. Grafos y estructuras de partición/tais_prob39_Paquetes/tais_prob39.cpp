// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACION:

		El problema se resuelve aplicando el algoritmo de Dijkstra (camino minimo) en el que se calcula el el menor
		coste desde el punto de origen a los vertices en los cuales hay que realizar los repartos. El problema pide el 
		minimo coste del camino de retorno desde el vertices de reparto al vertices de salida original, por lo tanto se 
		vuelve a aplicar el algoritmo con el grafo inverso.


	COSTES:

		En el peor de los casos deberemos recorrer todos los vertices del grafo con sus respectivas aristas.


	COSTE TOTAL:

		O(V + E) -> siendo V el numero de vertices del grafo y E el numero de aristas.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <limits.h>

#include "GrafoDirigidoValorado.h"
#include "village.h"

bool resuelveCaso() {

	int V;
	std::cin >> V;

	if (!std::cin) return false;

	int E;
	std::cin >> E;

	GrafoDirigidoValorado<int> G(V);
	int e1, e2, v;

	for (int i = 0; i < E; ++i) {

		std::cin >> e1 >> e2 >> v;

		G.ponArista({ e1 - 1, e2 - 1, v });
	}

	int S, R;
	std::cin >> S >> R;

	std::vector<int> v_distribution(R);
	for (auto & d : v_distribution) std::cin >> d;

	village v_org(G, S - 1);
	village v_dest(G.inverso(), S - 1);

	int min_cost = 0, i = 0, cost_org, cost_dest;
	bool possible = true;

	while (i < R && possible) {

		int dist = v_distribution[i] - 1;

		cost_org = v_org.min_cost(dist);
		cost_dest = v_dest.min_cost(dist);

		if (cost_org == INT_MAX || cost_dest == INT_MAX) possible = false;
		else min_cost += (cost_org + cost_dest);

		i++;
	}

	if (possible) std::cout << min_cost;
	else std::cout << "Imposible";

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