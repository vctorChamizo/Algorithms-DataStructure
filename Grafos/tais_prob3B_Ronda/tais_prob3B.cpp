// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

#include "free_love.h"

void resuelveCaso() {

	int W, H;
	std::cin >> W >> H;

	std::vector<std::vector<char>> G (H, std::vector<char>(W));

	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j) std::cin >> G[i][j];
	
	free_love FL(G);

	if (FL.hasPathToExit()) std::cout << FL.distanceToExit();
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