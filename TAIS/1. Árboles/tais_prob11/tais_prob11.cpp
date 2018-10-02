// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
El problema se resuelve mediante recursividad no final comprobadno cada
subarbol del arbol principal, de tal manera que, si los dos hijos
tienen la misma altura, es decir, es binario y el hijo izquierdo es menor
que el padre y el hijo derecho es mayor que el padre (estas dos condicones
se deben cumplir para cualquier rama o nodo del arbol), el arbol es AVL.
*/


#include <iostream>
#include <iomanip>
#include <climits>
#include <fstream>
#include "bintree_eda.h"


bool esAvl(const bintree<int>& arbol, int& altura, int& nodoMax, int& nodoMin) {

	int altL, altR;
	int nodMaxL, nodMinL, nodMaxR, nodMinR;

	if (arbol.empty()) return true;
	
	else if (arbol.left().empty() && arbol.right().empty()) {

		altura = 1;
		nodoMax = nodoMin = arbol.root();
		return true;
	}
	else if (arbol.left().empty()) {

		bool avlDer = esAvl(arbol.right(), altR, nodMaxR, nodMinR);

		nodoMax = nodMinR;
		nodoMin = arbol.root();
		altura = altR + 1;

		if (avlDer && altR <= 1 && nodMinR > arbol.root()) return true;
		else return false;
	}
	else if (arbol.right().empty()) {

		bool avlIzq = esAvl(arbol.left(), altL, nodMaxL, nodMinL);
		
		nodoMax = arbol.root();
		nodoMin = nodMaxL;
		altura = altL + 1;

		if (avlIzq && altL <= 1 && nodMaxL < arbol.root()) return true;
		else return false;
	}
	else {

		bool avlIzq = esAvl(arbol.left(), altL, nodMaxL, nodMinL);
		bool avlDer = esAvl(arbol.right(), altR, nodMaxR, nodMinR);

		if (avlIzq && avlDer && (abs(altL - altR) <= 1) && nodMaxL < arbol.root() && nodMinR > arbol.root()){

			nodoMin = nodMaxL;
			nodoMax = nodMinR;
			altura = std::max(altL, altR) + 1;

			return true;
		}
		else return false;
	}
}


void resuelveCaso() {

	bintree<int> arbol;
	int altura, nodoMax, nodoMin;

	arbol = leerArbol(-1);

	bool avl = esAvl(arbol, altura, nodoMax, nodoMin);

	if (avl) std::cout << "SI" << std::endl;
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