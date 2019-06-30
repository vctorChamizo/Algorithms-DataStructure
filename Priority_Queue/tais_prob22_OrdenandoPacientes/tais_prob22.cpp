// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:
		
		Para solucionar el problema se ha utilizado una cola de prioridad en la que los pacientes están ordenados
		de mayor a menor según su grado de dolencia.
		
		Por tanto, cuando un paciente debe ser atendido, se muestra el siguiente, que es el que se encuentra en la 
		top de la cola. En el caso de ingresar un nuevo paciente, este es inicializado con sus datos e insertado en 
		el lugar que le corresponda según su grado de dolencia.
	
	COSTES:
	
		- El coste de hacer top() es -> O(1)
		- El coste de hacer push() y pop() es -> O(log(n)) siendo n el numero de elementos de la cola.
	
	COSTE TOTAL:
	
		O(m * log(n)) -> siendo m el numero de eventos y n el numero de elementos de la cola.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <string>

#include "PriorityQueue.h"

struct tPacient {

	std::string name;
	int pain;
	int order;

	tPacient() {}

	tPacient(std::string n, int p, int o) : name(n), pain(p), order(o) {}

	bool operator < (tPacient const & p) const { return pain > p.pain || (pain == p.pain && order < p.order); }
};

std::string next_pacient(PriorityQueue<tPacient> & q) {

	std::string pacient = q.top().name;
	q.pop();

	return pacient;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	char e;
	std::string name;
	int pain, n_pacient = 0;
	PriorityQueue<tPacient> queue;

	for (int i = 0; i < n; ++i) {

		std::cin >> e;

		if (e == 'I') {

			std::cin >> name >> pain;

			n_pacient++;

			queue.push({ name, pain, n_pacient });
		}
		else {

			std::cout << next_pacient(queue) << std::endl;

			n_pacient--;
		}
	}

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