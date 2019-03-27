// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <queue>

#include "bintree_eda.h"

template <class T>
struct tRegistro {

	bintree<T> arbol;
	int profundidad;

	tRegistro(bintree<T> const& t, int p) : arbol(t), profundidad(p) {};
};

bool esPrimo(int n) {

	int nDiv = 2, i = 1;

	while (++i <= std::sqrt(n) && nDiv == 2) if (n % i == 0) ++nDiv;

	return nDiv == 2;
}

bool esMultiplo(int n) { return n % 7 == 0 && n != 7; }

template<class T>
bool barreraPrimos (bintree<T> const & arbol, int & profundidad, int & multiplo) {

	if (esPrimo(arbol.root())) return false;

	std::queue<tRegistro<int>> colaNodos;
	bool tieneCamino = false;

	tRegistro<int> registro(arbol, 1);

	colaNodos.push(registro);

	bintree<T> nodo = colaNodos.front().arbol;

	while (!colaNodos.empty() && !tieneCamino) {

		registro = colaNodos.front();
		nodo = registro.arbol;
		colaNodos.pop();

		multiplo = nodo.root();

		if (!nodo.left().empty() && !esPrimo(nodo.left().root())) colaNodos.push({ nodo.left(), registro.profundidad + 1 });
		if (!nodo.right().empty() && !esPrimo(nodo.right().root())) colaNodos.push({ nodo.right(), registro.profundidad + 1 });

		tieneCamino = (esMultiplo(multiplo) ? true : false);
	}

	profundidad = registro.profundidad;
	return tieneCamino;
}

void resuelveCaso() {

	bintree<int> tree = leerArbol(-1);
	int profundidad = 0, multiplo = 0;

	if (tree.empty()) std::cout << "NO HAY";
	else {

		if (barreraPrimos(tree, profundidad, multiplo)) std::cout << multiplo << ' ' << profundidad;
		else std::cout << "NO HAY";
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