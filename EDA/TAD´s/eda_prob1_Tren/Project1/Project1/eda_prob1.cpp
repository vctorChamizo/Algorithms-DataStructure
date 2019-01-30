// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Hora.h"

Hora cogerSiguiente(std::vector<Hora> const & hT, int ini, int fin, Hora const & hC) {

	if (ini == fin) return hT[ini];
	else if (ini + 1 == fin) {

		if (hC < hT[ini]) return hT[ini];
		else return hT[fin];
	}
	else {

		int m = (ini + fin) / 2;

		if (hC == hT[m]) return hT[m];
		else if (hC < hT[m]) return cogerSiguiente(hT, ini, m, hC);
		else return cogerSiguiente(hT, m + 1, fin, hC);
	}
}// cogerSiguiente

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

			if (horaConsulta < horariosTrenes[horariosTrenes.size() - 1]) std::cout << cogerSiguiente(horariosTrenes, 0, T - 1, horaConsulta);
			else std::cout << "NO";
			
			std::cout << std::endl;
		}
		catch (std::invalid_argument & ia) { std::cout << ia.what() << std::endl; }
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