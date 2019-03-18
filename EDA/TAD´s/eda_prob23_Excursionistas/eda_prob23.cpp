// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

#include "bintree_eda.h"

struct tRescue {

	int teams = 0;
	int max_hikers = 0;
};

tRescue rescue(bintree<int> const & t) {

	tRescue r;

	if (t.empty()) return r;
	else if (t.left().empty() && t.right().empty()) {

		r.max_hikers = t.root();

		if (t.root() == 0) r.teams = 0;
		else r.teams = 1;

		return r;
	}
	else {

		tRescue r_left = rescue(t.left());
		tRescue r_right = rescue(t.right());

		r.max_hikers = std::max(r_left.max_hikers, r_right.max_hikers) + t.root();

		r.teams = r_left.teams + r_right.teams;

		if (r.teams == 0 && t.root() != 0) r.teams = 1;

		return r;
	}
}

void resuelveCaso() {

	bintree<int> tree = leerArbol(-1);

	tRescue data_rescue = rescue(tree);

	std::cout << data_rescue.teams << ' ' << data_rescue.max_hikers << std::endl;
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