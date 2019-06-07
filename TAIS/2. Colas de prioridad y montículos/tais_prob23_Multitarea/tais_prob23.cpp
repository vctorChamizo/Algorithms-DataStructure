// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:
		
		Para solucionar el problema se ha utilizado una cola de prioridad en la que se ordenan las tareas de menor 
		a mayor segun su momento de comienzo.
		
		De esta forma, por cada nueva iteracion se comprueba que la tarea que está en el top de la cola
		no sea coincidente con al siguiente. Si la tarea es periodica se actualiza su momento de comienzo 
		y de fin y es de nuevo insertada en la cola, ocupando la posicion que le corrsponda según su comienzo.
	
	COSTES:
	
		- El coste de hacer top() es -> O(1)
		- El coste de hacer push() y pop() es -> O(log(n)) siendo n el numero de elementos de la cola.
	
	COSTE TOTAL:
	
		O(n * log(n)) -> siendo n el numero de tareas.
*/
#include <iostream>
#include <iomanip>
#include <fstream>

#include "PriorityQueue.h"

struct tTask {

	int begin;
	int end;
	int period = 0;

	tTask() {}

	tTask(int b, int e) : begin(b), end(e) {};

	tTask(int b, int e, int p) : begin(b), end(e), period(p) {};

	bool operator < (tTask const & t) const { return begin < t.begin; }
};

bool check_conflicts(PriorityQueue<tTask> & q, int t) {

	while (!q.empty() && q.top().begin < t) {

		tTask task = q.top();
		q.pop();

		if (!q.empty() && q.top().begin < t && task.end > q.top().begin) return true;

		// Si es una tarea periodica -> se actualiza la tarea
		if (task.period > 0) { 

			task.begin += task.period;
			task.end += task.period;

			q.push(task);
		}
	}

	return false;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (!std::cin) return false;

	int m, t;
	std::cin >> m >> t;

	PriorityQueue<tTask> queue;
	int b, e, p;

	for (int i = 0; i < n; ++i) {

		std::cin >> b >> e;

		queue.push({ b, e });
	}

	for (int j = 0; j < m; ++j) {

		std::cin >> b >> e >> p;

		queue.push({ b, e, p });
	}

	if (check_conflicts(queue, t)) std::cout << "SI";
	else std::cout << "NO";

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