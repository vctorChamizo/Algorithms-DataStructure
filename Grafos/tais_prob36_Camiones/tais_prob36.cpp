// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACION:
		
		Para resolver este problema se ha realizado una busqueda en profundidad en la que se parte desde el 
		punto de origen al resto de vertices con la restricción de que si son mas estrechos que la anchura
		del camión, en el vector de marcados aparece como no visitado, es decir, que no se puede acceder el.


	COSTES:

		- Para resolver el problema, en el peor de los casos deben recorrerse todos los vertices del grafo 
		  con sus respectivas aristas.


	COSTE TOTAL:

		O(V + E) -> siendo V el numero de vertices y E el numero de aristas del grafo.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "GrafoValorado.h"
#include "trucks.h"

bool resuelveCaso() {

	int V;
	std::cin >> V;

	if (!std::cin) return false;

	int E;
	std::cin >> E;

	int e1, e2, v;
	GrafoValorado<int> G(V);

	for (int i = 0; i < E; ++i) {

		std::cin >> e1 >> e2 >> v;

		G.ponArista({ e1 - 1, e2 - 1, v });
	}

	int K;
	std::cin >> K;

	int o, d, w;
	

	for (int i = 0; i < K; ++i) {

		std::cin >> o >> d >> w;

		trucks t(G, o - 1, w);

		if (t.is_possible(d - 1)) std::cout << "SI";
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