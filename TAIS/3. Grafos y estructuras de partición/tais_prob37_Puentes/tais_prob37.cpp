// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACION:

		Para solucionar este problema se ha usado el algoritmo de Prim (arbol de recubrimiento minimo)
		para poder unir todas las islas con el menor coste posibe. Si es imposible unir alguna de las islas,
		en el vector de marcado aparecerá como no visitado (FALSE).


	COSTES:

		- Hacer top() en la cola de prioridad -> O(1).
		- Hacer push() y pop() en la cola de prioridad -> O(log(n)) siendo n el numero de elementos de la cola.
		- Las llamadas a visit -> O(E * log(E)) siendo E el numero de aristas del grafo.

		- Por tanto el coste de hacer push() y pop() E veces (O(E * log(E)) + el coste de visit.


	COSTE TOTAL:

		O(E * log(E)) -> siendo E el numero de aristas del grafo.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "GrafoValorado.h"
#include "bridges.h"

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

	bridges b(G);

	if (b.is_possible()) std::cout << b.min_cost();
	else std::cout << "No hay puentes suficientes";

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