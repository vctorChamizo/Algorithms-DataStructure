// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"


long long int calcularEsfuerzo(PriorityQueue<long long int>& monticulo) {

	long long int oper1, oper2, suma;
	long long int esfuerzo = 0;

	while (monticulo.size() > 1) {

		oper1 = monticulo.top();
		monticulo.pop();

		oper2 = monticulo.top();
		monticulo.pop();

		suma = oper1 + oper2;

		esfuerzo += suma;

		monticulo.push(suma);
	}

	return esfuerzo;
}


bool resuelveCaso() {

	long long int nElem;

	std::cin >> nElem;

	if (nElem == 0)
		return false;

	PriorityQueue<long long int> monticulo;
	int elem;

	for (int i = 0; i < nElem; ++i) {

		std::cin >> elem;
		monticulo.push(elem);
	}

	long long int esfuerzo = calcularEsfuerzo(monticulo);

	std::cout << esfuerzo << std::endl;

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