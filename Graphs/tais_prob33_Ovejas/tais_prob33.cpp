// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Ovejas.h"

bool resuelveCaso() {

	int C;
	std::cin >> C;

	if (!std::cin) return false;

	int F;
	std::cin >> F;

	Imagen imagen(F, std::vector<char>(C));

	for (int i = 0; i < F; ++i)
		for (int j = 0; j < C; ++j) std::cin >> imagen[i][j];
	
	Ovejas ovejas(imagen);

	std::cout << ovejas.getOvejasBlancas() << std::endl;

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