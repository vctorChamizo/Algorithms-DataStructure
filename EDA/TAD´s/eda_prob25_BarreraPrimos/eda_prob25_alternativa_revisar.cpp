// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

#include "bintree_eda.h"

bool esPrimo(int n) {

	int nDiv = 2, i = 1;

	while (++i <= std::sqrt(n) && nDiv == 2) if (n % i == 0) ++nDiv;

	return nDiv == 2;
}

bool esMultiplo(int n) { return n % 7 == 0 && n != 7; }

struct tMult {

	int mult;
	int depth = 1;
	bool is = false;
};

tMult barrerraPrimos(bintree<int> const & t) {

	std::vector<int> v = t.levelorder();
	std::queue<tMult> q;
	int i = 1, j;
	tMult m;
	m.mult = v[0];

	q.push(m);

	while (i < v.size()) {

		tMult m_aux = q.front();
		q.pop();

		for (j = i; j < i + 2; ++j) {

			m.mult = v[j];
			m.depth = m_aux.depth + 1;

			q.push(m);
		}

		if (!esPrimo(q.front().mult) && esMultiplo(q.front().mult)) {

			m = q.front();
			m.is = true;

			return m;
		}

		i = j;
	}

	while (!q.empty()) {

		if (!esPrimo(q.front().mult) && esMultiplo(q.front().mult)) {

			m = q.front();
			m.is = true;

			return m;
		}
		else q.pop();
	}

	return m;
}

void resuelveCaso() {

	bintree<int> tree = leerArbol(-1);

	if (tree.empty()) std::cout << "NO HAY";
	else if (!esPrimo(tree.root()) && esMultiplo(tree.root())) std::cout << tree.root() << ' ' << 1;
	else {

		tMult mult = barrerraPrimos(tree);

		if (mult.is) std::cout << mult.mult << ' ' << mult.depth;
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