// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

struct tZurdo {

	int n_soon = 0;
	bool is = true;
};

tZurdo esZurdo(bintree<char> const & t) {

	tZurdo z;

	if (t.empty()) return z;
	else if (t.left().empty() && t.right().empty()) {

		z.n_soon++;
		return z;
	}
	else {

		tZurdo z_left, z_right;

		z_left = esZurdo(t.left());
		z_right = esZurdo(t.right());

		if (!z_left.is || !z_right.is) {

			z.is = false;
			return z;
		}
		else {
 
			if (z_left.n_soon > (z_left.n_soon + z_right.n_soon) / 2) z.n_soon = z_left.n_soon + z_right.n_soon + 1;
			else z.is = false;
			
			return z;
		}
	}
}

void resuelveCaso() {

	bintree<char> tree = leerArbol('.');

	tZurdo zurdo = esZurdo(tree);

	if (zurdo.is) std::cout << "SI";
	else std::cout << "NO";


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