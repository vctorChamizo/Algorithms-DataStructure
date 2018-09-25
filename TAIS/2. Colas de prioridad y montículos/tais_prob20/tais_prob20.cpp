// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"


// función que resuelve el problema
long long int resolver(PriorityQueue<long long int>& monticulo) {

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

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
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

	long long int sol = resolver(monticulo);

	std::cout << sol << std::endl;

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}