// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:
		
		Para solucionar el problema se ha utilizado una cola de prioridad en la que las cajas son ordenadas
		de menor a mayor según el memento en el que quedarán disponibles.
		
		Una vez que todos los clientes han sido atentidos, la caja que encabece el top de la cola será
		la que le corresponde al usuario.
	
	COSTES:
	
		- El coste de hacer top() es -> O(1)
		- El coste de hacer push() y pop() es -> O(log(n)) siendo n el numero de elementos de la cola.
	
	COSTE TOTAL:
	
		O(m * log(n)) -> siendo m el numero de clientes antes que el usuario y n el numero de cajas.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "PriorityQueue.h"

struct tBox {

	int n_box;
	int next = 0;

	tBox() {}

	tBox(int n) : n_box(n) {}

	bool operator < (tBox const & b) const { return next < b.next || (next == b.next && n_box < b.n_box); }
};

bool resuelveCaso() {

	int n, c;
	std::cin >> n >> c;

	if (n == 0 && c == 0) return false;

	PriorityQueue<tBox> queue;

	for (int i = 1; i <= n; ++i) queue.push({ i });

	int t;

	for (int j = 0; j < c; ++j) {

		std::cin >> t;

		tBox box = queue.top();
		queue.pop();

		box.next += t;

		queue.push(box);
	}

	std::cout << queue.top().n_box << std::endl;

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