// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACION:

		El problema se resuelve aplicando el algoritmo de Dijkstra, que calcula el camino minimo desde
		el punto de orgen al punto de destino. Para calcular el numero de veces que se puede llegar a ese
		destino se cuenta con un vector que contabiliza el numero de veces que el coste de llegar al
		vertice es el mismo.


	COSTES:

		- El coste de hacer top() en la cola de prioridad indexada -> O(1)
		- El coste de hacer push() y pop() en la cola de prioridad indexada -> O(log(n)) siendo n el numero de elementos de la cola.
		- El coste de hacer update() en la cola de prioridad indexada -> O(log(n)) siendo n el numero de elementos de la cola.

		- Al ser un grafo NO dirigido el algoritmo se repite para cada uno de los sentidos entre los vertices, por 
		  tanto la complejidad de las operaciones se realizan dos veces por cada arista -> O(2 * E)


	COSTE TOTAL:

		- O(E * log(V)) -> siendo E el numero de aristas del grafo y V el numero de vertices.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "GrafoValorado.h"
#include "school.h"

bool resuelveCaso() {

	int V;
	std::cin >> V;

	if (!std::cin) return false;

	int E;
	std::cin >> E;

	GrafoValorado<int> G(V);
	int e1, e2, v;

	for (int i = 0; i < E; ++i) {

		std::cin >> e1 >> e2 >> v;

		G.ponArista({ e1 - 1, e2 - 1, v });
	}

	school sch(G);

	std::cout << sch.n_paths(G.V() - 1) << std::endl;

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