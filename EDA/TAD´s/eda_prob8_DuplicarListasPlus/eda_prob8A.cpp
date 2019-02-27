// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_duplicate_plus.h"

bool resuelveCaso() {

	queue_duplicate<int> lista;
	queue_duplicate<int> lista_amplia;
	int n;

	std::cin >> n;
	if (!std::cin) return false;

	while (n != 0) {

		lista.push(n);
		std::cin >> n;
	}

	std::cin >> n;
	while (n != 0) {

		lista_amplia.push(n);
		std::cin >> n;
	}

	std::cin >> n;

	if (!lista.empty()) {

		lista.duplica();
		std::cout << lista.size() << std::endl;
		lista.print();
		lista.amplia(lista_amplia);
		lista.elimina(n);
		std::cout << std::endl << lista.size() << std::endl;
		lista.print();
	}
	else {

		std::cout << 0 << std::endl;
		lista_amplia.elimina(n);
		std::cout << std::endl << lista_amplia.size() << std::endl;
		lista_amplia.print();
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