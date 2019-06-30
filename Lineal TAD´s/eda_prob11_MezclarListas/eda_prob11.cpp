// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_merge.h"

bool resuelveCaso() {

	queue_merge<int> lista, lista_aux;;
	int N;

	std::cin >> N;

	while (N != 0) {

		lista.push(N);
		std::cin >> N;
	}

	std::cin >> N;
	while (N != 0) {

		lista_aux.push(N);
		std::cin >> N;
	}

	if (lista_aux.empty() && lista.empty()) std::cout << std::endl;
	else {

		if (lista.empty()) lista_aux.print();
		else if (lista_aux.empty()) lista.print();
		else {

			lista.mezclar(lista_aux);
			lista.print();
		}

		std::cout << std::endl;

	}

	return true;
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