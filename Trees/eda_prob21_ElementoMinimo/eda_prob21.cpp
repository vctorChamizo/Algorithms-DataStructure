// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "bintree_eda_ext.h"

/*
* 	Code to external function
*

#include "bintree_eda.h"

template <typename T>
inline bintree<T> leerArbol_ext(T vacio) {

	T raiz;
	std::cin >> raiz;

	if (raiz == vacio) return {};
	else {

		auto iz = leerArbol_ext(vacio);
		auto dr = leerArbol_ext(vacio);
		return { iz, raiz, dr };
	}
}


template<class T>
T nod_min(bintree<T> const& arbol)
{
	T minimo = arbol.root();
	for (auto it = arbol.begin(); it != arbol.end(); ++it)
		if (*it < minimo) minimo = *it;
	
	return minimo;
}
*/

bool resuelveCaso() {

	char type;
	std::cin >> type;

	if (!std::cin) return false;

	/*	Code to internal function	*/
	
	if (type == 'N') {

		bintree_ext<int> tree;
		tree = leerArbol_ext(-1);

		if (!tree.empty()) std::cout << tree.nod_min();
	}
	else {

		bintree_ext<std::string> tree;
		std::string empty = "#";
		tree = leerArbol_ext(empty);

		if (!tree.empty()) std::cout << tree.nod_min();
	}

	/*
	*	Code to external function
	*

		if (type == 'N') {

			bintree<int> tree;
			tree = leerArbol_ext(-1);

			if (!tree.empty()) std::cout << nod_min(tree);
		}
		else {

			bintree<std::string> tree;
			std::string empty = "#";
			tree = leerArbol_ext(empty);

			if (!tree.empty()) std::cout << nod_min(tree);
		}
	
	*/

	std::cout << std::endl;

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}