// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_insert.h"

bool resuelveCaso() {

	queue_insert<int> lista;
	queue_insert<int> lista_aux;
	int N, n, M, m, P;

	std::cin >> N;
	if (!std::cin) return false;

	for (int i = 0; i < N; ++i) {

		std::cin >> n;
		lista.push(n);
	}

	std::cin >> M >> P;

	for (int j = 0; j < M; ++j) {

		std::cin >> m;
		lista_aux.push(m);
	}

	lista.inserta(lista_aux, P);
	lista.print();
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