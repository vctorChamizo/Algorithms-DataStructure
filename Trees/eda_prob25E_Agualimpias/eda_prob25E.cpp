// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

//El coste es O(n) -> siendo n el numero de elementos del conjunto.

int tramos_navegables(bintree<int> const & t, int & caudal) {

	if (t.right().empty() && t.left().empty()) {

		caudal = 1;
		return 0;
	}
	else if (t.right().empty()) {

		int caudal_left;
		int n_tramos_left = tramos_navegables(t.left(), caudal_left);

		if (caudal_left >= 3) n_tramos_left++;

		caudal = caudal_left - t.root();

		if (caudal < 0) caudal = 0;

		return n_tramos_left;

	}
	else if (t.left().empty()) {

		int caudal_right;
		int n_tramos_right = tramos_navegables(t.right(), caudal_right);

		if (caudal_right >= 3) n_tramos_right++;
		
		caudal = caudal_right - t.root();

		if (caudal < 0) caudal = 0;

		return n_tramos_right;
	}
	else {

		int caudal_right, caudal_left;
		int n_tramos_left = tramos_navegables(t.left(), caudal_left);
		int n_tramos_right = tramos_navegables(t.right(), caudal_right);

		int n_tramos = n_tramos_left + n_tramos_right;

		if (caudal_left >= 3) n_tramos++;

		if (caudal_right >= 3) n_tramos++;

		caudal = caudal_left + caudal_right - t.root();

		if (caudal < 0) caudal = 0;

		return n_tramos;
	}
}

void resuelveCaso() {

	bintree<int> tree = leerArbol(-1);
	int caudal;

	std::cout << tramos_navegables(tree, caudal) << std::endl;
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