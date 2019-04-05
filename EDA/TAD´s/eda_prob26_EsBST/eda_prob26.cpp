// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <climits>
#include <fstream>
#include <algorithm>

#include "bintree_eda.h"

bool isBST(const bintree<int> & t, int & nodoMin, int & nodoMax) {

	int node_min_left, node_max_left;
	int node_min_right, node_max_right;
	bool isBST_left, isBST_right;

	if (t.left().empty() && t.right().empty()) nodoMax = nodoMin = t.root();
	else if (t.right().empty()) {

		isBST_left = isBST(t.left(), node_min_left, node_max_left);

		if (!isBST_left || node_max_left >= t.root()) return false;

		nodoMax = std::max(node_max_left, t.root());
		nodoMin = std::min(node_min_left, t.root());
	}
	else if (t.left().empty()) {

		isBST_right = isBST(t.right(), node_min_right, node_max_right);

		if (!isBST_right || node_min_right <= t.root()) return false;

		nodoMax = std::max(node_max_right, t.root());
		nodoMin = std::min(node_min_right, t.root());
	}
	else {

		isBST_left = isBST(t.left(), node_min_left, node_max_left);

		if (isBST_left) {

			isBST_right = isBST(t.right(), node_min_right, node_max_right);

			if (!isBST_right || node_max_left >= t.root() || node_min_right <= t.root()) return false;

			nodoMax = std::max(node_max_right, t.root());
			nodoMin = std::min(node_min_left, t.root());
		}
		else return false;
	}

	return true;
}

void resuelveCaso() {

	int nodoMax, nodoMin;
	bintree<int> arbol = leerArbol(-1);

	if (arbol.empty()) std::cout << "SI";
	else {

		if (isBST(arbol, nodoMax, nodoMin)) std::cout << "SI";
		else std::cout << "NO";
	}

	std::cout << std::endl;
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