// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*

	EXPLICACIÓN:

		El problema se resuelve con un grafo no dirigido y una busqueda en profundidad en la que 
		a cada vertice se colorea con el color opuesto a su adyacente antecesor. Si el veritce 
		ya ha sido marcado y esta coloreado del mismo color que el vertice actual, entonces no 
		puede ser bipartito.


	COSTES:
	
		- Para comprobar si un grafo es bipartito debe recorrerse el grafo completo ya que deben colorarse todos
		  los vertices del mismo.


	COSTE TOTAL:

		O(V + E) -> siendo V el numero de vertices del grafo y E el numero de aristas.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Grafo.h"
#include "bipartito.h"

bool resuelveCaso() {

	int V;
	std::cin >> V;

	if (!std::cin) return false;

	Grafo G(V);

	int E;
	std::cin >> E;
	int e1, e2;

	for (auto i = 0; i < E; ++i) {

		std::cin >> e1 >> e2;

		G.ponArista(e1, e2);
	}

	bipartito _bipartito(G);

	if (_bipartito.is_bipartito()) std::cout << "SI";
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