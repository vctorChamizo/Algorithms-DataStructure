// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:
		
		** Código documentado **
	
	COSTES:
	
		- El coste de hacer top() es -> O(1)
		- El coste de hacer push() y pop() es -> O(log(n)) siendo n el numero de elementos de la cola.
	
	COSTE TOTAL:
	
		O(n) -> siendo n el numero de elementos de las diferentes colas.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>

#include "PriorityQueue.h"

/*
	COSTE: 
*/

int calculate_median(PriorityQueue<int, std::greater<int>> & q_max, PriorityQueue<int> & q_min) {

	int median, sum;

	// Se controla que las colas siempre tengan una difenrecia de como maximo uno entre el número de elementos que poseen cada una.
	// En caso contrario se compensa a la otra cola con un elemento de la que tiene mayor cantidad de elementos.
	if (q_max.size() + 1 < q_min.size()) {

		q_max.push(q_min.top());
		q_min.pop();
	}
	else if (q_min.size() + 1 < q_max.size()) {

		q_min.push(q_max.top());
		q_max.pop();
	}

	sum = q_max.size() + q_min.size(); // Se suman la cantidad de elemntos de los que se quiere calcular la mediana

	// En caso de que sea impar
	if (sum % 2 != 0) {

		if (q_max.size() > q_min.size()) return q_max.top() * 2;
		else return q_min.top() * 2;
	}
	else return q_max.top() + q_min.top();
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	PriorityQueue<int, std::greater<int>> queue_max;;
	PriorityQueue<int> queue_min;

	int e;
	std::cin >> e;

	std::cout << e * 2 << ' ';

	queue_max.push(e);

	for (int i = 1; i < n; ++i) {

		std::cin >> e;

		if (e < queue_max.top()) queue_max.push(e);
		else queue_min.push(e);

		std::cout << calculate_median(queue_max, queue_min) << ' ';
	}

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