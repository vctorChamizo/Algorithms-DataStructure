// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>

#include "carnet_points.h"

bool resuelveCaso() {

	int points;
	std::string order, DNI;

	std::cin >> order;

	if (!std::cin) return false;

	carnet_points DGT;

	while (order != "FIN") {

		try {

			if (order == "nuevo") {

				std::cin >> DNI;

				DGT.new_carnet(DNI);
			}
			else if (order == "quitar") { 

				std::cin >> DNI >> points;

				DGT.rest_points(DNI, points);
			}
			else if (order == "consultar") {

				std::cin >> DNI;

				std::cout << "Puntos de " << DNI << ": " << DGT.consult(DNI) << std::endl;;
			}
			else if (order == "cuantos_con_puntos") {

				std::cin >> points;

				std::cout << "Con " << points << " puntos hay " << DGT.how_many_points(points) << std::endl;;
			}
			else std::cout << "OPERACION DESCONOCIDA" << std::endl;

		} catch (std::domain_error e) { std::cout << "ERROR: " << e.what() << std::endl; }

		std::cin >> order;
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