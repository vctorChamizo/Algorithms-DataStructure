// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:
		
		Para solucionar el problema se ha utilizado una cola de prioridad en la que los instrumentos están ordenados
		de maoyor a menor según el numero de instrumentos por partituras de cada grupo.
		
		De esta forma en la primera iteración se reparte una partitura a cada grupo de tal forma que ninguno de ellos
		se quede sin partitura. A partir de ese momento, se da una partitura nueva al grupo que encabece el top de la cola,
		ya que es el grupo que mas instrumentos por partituras tiene. Una vez actualizado sus datos, vuelve a ser insertado
		en la cola, donde es colocado en el lugar que le corresponde según el criterio anteriormente descrito.
		
		El proceso se repite hasta que es repartido el numero total de partituras disponibles.
	
	COSTES:
	
		- El coste de hacer top() es -> O(1)
		- El coste de hacer push() y pop() es -> O(log(n)) siendo n el numero de elementos de la cola.
	
	COSTE TOTAL:
	
		O(m * log(n)) -> siendo m el numero de partituras y n el numero de grupos.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include "PriorityQueue.h"

struct tInstrument {

	int n_instruments;
	int n_sheets = 1;

	tInstrument() {}

	tInstrument(int i) : n_instruments(i) {}
	
	bool operator < (tInstrument const & i) const {

		int op = n_instruments / n_sheets;
		if (n_instruments % n_sheets != 0) op++;

		int op_in = i.n_instruments / i.n_sheets;
		if (i.n_instruments % i.n_sheets != 0) op_in++;

		return op > op_in;
	}
};

int get_max(PriorityQueue<tInstrument> & q, int p) {

	tInstrument instrumnet;

	for (int j = 0; j < p; ++j) {

		instrumnet = q.top();
		q.pop();

		instrumnet.n_sheets++;

		q.push(instrumnet);
	}

	int max = q.top().n_instruments / q.top().n_sheets;
	if (q.top().n_instruments % q.top().n_sheets != 0) max++;

	return max;
}

bool resuelveCaso() {

	int p;
	std::cin >> p;

	if (!std::cin) return false;

	int n, i;
	PriorityQueue<tInstrument> queue;
	std::cin >> n;

	for (int k = 0; k < n; ++k) {

		std::cin >> i;

		queue.push({ i });
	}

	p -= n;

	if (p > 0) std::cout << get_max(queue, p);
	else std::cout << queue.top().n_instruments;

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