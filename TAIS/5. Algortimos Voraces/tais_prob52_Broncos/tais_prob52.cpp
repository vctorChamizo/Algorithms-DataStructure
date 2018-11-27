// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAS58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


int exitoMaximo(std::vector<int> const & pR, std::vector<int> const & pE) {

	int maxP = 0;

	for (auto i = 0; i < pR.size(); ++i)
		if (pE[i] > pR[i]) maxP += pE[i] - pR[i];

	return maxP;
}


bool resuelveCaso() {

	int partidos;

	std::cin >> partidos;

	if (partidos == 0) return false;

	std::vector<int> puntosRivales(partidos);
	std::vector<int> puntosEquipo(partidos);

	for (auto i = 0; i < partidos; ++i)
		std::cin >> puntosRivales[i];

	for (auto j = 0; j < partidos; ++j)
		std::cin >> puntosEquipo[j];

	std::sort(puntosRivales.begin(), puntosRivales.end());
	std::sort(puntosEquipo.begin(), puntosEquipo.end(), std::greater<int>());

	int maximo = exitoMaximo(puntosRivales, puntosEquipo);

	std::cout << maximo << std::endl;

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