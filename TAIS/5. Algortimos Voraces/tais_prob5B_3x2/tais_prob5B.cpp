// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:

		Para resoler el problema se ha usado una cola de prioridad y una estrategia voraz que consiste en
		colocar los precios de libros en la cola ordenados de mayor a menor de tal forma que se pueda compeltar el 
		3x2. Así de cada 3 libros, se cobran los dos de mayor importe y se ahorra el de menor; los libros que no completen
		la oferta se descartan y no se cuentan en el descuento.

	COSTES:

		- Coste de top() -> O(1)
		- Coste de push() y pop() -> O(log(n)) siendo n el número de elementos de la cola

	COSTE TOTAL:

		O(n * log(n)) -> siendo m el numero de libros a comprar 
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "PriorityQueue.h"

int max_offer(PriorityQueue<int, std::greater<int>> & p) {

	int max = 0;

	while (p.size() > 2) {

		p.pop();
		p.pop();

		max += p.top();
		p.pop();
	}

	return max;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (!std::cin) return false;

	PriorityQueue<int, std::greater<int>> p;
	int l;

	for (int i = 0; i < n; ++i) {

		std::cin >> l;

		p.push(l);
	}

	std::cout << max_offer(p) << std::endl;

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