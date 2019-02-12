// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Complejo.h"

bool esMandelbrot(Complejo<float> & c, int N) {

	int i = 1;
	Complejo<float> c_anterior = Complejo<float>(0, 0);
	Complejo<float> c_z;

	while (i <= N) {

		c_z = (c_anterior * c_anterior) + c;

		if (c_z.getMod() > 2) return false;
		else c_anterior = c_z;

		i++;
	}

	return true;
}

void resuelveCaso() {

	int N;
	Complejo<float> complejo;
	std::cin >> complejo >> N;

	if (esMandelbrot(complejo, N)) std::cout << "SI";
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
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}