// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:

		Para resolver este problema se ha utlizado una estrategia voraz que consiste en ordenar los
		voltajes de las pilas de menor a mayor de tal manera que que se sumen el voltaje mas pequeño con
		el mas grande para maximizar así el numero de coches con pilas que lleguen al minimo del voltaje.

	COSTE:

		O(n) -> siendo n el numero de pilas
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

int max_cars(std::vector<int> const & p, int v) {

	int cars = 0;
	int i = 0, j = p.size() - 1;

	while (i < j) {

		if (p[i] + p[j] >= v) {

			j--;
			cars++;
		}

		i++;
	}

	return cars;
}

void resuelveCaso() {

	int n, v;
	std::cin >> n >> v;

	std::vector<int> p(n);

	for (auto & e : p) std::cin >> e;

	std::sort(p.begin(), p.end());

	std::cout << max_cars(p, v) << std::endl;
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