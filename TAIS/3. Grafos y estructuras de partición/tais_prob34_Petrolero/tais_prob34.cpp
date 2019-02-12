// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "Manchas.h"


bool resuelveCaso() {

	int F;

	std::cin >> F;

	if (!std::cin) return false;

	int C;

	std::cin >> C;

	std::cin.ignore();// Ignoramos el primer espacio que consume.

	Area area(F, std::vector<char>(C));
	std::string lectura;
	char elem_aux;

	for (int i = 0; i < F; ++i) {

		getline(std::cin, lectura);// Leemos la linea entera.
		
		for (int j = 0; j < C; ++j) {//Recorremos cada uno de los elementos de la linea.

			elem_aux = (j >= lectura.size() ? ' ' : lectura[j]);

			area[i][j] = elem_aux;
		}
	}
		
	Manchas manchas(area);

	std::cout << manchas.getMaximo();

	int nCasos;

	std::cin >> nCasos;

	int x, y;

	for (int i = 0; i < nCasos; ++i) {

		std::cin >> x >> y;

		manchas.meterMancha(area, x - 1, y - 1);

		std::cout << " " << manchas.getMaximo();
	}
		
	std::cout << std::endl;

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