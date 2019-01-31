// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Hora.h"

bool resuelveCaso() {

	int T, H;
	std::cin >> T >> H;

	if (T == 0 && H == 0) return false;

	std::vector<Hora> horariosTrenes(T);
	Hora horaConsulta;

	for (auto & h : horariosTrenes) std::cin >> h;

	for (int i = 0; i < H; ++i) {

		Hora horaSalida;

		try {

			std::cin >> horaConsulta;
		}
		catch (std::invalid_argument & ia) { std::cout << ia.what() << std::endl; }

		auto it = std::lower_bound(horariosTrenes.begin(), horariosTrenes.end(), horaConsulta);

		if (it == horariosTrenes.end()) std::cout << "NO";
		else std::cout << *it;

		std::cout << std::endl;
	}

	std::cout << "---" << std::endl;

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