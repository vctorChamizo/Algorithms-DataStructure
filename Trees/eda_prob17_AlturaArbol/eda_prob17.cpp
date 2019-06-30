// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

int getHeight(int max_height) {

	int root;
	std::cin >> root;

	max_height++;

	if (std::cin && root != 0) {

		int max_aux = max_height;

		for (int i = 0; i < root; i++) max_height = std::max(max_height, getHeight(max_aux));

		return max_height;
	}
	else return max_height;
}

void resuelveCaso() {

	std::cout << getHeight(0) << std::endl;
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