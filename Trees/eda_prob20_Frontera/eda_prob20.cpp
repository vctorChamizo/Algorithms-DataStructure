// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "bintree_eda.h"

void calculateForintier(bintree<int> const & t, std::vector<int> & v) {

	if (t.left().empty() && t.right().empty()) v.push_back(t.root());
	else if (t.left().empty()) calculateForintier(t.right(), v);
	else if (t.right().empty()) calculateForintier(t.left(), v);
	else {

		calculateForintier(t.left(), v);
		calculateForintier(t.right(), v);
	}
}

void resuelveCaso() {

	bintree<int> tree;
	tree = leerArbol(-1);

	if (!tree.empty()) {

		std::vector<int> frontier;
		calculateForintier(tree, frontier);

		std::cout << frontier[0];
		for (int i = 1; i < frontier.size(); ++i) std::cout << ' ' << frontier[i];
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