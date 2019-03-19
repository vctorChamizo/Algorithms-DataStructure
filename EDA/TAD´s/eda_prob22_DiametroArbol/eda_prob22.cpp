// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#include "bintree_eda.h"

struct tDiametre {

	int max_height = 0;
	int max_diametre = 0;
};

tDiametre getDiametre(bintree<char> const & t) {

	tDiametre d;

	if (t.empty()) return d; // Si el nodo está vacio --> no hay camino.
	else if (t.left().empty() && t.right().empty()) { // Si el nodo es hoja --> su altura y diametro son 1

		d.max_height = 1;
		d.max_diametre = 1;

		return d;
	}
	else {

		tDiametre d_left = getDiametre(t.left());
		tDiametre d_right = getDiametre(t.right());

		d.max_height = std::max(d_left.max_height, d_right.max_height) + 1; // Altura maxima del arbol actual.

		int current_diametre = d_left.max_height + d_right.max_height + 1; // Diametro del arbol actual
		int max_sub_tree = std::max(d_left.max_diametre, d_right.max_diametre); // Longitud maxima del sub_arbol del nodo actual.

		d.max_diametre = std::max(current_diametre, max_sub_tree); 

		return d;
	}
}

void resuelveCaso() {

	bintree<char> tree;
	tree = leerArbol('.');

	tDiametre diametre = getDiametre(tree);

	std::cout << diametre.max_diametre << std::endl;
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