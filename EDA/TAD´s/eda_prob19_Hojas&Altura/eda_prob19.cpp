// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

#include "bintree_eda_ext.h"

/*
	Realizado de forma externa.
*/
/*template <typename T>
int calculateNods(bintree<T> const & t) {

	if (t.empty()) return 0;
	else return calculateNods(t.left()) + calculateNods(t.right()) + 1;
}

template <typename T>
int calculateSheets(bintree<T> const & t) {

	if (t.empty()) return 0;
	else if (t.left().empty() && t.right().empty()) return 1;
	else return calculateSheets(t.left()) + calculateSheets(t.right());
}

template <typename T>
int calculateHeight(bintree<T> const & t) {

	if (t.empty()) return 0;
	else return std::max(calculateHeight(t.left()), calculateHeight(t.right())) + 1;
}
*/

void resuelveCaso() {

	// Realizado de forma externa.
	/*
	bintree<char> tree;
	tree = leerArbol('.');


	std::cout << calculateNods(tree) << ' ' << calculateSheets(tree) << ' ' << calculateHeight(tree) << std::endl;
	*/

	bintree_ext<char> tree;
	tree = leerArbol_ext('.');

	std::cout << tree.nods() << ' ' << tree.sheets() << ' ' << tree.height() << std::endl;
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