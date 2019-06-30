// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN: 

		Para resolver el problema se ha utilizado un grafo no dirigido y una búsqueda en profundidad que
		encuentra la maxima componente conexa del grafo, de esta forma se consigue el grupo mas grande 
		de amistades en la ciudad


	COSTES:
		
		- Tanto en el bucle FOR de la constructora de "max_friends" como en el metodo privado DFS, 
		  en el peor de los casos se recorren todos los vertices del grafo así como sus aristas.


	COSTE TOTAL:

		O(V + E) -> siendo V el numero de vertices del grafo y E el numero de aristas.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Grafo.h"
#include "max_friends.h"

void resuelveCaso() {

	int V;
	std::cin >> V;

	Grafo G(V);

	int E;
	std::cin >> E;

	int e1, e2;

	for (int i = 0; i < E; ++i) {

		std::cin >> e1 >> e2;

		G.ponArista(e1 - 1, e2 - 1);
	}

	max_friends friends(G);

	std::cout << friends.max() << std::endl;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}