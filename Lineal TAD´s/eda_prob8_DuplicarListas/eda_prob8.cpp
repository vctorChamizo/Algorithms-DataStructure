// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_duplicate.h"

bool resuelveCaso() {

	queue_duplicate<int> lista;
	int n;

	std::cin >> n;
	if (!std::cin) return false;

	while (n != 0) {

		lista.push(n);
		std::cin >> n;
	}

	if (!lista.empty()) {

		lista.duplica();
		lista.print();
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