// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "autoescuela.h"

bool resuelveCaso() {

	std::string orden, alum, prof;
	int punt;

	std::cin >> orden;

	if (!std::cin) return false;

	autoescuela AE;

	while (orden != "FIN") {

		try {

			if (orden == "alta") {

				std::cin >> alum >> prof;

				AE.alta(alum, prof);
			}
			else if (orden == "es_alumno") {

				std::cin >> alum >> prof;

				if (AE.es_alumno(alum, prof)) std::cout << alum << " es alumno de " << prof << '\n';
				else std::cout << alum << " no es alumno de " << prof << '\n';
			}
			else if (orden == "puntuacion") {

				std::cin >> alum;

				int puntos = AE.puntuacion(alum);

				std::cout << "Puntuacion de " << alum << ": " << puntos << '\n';
			}
			else if (orden == "actualizar") {

				std::cin >> alum >> punt;

				AE.actualizar(alum, punt);
			}
			else if (orden == "examen") {

				std::cin >> prof >> punt;

				std::cout << "Alumnos de " << prof << " a examen:\n";

				for (auto const & a : AE.examen(prof, punt)) std::cout << a << '\n';
			}
			else if (orden == "aprobar") {

				std::cin >> alum;

				AE.aprobar(alum);
			}

		} 
		catch (std::domain_error e) { std::cout << "ERROR\n"; }

		std::cin >> orden;
	}

	std::cout << "------\n";

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
