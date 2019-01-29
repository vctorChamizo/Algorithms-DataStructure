// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Hora.h"

void cogerSiguiente(std::vector<Hora> const & hT, Hora const & hC, bool & eP, Hora & hS) {

	int i = 0;

	while (i < hT.size() && !eP) {

		if (hC < hT[i] || hC == hT[i]) {

			eP = true;
			hS = hT[i];
		}
		
		i++;
	}
}

bool resuelveCaso() {

	int T, H;
	std::cin >> T >> H;

	if (T == 0 && H == 0) return false;

	std::vector<Hora> horariosTrenes(T);
	Hora horaConsulta;

	for (auto & h : horariosTrenes) std::cin >> h;

	for (int i = 0; i < H; ++i) {

		bool esPosible = false;
		Hora horaSalida;

		try {

			std::cin >> horaConsulta;
			cogerSiguiente(horariosTrenes, horaConsulta, esPosible, horaSalida);

			if (esPosible) std::cout << horaSalida;
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