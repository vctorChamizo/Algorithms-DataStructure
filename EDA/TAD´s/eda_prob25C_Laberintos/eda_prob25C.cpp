// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "bintree_eda_ext.h"

/*
// Code to external function //

#include "bintree_eda.h"

const std::string DRAGON = "Dragon";

struct tWay {

	std::string name_sheet;
	int n_dragons;
};

tWay way_min(bintree<T> const & t) {
	
	tWay w, w_left, w_right;

	if (t.left().empty() && t.right().empty()) {

		w.n_dragons = 0;
		w.name_sheet = t.root();

		return w;
	}
	else if (t.right().empty()) {

		w_left = way_min(t.left());

		if (t.root() == DRAGON) w_left.n_dragons++;

		return w_left;
	}
	else if (t.left().empty()) {

		w_right = way_min(t.right());

		if (t.root() == DRAGON) w_right.n_dragons++;

		return w_right;
	}
	else {

		w_left = way_min(t.left());
		w_right = way_min(t.right());

		if (w_left.n_dragons > w_right.n_dragons) {

			w.n_dragons = w_right.n_dragons;
			w.name_sheet = w_right.name_sheet;
		}
		else {

			w.n_dragons = w_left.n_dragons;
			w.name_sheet = w_left.name_sheet;
		}

		if (t.root() == DRAGON) w.n_dragons++;

		return w;
	}
}
*/


void resuelveCaso() {

	
	// Code to internal function //

	std::string empty = "...";
	bintree_ext<std::string> tree = leerArbol_ext(empty);

	tWay way = tree.way_min();

	/*
	// Code to external function //

	std::string empty = "...";
	bintree<std::string> tree = leerArbol(empty);

	tWay way = way_min(tree);
	*/

	std::cout << way.name_sheet << ' ' << way.n_dragons;

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