// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN: 
	
		Para solucionar el problema se ha utilizado una cola de prioridad para ordenar los elementos de 
		menor a mayor debido a que así, el esfuerxo total de sumarlos es el mínimo.


	COSTES:
	
		- El coste de push y pop es -> O(log(n)) siendo n el numero de elementos de la cola.
		- El coste de top es -> O(1)
		
		
	COSTE TOTAL: 
	
		O(log(n)) -> siendo n el número de elementos de la cola.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "PriorityQueue.h"

long long int effort_sum(PriorityQueue<long long int> & q) {

	long long int op_1, op_2, sum, effort = 0;

	while (q.size() > 1) {

		op_1 = q.top();
		q.pop();

		op_2 = q.top();
		q.pop();

		sum = op_1 + op_2;

		effort += sum;

		q.push(sum);
	}

	return effort;
}

bool resuelveCaso() {

	long long int n;
	std::cin >> n;

	if (n == 0) return false;

	PriorityQueue<long long int> queue;
	long long int e;

	for (int i = 0; i < n; ++i) {

		std::cin >> e;

		queue.push(e);
	}

	std::cout << effort_sum(queue) << std::endl;

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