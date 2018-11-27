// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


int maximoCoches(std::vector<int> const & v, int vMin) {

	int nCoches = 0, ini = 0, fin = v.size() - 1;

	while (ini < fin) {

		if (v[ini] + v[fin] >= vMin) {
			nCoches++;
			ini++;
		}

		fin--;
	}

	return nCoches;
}


void resuelveCaso() {

	int pilas, voltajeMinimo;

	std::cin >> pilas >> voltajeMinimo;

	std::vector<int> voltajes(pilas);

	for (auto i = 0; i < pilas; ++i)
		std::cin >> voltajes[i];

	std::sort(voltajes.begin(), voltajes.end(), std::greater<int>());

	int maximo = maximoCoches(voltajes, voltajeMinimo);

	std::cout << maximo << std::endl;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}