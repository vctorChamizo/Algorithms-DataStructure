// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez:


#include <iostream>
#include <iomanip>
#include <climits>
#include <fstream>
#include "bintree_eda.h"


// función que resuelve el problema
bool resolver(const bintree<int>& arbol, int& altura, int& nodoMax, int& nodoMin) {

	int altL, altR;
	int nodMaxL, nodMinL, nodMaxR, nodMinR;

	if (arbol.empty()) return true;
	
	else if (arbol.left().empty() && arbol.right().empty()) {

		altura = 1;
		nodoMax = nodoMin = arbol.root();
		return true;
	}
	else if (arbol.left().empty()) {

		bool avlDer = resolver(arbol.right(), altR, nodMaxR, nodMinR);

		nodoMax = nodMinR;
		nodoMin = arbol.root();
		altura = altR + 1;

		if (avlDer && altR <= 1 && nodMinR > arbol.root()) return true;
		else return false;
	}
	else if (arbol.right().empty()) {

		bool avlIzq = resolver(arbol.left(), altL, nodMaxL, nodMinL);
		
		nodoMax = arbol.root();
		nodoMin = nodMaxL;
		altura = altL + 1;

		if (avlIzq && altL <= 1 && nodMaxL < arbol.root()) return true;
		else return false;
	}
	else {

		bool avlIzq = resolver(arbol.left(), altL, nodMaxL, nodMinL);
		bool avlDer = resolver(arbol.right(), altR, nodMaxR, nodMinR);

		if (avlIzq && avlDer && (abs(altL - altR) <= 1) && nodMaxL < arbol.root() && nodMinR > arbol.root()){

			nodoMin = nodMaxL;
			nodoMax = nodMinR;
			altura = std::max(altL, altR) + 1;

			return true;
		}
		else return false;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	bintree<int> arbol;
	int altura, nodoMax, nodoMin;

	arbol = leerArbol(-1);

	bool sol = resolver(arbol, altura, nodoMax, nodoMin);

	if (sol) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}