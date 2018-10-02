// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58


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
	
	bool sol = esBinario(arbol, altura);

	if (sol) std::cout << "SI" << std::endl;
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