// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
El problema se resuelve mediante recursividad no final comprobadno cada
subarbol del arbol principal, de tal manera que, si los dos hijos
tienen la misma altura, el árbol sigue siendo binario y por el contrario no.

De no ser binario el algoritmo sigue recorriendo todas las ramas del arbol, pero
hay una alternativa que suple este problema.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"


bool esBinario(const bintree<char>& arbol, int& altura) {

	if (arbol.empty()) {
		
		altura = 0;
		return true;
	}
	else if (arbol.left().empty() && arbol.right().empty()){
		
		altura = 1;
		return true;
	}
	else {

		int altL, altR;

		bool equL = esBinario(arbol.left(), altL);
		bool equR = esBinario(arbol.right(), altR);

		altura = std::max(altL, altR) + 1;

		if ((abs(altL - altR) <= 1) && equL && equR) return true;
		else return false;
	}
}
/*Alternativa de solucion:
	Controla el desiquilibrio del arbol saliendo de la función,
	evitando el recorrido completo del árbol.
*/
/*bool esBinario(const bintree<char>& arbol, int& altura) {

	if (arbol.empty()) {
		
		altura = 0;
		return true;
	}
	else if (arbol.left().empty() && arbol.right().empty()) {

		altura = 1;
		return true;
	}
	else {

		int altL, altR;

		bool equL = esBinario(arbol.left(), altL);

		if (equL) {

			bool equR = esBinario(arbol.right(), altR);

			altura = std::max(altL, altR) + 1;

			if (equL && equR && (abs(altL - altR) <= 1)) return true;
			else return false;
		}
		else return false;
	}
}*/


void resuelveCaso() {
	
	bintree <char> arbol;
	int altura;

	arbol = leerArbol('.');
	
	bool binario = esBinario(arbol, altura);

	if (binario) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}