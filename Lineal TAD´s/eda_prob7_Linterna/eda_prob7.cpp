// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "stack_eda.h"

bool esGanadora(std::vector<int> const & v) {

	int mediano = -1;
	stack<int> pila;

	pila.push(v[v.size() - 1]);

	for (int i = v.size() - 1; i >= 0; --i) {

		if (v[i] < mediano) return false;
		else {

			while (!pila.empty() && v[i] > pila.top()) {

				mediano = pila.top();
				pila.pop();
			}

			pila.push(v[i]);
		}
	}
	
	return true;
}

bool resuelveCaso() {

	int N;
	std::cin >> N;

	if (!std::cin) return false;

	std::vector<int> alturas(N);
	for (auto & a : alturas) std::cin >> a;

	if (esGanadora(alturas)) std::cout << "SIEMPRE PREMIO";
	else std::cout << "ELEGIR OTRA";

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