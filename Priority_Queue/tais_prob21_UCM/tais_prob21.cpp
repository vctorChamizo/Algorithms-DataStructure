// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:
	
		Para resolver el problema se ha usado una cola de prioridad en la que se ordenan los usuarios entrantes 
		de menor a mayor según el momento en el que se le tenga que enviar el siguiente mensajes. 
		
		De esta forma, por cada envio, el siguiente usuario es sacado de la cola, mostrado y actualizado 
		su proximo tiempo de envio; una vex realizado esto, es de nuevo insertado en la cola.
	
	
	COSTES:
	
		- El coste de realizar top() es -> O(1)
		- EL coste de realizar push() y pop() es -> O(log(n)) siendo n el numero de elementos de la cola.
	
	COSTE TOTAL: 
	
		O(m * log(n)) -> siendo m el numero de envios a realizar y n el numero de elementos en la cola.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "PriorityQueue.h"

struct tUser {

	int id;
	int period;
	int next;

	tUser() {}

	tUser(int _id, int _period) : id(_id), period(_period), next(_period) {}

	bool operator < (tUser const & u) const { return next < u.next || (next == u.next && id < u.id); }
};

int show_next(PriorityQueue<tUser> & q) {

	tUser user = q.top();
	q.pop();

	user.next += user.period;

	q.push(user);

	return user.id;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	PriorityQueue<tUser> queue;
	int _id, _period;

	for (int i = 0; i < n; ++i) {

		std::cin >> _id >> _period;

		queue.push({ _id, _period });
	}

	int k;
	std::cin >> k;

	for (int j = 0; j < k; ++j) std::cout << show_next(queue) << std::endl;

	std::cout << "----" << std::endl;

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