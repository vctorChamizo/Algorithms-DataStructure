// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:
	
		Este prblema se resuelve implementando una busqueda en anchura que encuentra el camino minimo desde la casilla
		de comienzo hasta la casilla del fianal deido a los atajos (aristas) que contiene el tablero.
		

	COSTES:
		
		- El numero de vertices del grafo en este caso son las casillas del tablero (N * N) y las aristas de cada
		  vertice son K, que son los saltos posibles que se pueden hacer desde cada vertice.
		
		- El caso peor es aquel en el que el tablero no tenga atajos, por tanto, habría que recorrer el tablero completo.
		
		- Una busqueda en anchura tiene coste -> O(V + E) siendo V el numero de vertices del grafo y E el numero de aristas.
		
		
	COSTE TOTAL:
	
		O(N * N * K) -> siendo N las dimensiones del tablero (vertices) y K las aristas de dicho grafo.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

#include "GrafoDirigido.h"
#include "snake_stairs.h"

bool resuelveCaso() {

	int N, K, S, E;
	std::cin >> N >> K >> S >> E;

	if (N == 0 && K == 0 && S == 0 && E == 0) return false;

	std::vector<int> table(N * N);

	for (auto i = 0; i < (N * N); ++i) table[i] = i;

	int begin, end;

	for (int j = 0; j < (S + E); ++j) {

		std::cin >> begin >> end;

		table[begin - 1] = end - 1;
	}

	snake_stairs game(table, K);

	std::cout << game.min_way(N * N - 1) << std::endl;

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