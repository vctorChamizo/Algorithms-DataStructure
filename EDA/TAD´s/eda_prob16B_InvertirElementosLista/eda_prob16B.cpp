// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_ext.h"

bool resuelveCaso() {

	int N;
	std::cin >> N;

	if (N == 0) return false;

	queue_ext<int> queue;
	int n;

	for (int i = 0; i < N; ++i) {

		std::cin >> n;
		queue.push(n);
	}

	queue.inverted_pair();
	queue.print();

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