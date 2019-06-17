// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:

		Este problema se resuelve con una busqueda en profuncidad para comprobar que desde un vertice se puede
		llegar a todos los demas desde un camino unico. Este se consigue generando un contador que por cada uno
		de los vertices marcados en el proceso de DFS y comprobando que es el mismo que el numero de vertices totales
		cuando el algortimo haya finalizado.

		Previamente a la busqueda en profundidad se debe comprabar que el nodo que se va a evaluar es un posible 
		candidato a ser vertice raiz. Un vertice es candidato a raiz si todas las aristas que posee son de salida,
		es decir, que no se puede accedder a ese vertice a través de ningun otro.


	COSTES:

		- En una busqueda en profundidad deben recorresrse todos los vertices del grafo así como sus aristas por lo
		  que su complejidad es O(V + E).


	COSTE TOTAL:
		
		O(V + E) -> siendo V el numero de vertices del grafo y E el numero de arsitas.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "arborescence.h"
#include "GrafoDirigido.h"

bool resuelveCaso() {

	int V;
	std::cin >> V;

	if (!std::cin) return false;

	int E;
	std::cin >> E;

	int e1, e2;
	GrafoDirigido G(V);

	for (int i = 0; i < E; ++i) {

		std::cin >> e1 >> e2;

		G.ponArista(e1, e2);
	}

	arborescence arb(G);

	if (arb.is_arborescence()) std::cout << "SI " << arb.get_root();
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