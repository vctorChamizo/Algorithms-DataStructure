// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACION:

		Para resolver este problema se usa el algoritmo de Dijkstra, para hayar el camino minimo desde el vertice
		de origen al vertice de destino. Para calcular el numero maximo de ratones que pueden completar el laberinto
		dentro del tiempo dado se aplica el algoritmo en el grafo inverso, de estar forma se calcula cuanto tarda cada
		raton en llegar a la salida.


	COSTES:

		- El coste de hacer top() en la cola de prioridad indexada -> O(1)
		- El coste de hacer push() y pop() en la cola de prioridad indexada -> O(log(n)) siendo n el numero de elementos de la cola.
		- El coste de hacer update() en la cola de prioridad indexada -> O(log(n)) siendo n el numero de elementos de la cola.


	COSE TOTAL:

		O(E * log(V)) -> siendo E el numero de aristas que contiene el grafo y V el numero de vertices.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "GrafoDirigidoValorado.h"
#include "labyrinth.h"

bool resuelveCaso() {

	int V;
	std::cin >> V;

	if (!std::cin) return false;

	int S, T, E;
	std::cin >> S >> T >> E;

	GrafoDirigidoValorado<int> G(V);
	int e1, e2, v;

	for (int i = 0; i < E; ++i) {

		std::cin >> e1 >> e2 >> v;

		G.ponArista({ e1 - 1, e2 - 1, v });
	}

	labyrinth labth(G.inverso(), S - 1);

	std::cout << labth.min_mouses(T) << std::endl;

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