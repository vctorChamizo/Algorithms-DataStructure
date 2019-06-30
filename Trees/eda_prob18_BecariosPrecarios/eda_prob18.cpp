// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

int precarious(int boss, int const K) {

	int nod;
	std::cin >> nod;

	if (nod == 0) {

		if (boss >= K) return 1;
		else return 0;
	}
	else {

		int p = 0;
		boss++;

		for (int i = 0; i < nod; i++)
			p += precarious(boss, K);

		return p;
	}
}

bool resuelveCaso() {

	int K;
	std::cin >> K;

	if (!std::cin) return false;

	std::cout << precarious(0, K) << std::endl;

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