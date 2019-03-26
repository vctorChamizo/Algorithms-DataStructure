// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_ext.h"
#include "Hora.h"

bool resuelveCaso() {

	int N;
	std::cin >> N;

	if (N == 0) return false;

	queue_ext<Hora> queue;
	Hora h;

	for (int i = 0; i < N; ++i) {

		std::cin >> h;
		queue.push(h);
	}

	if (!queue.empty()) {

		queue.removePair();
		queue.print();
	}
	
	std::cout << std::endl;

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while(resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}